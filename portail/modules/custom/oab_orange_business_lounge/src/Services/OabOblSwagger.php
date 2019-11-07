<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\oab_orange_business_lounge\Form\OabOblForm;



class OabOblSwagger {

    private $urlApi = '';
    private $titleLabel = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/countries';

    public function __construct() {
        $config = \Drupal::config(OabOblForm::getConfigName());
        $this->urlApi = $config->get('url_api');
        $this->titleLabel = $config->get('title_label');
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
                        drupal_set_message(t('Api connected Successfully -> ' . $url . $domaine), 'status', TRUE);
                    }
                    $json_ret = json_decode($ret_value, true);
                    break;

                default:
                    if ($display_message) {
                        drupal_set_message(t('Unexpected HTTP code: ' . $http_code . ' - ' . $url . $domaine), 'error', TRUE);
                    }
                    $json_ret = false;
            }
        }

        curl_close($ch);
        return $json_ret;

    }

}
