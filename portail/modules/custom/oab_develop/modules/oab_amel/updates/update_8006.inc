<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.simple_page.default');
$config->setData(
    array ('uuid' => 'bc469387-7cf3-4a8c-b18e-337f96898aa9',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.simple_page.field_area',
                        1 => 'field.field.node.simple_page.field_content',
                        2 => 'field.field.node.simple_page.field_content_owner',
                        3 => 'field.field.node.simple_page.field_customer_story',
                        4 => 'field.field.node.simple_page.field_display_title',
                        5 => 'field.field.node.simple_page.field_email_owner',
                        6 => 'field.field.node.simple_page.field_end_date',
                        7 => 'field.field.node.simple_page.field_grouping_title',
                        8 => 'field.field.node.simple_page.field_highlight',
                        9 => 'field.field.node.simple_page.field_industry',
                        10 => 'field.field.node.simple_page.field_meta_description',
                        11 => 'field.field.node.simple_page.field_meta_title',
                        12 => 'field.field.node.simple_page.field_metatags',
                        13 => 'field.field.node.simple_page.field_partner',
                        14 => 'field.field.node.simple_page.field_solution',
                        15 => 'field.field.node.simple_page.field_start_date',
                        16 => 'field.field.node.simple_page.field_subhome',
                        17 => 'node.type.simple_page',
                    ),
                'module' =>
                    array (
                        0 => 'metatag',
                        1 => 'text',
                        2 => 'user',
                    ),
            ),
        'id' => 'node.simple_page.default',
        'targetEntityType' => 'node',
        'bundle' => 'simple_page',
        'mode' => 'default',
        'content' =>
            array (
                'field_area' =>
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
                    ),
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
                'field_customer_story' =>
                    array (
                        'weight' => 2,
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
                'field_grouping_title' =>
                    array (
                        'weight' => 6,
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
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                    ),
                'field_solution' =>
                    array (
                        'type' => 'entity_reference_label',
                        'weight' => 8,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_subhome' =>
                    array (
                        'weight' => 7,
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
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_highlight' => true,
                'field_industry' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_partner' => true,
                'field_start_date' => true,
                'langcode' => true,
            ),
    ));

$config->save(TRUE);