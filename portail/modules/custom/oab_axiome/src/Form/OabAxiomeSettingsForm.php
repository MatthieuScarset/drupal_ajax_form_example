<?php

namespace Drupal\oab_axiome\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabAxiomeSettingsForm extends ConfigFormBase {
  public static function getConfigName() {
    return 'oab.axiome_settings';
  }
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_axiome_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab.axiome_settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    $form['axiome_enable_cron'] = array(
      '#type' => 'checkbox',
      '#title' => $this->t('Enable axiome cron'),
      '#default_value' => $config->get('axiome_enable_cron'),
    );


    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config($this->getConfigName())
      ->set('axiome_enable_cron', $form_state->getValue('axiome_enable_cron'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
