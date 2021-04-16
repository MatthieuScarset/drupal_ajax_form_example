<?php

namespace Drupal\oab_twitter\Services;

use \Drupal\Core\Config\ImmutableConfig;

/**
 * Helper class to construct a HTTP client with Drupal specific config.
 */
class ClientFactory {

  /**
   * The Guzzle client factory.
   *
   * @var Drupal\Core\Http\ClientFactory
   */
  public $httpClientFactory;

  /**
   * Constructs a new client object from general settings.
   *
   * @param \Drupal\Core\Config\ImmutableConfig $settings
   *   The general settings.
   *
   * @return \GuzzleHttp\Client
   *   The HTTP client.
   */
  public function fromSettings(ImmutableConfig $settings) {

    $proxy_server = null;

    if (!empty($settings) && !empty($settings->get('proxy_server')) && !empty($settings->get('proxy_port'))) {
      $proxy_server = $settings->get('proxy_server').':'. $settings->get('proxy_port');
    }

    $default_settings = [
      'proxy' => [
        'http' => $proxy_server,
        'https' => $proxy_server,
        'no' => [],
      ]
    ];
    return $this->httpClientFactory->fromOptions($default_settings);
  }

}
