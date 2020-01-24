<?php


namespace Drupal\oab_orange_business_lounge\Services;

use Drupal\oab_orange_business_lounge\Form\OabOblForm;



class OabOblSwagger {

    private $url_api = '';
    private $title_label = '';
    private $zone_id = '';

    const API_ZONE = "/zones";
    const API_PASS_DATA = '/pass_data_offers/retrieve.json';
    const API_COUNTRIES = '/root_countries?itemsPerPage=300';

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

    public function getNetworkData() {
        //return $this->executeScriptCurl("/operator/".$rootZone."/".$rootCountry);
        $toto = [
            [
                    'id' => 20,
                    'code' => "20408",
                    'rootCountry' => [
                        'france' => false,
                        'id' => 0,
                        'auroreCode' => '400',
                        'isoCode' => "CU",
                        'slug' => "cuba",
                        'label' => 'cuba',
                        'rootZone' => [
                            'id' => 3,
                            'label' => 'Business',
                        ],
                        'savAvailable' => false,
                    ],
                    'operator' => [
                        'name' => "mtn",
                        'networkNorms' => [
                            'items' => [
                                'networknorm' => "GSM (900\/1800)",
                                'type' => "GSM"
                            ]
                        ]
                    ],
                ],

            [
                'id' => 20,
                'code' => "20408",
                'rootCountry' => [
                    'france' => false,
                    'id' => 0,
                    'auroreCode' => '400',
                    'isoCode' => "CU",
                    'slug' => "cuba",
                    'label' => 'cuba',
                    'rootZone' => [
                        'id' => 3,
                        'label' => 'Business',
                    ],
                    'savAvailable' => false,
                ],
                'operator' => [
                    'name' => "CORE",
                    'networkNorms' => [
                        'items' => [
                            'networknorm' => "GSM (900\/1800)",
                            'type' => "4G"
                        ]
                    ]
                ],
            ],
         ];

        return $toto;
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

        curl_close($ch);
        return $json_ret;

    }

}