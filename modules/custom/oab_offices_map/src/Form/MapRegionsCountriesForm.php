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
            $query = \Drupal::request()->query;
            $selected_region = $query->has('region') ? $query->get('region') : 'all';
            $selected_country = $query->has('country') ? $query->get('country') : 'all';
        }

        $regions = getRegions();
        $countries = getCountries();

        $form['region'] = [
            '#multiple_toggle' => '1',
            '#type' => 'select',
            '#options' => $regions,
            '#default_value' => $selected_region,
            '#attributes' => [
              'class' => ['select-regions']
            ],
            '#form_id' => $this->getFormId(),
            '#label' => $regions['all'],
        ];
        $form['country'] = [
            '#multiple_toggle' => '1',
            '#type' => 'select',
            '#options' => $countries,
            '#default_value' => $selected_country,
            '#attributes' => [
              'class' => ['select-countries']
            ],
            '#form_id' => $this->getFormId(),
            '#label' => $countries['all'],
        ];


        $form['submit'] = [
            '#type' => 'submit',
            '#value' => $this->t('Apply'),
            '#name' => 'apply',
            '#attributes' => [
              'class' => ['btn', 'btn-secondary']
            ]
        ];

        // C'est moche, mais plus le temps :p et puis hein, voilà quoi fuck
        // Ajout de classe spécifiques pour le templates One-I
        if (\Drupal::theme()->getActiveTheme()->getName() === 'theme_one_i') {

          $form['#attributes']['class'][] = "form-inline";
          $form['#attributes']['class'][] = "mb-2";

          $form["buttons"] = [
            '#type' => 'actions',
            '#attributes' => [
              'class' => ['align-self-end', 'pt-sm-1']
            ]
          ];

          $form["buttons"]['submit'] = $form['submit'];
          unset($form['submit']);
          $form["buttons"]['submit']['#attributes']['class'] = array_merge(
            $form["buttons"]['submit']['#attributes']['class'],
            ['align-self-end', 'mr-1', 'mb-1', 'mb-sm-0']
          );

          $form["buttons"]['clear'] = [
            '#type' => 'submit',
            '#value' => $this->t('Clear'),
            '#name' => 'clear',
            '#attributes' => [
              'class' => ['btn', 'btn-secondary', 'align-self-md-end', 'mb-1', 'mb-sm-0']
            ],
          ];
        }

        return $form;
    }

    public function submitForm(array &$form, FormStateInterface $form_state) {

        // Commentaire Tristan : je sais pas à quoi sert ce code, ni ce qu'il fait
        // D'autant que le formulaire est affiché dans un controller et pas dans un node
        // C'est peut être un résidu d'un copié/collé depuis D7
        $current_route = \Drupal::routeMatch()->getRouteName();
        $route_parameters = array();
        if ($current_route == 'entity.node.canonical') {
            $route_parameters['node'] = \Drupal::routeMatch()->getRawParameter('node');
        }
        $input = &$form_state->getUserInput();

        if (isset($input['Clear'])) {
          $option = [
            'query' => array('region' => 'all', 'country' => 'all'),
          ];
        } else {
          $option = [
            'query' => array('region' => $input["region"] ?? 'all', 'country' => $input["country"] ?? 'all'),
          ];
        }

        $url = Url::fromRoute($current_route, $route_parameters, $option);
        $form_state->setRedirectUrl($url);
    }

    public function clearForm(array &$form, FormStateInterface $form_state) {
      echo "coucou";
    }
}
