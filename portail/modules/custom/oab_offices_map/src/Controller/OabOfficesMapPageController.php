<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_offices_map\Controller;


use Drupal\block\Entity\Block;
use Drupal\Core\Controller\ControllerBase;
use Drupal\views\Views;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

class OabOfficesMapPageController extends ControllerBase {

	public function viewPage(Request $request) {

		$officesMapView = Views::getView('offices_map_view');
		$officesMapView->setDisplay('offices_map_block');
		$officesMapView->preExecute();
		$officesMapView->execute();
		$mapBlock = $officesMapView->buildRenderable('offices_map_block', array());

		$officesMapView = Views::getView('offices_map_view');
		$officesMapView->setDisplay('offices_addresses_list_block');
		$officesMapView->preExecute();
		$officesMapView->execute();
		$officesListBlock = $officesMapView->buildRenderable('offices_addresses_list_block', array());

		return array(
			'#mapBlock' => $mapBlock,
			'#officesListBlock' => $officesListBlock,
			'#theme' => 'offices_map_page',
			'#attached' => array(
				'library' =>  array(
					'oab_offices_map/oab_offices_map.markers'
				),
			),
		);
	}
}
