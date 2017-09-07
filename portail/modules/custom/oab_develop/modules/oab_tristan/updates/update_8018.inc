<?php

/**
 * Ajout d'une description au field visuel ornemental pour les contenus de type document + trad fr
 */

$config_factory = \Drupal::configFactory();

############################
##Modification du formulaire
$config_group = $config_factory->getEditable('field.field.node.document.field_visual');

##On reset
$config_group->setData(array (
  'uuid' => '9c3a2301-e111-4bc4-aad3-93a29a9d51f5',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_visual',
          1 => 'media_entity.bundle.image',
          2 => 'node.type.document',
        ),
    ),
  'id' => 'node.document.field_visual',
  'field_name' => 'field_visual',
  'entity_type' => 'node',
  'bundle' => 'document',
  'label' => 'Ornamental visual',
  'description' => 'Image size 210w*270h',
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
));

##On save
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_visual',
  array (
    'label' => 'Visuel ornemental',
    'description' => 'Taille d\'image : 210L*270H',
));
