<?php

namespace Drupal\oab_text\Plugin\Field\FieldType;

use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\TypedData\DataDefinition;
use Drupal\text\Plugin\Field\FieldType\TextItemBase;

/**
 * Plugin implementation of the 'text_long' field type.
 *
 * @FieldType(
 *   id = "oab_text",
 *   label = @Translation("Text Oab (formatted, long)"),
 *   description = @Translation("This field stores a long text with a text format."),
 *   category = @Translation("Text"),
 *   default_widget = "oab_text_textfield",
 *   default_formatter = "text_default"
 * )
 */
class OabTextItem extends TextItemBase {

  /**
   * {@inheritdoc}
   */
  public static function defaultFieldSettings() {
    return array(
      'display_zone' => 0,
    ) + parent::defaultFieldSettings();
  }

  /**
   * {@inheritdoc}
   */
  public static function propertyDefinitions(FieldStorageDefinitionInterface $field_definition) {
    $properties = parent::propertyDefinitions($field_definition);

    $properties['zone'] = DataDefinition::create('string')
      ->setLabel(t('Zone'));

    return $properties;
  }

  /**
   * {@inheritdoc}
   */
  public static function schema(FieldStorageDefinitionInterface $field_definition) {
    return array(
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
        ),
        'format' => array(
          'type' => 'varchar_ascii',
          'length' => 255,
        ),
        'zone' => array(
          'type' => 'varchar_ascii',
          'length' => 255,
        ),
      ),
      'indexes' => array(
        'format' => array('format'),
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function isEmpty() {
    $value = $this->get('value')->getValue();
    return parent::isEmpty() && ($value === NULL || $value === '');
  }

  /**
   * {@inheritdoc}
   */
  public function fieldSettingsForm(array $form, FormStateInterface $form_state) {
    $element = array();
    $settings = $this->getSettings();

    $element['display_zone'] = array(
      '#type' => 'checkbox',
      '#title' => t('Zone input'),
      '#default_value' => $settings['display_zone'],
      '#description' => t('This allows authors to input a display zone.'),
    );

    return $element;
  }

}
