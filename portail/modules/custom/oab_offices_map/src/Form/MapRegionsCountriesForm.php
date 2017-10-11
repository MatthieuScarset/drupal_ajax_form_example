<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 22/08/2017
 * Time: 17:00
 */
namespace Drupal\oab_offices_map\Form;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Database\Database;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

class MapRegionsCountriesForm extends FormBase {
	/**
	 * {@inheritdoc}
	 */
	public function getFormId() {
		return 'oab_offices_map_regions_countries_form';
	}

	/**
	 * {@inheritdoc}
	 */
	public function buildForm(array $form, FormStateInterface $form_state) {

		$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
		$selectedRegion = (!empty($parameters) && isset($parameters['region']) && $parameters['region'] != 'All') ? $parameters['region'] : 'all';
		$selectedCountry = (!empty($parameters) && isset($parameters['country']) && $parameters['country'] != 'All') ? $parameters['country'] : 'all';

		$regions = $this->getRegions();
		$countries = $this->getCountries();
		$form['region'] = [
			'#multiple_toggle' => '1',
			'#type' => 'select',
			'#options' => $regions,
			'#default_value' => $selectedRegion,
			'#attributes' => array('class' => array('select-regions')),
		];
		$form['country'] = [
			'#multiple_toggle' => '1',
			'#type' => 'select',
			'#options' => $countries,
			'#default_value' => $selectedCountry,
			'#attributes' => array('class' => array('select-countries')),
		];
		$form['submit'] = [
			'#type' => 'submit',
			'#value' => $this->t('Apply'),
			'#name' => $this->t('Apply'),
		];
		return $form;
	}


	private function getCountries(){
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
			if(!array_key_exists($country->country_tid, $table_countries) && !empty($country->country_tid)){
				$table_countries[$country->country_tid] = $country->country_name;
			}
		}
		return $table_countries;
	}

	private function getRegions(){
		$query = Database::getConnection()->select('node_field_data', 'n');
		$query->leftjoin('node__field_region', 'r', 'n.nid = r.entity_id');
		$query->leftjoin('taxonomy_term_field_data', 't', 't.tid = r.field_region_target_id');
		$query->condition('n.type', 'office', '=');
		$query->condition('n.status', 1, '=');
		$query->addField('t', 'tid', 'region_tid');
		$query->addField('t', 'name', 'region_name');
    $query->addField('t', 'langcode', 'region_langcode');
		$query->orderBy('t.name');
		$results =	$query->execute()->fetchAll();

		$table_regions = array();
		$table_regions['all'] = $this->t('Region');


    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    foreach ($results as $region){
			if(!array_key_exists($region->region_tid, $table_regions)
            && !empty($region->region_tid)
            && $region->region_langcode == $current_language ){
			  $table_regions[$region->region_tid] = $region->region_name;
			}
		}
		return $table_regions;
	}

	/**
	 * {@inheritdoc}
	 */
	public function submitForm(array &$form, FormStateInterface $form_state){
		$current_route = \Drupal::routeMatch()->getRouteName();
		$input = &$form_state->getUserInput();
		$option = [
			'query' => array('region' => $input["region"], 'country' => $input["country"]),
		];
		$url = Url::fromRoute($current_route, array(), $option);
		$form_state->setRedirectUrl($url);
	}
}