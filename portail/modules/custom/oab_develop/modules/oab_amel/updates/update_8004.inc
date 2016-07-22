<?php

use \Drupal\language\Config\LanguageConfigFactoryOverride;

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.dashboard_du_manager_editorial');
$config_group->setData(array (
  'uuid' => NULL,
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_end_date',
          1 => 'field.storage.node.field_rendering_model',
          2 => 'field.storage.node.field_start_date',
          3 => 'node.type.container',
          4 => 'taxonomy.vocabulary.rendering_model',
        ),
      'module' =>
        array (
          0 => 'datetime',
          1 => 'node',
          2 => 'taxonomy',
          3 => 'user',
        ),
    ),
  'id' => 'dashboard_du_manager_editorial',
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
                          'previous' => '‹ Previous',
                          'next' => 'Next ›',
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
                  'options' =>
                    array (
                      'grouping' =>
                        array (
                        ),
                      'row_class' => '',
                      'default_row_class' => true,
                      'override' => true,
                      'sticky' => false,
                      'caption' => '',
                      'summary' => '',
                      'description' => '',
                      'columns' =>
                        array (
                          'title' => 'title',
                          'field_rendering_model' => 'field_rendering_model',
                          'field_start_date' => 'field_start_date',
                          'field_end_date' => 'field_end_date',
                          'uid' => 'uid',
                        ),
                      'info' =>
                        array (
                          'title' =>
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
                              'sortable' => false,
                              'default_sort_order' => 'asc',
                              'align' => '',
                              'separator' => '',
                              'empty_column' => false,
                              'responsive' => '',
                            ),
                          'field_start_date' =>
                            array (
                              'sortable' => true,
                              'default_sort_order' => 'asc',
                              'align' => '',
                              'separator' => '',
                              'empty_column' => false,
                              'responsive' => '',
                            ),
                          'field_end_date' =>
                            array (
                              'sortable' => true,
                              'default_sort_order' => 'asc',
                              'align' => '',
                              'separator' => '',
                              'empty_column' => false,
                              'responsive' => '',
                            ),
                          'uid' =>
                            array (
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
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Title',
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
                          'word_boundary' => false,
                          'ellipsis' => false,
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
                      'type' => 'string',
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
                      'entity_type' => 'node',
                      'entity_field' => 'title',
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
                      'label' => 'Model',
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
                  'field_start_date' =>
                    array (
                      'id' => 'field_start_date',
                      'table' => 'node__field_start_date',
                      'field' => 'field_start_date',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Start Date',
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
                      'click_sort_column' => 'value',
                      'type' => 'datetime_default',
                      'settings' =>
                        array (
                          'timezone_override' => '',
                          'format_type' => 'medium',
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
                      'label' => 'Expiration Date',
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
                      'click_sort_column' => 'value',
                      'type' => 'datetime_default',
                      'settings' =>
                        array (
                          'timezone_override' => '',
                          'format_type' => 'medium',
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
                  'uid' =>
                    array (
                      'id' => 'uid',
                      'table' => 'node_field_revision',
                      'field' => 'uid',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Author',
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
                ),
              'filters' =>
                array (
                  'type' =>
                    array (
                      'id' => 'type',
                      'table' => 'node_field_data',
                      'field' => 'type',
                      'value' =>
                        array (
                          'container' => 'container',
                        ),
                      'entity_type' => 'node',
                      'entity_field' => 'type',
                      'plugin_id' => 'bundle',
                      'group' => 1,
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
                          'label' => 'Modèle',
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
                          'label' => 'Date d\'expiration',
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
          4 => 'user',
          5 => 'user.node_grants:view',
          6 => 'user.permissions',
        ),
        'tags' =>
        array (
          0 => 'config:field.storage.node.field_end_date',
          1 => 'config:field.storage.node.field_rendering_model',
          2 => 'config:field.storage.node.field_start_date',
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
          'description' => '',
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
          4 => 'user',
          5 => 'user.node_grants:view',
          6 => 'user.permissions',
        ),
        'tags' =>
        array (
          0 => 'config:field.storage.node.field_end_date',
          1 => 'config:field.storage.node.field_rendering_model',
          2 => 'config:field.storage.node.field_start_date',
        ),
      ),
    ),
  ),
));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
//$config_factory->setLanguage(\Drupal::languageManager()->getLanguage('en'));
$config_group = $config_factory->getEditable('views.view.dashboard_du_manager_editorial');
$config_group->setData(
    array (
        'label' => 'Dashboard',
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
                                        'field_rendering_model' =>
                                            array (
                                                'label' => 'Model',
                                            ),
                                        'field_start_date' =>
                                            array (
                                                'label' => 'Start date',
                                            ),
                                        'field_end_date' =>
                                            array (
                                                'label' => 'Expiration date',
                                            ),
                                        'uid' =>
                                            array (
                                                'label' => 'Author',
                                            ),
                                    ),
                                'title' => 'Dashboard',
                            ),
                    ),
                'page_1' =>
                    array (
                        'display_options' =>
                            array (
                                'menu' =>
                                    array (
                                        'description' => 'Editorial manager dashboard, to manage content validity',
                                    ),
                            ),
                    ),
            ),
    )
);

$config_group->save(TRUE);