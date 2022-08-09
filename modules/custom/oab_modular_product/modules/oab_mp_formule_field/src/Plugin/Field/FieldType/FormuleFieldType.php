<?php

namespace Drupal\oab_mp_formule_field\Plugin\Field\FieldType;

use Drupal\Component\Utility\Random;
use Drupal\Core\Field\Annotation\FieldType;
use Drupal\Core\Field\FieldDefinitionInterface;
use Drupal\Core\Field\FieldItemBase;
use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\Core\TypedData\DataDefinition;

/**
 * Plugin implementation of the 'formule_field_type' field type.
 *
 * @FieldType(
 *   id = "formule_field_type",
 *   label = @Translation("Formule field type"),
 *   description = @Translation("Store the value of a formule field"),
 *   default_widget = "formule_field_widget_type",
 *   default_formatter = "formule_field_formatter_type"
 * )
 */
class FormuleFieldType extends FieldItemBase {

  /**
   * {@inheritdoc}
   */
  public static function defaultStorageSettings() {
    return [
      'max_length' => 255,
      'is_ascii' => FALSE,
      'case_sensitive' => FALSE,
    ] + parent::defaultStorageSettings();
  }

  /**
   * {@inheritdoc}
   */
  public static function propertyDefinitions(FieldStorageDefinitionInterface $field_definition) {
    // Prevent early t() calls by using the TranslatableMarkup.
    $properties['value'] = DataDefinition::create('string')
      ->setLabel(new TranslatableMarkup('Text value'))
      ->setSetting('case_sensitive', $field_definition->getSetting('case_sensitive'))
      ->setRequired(TRUE);

    $properties['formule_field_target'] = DataDefinition::create('string')
      ->setLabel(new TranslatableMarkup('Formule Field ID'))
      ->setSetting('case_sensitive', $field_definition->getSetting('case_sensitive'))
      ->setRequired(TRUE);

    return $properties;
  }


  /**
   * {@inheritdoc}
   */
  public static function schema(FieldStorageDefinitionInterface $field_definition) {
    $schema = [
      'columns' => [
        'value' => [
          'type' => $field_definition->getSetting('is_ascii') === TRUE ? 'varchar_ascii' : 'varchar',
          'length' => (int) $field_definition->getSetting('max_length'),
          'binary' => $field_definition->getSetting('case_sensitive'),
        ],
        'formule_field_target' => [
          'type' => $field_definition->getSetting('is_ascii') === TRUE ? 'varchar_ascii' : 'varchar',
          'length' => (int) $field_definition->getSetting('max_length'),
          'binary' => $field_definition->getSetting('case_sensitive'),
        ]
      ],
    ];

    return $schema;
  }


  /**
   * {@inheritdoc}
   */
  public static function generateSampleValue(FieldDefinitionInterface $field_definition) {

    /** @var \Drupal\oab_mp_formule_field\Entity\FormuleField[] $formule_fields */
    $formule_fields = \Drupal::entityTypeManager()->getStorage('formule_field')->loadByProperties([]);

    $formule_fields_ids = array_keys($formule_fields);
    $random_field = $formule_fields[$formule_fields_ids[rand(0, count($formule_fields) - 1)]];
    $random_field_choices = $random_field->getChoices();

    return [
      'value' => $random_field_choices[rand(0, count($random_field_choices) - 1)],
      'formule_field_target' => $random_field->bundle()
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function storageSettingsForm(array &$form, FormStateInterface $form_state, $has_data) {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public function isEmpty() {
    $value = $this->get('value')->getValue();
    return $value === NULL || $value === '';
  }

}
