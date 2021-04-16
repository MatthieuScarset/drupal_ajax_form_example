<?php

namespace Drupal\oab_marketo\DnbTokenHttpClient;

use GuzzleHttp\Client;
use Psr\Log\LoggerInterface;

class DnbTokenClient {

  /**
   * @var Client
   */
  private $altaresClient;

  /**
   * @var LoggerInterface
   */
  private $logger;


  public function __construct(Client $altares_client, LoggerInterface $logger) {
    $this->altaresClient = $altares_client;
    $this->logger = $logger;
  }

  public function getToken(): array {
    $ret = [];

    $body = [
      "grant_type" => "client_credentials"
    ];

    $result = $this->altaresClient->post('/v2/token', ['json' => $body]);

    if ($result->getStatusCode() !== 200) {
      $this->logger->error(t("Cannot get Token with response : %code (%reason) => %message", [
        '%code' => $result->getStatusCode(),
        '%reson' => $result->getReasonPhrase(),
        '%message' => $result->getBody()->getContents()
      ]));
    } else {
      $ret = json_decode($result->getBody()->getContents(), true);
    }

    return $ret;
  }

}
