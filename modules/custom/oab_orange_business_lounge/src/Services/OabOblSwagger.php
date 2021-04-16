<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\Core\Messenger\MessengerInterface;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;
use Symfony\Component\DependencyInjection\ContainerInterface;


class OabOblSwagger {

    private $urlApi = '';
    private $titleLabel = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/countries';
    const API_TECHNOLOGIES = '/network-types';

  /**
   * @var MessengerInterface
   */
    private $messenger;

  /**
   * OabOblSwagger constructor.
   */
  public function __construct() {
        $config = \Drupal::config(OabOblForm::getConfigName());
        $this->urlApi = $config->get('url_api');
        $this->titleLabel = $config->get('title_label');
        $this->messenger = \Drupal::messenger();
    }


    /**
     * @return mixed
     */
    public function getCountriesWithoutOperator() {
        $data = $this->executeScriptCurl(self::API_COUNTRIES);
        return $data;
    }

    /**
     * @return mixed
     */
    public function getZones($display_message = false) {
        $data = $this->executeScriptCurl(self::API_ZONE, $display_message);
        return $data;
    }

    /**
     * @return mixed
     */
    public function getOneZone($id) {
      return $this->executeScriptCurl(self::API_ZONE.'/'.$id);
    }

    /**
     * @return mixed
     */
    public function getPassData() {
        $data = $this->executeScriptCurl(self::API_PASS_DATA);
        return $data;
    }

    /**
     * @return mixed
     */
    public function getOneCountry($id) {
        return $this->executeScriptCurl("/countries/".$id);
    }


    /**
     * @return bool|mixed
     */
    public function getTechnologies() {
      return $this->executeScriptCurl(self::API_TECHNOLOGIES);
    }


    /**
     * @return bool|mixed
     */
    public function getNetworkTypes($id, $num_page) {
      $page_ext = "";
      if ($num_page > 0) {
        $page_ext = "?page=$num_page";
      }
      return $this->executeScriptCurl(self::API_TECHNOLOGIES.'/'.$id.'/table' . $page_ext);
    }


    /**
     * @param $url
     */
    public function isValid($url) {
        $this->executeScriptCurl(self::API_COUNTRIES, $url);
    }


    /**
     * @param $domaine
     * @param null $url
     * @return bool|mixed
     */
    private function executeScriptCurl($domaine, $display_message = false, $url = null) {

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
                        $this->messenger->addError(t('Unexpected HTTP code: ' . $http_code . ' - ' . $url . $domaine), TRUE);
                    }
                    $json_ret = false;
            }
        }

        curl_close($ch);
        return $json_ret;

    }

}
