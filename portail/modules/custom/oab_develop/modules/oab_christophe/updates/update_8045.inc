<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.rss');
$config_group->setData(
  array (
    'uuid' => '1c70492b-758a-429c-bb05-a964bda16cb3',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.rss',
            1 => 'field.field.node.container.field_area',
            2 => 'field.field.node.container.field_blog',
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_meta_descriptif_court',
            16 => 'field.field.node.container.field_meta_titre',
            17 => 'field.field.node.container.field_metatags',
            18 => 'field.field.node.container.field_owner',
            19 => 'field.field.node.container.field_partner',
            20 => 'field.field.node.container.field_profile',
            21 => 'field.field.node.container.field_rendering_model',
            22 => 'field.field.node.container.field_section',
            23 => 'field.field.node.container.field_short_description',
            24 => 'field.field.node.container.field_solution',
            25 => 'field.field.node.container.field_start_date',
            26 => 'field.field.node.container.field_state',
            27 => 'field.field.node.container.field_subtitle',
            28 => 'field.field.node.container.field_topic',
            29 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'oab_text',
            1 => 'user',
          ),
      ),
    'id' => 'node.container.rss',
    'targetEntityType' => 'node',
    'bundle' => 'container',
    'mode' => 'rss',
    'content' =>
      array (
        'field_content_field' =>
          array (
            'weight' => 4,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'oab_text_default',
          ),
        'field_meta_title' =>
          array (
            'weight' => 13,
            'label' => 'above',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'text_default',
          ),
        'field_subtitle' =>
          array (
            'weight' => 0,
            'label' => 'hidden',
            'settings' =>
              array (
                'link_to_entity' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'string',
          ),
      ),
    'hidden' =>
      array (
        'field_area' => true,
        'field_blog' => true,
        'field_city' => true,
        'field_commentaire' => true,
        'field_commentaires' => true,
        'field_country' => true,
        'field_customer_story' => true,
        'field_display_title' => true,
        'field_document_type' => true,
        'field_end_date' => true,
        'field_file' => true,
        'field_image' => true,
        'field_industry' => true,
        'field_magazine' => true,
        'field_meta_descriptif_court' => true,
        'field_meta_titre' => true,
        'field_metatags' => true,
        'field_owner' => true,
        'field_partner' => true,
        'field_profile' => true,
        'field_rendering_model' => true,
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
        'publish_date' => true,
        'unpublish_date' => true,
      ),
  ));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.fluxs');
$config_group->setData(
  array(
    'uuid' => '969a38b9-8d4f-462e-bd15-57a0d4b1d0ab',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.rss',
            1 => 'node.type.container',
            2 => 'taxonomy.vocabulary.rendering_model',
          ),
        'content' =>
          array (
            0 => 'taxonomy_term:rendering_model:1e33350e-e1b0-4acc-a1e5-b770247fd020',
            1 => 'taxonomy_term:rendering_model:1e54f911-3e54-42fc-a795-b58e61ad795c',
            2 => 'taxonomy_term:rendering_model:4a88701f-1958-430e-bd40-401c50a1a0fa',
            3 => 'taxonomy_term:rendering_model:6835769b-8e97-4dc4-b544-f3aa1cdbb0a7',
            4 => 'taxonomy_term:rendering_model:c925c29b-6808-49ed-86bb-d1f1476581ac',
          ),
        'module' =>
          array (
            0 => 'node',
            1 => 'taxonomy',
            2 => 'user',
          ),
      ),
    'id' => 'fluxs',
    'label' => 'fluxs',
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
                    'type' => 'mini',
                    'options' =>
                      array (
                        'items_per_page' => 10,
                        'offset' => 0,
                        'id' => 0,
                        'total_pages' => NULL,
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
                        'tags' =>
                          array (
                            'previous' => '‹‹',
                            'next' => '››',
                          ),
                      ),
                  ),
                'style' =>
                  array (
                    'type' => 'default',
                    'options' =>
                      array (
                        'grouping' =>
                          array (
                          ),
                        'row_class' => '',
                        'default_row_class' => true,
                        'uses_fields' => false,
                      ),
                  ),
                'row' =>
                  array (
                    'type' => 'fields',
                    'options' =>
                      array (
                        'inline' =>
                          array (
                          ),
                        'separator' => '',
                        'hide_empty' => false,
                        'default_field_elements' => true,
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
                            847 => 847,
                            848 => 848,
                            4179 => 4179,
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
                    2 => 'url.query_args',
                    3 => 'user',
                    4 => 'user.node_grants:view',
                    5 => 'user.permissions',
                  ),
                'tags' =>
                  array (
                  ),
              ),
          ),
        'feed_presse' =>
          array (
            'display_plugin' => 'feed',
            'id' => 'feed_presse',
            'display_title' => 'Presse',
            'position' => 2,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'row' =>
                  array (
                    'type' => 'node_rss',
                    'options' =>
                      array (
                        'relationship' => 'none',
                        'view_mode' => 'rss',
                      ),
                  ),
                'display_description' => '',
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
                            4176 => 4176,
                            4174 => 4174,
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
                'defaults' =>
                  array (
                    'filters' => false,
                    'filter_groups' => false,
                  ),
                'filter_groups' =>
                  array (
                    'operator' => 'AND',
                    'groups' =>
                      array (
                        1 => 'AND',
                      ),
                  ),
                'path' => 'presse.xml',
                'pager' =>
                  array (
                    'type' => 'some',
                    'options' =>
                      array (
                        'items_per_page' => 100,
                        'offset' => 0,
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
                    2 => 'user',
                    3 => 'user.node_grants:view',
                    4 => 'user.permissions',
                  ),
                'tags' =>
                  array (
                  ),
              ),
          ),
        'feed_realtimes' =>
          array (
            'display_plugin' => 'feed',
            'id' => 'feed_realtimes',
            'display_title' => 'Realtimes',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'row' =>
                  array (
                    'type' => 'node_rss',
                    'options' =>
                      array (
                        'relationship' => 'none',
                        'view_mode' => 'rss',
                      ),
                  ),
                'path' => 'realtimes.xml',
                'pager' =>
                  array (
                    'type' => 'some',
                    'options' =>
                      array (
                        'items_per_page' => 100,
                        'offset' => 0,
                      ),
                  ),
                'display_description' => '',
              ),
            'cache_metadata' =>
              array (
                'max-age' => -1,
                'contexts' =>
                  array (
                    0 => 'languages:language_content',
                    1 => 'languages:language_interface',
                    2 => 'user',
                    3 => 'user.node_grants:view',
                    4 => 'user.permissions',
                  ),
                'tags' =>
                  array (
                  ),
              ),
          ),
      ),
  ));
$config_group->save(TRUE);