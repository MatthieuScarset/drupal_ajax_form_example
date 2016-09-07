<?php

\Drupal::service('module_installer')->install(array('pathauto', 'redirect'), true);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('pathauto.pattern.nodes');
$config->setData(array (
  'uuid' => '74bdd105-73cb-43e8-90c1-26f1389bc498',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'nodes',
  'label' => 'nodes',
  'type' => 'canonical_entities:node',
  'pattern' => '[node:title]',
  'selection_criteria' =>
    array (
      '5bf59b58-e804-483d-825d-92e07484a5ae' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'container' => 'container',
              'profil_redacteur' => 'profil_redacteur',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '5bf59b58-e804-483d-825d-92e07484a5ae',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -5,
  'relationships' =>
    array (
      'node:langcode:language' =>
        array (
          'label' => 'Language',
        ),
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('redirect.settings');
$config->setData(array (
  'canonical' => true,
  'auto_redirect' => false,
  'default_status_code' => 301,
  'passthrough_querystring' => true,
  'warning' => false,
  'nonclean_to_clean' => true,
  'ignore_admin_path' => false,
  'frontpage_redirect' => true,
  'deslash' => true,
  'access_check' => true,
  'normalize_aliases' => true,
  'content_location_header' => true,
  'term_path_handler' => true,
  '_core' =>
    array (
      'default_config_hash' => 'IxLwI-D9NeuZKfY2iz87l0NeM8LfBn7IVucsc6RG6l4',
    ),
));
$config->save(TRUE);