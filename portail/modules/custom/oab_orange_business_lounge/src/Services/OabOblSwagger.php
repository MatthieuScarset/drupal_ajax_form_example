<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\oab_orange_business_lounge\Form\OabOblForm;



class OabOblSwagger {

    private $url_api = '';
    private $title_label = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/root_countries?itemsPerPage=300';
    const  API_OPER_COUNTRIES = '/countries';

    public function __construct() {
        $config = \Drupal::config(OabOblForm::getConfigName());
        $this->url_api = $config->get('url_api');
        $this->title_label = $config->get('title_label');
    }


    /**
     * @return mixed
     */
    public function getCountries () {
        $data = $this->executeScriptCurl(self::API_COUNTRIES);
        return $data;
    }

    /**
     * @return mixed
     */
    public function getZones () {
        $data = $this->executeScriptCurl(self::API_ZONE);
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
    public function getPassData () {
        $data = $this->executeScriptCurl(self::API_PASS_DATA);
        return $data;
    }

    /**
     * @return mixed
     */
    public function getOneCountry($id) {
      return $this->executeScriptCurl(self::API_OPER_COUNTRIES.'/'.$id);
    }

    /**
     * @return mixed
     */
    public function getCountriesWithOperator () {
      return $this->executeScriptCurl(self::API_OPER_COUNTRIES);
    }

    /**
     * @param $url
     * @return bool|mixed
     */
    public function isValid($url) {
        return $this->executeScriptCurl(self::API_COUNTRIES, $url);
    }


    /**
     * @param $domaine
     * @param null $url
     * @return bool|mixed
     */
    private function executeScriptCurl($domaine, $url = null) {

        if ($url === null) {
            $url = $this->url_api;
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
                    $json_ret = json_decode($ret_value, true);
                    break;

                default:
                    $json_ret = false;
            }
        }

        curl_close($ch);
        return $json_ret;

    }

}
