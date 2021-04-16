<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabGeneralSettingsForm extends ConfigFormBase {
    public static function getConfigName() {
        return 'oab_backoffice.general_settings';
    }
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_general_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_backoffice.general_settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    $form['proxy_server'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Proxy server'),
      '#default_value' => $config->get('proxy_server'),
    );

    $form['proxy_port'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Proxy port'),
      '#default_value' => $config->get('proxy_port'),
    );

      $form['oabt_logs'] = array(
          '#type' => 'details',
          '#open' => true,
          '#title' => t('Config oabt_logs'),
          '#description'    => t("Configuration des logs spécifiques oabt"),
      );

      $form['oabt_logs']['oabt_logs_mails_destinataires'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Liste destinataires'),
          '#description' => "Separez les mails par une virgule et un espace",
          '#default_value' => $config->get('oabt_logs.mails_destinataires'),
      );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config($this->getConfigName())
      ->set('proxy_server', $form_state->getValue('proxy_server'))
      ->set('proxy_port', $form_state->getValue('proxy_port'))
      ->set('oabt_logs.mails_destinataires', $form_state->getValue('oabt_logs_mails_destinataires'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
