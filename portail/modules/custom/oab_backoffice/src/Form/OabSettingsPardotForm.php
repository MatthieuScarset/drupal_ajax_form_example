<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsPardotForm extends ConfigFormBase {
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
    $form['Marketo'] = [
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

    $form['Marketo']['mkt_to_domain'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('mktToDomain'),
      '#default_value' => $config->get('mkt_to_domain'),
      '#description' => 'API domain : ' . $config->get('mkt_to_domain'),
      '#size'=> 80,
    );

    $form['Marketo']['mkt_form_name'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('formName'),
      '#default_value' => $config->get('mkt_form_name'),
      '#description' => 'API domain : ' . $config->get('mkt_form_name'),
      '#size'=> 80,
    );

    $form['Marketo']['mkt_to_munchkin_id'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('mktToMunchkinId'),
      '#default_value' => $config->get('mkt_to_munchkin_id'),
      '#size'=> 350,
    );

    $form['Marketo']['mkt_to_form_id'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('mktToFormId'),
      '#default_value' => $config->get('mkt_to_form_id'),
      '#size'=> 350,
    );

    $form['Marketo']['mkt_custom_follow_up_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('customFollowUpUrl'),
      '#default_value' => $config->get('mkt_custom_follow_up_url'),
      '#size'=> 350,
    );

    $form['Marketo']['mkt_form_follow_up_message'] = array(
      '#type' => 'textarea',
      '#title' => $this->t('formFollowUpMessage'),
      '#default_value' => $config->get('mkt_form_follow_up_message'),
      '#size'=> 350,
    );

    echo'<hr>';

    $form['Marketo']['mkt_version'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('version'),
      '#default_value' => $config->get('mkt_version'),
      '#size'=> 350,
    );

    $form['Marketo']['mkt_sous_domaine'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('sous_domaine'),
      '#default_value' => $config->get('mkt_sous_domaine'),
      '#size'=> 350,
    );

    $form['Marketo']['mkt_univers_affichage'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('univers_affichage'),
      '#default_value' => $config->get('mkt_univers_affichage'),
      '#size'=> 350,
    );


    #############################
    ## My field for Pardot
    $form['Pardot']['iframe_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('iframe url'),
      '#default_value' => $config->get('iframe_url'),
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab_backoffice.pardot')
      /* for Marketo */
      ->set('mkt_to_domain', $form_state->getValue('mkt_to_domain'))
      ->set('mkt_form_name', $form_state->getValue('mkt_form_name'))
      ->set('mkt_to_munchkin_id', $form_state->getValue('mkt_to_munchkin_id'))
      ->set('mkt_to_form_id', $form_state->getValue('mkt_to_form_id'))
      ->set('mkt_custom_follow_up_url', $form_state->getValue('mkt_custom_follow_up_url'))
      ->set('mkt_form_follow_up_message', $form_state->getValue('mkt_form_follow_up_message'))
      ->set('mkt_version', $form_state->getValue('mkt_version'))
      ->set('mkt_sous_domaine', $form_state->getValue('mkt_sous_domaine'))
      ->set('mkt_univers_affichage', $form_state->getValue('mkt_univers_affichage'))

      /* for Pardot */
      ->set('iframe_url', $form_state->getValue('iframe_url'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
