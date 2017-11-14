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

		$regions = getRegions();
		$countries = getCountries();
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