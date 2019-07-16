<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\oab_orange_business_lounge\Form\OabOblForm;



class OabOblSwagger {

    private $url_api = '';
    private $title_label = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/root_countries?itemsPerPage=300';

    public function __construct() {
        $config = \Drupal::config(OabOblForm::getConfigName());
        $this->url_api = $config->get('url_api');
        $this->title_label = $config->get('title_label');
        echo 'Yo '. $this->title_label; die();
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
    public function getPassData () {
        $data = $this->executeScriptCurl(self::API_PASS_DATA);
        return $data;
    }

    public function getTitle() {
        return $this->title_label;
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
                    drupal_set_message(t('Api connected Successfully -> ' . $url . $domaine), 'status', TRUE);
                    $json_ret = json_decode($ret_value, true);
                    break;

                default:
                    drupal_set_message(t('Unexpected HTTP code: ' . $http_code . ' - ' . $url . $domaine), 'error', TRUE);
                    $json_ret = false;
            }
        }

        return $json_ret;
        curl_close($ch);
    }

}