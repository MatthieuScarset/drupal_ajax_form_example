<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$config_group->setData(
    array (
        'uuid' => '7c01bb47-3e8e-4414-ae00-9bf970cbed77',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.partner.field_content',
                        1 => 'field.field.node.partner.field_content_owner',
                        2 => 'field.field.node.partner.field_display_title',
                        3 => 'field.field.node.partner.field_email_owner',
                        4 => 'field.field.node.partner.field_end_date',
                        5 => 'field.field.node.partner.field_file',
                        6 => 'field.field.node.partner.field_highlight',
                        7 => 'field.field.node.partner.field_meta_description',
                        8 => 'field.field.node.partner.field_meta_title',
                        9 => 'field.field.node.partner.field_metatags',
                        10 => 'field.field.node.partner.field_partner',
                        11 => 'field.field.node.partner.field_start_date',
                        12 => 'field.field.node.partner.field_subhome',
                        13 => 'field.field.node.partner.field_visual',
                        14 => 'node.type.partner',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'metatag',
                        2 => 'text',
                        3 => 'user',
                    ),
            ),
        'id' => 'node.partner.default',
        'targetEntityType' => 'node',
        'bundle' => 'partner',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                    ),
                'field_content_owner' =>
                    array (
                        'weight' => 3,
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
                'field_email_owner' =>
                    array (
                        'weight' => 4,
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
                'field_end_date' =>
                    array (
                        'weight' => 12,
                        'label' => 'hidden',
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
                'field_file' =>
                    array (
                        'weight' => 6,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                                'view_mode' => 'default',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_entity_view',
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
                    ),
                'field_meta_description' =>
                    array (
                        'weight' => 8,
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
                'field_meta_title' =>
                    array (
                        'weight' => 7,
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
                'field_metatags' =>
                    array (
                        'weight' => 9,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                    ),
                'field_partner' =>
                    array (
                        'weight' => 10,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                    ),
                'field_start_date' =>
                    array (
                        'weight' => 11,
                        'label' => 'hidden',
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
                'field_subhome' =>
                    array (
                        'weight' => 13,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                    ),
                'links' =>
                    array (
                        'weight' => 1,
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
                'field_display_title' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    ));
$config_group->save(TRUE);