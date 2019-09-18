<?php
namespace Drupal\oab_orange_business_lounge\Controller;

use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;

class OblController extends ControllerBase {

    public function oblPage() {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountries();

        $countriesWithoutOperator = $obl_service->getCountriesWithOperator();

        foreach ($countriesWithoutOperator['items'] as $tab) {
            $countriesWithOperators[] =  $obl_service->getOperator($tab['id']);
        }

        $mon_form = \Drupal::formBuilder()->getForm(SearchCountryForm::class);

        return array(
            '#zones' => $zones,
            '#mon_form' => $mon_form,
            '#countriesWithOperators' => $countriesWithOperators,
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
