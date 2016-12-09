<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.node.container.default');
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
                    14 => 'field.field.node.container.field_meta_descriptif_court',
                    15 => 'field.field.node.container.field_meta_titre',
                    16 => 'field.field.node.container.field_metatags',
                    17 => 'field.field.node.container.field_owner',
                    18 => 'field.field.node.container.field_partner',
                    19 => 'field.field.node.container.field_profile',
                    20 => 'field.field.node.container.field_rendering_model',
                    21 => 'field.field.node.container.field_section',
                    22 => 'field.field.node.container.field_short_description',
                    23 => 'field.field.node.container.field_solution',
                    24 => 'field.field.node.container.field_start_date',
                    25 => 'field.field.node.container.field_state',
                    26 => 'field.field.node.container.field_subtitle',
                    27 => 'field.field.node.container.field_topic',
                    28 => 'field.field.node.container.publish_date',
                    29 => 'field.field.node.container.unpublish_date',
                    30 => 'node.type.container',
                ),
            'module' =>
                array (
                    0 => 'comment',
                    1 => 'content_moderation',
                    2 => 'datetime',
                    3 => 'entity_browser',
                    4 => 'field_group',
                    5 => 'metatag',
                    6 => 'oab_text',
                    7 => 'path',
                    8 => 'workflowfield',
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
                                    5 => 'group_rediger',
                                    6 => 'group_classer',
                                    7 => 'group_publier',
                                ),
                            'parent_name' => '',
                            'weight' => 0,
                            'label' => 'Onglets',
                            'format_type' => 'tabs',
                            'format_settings' =>
                                array (
                                    'label' => 'Onglets',
                                    'direction' => 'vertical',
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
                            'parent_name' => 'group_publier',
                            'weight' => 5,
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
                    'group_rediger' =>
                        array (
                            'children' =>
                                array (
                                    0 => 'field_rendering_model',
                                    1 => 'langcode',
                                    2 => 'title',
                                    3 => 'field_display_title',
                                    4 => 'field_meta_titre',
                                    5 => 'field_subtitle',
                                    6 => 'field_short_description',
                                    7 => 'field_meta_descriptif_court',
                                    8 => 'field_content_field',
                                    9 => 'field_image',
                                    10 => 'field_file',
                                ),
                            'parent_name' => 'group_onglets',
                            'weight' => 6,
                            'label' => 'Write',
                            'format_type' => 'tab',
                            'format_settings' =>
                                array (
                                    'label' => 'Write',
                                    'formatter' => 'closed',
                                    'description' => '',
                                    'required_fields' => true,
                                    'id' => '',
                                    'classes' => '',
                                ),
                        ),
                    'group_classer' =>
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
                            'weight' => 7,
                            'label' => 'Classify',
                            'format_type' => 'tab',
                            'format_settings' =>
                                array (
                                    'label' => 'Classify',
                                    'formatter' => 'closed',
                                    'description' => '',
                                    'required_fields' => true,
                                    'id' => '',
                                    'classes' => '',
                                ),
                        ),
                    'group_publier' =>
                        array (
                            'children' =>
                                array (
                                    0 => 'field_profile',
                                    1 => 'field_owner',
                                    2 => 'group_date_fieldset',
                                    3 => 'field_state',
                                    4 => 'field_metatags',
                                    5 => 'path',
                                    6 => 'field_commentaire',
                                ),
                            'parent_name' => 'group_onglets',
                            'weight' => 8,
                            'label' => 'Publish',
                            'format_type' => 'tab',
                            'format_settings' =>
                                array (
                                    'label' => 'Publish',
                                    'formatter' => 'closed',
                                    'description' => '',
                                    'required_fields' => true,
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
                    'weight' => 6,
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
                    'weight' => 9,
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
                    'weight' => 10,
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
                    'weight' => 4,
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
                    'weight' => 9,
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
                    'type' => 'options_select',
                    'weight' => 12,
                    'settings' =>
                        array (
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
                    'weight' => 8,
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
            'field_meta_descriptif_court' =>
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
            'field_meta_title' =>
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
                    'type' => 'text_textfield',
                ),
            'field_meta_titre' =>
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
            'field_metatags' =>
                array (
                    'weight' => 7,
                    'settings' =>
                        array (
                        ),
                    'third_party_settings' =>
                        array (
                        ),
                    'type' => 'metatag_firehose',
                ),
            'field_owner' =>
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
            'field_partner' =>
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
            'field_profile' =>
                array (
                    'weight' => 3,
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
                    'weight' => 8,
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
                    'weight' => 5,
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
                    'weight' => 6,
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
                    'weight' => 7,
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
                    'weight' => 10,
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
            'field_city' => true,
            'field_country' => true,
            'field_section' => true,
            'promote' => true,
            'publish_date' => true,
            'sticky' => true,
            'uid' => true,
            'unpublish_date' => true,
        ),
));
$config->save(TRUE);

