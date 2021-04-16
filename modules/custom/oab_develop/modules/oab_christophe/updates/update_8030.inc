<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.relatedcontent');
$config_group->setData(array(
  'uuid' => '453a3215-10e6-4ac3-8cfc-761b2daf8441',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'ctools',
          1 => 'oab_frontoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'relatedcontent',
  'theme' => 'theme_boosted',
  'region' => 'prefooter',
  'weight' => -18,
  'provider' => NULL,
  'plugin' => 'related_content_block',
  'settings' =>
    array (
      'id' => 'related_content_block',
      'label' => 'Related content',
      'provider' => 'oab_frontoffice',
      'label_display' => '0',
      'context_mapping' =>
        array (
          'node' => '@node.node_route_context:node',
        ),
    ),
  'visibility' =>
    array (
      'entity_bundle:node' =>
        array (
          'id' => 'entity_bundle:node',
          'bundles' =>
            array (
              'country' => 'country',
              'industry' => 'industry',
              'region' => 'region',
              'solution' => 'solution',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => '@node.node_route_context:node',
            ),
        ),
    ),
));
$config_group->save(true);