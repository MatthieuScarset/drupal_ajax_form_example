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

  /* var \Drupal\Core\Logger\LoggerChannel */
  public $logger;

  /* var \Drupal\Core\Language\LanguageManager */
  public $languageManager;

  /* var \GuzzleHttp\Client */
  public $client;

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
    $cache_name = self::KEY_CACHE_OEMBED_TWEET_CID . '_' . $this->languageManager->getCurrentLanguage()->getId() . '_' . $tweet_id;
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
      'lang'      => $this->languageManager->getCurrentLanguage()->getId(),
      'maxwidth' => $this->getConf(self::KEY_TAILLE_TWEET)
    ];

    $url = $this->urlOembed . '?' . http_build_query($data);

    $response =  $this->client->request('GET', $url);

    $result = json_decode($response->getBody()->getContents(), true);

    $ret = null;

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
        'Authorization' => 'Bearer ' . $bearer,
        'Content-Type' => 'application/x-www-form-urlencoded'
      ];

      $url = $this->urlTimeline . "?" . http_build_query($data);

      $response =  $this->client->request('GET', $url, [
        'headers' => $headers
      ]);

      $json_ret = json_decode($response->getBody()->getContents(), true);

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

    $json_ret = null;

    $response =  $this->client->request('POST', $this->urlOauth, [
      'auth' => [
        $this->getConf(self::KEY_API_KEY),
        $this->getConf(self::KEY_API_SECRET)
      ],
      'form_params' => array(
        'grant_type' => 'client_credentials'
      )
    ]);

    $json_ret = json_decode($response->getBody()->getContents(), true);

    $ret = null;
    if (is_array($json_ret) && isset($json_ret['access_token'])) {
      $ret = $json_ret['access_token'];
    }

    return $ret;
  }

  private function getConf($key, $default = '') {
    $ret = $default;
    if ($this->config->get($key)) {
      $ret = $this->config->get($key);
    }

    return $ret;
  }
}
