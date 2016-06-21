<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.default');
$config->set('content', array(
  'field_content_field' =>
    array (
      'weight' => 4,
      'label' => 'hidden',
      'settings' =>
        array (
        ),
      'third_party_settings' =>
        array (
        ),
      'type' => 'oab_text_default',
    ),
  'field_file' =>
    array (
      'weight' => 3,
      'label' => 'hidden',
      'settings' =>
        array (
          'image_style' => '',
          'image_link' => '',
        ),
      'third_party_settings' =>
        array (
        ),
      'type' => 'media_thumbnail',
    ),
  'field_image' =>
    array (
      'weight' => 2,
      'label' => 'hidden',
      'settings' =>
        array (
          'image_style' => '',
          'view_mode' => 'default',
          'link' => false,
        ),
      'third_party_settings' =>
        array (
        ),
      'type' => 'entity_reference_image',
    ),
  'field_short_description' =>
    array (
      'weight' => 1,
      'label' => 'hidden',
      'settings' =>
        array (
        ),
      'third_party_settings' =>
        array (
        ),
      'type' => 'basic_string',
    ),
  'field_subtitle' =>
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
    ),
));
$config->set('hidden', array(
  'field_area' => true,
  'field_blog' => true,
  'field_customer_story' => true,
  'field_end_date' => true,
  'field_industry' => true,
  'field_magazine' => true,
  'field_partner' => true,
  'field_rendering_model' => true,
  'field_solution' => true,
  'field_start_date' => true,
  'field_state' => true,
  'langcode' => true,
  'links' => true,
));
$config->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();