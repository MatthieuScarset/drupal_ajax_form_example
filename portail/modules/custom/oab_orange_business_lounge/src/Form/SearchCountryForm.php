<?php

namespace Drupal\oab_orange_business_lounge\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;


class SearchCountryForm extends FormBase {


  public function buildForm (array $form, FormStateInterface $form_state, $extra = NULL) {

    $form['country_autocomplete'] = [
      '#type' => 'textfield',
      '#attributes' => [
        'class' => array('countries_input_autocomplete')
      ],
      '#title' => 'Vous avez également les accords et tarifs roaming par pays de destination',
      '#required' => false,
    ];

    $form['country_id'] = [
      '#type' => 'hidden',
      '#required' => false,
    ];

    $form['actions'] = ['#type' => 'actions'];
    $form['actions']['submit'] = ['#type' => 'submit', '#value' => 'Voir les tarifs'];

    return $form;
  }

  /**
   * Returns a unique string identifying the form.
   *
   * The returned ID should be a unique string that can be a valid PHP function
   * name, since it's used in hook implementation names such as
   * hook_form_FORM_ID_alter().
   *
   * @return string
   *   The unique string identifying the form.
   */
  public function getFormId () {
      return 'search_country_form';
  }

  /**
   * Form submission handler.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   */
  public function submitForm (array &$form, FormStateInterface $form_state) {
    if ($form_state->hasValue('country_id')
        && count($form_state->getErrors()) === 0) {
      $country_id = $form_state->getValue('country_id', null);
      $form_state->setRedirect('oab_obl_country_settings', ['id' => $country_id]);
    }

  }

}
