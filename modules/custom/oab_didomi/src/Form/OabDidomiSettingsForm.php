<?php

namespace Drupal\oab_didomi\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

class OabDidomiSettingsForm extends ConfigFormBase{

  public static function getConfigName() {
    return 'oab_didomi.settings';
  }
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_didomi_settings_form';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_didomi.settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    # Vendor ID for Youtube
    $form['vendor_id_youtube'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Vendor ID for Youtube'),
      '#default_value' => $config->get('vendor_id_youtube')
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config($this->getConfigName())
      ->set('vendor_id_youtube', $form_state->getValue('vendor_id_youtube'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
