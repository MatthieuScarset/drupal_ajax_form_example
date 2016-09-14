<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('entity_browser.browser.browse_medias_iframe');
$config_group->setData(array(
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
              'view_display' => 'entity_browser_1',
            ),
          'uuid' => '836df8ab-541a-4322-8092-5e4da51b50d6',
          'weight' => -10,
          'label' => 'Media listing',
          'id' => 'view',
        ),
    ),
  'submit_text' => 'Select',
));
$config_group->save(TRUE);



$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('entity_browser.browser.browse_media_modal');
$config_group->setData(array(
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
              'view_display' => 'entity_browser_1',
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
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.medias_entity_browser');
$config_group->setData(array(
  'uuid' => '409ba211-d01f-4fee-9700-d48c8b85ab6e',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.media.field_image',
          1 => 'image.style.thumbnail',
          2 => 'media_entity.bundle.image',
          3 => 'taxonomy.vocabulary.media_tags',
          4 => 'taxonomy.vocabulary.media_thematic',
        ),
      'module' =>
        array (
          0 => 'entity_browser',
          1 => 'image',
          2 => 'media_entity',
          3 => 'taxonomy',
          4 => 'user',
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
                      'entity_type' => 'media',
                      'entity_field' => 'media',
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
      'entity_browser_1' =>
        array (
          'display_plugin' => 'entity_browser',
          'id' => 'entity_browser_1',
          'display_title' => 'Entity browser',
          'position' => 1,
          'display_options' =>
            array (
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
    ),
));
$config_group->save(TRUE);