<?php

namespace Drupal\oab_backoffice\Plugin\Field\FieldWidget;

use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Field\Plugin\Field\FieldWidget\OptionsWidgetBase;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Field\FieldDefinitionInterface;

/**
 * Plugin implementation of the 'option_group_term_select' widget.
 *
 * @FieldWidget(
 *   id = "option_group_term_select",
 *   label = @Translation("Option Group Term Select"),
 *   field_types = {
 *     "entity_reference"
 *   },
 *   multiple_values = true
 * )
 */
class OptionGroupTermSelectWidget extends OptionsWidgetBase implements ContainerFactoryPluginInterface {

  /**
   * Entity type manager service.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * {@inheritdoc}
   */
  public function __construct($plugin_id, $plugin_definition, FieldDefinitionInterface $field_definition, array $settings, array $third_party_settings, EntityTypeManagerInterface $entity_type_manager) {
    parent::__construct($plugin_id, $plugin_definition, $field_definition, $settings, $third_party_settings);
    $this->entityTypeManager = $entity_type_manager;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $plugin_id,
      $plugin_definition,
      $configuration['field_definition'],
      $configuration['settings'],
      $configuration['third_party_settings'],
      $container->get('entity_type.manager')
    );
  }
  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return [
        // Create the custom setting 'size', and
        // assign a default value of 60
        'displayLangcode' => true,
        'filterLangcode' => true,
      ] + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $element['displayLangcode'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Display langcode for terms'),
      '#default_value' => $this->getSetting('displayLangcode'),
    ];
    $element['c'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Filter terms by langcode on edit content form'),
      '#default_value' => $this->getSetting('filterLangcode'),
    ];

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    $filterLangcode = $this->getSetting('filterLangcode');
    if($filterLangcode) {
      $currentLangCode = null;
      $currentNode = \Drupal::routeMatch()->getParameter('node');
      if (isset($currentNode) && $currentNode instanceof \Drupal\node\NodeInterface) {
        $currentLangCode = $currentNode->language()->getId();
      } else {
        $filterLangcode = false;
      }
    }

    $displayLangCode = $this->getSetting('displayLangcode');
    $element = parent::formElement($items, $delta, $element, $form, $form_state);
    $field_definition = $items->getFieldDefinition();
    $target_bundle = $field_definition->getSettings();
    $voc_list = $target_bundle['handler_settings']['target_bundles'];
    // Initailizing the variable.
    $parent = NULL;
    foreach ($voc_list as $key => $value) {
      $data = $this->entityTypeManager->getStorage('taxonomy_term')->loadTree($key);

      foreach ($data as $item) {
        if(!$filterLangcode || ($filterLangcode && $currentLangCode == $item->langcode)) {
          $label = $item->name;
          if ($displayLangCode) {
            $label .= ' (' . strtoupper($item->langcode) . ')';
          }
          if ($item->depth == 0) {
            $parent = $label;
          } else {
            $result[$parent][$item->tid] = $label;
          }
        }
      }
    }
    $element += [
      '#type' => 'select',
      '#options' => $result,
      '#default_value' => $this->getSelectedOptions($items),
      // Do not display a 'multiple' select box if there is only one option.
      '#multiple' => $this->multiple && count($this->options) > 1,
    ];
    return $element;
  }

}
