<?php

// blogpost
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
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

// blogpost profile
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.blogpost_profile');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'created',
  'type' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'profil_redacteur',
    ),
  'uid' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 1,
    ),
  'langcode' => 'langcode',
  'title' => 'title',
  'body/value' => 'field_txt_biography_fr',
  'field_first_name/value' => 'field_first_name',
  'field_last_name/value' => 'field_last_name',
  'field_job/value' => 'field_profil_fr',
  'field_social_accounts' => 'field_social_accounts',
  'field_location/value' => 'field_location_fr',
  'field_image' =>
    array (
      'plugin' => 'migration',
      'migration' => 'blogpost_profile_media',
      'source' => 'images',
    ),
  'path' => 'path',
));
$config->save(TRUE);

// document
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.document_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'created',
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

// dossier de presse
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.dossier_presse_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
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

// magazine article
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.magazinearticle_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
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

// magazine interview
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.magazineinterview_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
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
  'field_rendering_model/target_id' => 'rendering_model_id',
  'field_content_field' => 'content_field',
  'field_magazine' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'categories',
    ),
  'field_industry' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'industries',
    ),
  'field_solution' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'solutions',
    ),
  'field_partner' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'partners',
    ),
  'field_area' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'areas',
    ),
  'field_customer_story' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_term',
      'source' => 'customer_stories',
    ),
  'field_image' =>
    array (
      'plugin' => 'migration',
      'migration' => 'magazineinterview_media',
      'source' => 'images',
    ),
  'field_state/value' => 'workflow',
  'path' => 'path',
  'field_subtitle' => 'subtitle',
  'field_short_description' => 'short_description',
));
$config->save(TRUE);

// office
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.office_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
  'type' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 'office',
    ),
  'title' => 'title',
  'uid' =>
    array (
      'plugin' => 'default_value',
      'default_value' => 1,
    ),
  'field_gps_coordinates/lat' => 'latitude',
  'field_gps_coordinates/lng' => 'longitude',
  'field_address/langcode' => 'langcode',
  'field_address/country_code' => 'country',
  'field_address/locality' => 'city',
  'field_address/postal_code' => 'postal_code',
  'field_address/address_line1' => 'street',
  'field_address/address_line2' => 'additional',
  'field_areas/target_id' => 'area',
));
$config->save(TRUE);

// press release
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config->set('process', array (
  'created' => 'created',
  'changed' => 'changed',
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