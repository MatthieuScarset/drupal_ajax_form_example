<?php

/**
 * Edition de la configuration pour le formulaire
 */
/** core.entity_form_display.node.container.default **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.container.default');
$config_group->setData(
    array (
        'uuid' => NULL,
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.container.field_area',
                        1 => 'field.field.node.container.field_blog',
                        2 => 'field.field.node.container.field_city',
                        3 => 'field.field.node.container.field_commentaire',
                        4 => 'field.field.node.container.field_content_field',
                        5 => 'field.field.node.container.field_country',
                        6 => 'field.field.node.container.field_customer_story',
                        7 => 'field.field.node.container.field_display_title',
                        8 => 'field.field.node.container.field_document_type',
                        9 => 'field.field.node.container.field_end_date',
                        10 => 'field.field.node.container.field_file',
                        11 => 'field.field.node.container.field_image',
                        12 => 'field.field.node.container.field_industry',
                        13 => 'field.field.node.container.field_magazine',
                        14 => 'field.field.node.container.field_owner',
                        15 => 'field.field.node.container.field_partner',
                        16 => 'field.field.node.container.field_profile',
                        17 => 'field.field.node.container.field_rendering_model',
                        18 => 'field.field.node.container.field_section',
                        19 => 'field.field.node.container.field_short_description',
                        20 => 'field.field.node.container.field_solution',
                        21 => 'field.field.node.container.field_start_date',
                        22 => 'field.field.node.container.field_state',
                        23 => 'field.field.node.container.field_subtitle',
                        24 => 'field.field.node.container.field_topic',
                        25 => 'node.type.container',
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
                                        1 => 'field_section',
                                        2 => 'langcode',
                                        3 => 'title',
                                        4 => 'field_display_title',
                                        5 => 'field_subtitle',
                                        6 => 'field_short_description',
                                        7 => 'field_profile',
                                        8 => 'field_owner',
                                        9 => 'group_date_fieldset',
                                        10 => 'path',
                                        11 => 'field_country',
                                        12 => 'field_city',
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
                                'weight' => 10,
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
                'field_city' =>
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
                'field_country' =>
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
                        'weight' => 5,
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
                        'weight' => 8,
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
                'field_section' =>
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
                'field_short_description' =>
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
                        'weight' => 6,
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
                        'weight' => 3,
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
                        'weight' => 11,
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
                        'weight' => 4,
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
$config_group->save(TRUE);
drupal_set_message("Formulaire Container modifié", "status");


