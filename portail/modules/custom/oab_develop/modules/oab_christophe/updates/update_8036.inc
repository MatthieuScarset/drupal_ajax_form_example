<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('migrate_plus.migration.press_release_term');
$config->setData(array (
  'uuid' => 'b5c5ffab-5f16-4a64-8d64-434bd6c6b748',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
    ),
  '_core' =>
    array (
      'default_config_hash' => 'EiYDTd-d1VUomHr-OTMzRvk3ATg-0Z6IasA0kGf_fHk',
    ),
  'id' => 'press_release_term',
  'migration_tags' => NULL,
  'migration_group' => 'press_release',
  'label' => 'Communiqués de presse terms',
  'source' =>
    array (
      'plugin' => 'press_release_term',
    ),
  'process' =>
    array (
      'vid' => 'vid',
      'langcode' => 'language',
      'name' => 'name',
      'parent' =>
        array (
          'plugin' => 'migration',
          'migration' => 'press_release_term',
          'source' => 'parent',
        ),
      'weight' => 'weight',
    ),
  'destination' =>
    array (
      'plugin' => 'entity:taxonomy_term',
    ),
  'migration_dependencies' =>
    array (
    ),
));
$config->save(TRUE);

