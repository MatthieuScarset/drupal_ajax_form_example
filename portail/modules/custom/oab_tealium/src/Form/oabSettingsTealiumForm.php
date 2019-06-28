<?php

namespace Drupal\oab_tealium\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class oabSettingsTealiumForm extends ConfigFormBase {
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_tealium';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab.tealium',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('oab.tealium');

    $form['sous_domaine'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('sous domaine'),
      '#default_value' => $config->get('sous_domaine'),
    );

    $form['univers_affichage'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('univers affichage'),
      '#default_value' => $config->get('univers_affichage'),
    );

    $form['sous_univers'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('sous univers'),
      '#default_value' => $config->get('sous_univers'),
    );

    $form['domaine_marketing'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('domaine marketing'),
      '#default_value' => $config->get('domaine_marketing'),
    );

    $form['code_univers'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('code univers'),
      '#default_value' => $config->get('code_univers'),
    );

    $form['tealium_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('tealium url'),
      '#default_value' => $config->get('tealium_url'),
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab.tealium')
      ->set('sous_domaine', $form_state->getValue('sous_domaine'))
      ->set('univers_affichage', $form_state->getValue('univers_affichage'))
      ->set('sous_univers', $form_state->getValue('sous_univers'))
      ->set('domaine_marketing', $form_state->getValue('domaine_marketing'))
      ->set('code_univers', $form_state->getValue('code_univers'))
      ->set('tealium_url', $form_state->getValue('tealium_url'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
