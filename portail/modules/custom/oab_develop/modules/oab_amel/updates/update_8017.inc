<?php
/******** INDUSTRY *********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.default');
$config_group->setData(
    array (
        'uuid' => 'e8869272-4cf2-481b-ad12-c571dd1daa23',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.industry.field_content',
                        1 => 'field.field.node.industry.field_content_owner',
                        2 => 'field.field.node.industry.field_display_title',
                        3 => 'field.field.node.industry.field_email_owner',
                        4 => 'field.field.node.industry.field_end_date',
                        5 => 'field.field.node.industry.field_highlight',
                        6 => 'field.field.node.industry.field_industry',
                        7 => 'field.field.node.industry.field_job_profile',
                        8 => 'field.field.node.industry.field_market_segment',
                        9 => 'field.field.node.industry.field_meta_description',
                        10 => 'field.field.node.industry.field_meta_title',
                        11 => 'field.field.node.industry.field_region',
                        12 => 'field.field.node.industry.field_solution',
                        13 => 'field.field.node.industry.field_start_date',
                        14 => 'field.field.node.industry.field_top_zone',
                        15 => 'field.field.node.industry.field_top_zone_background',
                        16 => 'field.field.node.industry.field_visual',
                        17 => 'node.type.industry',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.industry.default',
        'targetEntityType' => 'node',
        'bundle' => 'industry',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 6,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                        'region' => 'content',
                    ),
                'field_industry' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'field_solution' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'links' =>
                    array (
                        'weight' => 1,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'workbench_moderation_control' =>
                    array (
                        'weight' => 0,
                        'region' => 'content',
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
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_start_date' => true,
                'field_top_zone' => true,
                'field_top_zone_background' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.industry.default');
$config_group->setData(
    array (
        'uuid' => '85031f3a-be20-43bc-bbe6-447651a7b1c3',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.industry.field_content',
                        2 => 'field.field.node.industry.field_content_owner',
                        3 => 'field.field.node.industry.field_display_title',
                        4 => 'field.field.node.industry.field_email_owner',
                        5 => 'field.field.node.industry.field_end_date',
                        6 => 'field.field.node.industry.field_highlight',
                        7 => 'field.field.node.industry.field_industry',
                        8 => 'field.field.node.industry.field_job_profile',
                        9 => 'field.field.node.industry.field_market_segment',
                        10 => 'field.field.node.industry.field_meta_description',
                        11 => 'field.field.node.industry.field_meta_title',
                        12 => 'field.field.node.industry.field_region',
                        13 => 'field.field.node.industry.field_solution',
                        14 => 'field.field.node.industry.field_start_date',
                        15 => 'field.field.node.industry.field_top_zone',
                        16 => 'field.field.node.industry.field_top_zone_background',
                        17 => 'field.field.node.industry.field_visual',
                        18 => 'node.type.industry',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
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
                                        3 => 'field_top_zone',
                                        4 => 'field_top_zone_background',
                                        5 => 'field_highlight',
                                        6 => 'field_content',
                                        7 => 'field_visual',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 17,
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
                                        0 => 'field_solution',
                                        1 => 'field_region',
                                        2 => 'field_industry',
                                        3 => 'field_job_profile',
                                        4 => 'field_market_segment',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 18,
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
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 19,
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
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
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
                                'weight' => 11,
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
        'id' => 'node.industry.default',
        'targetEntityType' => 'node',
        'bundle' => 'industry',
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
                        'weight' => 9,
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
                        'weight' => 4,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 10,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
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
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 7,
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
                'field_job_profile' =>
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
                'field_market_segment' =>
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
                'field_meta_description' =>
                    array (
                        'weight' => 1,
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
                'field_meta_title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 0,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_region' =>
                    array (
                        'weight' => 25,
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
                        'weight' => 24,
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
                        'weight' => 1,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_top_zone' =>
                    array (
                        'type' => 'text_textarea',
                        'weight' => 5,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_top_zone_background' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'weight' => 6,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'open' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'teaser',
                                    ),
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 13,
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
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'weight' => 12,
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);




/******** SOLUTION *********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.solution.default');
$config_group->setData(
    array (
        'uuid' => 'ded733d8-3084-4cab-87e2-7542b0f06974',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.solution.field_content',
                        2 => 'field.field.node.solution.field_content_owner',
                        3 => 'field.field.node.solution.field_display_title',
                        4 => 'field.field.node.solution.field_email_owner',
                        5 => 'field.field.node.solution.field_end_date',
                        6 => 'field.field.node.solution.field_highlight',
                        7 => 'field.field.node.solution.field_industry',
                        8 => 'field.field.node.solution.field_job_profile',
                        9 => 'field.field.node.solution.field_market_segment',
                        10 => 'field.field.node.solution.field_meta_description',
                        11 => 'field.field.node.solution.field_meta_title',
                        12 => 'field.field.node.solution.field_region',
                        13 => 'field.field.node.solution.field_solution',
                        14 => 'field.field.node.solution.field_start_date',
                        15 => 'field.field.node.solution.field_top_zone',
                        16 => 'field.field.node.solution.field_top_zone_background',
                        17 => 'field.field.node.solution.field_visual',
                        18 => 'node.type.solution',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
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
                                        4 => 'field_top_zone',
                                        5 => 'field_top_zone_background',
                                        6 => 'field_content',
                                        7 => 'field_visual',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 17,
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
                                        0 => 'field_solution',
                                        1 => 'field_region',
                                        2 => 'field_industry',
                                        3 => 'field_job_profile',
                                        4 => 'field_market_segment',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 18,
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
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 19,
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
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
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
                                'weight' => 14,
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
        'id' => 'node.solution.default',
        'targetEntityType' => 'node',
        'bundle' => 'solution',
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
                        'weight' => 12,
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
                        'weight' => 4,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
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
                        'weight' => 5,
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
                        'weight' => 16,
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
                        'weight' => 17,
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
                        'weight' => 18,
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
                        'weight' => 19,
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
                'field_meta_title' =>
                    array (
                        'weight' => 18,
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
                'field_region' =>
                    array (
                        'weight' => 15,
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
                        'weight' => 14,
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
                'field_top_zone' =>
                    array (
                        'type' => 'text_textarea',
                        'weight' => 6,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_top_zone_background' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'weight' => 7,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'open' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'teaser',
                                    ),
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 16,
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
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'weight' => 15,
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.default');
$config_group->setData(
    array (
        'uuid' => 'dd6a5788-1324-4b14-84cd-7bdf016bb502',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.solution.field_content',
                        1 => 'field.field.node.solution.field_content_owner',
                        2 => 'field.field.node.solution.field_display_title',
                        3 => 'field.field.node.solution.field_email_owner',
                        4 => 'field.field.node.solution.field_end_date',
                        5 => 'field.field.node.solution.field_highlight',
                        6 => 'field.field.node.solution.field_industry',
                        7 => 'field.field.node.solution.field_job_profile',
                        8 => 'field.field.node.solution.field_market_segment',
                        9 => 'field.field.node.solution.field_meta_description',
                        10 => 'field.field.node.solution.field_meta_title',
                        11 => 'field.field.node.solution.field_region',
                        12 => 'field.field.node.solution.field_solution',
                        13 => 'field.field.node.solution.field_start_date',
                        14 => 'field.field.node.solution.field_top_zone',
                        15 => 'field.field.node.solution.field_top_zone_background',
                        16 => 'field.field.node.solution.field_visual',
                        17 => 'node.type.solution',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.solution.default',
        'targetEntityType' => 'node',
        'bundle' => 'solution',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                        'region' => 'content',
                    ),
                'field_industry' =>
                    array (
                        'type' => 'entity_reference_label',
                        'weight' => 5,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_solution' =>
                    array (
                        'type' => 'entity_reference_label',
                        'weight' => 4,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'links' =>
                    array (
                        'weight' => 1,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'workbench_moderation_control' =>
                    array (
                        'weight' => 0,
                        'region' => 'content',
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
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_start_date' => true,
                'field_top_zone' => true,
                'field_top_zone_background' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



/******** REGION *********/

