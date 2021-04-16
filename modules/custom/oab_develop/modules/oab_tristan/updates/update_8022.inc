<?php

$config_factory = \Drupal::configFactory();

############################
##Modification du formulaire
$config_group = $config_factory->getEditable('views.view.subhomes');

##On reset
$config_group->setData(array (
  'uuid' => 'ba0eb672-ee75-40c7-bf72-6c3567bb64a6',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.subhome',
          1 => 'node.type.press_kit',
          2 => 'node.type.press_release',
          3 => 'taxonomy.vocabulary.blog_thematics',
          4 => 'taxonomy.vocabulary.document_types',
          5 => 'taxonomy.vocabulary.industries',
          6 => 'taxonomy.vocabulary.jobs_profiles',
          7 => 'taxonomy.vocabulary.magazine_thematics',
          8 => 'taxonomy.vocabulary.market_segments',
          9 => 'taxonomy.vocabulary.partner_types',
          10 => 'taxonomy.vocabulary.regions',
          11 => 'taxonomy.vocabulary.solutions',
        ),
      'module' =>
        array (
          0 => 'node',
          1 => 'oab_backoffice',
          2 => 'taxonomy',
          3 => 'user',
          4 => 'views_infinite_scroll',
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
                  'type' => 'infinite_scroll',
                  'options' =>
                    array (
                      'items_per_page' => 12,
                      'offset' => 0,
                      'id' => 0,
                      'total_pages' => NULL,
                      'tags' =>
                        array (
                          'previous' => '‹ Previous',
                          'next' => 'Next ›',
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
                      'views_infinite_scroll' =>
                        array (
                          'button_text' => 'Load More',
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
          'display_title' => 'blogs',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_blogs',
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
                  'field_blog_thematic_target_id' =>
                    array (
                      'id' => 'field_blog_thematic_target_id',
                      'table' => 'node__field_blog_thematic',
                      'field' => 'field_blog_thematic_target_id',
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
                          'operator_id' => 'field_blog_thematic_target_id_op',
                          'label' => 'By thematic',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'field_blog_thematic_target_id_op',
                          'identifier' => 'field_blog_thematic_target_id',
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
                      'vid' => 'blog_thematics',
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
          'display_title' => 'products',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_catalogue',
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
                  'tid' =>
                    array (
                      'id' => 'tid',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_op',
                          'label' => 'By job profile',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_op',
                          'identifier' => 'field_jobs_target_id',
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
                      'vid' => 'jobs_profiles',
                      'hierarchy' => false,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
                    ),
                  'tid_1' =>
                    array (
                      'id' => 'tid_1',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_1_op',
                          'label' => 'By market segment',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_1_op',
                          'identifier' => 'field_market_target_id',
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
                      'vid' => 'market_segments',
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
          'title' => 'Products',
        ),
      'page_customer' =>
        array (
          'display_plugin' => 'page',
          'id' => 'page_customer',
          'display_title' => 'customer stories',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_customers',
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
                  'tid' =>
                    array (
                      'id' => 'tid',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_op',
                          'label' => 'By job profile',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_op',
                          'identifier' => 'field_jobs_target_id',
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
                      'vid' => 'jobs_profiles',
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
          'title' => 'Case study',
        ),
      'page_document' =>
        array (
          'display_plugin' => 'page',
          'id' => 'page_document',
          'display_title' => 'documents',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_documents',
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
                  'field_blog_thematic_target_id' =>
                    array (
                      'id' => 'field_blog_thematic_target_id',
                      'table' => 'node__field_blog_thematic',
                      'field' => 'field_blog_thematic_target_id',
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
                          'operator_id' => 'field_blog_thematic_target_id_op',
                          'label' => 'By thematic',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'field_blog_thematic_target_id_op',
                          'identifier' => 'field_blog_thematic_target_id',
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
                      'vid' => 'blog_thematics',
                      'hierarchy' => false,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
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
                  'tid' =>
                    array (
                      'id' => 'tid',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_op',
                          'label' => 'By job profile',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_op',
                          'identifier' => 'field_jobs_target_id',
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
                      'vid' => 'jobs_profiles',
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
          'title' => 'Library',
        ),
      'page_magazine' =>
        array (
          'display_plugin' => 'page',
          'id' => 'page_magazine',
          'display_title' => 'magazine',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_magazine',
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
                  'field_magazine_thematic_target_id' =>
                    array (
                      'id' => 'field_magazine_thematic_target_id',
                      'table' => 'node__field_magazine_thematic',
                      'field' => 'field_magazine_thematic_target_id',
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
                          'operator_id' => 'field_magazine_thematic_target_id_op',
                          'label' => 'By thematic',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'field_magazine_thematic_target_id_op',
                          'identifier' => 'field_magazine_thematic_target_id',
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
                      'vid' => 'magazine_thematics',
                      'hierarchy' => false,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
                    ),
                  'node_year' =>
                    array (
                      'id' => 'node_year',
                      'table' => 'node_field_data',
                      'field' => 'node_year',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => '=',
                      'value' => '0',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'node_year_op',
                          'label' => 'Node year filter',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'node_year_op',
                          'identifier' => 'field_year_target_id',
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
                      'plugin_id' => 'node_year',
                    ),
                  'node_month' =>
                    array (
                      'id' => 'node_month',
                      'table' => 'node_field_data',
                      'field' => 'node_month',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => '=',
                      'value' => '01',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'node_month_op',
                          'label' => 'Node month filter',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'node_month_op',
                          'identifier' => 'field_month_target_id',
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
                      'plugin_id' => 'node_month',
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
          'title' => 'Magazine',
        ),
      'page_partners' =>
        array (
          'display_plugin' => 'page',
          'id' => 'page_partners',
          'display_title' => 'partners',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_partners',
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
                  'tid' =>
                    array (
                      'id' => 'tid',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_op',
                          'label' => 'By type',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_op',
                          'identifier' => 'field_types_target_id',
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
                      'vid' => 'partner_types',
                      'hierarchy' => false,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
                    ),
                  'tid_1' =>
                    array (
                      'id' => 'tid_1',
                      'table' => 'taxonomy_index',
                      'field' => 'tid',
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
                          'operator_id' => 'tid_1_op',
                          'label' => 'By region',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'tid_1_op',
                          'identifier' => 'field_regions_target_id',
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
                      'vid' => 'regions',
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
          'title' => 'Partners',
        ),
      'page_press' =>
        array (
          'display_plugin' => 'page',
          'id' => 'page_press',
          'display_title' => 'press',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'path' => 'subhome_press',
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
                          'press_kit' => 'press_kit',
                          'press_release' => 'press_release',
                        ),
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'type_op',
                          'label' => 'By type',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'type_op',
                          'identifier' => 'field_type_target_id',
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
                      'entity_field' => 'type',
                      'plugin_id' => 'bundle',
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
                  'node_year' =>
                    array (
                      'id' => 'node_year',
                      'table' => 'node_field_data',
                      'field' => 'node_year',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => '=',
                      'value' => '0',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'node_year_op',
                          'label' => 'By year',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'node_year_op',
                          'identifier' => 'field_year_target_id',
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
                      'plugin_id' => 'node_year',
                    ),
                  'node_month' =>
                    array (
                      'id' => 'node_month',
                      'table' => 'node_field_data',
                      'field' => 'node_month',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => '=',
                      'value' => '01',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'node_month_op',
                          'label' => 'By month',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'node_month_op',
                          'identifier' => 'field_month_target_id',
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
                      'plugin_id' => 'node_month',
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
              'use_ajax' => false,
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
          'title' => 'Press',
        ),
    ),
));

##On save
$config_group->save(TRUE);
