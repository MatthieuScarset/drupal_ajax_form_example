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
    return 'oab_admin_settings_axiome';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab.axiome',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('oab.axiome');

    $form['axiome_enable_cron'] = array(
      '#type' => 'checkbox',
      '#title' => $this->t('Enable axiome cron'),
      '#default_value' => $config->get('axiome_enable_cron'),
    );

    $form['icon_frame_connectivity'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-connectivity'),
      '#default_value' => $config->get('icon_frame_connectivity'),
    );

    $form['icon_frame_teamwork'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-teamwork'),
      '#default_value' => $config->get('icon_frame_teamwork'),
    );

    $form['icon_frame_my_customers'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-my-customers'),
      '#default_value' => $config->get('icon_frame_my_customers'),
    );

    $form['icon_frame_performance'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-performance'),
      '#default_value' => $config->get('icon_frame_performance'),
    );

    $form['icon_frame_security'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-security'),
      '#default_value' => $config->get('icon_frame_security'),
    );

    $form['icon_frame_care'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-care'),
      '#default_value' => $config->get('icon_frame_care'),
    );

    $form['icon_frame_tech'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-tech'),
      '#default_value' => $config->get('icon_frame_tech'),
    );

      return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab.axiome')
      ->set('axiome_enable_cron', $form_state->getValue('axiome_enable_cron'))
      ->set('icon_frame_connectivity', $form_state->getValue('icon_frame_connectivity'))
      ->set('icon_frame_teamwork', $form_state->getValue('icon_frame_teamwork'))
      ->set('icon_frame_my_customers', $form_state->getValue('icon_frame_my_customers'))
      ->set('icon_frame_performance', $form_state->getValue('icon_frame_performance'))
      ->set('icon_frame_security', $form_state->getValue('icon_frame_security'))
      ->set('icon_frame_care', $form_state->getValue('icon_frame_care'))
      ->set('icon_frame_tech', $form_state->getValue('icon_frame_tech'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
