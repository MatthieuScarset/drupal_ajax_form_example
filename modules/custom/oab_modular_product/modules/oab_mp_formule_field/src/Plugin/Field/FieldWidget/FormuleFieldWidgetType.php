<?php

namespace Drupal\oab_mp_formule_field\Plugin\Field\FieldWidget;

use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Field\FieldDefinitionInterface;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\WidgetBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_mp_formule_field\Entity\FormuleField;
use Drupal\oab_mp_formules\Entity\ProductFormuleEntity;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\ConstraintViolationInterface;

/**
 * Plugin implementation of the 'formule_field_widget_type' widget.
 *
 * @FieldWidget(
 *   id = "formule_field_widget_type",
 *   module = "oab_mp_formule_field",
 *   label = @Translation("Formule field widget type"),
 *   field_types = {
 *     "formule_field_type"
 *   }
 * )
 */
class FormuleFieldWidgetType extends WidgetBase {

  /**
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  private EntityTypeManagerInterface $entityTypeManager;

  /**
   * Constructs a WidgetBase object.
   *
   * @param string $plugin_id
   *   The plugin_id for the widget.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\Core\Field\FieldDefinitionInterface $field_definition
   *   The definition of the field to which the widget is associated.
   * @param array $settings
   *   The widget settings.
   * @param array $third_party_settings
   *   Any third party settings.
   */
  public function __construct($plugin_id, $plugin_definition, FieldDefinitionInterface $field_definition,
                              array $settings, array $third_party_settings, EntityTypeManagerInterface $entityTypeManager) {
    parent::__construct($plugin_id, $plugin_definition, $field_definition, $settings, $third_party_settings);
    $this->entityTypeManager = $entityTypeManager;
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

    ] + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $elements = [];
    return $elements;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = [];

    return $summary;
  }

  public function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    // TODO: Implement formElement() method.
    $entity = $items->getEntity();
    $storage = $this->entityTypeManager->getStorage($entity->getEntityType()->getBundleEntityType());

    $element = [];

    if ($storage) {
      /** @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageType $bundle_conf */
      $bundle_conf = $storage->load($entity->bundle());

      if ($bundle_conf && $formule = ProductFormuleEntity::load($bundle_conf->get('formule') ?? 0)) {

        $values = $items->getValue();
        $sort_values = [];
        foreach ($values as $key => $value) {
          $sort_values[$value['formule_field_target']] = $value['value'];
        }

        foreach ($formule->getFormuleFields() as $formule_field) {
          $element['formule_fields'][$formule_field->id()] = [
            '#type' => "select",
            '#title' => $formule_field->label(),
            '#options' => $formule_field->getChoices(),
            '#default_value' => $sort_values[$formule_field->id()] ?? null
          ];
        }
//        dd($element);
      }
    }

    return $element;
  }


  public function formMultipleElements(FieldItemListInterface $items, array &$form, FormStateInterface $form_state) {

    return [
        '#type' => 'container',
        '#title' => t("Formules"),
        '#description' => t('Choose the values of each fields of the formule'),
        '#tree' => true
    ] + $this->formSingleElement($items, 0, [], $form, $form_state);
  }


  public function massageFormValues(array $values, array $form, FormStateInterface $form_state) {

    $ret = [];
    foreach ($values as $value) {
      foreach ($value as $key => $result) {
        if ($key !== '_original_delta') {
          $ret[] = [
            'formule_field_target' => $key,
            'value' => $result
          ];
        }
      }
    }

    return $ret;
  }

}
