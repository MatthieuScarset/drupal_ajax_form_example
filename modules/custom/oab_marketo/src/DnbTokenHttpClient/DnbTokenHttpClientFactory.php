<?php


namespace Drupal\oab_marketo\DnbTokenHttpClient;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Http\ClientFactory;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use GuzzleHttp\Client;

class DnbTokenHttpClientFactory {

  /**
   * The Guzzle client factory.
   *
   * @var ClientFactory
   */
  private $httpClientFactory;

  /**
   * @var ImmutableConfig
   */
  private $altaresConfig;


  public function __construct(ClientFactory $client_factory, ImmutableConfig $altares_config) {
    $this->httpClientFactory = $client_factory;
    $this->altaresConfig = $altares_config;
  }


  /**
   * Constructs a new altares client object
   *
   * @return Client
   *   The HTTP client.
   */
  public function get() {
    $consumer_key = $this->altaresConfig->get(OabAltaresSettingsForm::CONSUMER_KEY);
    $consumer_secret = $this->altaresConfig->get(OabAltaresSettingsForm::CONSUMER_SECRET);
    $api_url = $this->altaresConfig->get(OabAltaresSettingsForm::ALTARES_API_URL);

    $default_settings = [
      'http_errors' => false,
      'base_uri' => $api_url,
      'headers' => [
        'Content-Type' => "application/json"
      ],
      'auth' => [$consumer_key, $consumer_secret]
    ];

    return $this->httpClientFactory->fromOptions($default_settings);
  }
}


