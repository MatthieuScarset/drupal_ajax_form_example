<?php


use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;



//========================== BLOG POST ==========================//

$field_storage = FieldStorageConfig::loadByName('node', 'field_insight');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$field = FieldConfig::loadByName('node', 'blog_post', 'field_insight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_insight',
        'entity_type' => 'node',
        'bundle' => 'blog_post',
        'label' => 'Insight',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_insight');
$config_group->setData(
    array (
        'uuid' => '5df06fa5-e18e-49e0-9384-9bd09c56bdaa',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_insight',
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_insight', array (
    'label' => 'Eclairages',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_insight');
$config_group->setData(
    array (
        'uuid' => 'f5b83293-033d-4409-a7d4-249127de4881',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_insight',
                        1 => 'node.type.blog_post',
                        2 => 'taxonomy.vocabulary.thematic',
                    ),
            ),
        'id' => 'node.blog_post.field_insight',
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'bundle' => 'blog_post',
        'label' => 'Insight',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'thematic' => 'thematic',
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
$config_group = $config_factory->getEditable('core.entity_form_display.node.blog_post.default');
$config_group->setData(
    array (
        'uuid' => '7783f827-dedc-4463-b4b9-3a3cf835ef89',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.blog_post.field_blog_format',
                        2 => 'field.field.node.blog_post.field_blog_thematic',
                        3 => 'field.field.node.blog_post.field_content',
                        4 => 'field.field.node.blog_post.field_content_owner',
                        5 => 'field.field.node.blog_post.field_display_title',
                        6 => 'field.field.node.blog_post.field_email_owner',
                        7 => 'field.field.node.blog_post.field_end_date',
                        8 => 'field.field.node.blog_post.field_highlight',
                        9 => 'field.field.node.blog_post.field_industry',
                        10 => 'field.field.node.blog_post.field_insight',
                        11 => 'field.field.node.blog_post.field_job_profile',
                        12 => 'field.field.node.blog_post.field_meta_description',
                        13 => 'field.field.node.blog_post.field_meta_title',
                        14 => 'field.field.node.blog_post.field_metatags',
                        15 => 'field.field.node.blog_post.field_profile',
                        16 => 'field.field.node.blog_post.field_region',
                        17 => 'field.field.node.blog_post.field_solution',
                        18 => 'field.field.node.blog_post.field_start_date',
                        19 => 'field.field.node.blog_post.field_subhome',
                        20 => 'field.field.node.blog_post.field_thematic',
                        21 => 'field.field.node.blog_post.field_visual',
                        22 => 'field.field.node.blog_post.publish_date',
                        23 => 'field.field.node.blog_post.unpublish_date',
                        24 => 'node.type.blog_post',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'inline_entity_form',
                        4 => 'metatag',
                        5 => 'path',
                        6 => 'text',
                        7 => 'workbench_moderation',
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
                                        4 => 'field_profile',
                                        5 => 'field_content',
                                        6 => 'field_visual',
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
                                'label' => 'Write',
                            ),
                        'group_classify' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_subhome',
                                        1 => 'field_industry',
                                        2 => 'field_region',
                                        3 => 'field_job_profile',
                                        4 => 'field_blog_thematic',
                                        5 => 'field_blog_format',
                                        6 => 'field_insight',
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
                                'label' => 'Classify',
                            ),
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'group_scheduled_updates',
                                        4 => 'promote',
                                        5 => 'path',
                                        6 => 'field_metatags',
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
                        'group_scheduled_updates' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'publish_date',
                                        1 => 'unpublish_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 15,
                                'format_type' => 'fieldset',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'description' => '',
                                        'required_fields' => false,
                                    ),
                                'label' => 'Scheduled Updates',
                            ),
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.blog_post.default',
        'targetEntityType' => 'node',
        'bundle' => 'blog_post',
        'mode' => 'default',
        'content' =>
            array (
                'field_blog_format' =>
                    array (
                        'type' => 'options_select',
                        'weight' => 31,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_blog_thematic' =>
                    array (
                        'type' => 'options_select',
                        'weight' => 30,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
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
                        'weight' => 15,
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
                'field_insight' =>
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
                'field_job_profile' =>
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
                'field_profile' =>
                    array (
                        'weight' => 7,
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
                        'region' => 'content',
                    ),
                'field_region' =>
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
                        'weight' => 14,
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
                'field_visual' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
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
                'publish_date' =>
                    array (
                        'type' => 'inline_entity_form_complex',
                        'weight' => 11,
                        'settings' =>
                            array (
                                'override_labels' => true,
                                'label_singular' => 'Publish date',
                                'label_plural' => 'Publish dates',
                                'allow_new' => true,
                                'match_operator' => 'CONTAINS',
                                'allow_existing' => false,
                                'form_mode' => 'default',
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
                'unpublish_date' =>
                    array (
                        'type' => 'inline_entity_form_complex',
                        'weight' => 12,
                        'settings' =>
                            array (
                                'override_labels' => true,
                                'label_singular' => 'Unpublish Date',
                                'label_plural' => 'Unpublish Dates',
                                'allow_new' => true,
                                'match_operator' => 'CONTAINS',
                                'allow_existing' => false,
                                'form_mode' => 'default',
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
                'field_solution' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_group->setData(
    array (
        'uuid' => 'a9af707b-c593-4e61-9d22-a86271f4e7d7',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.blog_post.field_blog_format',
                        1 => 'field.field.node.blog_post.field_blog_thematic',
                        2 => 'field.field.node.blog_post.field_content',
                        3 => 'field.field.node.blog_post.field_content_owner',
                        4 => 'field.field.node.blog_post.field_display_title',
                        5 => 'field.field.node.blog_post.field_email_owner',
                        6 => 'field.field.node.blog_post.field_end_date',
                        7 => 'field.field.node.blog_post.field_highlight',
                        8 => 'field.field.node.blog_post.field_industry',
                        9 => 'field.field.node.blog_post.field_insight',
                        10 => 'field.field.node.blog_post.field_job_profile',
                        11 => 'field.field.node.blog_post.field_meta_description',
                        12 => 'field.field.node.blog_post.field_meta_title',
                        13 => 'field.field.node.blog_post.field_metatags',
                        14 => 'field.field.node.blog_post.field_profile',
                        15 => 'field.field.node.blog_post.field_region',
                        16 => 'field.field.node.blog_post.field_solution',
                        17 => 'field.field.node.blog_post.field_start_date',
                        18 => 'field.field.node.blog_post.field_subhome',
                        19 => 'field.field.node.blog_post.field_thematic',
                        20 => 'field.field.node.blog_post.field_visual',
                        21 => 'field.field.node.blog_post.publish_date',
                        22 => 'field.field.node.blog_post.unpublish_date',
                        23 => 'node.type.blog_post',
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
                        'region' => 'content',
                    ),
                'field_insight' =>
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
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'field_profile' =>
                    array (
                        'weight' => 10,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => false,
                                'view_mode' => 'teaser',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_entity_view',
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
                        'region' => 'content',
                    ),
                'field_subhome' =>
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
                'field_blog_format' => true,
                'field_blog_thematic' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
                'publish_date' => true,
                'unpublish_date' => true,
            ),
    )
);
$config_group->save(TRUE);

//========================== DOCUMENT ==========================//

$field = FieldConfig::loadByName('node', 'document', 'field_insight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_insight',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Insight',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_insight');
$config_group->setData(
    array (
        'uuid' => 'ce002b9e-b333-4ced-aa1a-fd2ea0b6caa4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_insight',
                        1 => 'node.type.document',
                        2 => 'taxonomy.vocabulary.thematic',
                    ),
            ),
        'id' => 'node.document.field_insight',
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Insight',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'thematic' => 'thematic',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_insight', array (
    'label' => 'Eclairages',
));

$field_storage = FieldStorageConfig::loadByName('node', 'field_document_thematic');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_document_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_document_thematic');
$config_group->setData(
    array (
        'uuid' => 'c173b3f9-bda3-48fb-a7a6-449ca2a1026d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_document_thematic',
        'field_name' => 'field_document_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'document', 'field_document_thematic');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_document_thematic',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Document Thematic',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_document_thematic');
$config_group->setData(
    array (
        'uuid' => 'b12e9cf9-60ba-4cf6-b9aa-7eb8f23fc81a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_document_thematic',
                        1 => 'node.type.document',
                        2 => 'taxonomy.vocabulary.document_thematics',
                    ),
            ),
        'id' => 'node.document.field_document_thematic',
        'field_name' => 'field_document_thematic',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Document Thematic',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'document_thematics' => 'document_thematics',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_document_thematic', array (
    'label' => 'Thème Document',
));



// ***** FIELD_DOCUMENT_TYPE

$field_storage = FieldStorageConfig::loadByName('node', 'field_document_type');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_document_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_document_type');
$config_group->setData(
    array (
        'uuid' => 'd72f5e85-f5a0-49f9-bdaa-1635d71def1a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_document_type',
        'field_name' => 'field_document_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'document', 'field_document_type');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_document_type',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Document Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_document_type');
$config_group->setData(
    array (
        'uuid' => '9a8e1e34-dff7-48e1-8300-3a2ca11d9290',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_document_type',
                        1 => 'node.type.document',
                        2 => 'taxonomy.vocabulary.document_types',
                    ),
                'content' =>
                    array (
                        0 => 'taxonomy_term:document_types:e83a2ebe-9dc8-48e9-8f87-3e0eb784e748',
                    ),
            ),
        'id' => 'node.document.field_document_type',
        'field_name' => 'field_document_type',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Document Type',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
                0 =>
                    array (
                        'target_uuid' => 'e83a2ebe-9dc8-48e9-8f87-3e0eb784e748',
                    ),
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'document_types' => 'document_types',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_document_thematic', array (
    'label' => 'Format Document',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.document.default');
$config_group->setData(
    array (
        'uuid' => '7ab655ee-4a3b-4eaf-b035-2bf9eb907aa6',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.document.field_blog_thematic',
                        2 => 'field.field.node.document.field_content',
                        3 => 'field.field.node.document.field_content_owner',
                        4 => 'field.field.node.document.field_display_title',
                        5 => 'field.field.node.document.field_document_thematic',
                        6 => 'field.field.node.document.field_document_type',
                        7 => 'field.field.node.document.field_email_owner',
                        8 => 'field.field.node.document.field_end_date',
                        9 => 'field.field.node.document.field_file',
                        10 => 'field.field.node.document.field_highlight',
                        11 => 'field.field.node.document.field_industry',
                        12 => 'field.field.node.document.field_insight',
                        13 => 'field.field.node.document.field_job_profile',
                        14 => 'field.field.node.document.field_meta_description',
                        15 => 'field.field.node.document.field_meta_title',
                        16 => 'field.field.node.document.field_metatags',
                        17 => 'field.field.node.document.field_region',
                        18 => 'field.field.node.document.field_solution',
                        19 => 'field.field.node.document.field_start_date',
                        20 => 'field.field.node.document.field_subhome',
                        21 => 'field.field.node.document.field_thematic',
                        22 => 'field.field.node.document.field_visual',
                        23 => 'node.type.document',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
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
                                        4 => 'field_visual',
                                        5 => 'field_file',
                                        6 => 'field_content',
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
                                        0 => 'field_subhome',
                                        1 => 'field_document_type',
                                        2 => 'field_industry',
                                        3 => 'field_solution',
                                        4 => 'field_region',
                                        5 => 'field_job_profile',
                                        6 => 'field_document_thematic',
                                        7 => 'field_insight',
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
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
                                        5 => 'field_metatags',
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
                                'weight' => 48,
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.document.default',
        'targetEntityType' => 'node',
        'bundle' => 'document',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 10,
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
                        'weight' => 46,
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
                                'display_label' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_document_thematic' =>
                    array (
                        'weight' => 58,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_document_type' =>
                    array (
                        'weight' => 52,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_email_owner' =>
                    array (
                        'weight' => 47,
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
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
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
                        'weight' => 53,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_insight' =>
                    array (
                        'weight' => 59,
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
                        'weight' => 56,
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
                        'weight' => 6,
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
                        'weight' => 5,
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
                        'weight' => 51,
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
                        'weight' => 55,
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
                        'weight' => 54,
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
                        'weight' => 33,
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
                        'weight' => 51,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_visual' =>
                    array (
                        'weight' => 8,
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
                        'weight' => 50,
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
                        'weight' => 49,
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
                'field_blog_thematic' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.default');
$config_group->setData(
    array (
        'uuid' => '855ef887-55de-4173-9570-b12dbd575669',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.document.field_blog_thematic',
                        1 => 'field.field.node.document.field_content',
                        2 => 'field.field.node.document.field_content_owner',
                        3 => 'field.field.node.document.field_display_title',
                        4 => 'field.field.node.document.field_document_thematic',
                        5 => 'field.field.node.document.field_document_type',
                        6 => 'field.field.node.document.field_email_owner',
                        7 => 'field.field.node.document.field_end_date',
                        8 => 'field.field.node.document.field_file',
                        9 => 'field.field.node.document.field_highlight',
                        10 => 'field.field.node.document.field_industry',
                        11 => 'field.field.node.document.field_insight',
                        12 => 'field.field.node.document.field_job_profile',
                        13 => 'field.field.node.document.field_meta_description',
                        14 => 'field.field.node.document.field_meta_title',
                        15 => 'field.field.node.document.field_metatags',
                        16 => 'field.field.node.document.field_region',
                        17 => 'field.field.node.document.field_solution',
                        18 => 'field.field.node.document.field_start_date',
                        19 => 'field.field.node.document.field_subhome',
                        20 => 'field.field.node.document.field_thematic',
                        21 => 'field.field.node.document.field_visual',
                        22 => 'node.type.document',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'metatag',
                        2 => 'text',
                        3 => 'user',
                    ),
            ),
        'id' => 'node.document.default',
        'targetEntityType' => 'node',
        'bundle' => 'document',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 9,
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
                'field_document_thematic' =>
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
                        'region' => 'content',
                    ),
                'field_document_type' =>
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
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 2,
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
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 4,
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
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 10,
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
                'field_insight' =>
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
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'field_solution' =>
                    array (
                        'weight' => 6,
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
                        'region' => 'content',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 8,
                        'region' => 'content',
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'document_visual',
                                'link' => false,
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
                'field_blog_thematic' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



//========================== PARTNER ==========================//


// ***** FIELD_GEOGRAPHIC

$field_storage = FieldStorageConfig::loadByName('node', 'field_geographic');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_geographic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_geographic');
$config_group->setData(
    array (
        'uuid' => 'c0b4520b-240f-4a3d-974f-084da217883c',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_geographic',
        'field_name' => 'field_geographic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'partner', 'field_geographic');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_geographic',
        'entity_type' => 'node',
        'bundle' => 'partner',
        'label' => 'Geographic',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_geographic');
$config_group->setData(
    array (
        'uuid' => 'c6cad089-27c3-4795-a8cd-0ef58da21963',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_geographic',
                        1 => 'node.type.partner',
                        2 => 'taxonomy.vocabulary.geographics',
                    ),
            ),
        'id' => 'node.partner.field_geographic',
        'field_name' => 'field_geographic',
        'entity_type' => 'node',
        'bundle' => 'partner',
        'label' => 'Geographic',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'geographics' => 'geographics',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.partner.field_geographic', array (
    'label' => 'Géographie',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.partner.default');
$config_group->setData(
    array (
        'uuid' => 'd204eff1-4049-4d05-97a3-10f4f436a154',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.partner.field_content',
                        2 => 'field.field.node.partner.field_content_owner',
                        3 => 'field.field.node.partner.field_display_title',
                        4 => 'field.field.node.partner.field_email_owner',
                        5 => 'field.field.node.partner.field_end_date',
                        6 => 'field.field.node.partner.field_file',
                        7 => 'field.field.node.partner.field_geographic',
                        8 => 'field.field.node.partner.field_highlight',
                        9 => 'field.field.node.partner.field_industry',
                        10 => 'field.field.node.partner.field_meta_description',
                        11 => 'field.field.node.partner.field_meta_title',
                        12 => 'field.field.node.partner.field_metatags',
                        13 => 'field.field.node.partner.field_partner_type',
                        14 => 'field.field.node.partner.field_region',
                        15 => 'field.field.node.partner.field_solution',
                        16 => 'field.field.node.partner.field_start_date',
                        17 => 'field.field.node.partner.field_subhome',
                        18 => 'field.field.node.partner.field_thematic',
                        19 => 'field.field.node.partner.field_visual',
                        20 => 'node.type.partner',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
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
                                        5 => 'field_visual',
                                        6 => 'field_file',
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
                                        0 => 'field_subhome',
                                        1 => 'field_solution',
                                        2 => 'field_partner_type',
                                        3 => 'field_geographic',
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
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
                                        5 => 'field_metatags',
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
                                'weight' => 36,
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
                                'label' => 'SEO',
                            ),
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
                        'weight' => 34,
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
                        'weight' => 35,
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
                        'weight' => 43,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 10,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
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
                'field_geographic' =>
                    array (
                        'weight' => 47,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
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
                'field_meta_description' =>
                    array (
                        'weight' => 6,
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
                        'weight' => 5,
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
                        'weight' => 39,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_partner_type' =>
                    array (
                        'weight' => 46,
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
                        'weight' => 45,
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
                        'weight' => 42,
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
                        'weight' => 44,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
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
                        'weight' => 38,
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
                        'weight' => 37,
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
                'field_industry' => true,
                'field_region' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

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
                        6 => 'field.field.node.partner.field_geographic',
                        7 => 'field.field.node.partner.field_highlight',
                        8 => 'field.field.node.partner.field_industry',
                        9 => 'field.field.node.partner.field_meta_description',
                        10 => 'field.field.node.partner.field_meta_title',
                        11 => 'field.field.node.partner.field_metatags',
                        12 => 'field.field.node.partner.field_partner_type',
                        13 => 'field.field.node.partner.field_region',
                        14 => 'field.field.node.partner.field_solution',
                        15 => 'field.field.node.partner.field_start_date',
                        16 => 'field.field.node.partner.field_subhome',
                        17 => 'field.field.node.partner.field_thematic',
                        18 => 'field.field.node.partner.field_visual',
                        19 => 'node.type.partner',
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
                'field_end_date' =>
                    array (
                        'weight' => 7,
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
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 4,
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
                        'region' => 'content',
                    ),
                'field_geographic' =>
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
                'field_metatags' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                        'region' => 'content',
                    ),
                'field_start_date' =>
                    array (
                        'weight' => 6,
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
                'field_industry' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_partner_type' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);


//========================== CUSTOMER STORY ==========================//

// ajout de field_country


$field_storage = FieldStorageConfig::loadByName('node', 'field_country');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_country',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
$field = FieldConfig::loadByName('node', 'customer_story', 'field_country');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_country',
        'entity_type' => 'node',
        'bundle' => 'customer_story',
        'label' => 'Country',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_country');
$config_group->setData(
    array (
        'uuid' => 'b77ce485-e04b-42da-965c-1f55397e177d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_country',
                        1 => 'node.type.customer_story',
                    ),
            ),
        'id' => 'node.customer_story.field_country',
        'field_name' => 'field_country',
        'entity_type' => 'node',
        'bundle' => 'customer_story',
        'label' => 'Country',
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
    )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.customer_story.field_country', array (
    'label' => 'Pays',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.customer_story.default');
$config_group->setData(
    array (
        'uuid' => 'bb4b4a01-bc65-4bec-89db-f4a29247e519',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.customer_story.field_content',
                        2 => 'field.field.node.customer_story.field_content_owner',
                        3 => 'field.field.node.customer_story.field_country',
                        4 => 'field.field.node.customer_story.field_display_title',
                        5 => 'field.field.node.customer_story.field_email_owner',
                        6 => 'field.field.node.customer_story.field_end_date',
                        7 => 'field.field.node.customer_story.field_file',
                        8 => 'field.field.node.customer_story.field_highlight',
                        9 => 'field.field.node.customer_story.field_industry',
                        10 => 'field.field.node.customer_story.field_job_profile',
                        11 => 'field.field.node.customer_story.field_meta_description',
                        12 => 'field.field.node.customer_story.field_meta_title',
                        13 => 'field.field.node.customer_story.field_metatags',
                        14 => 'field.field.node.customer_story.field_region',
                        15 => 'field.field.node.customer_story.field_solution',
                        16 => 'field.field.node.customer_story.field_start_date',
                        17 => 'field.field.node.customer_story.field_subhome',
                        18 => 'field.field.node.customer_story.field_thematic',
                        19 => 'field.field.node.customer_story.field_visual',
                        20 => 'node.type.customer_story',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
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
                                        5 => 'field_file',
                                        6 => 'field_visual',
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
                                        0 => 'field_subhome',
                                        1 => 'field_solution',
                                        2 => 'field_industry',
                                        3 => 'field_region',
                                        4 => 'field_country',
                                        5 => 'field_job_profile',
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
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
                                        5 => 'field_metatags',
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
                                'weight' => 36,
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.customer_story.default',
        'targetEntityType' => 'node',
        'bundle' => 'customer_story',
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
                        'weight' => 34,
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
                'field_country' =>
                    array (
                        'weight' => 51,
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
                        'weight' => 35,
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
                        'weight' => 46,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 9,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
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
                        'weight' => 49,
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
                        'weight' => 52,
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
                        'weight' => 6,
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
                        'weight' => 5,
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
                        'weight' => 39,
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
                        'weight' => 50,
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
                        'weight' => 48,
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
                        'weight' => 45,
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
                        'weight' => 47,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'weight' => 10,
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
                        'weight' => 38,
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
                        'weight' => 37,
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
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.default');
$config_group->setData(
    array (
        'uuid' => '1ae6166d-5e49-4e9a-8e10-c6ed03d293f9',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.customer_story.field_content',
                        1 => 'field.field.node.customer_story.field_content_owner',
                        2 => 'field.field.node.customer_story.field_country',
                        3 => 'field.field.node.customer_story.field_display_title',
                        4 => 'field.field.node.customer_story.field_email_owner',
                        5 => 'field.field.node.customer_story.field_end_date',
                        6 => 'field.field.node.customer_story.field_file',
                        7 => 'field.field.node.customer_story.field_highlight',
                        8 => 'field.field.node.customer_story.field_industry',
                        9 => 'field.field.node.customer_story.field_job_profile',
                        10 => 'field.field.node.customer_story.field_meta_description',
                        11 => 'field.field.node.customer_story.field_meta_title',
                        12 => 'field.field.node.customer_story.field_metatags',
                        13 => 'field.field.node.customer_story.field_region',
                        14 => 'field.field.node.customer_story.field_solution',
                        15 => 'field.field.node.customer_story.field_start_date',
                        16 => 'field.field.node.customer_story.field_subhome',
                        17 => 'field.field.node.customer_story.field_thematic',
                        18 => 'field.field.node.customer_story.field_visual',
                        19 => 'node.type.customer_story',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'metatag',
                        2 => 'text',
                        3 => 'user',
                    ),
            ),
        'id' => 'node.customer_story.default',
        'targetEntityType' => 'node',
        'bundle' => 'customer_story',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 4,
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
                'field_country' =>
                    array (
                        'weight' => 10,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 9,
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
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 3,
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
                        'weight' => 6,
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
                'field_start_date' =>
                    array (
                        'weight' => 8,
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
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



//========================== PRESS RELEASE ==========================//

// **** FIELD_PRESS_TYPE

$field_storage = FieldStorageConfig::loadByName('node', 'field_press_type');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_press_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_press_type');
$config_group->setData(
    array (
        'uuid' => 'a06ca612-6342-43f9-84fa-badc53f2ca6b',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_press_type',
        'field_name' => 'field_press_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'press_release', 'field_press_type');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_press_type',
        'entity_type' => 'node',
        'bundle' => 'press_release',
        'label' => 'Press Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_press_type');
$config_group->setData(
    array (
        'uuid' => 'd03687fd-e57a-4eb5-94da-c43b515f51c0',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_press_type',
                        1 => 'node.type.press_release',
                        2 => 'taxonomy.vocabulary.press_formats',
                    ),
            ),
        'id' => 'node.press_release.field_press_type',
        'field_name' => 'field_press_type',
        'entity_type' => 'node',
        'bundle' => 'press_release',
        'label' => 'Press Type',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'press_formats' => 'press_formats',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_release.field_press_type', array (
    'label' => 'Format Presse',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.press_release.default');
$config_group->setData(
    array (
        'uuid' => '1d69e062-13cb-4327-97c1-60a867ef8d3f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.press_release.field_city',
                        2 => 'field.field.node.press_release.field_content',
                        3 => 'field.field.node.press_release.field_content_owner',
                        4 => 'field.field.node.press_release.field_country',
                        5 => 'field.field.node.press_release.field_display_title',
                        6 => 'field.field.node.press_release.field_email_owner',
                        7 => 'field.field.node.press_release.field_end_date',
                        8 => 'field.field.node.press_release.field_file',
                        9 => 'field.field.node.press_release.field_highlight',
                        10 => 'field.field.node.press_release.field_industry',
                        11 => 'field.field.node.press_release.field_job_profile',
                        12 => 'field.field.node.press_release.field_meta_description',
                        13 => 'field.field.node.press_release.field_meta_title',
                        14 => 'field.field.node.press_release.field_metatags',
                        15 => 'field.field.node.press_release.field_press_type',
                        16 => 'field.field.node.press_release.field_region',
                        17 => 'field.field.node.press_release.field_solution',
                        18 => 'field.field.node.press_release.field_start_date',
                        19 => 'field.field.node.press_release.field_subhome',
                        20 => 'field.field.node.press_release.field_thematic',
                        21 => 'field.field.node.press_release.field_visual',
                        22 => 'node.type.press_release',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
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
                                        4 => 'field_country',
                                        5 => 'field_city',
                                        6 => 'field_content',
                                        7 => 'field_visual',
                                        8 => 'field_file',
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
                                        0 => 'field_subhome',
                                        1 => 'field_solution',
                                        2 => 'field_press_type',
                                        3 => 'field_industry',
                                        4 => 'field_region',
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
                        'group_content_worthy_period' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 37,
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
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'field_metatags',
                                        5 => 'path',
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.press_release.default',
        'targetEntityType' => 'node',
        'bundle' => 'press_release',
        'mode' => 'default',
        'content' =>
            array (
                'field_city' =>
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
                'field_content' =>
                    array (
                        'weight' => 10,
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
                        'weight' => 35,
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
                'field_country' =>
                    array (
                        'weight' => 8,
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
                        'weight' => 36,
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
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 12,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
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
                        'weight' => 51,
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
                        'weight' => 6,
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
                        'weight' => 5,
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
                        'weight' => 39,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_press_type' =>
                    array (
                        'weight' => 50,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 52,
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
                        'weight' => 49,
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
                        'weight' => 33,
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
                        'weight' => 48,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_visual' =>
                    array (
                        'weight' => 11,
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
                        'weight' => 40,
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
                        'weight' => 38,
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
                'field_job_profile' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.default');
$config_group->setData(
    array (
        'uuid' => '8a990e68-44cc-4820-9d3f-0f6aace3d1d5',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.press_release.field_city',
                        1 => 'field.field.node.press_release.field_content',
                        2 => 'field.field.node.press_release.field_content_owner',
                        3 => 'field.field.node.press_release.field_country',
                        4 => 'field.field.node.press_release.field_display_title',
                        5 => 'field.field.node.press_release.field_email_owner',
                        6 => 'field.field.node.press_release.field_end_date',
                        7 => 'field.field.node.press_release.field_file',
                        8 => 'field.field.node.press_release.field_highlight',
                        9 => 'field.field.node.press_release.field_industry',
                        10 => 'field.field.node.press_release.field_job_profile',
                        11 => 'field.field.node.press_release.field_meta_description',
                        12 => 'field.field.node.press_release.field_meta_title',
                        13 => 'field.field.node.press_release.field_metatags',
                        14 => 'field.field.node.press_release.field_press_type',
                        15 => 'field.field.node.press_release.field_region',
                        16 => 'field.field.node.press_release.field_solution',
                        17 => 'field.field.node.press_release.field_start_date',
                        18 => 'field.field.node.press_release.field_subhome',
                        19 => 'field.field.node.press_release.field_thematic',
                        20 => 'field.field.node.press_release.field_visual',
                        21 => 'node.type.press_release',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'metatag',
                        2 => 'text',
                        3 => 'user',
                    ),
            ),
        'id' => 'node.press_release.default',
        'targetEntityType' => 'node',
        'bundle' => 'press_release',
        'mode' => 'default',
        'content' =>
            array (
                'field_city' =>
                    array (
                        'weight' => 10,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
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
                        'region' => 'content',
                    ),
                'field_country' =>
                    array (
                        'weight' => 11,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 2,
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
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 7,
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
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 5,
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
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                        'region' => 'content',
                    ),
                'field_press_type' =>
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
                        'region' => 'content',
                    ),
                'field_solution' =>
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
                        'region' => 'content',
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
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);


//========================== PRESS KIT ==========================//

$field = FieldConfig::loadByName('node', 'press_kit', 'field_press_type');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_press_type',
        'entity_type' => 'node',
        'bundle' => 'press_kit',
        'label' => 'Press Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_press_type');
$config_group->setData(
    array (
        'uuid' => 'f66cff78-ddb6-4a17-85ab-e0edd06e5c8c',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_press_type',
                        1 => 'node.type.press_kit',
                        2 => 'taxonomy.vocabulary.press_formats',
                    ),
            ),
        'id' => 'node.press_kit.field_press_type',
        'field_name' => 'field_press_type',
        'entity_type' => 'node',
        'bundle' => 'press_kit',
        'label' => 'Press Type',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'press_formats' => 'press_formats',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_kit.field_press_type', array (
    'label' => 'Format Presse',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.press_kit.default');
$config_group->setData(
    array (
        'uuid' => 'ee2da6c7-133d-4053-9d40-700af376c614',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.press_kit.field_content',
                        2 => 'field.field.node.press_kit.field_content_owner',
                        3 => 'field.field.node.press_kit.field_display_title',
                        4 => 'field.field.node.press_kit.field_email_owner',
                        5 => 'field.field.node.press_kit.field_end_date',
                        6 => 'field.field.node.press_kit.field_file',
                        7 => 'field.field.node.press_kit.field_highlight',
                        8 => 'field.field.node.press_kit.field_industry',
                        9 => 'field.field.node.press_kit.field_job_profile',
                        10 => 'field.field.node.press_kit.field_meta_description',
                        11 => 'field.field.node.press_kit.field_meta_title',
                        12 => 'field.field.node.press_kit.field_metatags',
                        13 => 'field.field.node.press_kit.field_press_type',
                        14 => 'field.field.node.press_kit.field_region',
                        15 => 'field.field.node.press_kit.field_solution',
                        16 => 'field.field.node.press_kit.field_start_date',
                        17 => 'field.field.node.press_kit.field_subhome',
                        18 => 'field.field.node.press_kit.field_thematic',
                        19 => 'field.field.node.press_kit.field_visual',
                        20 => 'node.type.press_kit',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
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
                                        5 => 'field_visual',
                                        6 => 'field_file',
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
                                        0 => 'field_subhome',
                                        1 => 'field_industry',
                                        2 => 'field_solution',
                                        3 => 'field_press_type',
                                        4 => 'field_region',
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
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'promote',
                                        4 => 'path',
                                        5 => 'field_metatags',
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
                                'weight' => 43,
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.press_kit.default',
        'targetEntityType' => 'node',
        'bundle' => 'press_kit',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 27,
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
                        'weight' => 41,
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
                        'weight' => 23,
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
                        'weight' => 42,
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
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 29,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
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
                'field_highlight' =>
                    array (
                        'weight' => 25,
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
                        'weight' => 49,
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
                        'weight' => 25,
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
                        'weight' => 24,
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
                        'weight' => 46,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_press_type' =>
                    array (
                        'weight' => 51,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 53,
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
                        'weight' => 50,
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
                        'weight' => 33,
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
                        'weight' => 48,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_visual' =>
                    array (
                        'weight' => 28,
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
                        'weight' => 21,
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
                        'weight' => 45,
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
                        'weight' => 44,
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
                        'weight' => 22,
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
                'field_job_profile' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.default');
$config_group->setData(
    array (
        'uuid' => '39c4ab04-daea-4a21-94d8-a1639f76c645',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.press_kit.field_content',
                        1 => 'field.field.node.press_kit.field_content_owner',
                        2 => 'field.field.node.press_kit.field_display_title',
                        3 => 'field.field.node.press_kit.field_email_owner',
                        4 => 'field.field.node.press_kit.field_end_date',
                        5 => 'field.field.node.press_kit.field_file',
                        6 => 'field.field.node.press_kit.field_highlight',
                        7 => 'field.field.node.press_kit.field_industry',
                        8 => 'field.field.node.press_kit.field_job_profile',
                        9 => 'field.field.node.press_kit.field_meta_description',
                        10 => 'field.field.node.press_kit.field_meta_title',
                        11 => 'field.field.node.press_kit.field_metatags',
                        12 => 'field.field.node.press_kit.field_press_type',
                        13 => 'field.field.node.press_kit.field_region',
                        14 => 'field.field.node.press_kit.field_solution',
                        15 => 'field.field.node.press_kit.field_start_date',
                        16 => 'field.field.node.press_kit.field_subhome',
                        17 => 'field.field.node.press_kit.field_thematic',
                        18 => 'field.field.node.press_kit.field_visual',
                        19 => 'node.type.press_kit',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'metatag',
                        2 => 'text',
                        3 => 'user',
                    ),
            ),
        'id' => 'node.press_kit.default',
        'targetEntityType' => 'node',
        'bundle' => 'press_kit',
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
                'field_end_date' =>
                    array (
                        'weight' => 2,
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
                        'region' => 'content',
                    ),
                'field_file' =>
                    array (
                        'weight' => 4,
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
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 7,
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
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                        'region' => 'content',
                    ),
                'field_press_type' =>
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
                        'region' => 'content',
                    ),
                'field_solution' =>
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
                        'region' => 'content',
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
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);




//========================== MAGAZINE ==========================//

// ******* field_magazine_thematic

$field_storage = FieldStorageConfig::loadByName('node', 'field_magazine_thematic');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_magazine_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_magazine_thematic');
$config_group->setData(
    array (
        'uuid' => 'a5a4e421-5754-45a2-8200-ee62571a53ba',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_magazine_thematic',
        'field_name' => 'field_magazine_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'magazine', 'field_magazine_thematic');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_magazine_thematic',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Magazine Thematic',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_magazine_thematic');
$config_group->setData(
    array (
        'uuid' => '7d7607c5-0e63-4865-9a97-6e19073fabbf',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_magazine_thematic',
                        1 => 'node.type.magazine',
                        2 => 'taxonomy.vocabulary.magazine_thematics',
                    ),
            ),
        'id' => 'node.magazine.field_magazine_thematic',
        'field_name' => 'field_magazine_thematic',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Magazine Thematic',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'magazine_thematics' => 'magazine_thematics',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_magazine_thematic', array (
    'label' => 'Thème Magazine',
));

// ******* field_magazine_type

$field_storage = FieldStorageConfig::loadByName('node', 'field_magazine_type');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_magazine_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_magazine_type');
$config_group->setData(
    array (
        'uuid' => '1ffb439a-dee1-463d-ae84-3bfe23c63dd4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                    ),
            ),
        'id' => 'node.field_magazine_type',
        'field_name' => 'field_magazine_type',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'magazine', 'field_magazine_type');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_magazine_type',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Magazine Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_magazine_type');
$config_group->setData(
    array (
        'uuid' => 'ab16310c-dc4e-4aab-a47b-f377fc2f83c5',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_magazine_type',
                        1 => 'node.type.magazine',
                        2 => 'taxonomy.vocabulary.magazine_types',
                    ),
            ),
        'id' => 'node.magazine.field_magazine_type',
        'field_name' => 'field_magazine_type',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Magazine Type',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'magazine_types' => 'magazine_types',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_magazine_type', array (
    'label' => 'Format Magazine',
));


$field = FieldConfig::loadByName('node', 'magazine', 'field_insight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_insight',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Insight',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_insight');
$config_group->setData(
    array (
        'uuid' => '2cd3ba5d-bffe-40c5-b63b-4061b8882654',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_insight',
                        1 => 'node.type.magazine',
                        2 => 'taxonomy.vocabulary.thematic',
                    ),
            ),
        'id' => 'node.magazine.field_insight',
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Insight',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'thematic' => 'thematic',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_insight', array (
    'label' => 'Eclairages',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.magazine.default');
$config_group->setData(
    array (
        'uuid' => '16d663a1-82ed-4352-aa5e-4a1be3ab230a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.magazine.field_blog_format',
                        2 => 'field.field.node.magazine.field_blog_thematic',
                        3 => 'field.field.node.magazine.field_content',
                        4 => 'field.field.node.magazine.field_content_owner',
                        5 => 'field.field.node.magazine.field_display_title',
                        6 => 'field.field.node.magazine.field_email_owner',
                        7 => 'field.field.node.magazine.field_end_date',
                        8 => 'field.field.node.magazine.field_highlight',
                        9 => 'field.field.node.magazine.field_industry',
                        10 => 'field.field.node.magazine.field_insight',
                        11 => 'field.field.node.magazine.field_job_profile',
                        12 => 'field.field.node.magazine.field_magazine_thematic',
                        13 => 'field.field.node.magazine.field_magazine_type',
                        14 => 'field.field.node.magazine.field_meta_description',
                        15 => 'field.field.node.magazine.field_meta_title',
                        16 => 'field.field.node.magazine.field_metatags',
                        17 => 'field.field.node.magazine.field_region',
                        18 => 'field.field.node.magazine.field_solution',
                        19 => 'field.field.node.magazine.field_start_date',
                        20 => 'field.field.node.magazine.field_subhome',
                        21 => 'field.field.node.magazine.field_thematic',
                        22 => 'field.field.node.magazine.field_visual',
                        23 => 'node.type.magazine',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_browser',
                        2 => 'field_group',
                        3 => 'metatag',
                        4 => 'path',
                        5 => 'text',
                        6 => 'workbench_moderation',
                    ),
            ),
        'third_party_settings' =>
            array (
                'field_group' =>
                    array (
                        'group_write' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'langcode',
                                        1 => 'title',
                                        2 => 'field_display_title',
                                        3 => 'field_highlight',
                                        4 => 'field_content',
                                        5 => 'field_visual',
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
                                'label' => 'Write',
                            ),
                        'group_classify' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_subhome',
                                        1 => 'field_industry',
                                        2 => 'field_job_profile',
                                        3 => 'field_region',
                                        4 => 'field_insight',
                                        5 => 'field_magazine_thematic',
                                        6 => 'field_magazine_type',
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
                                'weight' => 11,
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
                        'group_content_worthy_period' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 19,
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
                                'label' => 'SEO',
                            ),
                    ),
            ),
        'id' => 'node.magazine.default',
        'targetEntityType' => 'node',
        'bundle' => 'magazine',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
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
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_content_owner' =>
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
                'field_end_date' =>
                    array (
                        'weight' => 14,
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
                'field_insight' =>
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
                'field_job_profile' =>
                    array (
                        'type' => 'options_select',
                        'weight' => 28,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_magazine_thematic' =>
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
                'field_magazine_type' =>
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
                        'weight' => 22,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_partner' =>
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
                'field_region' =>
                    array (
                        'type' => 'options_select',
                        'weight' => 29,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_start_date' =>
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
                'field_visual' =>
                    array (
                        'weight' => 8,
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
                        'weight' => 21,
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
                        'weight' => 20,
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
                'field_blog_format' => true,
                'field_blog_thematic' => true,
                'field_solution' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.default');
$config_group->setData(
    array (
        'uuid' => '6d4e1bbd-d8c2-4b55-9f43-ba29e915ee7c',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.magazine.field_blog_format',
                        1 => 'field.field.node.magazine.field_blog_thematic',
                        2 => 'field.field.node.magazine.field_content',
                        3 => 'field.field.node.magazine.field_content_owner',
                        4 => 'field.field.node.magazine.field_display_title',
                        5 => 'field.field.node.magazine.field_email_owner',
                        6 => 'field.field.node.magazine.field_end_date',
                        7 => 'field.field.node.magazine.field_highlight',
                        8 => 'field.field.node.magazine.field_industry',
                        9 => 'field.field.node.magazine.field_insight',
                        10 => 'field.field.node.magazine.field_job_profile',
                        11 => 'field.field.node.magazine.field_magazine_thematic',
                        12 => 'field.field.node.magazine.field_magazine_type',
                        13 => 'field.field.node.magazine.field_meta_description',
                        14 => 'field.field.node.magazine.field_meta_title',
                        15 => 'field.field.node.magazine.field_metatags',
                        16 => 'field.field.node.magazine.field_region',
                        17 => 'field.field.node.magazine.field_solution',
                        18 => 'field.field.node.magazine.field_start_date',
                        19 => 'field.field.node.magazine.field_subhome',
                        20 => 'field.field.node.magazine.field_thematic',
                        21 => 'field.field.node.magazine.field_visual',
                        22 => 'node.type.magazine',
                    ),
                'module' =>
                    array (
                        0 => 'metatag',
                        1 => 'text',
                        2 => 'user',
                    ),
            ),
        'id' => 'node.magazine.default',
        'targetEntityType' => 'node',
        'bundle' => 'magazine',
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
                'field_insight' =>
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
                        'region' => 'content',
                    ),
                'field_magazine_thematic' =>
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
                        'region' => 'content',
                    ),
                'field_magazine_type' =>
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
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_empty_formatter',
                        'region' => 'content',
                    ),
                'field_partner' =>
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
                'field_blog_format' => true,
                'field_blog_thematic' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);




// ===================== TRADUCTIONS ========================== //

//INDUSTRY - SECTEUR D'ACTIVITE

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.customer_story.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.partner.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_kit.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_release.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.product.field_industry', array (
    'label' => 'Secteur d\'activité',
));

// PROFESSION - METIER

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_job_profile', array (
    'label' => 'Métier',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.customer_story.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_kit.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_release.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.product.field_job_profile', array (
    'label' => 'Métier',
));

// Renommage en Profession sur tous les types de contenus

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_job_profile');
$config_group->setData(
    array (
        'uuid' => 'fb7fb25d-fa69-42f9-a7ba-6ee7919adfb5',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.blog_post',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.blog_post.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'blog_post',
        'label' => 'Profession',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_job_profile');
$config_group->setData(
    array (
        'uuid' => '6af4c92e-c064-48c9-bd76-801a83699df2',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.customer_story',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.customer_story.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'customer_story',
        'label' => 'Profession',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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
$config_group = $config_factory->getEditable('field.field.node.document.field_job_profile');
$config_group->setData(
    array (
        'uuid' => '2a0d1aae-5486-42a2-9006-6736002a3168',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.document',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.document.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'document',
        'label' => 'Profession',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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
$config_group = $config_factory->getEditable('field.field.node.magazine.field_job_profile');
$config_group->setData(
    array (
        'uuid' => 'addec776-ff5b-4755-b64a-8cf7392f953c',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.magazine',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.magazine.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'magazine',
        'label' => 'Profession',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_job_profile');
$config_group->setData(
    array (
        'uuid' => 'b63da216-3a78-44bd-8052-6f1bfeb6b009',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.press_kit',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.press_kit.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'press_kit',
        'label' => 'Profession',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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
$config_group = $config_factory->getEditable('field.field.node.press_release.field_job_profile');
$config_group->setData(
    array (
        'uuid' => '076abf21-842c-4531-873d-b99f754ef9fe',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.press_release',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.press_release.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'press_release',
        'label' => 'Job profile',
        'description' => '',
        'required' => false,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'jobs_profiles' => 'jobs_profiles',
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


// SUBHOME - RUBRIQUE

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_subhome', array (
    'label' => 'Rubrique',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.customer_story.field_subhome', array (
    'label' => 'Rubrique',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_subhome', array (
    'label' => 'Rubrique',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.magazine.field_subhome', array (
    'label' => 'Rubrique',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.partner.field_subhome', array (
    'label' => 'Rubrique',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_kit.field_subhome', array (
    'label' => 'Rubrique',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.press_release.field_subhome', array (
    'label' => 'Rubrique',
));

//BLOG TYPE - FORMAT BLOG et BLOG THEMATIC - THEME BLOG

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_blog_format');
$config_group->setData(
    array (
        'uuid' => '7d5218e0-d512-447c-ad41-522ef5449f30',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_format',
                        1 => 'node.type.blog_post',
                        2 => 'taxonomy.vocabulary.blog_formats',
                    ),
            ),
        'id' => 'node.blog_post.field_blog_format',
        'field_name' => 'field_blog_format',
        'entity_type' => 'node',
        'bundle' => 'blog_post',
        'label' => 'Blog format',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'blog_formats' => 'blog_formats',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_blog_format', array (
    'label' => 'Format blog',
));


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_blog_thematic');
$config_group->setData(
    array (
        'uuid' => '23990e3f-ae0c-4547-9f4a-f443f71ebfdc',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_thematic',
                        1 => 'node.type.blog_post',
                        2 => 'taxonomy.vocabulary.blog_thematics',
                    ),
            ),
        'id' => 'node.blog_post.field_blog_thematic',
        'field_name' => 'field_blog_thematic',
        'entity_type' => 'node',
        'bundle' => 'blog_post',
        'label' => 'Blog thematic',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'blog_thematics' => 'blog_thematics',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.blog_post.field_blog_thematic', array (
    'label' => 'Thème blog',
));

