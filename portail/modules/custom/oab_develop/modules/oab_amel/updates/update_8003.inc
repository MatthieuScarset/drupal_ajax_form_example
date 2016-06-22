<?php
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.container.default');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.container.field_area',
                        1 => 'field.field.node.container.field_blog',
                        2 => 'field.field.node.container.field_content_field',
                        3 => 'field.field.node.container.field_customer_story',
                        4 => 'field.field.node.container.field_end_date',
                        5 => 'field.field.node.container.field_file',
                        6 => 'field.field.node.container.field_image',
                        7 => 'field.field.node.container.field_industry',
                        8 => 'field.field.node.container.field_magazine',
                        9 => 'field.field.node.container.field_partner',
                        10 => 'field.field.node.container.field_rendering_model',
                        11 => 'field.field.node.container.field_short_description',
                        12 => 'field.field.node.container.field_solution',
                        13 => 'field.field.node.container.field_start_date',
                        14 => 'field.field.node.container.field_state',
                        15 => 'field.field.node.container.field_subtitle',
                        16 => 'node.type.container',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'oab_text',
                        4 => 'path',
                        5 => 'workflowfield',
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
                                        3 => 'field_subtitle',
                                        4 => 'field_short_description',
                                        5 => 'field_start_date',
                                        6 => 'field_end_date',
                                        7 => 'path',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 1,
                                'label' => 'Général',
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
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 2,
                                'label' => 'Taxonomie',
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'open' => false,
                                        'required_fields' => true,
                                        'classes' => '',
                                        'id' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'direction' => 'vertical',
                                    ),
                            ),
                        'group_medias' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_image',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 3,
                                'label' => 'Médias',
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
                        'group_workflow' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_state',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 4,
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
                        'group_contenu' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_field',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 5,
                                'label' => 'Contenu',
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'classes' => '',
                                        'id' => '',
                                        'required_fields' => true,
                                    ),
                            ),
                        'group_onglets' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'group_general',
                                        1 => 'group_taxonomie',
                                        2 => 'group_medias',
                                        3 => 'group_workflow',
                                        4 => 'group_contenu',
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
                'field_image' =>
                    array (
                        'weight' => 11,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'rendered_entity',
                                'field_widget_edit' => '1',
                                'field_widget_remove' => '1',
                                'field_widget_display_settings' =>
                                    array (
                                        'view_mode' => 'teaser',
                                    ),
                                'open' => 0,
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
                        'weight' => 8,
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
                'field_file' => true,
                'promote' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);