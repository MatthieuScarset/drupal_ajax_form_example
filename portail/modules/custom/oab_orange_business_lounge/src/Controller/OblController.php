<?php
namespace Drupal\oab_orange_business_lounge\Controller;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;
use \Drupal\Core\Controller\ControllerBase;

class OblController extends ControllerBase {

    public function oblPage() {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountries();

      $countries_without_operator = $obl_service->getCountriesWithOperator();

      $i = 0;
      foreach ($countries_without_operator['items'] as $tab) {
        $countries_with_operator[] =  $obl_service->getOneCountry($tab['id']);
        if (++$i > 30) break;
      }

        return array(
            '#zones' => $zones,
            '#countriesWithOperators' => $countries_with_operator,
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
