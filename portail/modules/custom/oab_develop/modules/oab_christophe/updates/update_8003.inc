<?php

// Blog post node
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config->set('process', array(
  'status' =>
    array(
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


// Document node
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.document_node');
$config->set('process', array(
  'status' =>
    array(
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
  'field_document_type' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'document_types',
    ),
  'field_topic' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'topics',
    ),
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'solutions',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'industries',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_term',
      'source' => 'customer_stories',
    ),
  'field_file' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_media_file',
      'source' => 'files',
    ),
  'field_image' =>
    array (
      'plugin' => 'migration',
      'migration' => 'document_media_image',
      'source' => 'images',
    ),
  'field_state/value' => 'workflow',
  'path' => 'path',
  'field_subtitle' => 'subtitle',
  'field_short_description' => 'short_description',
));
$config->save(TRUE);


// Dossier Presse node
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.dossier_presse_node');
$config->set('process', array(
  'status' =>
    array(
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
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_term',
      'source' => 'solutions',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_term',
      'source' => 'industries',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_term',
      'source' => 'customer_stories',
    ),
  'field_file' =>
    array (
      'plugin' => 'migration',
      'migration' => 'dossier_presse_media',
      'source' => 'files',
    ),
  'field_state/value' => 'workflow',
  'path' => 'path',
));
$config->save(TRUE);


// Magazine Article node
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.magazinearticle_node');
$config->set('process', array(
  'status' =>
    array(
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
  'field_magazine' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'categories',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'industries',
    ),
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'solutions',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_term',
      'source' => 'customer_stories',
    ),
  'field_image' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazinearticle_media',
      'source' => 'images',
    ),
  'field_state/value' => 'workflow',
  'path' => 'path',
  'field_subtitle' => 'subtitle',
  'field_short_description' => 'short_description',
));
$config->save(TRUE);


// Press Release node
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config->set('process', array(
  'status' =>
    array(
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
  'field_rendering_model/target_id' => 'rendering_model_id',
  'field_content_field/value' => 'content_field',
  'field_content_field/format' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'full_html',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_term',
      'source' => 'industries',
    ),
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_term',
      'source' => 'solutions',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_term',
      'source' => 'customer_stories',
    ),
  'field_file' =>
    array (
      'plugin' => 'migration',
      'migration' => 'press_release_media',
      'source' => 'files',
    ),
  'field_short_description' => 'short_description',
  'field_state/value' => 'workflow',
  'path' => 'path',
  'field_country' => 'country',
  'field_city' => 'city',
));
$config->save(TRUE);


//throw new \Drupal\Core\Utility\UpdateException();