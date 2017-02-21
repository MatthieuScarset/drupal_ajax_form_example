<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.full_html');
$config_group->setData(array(
  'uuid' => 'd725e214-2c7a-4ea2-81c7-26a6b2e23fc9',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'menu_ui',
          1 => 'workbench_access',
          2 => 'workbench_moderation',
        ),
    ),
  'third_party_settings' =>
    array (
      'menu_ui' =>
        array (
          'available_menus' =>
            array (
            ),
          'parent' => '',
        ),
      'workbench_access' =>
        array (
          'workbench_access_status' => false,
        ),
      'workbench_moderation' =>
        array (
          'enabled' => true,
          'allowed_moderation_states' =>
            array (
              0 => 'published',
              1 => 'archived',
              2 => 'draft',
              3 => 'needs_review',
              4 => 'unpublished',
            ),
          'default_moderation_state' => 'draft',
        ),
    ),
  'name' => 'full html',
  'type' => 'full_html',
  'description' => '',
  'help' => '',
  'new_revision' => true,
  'preview_mode' => 1,
  'display_submitted' => false,
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.node.full_html');
$config_group->setData(array(
  'uuid' => 'b900b1a8-1156-4f45-b445-aed8a6449eed',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'content_translation',
        ),
    ),
  'third_party_settings' =>
    array (
      'content_translation' =>
        array (
          'enabled' => false,
        ),
    ),
  'id' => 'node.full_html',
  'target_entity_type_id' => 'node',
  'target_bundle' => 'full_html',
  'default_langcode' => 'site_default',
  'language_alterable' => true,
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('simplify.content_type.full_html');
$config_group->setData(array(
  'simplify_nodes' =>
    array (
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_content');
$config_group->setData(array(
  'uuid' => '2dd2f252-e2e1-4a63-9c35-43b792e5340c',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_content',
          1 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  'id' => 'node.full_html.field_content',
  'field_name' => 'field_content',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Content',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'text_long',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_display_title');
$config_group->setData(array(
  'uuid' => '36f5493d-1dc8-467a-8c1f-7df1b3a51fd6',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_display_title',
          1 => 'node.type.full_html',
        ),
    ),
  'id' => 'node.full_html.field_display_title',
  'field_name' => 'field_display_title',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Display title',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
      0 =>
        array (
          'value' => 0,
        ),
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
      'on_label' => 'On',
      'off_label' => 'Off',
    ),
  'field_type' => 'boolean',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_end_date');
$config_group->setData(array(
  'uuid' => '693540fc-eaa6-423b-ada2-3be48e6c4af2',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_end_date',
          1 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'datetime',
        ),
    ),
  'id' => 'node.full_html.field_end_date',
  'field_name' => 'field_end_date',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'End date',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'datetime',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_metatags');
$config_group->setData(array(
  'uuid' => '96bdecf5-d457-4164-bf39-8bae0e36dd3f',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_metatags',
          1 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'metatag',
        ),
    ),
  'id' => 'node.full_html.field_metatags',
  'field_name' => 'field_metatags',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Metatags',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
      0 =>
        array (
          'value' => 'a:0:{}',
        ),
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'metatag',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_meta_description');
$config_group->setData(array(
  'uuid' => 'a503c541-3890-4a0b-9c1b-2dc83cab78b4',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_meta_description',
          1 => 'node.type.full_html',
        ),
    ),
  'id' => 'node.full_html.field_meta_description',
  'field_name' => 'field_meta_description',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Meta description',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'string',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_meta_title');
$config_group->setData(array(
  'uuid' => 'bf6060f7-f8cf-4f22-9263-f98f3856293f',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_meta_title',
          1 => 'node.type.full_html',
        ),
    ),
  'id' => 'node.full_html.field_meta_title',
  'field_name' => 'field_meta_title',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Meta title',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'string',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_start_date');
$config_group->setData(array(
  'uuid' => '11f421e0-fd76-49e1-9643-cfac800e780a',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.storage.node.field_start_date',
          1 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'datetime',
        ),
    ),
  'id' => 'node.full_html.field_start_date',
  'field_name' => 'field_start_date',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Start date',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
    ),
  'field_type' => 'datetime',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.full_html.promote');
