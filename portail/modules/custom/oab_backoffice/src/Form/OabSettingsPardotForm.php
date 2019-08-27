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

    $form['iframe_url'] = array(
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
      ->set('iframe_url', $form_state->getValue('iframe_url'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