// solution top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_top_zone');
$config_group->setData(
    array (
        'uuid' => 'cbf75b33-199d-4adc-be97-08eb88c9ec60',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_top_zone',
                        1 => 'node.type.region',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                    ),
            ),
        'id' => 'node.region.field_top_zone',
        'field_name' => 'field_top_zone',
        'entity_type' => 'node',
        'bundle' => 'region',
        'label' => 'Top zone',
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
    )
);
$config_group->save(TRUE);

// solution top zone BG
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_top_zone_background');
$config_group->setData(
    array (
        'uuid' => 'f0d4374f-1c11-4034-9ea8-99e172bbab81',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_top_zone_background',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.region',
                    ),
            ),
        'id' => 'node.region.field_top_zone_background',
        'field_name' => 'field_top_zone_background',
        'entity_type' => 'node',
        'bundle' => 'region',
        'label' => 'Top zone background',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.region.default');
$config_group->setData(
    array (
        'uuid' => 'fafecffa-fff7-4acd-85fc-37adbc281168',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.region.field_content',
                        2 => 'field.field.node.region.field_content_owner',
                        3 => 'field.field.node.region.field_display_title',
                        4 => 'field.field.node.region.field_email_owner',
                        5 => 'field.field.node.region.field_end_date',
                        6 => 'field.field.node.region.field_highlight',
                        7 => 'field.field.node.region.field_industry',
                        8 => 'field.field.node.region.field_job_profile',
                        9 => 'field.field.node.region.field_market_segment',
                        10 => 'field.field.node.region.field_meta_description',
                        11 => 'field.field.node.region.field_meta_title',
                        12 => 'field.field.node.region.field_region',
                        13 => 'field.field.node.region.field_solution',
                        14 => 'field.field.node.region.field_start_date',
                        15 => 'field.field.node.region.field_top_zone',
                        16 => 'field.field.node.region.field_top_zone_background',
                        17 => 'field.field.node.region.field_visual',
                        18 => 'node.type.region',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
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
                                        4 => 'field_top_zone',
                                        5 => 'field_top_zone_background',
                                        6 => 'field_content',
                                        7 => 'field_visual',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 7,
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
                                        0 => 'field_solution',
                                        1 => 'field_region',
                                        2 => 'field_industry',
                                        3 => 'field_job_profile',
                                        4 => 'field_market_segment',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 8,
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
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 9,
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
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_c',
                                        3 => 'promote',
                                        4 => 'path',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 10,
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
                        'group_c' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 11,
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
        'id' => 'node.region.default',
        'targetEntityType' => 'node',
        'bundle' => 'region',
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
                        'weight' => 9,
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
                        'weight' => 4,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
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
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 8,
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
                        'weight' => 5,
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
                'field_market_segment' =>
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
                'field_meta_description' =>
                    array (
                        'weight' => 21,
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
                'field_meta_title' =>
                    array (
                        'weight' => 20,
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
                'field_region' =>
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
                'field_solution' =>
                    array (
                        'weight' => 25,
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
                        'weight' => 7,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_top_zone' =>
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
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_top_zone_background' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
                        'weight' => 7,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 13,
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
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'weight' => 12,
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.default');
$config_group->setData(
    array (
        'uuid' => 'd93f57d7-8441-47bd-b0b3-598c3df704f0',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.region.field_content',
                        1 => 'field.field.node.region.field_content_owner',
                        2 => 'field.field.node.region.field_display_title',
                        3 => 'field.field.node.region.field_email_owner',
                        4 => 'field.field.node.region.field_end_date',
                        5 => 'field.field.node.region.field_highlight',
                        6 => 'field.field.node.region.field_industry',
                        7 => 'field.field.node.region.field_job_profile',
                        8 => 'field.field.node.region.field_market_segment',
                        9 => 'field.field.node.region.field_meta_description',
                        10 => 'field.field.node.region.field_meta_title',
                        11 => 'field.field.node.region.field_region',
                        12 => 'field.field.node.region.field_solution',
                        13 => 'field.field.node.region.field_start_date',
                        14 => 'field.field.node.region.field_top_zone',
                        15 => 'field.field.node.region.field_top_zone_background',
                        16 => 'field.field.node.region.field_visual',
                        17 => 'node.type.region',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.region.default',
        'targetEntityType' => 'node',
        'bundle' => 'region',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 6,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                        'region' => 'content',
                    ),
                'field_industry' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'field_solution' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'links' =>
                    array (
                        'weight' => 1,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'workbench_moderation_control' =>
                    array (
                        'weight' => 0,
                        'region' => 'content',
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
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_start_date' => true,
                'field_top_zone' => true,
                'field_top_zone_background' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



/******** COUNTRY *********/

// country top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_top_zone');
$config_group->setData(
    array (
        'uuid' => '4e0a4221-9c73-4cb8-a521-a6a6719455ab',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_top_zone',
                        1 => 'node.type.country',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                    ),
            ),
        'id' => 'node.country.field_top_zone',
        'field_name' => 'field_top_zone',
        'entity_type' => 'node',
        'bundle' => 'country',
        'label' => 'Top zone',
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
    )
);
$config_group->save(TRUE);

// industrie top zone BG
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_top_zone_background');
$config_group->setData(
    array (
        'uuid' => 'a4ae2117-a05c-4c4b-b5f8-cfdd2558d56d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_top_zone_background',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.country',
                    ),
            ),
        'id' => 'node.country.field_top_zone_background',
        'field_name' => 'field_top_zone_background',
        'entity_type' => 'node',
        'bundle' => 'country',
        'label' => 'Top zone background',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');
$config_group->setData(
    array (
        'uuid' => '1f8a80eb-afb8-43ea-bbbc-e82b705e0d23',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.country.field_content',
                        2 => 'field.field.node.country.field_content_owner',
                        3 => 'field.field.node.country.field_display_title',
                        4 => 'field.field.node.country.field_email_owner',
                        5 => 'field.field.node.country.field_end_date',
                        6 => 'field.field.node.country.field_highlight',
                        7 => 'field.field.node.country.field_industry',
                        8 => 'field.field.node.country.field_job_profile',
                        9 => 'field.field.node.country.field_market_segment',
                        10 => 'field.field.node.country.field_meta_description',
                        11 => 'field.field.node.country.field_meta_title',
                        12 => 'field.field.node.country.field_region',
                        13 => 'field.field.node.country.field_solution',
                        14 => 'field.field.node.country.field_start_date',
                        15 => 'field.field.node.country.field_top_zone',
                        16 => 'field.field.node.country.field_top_zone_background',
                        17 => 'field.field.node.country.field_visual',
                        18 => 'node.type.country',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
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
                                        4 => 'field_top_zone',
                                        5 => 'field_top_zone_background',
                                        6 => 'field_content',
                                        7 => 'field_visual',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 7,
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
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 9,
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
                        'group_classify' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_solution',
                                        1 => 'field_region',
                                        2 => 'field_industry',
                                        3 => 'field_job_profile',
                                        4 => 'field_market_segment',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 8,
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
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 10,
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
                                'weight' => 17,
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
        'id' => 'node.country.default',
        'targetEntityType' => 'node',
        'bundle' => 'country',
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
                        'weight' => 15,
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
                        'weight' => 4,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
                    array (
                        'weight' => 16,
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
                        'weight' => 13,
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
                        'weight' => 5,
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
                'field_job_profile' =>
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
                'field_market_segment' =>
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
                'field_meta_description' =>
                    array (
                        'weight' => 18,
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
                'field_meta_title' =>
                    array (
                        'weight' => 17,
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
                'field_region' =>
                    array (
                        'weight' => 25,
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
                        'weight' => 24,
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
                        'weight' => 12,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_top_zone' =>
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
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_top_zone_background' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
                        'weight' => 7,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'default',
                                    ),
                                'open' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 19,
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
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'weight' => 18,
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.default');
$config_group->setData(
    array (
        'uuid' => '1b599147-7899-418c-a9e2-74442607a028',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.country.field_content',
                        1 => 'field.field.node.country.field_content_owner',
                        2 => 'field.field.node.country.field_display_title',
                        3 => 'field.field.node.country.field_email_owner',
                        4 => 'field.field.node.country.field_end_date',
                        5 => 'field.field.node.country.field_highlight',
                        6 => 'field.field.node.country.field_industry',
                        7 => 'field.field.node.country.field_job_profile',
                        8 => 'field.field.node.country.field_market_segment',
                        9 => 'field.field.node.country.field_meta_description',
                        10 => 'field.field.node.country.field_meta_title',
                        11 => 'field.field.node.country.field_region',
                        12 => 'field.field.node.country.field_solution',
                        13 => 'field.field.node.country.field_start_date',
                        14 => 'field.field.node.country.field_top_zone',
                        15 => 'field.field.node.country.field_top_zone_background',
                        16 => 'field.field.node.country.field_visual',
                        17 => 'node.type.country',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.country.default',
        'targetEntityType' => 'node',
        'bundle' => 'country',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'links' =>
                    array (
                        'weight' => 0,
                        'region' => 'content',
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
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_top_zone' => true,
                'field_top_zone_background' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



/**** FIELD VISUAL ****/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_visual');
$config_group->setData(
    array (
        'uuid' => 'b735577a-79cc-4518-9916-a91d414e204d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.solution',
                    ),
            ),
        'id' => 'node.solution.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'solution',
        'label' => 'Ornamental visual',
        'description' => 'image size : width 420 x height 200 px',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);




$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_visual');
$config_group->setData(
    array (
        'uuid' => '1a36a46c-f16f-458b-ac0c-9d8b7b5e9295',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.industry',
                    ),
            ),
        'id' => 'node.industry.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'industry',
        'label' => 'Ornamental visual',
        'description' => 'image size : width 420 x height 200 px',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);





$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_visual');
$config_group->setData(
    array (
        'uuid' => '0c2f157f-5c33-47c4-a800-1873b85cd35f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.region',
                    ),
            ),
        'id' => 'node.region.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'region',
        'label' => 'Ornamental visual',
        'description' => 'image size : width 420 x height 200 px',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);



$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_visual');
$config_group->setData(
    array (
        'uuid' => '38a65dbc-c3d0-46f5-a90e-1c6795eed14f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.country',
                    ),
            ),
        'id' => 'node.country.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'country',
        'label' => 'Ornamental visual',
        'description' => 'image size : width 420 x height 200 px',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'image' => 'image',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);
