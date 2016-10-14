<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.container.field_section');
$config_group->setData(
  array (
    'uuid' => '89333120-9910-4f71-818c-1e0087a6e3a1',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_section',
            1 => 'node.type.container',
            2 => 'taxonomy.vocabulary.sections',
          ),
      ),
    'id' => 'node.container.field_section',
    'field_name' => 'field_section',
    'entity_type' => 'node',
    'bundle' => 'container',
    'label' => 'Section',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:taxonomy_term',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'sections' => 'sections',
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
  ));
$config_group->save(TRUE);

return '';