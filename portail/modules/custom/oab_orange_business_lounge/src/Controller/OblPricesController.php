<?php
namespace Drupal\oab_orange_business_lounge\Controller;

use \Drupal\Core\Controller\ControllerBase;
use Drupal\migrate_plus\Plugin\migrate_plus\data_parser\Json;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;
use Zend\Diactoros\Response\JsonResponse;

class OblPricesController extends ControllerBase {

    public function oblPricePage() {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $config = \Drupal::config(OabOblForm::getConfigName());

        $countries = $obl_service->getCountries();
        $zones = $obl_service->getZones();
        $pass_data = $obl_service->getPassData();
        $title = $config->get('title_label');
       // kint($countries);

        return array(
            '#countries' => $countries,
            '#zones' => $zones,
            '#pass_data' => $pass_data,
            '#title' => $title,
            '#theme' => 'orange_business_lounge_page_pays',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/metadata.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["hydra:member"],
                ]
            ],

        );
    }

    public function oblUniqueZone($id) {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $unique_zone = $obl_service->getOneZone($id);
        
        return new JsonResponse($unique_zone);
    }
}
