<?php
namespace Drupal\oab_orange_business_lounge\Controller;

use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;
use Zend\Diactoros\Response\JsonResponse;

class OblPricesController extends ControllerBase {

    public function oblPricePage($id) {

      /** @var \Drupal\oab_orange_business_lounge\Services\OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $config = \Drupal::config(OabOblForm::getConfigName());

        $zones_image = $config->getRawData()['zones_image'];

        foreach ($zones_image as $key => $image) {
            $file = \Drupal\file\Entity\File::load($image);
            $zones_image[$key] = file_create_url($file->getFileUri());
        }

        $countries = $obl_service->getCountriesWithoutOperator();

        $zones = $obl_service->getZones(false);
        $items = $zones['items'];
        usort($items, function($a, $b) {
          return $a['position'] <=> $b['position'];
        });
        //revenir à l'état initial du tableau avant le tri
        $zones = [
          'items' => $items
        ];


        return array(
            '#countries' => $countries,
            '#zones' => $zones,
            '#zones_image' => $zones_image,
            '#theme' => 'orange_business_lounge_page_pays',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/metadata.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["items"],
                    'id_country' => $id,
                    'obl_zones' => $items
                ]
            ],
        );
    }

    public function getTitle() {
      $config = \Drupal::config(OabOblForm::getConfigName());
      return $config->get('title_label');
    }

    public function oblUniqueZone($id) {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $unique_zone = $obl_service->getOneZone($id);

        return new JsonResponse($unique_zone);
    }

    public function oblUniqueCountry($id) {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $unique_countrie = $obl_service->getOneCountry($id);

        return new JsonResponse($unique_countrie);
    }
}
