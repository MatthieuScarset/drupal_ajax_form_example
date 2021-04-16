<?php

use Drupal\node\Entity\NodeType;

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.contributor');
$config_group->setData(array(
  'uuid' => '9d0a2637-b58f-4e23-952a-609c8c9dc59f',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'contributor',
  'label' => 'contributeur',
  'weight' => 6,
  'is_admin' => NULL,
  'permissions' =>
    array (
      0 => 'access administration pages',
      1 => 'access browse_media_modal entity browser pages',
      2 => 'access browse_medias_iframe entity browser pages',
      3 => 'access browser_file_modal entity browser pages',
      4 => 'access content overview',
      5 => 'access files overview',
      6 => 'access in-place editing',
      7 => 'access media overview',
      8 => 'access shortcuts',
      9 => 'access toolbar',
      10 => 'access tour',
      11 => 'access user profiles',
      12 => 'access workbench',
      13 => 'administer media',
      14 => 'administer nodes',
      15 => 'delete own product content',
      16 => 'edit own blog_post content',
      17 => 'edit own country content',
      18 => 'edit own customer_story content',
      19 => 'edit own document content',
      20 => 'edit own full_html content',
      21 => 'edit own industry content',
      22 => 'edit own magazine content',
      23 => 'edit own office content',
      24 => 'edit own partner content',
      25 => 'edit own press_kit content',
      26 => 'edit own press_release content',
      27 => 'edit own profile content',
      28 => 'edit own region content',
      29 => 'edit own simple_page content',
      30 => 'edit own solution content',
      31 => 'edit own webform content',
      32 => 'use draft_draft transition',
      33 => 'use draft_needs_review transition',
      34 => 'use needs_review_draft transition',
      35 => 'use published_draft transition',
      36 => 'use published_published transition',
      37 => 'use text format full_html',
      38 => 'use unpublished_to_draft transition',
      39 => 'view full_html revisions',
      40 => 'view moderation states',
      41 => 'view own unpublished content',
      42 => 'view the administration theme',
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.content');
$config_group->setData(array(
  'uuid' => '1f1bf27f-51d4-4a57-b465-0e3c07f8447e',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
          1 => 'user',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => 'fUDNcSYKNw6cTMPsX3G9VhsUGov5yUe6_TBHbcnZHyo',
    ),
  'id' => 'content',
  'label' => 'Content',
  'module' => 'node',
  'description' => 'Find and manage content.',
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
                      'submit_button' => 'Filter',
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
                          'type' => 'type',
                          'name' => 'name',
                          'langcode' => 'langcode',
                          'moderation_state' => 'moderation_state',
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
                          'type' =>
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
                          'langcode' =>
                            array (
                              'sortable' => false,
                              'default_sort_order' => 'asc',
                              'align' => '',
                              'separator' => '',
                              'empty_column' => false,
                              'responsive' => '',
                            ),
                          'moderation_state' =>
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
                      'label' => 'Title',
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
                  'type' =>
                    array (
                      'id' => 'type',
                      'table' => 'node_field_data',
                      'field' => 'type',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Content type',
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
                  'name' =>
                    array (
                      'id' => 'name',
                      'table' => 'users_field_data',
                      'field' => 'name',
                      'relationship' => 'uid',
                      'label' => 'Author',
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
                      'plugin_id' => 'field',
                      'type' => 'user_name',
                      'entity_type' => 'user',
                      'entity_field' => 'name',
                    ),
                  'langcode' =>
                    array (
                      'id' => 'langcode',
                      'table' => 'node_field_data',
                      'field' => 'langcode',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Language',
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
                  'moderation_state' =>
                    array (
                      'id' => 'moderation_state',
                      'table' => 'node_field_data',
                      'field' => 'moderation_state',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'label' => 'Status',
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
                      'entity_field' => 'moderation_state',
                      'plugin_id' => 'field',
                    ),
                  'changed' =>
                    array (
                      'id' => 'changed',
                      'table' => 'node_field_data',
                      'field' => 'changed',
                      'label' => 'Updated',
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
                      'type' => 'timestamp',
                      'settings' =>
                        array (
                          'date_format' => 'short',
                          'custom_date_format' => '',
                          'timezone' => '',
                        ),
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
                      'label' => 'Operations',
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
                  'status_extra' =>
                    array (
                      'id' => 'status_extra',
                      'table' => 'node_field_data',
                      'field' => 'status_extra',
                      'operator' => '=',
                      'value' => false,
                      'plugin_id' => 'node_status',
                      'group' => 1,
                      'entity_type' => 'node',
                    ),
                  'moderation_state' =>
                    array (
                      'id' => 'moderation_state',
                      'table' => 'node_field_data',
                      'field' => 'moderation_state',
                      'relationship' => 'none',
                      'group_type' => 'group',
                      'admin_label' => '',
                      'operator' => '=',
                      'value' => '',
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'moderation_state_op',
                          'label' => 'Status',
                          'description' => '',
                          'use_operator' => false,
                          'operator' => 'moderation_state_op',
                          'identifier' => 'moderation_state',
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
                      'is_grouped' => true,
                      'group_info' =>
                        array (
                          'label' => 'État de modération',
                          'description' => '',
                          'identifier' => 'moderation_state',
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
                                  'title' => 'Archived',
                                  'operator' => '=',
                                  'value' => 'archived',
                                ),
                              2 =>
                                array (
                                  'title' => 'Draft',
                                  'operator' => '=',
                                  'value' => 'draft',
                                ),
                              3 =>
                                array (
                                  'title' => 'Dépublié',
                                  'operator' => '=',
                                  'value' => 'unpublished',
                                ),
                              4 =>
                                array (
                                  'title' => 'Needs Review',
                                  'operator' => '=',
                                  'value' => 'needs_review',
                                ),
                              5 =>
                                array (
                                  'title' => 'Published',
                                  'operator' => '=',
                                  'value' => 'published',
                                ),
                              6 =>
                                array (
                                  'title' => 'Empty',
                                  'operator' => 'empty',
                                  'value' => '',
                                ),
                            ),
                        ),
                      'entity_type' => 'node',
                      'entity_field' => 'moderation_state',
                      'plugin_id' => 'string',
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
                          'label' => 'Content type',
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
                          'label' => 'Title',
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
                        ),
                      'group' => 1,
                      'exposed' => true,
                      'expose' =>
                        array (
                          'operator_id' => 'langcode_op',
                          'label' => 'Language',
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
                      'plugin_id' => 'language',
                      'entity_type' => 'node',
                      'entity_field' => 'langcode',
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
                ),
            ),
        ),
      'page_1' =>
        array (
          'display_options' =>
            array (
              'path' => 'admin/content/node',
              'menu' =>
                array (
                  'type' => 'default tab',
                  'title' => 'Content',
                  'description' => '',
                  'menu_name' => 'admin',
                  'weight' => -10,
                  'context' => '',
                ),
              'tab_options' =>
                array (
                  'type' => 'normal',
                  'title' => 'Content',
                  'description' => 'Find and manage content',
                  'menu_name' => 'admin',
                  'weight' => -10,
                ),
              'display_extenders' =>
                array (
                ),
            ),
          'display_plugin' => 'page',
          'display_title' => 'Page',
          'id' => 'page_1',
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
                ),
            ),
        ),
      'page_2' =>
        array (
          'display_options' =>
            array (
              'path' => 'admin/content/my-content',
              'menu' =>
                array (
                  'type' => 'tab',
                  'title' => 'My content',
                  'description' => '',
                  'expanded' => false,
                  'parent' => 'system.admin_content',
                  'weight' => -10,
                  'context' => '0',
                  'menu_name' => 'admin',
                ),
              'tab_options' =>
                array (
                  'type' => 'normal',
                  'title' => 'Content',
                  'description' => 'Find and manage content',
                  'weight' => -10,
                ),
              'display_extenders' =>
                array (
                ),
              'display_description' => '',
              'arguments' =>
                array (
                  'uid' =>
                    array (
                      'id' => 'uid',
                      'table' => 'node_field_data',
                      'field' => 'uid',
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
                      'default_argument_type' => 'current_user',
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
                      'entity_field' => 'uid',
                      'plugin_id' => 'numeric',
                    ),
                ),
              'defaults' =>
                array (
                  'arguments' => false,
                  'title' => false,
                ),
              'title' => 'My content',
            ),
          'display_plugin' => 'page',
          'display_title' => 'My content',
          'id' => 'page_2',
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
                ),
            ),
        ),
    ),
));
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('views.view.content', array (
  'label' => 'Contenu',
  'description' => 'Trouver et gérer le contenu.',
  'display' =>
    array (
      'default' =>
        array (
          'display_options' =>
            array (
              'exposed_form' =>
                array (
                  'options' =>
                    array (
                      'submit_button' => 'Filtrer',
                      'reset_button_label' => 'Réinitialiser',
                      'exposed_sorts_label' => 'Trier par',
                    ),
                ),
              'pager' =>
                array (
                  'options' =>
                    array (
                      'tags' =>
                        array (
                          'previous' => '‹ Précédent',
                          'next' => 'Suivant ›',
                          'first' => '« Premier',
                          'last' => 'Dernier »',
                        ),
                    ),
                ),
              'fields' =>
                array (
                  'title' =>
                    array (
                      'label' => 'Titre',
                    ),
                  'type' =>
                    array (
                      'label' => 'Type de contenu',
                    ),
                  'name' =>
                    array (
                      'label' => 'Auteur',
                    ),
                  'changed' =>
                    array (
                      'label' => 'Mis à jour',
                    ),
                  'operations' =>
                    array (
                      'label' => 'Opérations',
                    ),
                ),
              'filters' =>
                array (
                  'title' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Titre',
                        ),
                    ),
                  'type' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Type de contenu',
                        ),
                    ),
                  'langcode' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Langue',
                        ),
                    ),
                ),
              'title' => 'Contenu',
              'empty' =>
                array (
                  'area_text_custom' =>
                    array (
                      'content' => 'Pas de contenu disponible',
                    ),
                ),
            ),
          'display_title' => 'Maître',
        ),
      'page_1' =>
        array (
          'display_options' =>
            array (
              'menu' =>
                array (
                  'title' => 'Contenu',
                ),
              'tab_options' =>
                array (
                  'title' => 'Contenu',
                  'description' => 'Trouver et gérer le contenu',
                ),
            ),
        ),
      'page_2' =>
        array (
          'display_title' => 'Mon contenu',
          'display_options' =>
            array (
              'title' => 'Mon contenu',
              'menu' =>
                array (
                  'title' => 'Mon contenu',
                ),
            ),
        ),
    ),
));

// ajout du champ "authored by" à tous les types de contenu
$content_types = NodeType::loadMultiple();
if (is_array($content_types) && !empty($content_types)) {
  foreach ($content_types AS $type_name => $type_object) {
    $config_factory = \Drupal::configFactory();
    $config_string = "core.entity_form_display.node." . $type_name . ".default";
    $config_group = $config_factory->getEditable($config_string);

    $fieldAuthor = $config_group->get('content.uid');

    if (is_null($fieldAuthor)) {
      $config_group->set('content.uid', array(
        'type' => 'entity_reference_autocomplete',
        'weight' => 1,
        'region' => 'content',
        'settings' =>
          array(
            'match_operator' => 'CONTAINS',
            'size' => 60,
            'placeholder' => '',
          ),
        'third_party_settings' =>
          array(),
      ));
      $config_group->save(true);
    }
  }
}