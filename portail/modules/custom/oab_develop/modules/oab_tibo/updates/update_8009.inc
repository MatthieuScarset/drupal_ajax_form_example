<?php

// storage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_top_zone');
$config_group->setData(
  array (
    'uuid' => '49b405a0-d474-4065-a211-2ce9e4cca553',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
            1 => 'text',
          ),
      ),
    'id' => 'node.field_top_zone',
    'field_name' => 'field_top_zone',
    'entity_type' => 'node',
    'type' => 'text_long',
    'settings' =>
      array (
      ),
    'module' => 'text',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_top_zone_background');
$config_group->setData(
  array (
    'uuid' => '40da4255-5a7e-4f1a-acd9-42606407d5da',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'media_entity',
            1 => 'node',
          ),
      ),
    'id' => 'node.field_top_zone_background',
    'field_name' => 'field_top_zone_background',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'media',
      ),
    'module' => 'core',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  )
);
$config_group->save(TRUE);

// fields
$config_group = $config_factory->getEditable('field.field.node.product.field_top_zone');
$config_group->setData(
  array (
    'uuid' => 'a5247275-b9fe-456b-b2ca-42ab75ad0806',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_top_zone',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'node.product.field_top_zone',
    'field_name' => 'field_top_zone',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Top zone',
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
  )
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.product.field_top_zone_background');
$config_group->setData(
  array (
    'uuid' => '27560084-d093-4b83-8e70-6a797b70e5c3',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_top_zone_background',
            1 => 'media_entity.bundle.image',
            2 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.field_top_zone_background',
    'field_name' => 'field_top_zone_background',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Top zone background',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:media',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'image' => 'image',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => false,
            'auto_create_bundle' => '',
          ),
      ),
    'field_type' => 'entity_reference',
  )
);
$config_group->save(TRUE);

// bloc top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topzone');
$config_group->setData(
  array (
    'uuid' => '4f93e884-e26f-402b-a392-833e615de361',
    'langcode' => 'fr',
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
    'id' => 'topzone',
    'theme' => 'theme_boosted',
    'region' => 'top_zone',
    'weight' => -17,
    'provider' => NULL,
    'plugin' => 'top_zone_block',
    'settings' =>
      array (
        'id' => 'top_zone_block',
        'label' => 'Top Zone',
        'provider' => 'oab_frontoffice',
        'label_display' => 'visible',
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
                'industry' => 'industry',
                'product' => 'product',
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
  )
);
$config_group->save(TRUE);

// image style
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.top_zone');
$config_group->setData(
  array (
    'uuid' => 'f7846ea5-7648-4499-9445-d87ea096630f',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'name' => 'top_zone',
    'label' => 'Top zone',
    'effects' =>
      array (
        '7c40d148-7df6-4a44-8c1e-4f4015fc79ec' =>
          array (
            'uuid' => '7c40d148-7df6-4a44-8c1e-4f4015fc79ec',
            'id' => 'image_scale_and_crop',
            'weight' => 1,
            'data' =>
              array (
                'width' => 3000,
                'height' => 180,
              ),
          ),
      ),
  )
);
$config_group->save(TRUE);

throw new \Drupal\Core\Utility\UpdateException();