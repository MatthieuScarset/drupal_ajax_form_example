<?php
use \Drupal\node\Entity\NodeType;
/**
 * Création type de contenu Custom page
 * */
$nodeStorage = NodeType::load('custom_page');
if (empty($nodeStorage)) {
    $nodeType = NodeType::create([
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'menu_ui',
                        1 => 'workbench_access',
                        2 => 'workbench_moderation',
                    ),
            ),
        'third_party_settings' =>
            array (
                'menu_ui' =>
                    array (
                        'available_menus' =>
                            array (
                            ),
                        'parent' => '',
                    ),
                'workbench_access' =>
                    array (
                        'workbench_access_status' => false,
                    ),
                'workbench_moderation' =>
                    array (
                        'enabled' => true,
                        'allowed_moderation_states' =>
                            array (
                                0 => 'published',
                                1 => 'archived',
                                2 => 'draft',
                                3 => 'needs_review',
                                4 => 'unpublished',
                            ),
                        'default_moderation_state' => 'draft',
                    ),
            ),
        'name' => 'Custom Page',
        'type' => 'custom_page',
        'description' => 'Full html content page without menu, footer or header',
        'help' => '',
        'new_revision' => true,
        'preview_mode' => 1,
        'display_submitted' => false,
    ]);
    $nodeType->save();
}

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.custom_page', array (
    'label' => 'Page personnalisée',
));


//Champs Content
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'field_content');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_content',
                        1 => 'node.type.custom_page',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                    ),
            ),
        'id' => 'node.custom_page.field_content',
        'field_name' => 'field_content',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Content',
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
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champs Display title
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'field_display_title');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_display_title',
                        1 => 'node.type.custom_page',
                    ),
            ),
        'id' => 'node.custom_page.field_display_title',
        'field_name' => 'field_display_title',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Display title',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
                0 =>
                    array (
                        'value' => 0,
                    ),
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'on_label' => 'On',
                'off_label' => 'Off',
            ),
        'field_type' => 'boolean',
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champs Meta title
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'field_meta_title');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.custom_page',
                    ),
            ),
        'id' => 'node.custom_page.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Meta title',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champs Meta description
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'field_meta_description');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.custom_page',
                    ),
            ),
        'id' => 'node.custom_page.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champs Metatags
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'custom_page', 'field_metatags');
if (empty($field)) {
    $config_array = array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_metatags',
                        1 => 'node.type.custom_page',
                    ),
                'module' =>
                    array (
                        0 => 'metatag',
                    ),
            ),
        'id' => 'node.custom_page.field_metatags',
        'field_name' => 'field_metatags',
        'entity_type' => 'node',
        'bundle' => 'custom_page',
        'label' => 'Metatags',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
                0 =>
                    array (
                        'value' => 'a:0:{}',
                    ),
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'metatag',
    );
    \Drupal\field\Entity\FieldConfig::create($config_array)->save();
}



oabt_YmlImport('core.entity_view_display.node.custom_page.teaser.yml');
oabt_YmlImport('core.entity_view_display.node.custom_page.default.yml');
oabt_YmlImport('core.entity_form_display.node.custom_page.default.yml');
oabt_YmlImport('core.base_field_override.node.custom_page.status.yml');
oabt_YmlImport('core.base_field_override.node.custom_page.promote.yml');
oabt_YmlImport('language.content_settings.node.custom_page.yml');
oabt_YmlImport('metatag.metatag_defaults.node__custom_page.yml');