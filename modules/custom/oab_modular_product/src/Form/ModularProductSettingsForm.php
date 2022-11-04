<?php

namespace Drupal\oab_modular_product\Form;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Entity\EntityFieldManagerInterface;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

class ModularProductSettingsForm extends ConfigFormBase {


  /**
   * @var EntityFieldManagerInterface
   */
  private EntityFieldManagerInterface $entityFieldManager;

  public function __construct(ConfigFactoryInterface $config_factory,
                              EntityFieldManagerInterface $entity_field_manager) {
    parent::__construct($config_factory);
    $this->entityFieldManager = $entity_field_manager;
  }

  public static function create(ContainerInterface $container): ModularProductSettingsForm {
    return new self(
      $container->get('config.factory'),
      $container->get('entity_field.manager')
    );
  }

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
    $form['modules_titles']['to_go_further'] = [
      '#type' => 'textfield',
      '#title' => t('To go further title'),
      '#default_value' => $conf->get('modules_titles.to_go_further') ?? 'To go further',
    ];

    $form['modules_settings'] = [
      '#type' => 'details',
      '#tree' => TRUE,
      '#open' => false,
      '#title' => t('Modules settings'),
      '#group' => 'tabs'
    ];

    /**
     * @var \Drupal\Core\Field\FieldDefinitionInterface[]
     */
    //On récupère la liste des modules cochés pour le champ Field_modules de Modular Product (pour avoir les id dispo pour l'ordre et le required
    $bundle_fields = $this->entityFieldManager->getFieldDefinitions('node', 'modular_product');
    $target_settings = $bundle_fields['field_modules']?->getSetting("handler_settings");
    if(isset($target_settings['target_bundles']) && is_array($target_settings['target_bundles'])) {
      $list_modules = implode(", ", $target_settings['target_bundles']);
    }

    $form['modules_settings']['modules_list'] = [
      '#type' => 'item',
      '#title' => 'Available id modules',
      '#description' => $list_modules ?? ''
    ];
    $form['modules_settings']['modules_order'] = [
      '#type' => 'textarea',
      '#title' => t('Modules Order'),
      '#default_value' => $conf->get('modules_settings.modules_order') ?? ''
    ];
    $form['modules_settings']['modules_required'] = [
      '#type' => 'textarea',
      '#title' => t('Required Modules'),
      '#default_value' => $conf->get('modules_settings.modules_required') ?? ''
    ];

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());
    $config->set('mp', $form_state->getValue('mp', []));
    $config->set('modules_titles', $form_state->getValue('modules_titles', []));
    $config->set('modules_settings', $form_state->getValue('modules_settings', []));
    $config->save();
    parent::submitForm($form, $form_state);
  }
}
