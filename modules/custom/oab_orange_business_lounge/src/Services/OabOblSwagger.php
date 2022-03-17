<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\Core\Messenger\MessengerInterface;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;



class OabOblSwagger {

    private mixed $urlApi = '';
    private mixed $titleLabel = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/countries';
    const API_TECHNOLOGIES = '/network-types';

  /**
   * @var MessengerInterface
   */
  private MessengerInterface $messenger;


  public function __construct(MessengerInterface $messenger_service) {
        $config = \Drupal::config(OabOblForm::getConfigName());
        $this->messenger = $messenger_service;
        $this->urlApi = $config->get('url_api');
        $this->titleLabel = $config->get('title_label');
    }


    /**
     * @return mixed
     */
    public function getCountriesWithoutOperator(): mixed {
        $data = $this->executeScriptCurl(self::API_COUNTRIES);
        return $data;
    }

  /**
   * @param bool $display_message
   *
   * @return mixed
   */
    public function getZones(bool $display_message = false): mixed {
        $data = $this->executeScriptCurl(self::API_ZONE, $display_message);
        return $data;
    }

  /**
   * @param $id
   *
   * @return mixed
   */
    public function getOneZone($id): mixed {
      return $this->executeScriptCurl(self::API_ZONE.'/'.$id);
    }

    /**
     * @return mixed
     */
    public function getPassData(): mixed {
      return $this->executeScriptCurl(self::API_PASS_DATA);
    }

  /**
   * @param $id
   *
   * @return mixed
   */
    public function getOneCountry($id): mixed {
        return $this->executeScriptCurl("/countries/".$id);
    }


    /**
     * @return bool|mixed
     */
    public function getTechnologies(): mixed {
      return $this->executeScriptCurl(self::API_TECHNOLOGIES);
    }


    /**
     * @return bool|mixed
     */
    public function getNetworkTypes($id, $num_page): mixed {
      $page_ext = "";
      if ($num_page > 0) {
        $page_ext = "?page=$num_page";
      }
      return $this->executeScriptCurl(self::API_TECHNOLOGIES.'/'.$id.'/table' . $page_ext);
    }


  /**
   * @param $url
   *
   * @return bool|mixed
   */
    public function isValid($url): mixed {
      return $this->executeScriptCurl(self::API_COUNTRIES, $url);
    }


  /**
   * @param $domaine
   * @param bool $display_message
   * @param null $url
   *
   * @return bool|mixed
   */
    private function executeScriptCurl($domaine, bool $display_message = false, $url = null): mixed {

        if ($url === null) {
            $url = $this->urlApi;
        }

        $ch = curl_init($url . $domaine);
        // Will return the response, if false it print the response
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        // Execute
        $ret_value = curl_exec($ch);

        // Vérification du code d'état HTTP
        if (!curl_errno($ch)) {

            switch ($http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE)) {
                case 200:  # OK
                    if ($display_message) {
                        $this->messenger->addMessage(t('Api connected Successfully -> ' . $url . $domaine), 'status', TRUE);
                    }
                    $json_ret = json_decode($ret_value, true);
                    break;

                default:
                    if ($display_message) {
                        $this->messenger->addMessage(t('Unexpected HTTP code: ' . $http_code . ' - ' . $url . $domaine), 'error', TRUE);
                    }
                    $json_ret = false;
            }
        }

        curl_close($ch);

        return $json_ret;
    }

}
