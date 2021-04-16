<?php
use \Drupal\Core\Utility\UpdateException;

/***********************
 * Affichage de l'image du blogueur dans l'encadré blogueur (au lieu d'un texte avant)
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.profile.field_visual');
$config_group->setData(
    array (
        'uuid' => '58c33d51-9729-4d8d-ad8c-27527e149d7f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.profile',
                    ),
            ),
        'id' => 'node.profile.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'profile',
        'label' => 'Image',
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

#A enlever à la fin des tests
//throw new UpdateException();