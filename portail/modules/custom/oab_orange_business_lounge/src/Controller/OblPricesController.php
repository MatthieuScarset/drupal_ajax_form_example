<?php
namespace Drupal\oab_orange_business_lounge\Controller;

use \Drupal\Core\Controller\ControllerBase;
use Drupal\oab_orange_business_lounge\Form\OabOblForm;
use Zend\Diactoros\Response\JsonResponse;

class OblPricesController extends ControllerBase {

    public function oblPricePage($id) {

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $config = \Drupal::config(OabOblForm::getConfigName());

        $zones_image = $config->getRawData()['zones_image'];

        foreach ($zones_image as $key => $image) {
            $file = \Drupal\file\Entity\File::load($image);
            $zones_image[$key] = file_create_url($file->getFileUri());
        }

        $countries = $obl_service->getCountriesWithoutOperator();
        $zones = $obl_service->getZones(false);
        $title = $config->get('title_label');

        return array(
            '#countries' => $countries,
            '#countrie_id' => $id,
            '#zones' => $zones,
            '#zones_image' => $zones_image,
            '#title' => $title,
            '#theme' => 'orange_business_lounge_page_pays',
            '#attached' => [
                'library' => [
                    'oab_orange_business_lounge/js/metadata.js',
                ],
                'drupalSettings' => [
                    'arr_contries' => $countries["items"],
                    //'id_country' => $id
                ]
            ],

        );
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
