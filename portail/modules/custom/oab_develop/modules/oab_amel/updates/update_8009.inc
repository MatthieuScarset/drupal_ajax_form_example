<?php

use \Drupal\Core\Utility\UpdateException;

/***
 * Fichier de configuration pour le dashboard du manager editorial : MISE A JOUR
 */

/*****************************
 * DASHBOARD MANAGER EDITORIAL
 *****************************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.dashboard_du_manager_editorial');
$config_group->setData(
    array(
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(
                'config' =>
                    array(
                        0 => 'field.storage.node.field_end_date',
                        1 => 'field.storage.node.field_rendering_model',
                        2 => 'field.storage.node.field_start_date',
                        3 => 'field.storage.node.field_state',
                        4 => 'node.type.container',
                        5 => 'taxonomy.vocabulary.rendering_model',
                    ),
                'module' =>
                    array(
                        0 => 'datetime',
                        1 => 'node',
                        2 => 'options',
                        3 => 'taxonomy',
                        4 => 'user',
                    ),
            ),
        'id' => 'dashboard_du_manager_editorial',
        'label' => 'Dashboard du manager editorial',
        'module' => 'views',
        'description' => '',
        'tag' => '',
        'base_table' => 'node_field_data',
        'base_field' => 'nid',
        'core' => '8.x',
        'display' =>
            array(
                'default' =>
                    array(
                        'display_plugin' => 'default',
                        'id' => 'default',
                        'display_title' => 'Master',
                        'position' => 0,
                        'display_options' =>
                            array(
                                'access' =>
                                    array(
                                        'type' => 'perm',
                                        'options' =>
                                            array(
                                                'perm' => 'access content overview',
                                            ),
                                    ),
                                'cache' =>
                                    array(
                                        'type' => 'tag',
                                        'options' =>
                                            array(),
                                    ),
                                'query' =>
                                    array(
                                        'type' => 'views_query',
                                        'options' =>
                                            array(
                                                'disable_sql_rewrite' => false,
                                                'distinct' => false,
                                                'replica' => false,
                                                'query_comment' => '',
                                                'query_tags' =>
                                                    array(),
                                            ),
                                    ),
                                'exposed_form' =>
                                    array(
                                        'type' => 'basic',
                                        'options' =>
                                            array(
                                                'submit_button' => 'Apply',
                                                'reset_button' => false,
                                                'reset_button_label' => 'Reset',
                                                'exposed_sorts_label' => 'Sort by',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array(
                                        'type' => 'full',
                                        'options' =>
                                            array(
                                                'items_per_page' => 10,
                                                'offset' => 0,
                                                'id' => 0,
                                                'total_pages' => NULL,
                                                'tags' =>
                                                    array(
                                                        'previous' => '‹ Previous',
                                                        'next' => 'Next ›',
                                                        'first' => '« First',
                                                        'last' => 'Last »',
                                                    ),
                                                'expose' =>
                                                    array(
                                                        'items_per_page' => false,
                                                        'items_per_page_label' => 'Items per page',
                                                        'items_per_page_options' => '5, 10, 25, 50',
                                                        'items_per_page_options_all' => false,
                                                        'items_per_page_options_all_label' => '- All -',
                                                        'offset' => false,
                                                        'offset_label' => 'Offset',
                                                    ),
                                                'quantity' => 9,
                                            ),
                                    ),
                                'style' =>
                                    array(
                                        'type' => 'table',
                                        'options' =>
                                            array(
                                                'grouping' =>
                                                    array(),
                                                'row_class' => '',
                                                'default_row_class' => true,
                                                'override' => true,
                                                'sticky' => false,
                                                'caption' => '',
                                                'summary' => '',
                                                'description' => '',
                                                'columns' =>
                                                    array(
                                                        'title' => 'title',
                                                        'field_rendering_model' => 'field_rendering_model',
                                                        'field_start_date' => 'field_start_date',
                                                        'field_end_date' => 'field_end_date',
                                                        'uid' => 'uid',
                                                    ),
                                                'info' =>
                                                    array(
                                                        'title' =>
                                                            array(
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_rendering_model' =>
                                                            array(
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_start_date' =>
                                                            array(
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_end_date' =>
                                                            array(
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'uid' =>
                                                            array(
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                    ),
                                                'default' => '-1',
                                                'empty_table' => false,
                                            ),
                                    ),
                                'row' =>
                                    array(
                                        'type' => 'fields',
                                    ),
                                'fields' =>
                                    array(
                                        'title' =>
                                            array(
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                                'alter' =>
                                                    array(
                                                        'alter_text' => false,
                                                        'make_link' => false,
                                                        'absolute' => false,
                                                        'trim' => false,
                                                        'word_boundary' => false,
                                                        'ellipsis' => false,
                                                        'strip_tags' => false,
                                                        'html' => false,
                                                    ),
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'settings' =>
                                                    array(
                                                        'link_to_entity' => true,
                                                    ),
                                                'plugin_id' => 'field',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Titre',
                                                'exclude' => false,
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'string',
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array(),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                            ),
                                        'uid_1' =>
                                            array(
                                                'id' => 'uid_1',
                                                'table' => 'node_field_revision',
                                                'field' => 'uid',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Auteur',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array(
                                                        'link' => true,
                                                    ),
                                                'group_column' => 'target_id',
                                                'group_columns' =>
                                                    array(),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                                'entity_type' => 'node',
                                                'entity_field' => 'uid',
                                                'plugin_id' => 'field',
                                            ),
                                        'field_rendering_model' =>
                                            array(
                                                'id' => 'field_rendering_model',
                                                'table' => 'node__field_rendering_model',
                                                'field' => 'field_rendering_model',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Modèle',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array(
                                                        'link' => true,
                                                    ),
                                                'group_column' => 'target_id',
                                                'group_columns' =>
                                                    array(),
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
                                        'langcode' =>
                                            array(
                                                'id' => 'langcode',
                                                'table' => 'node',
                                                'field' => 'langcode',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Langue d\'origine',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'click_sort_column' => 'value',
                                                'type' => 'language',
                                                'settings' =>
                                                    array(
                                                        'link_to_entity' => false,
                                                        'native_language' => false,
                                                    ),
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array(),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                                'entity_type' => 'node',
                                                'entity_field' => 'langcode',
                                                'plugin_id' => 'field',
                                            ),
                                        'field_state' =>
                                            array(
                                                'id' => 'field_state',
                                                'table' => 'node__field_state',
                                                'field' => 'field_state',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Workflow Status',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'list_default',
                                                'settings' =>
                                                    array(),
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array(),
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
                                        'field_start_date' =>
                                            array(
                                                'id' => 'field_start_date',
                                                'table' => 'node__field_start_date',
                                                'field' => 'field_start_date',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Date de début',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'click_sort_column' => 'value',
                                                'type' => 'datetime_default',
                                                'settings' =>
                                                    array(
                                                        'timezone_override' => '',
                                                        'format_type' => 'medium',
                                                    ),
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array(),
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
                                        'field_end_date' =>
                                            array(
                                                'id' => 'field_end_date',
                                                'table' => 'node__field_end_date',
                                                'field' => 'field_end_date',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Date d\'expiration',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'click_sort_column' => 'value',
                                                'type' => 'datetime_default',
                                                'settings' =>
                                                    array(
                                                        'timezone_override' => '',
                                                        'format_type' => 'medium',
                                                    ),
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array(),
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
                                        'operations' =>
                                            array(
                                                'id' => 'operations',
                                                'table' => 'node',
                                                'field' => 'operations',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Actions',
                                                'exclude' => false,
                                                'alter' =>
                                                    array(
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'destination' => true,
                                                'entity_type' => 'node',
                                                'plugin_id' => 'entity_operations',
                                            ),
                                    ),
                                'filters' =>
                                    array(
                                        'type' =>
                                            array(
                                                'id' => 'type',
                                                'table' => 'node_field_data',
                                                'field' => 'type',
                                                'value' =>
                                                    array(
                                                        'container' => 'container',
                                                    ),
                                                'entity_type' => 'node',
                                                'entity_field' => 'type',
                                                'plugin_id' => 'bundle',
                                                'group' => 1,
                                            ),
                                        'field_rendering_model_target_id' =>
                                            array(
                                                'id' => 'field_rendering_model_target_id',
                                                'table' => 'node__field_rendering_model',
                                                'field' => 'field_rendering_model_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array(),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array(
                                                        'operator_id' => 'field_rendering_model_target_id_op',
                                                        'label' => 'Modèle',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_rendering_model_target_id_op',
                                                        'identifier' => 'field_rendering_model_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array(
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'fh_admin' => '0',
                                                                'fh_content' => '0',
                                                                'editor' => '0',
                                                            ),
                                                        'reduce' => false,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array(
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array(),
                                                        'group_items' =>
                                                            array(),
                                                    ),
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'rendering_model',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
                                            ),
                                        'field_end_date_value' =>
                                            array(
                                                'id' => 'field_end_date_value',
                                                'table' => 'node__field_end_date',
                                                'field' => 'field_end_date_value',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'not empty',
                                                'value' =>
                                                    array(
                                                        'min' => '',
                                                        'max' => '',
                                                        'value' => '',
                                                        'type' => 'date',
                                                    ),
                                                'group' => 1,
                                                'exposed' => false,
                                                'expose' =>
                                                    array(
                                                        'operator_id' => '',
                                                        'label' => '',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => '',
                                                        'identifier' => '',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array(
                                                                'authenticated' => 'authenticated',
                                                            ),
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array(
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array(),
                                                        'group_items' =>
                                                            array(),
                                                    ),
                                                'plugin_id' => 'datetime',
                                            ),
                                        'field_state_value' =>
                                            array(
                                                'id' => 'field_state_value',
                                                'table' => 'node__field_state',
                                                'field' => 'field_state_value',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => '=',
                                                'value' => '',
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array(
                                                        'operator_id' => 'field_state_value_op',
                                                        'label' => 'Status (field_state)',
                                                        'description' => NULL,
                                                        'use_operator' => false,
                                                        'operator' => 'field_state_value_op',
                                                        'identifier' => 'field_state_value',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array(
                                                                'authenticated' => 'authenticated',
                                                            ),
                                                    ),
                                                'is_grouped' => true,
                                                'group_info' =>
                                                    array(
                                                        'label' => 'workflow',
                                                        'description' => '',
                                                        'identifier' => 'field_state_value',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array(),
                                                        'group_items' =>
                                                            array(
                                                                1 =>
                                                                    array(
                                                                        'title' => 'Draft',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_draft',
                                                                    ),
                                                                2 =>
                                                                    array(
                                                                        'title' => 'Waiting publication',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_awaiting_publication',
                                                                    ),
                                                                3 =>
                                                                    array(
                                                                        'title' => 'Unpublished',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_unpublished',
                                                                    ),
                                                                4 =>
                                                                    array(
                                                                        'title' => 'Published',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_published',
                                                                    ),
                                                            ),
                                                    ),
                                                'plugin_id' => 'string',
                                            ),
                                    ),
                                'sorts' =>
                                    array(
                                        'field_end_date_value' =>
                                            array(
                                                'id' => 'field_end_date_value',
                                                'table' => 'node__field_end_date',
                                                'field' => 'field_end_date_value',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'order' => 'ASC',
                                                'exposed' => false,
                                                'expose' =>
                                                    array(
                                                        'label' => 'Date d\'expiration',
                                                    ),
                                                'granularity' => 'second',
                                                'plugin_id' => 'datetime',
                                            ),
                                    ),
                                'title' => 'Dashboard du manager editorial',
                                'header' =>
                                    array(),
                                'footer' =>
                                    array(),
                                'empty' =>
                                    array(),
                                'relationships' =>
                                    array(),
                                'arguments' =>
                                    array(),
                                'display_extenders' =>
                                    array(),
                                'filter_groups' =>
                                    array(
                                        'operator' => 'AND',
                                        'groups' =>
                                            array(
                                                1 => 'AND',
                                            ),
                                    ),
                            ),
                        'cache_metadata' =>
                            array(
                                'max - age' => 0,
                                'contexts' =>
                                    array(
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array(
                                        0 => 'config:field.storage.node.field_end_date',
                                        1 => 'config:field.storage.node.field_rendering_model',
                                        2 => 'config:field.storage.node.field_start_date',
                                        3 => 'config:field.storage.node.field_state',
                                    ),
                            ),
                    ),
                'page_1' =>
                    array(
                        'display_plugin' => 'page',
                        'id' => 'page_1',
                        'display_title' => 'Page',
                        'position' => 1,
                        'display_options' =>
                            array(
                                'display_extenders' =>
                                    array(),
                                'path' => 'admin/content/dashboard',
                                'menu' =>
                                    array(
                                        'type' => 'tab',
                                        'title' => 'Dashboard',
                                        'description' => '',
                                        'expanded' => false,
                                        'parent' => '',
                                        'weight' => 0,
                                        'context' => '0',
                                        'menu_name' => 'main',
                                        'enabled' => true,
                                    ),
                            ),
                        'cache_metadata' =>
                            array(
                                'max - age' => 0,
                                'contexts' =>
                                    array(
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array(
                                        0 => 'config:field.storage.node.field_end_date',
                                        1 => 'config:field.storage.node.field_rendering_model',
                                        2 => 'config:field.storage.node.field_start_date',
                                        3 => 'config:field.storage.node.field_state',
                                    ),
                            ),
                    ),
            ),
    ));

$config_group->save(TRUE);


/***
 * Fichier de configuration pour la vue content
 */

