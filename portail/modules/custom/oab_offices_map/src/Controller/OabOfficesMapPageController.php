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
use Drupal\Core\Url;
use Drupal\taxonomy\Plugin\views\wizard\TaxonomyTerm;
use Drupal\views\Views;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabOfficesMapPageController extends ControllerBase {

	public function getPageTitle(){
		return t("Our local offices");
	}

	public function viewPage(Request $request) {

		$current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
		if($current_language == "fr")
		{
			//on lance une 404
			throw new NotFoundHttpException();
		}
		else {
			//paramètres :
			$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
			$region_id = (!empty($parameters) && isset($parameters['region']) && $parameters['region'] != 'All') ? $parameters['region'] : 'all';
			$country_id = (!empty($parameters) && isset($parameters['country']) && $parameters['country'] != 'All') ? $parameters['country'] : 'all';
			if(($current_language == "ru" && !empty($country_id) && $country_id =="ru")
			|| ($current_language == "ru" && !empty($country_id) && $country_id =="all" && (empty($region_id) || $region_id == "all")))
			{
				// si l'url est /ru/contacts ou /ru/contacts?country=ru => on redirige vers le bon id du pays Russia
				$query = \Drupal::entityQuery('taxonomy_term');
				$query->condition('vid', 'office_countries');
				$query->condition('name', 'Russia');
				$entity = $query->execute();

				if(!empty($entity))
				{
					$country_id = array_pop(array_values($entity));
				}
				$current_route = \Drupal::routeMatch()->getRouteName();
				$option = [
					'query' => array('region' => $region_id, 'country' => $country_id),
				];
				$url = Url::fromRoute($current_route, array(), $option);
				return new RedirectResponse($url->toString());
			}
			else {
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

				$regionsCountriesForm = \Drupal::formBuilder()
					->getForm('Drupal\oab_offices_map\Form\MapRegionsCountriesForm');

				$listLabel = t('All offices');
				if ($region_id != 'all') {
					$region = \Drupal\taxonomy\Entity\Term::load($region_id);
					$listLabel = $region->label() . ' offices';
				}
				return array(
					'#mapBlock' => $mapBlock,
					'#officesListBlock' => $officesListBlock,
					'#regionsCountriesForm' => $regionsCountriesForm,
					'#labelList' => $listLabel,
					'#theme' => 'offices_map_page',
					'#attached' => array(
						'library' => array(
							'oab_offices_map/oab_offices_map.markers'
						),
						'drupalSettings' => array(
							'countriesRegionsTab' => getArrayRegionsCountries(),
							'allCountriesArray' => getCountriesForJS(),
						),
					),
				);
			}
		}
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
		//tableau [pays id] => region id
		$table_country_region = array();
		foreach ($results as $rowCountryRegion){
			$table_country_region[$rowCountryRegion->country_tid] = $rowCountryRegion->region_tid;
		}

		return $table_country_region;
	}


	private function getCountries(){
		$keys = array();
		$query = Database::getConnection()->select('node_field_data', 'n');
		$query->leftjoin('node__field_office_country', 'c', 'n.nid = c.entity_id');
		$query->leftjoin('taxonomy_term_field_data', 'oc', 'oc.tid = c.field_office_country_target_id');
		$query->condition('n.type', 'office', '=');
		$query->condition('n.status', 1, '=');
		$query->addField('oc', 'tid', 'country_tid');
		$query->addField('oc', 'name', 'country_name');
		$query->orderBy('oc.name');
		$results =	$query->execute()->fetchAll();

		$table_countries = array();
		$table_countries['all'] = $this->t('Country');
		foreach ($results as $country){
			if(!in_array($country->country_tid, $keys) && !empty($country->country_tid)){
				$keys[] = $country->country_tid;
				$table_countries[] = array('id' => $country->country_tid, "name" => $country->country_name);
			}
		}
		return $table_countries;
	}

}
