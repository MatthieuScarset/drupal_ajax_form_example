<?php

//Champs Content
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'moderation_state_update');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.moderation_state_update',
                        1 => 'node.type.custom_page',
                        2 => 'scheduled_updates.scheduled_update_type.moderation_state_update',
                    ),
            ),
        'id' => 'node.custom_page.moderation_state_update',
        'field_name' => 'moderation_state_update',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Moderation state update',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:scheduled_update',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'moderation_state_update' => 'moderation_state_update',
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
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

oabt_YmlImport('core.entity_form_display.node.custom_page.default.yml');
oabt_YmlImport('core.entity_view_display.node.custom_page.default.yml');