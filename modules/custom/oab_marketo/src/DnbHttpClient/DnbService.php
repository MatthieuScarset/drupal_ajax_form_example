<?php


namespace Drupal\oab_marketo\DnbHttpClient;


use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use GuzzleHttp\Client;

class DnbService {

  /**
   * @var Client
   */
  private $altaresClient;

  /**
   * @var CacheBackendInterface
   */
  private $cache;

  public function __construct(DnbClient $altares_client, CacheBackendInterface $cache) {
    $this->altaresClient = $altares_client;
    $this->cache = $cache;
  }

  public function getInfo(string $string): array {
    $ret = [];

    $url = "/v1/match/cleanseMatch";
    $params = [
      'duns' => $string //research by duns

      //research by SIRET + Country Alpha Code
//      'registrationNumber' => $string,
//      'countryISOAlpha2Code' => $countryAlphaCode
    ];

    $data = $this->get($url, $params);

    if (isset($data["matchCandidates"])) {
      $ret = $data["matchCandidates"];
    }

    return $ret;
  }

  public function typeahead(string $string): array {
    $ret = [];

    $url = "/v1/search/typeahead";
    $params = [
      'searchTerm' => $string
    ];

    $data = $this->get($url, $params);

    if (isset($data['searchCandidates'])) {
      $ret = $data['searchCandidates'];
    }

    return $ret;
  }

  private function get($url, $params) {

    $cid = $this->getCid($url, $params);
    $cache_data = $this->cache->get($cid);

    if ($cache_data !== false) {
      $data = $cache_data->data;
    } else {
      $data = $this->altaresClient->get($url, $params);
      $this->putInCache($cid, $data);
    }

    return $data;
  }

  private function putInCache($cid, $data) {
    $now = new \DateTime();
    $cache_time = (string) \Drupal::config(OabAltaresSettingsForm::getConfigName())->get(OabAltaresSettingsForm::CACHE_RETENTION_TIME);
    $now->add(new \DateInterval('PT'.$cache_time.'H')); // Ajout de 24h;
    // On cache le résultat en cache pour éviter de faire trop d'appels
    $this->cache->set($cid, $data, $now->format('U'));
  }

  private function getCid(string $url, array $params) {
    return $url . ":" . http_build_query($params);
  }
}
