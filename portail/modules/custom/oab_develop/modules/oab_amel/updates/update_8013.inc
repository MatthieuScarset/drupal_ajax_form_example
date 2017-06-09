<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.simple_page.default');
$config_group->setData(
    array (
        'uuid' => 'a8a2d874-fad2-4ae5-b480-d48715177cb8',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.simple_page.field_content',
                        1 => 'field.field.node.simple_page.field_content_owner',
                        2 => 'field.field.node.simple_page.field_display_title',
                        3 => 'field.field.node.simple_page.field_email_owner',
                        4 => 'field.field.node.simple_page.field_end_date',
                        5 => 'field.field.node.simple_page.field_grouping_title',
                        6 => 'field.field.node.simple_page.field_highlight',
                        7 => 'field.field.node.simple_page.field_industry',
                        8 => 'field.field.node.simple_page.field_job_profile',
                        9 => 'field.field.node.simple_page.field_market_segment',
                        10 => 'field.field.node.simple_page.field_meta_description',
                        11 => 'field.field.node.simple_page.field_meta_title',
                        12 => 'field.field.node.simple_page.field_metatags',
                        13 => 'field.field.node.simple_page.field_region',
                        14 => 'field.field.node.simple_page.field_solution',
                        15 => 'field.field.node.simple_page.field_start_date',
                        16 => 'field.field.node.simple_page.field_subhome',
                        17 => 'field.field.node.simple_page.field_thematic',
                        18 => 'node.type.simple_page',
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
                                        2 => 'group_seo',
                                        3 => 'group_publish',
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
                                        3 => 'field_highlight',
                                        4 => 'field_content',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 3,
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
                                        0 => 'field_subhome',
                                        1 => 'field_industry',
                                        2 => 'field_solution',
                                        3 => 'field_region',
                                        4 => 'field_market_segment',
                                        5 => 'field_job_profile',
                                        6 => 'field_thematic',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 4,
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
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
                                        5 => 'field_metatags',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 6,
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
                        'group_content_worthy_period' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 15,
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
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 5,
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
                    ),
            ),
        'id' => 'node.simple_page.default',
        'targetEntityType' => 'node',
        'bundle' => 'simple_page',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 8,
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_content_owner' =>
                    array (
                        'weight' => 13,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_display_title' =>
                    array (
                        'weight' => 3,
                        'settings' =>
                            array (
                                'display_label' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
                    array (
                        'weight' => 14,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 10,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
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
                        'region' => 'content',
                    ),
                'field_industry' =>
                    array (
                        'weight' => 27,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_job_profile' =>
                    array (
                        'weight' => 31,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_market_segment' =>
                    array (
                        'weight' => 30,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_meta_description' =>
                    array (
                        'weight' => 5,
                        'settings' =>
                            array (
                                'size' => 156,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_meta_title' =>
                    array (
                        'weight' => 4,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 18,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 29,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_solution' =>
                    array (
                        'weight' => 28,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_start_date' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_subhome' =>
                    array (
                        'weight' => 26,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_thematic' =>
                    array (
                        'weight' => 32,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'langcode' =>
                    array (
                        'type' => 'language_select',
                        'weight' => 1,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 17,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'promote' =>
                    array (
                        'type' => 'boolean_checkbox',
                        'weight' => 16,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 2,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_grouping_title' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

