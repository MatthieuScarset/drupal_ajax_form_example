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

      $form['mp']['titles']['title_short'] = [
        '#type' => 'number',
        '#title' => t('Titles with 70 max character'),
        '#default_value' => $conf->get('mp.title.title_short') ?? 70,
        '#max' => 255,
        '#min' => 50,
        '#step' => 5
      ];

      $form['mp']['titles']['title_long'] = [
        '#type' => 'number',
        '#title' => t('Titles with 150 max character'),
        '#default_value' => $conf->get('mp.title.title_long') ?? 150,
        '#max' => 255,
        '#min' => 90,
        '#step' => 5
      ];

      $form['mp']['descriptions'] = [
        '#type' => 'details',
        '#open' => false ,
        '#title' => t('Descriptions max character')
      ];

      $form['mp']['descriptions']['description_long'] = [
        '#type' => 'number',
        '#title' => t('Descriptions max character'),
        '#default_value' => $conf->get('mp.descriptions.descriptions_long') ?? 250,
        '#max' => 255,
        '#min' => 200,
        '#step' => 5
      ];

    $form['modules_titles'] = [
      '#type' => 'details',
      '#tree' => TRUE,
      '#open' => false,
      '#title' => t('Modules titles'),
      '#description'    => t("Config modules titles "),
      '#group' => 'tabs'
    ];
    $form['modules_titles']['module_presentation'] = [
      '#type' => 'textfield',
      '#title' => t('Presentation module title'),
      '#default_value' => $conf->get('modules_titles.module_presentation') ?? 'Presentation',
    ];
    $form['modules_titles']['module_detail_offre'] = [
      '#type' => 'textfield',
      '#title' => t('Offer Detail module title'),
      '#default_value' => $conf->get('modules_titles.module_detail_offre') ?? 'Offer Detail',
    ];
    $form['modules_titles']['module_detail_gamme'] = [
      '#type' => 'textfield',
      '#title' => t('Detail of the range module title'),
      '#default_value' => $conf->get('modules_titles.module_detail_gamme') ?? 'Detail of the range',
    ];
    $form['modules_titles']['module_services'] = [
      '#type' => 'textfield',
      '#title' => t('Tailor-made services module title'),
      '#default_value' => $conf->get('modules_titles.module_services') ?? 'Tailor-made services',
    ];
    $form['modules_titles']['module_customer_space'] = [
      '#type' => 'textfield',
      '#title' => t('Customer space module title'),
      '#default_value' => $conf->get('modules_titles.module_customer_space') ?? 'Customer space',
    ];
    $form['modules_titles']['module_exemples'] = [
      '#type' => 'textfield',
      '#title' => t('Examples module title'),
      '#default_value' => $conf->get('modules_titles.module_exemples') ?? 'Examples',
    ];
    $form['modules_titles']['module_testimonial'] = [
      '#type' => 'textfield',
      '#title' => t('Testimonials module title'),
      '#default_value' => $conf->get('modules_titles.module_testimonial') ?? 'Testimonials',
    ];

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());
    $config->set('mp', $form_state->getValue('mp', []));
    $config->set('modules_titles', $form_state->getValue('modules_titles', []));
    $config->save();
    parent::submitForm($form, $form_state);
  }
}
