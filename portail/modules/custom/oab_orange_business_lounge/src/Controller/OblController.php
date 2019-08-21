<?php
namespace Drupal\oab_orange_business_lounge\Controller;

use \Drupal\Core\Controller\ControllerBase;

class OblController extends ControllerBase {

    public function oblPage() {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountries();

        return array(
            '#zones' => $zones,
            '#countries' => $countries,
            '#theme' => 'orange_business_lounge_page_zone',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/obl.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["hydra:member"],
                ]
            ],
        );
    }
}
