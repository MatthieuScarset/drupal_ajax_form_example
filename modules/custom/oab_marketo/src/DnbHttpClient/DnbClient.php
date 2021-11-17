<?php

namespace Drupal\oab_marketo\DnbHttpClient;

use GuzzleHttp\Client;
use Psr\Log\LoggerInterface;

class DnbClient {


  /**
   * @var LoggerInterface
   */
  private $logger;

  public function __construct(LoggerInterface $logger) {
    $this->logger = $logger;
  }

  public function get(string $url, array $params): array {
    $ret = [];
    $dnb_client = $this->getDnbClient();

    $res = $dnb_client->get($url, ['query' => $params]);
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

  public function getDnbClient() {
    return \Drupal::service('oab_marketo.dnb_http_client');
  }

}
