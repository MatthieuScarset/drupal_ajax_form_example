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

      $form['mp_title'] = [
        '#type' => 'details',
        '#tree' => TRUE,
        '#open' => true,
        '#title' => t('Title max character'),
        '#description'    => t("Config Modular Product Title max character"),
        '#group' => 'tabs'
      ];

      $form['mp_title']['top_zone'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Product title')
      ];

      $form['mp_title']['top_zone']['title'] = [
        '#type' => 'number',
        '#title' => t('Title max character'),
        '#default_value' => $conf->get('mp_title.top_zone.title') ?? 70,
        '#max' => 255,
        '#min' => 50,
        '#step' => 5
      ];

      $form['mp_title']['top_zone']['description'] = [
        '#type' => 'number',
        '#title' => t('Teaser max character'),
        '#default_value' => $conf->get('mp_title.top_zone.description') ?? 255,
        '#max' => 255,
        '#min' => 100,
        '#step' => 5
      ];

      $form['mp_title']['module'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Modules title')
      ];

      $form['mp_title']['module']['title'] = [
        '#type' => 'number',
        '#title' => t('Title max character'),
        '#default_value' => $conf->get('mp_title.module.title') ?? 65,
        '#max' => 255,
        '#min' => 50,
        '#step' => 5
      ];

      $form['mp_title']['module']['description'] = [
        '#type' => 'number',
        '#title' => t('Accroche max character'),
        '#default_value' => $conf->get('mp_title.module.description') ?? 150,
        '#max' => 255,
        '#min' => 100,
        '#step' => 5
      ];

      $form['mp_title']['module_items'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Items Modules title')
      ];

      $form['mp_title']['module_items']['title'] = [
        '#type' => 'number',
        '#title' => t('Title max character'),
        '#default_value' => $conf->get('mp_title.module_items.title') ?? 70,
        '#max' => 255,
        '#min' => 50,
        '#step' => 5
      ];

      $form['mp_title']['module_items']['description'] = [
        '#type' => 'number',
        '#title' => t('Description max character'),
        '#default_value' => $conf->get('mp_title.module_items.description') ?? 130,
        '#max' => 255,
        '#min' => 100,
        '#step' => 5
      ];

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {

    $config = $this->config($this->getConfigName());

    $config->set('mp_title', $form_state->getValue('mp_title', []));

    $config->save();

    parent::submitForm($form, $form_state);
  }
}
