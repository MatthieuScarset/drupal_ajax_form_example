<?php

use \Drupal\Core\Utility\UpdateException;


/*****************************
 * migrate_plus.migration.blogpost_node
 *****************************/

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
  'field_profile' => 'profile_blogger_id',
  'status' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 1,
    ),
  'type' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'container',
    ),
  'title' => 'title',
  'langcode' => 'language',
  'uid' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 1,
    ),
  'field_type/target_id' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 7,
    ),
  'field_rendering_model/target_id' => 'rendering_model_id',
  'field_content_field/value' => 'content_field',
  'field_content_field/format' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'full_html',
    ),
  'field_content_field/zone' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'default',
    ),
  'field_blog' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'categories',
    ),
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'solutions',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'industries',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_term',
      'source' => 'customer_stories',
    ),
  'field_image' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_media',
      'source' => 'images',
    ),
  'field_state/value' => 'workflow',
  'path' => 'path',
));
$config->save(TRUE);
