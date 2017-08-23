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
use Drupal\taxonomy\Plugin\views\wizard\TaxonomyTerm;
use Drupal\views\Views;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

class OabOfficesMapPageController extends ControllerBase {

	public function getPageTitle(){
		return t("Our local offices");
	}

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

		$listLabel = t('All offices');
		if($region_id != 'all'){
			$region =  \Drupal\taxonomy\Entity\Term::load($region_id);
			$listLabel = $region->label().' offices';
		}
		return array(
			'#mapBlock' => $mapBlock,
			'#officesListBlock' => $officesListBlock,
			'#regionsCountriesForm' => $regionsCountriesForm,
			'#labelList' => $listLabel,
			'#theme' => 'offices_map_page',
			'#attached' => array(
				'library' =>  array(
					'oab_offices_map/oab_offices_map.markers'
				),
				'drupalSettings' =>  array(
					'countriesRegionsTab' => $this->getArrayRegionsCountries(),
				),
			),
		);
	}

	private function getArrayRegionsCountries(){
		$query = Database::getConnection()->select('node_field_data', 'n');
		$query->leftjoin('node__field_office_country', 'c', 'n.nid = c.entity_id');
		$query->leftjoin('taxonomy_term_field_data', 'oc', 'oc.tid = c.field_office_country_target_id');
		$query->leftjoin('taxonomy_term__field_country_code', 'occ', 'occ.entity_id = c.field_office_country_target_id');
		$query->leftjoin('node__field_region', 'r', 'n.nid = r.entity_id');
		$query->leftjoin('taxonomy_term_field_data', 't', 't.tid = r.field_region_target_id');
		$query->condition('n.type', 'office', '=');
		$query->condition('n.status', 1, '=');
		$query->addField('t', 'tid', 'region_tid');
		$query->addField('t', 'name', 'region_name');
		$query->addField('oc', 'tid', 'country_tid');
		$query->addField('oc', 'name', 'country_name');
		$query->addField('occ', 'field_country_code_value', 'country_code');
		$results =	$query->execute()->fetchAll();
		/*
		$table_regions_countries = array();
		foreach ($results as $rowCountryRegion){
			if((!array_key_exists($rowCountryRegion->region_tid, $table_regions_countries)
					|| !in_array($rowCountryRegion->country_tid, $table_regions_countries[$rowCountryRegion->region_tid]))
				&& !empty($rowCountryRegion->region_tid)){
				$table_regions_countries[$rowCountryRegion->region_tid][] = $rowCountryRegion->country_tid;
			}
		}*/

		//tableau [pays id] => region id
		$table_country_region = array();
		foreach ($results as $rowCountryRegion){
			$table_country_region[$rowCountryRegion->country_tid] = $rowCountryRegion->region_tid;
		}

		return $table_country_region;
	}

}
