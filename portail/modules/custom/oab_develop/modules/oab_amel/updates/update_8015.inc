<?php

use Drupal\Core\Database\Database;
use \Drupal\Core\Utility\UpdateException;

/***
 * Fichier de configuration pour le dashboard
 */

/***********
 * DASHBOARD
 ************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.dashboard');
$config_group->setData(
array (
    'uuid' => '0118bf98-891f-4128-bf38-6bf58d858bb7',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_end_date',
                    1 => 'field.storage.node.field_rendering_model',
                    2 => 'field.storage.node.field_start_date',
                    3 => 'field.storage.node.field_state',
                    4 => 'node.type.container',
                ),
            'module' =>
                array (
                    0 => 'datetime',
                    1 => 'node',
                    2 => 'options',
                    3 => 'user',
                ),
        ),
    'id' => 'dashboard',
    'label' => 'Dashboard',
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
                                            'perm' => 'access content overview',
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
                                array (
                                    'type' => 'full',
                                    'options' =>
                                        array (
                                            'items_per_page' => 10,
                                            'offset' => 0,
                                            'id' => 0,
                                            'total_pages' => NULL,
                                            'tags' =>
                                                array (
                                                    'previous' => '‹‹',
                                                    'next' => '››',
                                                    'first' => '« First',
                                                    'last' => 'Last »',
                                                ),
                                            'expose' =>
                                                array (
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
                                array (
                                    'type' => 'table',
                                ),
                            'row' =>
                                array (
                                    'type' => 'fields',
                                ),
                            'fields' =>
                                array (
                                    'title' =>
                                        array (
                                            'id' => 'title',
                                            'table' => 'node_field_data',
                                            'field' => 'title',
                                            'entity_type' => 'node',
                                            'entity_field' => 'title',
                                            'alter' =>
                                                array (
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
                                                array (
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
                                        ),
                                    'uid' =>
                                        array (
                                            'id' => 'uid',
                                            'table' => 'node_field_data',
                                            'field' => 'uid',
                                            'relationship' => 'none',
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
                                            'click_sort_column' => 'target_id',
                                            'type' => 'entity_reference_label',
                                            'settings' =>
                                                array (
                                                    'link' => true,
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
                                            'entity_field' => 'uid',
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
                                                    'link' => true,
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
                                            'table' => 'node',
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
                                            'label' => 'Statut du Workflow',
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
                                    'field_start_date' =>
                                        array (
                                            'id' => 'field_start_date',
                                            'table' => 'node__field_start_date',
                                            'field' => 'field_start_date',
                                            'relationship' => 'none',
                                            'group_type' => 'group',
                                            'admin_label' => '',
                                            'label' => 'Date de début',
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
                                            'type' => 'datetime_default',
                                            'settings' =>
                                                array (
                                                    'timezone_override' => '',
                                                    'format_type' => 'short',
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
                                    'field_end_date' =>
                                        array (
                                            'id' => 'field_end_date',
                                            'table' => 'node__field_end_date',
                                            'field' => 'field_end_date',
                                            'relationship' => 'none',
                                            'group_type' => 'group',
                                            'admin_label' => '',
                                            'label' => 'Date d\'expiration',
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
            'type' => 'datetime_default',
            'settings' =>
            array (
              'timezone_override' => '',
              'format_type' => 'short',
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
          'operations' =>
          array (
            'id' => 'operations',
            'table' => 'node',
            'field' => 'operations',
            'relationship' => 'none',
            'group_type' => 'group',
            'admin_label' => '',
            'label' => 'Liens d\'actions',
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
            'entity_type' => 'node',
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
                    'operator' => '=',
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
                                    'fh_admin' => '0',
                                    'fh_content' => '0',
                                    'editor' => '0',
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
                    'entity_type' => 'node',
                    'entity_field' => 'title',
                    'plugin_id' => 'string',
                ),
            'uid' =>
                array (
                    'id' => 'uid',
                    'table' => 'node_field_data',
                    'field' => 'uid',
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
                            'operator_id' => 'uid_op',
                            'label' => 'Auteur',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'uid_op',
                            'identifier' => 'uid',
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
                    'entity_type' => 'node',
                    'entity_field' => 'uid',
                    'plugin_id' => 'user_name',
                ),
            'langcode' =>
                array (
                    'id' => 'langcode',
                    'table' => 'node_field_revision',
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
                            'label' => 'Langue de traduction',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'langcode_op',
                            'identifier' => 'langcode',
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
                            'reduce' => true,
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
                    'entity_type' => 'node',
                    'entity_field' => 'langcode',
                    'plugin_id' => 'language',
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
                            'label' => 'Status (field_state)',
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
                            'label' => 'Statut du Workflow',
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
            'field_end_date_value' =>
                array (
                    'id' => 'field_end_date_value',
                    'table' => 'node__field_end_date',
                    'field' => 'field_end_date_value',
                    'relationship' => 'none',
                    'group_type' => 'group',
                    'admin_label' => '',
                    'operator' => 'not empty',
                    'value' =>
                        array (
                            'min' => '',
                            'max' => '',
                            'value' => '',
                            'type' => 'date',
                        ),
                    'group' => 1,
                    'exposed' => false,
                    'expose' =>
                        array (
                            'operator_id' => 'field_end_date_value_op',
                            'label' => 'End date (field_end_date)',
                            'description' => NULL,
                            'use_operator' => false,
                            'operator' => 'field_end_date_value_op',
                            'identifier' => 'field_end_date_value',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                                array (
                                    'authenticated' => 'authenticated',
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
                    'plugin_id' => 'datetime',
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
                            'container' => 'container',
                        ),
                    'group' => 1,
                    'exposed' => false,
                    'expose' =>
                        array (
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
                                array (
                                    'authenticated' => 'authenticated',
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
                    'entity_type' => 'node',
                    'entity_field' => 'type',
                    'plugin_id' => 'bundle',
                ),
        ),
        'sorts' =>
        array (
            'field_end_date_value' =>
                array (
                    'id' => 'field_end_date_value',
                    'table' => 'node__field_end_date',
                    'field' => 'field_end_date_value',
                    'relationship' => 'none',
                    'group_type' => 'group',
                    'admin_label' => '',
                    'order' => 'ASC',
                    'exposed' => false,
                    'expose' =>
                        array (
                            'label' => '',
                        ),
                    'granularity' => 'second',
                    'plugin_id' => 'datetime',
                ),
        ),
        'title' => 'Dashboard',
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
        ),
        'arguments' =>
        array (
        ),
        'display_extenders' =>
        array (
        ),
        'filter_groups' =>
        array (
            'operator' => 'AND',
            'groups' =>
                array (
                    1 => 'AND',
                ),
        ),
      ),
      'cache_metadata' =>
      array (
          'max-age' => 0,
          'contexts' =>
              array (
                  0 => 'languages:language_content',
                  1 => 'languages:language_interface',
                  2 => 'url',
                  3 => 'url.query_args',
                  4 => 'user.node_grants:view',
                  5 => 'user.permissions',
              ),
          'tags' =>
              array (
                  0 => 'config:field.storage.node.field_end_date',
                  1 => 'config:field.storage.node.field_rendering_model',
                  2 => 'config:field.storage.node.field_start_date',
                  3 => 'config:field.storage.node.field_state',
              ),
      ),
    ),
    'page_1' =>
    array (
        'display_plugin' => 'page',
        'id' => 'page_1',
        'display_title' => 'Page',
        'position' => 1,
        'display_options' =>
            array (
                'display_extenders' =>
                    array (
                    ),
                'path' => 'admin/content/dashboard',
                'menu' =>
                    array (
                        'type' => 'tab',
                        'title' => 'Dashboard',
                        'description' => 'Gestion des contenus expirés pour le manager éditorial',
                        'expanded' => false,
                        'parent' => '',
                        'weight' => 0,
                        'context' => '0',
                        'menu_name' => 'main',
                    ),
            ),
        'cache_metadata' =>
            array (
                'max-age' => 0,
                'contexts' =>
                    array (
                        0 => 'languages:language_content',
                        1 => 'languages:language_interface',
                        2 => 'url',
                        3 => 'url.query_args',
                        4 => 'user.node_grants:view',
                        5 => 'user.permissions',
                    ),
                'tags' =>
                    array (
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


// Gestion de la traduction

$connection = Database::getConnection();
$query_delete = $connection->delete('config')
    ->condition('collection', 'language.en')
    ->condition('name', 'views.view.dashboard')
    ->execute();

$query_create = $connection->insert('config')
    ->fields(array(
        'collection' => 'language.en',
        'name' => 'views.view.dashboard',
        'data' => serialize(array (
            'display' =>
                array (
                    'default' =>
                        array (
                            'display_options' =>
                                array (
                                    'fields' =>
                                        array (
                                            'title' =>
                                                array (
                                                    'label' => 'Title',
                                                ),
                                            'uid' =>
                                                array (
                                                    'label' => 'Author',
                                                ),
                                            'field_rendering_model' =>
                                                array (
                                                    'label' => 'Model',
                                                ),
                                            'langcode' =>
                                                array (
                                                    'label' => 'Language',
                                                ),
                                            'field_state' =>
                                                array (
                                                    'label' => 'Workflow status',
                                                ),
                                            'field_start_date' =>
                                                array (
                                                    'label' => 'Creation date',
                                                ),
                                            'field_end_date' =>
                                                array (
                                                    'label' => 'Expires on',
                                                ),
                                            'operations' =>
                                                array (
                                                    'label' => 'Actions',
                                                ),
                                        ),
                                    'filters' =>
                                        array (
                                            'field_state_value' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'description' => '',
                                                        ),
                                                ),
                                            'field_end_date_value' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'description' => '',
                                                        ),
                                                ),
                                        ),
                                ),
                        ),
                ),
        ))
    ))
    ->execute();
