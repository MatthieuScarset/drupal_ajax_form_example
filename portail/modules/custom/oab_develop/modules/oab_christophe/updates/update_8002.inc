<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.blogpost_profile');
$config->set('process', array(
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

