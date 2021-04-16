<?php
namespace Drupal\oab_orange_business_lounge\Controller;
use Drupal\Core\Pager\PagerManagerInterface;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;
use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;
use Drupal\oab_orange_business_lounge\Services\OabOblSwagger;
use Symfony\Component\HttpFoundation\Request;
use Zend\Diactoros\Response\JsonResponse;

class OblController extends ControllerBase {

  /**
   * @var PagerManagerInterface
   */
  private $pageManager;

  public function __construct(PagerManagerInterface $page_manager) {
    $this->pageManager = $page_manager;
  }

    public function getTitle() {
        return "Accords roaming";
    }

    public function oblPage(Request $request) {

      $page = 0;
      if ($request->query->has('page')) {
          $page = $request->query->get('page');
      }

      /** @var OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        $zones = $obl_service->getZones();
        $countries = $obl_service->getCountriesWithoutOperator();

        $technologies = $obl_service->getTechnologies();
        $items = $technologies['items'];
        uasort($items, [$this, "sortById"]);


        if ($request->query->has('techno')
          && false !==  $this->getTechnoByName($items, $request->query->get('techno'))) {
          $actual_techno = $this->getTechnoByName($items, $request->query->get('techno'));
        } else {
          $actual_techno = reset($items);  // Else on retourne le 1er element des technos
        }

        $data = $obl_service->getNetworkTypes($actual_techno['id'], $page+1);

        foreach ($data['items'] as $row) {
          $prepared_data[$row['country']][] = $row;
        }

        $pager = $this->pageManager->createPager($data['totalItem'], $data['itemPerPage']);
        $page = $pager->getCurrentPage();

        return array (
            '#zones' => $zones,
            '#theme' => 'orange_business_lounge_page_zone',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/oab_obl_js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["items"],
                    'arr_technologies_obl' => $technologies["items"],
                    'techno' => $actual_techno,
                    'techno_name' => $this->getNameTechnoByActualTech($technologies['items'], $actual_techno['id'])
                ]
            ],
            '#detail_accords' => $prepared_data,
            '#techno' => $actual_techno['name'],
            '#techno_for_print' => $this->getNameTechnoByActualTech($technologies['items'], $actual_techno['id']),
            '#pager' => [
              '#type' => 'pager',
              '#page_id' => 'obl_controller'
            ]
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

  /**
   * @param $technologies
   * @param $actual_techno
   * @return mixed
   */
  private function getNameTechnoByActualTech($technologies, $actual_techno) {
    $ret = '';
    foreach ($technologies as $key => $technology) {
      if ($technology['id'] == $actual_techno) {
        $ret = $technology['name'];
      }
    }

    return $ret;
  }

  private function getTechnoByName($technologies, $techno_name) {
    $ret = false;
    foreach ($technologies as $techno) {
      if (isset($techno['name']) && $techno['name'] === $techno_name) {
        $ret = $techno;
      }
    }
    return $ret;
  }


}
