<?php

namespace Drupal\oab_marketo\DnbHttpClient;

use GuzzleHttp\Client;
use Psr\Log\LoggerInterface;

class DnbClient {

  /**
   * @var Client
   */
  private $dnbClient;


  /**
   * @var LoggerInterface
   */
  private $logger;

  public function __construct(Client $dnb_client, LoggerInterface $logger) {
    $this->dnbClient = $dnb_client;
    $this->logger = $logger;
  }

  public function get(string $url, array $params): array {
    $ret = [];

    $res = $this->dnbClient->get($url, ['query' => $params]);
    if ($res->getStatusCode() > 299) {
      $this->logger->error(t("Altares client return error for url %url with message : %code => %message", [
        '%url' => $url . "?" . http_build_query($params),
        '%code' => $res->getStatusCode(),
        '%message' => $res->getBody()->getContents()
      ]));
    } else {
      $ret = json_decode($res->getBody()->getContents(), true);
    }

    return $ret;
  }

}