/*****************************
 * VIEW CONTENT
 *****************************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.content');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_rendering_model',
                        1 => 'field.storage.node.field_state',
                        2 => 'taxonomy.vocabulary.rendering_model',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'options',
                        2 => 'taxonomy',
                        3 => 'user',
                    ),
            ),
        'id' => 'content',
        'label' => 'Content',
        'module' => 'node',
        'description' => 'Trouver et gérer le contenu.',
        'tag' => 'default',
        'base_table' => 'node_field_data',
        'base_field' => 'nid',
        'core' => '8.x',
        'display' =>
            array (
                'default' =>
                    array (
                        'display_options' =>
                            array (
                                'access' =>
                                    array (
                                        'type' => 'perm',
                                        'options' =>
                                            array (
                                                'perm' => 'access content overview',
                                            ),
                                    ),
                                'cache' =>
                                    array (
                                        'type' => 'tag',
                                    ),
                                'query' =>
                                    array (
                                        'type' => 'views_query',
                                    ),
                                'exposed_form' =>
                                    array (
                                        'type' => 'basic',
                                        'options' =>
                                            array (
                                                'submit_button' => 'Filtrer',
                                                'reset_button' => true,
                                                'reset_button_label' => 'Reset',
                                                'exposed_sorts_label' => 'Sort by',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array (
                                        'type' => 'full',
                                        'options' =>
                                            array (
                                                'items_per_page' => 50,
                                                'tags' =>
                                                    array (
                                                        'previous' => '‹ Previous',
                                                        'next' => 'Next ›',
                                                        'first' => '« First',
                                                        'last' => 'Last »',
                                                    ),
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'table',
                                        'options' =>
                                            array (
                                                'grouping' =>
                                                    array (
                                                    ),
                                                'row_class' => '',
                                                'default_row_class' => true,
                                                'override' => true,
                                                'sticky' => true,
                                                'caption' => '',
                                                'summary' => '',
                                                'description' => '',
                                                'columns' =>
                                                    array (
                                                        'node_bulk_form' => 'node_bulk_form',
                                                        'title' => 'title',
                                                        'name' => 'name',
                                                        'type' => 'type',
                                                        'field_rendering_model' => 'field_rendering_model',
                                                        'langcode' => 'langcode',
                                                        'field_state' => 'field_state',
                                                        'field_start_date' => 'field_start_date',
                                                        'field_end_date' => 'field_end_date',
                                                        'created' => 'created',
                                                        'changed' => 'changed',
                                                        'operations' => 'operations',
                                                    ),
                                                'info' =>
                                                    array (
                                                        'node_bulk_form' =>
                                                            array (
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'title' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'name' =>
                                                            array (
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => 'priority-low',
                                                            ),
                                                        'type' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_rendering_model' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'langcode' =>
                                                            array (
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_state' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_start_date' =>
                                                            array (
                                                                'sortable' => false,
                                                                'default_sort_order' => 'desc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'field_end_date' =>
                                                            array (
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'created' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                        'changed' =>
                                                            array (
                                                                'sortable' => true,
                                                                'default_sort_order' => 'desc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => 'priority-low',
                                                            ),
                                                        'operations' =>
                                                            array (
                                                                'sortable' => false,
                                                                'default_sort_order' => 'asc',
                                                                'align' => '',
                                                                'separator' => '',
                                                                'empty_column' => false,
                                                                'responsive' => '',
                                                            ),
                                                    ),
                                                'default' => 'changed',
                                                'empty_table' => true,
                                            ),
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'fields',
                                    ),
                                'fields' =>
                                    array (
                                        'node_bulk_form' =>
                                            array (
                                                'id' => 'node_bulk_form',
                                                'table' => 'node',
                                                'field' => 'node_bulk_form',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                    ),
                                                'element_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'plugin_id' => 'node_bulk_form',
                                                'entity_type' => 'node',
                                            ),
                                        'title' =>
                                            array (
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'label' => 'Titre',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                    ),
                                                'element_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                                'type' => 'string',
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => true,
                                                    ),
                                                'plugin_id' => 'field',
                                            ),
                                        'name' =>
                                            array (
                                                'id' => 'name',
                                                'table' => 'users_field_data',
                                                'field' => 'name',
                                                'relationship' => 'uid',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Auteur',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'user_name',
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => true,
                                                    ),
                                                'group_column' => 'value',
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
                                                'entity_type' => 'user',
                                                'entity_field' => 'name',
                                            ),
                                        'type' =>
                                            array (
                                                'id' => 'type',
                                                'table' => 'node_field_data',
                                                'field' => 'type',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Type',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array (
                                                        'link' => false,
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
                                                'entity_type' => 'node',
                                                'entity_field' => 'type',
                                                'plugin_id' => 'field',
                                            ),
                                        'field_rendering_model' =>
                                            array (
                                                'id' => 'field_rendering_model',
                                                'table' => 'node__field_rendering_model',
                                                'field' => 'field_rendering_model',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Modèle',
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
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array (
                                                        'link' => false,
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
                                        'langcode' =>
                                            array (
                                                'id' => 'langcode',
                                                'table' => 'node_field_data',
                                                'field' => 'langcode',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Langue',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'language',
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => false,
                                                        'native_language' => false,
                                                    ),
                                                'group_column' => 'value',
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
                                                'entity_type' => 'node',
                                                'entity_field' => 'langcode',
                                                'plugin_id' => 'field',
                                            ),
                                        'field_state' =>
                                            array (
                                                'id' => 'field_state',
                                                'table' => 'node__field_state',
                                                'field' => 'field_state',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Statut',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'list_default',
                                                'settings' =>
                                                    array (
                                                    ),
                                                'group_column' => 'value',
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
                                        'created' =>
                                            array (
                                                'id' => 'created',
                                                'table' => 'node_field_data',
                                                'field' => 'created',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Écrit le',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'timestamp',
                                                'settings' =>
                                                    array (
                                                        'date_format' => 'short',
                                                        'custom_date_format' => '',
                                                        'timezone' => '',
                                                    ),
                                                'group_column' => 'value',
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
                                                'entity_type' => 'node',
                                                'entity_field' => 'short',
                                                'plugin_id' => 'field',
                                            ),
                                        'changed' =>
                                            array (
                                                'id' => 'changed',
                                                'table' => 'node_field_data',
                                                'field' => 'changed',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Date de mise à jour',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'timestamp',
                                                'settings' =>
                                                    array (
                                                        'date_format' => 'short',
                                                        'custom_date_format' => '',
                                                        'timezone' => '',
                                                    ),
                                                'group_column' => 'value',
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
                                                'entity_type' => 'node',
                                                'entity_field' => 'changed',
                                            ),
                                        'operations' =>
                                            array (
                                                'id' => 'operations',
                                                'table' => 'node',
                                                'field' => 'operations',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => 'Actions',
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
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'destination' => true,
                                                'plugin_id' => 'entity_operations',
                                            ),
                                    ),
                                'filters' =>
                                    array (
                                        'title' =>
                                            array (
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'contains',
                                                'value' => '',
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'title_op',
                                                        'label' => 'Titre',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'title_op',
                                                        'identifier' => 'title',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                            ),
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'plugin_id' => 'string',
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                            ),
                                        'type' =>
                                            array (
                                                'id' => 'type',
                                                'table' => 'node_field_data',
                                                'field' => 'type',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'in',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'type_op',
                                                        'label' => 'Type',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'type_op',
                                                        'identifier' => 'type',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                            ),
                                                        'reduce' => false,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'plugin_id' => 'bundle',
                                                'entity_type' => 'node',
                                                'entity_field' => 'type',
                                            ),
                                        'field_rendering_model_target_id' =>
                                            array (
                                                'id' => 'field_rendering_model_target_id',
                                                'table' => 'node__field_rendering_model',
                                                'field' => 'field_rendering_model_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_rendering_model_target_id_op',
                                                        'label' => 'Model',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_rendering_model_target_id_op',
                                                        'identifier' => 'field_rendering_model_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'fh_admin' => '0',
                                                                'fh_content' => '0',
                                                                'editor' => '0',
                                                            ),
                                                        'reduce' => false,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'rendering_model',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
                                            ),
                                        'langcode' =>
                                            array (
                                                'id' => 'langcode',
                                                'table' => 'node_field_data',
                                                'field' => 'langcode',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'in',
                                                'value' =>
                                                    array (
                                                        'en' => 'en',
                                                        'fr' => 'fr',
                                                        'ru' => 'ru',
                                                        'ru-en' => 'ru-en',
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'langcode_op',
                                                        'label' => 'Language',
                                                        'description' => '',
                                                        'use_operator' => 0,
                                                        'operator' => 'langcode_op',
                                                        'identifier' => 'langcode',
                                                        'required' => 0,
                                                        'remember' => 0,
                                                        'multiple' => 0,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => 0,
                                                                'administrator' => 0,
                                                                'fh_admin' => 0,
                                                                'fh_content' => 0,
                                                                'editor' => 0,
                                                            ),
                                                        'reduce' => 1,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'plugin_id' => 'language',
                                                'entity_type' => 'node',
                                                'entity_field' => 'langcode',
                                            ),
                                        'field_state_value' =>
                                            array (
                                                'id' => 'field_state_value',
                                                'table' => 'node__field_state',
                                                'field' => 'field_state_value',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => '=',
                                                'value' => '',
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_state_value_op',
                                                        'label' => 'State (field_state)',
                                                        'description' => NULL,
                                                        'use_operator' => false,
                                                        'operator' => 'field_state_value_op',
                                                        'identifier' => 'field_state_value',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                            ),
                                                    ),
                                                'is_grouped' => true,
                                                'group_info' =>
                                                    array (
                                                        'label' => 'workflow',
                                                        'description' => '',
                                                        'identifier' => 'field_state_value',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                                1 =>
                                                                    array (
                                                                        'title' => 'Draft',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_draft',
                                                                    ),
                                                                2 =>
                                                                    array (
                                                                        'title' => 'Waiting publication',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_awaiting_publication',
                                                                    ),
                                                                3 =>
                                                                    array (
                                                                        'title' => 'Unpublished',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_unpublished',
                                                                    ),
                                                                4 =>
                                                                    array (
                                                                        'title' => 'Published',
                                                                        'operator' => '=',
                                                                        'value' => 'content_workflow_published',
                                                                    ),
                                                            ),
                                                    ),
                                                'plugin_id' => 'string',
                                            ),
                                    ),
                                'sorts' =>
                                    array (
                                    ),
                                'title' => 'Content',
                                'empty' =>
                                    array (
                                        'area_text_custom' =>
                                            array (
                                                'id' => 'area_text_custom',
                                                'table' => 'views',
                                                'field' => 'area_text_custom',
                                                'empty' => true,
                                                'content' => 'No content available.',
                                                'plugin_id' => 'text_custom',
                                            ),
                                    ),
                                'arguments' =>
                                    array (
                                    ),
                                'relationships' =>
                                    array (
                                        'uid' =>
                                            array (
                                                'id' => 'uid',
                                                'table' => 'node_field_data',
                                                'field' => 'uid',
                                                'admin_label' => 'author',
                                                'required' => true,
                                                'plugin_id' => 'standard',
                                            ),
                                    ),
                                'show_admin_links' => false,
                                'filter_groups' =>
                                    array (
                                        'operator' => 'AND',
                                        'groups' =>
                                            array (
                                                1 => 'AND',
                                            ),
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'display_plugin' => 'default',
                        'display_title' => 'Master',
                        'id' => 'default',
                        'position' => 0,
                        'cache_metadata' =>
                            array (
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'max-age' => 0,
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_rendering_model',
                                        1 => 'config:field.storage.node.field_state',
                                    ),
                            ),
                    ),
                'page_content_dashboard' =>
                    array (
                        'display_options' =>
                            array (
                                'path' => 'admin/content/node',
                                'menu' =>
                                    array (
                                        'type' => 'default tab',
                                        'title' => 'Contenu',
                                        'description' => '',
                                        'menu_name' => 'admin',
                                        'weight' => -10,
                                        'context' => '',
                                        'enabled' => true,
                                        'expanded' => false,
                                    ),
                                'tab_options' =>
                                    array (
                                        'type' => 'normal',
                                        'title' => 'Contenu',
                                        'description' => 'Trouver et gérer le contenu',
                                        'menu_name' => 'admin',
                                        'weight' => -10,
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'display_plugin' => 'page',
                        'display_title' => 'Page',
                        'id' => 'page_content_dashboard',
                        'position' => 1,
                        'cache_metadata' =>
                            array (
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'max-age' => 0,
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_rendering_model',
                                        1 => 'config:field.storage.node.field_state',
                                    ),
                            ),
                    ),
            ),
    )
);

$config_group->save(TRUE);



//throw new \Drupal\Core\Utility\UpdateException();