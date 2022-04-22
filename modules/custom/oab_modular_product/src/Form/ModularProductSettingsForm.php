<?php

namespace Drupal\oab_modular_product\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

class ModularProductSettingsForm extends ConfigFormBase {

  private function getConfigName(): string {
    return 'oab_modular_product.settings';
  }

  protected function getEditableConfigNames(): array {
    return [ $this->getConfigName() ];
  }

  public function getFormId(): string {
    return 'oab_modular_product_settings';
  }

  public function buildForm(array $form, FormStateInterface $form_state): array {
    $conf = $this->config($this->getConfigName());

    $form['tabs'] = [
      '#type' => 'vertical_tabs',
      '#title' => t('Configure Modular Product')
    ];

      $form['mp'] = [
        '#type' => 'details',
        '#tree' => TRUE,
        '#open' => true,
        '#title' => t('Max character'),
        '#description'    => t("Config modular product title and description max character"),
        '#group' => 'tabs'
      ];

      $form['mp']['titles'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Titles max character')
      ];

      $form['mp']['titles']['title_70'] = [
        '#type' => 'number',
        '#title' => t('Titles with 70 max character'),
        '#default_value' => $conf->get('mp.title.title_70') ?? 70,
        '#max' => 255,
        '#min' => 50,
        '#step' => 5
      ];

      $form['mp']['titles']['title_150'] = [
        '#type' => 'number',
        '#title' => t('Titles with 150 max character'),
        '#default_value' => $conf->get('mp.title.title_150') ?? 150,
        '#max' => 255,
        '#min' => 90,
        '#step' => 5
      ];

      $form['mp']['descriptions'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Descriptions max character')
      ];

      $form['mp']['descriptions']['description_150'] = [
        '#type' => 'number',
        '#title' => t('Descriptions with 150 max character'),
        '#default_value' => $conf->get('mp.descriptions.description_150') ?? 150,
        '#max' => 255,
        '#min' => 100,
        '#step' => 5
      ];

      $form['mp']['descriptions']['description_250'] = [
        '#type' => 'number',
        '#title' => t('Descriptions with 250 max character'),
        '#default_value' => $conf->get('mp.descriptions.descriptions_250') ?? 250,
        '#max' => 255,
        '#min' => 200,
        '#step' => 5
      ];

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {

    $config = $this->config($this->getConfigName());

    $config->set('mp', $form_state->getValue('mp', []));

    $config->save();

    parent::submitForm($form, $form_state);
  }
}
