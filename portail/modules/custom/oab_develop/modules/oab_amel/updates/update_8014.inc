<?php
/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.default');
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
                    2 => 'field.field.node.container.field_commentaires',
                    3 => 'field.field.node.container.field_content_field',
                    4 => 'field.field.node.container.field_customer_story',
                    5 => 'field.field.node.container.field_document_type',
                    6 => 'field.field.node.container.field_end_date',
                    7 => 'field.field.node.container.field_file',
                    8 => 'field.field.node.container.field_image',
                    9 => 'field.field.node.container.field_industry',
                    10 => 'field.field.node.container.field_magazine',
                    11 => 'field.field.node.container.field_partner',
                    12 => 'field.field.node.container.field_profile',
                    13 => 'field.field.node.container.field_rendering_model',
                    14 => 'field.field.node.container.field_short_description',
                    15 => 'field.field.node.container.field_solution',
                    16 => 'field.field.node.container.field_start_date',
                    17 => 'field.field.node.container.field_state',
                    18 => 'field.field.node.container.field_subtitle',
                    19 => 'field.field.node.container.field_topic',
                    20 => 'node.type.container',
                ),
            'module' =>
                array (
                    0 => 'oab_text',
                    1 => 'user',
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
                    'type' => 'entity_reference_label',
                    'weight' => 10,
                    'label' => 'hidden',
                    'settings' =>
                        array (
                            'link' => true,
                        ),
                    'third_party_settings' =>
                        array (
                        ),
                ),
            'field_blog' =>
                array (
                    'type' => 'entity_reference_entity_view',
                    'weight' => 6,
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
            'field_commentaire' =>
                array (
                    'weight' => 11,
                    'label' => 'above',
                    'settings' =>
                        array (
                            'pager_id' => 0,
                        ),
                    'third_party_settings' =>
                        array (
                        ),
                    'type' => 'comment_default',
                ),
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
            'field_file' =>
                array (
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
                    'type' => 'entity_reference_entity_view',
                ),
            'field_image' =>
                array (
                    'type' => 'entity_reference_entity_view',
                    'weight' => 2,
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
            'field_magazine' =>
                array (
                    'type' => 'entity_reference_entity_view',
                    'weight' => 7,
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
            'field_profile' =>
                array (
                    'weight' => 5,
                    'label' => 'hidden',
                    'settings' =>
                        array (
                            'view_mode' => 'teaser',
                            'link' => false,
                        ),
                    'third_party_settings' =>
                        array (
                        ),
                    'type' => 'entity_reference_entity_view',
                ),
            'field_short_description' =>
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
            'field_commentaires' => true,
            'field_customer_story' => true,
            'field_document_type' => true,
            'field_end_date' => true,
            'field_industry' => true,
            'field_partner' => true,
            'field_rendering_model' => true,
            'field_solution' => true,
            'field_start_date' => true,
            'field_state' => true,
            'field_topic' => true,
            'langcode' => true,
            'links' => true,
        ),
));
$config_group->save(TRUE);
