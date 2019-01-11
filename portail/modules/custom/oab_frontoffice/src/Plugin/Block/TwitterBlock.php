<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\Cache;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;

/**
 *
 * @Block(
 *   id = "twitter_block",
 *   admin_label = @Translation("Twitter Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class TwitterBlock extends BlockBase {

    const API_KEY       = 'api_key';
    const API_SECRET    = 'api_secret';
    const USER_PROFILE  = 'user_profile';
    const NB_TWEET      = 'nb_tweet';
    const TAILLE_TWEET  = 'taille_tweet';

    const CACHE_BIN                 = 'twitter_api';
    const CACHE_BEARER_CID          = 'twitter_oauth_bearer';
    const CACHE_OEMBED_TWEET_CID    = 'twitter_oembed_tweet';
    const LOGGER_CHANNEL            = 'twitter_api';

    private $url_oauth      = 'https://api.twitter.com/oauth2/token';
    private $url_timeline   = 'https://api.twitter.com/1.1/statuses/user_timeline.json';
    private $url_oembed     = 'https://publish.twitter.com/oembed';

    public function build() {

        $timeline = $this->getTimeline();
        $tweets = $this->getEmbededTweets($timeline);
        return (count($tweets) > 0) ? array("tweets" => $tweets) : array();
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        // Add a form field to the existing block configuration form.
        $form[self::API_KEY] = array(
            '#type' => 'textfield',
            '#title' => t('API Customer Key'),
            '#default_value' => $this->getConf(self::API_KEY),
            '#required' => true,
        );

        $form[self::API_SECRET] = array(
            '#type' => 'textfield',
            '#title' => t('API Customer Secret'),
            '#default_value' => $this->getConf(self::API_SECRET),
            '#required' => true,
        );

        $form[self::USER_PROFILE] = array(
            '#type' => 'textfield',
            '#title' => t('Compte twitter'),
            '#default_value' =>  $this->getConf(self::USER_PROFILE),
            '#description' => "Compte twitter, sans le '@'",
            '#required' => true,
        );

        $form[self::NB_TWEET] = array(
            '#type' => 'number',
            '#title' => t('Nombre de tweets'),
            '#default_value' => $this->getConf(self::NB_TWEET, 5),
            '#description' => 'Nombre de tweets à afficher',
            '#required' => true,
        );

        $form[self::TAILLE_TWEET] = array(
            '#type' => 'number',
            '#title' => t('Largeur des tweets'),
            '#default_value' =>  $this->getConf(self::TAILLE_TWEET, 316),
            '#required' => false,
        );
        return $form;
    }

    /**
     * {@inheritdoc}
     */
    public function blockValidate($form, FormStateInterface $form_state) {

    }

    /**
     * {@inheritdoc}
     */
    public function blockSubmit($form, FormStateInterface $form_state) {
        // Save our custom settings when the form is submitted.
        $this->setConfigurationValue(self::API_KEY, $form_state->getValue(self::API_KEY));
        $this->setConfigurationValue(self::API_SECRET, $form_state->getValue(self::API_SECRET));
        $this->setConfigurationValue(self::USER_PROFILE, $form_state->getValue(self::USER_PROFILE));
        $this->setConfigurationValue(self::NB_TWEET, $form_state->getValue(self::NB_TWEET));
    }

    private function getEmbededTweets($tweets) {
        $ret = array();
        foreach ($tweets as $tweet) {
            if (isset($tweet['id'])) {
                $ret[] = $this->getEmbededTweet($tweet['id']);
            }
        }

        return $ret;
    }

    private function getEmbededTweet($tweet_id) {
        $cache_name = self::CACHE_OEMBED_TWEET_CID . '_' . $tweet_id;
        $cache = \Drupal::cache(self::CACHE_BIN)->get($cache_name);

        $ret = null;
        if ($cache !== false && isset($cachedData->data)) {
            $ret = $cache->data;
        } else {
            $tweet = $this->requestForEmbededTweet($tweet_id);

            $expiration = new \DateTime();
            $expiration->add(new \DateInterval("PT12H"));

            \Drupal::cache(self::CACHE_BIN)->set($cache_name, $tweet, $expiration->getTimestamp());

            $ret = $tweet;
        }

        return $ret;
    }

    private function requestForEmbededTweet($tweet_id) {
        $data = [
            'url' => $this->generateTweetUrl($tweet_id),
            'hide_thread' => true,
            'lang'      => \Drupal::languageManager()->getCurrentLanguage()->getId(),
            'maxwidth' => $this->getConf(self::TAILLE_TWEET)
        ];

        $url = $this->url_oembed . '?' . http_build_query($data);
        $ch = $this->getCurl($url);

        $ret = null;

        $result = $this->execCurl($ch);
        if (is_array($result) && isset($result['html'])) {
            $ret = $result['html'];
        }

        return $ret;
    }

    private function generateTweetUrl($tweet_id) {
        return 'https://twitter.com/' . $this->getConf(self::USER_PROFILE) . '/status/' . $tweet_id;
    }

    private function getTimeline($nbTweetRequested = null) {
        $nb_tweet_wanted = $this->getConf(self::NB_TWEET);

        if ($nbTweetRequested === null) {
            $nbTweetRequested = $nb_tweet_wanted;
        }

        $data = [
            'screen_name'       => $this->getConf(self::USER_PROFILE),
            // J'augmente le count pour éviter de faire trop de requetes
            'count'             => (int) $nbTweetRequested + ($nbTweetRequested > 20 ? $nbTweetRequested * 25 / 100 : 5),
            'trim_user'         => false,
            'include_rts'       => false,
            'exclude_replies'   => true
        ];

        $ret = null;
        if (null !== ($bearer = $this->getBearer())) {
            $headers = [
                'Authorization: Bearer ' . $bearer,
                'Content-Type: application/x-www-form-urlencoded'
            ];

            $url = $this->url_timeline . "?" . http_build_query($data);
            $ch = $this->getCurl($url);

            curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

            $json_ret = $this->execCurl($ch);

            // On check toujours par rapport au nombre de tweets voulu dans la conf
            // et pas au nb tweet passé en param
            // Twitter ne renvoie pas les Retweets, parce que demandé, mais les comptes quand mêmes dans son nb tweets
            // donc on recoie moins de tweet que demandé
            if (count($json_ret) < $nb_tweet_wanted) {
                $json_ret = $this->getTimeline($nbTweetRequested + 5);
            }

            // On retourne le nombre de tweets voulu, et non celui requeté
            $ret = array_slice($json_ret, 0, $nb_tweet_wanted);

        } else {
            \Drupal::logger(self::LOGGER_CHANNEL)->error('Bearer null, Authentification à l\'API Twitter impossible.');
        }

        return $ret;
    }

    private function getBearer() {
        $ret = null;

        $cid = self::CACHE_BEARER_CID . '_' . $this->getConf(self::API_KEY);

        $cachedData = \Drupal::cache()->get($cid);
        if ($cachedData !== false && isset($cachedData->data)) {
            $ret = $cachedData->data;
        } else {
            $bearer = $this->requestForBearer();

            $expiration = new \DateTime();
            $expiration->add(new \DateInterval("PT12H"));

            \Drupal::cache(self::CACHE_BIN)->set($cid, $bearer, $expiration->getTimestamp());

            $ret = $bearer;
        }

        return $ret;
    }

    private function requestForBearer() {
        $apiKey = $this->getConf(self::API_KEY);
        $apiSecret = $this->getConf(self::API_SECRET);

        $ch = $this->getCurl($this->url_oauth);

        curl_setopt($ch, CURLOPT_USERPWD, $apiKey . ":" . $apiSecret);
        curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_POSTFIELDS, array('grant_type' => 'client_credentials'));

        $json_ret = $this->execCurl($ch);

        if (is_array($json_ret) && isset($json_ret['access_token'])) {
            $ret = $json_ret['access_token'];
        }

        return $ret;
    }

    /**
     * @param $ch
     * @return array
     */
    private function execCurl($ch) {
        $result = curl_exec($ch);

        // Obligé de passer par là, le proxy ajoute de la data avant le json
        $json_ret = json_decode(strstr($result, '{'), true);

        // Si on a null, c'est que le json commencait par "["
        if (is_null($json_ret) || !is_array($json_ret)) {
            $json_ret = json_decode(strstr($result, '['), true);
        }

        if (is_array($json_ret) && isset($json_ret['errors'])) {
            $errors_message = "Curl error : " . curl_getinfo($ch, CURLINFO_EFFECTIVE_URL) . " | ";
            foreach ($json_ret['errors'] as $key => $error) {
                $errors_message .= $key . ' : ' . $error['code'] . " => " . $error['message'] . ' | ';
            }

            \Drupal::logger(self::LOGGER_CHANNEL)->error($errors_message);
        } elseif ( !is_array($json_ret) || curl_errno($ch) > 0 ) {
            $error_message = "Curl error : " . curl_getinfo($ch, CURLINFO_EFFECTIVE_URL) . " | "
                    . curl_errno($ch) . ' => ' . curl_error($ch) .  ' | '
                    . $result . ' | ' . json_encode(curl_getinfo($ch));
            \Drupal::logger(self::LOGGER_CHANNEL)->error($error_message);
        }

        return $json_ret;
    }

    private function getCurl($url = null) {

        $config_factory = \Drupal::configFactory();
        $config_proxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
        if (!empty($config) && !empty($config_proxy->get('proxy_server')) && !empty($config_proxy->get('proxy_port'))) {
            $proxy_server = $config_proxy->get('proxy_server').':'.$config_proxy->get('proxy_port');
        } else {
            $proxy_server = NULL;
        }

        $ch = curl_init();

        if ($url !== null) {
            curl_setopt($ch, CURLOPT_URL, $url);
        }

        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
        curl_setopt($ch, CURLOPT_TIMEOUT, 5);
        curl_setopt($ch, CURLOPT_PROXY, $proxy_server);
        curl_setopt($ch, CURLOPT_SSLVERSION, 0);
        curl_setopt($ch, CURLOPT_SSLVERSION, false);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_HEADER, 1);

        return $ch;
    }

    private function getConf($key, $default = '') {
        $ret = $default;

        if (isset($this->configuration[$key])) {
            $ret = $this->configuration[$key];
        }

        return $ret;
    }
}