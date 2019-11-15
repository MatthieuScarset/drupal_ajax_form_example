<?php

namespace Drupal\oab_twitter\Services;

use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;

class TwitterService {

  /* var \Drupal\Core\Config\ImmutableConfig */
  public $config;

  /* var \Drupal\Core\Config\ImmutableConfig */
  public $generalConfig;

  /* var \Drupal\Core\Cache\DatabaseBackend */
  public $cache;

  /* var Drupal\Core\Logger\LoggerChannel */
  public $logger;

  /* var Drupal\Core\Language\LanguageDefault */
  public $language;

  const KEY_API_KEY       = 'api_key';
  const KEY_API_SECRET    = 'api_secret';
  const KEY_USER_PROFILE  = 'user_profile';
  const KEY_NB_TWEET      = 'nb_tweet';
  const KEY_TAILLE_TWEET  = 'taille_tweet';

  const KEY_CACHE_BEARER_CID          = 'twitter_oauth_bearer';
  const KEY_CACHE_OEMBED_TWEET_CID    = 'twitter_oembed_tweet';

  private $urlOauth      = 'https://api.twitter.com/oauth2/token';
  private $urlTimeline   = 'https://api.twitter.com/1.1/statuses/user_timeline.json';
  private $urlOembed     = 'https://publish.twitter.com/oembed';

  public function getTweet(int $position) {
    $timeline = $this->getTimeline($position);
    $tweets = $this->getEmbededTweets($timeline);
    return $tweets;
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
    $cache_name = self::KEY_CACHE_OEMBED_TWEET_CID . '_' . $tweet_id;
    $cache = $this->cache->get($cache_name);

    $ret = null;
    if ($cache !== false && isset($cache->data)) {
      $ret = $cache->data;
    } else {
      $tweet = $this->requestForEmbededTweet($tweet_id);

      $expiration = new \DateTime();
      $expiration->add(new \DateInterval("PT12H"));

      $this->cache->set($cache_name, $tweet, $expiration->getTimestamp());

      $ret = $tweet;
    }

    return $ret;
  }

  private function requestForEmbededTweet($tweet_id) {
    $data = [
      'url' => $this->generateTweetUrl($tweet_id),
      'hide_thread' => true,
      'lang'      => $this->language->get()->getId(),
      'maxwidth' => $this->getConf(self::KEY_TAILLE_TWEET)
    ];

    $url = $this->urlOembed . '?' . http_build_query($data);
    $ch = $this->getCurl($url);

    $ret = null;

    $result = $this->execCurl($ch);
    if (is_array($result) && isset($result['html'])) {
      $ret = $result['html'];
    }

    return $ret;
  }

  private function generateTweetUrl($tweet_id) {
    return 'https://twitter.com/' . $this->getConf(self::KEY_USER_PROFILE) . '/status/' . $tweet_id;
  }

  private function getTimeline($position, $nb_tweet_requested = null) {
    $nb_tweet_cache = $this->getConf(self::KEY_NB_TWEET);

    if ($nb_tweet_requested === null) {
      $nb_tweet_requested = $nb_tweet_cache;
    }

    $data = [
      'screen_name'       => $this->getConf(self::KEY_USER_PROFILE),
      // J'augmente le count pour éviter de faire trop de requetes
      'count'             => (int) $nb_tweet_requested * 1.30,
      'trim_user'         => false,
      'include_rts'       => false,
      'exclude_replies'   => true
    ];

    $ret = array();
    if (null !== ($bearer = $this->getBearer())) {
      $headers = [
        'Authorization: Bearer ' . $bearer,
        'Content-Type: application/x-www-form-urlencoded'
      ];

      $url = $this->urlTimeline . "?" . http_build_query($data);
      $ch = $this->getCurl($url);

      curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

      $json_ret = $this->execCurl($ch);

      // On check toujours par rapport au nombre de tweets voulu dans la conf
      // et pas au nb tweet passé en param
      // Twitter ne renvoie pas les Retweets, parce que demandé, mais les comptes quand mêmes dans son nb tweets
      // donc on recoie moins de tweet que demandé

      if (count($json_ret) < $nb_tweet_cache) {
        $json_ret = $this->getTimeline($position, $nb_tweet_requested * 2);
      }

      // On retourne le nombre de tweets voulu, et non celui requeté
      $ret = array_slice($json_ret, $position - 1, $position);

    } else {
      $this->logger->error('Bearer null, Authentification à l\'API Twitter impossible.');
    }

    return $ret;
  }

  private function getBearer() {
    $ret = null;

    $cid = self::KEY_CACHE_BEARER_CID . '_' . $this->getConf(self::KEY_API_KEY);

    $cached_data = $this->cache->get($cid);
    if ($cached_data !== false && isset($cached_data->data)) {
      $ret = $cached_data->data;
    } else {
      $bearer = $this->requestForBearer();

      $expiration = new \DateTime();
      $expiration->add(new \DateInterval("PT12H"));

      $this->cache->set($cid, $bearer, $expiration->getTimestamp());

      $ret = $bearer;
    }

    return $ret;
  }

  private function requestForBearer() {
    $api_key = $this->getConf(self::KEY_API_KEY);
    $api_secret = $this->getConf(self::KEY_API_SECRET);

    $ch = $this->getCurl($this->urlOauth);

    curl_setopt($ch, CURLOPT_USERPWD, $api_key . ":" . $api_secret);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, array('grant_type' => 'client_credentials'));

    $json_ret = $this->execCurl($ch);

    $ret = null;
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

      $this->logger->error($errors_message);
    } elseif (!is_array($json_ret) || curl_errno($ch) > 0) {
      $error_message = "Curl error : " . curl_getinfo($ch, CURLINFO_EFFECTIVE_URL) . " | "
        . curl_errno($ch) . ' => ' . curl_error($ch) .  ' | '
        . $result . ' | ' . json_encode(curl_getinfo($ch));
      $this->logger->error($error_message);
    }

    return $json_ret;
  }

  private function getCurl($url = null) {

    $proxy_server = NULL;

    if (!empty($this->generalConfig) && !empty($this->generalConfig->get('proxy_server')) && !empty($this->generalConfig->get('proxy_port'))) {
      $proxy_server = $this->generalConfig->get('proxy_server').':'.$this->generalConfig->get('proxy_port');
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
    if ($this->config->get($key)) {
      $ret = $this->config->get($key);
    }

    return $ret;
  }
}
