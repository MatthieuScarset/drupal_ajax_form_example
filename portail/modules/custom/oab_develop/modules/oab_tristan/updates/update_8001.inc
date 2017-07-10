<?php
use \Drupal\Core\Utility\UpdateException;
/****
 *
 * Modification de l'affichage du teaser du profil d'un blogger pour les contenus de type blog_post
 *
 */


/***********************
 * Modification du libellé du firstname + sa traduction FR
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.profile.field_first_name');
$config_group->setData(
    array (
        'uuid' => '268e8612-7795-4f1c-b4a4-9fe40d08d28d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_first_name',
                        1 => 'node.type.profile',
                    ),
            ),
        'id' => 'node.profile.field_first_name',
        'field_name' => 'field_first_name',
        'entity_type' => 'node',
        'bundle' => 'profile',
        'label' => 'Firstname',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.profile.field_first_name', array (
    'label' => 'Prénom',
));

/***********************
 * Modification du libellé du Twitter Account + sa traduction FR
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.profile.field_social_account');
$config_group->setData(
    array (
        'uuid' => 'ff1a34e0-7e7c-4313-83a9-727cc984db42',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_social_account',
                        1 => 'node.type.profile',
                    ),
            ),
        'id' => 'node.profile.field_social_account',
        'field_name' => 'field_social_account',
        'entity_type' => 'node',
        'bundle' => 'profile',
        'label' => 'Twitter account',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);

$config_group->save(TRUE);
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.profile.field_social_account', array (
    'label' => 'Compte Twitter',
));

/***********************
 * Modification de la config pour l'affichage personnalisé du teaser du blogger d'un blog_post
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
                        'type' => 'entity_reference_label',
                        'weight' => 5,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
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
