<?php
namespace Drupal\oab_orange_business_lounge\Controller;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;
use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Services\OabOblSwagger;

class OblController extends ControllerBase {

    public function oblPage() {

      /** @var OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountries();

        $countries_with_operator = $obl_service->extractingUsefulData();
        $technologies = $obl_service->getTechnologies();

        return array(
            '#zones' => $zones,
            '#theme' => 'orange_business_lounge_page_zone',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/obl.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["hydra:member"],
                    'arr_technologies_obl' => $technologies["items"],
                    'arr_country_with_op' => $countries_with_operator
                ]
            ],
        );
    }
}
