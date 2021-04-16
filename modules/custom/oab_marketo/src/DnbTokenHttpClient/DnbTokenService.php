<?php


namespace Drupal\oab_marketo\DnbTokenHttpClient;

use Drupal\Core\Cache\CacheBackendInterface;

class DnbTokenService {

  private $cid = "oab_marketo:dnb_token";


  /**
   * @var DnbTokenClient
   */
  private $altaresClient;

  /**
   * @var CacheBackendInterface
   */
  private $cache;


  public function __construct(DnbTokenClient $altares_client, CacheBackendInterface $cache) {
    $this->altaresClient = $altares_client;
    $this->cache = $cache;
  }

  public function getToken(): string {
    $cache_data = $this->cache->get($this->cid);
    if ($cache_data !== false) {
      $token = $cache_data->data;
    } else {
      // Valeur par défaut si on n'arrive pas à récueperer le token pour ne pas couper l'appel
      //A voir pour y remplacer par une exception qui serait catchée dans le controller
      $token = "";

      $client_result = $this->altaresClient->getToken();

      if (isset($client_result['access_token'])) {
        $token = $client_result['access_token'];
        $this->cache->set($this->cid, $client_result['access_token'], date('U') + ($client_result['expiresIn']));
      }
    }

    return $token;
  }

}
