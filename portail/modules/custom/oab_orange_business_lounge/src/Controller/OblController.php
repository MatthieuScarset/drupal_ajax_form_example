<?php
namespace Drupal\oab_orange_business_lounge\Controller;
use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Services\OabOblSwagger;
use Symfony\Component\HttpFoundation\Request;
use Zend\Diactoros\Response\JsonResponse;

class OblController extends ControllerBase {

    public function oblPage(Request $request) {

      $page = 1;
      if ($request->query->has('page')) {
          $page = $request->query->get('page');
      }

      /** @var OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountriesWithoutOperator();

        $technologies = $obl_service->getTechnologies();
        $items = $technologies['items'];
        kint($items);
        uasort($items, [$this, "sortById"]);
        kint($items);


        $actual_techno = $request->query->has('techno') && $request->query->get('techno') !== 0
            ? $request->query->get('techno')
            : reset($items);


        $data = $obl_service->getNetworkTypes($actual_techno['id'], $page);
        $prepared_data = [];
        foreach ($data['items'] as $row) {
          $prepared_data[$row['country']][] = $row;
        }

        $max_limit_page = ceil($data['totalItem']/$data['itemPerPage']);

        return array (
            '#zones' => $zones,
            '#theme' => 'orange_business_lounge_page_zone',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/obl.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["items"],
                    'arr_technologies_obl' => $technologies["items"],
                    'techno' => $actual_techno
                ]
            ],
            '#detail_accords' => $prepared_data,
            '#page' => $page,
            '#techno' => $actual_techno['id'],
            '#max_limit_page' => $max_limit_page
        );
    }

    public function oblGetCountriesWithOperators($id, $page) {

      $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
      $get_countries_with_op = $obl_service->getNetworkTypes($id, $page);

      return new JsonResponse($get_countries_with_op);
    }

    /*
     * sort tab technos
     */
    public function sortById($a, $b) {
      return $a["id"] > $b["id"];
    }


}
