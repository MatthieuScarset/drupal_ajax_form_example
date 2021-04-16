<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.subhomes');
$config_group->setData(
  array (
    'uuid' => 'ba0eb672-ee75-40c7-bf72-6c3567bb64a6',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.subhome',
            1 => 'taxonomy.vocabulary.document_types',
            2 => 'taxonomy.vocabulary.industries',
            3 => 'taxonomy.vocabulary.solutions',
          ),
        'module' =>
          array (
            0 => 'node',
            1 => 'taxonomy',
            2 => 'user',
            3 => 'views_infinite_scroll',
          ),
      ),
    'id' => 'subhomes',
    'label' => 'subhomes',
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
                        'submit_button' => t('Apply'),
                        'reset_button' => false,
                        'reset_button_label' => t('Reset'),
                        'exposed_sorts_label' => t('Sort by'),
                        'expose_sort_order' => true,
                        'sort_asc_label' => t('Asc'),
                        'sort_desc_label' => t('Desc'),
                      ),
                  ),
                'pager' =>
                  array (
                    'type' => 'infinite_scroll',
                    'options' =>
                      array (
                        'items_per_page' => 12,
                        'offset' => 0,
                        'id' => 0,
                        'total_pages' => NULL,
                        'tags' =>
                          array (
                            'previous' => t('‹ Previous'),
                            'next' => t('Next ›'),
                          ),
                        'expose' =>
                          array (
                            'items_per_page' => false,
                            'items_per_page_label' => t('Items per page'),
                            'items_per_page_options' => '5, 10, 25, 50',
                            'items_per_page_options_all' => false,
                            'items_per_page_options_all_label' => t('- All -'),
                            'offset' => false,
                            'offset_label' => t('Offset'),
                          ),
                        'views_infinite_scroll' =>
                          array (
                            'button_text' => t('Load More'),
                            'automatically_load_content' => false,
                          ),
                      ),
                  ),
                'style' =>
                  array (
                    'type' => 'grid',
                    'options' =>
                      array (
                        'uses_fields' => false,
                        'columns' => 4,
                        'automatic_width' => true,
                        'alignment' => 'horizontal',
                        'col_class_default' => true,
                        'col_class_custom' => '',
                        'row_class_default' => true,
                        'row_class_custom' => '',
                      ),
                  ),
                'row' =>
                  array (
                    'type' => 'entity:node',
                    'options' =>
                      array (
                        'relationship' => 'none',
                        'view_mode' => 'subhome',
                      ),
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
                        'label' => '',
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
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'Solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
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
                'title' => 'Press',
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
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_blog' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_blog',
            'display_title' => 'Blog',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'blogs',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'blog_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Blog',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_catalogue' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_catalogue',
            'display_title' => 'Catalogue',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'products',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'product_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Catalogue',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_customer' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_customer',
            'display_title' => 'Customers',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'case-study',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'customer_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                    'field_industry_target_id' =>
                      array (
                        'id' => 'field_industry_target_id',
                        'table' => 'node__field_industry',
                        'field' => 'field_industry_target_id',
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
                            'operator_id' => 'field_industry_target_id_op',
                            'label' => 'By industry',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_industry_target_id_op',
                            'identifier' => 'field_industry_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'industries',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Customers',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_document' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_document',
            'display_title' => 'Documents',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'library',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'library_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                    'field_industry_target_id' =>
                      array (
                        'id' => 'field_industry_target_id',
                        'table' => 'node__field_industry',
                        'field' => 'field_industry_target_id',
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
                            'operator_id' => 'field_industry_target_id_op',
                            'label' => 'By industry',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_industry_target_id_op',
                            'identifier' => 'field_industry_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'industries',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Documents',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_magazine' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_magazine',
            'display_title' => 'Magazine',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'magazine',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'magazine_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Magazine',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_partners' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_partners',
            'display_title' => 'Partners',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'partners',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'partner_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'title' => false,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'title' => 'Partners',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
        'page_press' =>
          array (
            'display_plugin' => 'page',
            'id' => 'page_press',
            'display_title' => 'Press',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'path' => 'press',
                'display_description' => '',
                'arguments' =>
                  array (
                    'field_subhome_target_id' =>
                      array (
                        'id' => 'field_subhome_target_id',
                        'table' => 'node__field_subhome',
                        'field' => 'field_subhome_target_id',
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
                        'default_argument_type' => 'config_key',
                        'default_argument_options' =>
                          array (
                            'config_name' => 'oab_subhomes.subhomes',
                            'config_key' => 'press_term_tid',
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
                        'plugin_id' => 'numeric',
                      ),
                  ),
                'defaults' =>
                  array (
                    'arguments' => false,
                    'filters' => false,
                    'filter_groups' => false,
                    'pager' => true,
                    'use_ajax' => false,
                    'style' => true,
                    'row' => true,
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
                    'langcode' =>
                      array (
                        'id' => 'langcode',
                        'table' => 'node',
                        'field' => 'langcode',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => '',
                        'operator' => 'in',
                        'value' =>
                          array (
                            '***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
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
                        'entity_field' => 'langcode',
                        'plugin_id' => 'language',
                      ),
                    'field_document_type_target_id' =>
                      array (
                        'id' => 'field_document_type_target_id',
                        'table' => 'node__field_document_type',
                        'field' => 'field_document_type_target_id',
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
                            'operator_id' => 'field_document_type_target_id_op',
                            'label' => 'By type',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_document_type_target_id_op',
                            'identifier' => 'field_document_type_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'document_types',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                    'field_solution_target_id' =>
                      array (
                        'id' => 'field_solution_target_id',
                        'table' => 'node__field_solution',
                        'field' => 'field_solution_target_id',
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
                            'operator_id' => 'field_solution_target_id_op',
                            'label' => 'By solution',
                            'description' => '',
                            'use_operator' => false,
                            'operator' => 'field_solution_target_id_op',
                            'identifier' => 'field_solution_target_id',
                            'required' => false,
                            'remember' => false,
                            'multiple' => false,
                            'remember_roles' =>
                              array (
                                'authenticated' => 'authenticated',
                                'anonymous' => '0',
                                'administrator' => '0',
                                'chief_editor' => '0',
                                'digital_admin' => '0',
                                'webform_manager' => '0',
                                'contributor' => '0',
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
                        'vid' => 'solutions',
                        'hierarchy' => false,
                        'error_message' => true,
                        'plugin_id' => 'taxonomy_index_tid',
                      ),
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'use_ajax' => true,
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
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
                  ),
              ),
          ),
      ),
  )
);
$config_group->save(TRUE);