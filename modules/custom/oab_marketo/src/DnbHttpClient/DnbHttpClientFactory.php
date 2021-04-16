<?php


namespace Drupal\oab_marketo\DnbHttpClient;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Http\ClientFactory;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use Drupal\oab_marketo\DnbTokenHttpClient\DnbTokenService;
use GuzzleHttp\Client;

class DnbHttpClientFactory
{

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


  /**
   * @var DnbTokenService
   */
  private $dnbTokenService;


  public function __construct(ClientFactory $client_factory, ImmutableConfig $altares_config, DnbTokenService $dnb_token_service) {
    $this->httpClientFactory = $client_factory;
    $this->altaresConfig =  $altares_config;
    $this->dnbTokenService = $dnb_token_service;
  }


  /**
   * Constructs a new altares client object
   *
   * @return Client
   *   The HTTP client.
   */
  public function get() {
    $api_url = $this->altaresConfig->get(OabAltaresSettingsForm::ALTARES_API_URL);
    $token = $this->dnbTokenService->getToken();

    $default_settings['base_uri'] = $api_url;

    $default_settings = [
      'http_errors' => false,
      'base_uri' => $api_url,
      'headers' => [
        'Authorization' => "Bearer " . $token,
        'Content-type' => "application/json",
      ]
    ];

    return $this->httpClientFactory->fromOptions($default_settings);
  }
}
