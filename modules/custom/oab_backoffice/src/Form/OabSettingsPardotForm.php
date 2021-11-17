<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsPardotForm extends ConfigFormBase {

  public static function getConfigName() {
    return 'oab_backoffice.pardot';
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_pardot';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_backoffice.pardot',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('oab_backoffice.pardot');

    /* Window general */
    $form['tabs_general'] = [
      '#type' => 'vertical_tabs',
      '#tree' => true
    ];

    /* Tab for Marketo */
    $form['marketo'] = [
      '#type' => 'details',
      '#title' => t('Marketo'),
      '#group' => "tabs_general"
    ];

    /* Tab for Pardot */
    $form['Pardot'] = [
      '#type' => 'details',
      '#title' => t('Pardot'),
      '#group' => "tabs_general"
    ];


    /** My fields for Marketo **/

    $form['marketo']['general'] = [
      '#type' => "fieldset",
      '#title' => $this->t("General conf"),
      '#description' => $this->t("Configuration for all marketo forms"),
    ];

    $form['marketo']['general']['mkto_domain'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Domain'),
      '#default_value' => $config->get('marketo.general.mkto_domain'),
      '#description' => 'API domain : ' . $config->get('marketo.general.mkto_domain'),
      '#size'=> 80,
    );

    $form['marketo']['general']['mkto_munchkin_id'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Munchkin Id'),
      '#default_value' => $config->get('marketo.general.mkto_munchkin_id'),
      '#size'=> 350,
    );

    $form['marketo']['general']['mkto_version'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Version'),
      '#default_value' => $config->get('marketo.general.mkto_version'),
      '#size'=> 350,
    );

    $form['marketo']['general']['mkto_sous_domaine'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Sous domaine'),
      '#default_value' => $config->get('marketo.general.mkto_sous_domaine'),
      '#size'=> 350,
    );

    $form['marketo']['general']['mkto_univers_affichage'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Univers affichage'),
      '#default_value' => $config->get('marketo.general.mkto_univers_affichage'),
      '#size'=> 350,
    );

    $form['marketo']['general']['libraries']['awe'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Librairie AWE'),
      '#default_value' => $config->get('marketo.general.libraries.awe'),
      '#size'=> 350,
    );

    $form['marketo']['general']['libraries']['simple_dto'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Librairie SimpleDTO'),
      '#default_value' => $config->get('marketo.general.libraries.simple_dto'),
      '#size'=> 350,
    );

    $form['marketo']['general']['libraries']['enhanced_form'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Librairie enhancedForm'),
      '#default_value' => $config->get('marketo.general.libraries.enhanced_form'),
      '#size'=> 350,
    );

    $form['marketo']['general']['libraries']['forms2'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Librairie forms2'),
      '#default_value' => $config->get('marketo.general.libraries.forms2'),
      '#size'=> 350,
    );

    $form['marketo']['general']['libraries']['photoclient'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Librairie PhotoClient'),
      '#default_value' => $config->get('marketo.general.libraries.photoclient'),
      '#size'=> 350,
    );

    $form['marketo']['document'] = [
      '#type' => "fieldset",
      '#title' => $this->t("Document marketo form settings"),
      '#description' => $this->t("Specific config for document marketo form")
    ];

    $form['marketo']['document']['mkto_form_name'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Form name'),
      '#default_value' => $config->get('marketo.document.mkto_form_name'),
      '#size'=> 80,
    );

    $form['marketo']['document']['mkto_form_id'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Form Id'),
      '#default_value' => $config->get('marketo.document.mkto_form_id'),
      '#size'=> 350,
    );

    $form['marketo']['document']['mkto_custom_follow_up_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Custom follow up URL'),
      '#default_value' => $config->get('marketo.document.mkto_custom_follow_up_url'),
      '#size'=> 350,
    );

    $mkt_follow_up = $config->get('marketo.document.mkto_form_follow_up_message');
    $form['marketo']['document']['mkto_form_follow_up_message'] = array(
      '#type' => 'text_format',
      '#title' => $this->t('Form follow up message'),
      '#default_value' => $mkt_follow_up['value'] ?: "",
      '#format'=> $mkt_follow_up['format'] ?: 'full_html',
    );


    #############################
    ## My field for Pardot
    $form['Pardot']['iframe_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('iframe url'),
      '#default_value' => $config->get('pardot.iframe_url'),
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration

    $this->config('oab_backoffice.pardot')
      ->set('marketo.general.mkto_domain', $form_state->getValue('mkto_domain'))
      ->set('marketo.general.mkto_munchkin_id', $form_state->getValue('mkto_munchkin_id'))
      ->set('marketo.general.mkto_version', $form_state->getValue('mkto_version'))
      ->set('marketo.general.mkto_sous_domaine', $form_state->getValue('mkto_sous_domaine'))
      ->set('marketo.general.mkto_univers_affichage', $form_state->getValue('mkto_univers_affichage'))
      ->set('marketo.general.libraries.awe', $form_state->getValue('awe'))
      ->set('marketo.general.libraries.simple_dto', $form_state->getValue('simple_dto'))
      ->set('marketo.general.libraries.enhanced_form', $form_state->getValue('enhanced_form'))
      ->set('marketo.general.libraries.forms2', $form_state->getValue('forms2'))
      ->set('marketo.general.libraries.photoclient', $form_state->getValue('photoclient'))
      ->set('marketo.document.mkto_form_name', $form_state->getValue('mkto_form_name'))
      ->set('marketo.document.mkto_form_id', $form_state->getValue('mkto_form_id'))
      ->set('marketo.document.mkto_custom_follow_up_url', $form_state->getValue('mkto_custom_follow_up_url'))
      ->set('marketo.document.mkto_form_follow_up_message', $form_state->getValue('mkto_form_follow_up_message'))

      /* for Pardot */
      ->set('pardot.iframe_url', $form_state->getValue('iframe_url'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
