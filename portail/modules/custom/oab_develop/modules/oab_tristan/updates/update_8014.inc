<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.webform_path');

##On reset
$config_group->setData(array (
  'uuid' => 'c3a86161-5d04-4959-9ba2-e41e4da10286',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
  array (
    'module' =>
      array (
        0 => 'node',
      ),
  ),
  'id' => 'webform_path',
  'label' => 'Webform',
  'type' => 'canonical_entities:node',
  'pattern' => '[node:title]',
  'selection_criteria' =>
  array (
    '0a3c0803-1812-416e-9cf7-7605132a85bb' =>
      array (
        'id' => 'node_type',
        'bundles' =>
          array (
            'webform' => 'webform',
          ),
        'negate' => false,
        'context_mapping' =>
          array (
            'node' => 'node',
          ),
        'uuid' => '0a3c0803-1812-416e-9cf7-7605132a85bb',
      ),
  ),
  'selection_logic' => 'and',
  'weight' => -5,
  'relationships' =>
  array (
  ),
));

##On save
$config_group->save(TRUE);