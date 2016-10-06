<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('views.view.medias_entity_browser');
$config->setData(array (
  'uuid' => '409ba211-d01f-4fee-9700-d48c8b85ab6e',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.media.field_image',
          1 => 'image.style.thumbnail',
          2 => 'media_entity.bundle.file',
          3 => 'media_entity.bundle.image',
          4 => 'taxonomy.vocabulary.media_tags',
          5 => 'taxonomy.vocabulary.media_thematic',
        ),
      'module' =>
        array (
          0 => 'entity_browser',
          1 => 'file',
          2 => 'image',
          3 => 'media_entity',
          4 => 'taxonomy',
          5 => 'user',
        ),
    ),
  'id' => 'medias_entity_browser',
  'label' => 'Medias entity browser',
  'module' => 'views',
  'description' => '',
  'tag' => '',
  'base_table' => 'media_field_data',
  'base_field' => 'mid',
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
                      'perm' => 'view media',
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
                      'items_per_page' => 24,
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
                  'type' => 'grid',
                  'options' =>
                    array (
                      'grouping' =>
                        array (
                        ),
                      'columns' => 6,
                      'automatic_width' => false,
                      'alignment' => 'horizontal',
                      'col_class_default' => true,
                      'col_class_custom' => '',
                      'row_class_default' => true,
                      'row_class_custom' => '',
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
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'media_field_data',
                      'field' => 'name',
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
                      'element_label_colon' => false,
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
                          'link_to_entity' => false,
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
                      'entity_type' => 'media',
                      'entity_field' => 'media',
                      'plugin_id' => 'field',
                    ),
                  'entity_browser_select' =>
                    array (
                      'id' => 'entity_browser_select',
                      'table' => 'media_field_data',
                      'field' => 'entity_browser_select',
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
                      'entity_type' => 'media',
                      'plugin_id' => 'entity_browser_select',
                    ),
                  'field_image' =>
                    array (
                      'id' => 'field_image',
                      'table' => 'media__field_image',
                      'field' => 'field_image',
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
                      'type' => 'image',
                      'settings' =>
                        array (
                          'image_style' => 'thumbnail',
                          'image_link' => '',
                        ),
                      'group_column' => '',
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
              'filters' =>
                array (
                  'bundle' =>
                    array (
                      'id' => 'bundle',
                      'table' => 'media_field_data',
                      'field' => 'bundle',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => 'in',
                      'value' =>
                        array (
                          'image' => 'image',
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
                      'entity_type' => 'media',
                      'entity_field' => 'bundle',
                      'plugin_id' => 'bundle',
                    ),
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'media_field_data',
                      'field' => 'name',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => 'contains',
                      'value' => '',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'name_op',
                          'label' => 'Media name',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'name_op',
                          'identifier' => 'name',
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
                      'entity_type' => 'media',
                      'entity_field' => 'name',
                      'plugin_id' => 'string',
                    ),
                  'field_tags_target_id' =>
                    array (
                      'id' => 'field_tags_target_id',
                      'table' => 'media__field_tags',
                      'field' => 'field_tags_target_id',
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
                          'operator_id' => 'field_tags_target_id_op',
                          'label' => 'tags',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'field_tags_target_id_op',
                          'identifier' => 'field_tags_target_id',
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
                      'type' => 'textfield',
                      'limit' => true,
                      'vid' => 'media_tags',
                      'hierarchy' => false,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
                    ),
                  'field_thematic_target_id' =>
                    array (
                      'id' => 'field_thematic_target_id',
                      'table' => 'media__field_thematic',
                      'field' => 'field_thematic_target_id',
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
                          'operator_id' => 'field_thematic_target_id_op',
                          'label' => 'thematic',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'field_thematic_target_id_op',
                          'identifier' => 'field_thematic_target_id',
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
                      'vid' => 'media_thematic',
                      'hierarchy' => true,
                      'error_message' => true,
                      'plugin_id' => 'taxonomy_index_tid',
                    ),
                ),
              'sorts' =>
                array (
                  'changed' =>
                    array (
                      'id' => 'changed',
                      'table' => 'media_field_data',
                      'field' => 'changed',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'order' => 'DESC',
                      'exposed' => false,
                      'expose' =>
                        array (
                          'label' => '',
                        ),
                      'granularity' => 'second',
                      'entity_type' => 'media',
                      'entity_field' => 'changed',
                      'plugin_id' => 'date',
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
                  2 => 'url',
                  3 => 'url.query_args',
                  4 => 'user',
                  5 => 'user.permissions',
                ),
              'tags' =>
                array (
                  0 => 'config:field.storage.media.field_image',
                ),
            ),
        ),
      'entity_browser_file' =>
        array (
          'display_plugin' => 'entity_browser',
          'id' => 'entity_browser_file',
          'display_title' => 'Entity browser file',
          'position' => 2,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'display_description' => '',
              'fields' =>
                array (
                  'entity_browser_select' =>
                    array (
                      'id' => 'entity_browser_select',
                      'table' => 'media_field_data',
                      'field' => 'entity_browser_select',
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
                      'entity_type' => 'media',
                      'plugin_id' => 'entity_browser_select',
                    ),
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'media_field_data',
                      'field' => 'name',
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
                      'element_label_colon' => false,
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
                          'link_to_entity' => false,
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
                      'entity_type' => 'media',
                      'entity_field' => 'media',
                      'plugin_id' => 'field',
                    ),
                  'filesize' =>
                    array (
                      'id' => 'filesize',
                      'table' => 'file_managed',
                      'field' => 'filesize',
                      'relationship' => 'field_file_target_id',
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
                      'click_sort_column' => 'value',
                      'type' => 'file_size',
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
                      'entity_type' => 'file',
                      'entity_field' => 'filesize',
                      'plugin_id' => 'field',
                    ),
                ),
              'defaults' =>
                array (
                  'fields' => false,
                  'filters' => false,
                  'filter_groups' => false,
                  'relationships' => false,
                ),
              'filters' =>
                array (
                  'bundle' =>
                    array (
                      'id' => 'bundle',
                      'table' => 'media_field_data',
                      'field' => 'bundle',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => 'in',
                      'value' =>
                        array (
                          'file' => 'file',
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
                      'entity_type' => 'media',
                      'entity_field' => 'bundle',
                      'plugin_id' => 'bundle',
                    ),
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'media_field_data',
                      'field' => 'name',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => 'contains',
                      'value' => '',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'name_op',
                          'label' => 'Media name',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'name_op',
                          'identifier' => 'name',
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
                      'entity_type' => 'media',
                      'entity_field' => 'name',
                      'plugin_id' => 'string',
                    ),
                  'filemime' =>
                    array (
                      'id' => 'filemime',
                      'table' => 'file_managed',
                      'field' => 'filemime',
                      'relationship' => 'field_file_target_id',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => 'contains',
                      'value' => '',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'filemime_op',
                          'label' => 'File MIME type',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'filemime_op',
                          'identifier' => 'filemime',
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
                      'entity_type' => 'file',
                      'entity_field' => 'filemime',
                      'plugin_id' => 'string',
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
              'relationships' =>
                array (
                  'field_file_target_id' =>
                    array (
                      'id' => 'field_file_target_id',
                      'table' => 'media__field_file',
                      'field' => 'field_file_target_id',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => 'fichier de field_file',
                      'required' => true,
                      'plugin_id' => 'standard',
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
                  3 => 'url.query_args',
                  4 => 'user.permissions',
                ),
              'tags' =>
                array (
                ),
            ),
        ),
      'entity_browser_media' =>
        array (
          'display_plugin' => 'entity_browser',
          'id' => 'entity_browser_media',
          'display_title' => 'Entity browser',
          'position' => 1,
          'display_options' =>
            array (
              'display_extenders' =>
                array (
                ),
              'fields' =>
                array (
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'media_field_data',
                      'field' => 'name',
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
                      'element_label_colon' => false,
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
                          'link_to_entity' => false,
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
                      'entity_type' => 'media',
                      'entity_field' => 'media',
                      'plugin_id' => 'field',
                    ),
                  'entity_browser_select' =>
                    array (
                      'id' => 'entity_browser_select',
                      'table' => 'media_field_data',
                      'field' => 'entity_browser_select',
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
                      'entity_type' => 'media',
                      'plugin_id' => 'entity_browser_select',
                    ),
                  'field_image' =>
                    array (
                      'id' => 'field_image',
                      'table' => 'media__field_image',
                      'field' => 'field_image',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => '',
                      'exclude' => false,
                      'alter' =>
                        array (
                          'alter_text' => false,
                          'text' => '<img src="{{ field_image.uri }}" title="{{ name }}" />',
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
                      'type' => 'image',
                      'settings' =>
                        array (
                          'image_style' => 'thumbnail',
                          'image_link' => '',
                        ),
                      'group_column' => '',
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
              'defaults' =>
                array (
                  'fields' => false,
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
                  5 => 'user.permissions',
                ),
              'tags' =>
                array (
                  0 => 'config:field.storage.media.field_image',
                ),
            ),
        ),
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('entity_browser.browser.browse_media_modal');
$config->setData(array (
  'uuid' => 'b6c4c146-7bfc-4352-9208-8d0f91e00aae',
  'langcode' => 'und',
  'status' => true,
  'dependencies' =>
    array (
      'enforced' =>
        array (
          'module' =>
            array (
              0 => 'oab_media_browser',
            ),
        ),
      'module' =>
        array (
          0 => 'entity_browser_entity_form',
          1 => 'views',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => 'mdUNatZ7S-c7XVDJ-ZivN7sKeRi7A4l9iN263Psv7GU',
    ),
  'name' => 'browse_media_modal',
  'label' => 'Browser modal for medias',
  'display' => 'modal',
  'display_configuration' =>
    array (
      'widget_ids' =>
        array (
          '735d146c-a4b2-4327-a057-d109e0905e06' => 'Upload media',
          'a4ad947c-9669-497c-9988-24351955a02f' => 'Medias listing',
        ),
      'width' => '',
      'height' => '700',
      'link_text' => 'Select medias',
      'auto_open' => true,
    ),
  'selection_display' => 'no_display',
  'selection_display_configuration' =>
    array (
      'view' => 'medias_entity_browser',
      'view_display' => 'entity_browser_1',
    ),
  'widget_selector' => 'tabs',
  'widget_selector_configuration' =>
    array (
    ),
  'widgets' =>
    array (
      'a4ad947c-9669-497c-9988-24351955a02f' =>
        array (
          'settings' =>
            array (
              'view' => 'medias_entity_browser',
              'view_display' => 'entity_browser_media',
            ),
          'uuid' => 'a4ad947c-9669-497c-9988-24351955a02f',
          'weight' => -10,
          'label' => 'Medias listing',
          'id' => 'view',
        ),
      '735d146c-a4b2-4327-a057-d109e0905e06' =>
        array (
          'settings' =>
            array (
              'entity_type' => 'media',
              'bundle' => 'image',
            ),
          'uuid' => '735d146c-a4b2-4327-a057-d109e0905e06',
          'weight' => -9,
          'label' => 'Upload medias',
          'id' => 'entity_form',
        ),
    ),
  'submit_text' => 'Select',
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('entity_browser.browser.browse_medias_iframe');
$config->setData(array (
  'uuid' => 'e6d05d29-5b9e-4fa6-ba00-a815684d9bdb',
  'langcode' => 'und',
  'status' => true,
  'dependencies' =>
    array (
      'enforced' =>
        array (
          'module' =>
            array (
              0 => 'oab_media_browser',
            ),
        ),
      'module' =>
        array (
          0 => 'entity_browser_entity_form',
          1 => 'views',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => 'Ue8A-OJls6HvSBav2bfwtUwPJLkMT8WjeLrW6DgU-9U',
    ),
  'name' => 'browse_medias_iframe',
  'label' => 'Browser iframe for medias',
  'display' => 'iframe',
  'display_configuration' =>
    array (
      'widget_ids' =>
        array (
          '735d146c-a4b2-4327-a057-d109e0905e06' => 'Upload media',
          'a4ad947c-9669-497c-9988-24351955a02f' => 'Medias listing',
        ),
      'width' => '1150',
      'height' => '700',
      'link_text' => 'Select medias',
      'auto_open' => true,
      'path' => '',
    ),
  'selection_display' => 'no_display',
  'selection_display_configuration' =>
    array (
      'view' => 'medias_entity_browser',
      'view_display' => 'entity_browser_1',
    ),
  'widget_selector' => 'tabs',
  'widget_selector_configuration' =>
    array (
    ),
  'widgets' =>
    array (
      '735d146c-a4b2-4327-a057-d109e0905e06' =>
        array (
          'settings' =>
            array (
              'entity_type' => 'media',
              'bundle' => 'image',
            ),
          'uuid' => '735d146c-a4b2-4327-a057-d109e0905e06',
          'weight' => -9,
          'label' => 'Upload media',
          'id' => 'entity_form',
        ),
      '836df8ab-541a-4322-8092-5e4da51b50d6' =>
        array (
          'settings' =>
            array (
              'view' => 'medias_entity_browser',
              'view_display' => 'entity_browser_media',
            ),
          'uuid' => '836df8ab-541a-4322-8092-5e4da51b50d6',
          'weight' => -10,
          'label' => 'Media listing',
          'id' => 'view',
        ),
    ),
  'submit_text' => 'Select',
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('entity_browser.browser.browser_file_modal');
$config->setData(array (
  'uuid' => '2a18903d-a470-460c-8baf-9ca029eabf47',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'entity_browser_entity_form',
          1 => 'views',
        ),
    ),
  'name' => 'browser_file_modal',
  'label' => 'Browser modal for files',
  'display' => 'modal',
  'display_configuration' =>
    array (
      'width' => '',
      'height' => '700',
      'link_text' => 'Select files',
    ),
  'selection_display' => 'no_display',
  'selection_display_configuration' =>
    array (
    ),
  'widget_selector' => 'tabs',
  'widget_selector_configuration' =>
    array (
    ),
  'widgets' =>
    array (
      '04fc7b85-5cb1-4a8f-bb2b-eca34e603361' =>
        array (
          'settings' =>
            array (
              'entity_type' => 'media',
              'bundle' => 'file',
            ),
          'uuid' => '04fc7b85-5cb1-4a8f-bb2b-eca34e603361',
          'weight' => -9,
          'label' => 'Upload files',
          'id' => 'entity_form',
        ),
      'd2fd7d63-4882-42b7-ac45-79ea97fbc1b3' =>
        array (
          'settings' =>
            array (
              'view' => 'medias_entity_browser',
              'view_display' => 'entity_browser_file',
            ),
          'uuid' => 'd2fd7d63-4882-42b7-ac45-79ea97fbc1b3',
          'weight' => -10,
          'label' => 'Files listing',
          'id' => 'view',
        ),
    ),
  'submit_text' => 'Select',
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.node.container.default');
$config->setData(array (
  'uuid' => NULL,
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.container.field_area',
          1 => 'field.field.node.container.field_blog',
          2 => 'field.field.node.container.field_commentaire',
          3 => 'field.field.node.container.field_content_field',
          4 => 'field.field.node.container.field_customer_story',
          5 => 'field.field.node.container.field_display_title',
          6 => 'field.field.node.container.field_document_type',
          7 => 'field.field.node.container.field_end_date',
          8 => 'field.field.node.container.field_file',
          9 => 'field.field.node.container.field_image',
          10 => 'field.field.node.container.field_industry',
          11 => 'field.field.node.container.field_magazine',
          12 => 'field.field.node.container.field_owner',
          13 => 'field.field.node.container.field_partner',
          14 => 'field.field.node.container.field_profile',
          15 => 'field.field.node.container.field_rendering_model',
          16 => 'field.field.node.container.field_short_description',
          17 => 'field.field.node.container.field_solution',
          18 => 'field.field.node.container.field_start_date',
          19 => 'field.field.node.container.field_state',
          20 => 'field.field.node.container.field_subtitle',
          21 => 'field.field.node.container.field_topic',
          22 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'comment',
          1 => 'datetime',
          2 => 'entity_browser',
          3 => 'field_group',
          4 => 'oab_text',
          5 => 'path',
          6 => 'workflowfield',
        ),
    ),
  'third_party_settings' =>
    array (
      'field_group' =>
        array (
          'group_general' =>
            array (
              'children' =>
                array (
                  0 => 'field_rendering_model',
                  1 => 'langcode',
                  2 => 'title',
                  3 => 'field_display_title',
                  4 => 'field_subtitle',
                  5 => 'field_short_description',
                  6 => 'field_profile',
                  7 => 'field_owner',
                  8 => 'group_date_fieldset',
                  9 => 'path',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 1,
              'label' => 'General',
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'label' => 'General',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                  'id' => '',
                  'classes' => '',
                ),
            ),
          'group_taxonomie' =>
            array (
              'children' =>
                array (
                  0 => 'field_blog',
                  1 => 'field_magazine',
                  2 => 'field_customer_story',
                  3 => 'field_solution',
                  4 => 'field_area',
                  5 => 'field_partner',
                  6 => 'field_industry',
                  7 => 'field_document_type',
                  8 => 'field_topic',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 2,
              'label' => 'Taxonomy',
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'label' => 'Taxonomy',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                  'id' => '',
                  'classes' => '',
                ),
            ),
          'group_medias' =>
            array (
              'children' =>
                array (
                  0 => 'field_image',
                  1 => 'field_file',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 3,
              'label' => 'Medias',
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'label' => 'Medias',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                  'id' => '',
                  'classes' => '',
                ),
            ),
          'group_contenu' =>
            array (
              'children' =>
                array (
                  0 => 'field_content_field',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 4,
              'label' => 'Content',
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'label' => 'Content',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                  'id' => '',
                  'classes' => '',
                ),
            ),
          'group_workflow' =>
            array (
              'children' =>
                array (
                  0 => 'field_state',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 5,
              'label' => 'Workflow',
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'description' => '',
                  'classes' => '',
                  'id' => '',
                  'required_fields' => true,
                  'open' => false,
                  'formatter' => 'closed',
                  'direction' => 'vertical',
                ),
            ),
          'group_onglets' =>
            array (
              'children' =>
                array (
                  0 => 'group_general',
                  1 => 'group_taxonomie',
                  2 => 'group_medias',
                  3 => 'group_contenu',
                  4 => 'group_workflow',
                ),
              'parent_name' => '',
              'weight' => 0,
              'label' => 'Onglets',
              'format_type' => 'tabs',
              'format_settings' =>
                array (
                  'label' => 'Onglets',
                  'direction' => 'horizontal',
                  'id' => '',
                  'classes' => '',
                ),
            ),
          'group_date_fieldset' =>
            array (
              'children' =>
                array (
                  0 => 'field_start_date',
                  1 => 'field_end_date',
                ),
              'parent_name' => 'group_general',
              'weight' => 9,
              'label' => 'Content worthy period',
              'format_type' => 'fieldset',
              'format_settings' =>
                array (
                  'description' => '',
                  'classes' => '',
                  'id' => '',
                  'required_fields' => true,
                ),
            ),
        ),
    ),
  'id' => 'node.container.default',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'default',
  'content' =>
    array (
      'field_area' =>
        array (
          'weight' => 5,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_blog' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_blogger' =>
        array (
          'weight' => 27,
          'settings' =>
            array (
              'match_operator' => 'CONTAINS',
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_autocomplete',
        ),
      'field_commentaire' =>
        array (
          'weight' => 26,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'comment_default',
        ),
      'field_content_field' =>
        array (
          'weight' => 3,
          'settings' =>
            array (
              'rows' => '9',
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_textfield',
        ),
      'field_customer_story' =>
        array (
          'weight' => 3,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_display_title' =>
        array (
          'type' => 'boolean_checkbox',
          'weight' => 4,
          'settings' =>
            array (
              'display_label' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_document_type' =>
        array (
          'weight' => 8,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_end_date' =>
        array (
          'weight' => 7,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
        ),
      'field_file' =>
        array (
          'type' => 'entity_browser_entity_reference',
          'weight' => 12,
          'settings' =>
            array (
              'entity_browser' => 'browser_file_modal',
              'field_widget_display' => 'rendered_entity',
              'field_widget_edit' => true,
              'field_widget_remove' => true,
              'field_widget_display_settings' =>
                array (
                  'view_mode' => 'teaser',
                ),
              'open' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_image' =>
        array (
          'weight' => 11,
          'settings' =>
            array (
              'entity_browser' => 'browse_media_modal',
              'field_widget_display' => 'rendered_entity',
              'field_widget_edit' => true,
              'field_widget_remove' => true,
              'field_widget_display_settings' =>
                array (
                  'view_mode' => 'teaser',
                ),
              'open' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_browser_entity_reference',
        ),
      'field_industry' =>
        array (
          'weight' => 7,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_magazine' =>
        array (
          'weight' => 2,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_owner' =>
        array (
          'weight' => 8,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_partner' =>
        array (
          'weight' => 6,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_profile' =>
        array (
          'weight' => 7,
          'settings' =>
            array (
              'match_operator' => 'CONTAINS',
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_autocomplete',
        ),
      'field_rendering_model' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_short_description' =>
        array (
          'weight' => 6,
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textarea',
        ),
      'field_solution' =>
        array (
          'weight' => 4,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'field_start_date' =>
        array (
          'weight' => 6,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
        ),
      'field_state' =>
        array (
          'weight' => 5,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'workflow_default',
        ),
      'field_subtitle' =>
        array (
          'weight' => 5,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_topic' =>
        array (
          'weight' => 9,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
        ),
      'langcode' =>
        array (
          'type' => 'language_select',
          'weight' => 2,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'path' =>
        array (
          'type' => 'path',
          'weight' => 10,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'title' =>
        array (
          'type' => 'string_textfield',
          'weight' => 3,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'promote' => true,
      'sticky' => true,
      'uid' => true,
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.media.file.default');
$config->setData(array (
  'uuid' => 'f6fb4a96-2bee-4d6c-807c-fa20f64f003d',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.media.file.field_file',
          1 => 'media_entity.bundle.file',
        ),
      'module' =>
        array (
          0 => 'file',
        ),
    ),
  'id' => 'media.file.default',
  'targetEntityType' => 'media',
  'bundle' => 'file',
  'mode' => 'default',
  'content' =>
    array (
      'field_file' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
              'progress_indicator' => 'throbber',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'file_generic',
        ),
      'name' =>
        array (
          'type' => 'string_textfield',
          'weight' => 0,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'langcode' => true,
      'uid' => true,
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.media.image.teaser');
$config->setData(array (
  'uuid' => NULL,
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.media.teaser',
          1 => 'field.field.media.image.field_image',
          2 => 'field.field.media.image.field_tags',
          3 => 'field.field.media.image.field_thematic',
          4 => 'image.style.medium',
          5 => 'media_entity.bundle.image',
        ),
      'module' =>
        array (
          0 => 'image',
        ),
    ),
  'id' => 'media.image.teaser',
  'targetEntityType' => 'media',
  'bundle' => 'image',
  'mode' => 'teaser',
  'content' =>
    array (
      'field_image' =>
        array (
          'type' => 'image',
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'image_style' => 'medium',
              'image_link' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'field_tags' => true,
      'field_thematic' => true,
      'langcode' => true,
      'name' => true,
      'thumbnail' => true,
      'uid' => true,
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.press_release');
$config->setData(array (
  'uuid' => '1530fbb7-f0fa-4249-b9f4-ffda456972dd',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.press_release',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.press_release',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'press_release',
  'content' =>
    array (
      'field_area' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_content_field' =>
        array (
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_file' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'default',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_subtitle' =>
        array (
          'weight' => 1,
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
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_image' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_profile' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);
