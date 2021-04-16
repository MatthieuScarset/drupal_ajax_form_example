<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsEceForm extends ConfigFormBase {
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_ece';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_backoffice.ece',
    ];
  }

  /**
   * {@inheritdoc}
   */
   public static function getConfigName() {
    return 'oab_backoffice.ece';
  }

    /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config(self::getConfigName());

    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Title'),
      '#default_value' => $config->get('title'),
    );

      $form['intro'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Intro'),
          '#default_value' => $config->get('intro'),
      );

      $form['connect_txt'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Texte se connecter'),
          '#default_value' => $config->get('connect_txt'),
      );

      $form['connect_link'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Lien se connecter'),
          '#default_value' => $config->get('connect_link'),
      );

      $form['discover_txt'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Texte découvrir'),
          '#default_value' => $config->get('discover_txt'),
      );

      $form['discover_link'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Lien découvrir'),
          '#default_value' => $config->get('discover_link'),
      );

      $form['create_txt'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Texte créer compte'),
          '#default_value' => $config->get('create_txt'),
      );

      $form['create_link'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Lien créer compte'),
          '#default_value' => $config->get('create_link'),
      );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config(self::getConfigName())
      ->set('title', $form_state->getValue('title'))
        ->set('intro', $form_state->getValue('intro'))
        ->set('connect_txt', $form_state->getValue('connect_txt'))
        ->set('connect_link', $form_state->getValue('connect_link'))
        ->set('discover_txt', $form_state->getValue('discover_txt'))
        ->set('discover_link', $form_state->getValue('discover_link'))
        ->set('create_txt', $form_state->getValue('create_txt'))
        ->set('create_link', $form_state->getValue('create_link'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
