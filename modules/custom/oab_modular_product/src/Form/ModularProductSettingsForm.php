<?php

namespace Drupal\oab_modular_product\Form;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Entity\EntityFieldManagerInterface;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_modular_product\Services\OabModularProductService;
use Drupal\paragraphs\Entity\ParagraphsType;
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
      '#open' => TRUE,
      '#title' => t('Max character'),
      '#description' => t("Config modular product title and description max character"),
      '#group' => 'tabs'
    ];

    $form['mp']['titles'] = [
      '#type' => 'details',
      '#open' => FALSE,
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
      '#open' => FALSE,
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
      '#open' => FALSE,
      '#title' => t('Modules titles'),
      '#description' => t("Config modules titles "),
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
      '#open' => FALSE,
      '#title' => t('Modules settings'),
      '#group' => 'tabs'
    ];

    $this->constructModulesTable($form, $conf);

    return parent::buildForm($form, $form_state);
  }

  /** Construit la partie des modules (ordre et requis) sous forme de table (drag & drop)
   * @param $form
   * @param $conf
   */
  private function constructModulesTable(&$form, $conf) {
    /**
     * @var \Drupal\Core\Field\FieldDefinitionInterface[]
     */
    //On récupère la liste des modules cochés pour le champ Field_modules de Modular Product
    $bundle_fields = $this->entityFieldManager->getFieldDefinitions('node', 'modular_product');
    $target_settings = $bundle_fields['field_modules']?->getSetting("handler_settings");
    $modules_in_field = $target_settings['target_bundles'] ?? [];

    //Construction de la table pour gérer l'ordre des modules et s'ils sont obligatoires ou non
    $group_class = 'group-order-weight';
    // Build table.
    $form['modules_settings']['modules'] = [
      '#type' => 'table',
      '#caption' => $this->t('Modules'),
      '#header' => [
        $this->t('Module label'),
        $this->t('ID'),
        $this->t('Required'),
        $this->t('Optional second position'),
        $this->t('Weight'),
      ],
      '#empty' => $this->t('No modules.'),
      '#tableselect' => FALSE,
      '#tabledrag' => [
        [
          'action' => 'order',
          'relationship' => 'sibling',
          'group' => $group_class,
        ]
      ]
    ];

    //on gère la conf uniquement s'il y a des paragraphs cochés
    if (is_array($modules_in_field) && count($modules_in_field) > 0 ) {
      //on récupère la conf courante :
      $current_conf_modules = $conf->get('modules_settings.modules');
      $max_weight = 0;
      //Pour chaque ligne de la conf actuelle
      foreach ($current_conf_modules as $module_id => $module_conf) {
        //on prend en compte le module de la conf que s'il est coché dans la conf du field_modules
        if(in_array($module_id, $modules_in_field) && !in_array($module_id, OabModularProductService::MODULES_OPTIONNELS)) {
          $paragraph_type = ParagraphsType::load($module_id); //chargement du paragraphType pour récupérer son label
          if(isset($paragraph_type)) {
            $form['modules_settings']['modules'][$module_id]['#attributes']['class'][] = 'draggable';
            $form['modules_settings']['modules'][$module_id]['#weight'] = $module_conf['weight'];
            // on va garder la plus haute valeur de weight pour les modules qu'on ajoutera à la fin
            $max_weight = max($module_conf['weight'], $max_weight);
            // Label col.
            $form['modules_settings']['modules'][$module_id]['label'] = [
              '#plain_text' => $paragraph_type->label(),
            ];
            // ID col.
            $form['modules_settings']['modules'][$module_id]['id'] = [
              '#plain_text' => $module_id,
            ];
            // required col.
            $form['modules_settings']['modules'][$module_id]['required'] = [
              '#type' => 'checkbox',
              '#default_value' => $module_conf['required'],
            ];
            // optional second position col.
            $form['modules_settings']['modules'][$module_id]['second_position'] = [
              '#type' => 'checkbox',
              '#default_value' => $module_conf['second_position'],
            ];
            // Weight col.
            $form['modules_settings']['modules'][$module_id]['weight'] = [
              '#type' => 'weight',
              '#title' => $this->t('Weight for @title', ['@title' => $paragraph_type->label()]),
              '#title_display' => 'invisible',
              '#default_value' => $module_conf['weight'],
              '#attributes' => ['class' => [$group_class]],
            ];
            //on supprime l'élément du tableau des modules puisqu'il a été traité
            unset($modules_in_field[$module_id]);
          }
        }
      }
      // après avoir parcouru la conf, on va regarder les modules cochés (du champ field_modules) restants qui ne seraient pas encore en conf

      foreach ($modules_in_field as $module_id) {
        //s'il n'est pas encore dans le tableau de rendu
        if (!in_array($module_id, $form['modules_settings']['modules']) && !in_array($module_id, OabModularProductService::MODULES_OPTIONNELS)) {
          $paragraph_type = ParagraphsType::load($module_id);
          if (isset($paragraph_type)) {
            $max_weight++; //mise a jour du weight pour ce nouvel élément
            $form['modules_settings']['modules'][$module_id]['#attributes']['class'][] = 'draggable';
            $form['modules_settings']['modules'][$module_id]['#weight'] = $max_weight;
            // Label col.
            $form['modules_settings']['modules'][$module_id]['label'] = [
              '#plain_text' => $paragraph_type->label(),
            ];
            // ID col.
            $form['modules_settings']['modules'][$module_id]['id'] = [
              '#plain_text' => $module_id,
            ];
            // required col.
            $form['modules_settings']['modules'][$module_id]['required'] = [
              '#type' => 'checkbox',
              '#default_value' => FALSE, //par défaut, non obligatoire
            ];
            // optional second position col.
            $form['modules_settings']['modules'][$module_id]['second_position'] = [
              '#type' => 'checkbox',
              '#default_value' => FALSE, //par défaut, non obligatoire
            ];
            // Weight col.
            $form['modules_settings']['modules'][$module_id]['weight'] = [
              '#type' => 'weight',
              '#title' => $this->t('Weight for @title', ['@title' => $paragraph_type->label()]),
              '#title_display' => 'invisible',
              '#default_value' => $max_weight,
              '#attributes' => ['class' => [$group_class]],
            ];
          }
        }
      }
    }
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
