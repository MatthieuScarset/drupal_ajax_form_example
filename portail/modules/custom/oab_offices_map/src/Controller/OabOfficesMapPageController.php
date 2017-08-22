<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_offices_map\Controller;


use Drupal\block\Entity\Block;
use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\views\Views;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

class OabOfficesMapPageController extends ControllerBase {

	public function viewPage(Request $request) {

		//paramètres :
		$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
		$region_id = (!empty($parameters) && isset($parameters['region']) && $parameters['region'] != 'All') ? $parameters['region'] : 'all';
		$country_id = (!empty($parameters) && isset($parameters['country']) && $parameters['country'] != 'All') ? $parameters['country'] : 'all';

		$officesMapView = Views::getView('offices_map_view');
		$officesMapView->setDisplay('offices_map_block');
		$officesMapView->args = array($region_id, $country_id);
		$officesMapView->preExecute();
		$officesMapView->execute();
		$mapBlock = $officesMapView->buildRenderable('offices_map_block', array());

		$officesMapView = Views::getView('offices_map_view');
		$officesMapView->setDisplay('offices_addresses_list_block');
		$officesMapView->args = array($region_id, $country_id);
		$officesMapView->preExecute();
		$officesMapView->execute();
		$officesListBlock = $officesMapView->buildRenderable('offices_addresses_list_block', array());

		$regionsCountriesForm = \Drupal::formBuilder()->getForm('Drupal\oab_offices_map\Form\OabOfficesMapRegionsCountriesForm');
		return array(
			'#mapBlock' => $mapBlock,
			'#officesListBlock' => $officesListBlock,
			'#regionsCountriesForm' => $regionsCountriesForm,
			'#theme' => 'offices_map_page',
			'#attached' => array(
				'library' =>  array(
					'oab_offices_map/oab_offices_map.markers'
				),
			),
		);
	}

}
