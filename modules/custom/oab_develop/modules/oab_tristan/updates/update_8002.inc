<?php
use \Drupal\Core\Utility\UpdateException;

/***********************
 * Affichage de l'image du blogueur dans l'encadré blogueur (au lieu d'un texte avant)
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.teaser');
$config_group->setData(
    array (
        'uuid' => 'e3e9f379-0205-41c0-ae2c-de44d430ac57',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.teaser',
                        1 => 'field.field.node.profile.body',
                        2 => 'field.field.node.profile.field_first_name',
                        3 => 'field.field.node.profile.field_last_name',
                        4 => 'field.field.node.profile.field_metatags',
                        5 => 'field.field.node.profile.field_social_account',
                        6 => 'field.field.node.profile.field_visual',
                        7 => 'node.type.profile',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.profile.teaser',
        'targetEntityType' => 'node',
        'bundle' => 'profile',
        'mode' => 'teaser',
        'content' =>
            array (
                'body' =>
                    array (
                        'type' => 'text_default',
                        'weight' => 4,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_first_name' =>
                    array (
                        'type' => 'string',
                        'weight' => 2,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_last_name' =>
                    array (
                        'type' => 'string',
                        'weight' => 3,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_social_account' =>
                    array (
                        'type' => 'string',
                        'weight' => 1,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 5,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                                'view_mode' => 'default',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'links' =>
                    array (
                        'weight' => 0,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_metatags' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);

#A enlever à la fin des tests
//throw new UpdateException();