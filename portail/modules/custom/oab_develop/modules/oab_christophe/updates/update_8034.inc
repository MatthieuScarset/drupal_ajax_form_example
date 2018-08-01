<?php

use Drupal\paragraphs\Entity\ParagraphsType;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\Core\Entity\Entity\EntityFormDisplay;

$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_link');
if (!empty($field)) {
  $field->delete();
}

// création des champs pour le paragraph
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_reallink');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_reallink',
    'entity_type' => 'paragraph',
    'type' => 'link',
    'cardinality' => 1,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}

$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_reallink');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_reallink',
    'entity_type' => 'paragraph',
    'bundle' => 'related_content',
    'label' => 'link',
    'required' => FALSE,
    'translatable' => false,
    'language' => 'en',
    'field_type' => 'link',
    'settings' =>
      array (
        'link_type' => 17,
        'title' => 0,
      ),
  );
  FieldConfig::create($config_array)->save();
}


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.related_content.default');
$config_group->setData(array(
  'uuid' => '635774a3-d4d2-44e6-8ed8-58271a67cedd',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'entity_browser.browser.browse_media_modal',
          1 => 'field.field.paragraph.related_content.field_catcher',
          2 => 'field.field.paragraph.related_content.field_reallink',
          3 => 'field.field.paragraph.related_content.field_title',
          4 => 'field.field.paragraph.related_content.field_visual',
          5 => 'paragraphs.paragraphs_type.related_content',
        ),
      'module' =>
        array (
          0 => 'entity_browser',
          1 => 'link',
          2 => 'workbench_moderation',
        ),
    ),
  'id' => 'paragraph.related_content.default',
  'targetEntityType' => 'paragraph',
  'bundle' => 'related_content',
  'mode' => 'default',
  'content' =>
    array (
      'field_catcher' =>
        array (
          'weight' => 7,
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textarea',
          'region' => 'content',
        ),
      'field_reallink' =>
        array (
          'weight' => 9,
          'settings' =>
            array (
              'placeholder_url' => '',
              'placeholder_title' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'link_default',
          'region' => 'content',
        ),
      'field_title' =>
        array (
          'weight' => 6,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
          'region' => 'content',
        ),
      'field_visual' =>
        array (
          'weight' => 8,
          'settings' =>
            array (
              'entity_browser' => 'browse_media_modal',
              'field_widget_display' => 'rendered_entity',
              'field_widget_edit' => true,
              'field_widget_remove' => true,
              'selection_mode' => 'selection_append',
              'field_widget_display_settings' =>
                array (
                  'view_mode' => 'related_content_image',
                ),
              'open' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_browser_entity_reference',
          'region' => 'content',
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'status' => true,
      'uid' => true,
    ),
));
$config_group->save(true);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.related_content.default');
$config_group->setData(array(
  'uuid' => '29d298f0-2a41-4cc0-8ea7-c3ec0023fb75',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.paragraph.related_content.field_catcher',
          1 => 'field.field.paragraph.related_content.field_reallink',
          2 => 'field.field.paragraph.related_content.field_title',
          3 => 'field.field.paragraph.related_content.field_visual',
          4 => 'paragraphs.paragraphs_type.related_content',
        ),
      'module' =>
        array (
          0 => 'link',
        ),
    ),
  'id' => 'paragraph.related_content.default',
  'targetEntityType' => 'paragraph',
  'bundle' => 'related_content',
  'mode' => 'default',
  'content' =>
    array (
      'field_catcher' =>
        array (
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'basic_string',
          'region' => 'content',
        ),
      'field_reallink' =>
        array (
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
              'trim_length' => 80,
              'url_only' => false,
              'url_plain' => false,
              'rel' => '',
              'target' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'link',
          'region' => 'content',
        ),
      'field_title' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
          'region' => 'content',
        ),
      'field_visual' =>
        array (
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'related_content_image',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
          'region' => 'content',
        ),
    ),
  'hidden' =>
    array (
    ),
));
$config_group->save(true);


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.paragraph.related_content.field_reallink', array (
  "label" => "lien"
));