$config_group->setData(array(
  'uuid' => '2dada232-4925-4b4e-a6c9-8730a759912f',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'node.type.full_html',
        ),
    ),
  'id' => 'node.full_html.promote',
  'field_name' => 'promote',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Promoted to front page',
  'description' => '',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
      0 =>
        array (
          'value' => 0,
        ),
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
      'on_label' => 'On',
      'off_label' => 'Off',
    ),
  'field_type' => 'boolean',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.full_html.status');
$config_group->setData(array(
  'uuid' => '0eeac7fb-915d-4792-97c0-de516e418924',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'node.type.full_html',
        ),
    ),
  'id' => 'node.full_html.status',
  'field_name' => 'status',
  'entity_type' => 'node',
  'bundle' => 'full_html',
  'label' => 'Publishing status',
  'description' => 'A boolean indicating whether the node is published.',
  'required' => false,
  'translatable' => true,
  'default_value' =>
    array (
      0 =>
        array (
          'value' => 0,
        ),
    ),
  'default_value_callback' => '',
  'settings' =>
    array (
      'on_label' => 'On',
      'off_label' => 'Off',
    ),
  'field_type' => 'boolean',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.full_html.default');
$config_group->setData(array(
  'uuid' => '5e5ca55f-26fa-4b50-9cbb-6e0493d853c9',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.full_html.field_content',
          1 => 'field.field.node.full_html.field_display_title',
          2 => 'field.field.node.full_html.field_end_date',
          3 => 'field.field.node.full_html.field_meta_description',
          4 => 'field.field.node.full_html.field_meta_title',
          5 => 'field.field.node.full_html.field_metatags',
          6 => 'field.field.node.full_html.field_start_date',
          7 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'datetime',
          1 => 'field_group',
          2 => 'metatag',
          3 => 'path',
          4 => 'text',
          5 => 'workbench_moderation',
        ),
    ),
  'third_party_settings' =>
    array (
      'field_group' =>
        array (
          'group_onglets' =>
            array (
              'children' =>
                array (
                  0 => 'group_write',
                  1 => 'group_classify',
                  2 => 'group_publish',
                  3 => 'group_seo',
                ),
              'parent_name' => '',
              'weight' => 0,
              'format_type' => 'tabs',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'direction' => 'vertical',
                ),
              'label' => 'Onglets',
            ),
          'group_write' =>
            array (
              'children' =>
                array (
                  0 => 'langcode',
                  1 => 'title',
                  2 => 'field_display_title',
                  3 => 'field_content',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 20,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Write',
            ),
          'group_classify' =>
            array (
              'children' =>
                array (
                ),
              'parent_name' => 'group_onglets',
              'weight' => 21,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Classify',
            ),
          'group_publish' =>
            array (
              'children' =>
                array (
                  0 => 'group_content_worthy_period',
                  1 => 'path',
                  2 => 'field_metatags',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 22,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Publish',
            ),
          'group_seo' =>
            array (
              'children' =>
                array (
                  0 => 'field_meta_title',
                  1 => 'field_meta_description',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 23,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'SEO',
            ),
          'group_content_worthy_period' =>
            array (
              'children' =>
                array (
                  0 => 'field_start_date',
                  1 => 'field_end_date',
                ),
              'parent_name' => 'group_publish',
              'weight' => 20,
              'format_type' => 'fieldset',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Content worthy period',
            ),
        ),
    ),
  'id' => 'node.full_html.default',
  'targetEntityType' => 'node',
  'bundle' => 'full_html',
  'mode' => 'default',
  'content' =>
    array (
      'field_content' =>
        array (
          'weight' => 5,
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'text_textarea',
        ),
      'field_display_title' =>
        array (
          'weight' => 4,
          'settings' =>
            array (
              'display_label' => true,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'boolean_checkbox',
        ),
      'field_end_date' =>
        array (
          'weight' => 2,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
        ),
      'field_meta_description' =>
        array (
          'weight' => 11,
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
      'field_meta_title' =>
        array (
          'weight' => 10,
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
      'field_metatags' =>
        array (
          'weight' => 22,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'metatag_firehose',
        ),
      'field_start_date' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
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
          'weight' => 21,
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
      'translation' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
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
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.full_html.default');
$config_group->setData(array(
  'uuid' => '446d7370-d30e-4e73-bf4b-4c04d0dbecad',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.full_html.field_content',
          1 => 'field.field.node.full_html.field_display_title',
          2 => 'field.field.node.full_html.field_end_date',
          3 => 'field.field.node.full_html.field_meta_description',
          4 => 'field.field.node.full_html.field_meta_title',
          5 => 'field.field.node.full_html.field_metatags',
          6 => 'field.field.node.full_html.field_start_date',
          7 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'text',
          1 => 'user',
        ),
    ),
  'id' => 'node.full_html.default',
  'targetEntityType' => 'node',
  'bundle' => 'full_html',
  'mode' => 'default',
  'content' =>
    array (
      'field_content' =>
        array (
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'text_default',
        ),
    ),
  'hidden' =>
    array (
      'field_display_title' => true,
      'field_end_date' => true,
      'field_meta_description' => true,
      'field_meta_title' => true,
      'field_metatags' => true,
      'field_start_date' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.full_html.full');
$config_group->setData(array(
  'uuid' => '5d643335-bd06-4f2b-b3b6-914270809087',
  'langcode' => 'en',
  'status' => false,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.full',
          1 => 'field.field.node.full_html.field_content',
          2 => 'field.field.node.full_html.field_display_title',
          3 => 'field.field.node.full_html.field_end_date',
          4 => 'field.field.node.full_html.field_meta_description',
          5 => 'field.field.node.full_html.field_meta_title',
          6 => 'field.field.node.full_html.field_metatags',
          7 => 'field.field.node.full_html.field_start_date',
          8 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'datetime',
          1 => 'metatag',
          2 => 'text',
          3 => 'user',
        ),
    ),
  'id' => 'node.full_html.full',
  'targetEntityType' => 'node',
  'bundle' => 'full_html',
  'mode' => 'full',
  'content' =>
    array (
      'field_content' =>
        array (
          'weight' => 101,
          'label' => 'above',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'text_default',
        ),
      'field_display_title' =>
        array (
          'weight' => 103,
          'label' => 'above',
          'settings' =>
            array (
              'format' => 'default',
              'format_custom_false' => '',
              'format_custom_true' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'boolean',
        ),
      'field_end_date' =>
        array (
          'weight' => 107,
          'label' => 'above',
          'settings' =>
            array (
              'format_type' => 'medium',
              'timezone_override' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
        ),
      'field_meta_description' =>
        array (
          'weight' => 105,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_meta_title' =>
        array (
          'weight' => 104,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_metatags' =>
        array (
          'weight' => 102,
          'label' => 'above',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'metatag_empty_formatter',
        ),
      'field_start_date' =>
        array (
          'weight' => 106,
          'label' => 'above',
          'settings' =>
            array (
              'format_type' => 'medium',
              'timezone_override' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
        ),
      'links' =>
        array (
          'weight' => 100,
        ),
    ),
  'hidden' =>
    array (
      'langcode' => true,
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.full_html.teaser');
$config_group->setData(array(
  'uuid' => '2222dc93-fd8d-4426-b941-6972a6b4c629',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.teaser',
          1 => 'field.field.node.full_html.field_content',
          2 => 'field.field.node.full_html.field_display_title',
          3 => 'field.field.node.full_html.field_end_date',
          4 => 'field.field.node.full_html.field_meta_description',
          5 => 'field.field.node.full_html.field_meta_title',
          6 => 'field.field.node.full_html.field_metatags',
          7 => 'field.field.node.full_html.field_start_date',
          8 => 'node.type.full_html',
        ),
      'module' =>
        array (
          0 => 'text',
          1 => 'user',
        ),
    ),
  'id' => 'node.full_html.teaser',
  'targetEntityType' => 'node',
  'bundle' => 'full_html',
  'mode' => 'teaser',
  'content' =>
    array (
      'field_content' =>
        array (
          'type' => 'text_trimmed',
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'trim_length' => 100,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'field_display_title' => true,
      'field_end_date' => true,
      'field_meta_description' => true,
      'field_meta_title' => true,
      'field_metatags' => true,
      'field_start_date' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config_group->save(TRUE);