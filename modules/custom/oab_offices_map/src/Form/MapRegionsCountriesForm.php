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
        $arguments = $form_state->getBuildInfo()['args'];
        if (count($arguments) > 0) {
            //oabt($arguments);
            $selected_region = (isset($arguments[0]['region_id']) && !empty($arguments[0]['region_id'])) ? $arguments[0]['region_id'] : 'all';
            $selected_country = (isset($arguments[0]['country_id']) && !empty($arguments[0]['country_id'])) ?$arguments[0]['country_id'] : 'all';
        }
        else {
            $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
            $selected_region = (!empty($parameters) && isset($parameters['region']) && $parameters['region'] != 'All') ? $parameters['region'] : 'all';
            $selected_country = (!empty($parameters) && isset($parameters['country']) && $parameters['country'] != 'All') ? $parameters['country'] : 'all';
        }

        $regions = getRegions();
        $countries = getCountries();
        $form['region'] = [
            '#multiple_toggle' => '1',
            '#type' => 'select',
            '#options' => $regions,
            '#default_value' => $selected_region,
            '#attributes' => array('class' => array('select-regions')),
        ];
        $form['country'] = [
            '#multiple_toggle' => '1',
            '#type' => 'select',
            '#options' => $countries,
            '#default_value' => $selected_country,
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
    public function submitForm(array &$form, FormStateInterface $form_state) {
        $current_route = \Drupal::routeMatch()->getRouteName();
        $route_parameters = array();
        if ($current_route == 'entity.node.canonical') {
            $route_parameters['node'] = \Drupal::routeMatch()->getRawParameter('node');
        }
        $input = &$form_state->getUserInput();
        $option = [
            'query' => array('region' => $input["region"], 'country' => $input["country"]),
        ];
        $url = Url::fromRoute($current_route, $route_parameters, $option);
        $form_state->setRedirectUrl($url);
    }
}
