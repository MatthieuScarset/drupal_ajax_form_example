<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_content');
$config_group->setData(array(
  'uuid' => 'c497d257-1192-4407-bb25-740fd949786b',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_content',
          1 => 'node.type.solution',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  'id' => 'node.solution.field_content',
  'field_name' => 'field_content',
  'entity_type' => 'node',
  'bundle' => 'solution',
  'label' => 'Content',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'text_long',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_content');
$config_group->setData(array(
  'uuid' => 'd4595778-3cb8-4593-92cd-5d26bbcb481b',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_content',
          1 => 'node.type.industry',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  'id' => 'node.industry.field_content',
  'field_name' => 'field_content',
  'entity_type' => 'node',
  'bundle' => 'industry',
  'label' => 'Content',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'text_long',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_content');
$config_group->setData(array(
  'uuid' => '4a2ebaf2-fdfb-4542-b513-1233f2128910',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_content',
          1 => 'node.type.region',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  'id' => 'node.region.field_content',
  'field_name' => 'field_content',
  'entity_type' => 'node',
  'bundle' => 'region',
  'label' => 'Content',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'text_long',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_content');
$config_group->setData(array(
  'uuid' => '13ebda50-84e9-4542-bc12-715560548cc8',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_content',
          1 => 'node.type.country',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  'id' => 'node.country.field_content',
  'field_name' => 'field_content',
  'entity_type' => 'node',
  'bundle' => 'country',
  'label' => 'Content',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'text_long',
));
$config_group->save(TRUE);

// traduction
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.solution.field_content', array (
  "label" => "Contenu"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.industry.field_content', array (
  "label" => "Contenu"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.region.field_content', array (
  "label" => "Contenu"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.country.field_content', array (
  "label" => "Contenu"
));
