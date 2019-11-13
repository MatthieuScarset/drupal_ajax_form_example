<?php

namespace Drupal\oab_twitter\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class TwitterSettingsForm extends ConfigFormBase {

  const API_KEY       = 'api_key';
  const API_SECRET    = 'api_secret';
  const USER_PROFILE  = 'user_profile';
  const NB_TWEET      = 'nb_tweet';
  const TWEET_LENGTTH  = 'tweet_length';

  public static function getConfigName() {
    return 'oab_twitter.settings_form';
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_twitter_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab_twitter.settings_form',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    // Add a form field to the existing block configuration form.
    $form[self::API_KEY] = array(
      '#type' => 'textfield',
      '#title' => t('API Customer Key'),
      '#default_value' => $config->get(self::API_KEY),
      '#required' => true,
    );

    $form[self::API_SECRET] = array(
      '#type' => 'textfield',
      '#title' => t('API Customer Secret'),
      '#default_value' => $config->get(self::API_SECRET),
      '#required' => true,
    );

    $form[self::USER_PROFILE] = array(
      '#type' => 'textfield',
      '#title' => t('Compte twitter'),
      '#default_value' =>  $config->get(self::USER_PROFILE),
      '#description' => "Compte twitter, sans le '@'",
      '#required' => true,
    );

    $form[self::NB_TWEET] = array(
      '#type' => 'number',
      '#title' => t('Nombre de tweets'),
      '#default_value' => $config->get(self::NB_TWEET) ?  $config->get(self::NB_TWEET) : 5,
      '#description' => 'Nombre de tweets à afficher',
      '#required' => true,
    );

    $form[self::TWEET_LENGTTH] = array(
      '#type' => 'number',
      '#title' => t('Largeur des tweets'),
      '#default_value' =>  $config->get(self::TWEET_LENGTTH) ? $config->get(self::TWEET_LENGTTH) : 316,
      '#required' => false,
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config($this->getConfigName())
      ->set(self::API_KEY, $form_state->getValue(self::API_KEY))
      ->set(self::API_SECRET, $form_state->getValue(self::API_SECRET))
      ->set(self::USER_PROFILE, $form_state->getValue(self::USER_PROFILE))
      ->set(self::NB_TWEET, $form_state->getValue(self::NB_TWEET))
      ->set(self::TWEET_LENGTTH, $form_state->getValue(self::TWEET_LENGTTH))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
