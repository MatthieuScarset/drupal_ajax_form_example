<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\locale\SourceString;
##Je charge la librairie pour accéder aux config en BDD
$config_factory = \Drupal::configFactory();
$configs = [
    'views.view.rebond_document' => array (
        'uuid' => '16e8cc16-a703-4a0c-ab38-5671ace35ed0',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_page_du_site_1',
                        1 => 'field.storage.node.field_page_du_site_2',
                        2 => 'field.storage.node.field_rebond_document',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'user',
                    ),
            ),
        'id' => 'rebond_document',
        'label' => 'Zone rebond',
        'module' => 'views',
        'description' => '',
        'tag' => '',
        'base_table' => 'node_field_data',
        'base_field' => 'nid',
        'core' => '8.x',
        'display' =>
            array (
                'default' =>
                    array (
                        'display_plugin' => 'default',
                        'id' => 'default',
                        'display_title' => 'Master',
                        'position' => 0,
                        'display_options' =>
                            array (
                                'access' =>
                                    array (
                                        'type' => 'perm',
                                        'options' =>
                                            array (
                                                'perm' => 'access content',
                                            ),
                                    ),
                                'cache' =>
                                    array (
                                        'type' => 'tag',
                                        'options' =>
                                            array (
                                            ),
                                    ),
                                'query' =>
                                    array (
                                        'type' => 'views_query',
                                        'options' =>
                                            array (
                                                'disable_sql_rewrite' => false,
                                                'distinct' => false,
                                                'replica' => false,
                                                'query_comment' => '',
                                                'query_tags' =>
                                                    array (
                                                    ),
                                            ),
                                    ),
                                'exposed_form' =>
                                    array (
                                        'type' => 'basic',
                                        'options' =>
                                            array (
                                                'submit_button' => 'Appliquer',
                                                'reset_button' => false,
                                                'reset_button_label' => 'Réinitialiser',
                                                'exposed_sorts_label' => 'Trier par',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array (
                                        'type' => 'none',
                                        'options' =>
                                            array (
                                                'offset' => 0,
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'default',
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'fields',
                                        'options' =>
                                            array (
                                                'default_field_elements' => true,
                                                'inline' =>
                                                    array (
                                                    ),
                                                'separator' => '',
                                                'hide_empty' => false,
                                            ),
                                    ),
                                'fields' =>
                                    array (
                                        'field_page_du_site_1' =>
                                            array (
                                                'id' => 'field_page_du_site_1',
                                                'table' => 'node__field_page_du_site_1',
                                                'field' => 'field_page_du_site_1',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_entity_view',
                                                'settings' =>
                                                    array (
                                                        'view_mode' => 'rebond_page_site',
                                                    ),
                                                'group_column' => 'target_id',
                                                'group_columns' =>
                                                    array (
                                                    ),
                                                'group_rows' => true,
                                                'delta_limit' => 2,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                                'plugin_id' => 'field',
                                            ),
                                    ),
                                'filters' =>
                                    array (
                                        'status' =>
                                            array (
                                                'value' => '1',
                                                'table' => 'node_field_data',
                                                'field' => 'status',
                                                'plugin_id' => 'boolean',
                                                'entity_type' => 'node',
                                                'entity_field' => 'status',
                                                'id' => 'status',
                                                'expose' =>
                                                    array (
                                                        'operator' => '',
                                                    ),
                                                'group' => 1,
                                            ),
                                    ),
                                'sorts' =>
                                    array (
                                        'created' =>
                                            array (
                                                'id' => 'created',
                                                'table' => 'node_field_data',
                                                'field' => 'created',
                                                'order' => 'DESC',
                                                'entity_type' => 'node',
                                                'entity_field' => 'created',
                                                'plugin_id' => 'date',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'label' => '',
                                                    ),
                                                'granularity' => 'second',
                                            ),
                                    ),
                                'title' => 'rebond_document',
                                'header' =>
                                    array (
                                    ),
                                'footer' =>
                                    array (
                                    ),
                                'empty' =>
                                    array (
                                    ),
                                'relationships' =>
                                    array (
                                        'field_page_du_site_1' =>
                                            array (
                                                'id' => 'field_page_du_site_1',
                                                'table' => 'node__field_page_du_site_1',
                                                'field' => 'field_page_du_site_1',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => 'field_page_du_site_1 : Contenu',
                                                'required' => true,
                                                'plugin_id' => 'standard',
                                            ),
                                    ),
                                'arguments' =>
                                    array (
                                        'nid' =>
                                            array (
                                                'id' => 'nid',
                                                'table' => 'node_field_data',
                                                'field' => 'nid',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'default_action' => 'default',
                                                'exception' =>
                                                    array (
                                                        'value' => 'all',
                                                        'title_enable' => false,
                                                        'title' => 'All',
                                                    ),
                                                'title_enable' => false,
                                                'title' => '',
                                                'default_argument_type' => 'node',
                                                'default_argument_options' =>
                                                    array (
                                                    ),
                                                'default_argument_skip_url' => false,
                                                'summary_options' =>
                                                    array (
                                                        'base_path' => '',
                                                        'count' => true,
                                                        'items_per_page' => 25,
                                                        'override' => false,
                                                    ),
                                                'summary' =>
                                                    array (
                                                        'sort_order' => 'asc',
                                                        'number_of_records' => 0,
                                                        'format' => 'default_summary',
                                                    ),
                                                'specify_validation' => false,
                                                'validate' =>
                                                    array (
                                                        'type' => 'none',
                                                        'fail' => 'not found',
                                                    ),
                                                'validate_options' =>
                                                    array (
                                                    ),
                                                'break_phrase' => false,
                                                'not' => false,
                                                'entity_type' => 'node',
                                                'entity_field' => 'nid',
                                                'plugin_id' => 'node_nid',
                                            ),
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_page_du_site_1',
                                    ),
                            ),
                    ),

                'block_page_site_1' =>
                    array (
                        'display_plugin' => 'block',
                        'id' => 'block_page_site_1',
                        'display_title' => 'Page du site #1',
                        'position' => 1,
                        'display_options' =>
                            array (
                                'display_extenders' =>
                                    array (
                                    ),
                                'allow' =>
                                    array (
                                        'items_per_page' => true,
                                    ),
                                'display_description' => '',
                                'relationships' =>
                                    array (
                                        'field_page_du_site_1' =>
                                            array (
                                                'id' => 'field_page_du_site_1',
                                                'table' => 'node__field_page_du_site_1',
                                                'field' => 'field_page_du_site_1',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => 'field_page_du_site_1 : Contenu',
                                                'required' => true,
                                                'plugin_id' => 'standard',
                                            ),
                                    ),
                                'defaults' =>
                                    array (
                                        'relationships' => false,
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_page_du_site_1',
                                    ),
                            ),
                    ),
                'block_page_site_2' =>
                    array (
                        'display_plugin' => 'block',
                        'id' => 'block_page_site_2',
                        'display_title' => 'Page du site #2',
                        'position' => 1,
                        'display_options' =>
                            array (
                                'display_extenders' =>
                                    array (
                                    ),
                                'allow' =>
                                    array (
                                        'items_per_page' => true,
                                    ),
                                'display_description' => '',
                                'relationships' =>
                                    array (
                                        'field_page_du_site_2' =>
                                            array (
                                                'id' => 'field_page_du_site_2',
                                                'table' => 'node__field_page_du_site_2',
                                                'field' => 'field_page_du_site_2',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => 'field_page_du_site_2 : Contenu',
                                                'required' => true,
                                                'plugin_id' => 'standard',
                                            ),
                                    ),
                                'defaults' =>
                                    array (
                                        'relationships' => false,
                                        'fields' => false,
                                    ),
                                'fields' =>
                                    array (
                                        'field_page_du_site_2' =>
                                            array (
                                                'id' => 'field_page_du_site_2',
                                                'table' => 'node__field_page_du_site_2',
                                                'field' => 'field_page_du_site_2',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_entity_view',
                                                'settings' =>
                                                    array (
                                                        'view_mode' => 'rebond_page_site',
                                                    ),
                                                'group_column' => 'target_id',
                                                'group_columns' =>
                                                    array (
                                                    ),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                                'plugin_id' => 'field',
                                            ),
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_page_du_site_2',
                                    ),
                            ),
                    ),
            ),
    ),
    'block.block.views_block__rebond_document_block_document' => array (
        'uuid' => '8ad63b1b-162e-4c1c-984c-063e9a53b939',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'views.view.rebond_document',
                    ),
                'module' =>
                    array (
                        0 => 'ctools',
                        1 => 'views',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'views_block__rebond_document_block_document',
        'theme' => 'theme_boosted',
        'region' => 'sidebar',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'views_block:rebond_document-block_document',
        'settings' =>
            array (
                'id' => 'views_block:rebond_document-block_document',
                'label' => '',
                'provider' => 'views',
                'label_display' => '0',
                'views_label' => '',
                'items_per_page' => 'none',
                'context_mapping' =>
                    array (
                    ),
            ),
        'visibility' =>
            array (
                'entity_bundle:node' =>
                    array (
                        'id' => 'entity_bundle:node',
                        'bundles' =>
                            array (
                                'blog_post' => 'blog_post',
                                'customer_story' => 'customer_story',
                                'document' => 'document',
                                'magazine' => 'magazine',
                                'partner' => 'partner',
                                'press_release' => 'press_release',
                                'simple_page' => 'simple_page',
                                'webform' => 'webform',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'node' => '@node.node_route_context:node',
                            ),
                    ),
            ),
    ),
    'block.block.views_block__rebond_document_block_page_site_1' => array (
        'uuid' => '6149aaff-4d21-4acc-88c5-401600ea036a',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'views.view.rebond_document',
                    ),
                'module' =>
                    array (
                        0 => 'ctools',
                        1 => 'views',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'views_block__rebond_document_block_page_site_1',
        'theme' => 'theme_boosted',
        'region' => 'sidebar',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'views_block:rebond_document-block_page_site_1',
        'settings' =>
            array (
                'id' => 'views_block:rebond_document-block_page_site_1',
                'label' => '',
                'provider' => 'views',
                'label_display' => '0',
                'views_label' => '',
                'items_per_page' => 'none',
                'context_mapping' =>
                    array (
                    ),
            ),
        'visibility' =>
            array (
                'entity_bundle:node' =>
                    array (
                        'id' => 'entity_bundle:node',
                        'bundles' =>
                            array (
                                'blog_post' => 'blog_post',
                                'customer_story' => 'customer_story',
                                'document' => 'document',
                                'magazine' => 'magazine',
                                'partner' => 'partner',
                                'press_release' => 'press_release',
                                'simple_page' => 'simple_page',
                                'webform' => 'webform',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'node' => '@node.node_route_context:node',
                            ),
                    ),
            ),
    ),
    'block.block.views_block__rebond_document_block_page_site_2' => array (
        'uuid' => 'cd334b79-11a3-43b9-9b83-9dd49a6285ee',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'views.view.rebond_document',
                    ),
                'module' =>
                    array (
                        0 => 'ctools',
                        1 => 'views',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'views_block__rebond_document_block_page_site_2',
        'theme' => 'theme_boosted',
        'region' => 'sidebar',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'views_block:rebond_document-block_page_site_2',
        'settings' =>
            array (
                'id' => 'views_block:rebond_document-block_page_site_2',
                'label' => '',
                'provider' => 'views',
                'label_display' => '0',
                'views_label' => '',
                'items_per_page' => 'none',
                'context_mapping' =>
                    array (
                    ),
            ),
        'visibility' =>
            array (
                'entity_bundle:node' =>
                    array (
                        'id' => 'entity_bundle:node',
                        'bundles' =>
                            array (
                                'blog_post' => 'blog_post',
                                'customer_story' => 'customer_story',
                                'document' => 'document',
                                'magazine' => 'magazine',
                                'partner' => 'partner',
                                'press_release' => 'press_release',
                                'simple_page' => 'simple_page',
                                'webform' => 'webform',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'node' => '@node.node_route_context:node',
                            ),
                    ),
            ),
    )
];

foreach ($configs as $configName => $config) {
    $config_group = $config_factory->getEditable($configName);
    $config_group->setData($config);
    $config_group->save(TRUE);
}