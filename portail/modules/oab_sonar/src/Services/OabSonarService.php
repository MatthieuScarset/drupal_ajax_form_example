<?php


namespace Drupal\oab_sonar\Services;

use Drupal\oab_sonar\Form\OabSonarForm;



class OabOblSonar {

    private $tokenSonar = '';
    private $urlSonar = '';
    private $projetSonar = '';
    private $metricsSonar = '';
    private $emailsSonar = '';


    public function __construct() {
        $config = \Drupal::config(OabSonarForm::getConfigName());
        $this->tokenSonar = $config->get('token_sonar');
        $this->urlSonar = $config->get('url_sonar');
        $this->projetSonar = $config->get('projet_sonar');
        $this->metricsSonar = $config->get('metrics_sonar');
        $this->emailsSonar = $config->get('emails_sonar');
    }


    /**
     * @return mixed
     */
    public function generateUrl($component) {

        $url = $this->urlSonar . '/' . $component;

        if (count($this->metricsSonar) > 0 ) {
            $url .= "?";

            foreach ($this->metricsSonar as $key => $param) {
                $url .= "$key=$param&";
            }

            // Suppression du dernier "&" de l'URL
            $url = rtrim($url, "&");

        }

        return $url;
    }

    /**
     * @return mixed
     */
    public function get($component) {
        
    }

    /**
     * @return mixed
     */
    public function getOneZone($id) {
        return $this->executeScriptCurl("/zones/".$id);
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
