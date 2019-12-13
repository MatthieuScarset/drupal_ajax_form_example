<?php
namespace Drupal\oab_orange_business_lounge\Controller;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;
use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Services\OabOblSwagger;
use Zend\Diactoros\Response\JsonResponse;

class OblController extends ControllerBase {

    public function oblPage() {

      /** @var OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountriesWithoutOperator();
        $technologies = $obl_service->getTechnologies();

        return array(
            '#zones' => $zones,
            '#theme' => 'orange_business_lounge_page_zone',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/obl.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["items"],
                    'arr_technologies_obl' => $technologies["items"],
                ]
            ],
        );
    }

    public function oblGetCountriesWithOperators($id) {
      $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
      $get_countries_with_op = $obl_service->getNetworkTypes($id);

      return new JsonResponse($get_countries_with_op);
    }

}
