<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.profile.default');
$config_group->set('content.field_visual', array (
    'weight' => 26,
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
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.default');
$config_group->set(
    'content.field_visual', array (
        'weight' => 110,
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
    'field_first_name', array (
        'weight' => 111,
        'label' => 'hidden',
        'settings' =>
            array (
                'link_to_entity' => false,
            ),
        'third_party_settings' =>
            array (
            ),
        'type' => 'string',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_group->setData(array(
    'uuid' => 'a9af707b-c593-4e61-9d22-a86271f4e7d7',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.field.node.blog_post.field_area',
                    1 => 'field.field.node.blog_post.field_blog',
                    2 => 'field.field.node.blog_post.field_content',
                    3 => 'field.field.node.blog_post.field_content_owner',
                    4 => 'field.field.node.blog_post.field_customer_story',
                    5 => 'field.field.node.blog_post.field_display_title',
                    6 => 'field.field.node.blog_post.field_email_owner',
                    7 => 'field.field.node.blog_post.field_end_date',
                    8 => 'field.field.node.blog_post.field_highlight',
                    9 => 'field.field.node.blog_post.field_industry',
                    10 => 'field.field.node.blog_post.field_meta_description',
                    11 => 'field.field.node.blog_post.field_meta_title',
                    12 => 'field.field.node.blog_post.field_metatags',
                    13 => 'field.field.node.blog_post.field_partner',
                    14 => 'field.field.node.blog_post.field_profile',
                    15 => 'field.field.node.blog_post.field_solution',
                    16 => 'field.field.node.blog_post.field_start_date',
                    17 => 'field.field.node.blog_post.field_subhome',
                    18 => 'field.field.node.blog_post.field_visual',
                    19 => 'field.field.node.blog_post.publish_date',
                    20 => 'field.field.node.blog_post.unpublish_date',
                    21 => 'node.type.blog_post',
                ),
            'module' =>
                array (
                    0 => 'datetime',
                    1 => 'metatag',
                    2 => 'text',
                    3 => 'user',
                ),
        ),
    'id' => 'node.blog_post.default',
    'targetEntityType' => 'node',
    'bundle' => 'blog_post',
    'mode' => 'default',
    'content' =>
        array (
            'field_area' =>
                array (
                    'weight' => 12,
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
            'field_blog' =>
                array (
                    'weight' => 8,
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
                    'weight' => 6,
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
                    'weight' => 9,
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
            'field_end_date' =>
                array (
                    'weight' => 4,
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
            'field_industry' =>
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
            'field_metatags' =>
                array (
                    'weight' => 7,
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
                    'weight' => 11,
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
            'field_profile' =>
                array (
                    'weight' => 14,
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
                ),
            'field_start_date' =>
                array (
                    'weight' => 3,
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
            'field_content_owner' => true,
            'field_display_title' => true,
            'field_email_owner' => true,
            'field_meta_description' => true,
            'field_meta_title' => true,
            'field_visual' => true,
            'langcode' => true,
            'publish_date' => true,
            'unpublish_date' => true,
        ),
));
$config_group->save(TRUE);