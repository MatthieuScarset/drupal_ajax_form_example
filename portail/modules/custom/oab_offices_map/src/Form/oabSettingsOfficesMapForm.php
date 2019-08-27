<?php

namespace Drupal\oab_offices_map\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsOfficesMapForm extends ConfigFormBase {
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_offices_map';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_offices_map.offices_map',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('oab_offices_map.offices_map');

    $form['contact_url'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Contact form url'),
      '#default_value' => $config->get('contact_url'),
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab_offices_map.offices_map')
      ->set('contact_url', $form_state->getValue('contact_url'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
