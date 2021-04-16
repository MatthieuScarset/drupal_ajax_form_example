<?php


use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;



//========================== PRODUCT AXIOME ==========================//

$field_storage = FieldStorageConfig::loadByName('node', 'field_market_segment');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_market_segment',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_market_segment');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_market_segment',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Market Segment',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_market_segment');
$config_group->setData(
    array (
        'uuid' => '9c86ab2c-cee9-41a9-95e9-e83681d8a4f5',
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
        'id' => 'node.field_market_segment',
        'field_name' => 'field_market_segment',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => -1,
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
$collection->write('field.field.node.product.field_market_segment', array (
    'label' => 'Segment de marché',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_market_segment');
$config_group->setData(
    array (
        'uuid' => '46f2131e-1c35-4142-a8c6-9686d74fe5ec',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_market_segment',
                        1 => 'node.type.product',
                        2 => 'taxonomy.vocabulary.market_segments',
                    ),
            ),
        'id' => 'node.product.field_market_segment',
        'field_name' => 'field_market_segment',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Market Segment',
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
                                'market_segments' => 'market_segments',
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
$config_group = $config_factory->getEditable('field.field.node.product.field_job_profile');
$config_group->setData(
    array (
        'uuid' => 'c6bf1054-176e-4625-8491-ff1d665ad4e8',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.product',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.product.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'product',
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


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.product.field_subhome', array (
    'label' => 'Rubrique',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.product.default');
$config_group->setData(
    array (
        'uuid' => '25a16d28-a765-4ea1-bcc0-dcbd469c1613',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.product.field_axiome_data',
                        2 => 'field.field.node.product.field_content',
                        3 => 'field.field.node.product.field_content_owner',
                        4 => 'field.field.node.product.field_email_owner',
                        5 => 'field.field.node.product.field_end_date',
                        6 => 'field.field.node.product.field_file',
                        7 => 'field.field.node.product.field_highlight',
                        8 => 'field.field.node.product.field_id_fiche',
                        9 => 'field.field.node.product.field_id_offre',
                        10 => 'field.field.node.product.field_industry',
                        11 => 'field.field.node.product.field_job_profile',
                        12 => 'field.field.node.product.field_market_segment',
                        13 => 'field.field.node.product.field_meta_description',
                        14 => 'field.field.node.product.field_meta_title',
                        15 => 'field.field.node.product.field_metatags',
                        16 => 'field.field.node.product.field_region',
                        17 => 'field.field.node.product.field_solution',
                        18 => 'field.field.node.product.field_start_date',
                        19 => 'field.field.node.product.field_sub_family',
                        20 => 'field.field.node.product.field_subhome',
                        21 => 'field.field.node.product.field_top_zone',
                        22 => 'field.field.node.product.field_top_zone_background',
                        23 => 'field.field.node.product.field_visual',
                        24 => 'node.type.product',
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
                                        2 => 'field_highlight',
                                        3 => 'field_top_zone',
                                        4 => 'field_top_zone_background',
                                        5 => 'field_content',
                                        6 => 'field_file',
                                        7 => 'field_visual',
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
                                'label' => 'Write',
                            ),
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_content_owner',
                                        1 => 'field_email_owner',
                                        2 => 'group_content_worthy_period',
                                        3 => 'path',
                                        4 => 'field_metatags',
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
                                'label' => 'SEO',
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
                        'group_classify' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_subhome',
                                        1 => 'field_solution',
                                        2 => 'field_industry',
                                        3 => 'field_region',
                                        4 => 'field_job_profile',
                                        5 => 'field_market_segment',
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
                                'label' => 'Classify',
                            ),
                    ),
            ),
        'id' => 'node.product.default',
        'targetEntityType' => 'node',
        'bundle' => 'product',
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
                        'weight' => 27,
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
                        'weight' => 8,
                        'settings' =>
                            array (
                                'entity_browser' => 'browser_file_modal',
                                'field_widget_display' => 'label',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'open' => false,
                                'field_widget_display_settings' =>
                                    array (
                                    ),
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_browser_entity_reference',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 4,
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
                        'weight' => 36,
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
                        'weight' => 38,
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
                        'weight' => 40,
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
                        'weight' => 14,
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
                        'weight' => 37,
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
                        'weight' => 35,
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
                        'weight' => 26,
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
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_top_zone' =>
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
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_top_zone_background' =>
                    array (
                        'type' => 'entity_browser_entity_reference',
                        'weight' => 6,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'label',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'open' => false,
                                'field_widget_display_settings' =>
                                    array (
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
                                'field_widget_display' => 'label',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'open' => false,
                                'field_widget_display_settings' =>
                                    array (
                                    ),
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
                'field_axiome_data' => true,
                'field_id_fiche' => true,
                'field_id_offre' => true,
                'field_product' => true,
                'field_sub_family' => true,
                'promote' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.product.default');
$config_group->setData(
    array (
        'uuid' => '2836a2b4-4feb-423c-a23c-35e333688957',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.product.field_axiome_data',
                        1 => 'field.field.node.product.field_content',
                        2 => 'field.field.node.product.field_content_owner',
                        3 => 'field.field.node.product.field_email_owner',
                        4 => 'field.field.node.product.field_end_date',
                        5 => 'field.field.node.product.field_file',
                        6 => 'field.field.node.product.field_highlight',
                        7 => 'field.field.node.product.field_id_fiche',
                        8 => 'field.field.node.product.field_id_offre',
                        9 => 'field.field.node.product.field_industry',
                        10 => 'field.field.node.product.field_job_profile',
                        11 => 'field.field.node.product.field_market_segment',
                        12 => 'field.field.node.product.field_meta_description',
                        13 => 'field.field.node.product.field_meta_title',
                        14 => 'field.field.node.product.field_metatags',
                        15 => 'field.field.node.product.field_region',
                        16 => 'field.field.node.product.field_solution',
                        17 => 'field.field.node.product.field_start_date',
                        18 => 'field.field.node.product.field_sub_family',
                        19 => 'field.field.node.product.field_subhome',
                        20 => 'field.field.node.product.field_top_zone',
                        21 => 'field.field.node.product.field_top_zone_background',
                        22 => 'field.field.node.product.field_visual',
                        23 => 'node.type.product',
                    ),
                'module' =>
                    array (
                        0 => 'metatag',
                        1 => 'text',
                        2 => 'user',
                    ),
            ),
        'id' => 'node.product.default',
        'targetEntityType' => 'node',
        'bundle' => 'product',
        'mode' => 'default',
        'content' =>
            array (
                'field_axiome_data' =>
                    array (
                        'weight' => 6,
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
                'field_content_owner' =>
                    array (
                        'weight' => 9,
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
                'field_email_owner' =>
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
                'field_file' =>
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
                'field_market_segment' =>
                    array (
                        'weight' => 11,
                        'label' => 'above',
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
                'field_meta_description' =>
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
                        'region' => 'content',
                    ),
                'field_meta_title' =>
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
                'field_visual' =>
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
                'field_end_date' => true,
                'field_highlight' => true,
                'field_id_fiche' => true,
                'field_id_offre' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_product' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_sub_family' => true,
                'field_subhome' => true,
                'field_top_zone' => true,
                'field_top_zone_background' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);




//========================== SIMPLE PAGE ==========================//

$field_storage = FieldStorageConfig::loadByName('node', 'field_blog_thematic');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_blog_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}

$field = FieldConfig::loadByName('node', 'simple_page', 'field_blog_thematic');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_blog_thematic',
        'entity_type' => 'node',
        'bundle' => 'simple_page',
        'label' => 'Thematic',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_blog_thematic');
$config_group->setData(
    array (
        'uuid' => '34230e52-d735-4c17-b335-529ea2a4ec27',
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
        'id' => 'node.field_blog_thematic',
        'field_name' => 'field_blog_thematic',
        'entity_type' => 'node',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => -1,
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
$collection->write('field.field.node.simple_page.field_blog_thematic', array (
    'label' => 'Thème',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_blog_thematic');
$config_group->setData(
    array (
        'uuid' => '1da4d45c-84fc-444a-84b0-21dcd7f4f7e7',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_thematic',
                        1 => 'node.type.simple_page',
                        2 => 'taxonomy.vocabulary.blog_thematics',
                    ),
            ),
        'id' => 'node.simple_page.field_blog_thematic',
        'field_name' => 'field_blog_thematic',
        'entity_type' => 'node',
        'bundle' => 'simple_page',
        'label' => 'Thematic',
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


$field = FieldConfig::loadByName('node', 'simple_page', 'field_blog_format');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_blog_format',
        'entity_type' => 'node',
        'bundle' => 'simple_page',
        'label' => 'Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.simple_page.field_blog_format', array (
    'label' => 'Format',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_blog_format');
$config_group->setData(
    array (
        'uuid' => '696aa34f-fffb-4a42-b651-f7667b8176c2',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_format',
                        1 => 'node.type.simple_page',
                        2 => 'taxonomy.vocabulary.blog_formats',
                    ),
            ),
        'id' => 'node.simple_page.field_blog_format',
        'field_name' => 'field_blog_format',
        'entity_type' => 'node',
        'bundle' => 'simple_page',
        'label' => 'Type',
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
$collection->write('field.field.node.simple_page.field_subhome', array (
    'label' => 'Rubrique',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.simple_page.field_job_profile', array (
    'label' => 'Métier',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.simple_page.field_industry', array (
    'label' => 'Secteur d\'activité',
));

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
                        0 => 'entity_browser.browser.browse_media_modal',
                        1 => 'field.field.node.simple_page.field_blog_format',
                        2 => 'field.field.node.simple_page.field_blog_thematic',
                        3 => 'field.field.node.simple_page.field_content',
                        4 => 'field.field.node.simple_page.field_content_owner',
                        5 => 'field.field.node.simple_page.field_display_title',
                        6 => 'field.field.node.simple_page.field_email_owner',
                        7 => 'field.field.node.simple_page.field_end_date',
                        8 => 'field.field.node.simple_page.field_grouping_title',
                        9 => 'field.field.node.simple_page.field_highlight',
                        10 => 'field.field.node.simple_page.field_industry',
                        11 => 'field.field.node.simple_page.field_job_profile',
                        12 => 'field.field.node.simple_page.field_meta_description',
                        13 => 'field.field.node.simple_page.field_meta_title',
                        14 => 'field.field.node.simple_page.field_metatags',
                        15 => 'field.field.node.simple_page.field_region',
                        16 => 'field.field.node.simple_page.field_solution',
                        17 => 'field.field.node.simple_page.field_start_date',
                        18 => 'field.field.node.simple_page.field_subhome',
                        19 => 'field.field.node.simple_page.field_thematic',
                        20 => 'field.field.node.simple_page.field_visual',
                        21 => 'node.type.simple_page',
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
                                        3 => 'field_grouping_title',
                                        4 => 'field_highlight',
                                        5 => 'field_content',
                                        6 => 'field_visual',
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
                                        2 => 'field_blog_format',
                                        3 => 'field_blog_thematic',
                                        4 => 'field_solution',
                                        5 => 'field_region',
                                        6 => 'field_job_profile',
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
                'field_blog_format' =>
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
                'field_blog_thematic' =>
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
                'field_content' =>
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
                'field_grouping_title' =>
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
                'field_solution' =>
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
                'field_visual' =>
                    array (
                        'weight' => 7,
                        'settings' =>
                            array (
                                'entity_browser' => 'browse_media_modal',
                                'field_widget_display' => 'label',
                                'field_widget_edit' => true,
                                'field_widget_remove' => true,
                                'selection_mode' => 'selection_append',
                                'open' => false,
                                'field_widget_display_settings' =>
                                    array (
                                    ),
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
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.simple_page.default');
$config_group->setData(
    array (
        'uuid' => 'bc469387-7cf3-4a8c-b18e-337f96898aa9',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.simple_page.field_blog_format',
                        1 => 'field.field.node.simple_page.field_blog_thematic',
                        2 => 'field.field.node.simple_page.field_content',
                        3 => 'field.field.node.simple_page.field_content_owner',
                        4 => 'field.field.node.simple_page.field_display_title',
                        5 => 'field.field.node.simple_page.field_email_owner',
                        6 => 'field.field.node.simple_page.field_end_date',
                        7 => 'field.field.node.simple_page.field_grouping_title',
                        8 => 'field.field.node.simple_page.field_highlight',
                        9 => 'field.field.node.simple_page.field_industry',
                        10 => 'field.field.node.simple_page.field_job_profile',
                        11 => 'field.field.node.simple_page.field_meta_description',
                        12 => 'field.field.node.simple_page.field_meta_title',
                        13 => 'field.field.node.simple_page.field_metatags',
                        14 => 'field.field.node.simple_page.field_region',
                        15 => 'field.field.node.simple_page.field_solution',
                        16 => 'field.field.node.simple_page.field_start_date',
                        17 => 'field.field.node.simple_page.field_subhome',
                        18 => 'field.field.node.simple_page.field_thematic',
                        19 => 'field.field.node.simple_page.field_visual',
                        20 => 'node.type.simple_page',
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
                'field_blog_format' =>
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
                'field_blog_thematic' =>
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
                        'region' => 'content',
                    ),
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
                'field_grouping_title' =>
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
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 2,
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
                        'type' => 'entity_reference_label',
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_region' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'field_thematic' => true,
                'field_visual' => true,
                'langcode' => true,
            ),
    )
);
$config_group->save(TRUE);



//========================== FULL HTML PAGE ==========================//


// Création des champs taxonomies

$field = FieldConfig::loadByName('node', 'full_html', 'field_industry');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_industry',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Industry',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_industry');
$config_group->setData(
    array (
        'uuid' => '49a4d6f7-6d4f-495d-b08c-f1e1304d5abe',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_industry',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.industries',
                    ),
            ),
        'id' => 'node.full_html.field_industry',
        'field_name' => 'field_industry',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Industry',
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
                                'industries' => 'industries',
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
$collection->write('field.field.node.full_html.field_industry', array (
    'label' => 'Secteur d\'activité',
));

$field = FieldConfig::loadByName('node', 'full_html', 'field_insight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_insight',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Insight',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_insight');
$config_group->setData(
    array (
        'uuid' => '74f93c28-5253-491f-aa11-cea4e2cd566b',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_insight',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.thematic',
                    ),
            ),
        'id' => 'node.full_html.field_insight',
        'field_name' => 'field_insight',
        'entity_type' => 'node',
        'bundle' => 'full_html',
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
$collection->write('field.field.node.full_html.field_insight', array (
    'label' => 'Eclairages',
));


$field = FieldConfig::loadByName('node', 'full_html', 'field_job_profile');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Profession',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_job_profile');
$config_group->setData(
    array (
        'uuid' => 'b0b79eb5-4ab8-4124-9d3e-e8e5e1499999',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_job_profile',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.jobs_profiles',
                    ),
            ),
        'id' => 'node.full_html.field_job_profile',
        'field_name' => 'field_job_profile',
        'entity_type' => 'node',
        'bundle' => 'full_html',
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.full_html.field_job_profile', array (
    'label' => 'Métier',
));


$field = FieldConfig::loadByName('node', 'full_html', 'field_region');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_region',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Region',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_region');
$config_group->setData(
    array (
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_region',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.regions',
                    ),
            ),
        'id' => 'node.full_html.field_region',
        'field_name' => 'field_region',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Region',
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
                                'regions' => 'regions',
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
$collection->write('field.field.node.full_html.field_region', array (
    'label' => 'Zone géographique',
));

$field = FieldConfig::loadByName('node', 'full_html', 'field_subhome');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_subhome',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Subhome',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_subhome');
$config_group->setData(
    array (
        'uuid' => '3a20fa0e-4d3b-44a8-900e-c0c60fd6dc62',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_subhome',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.subhomes',
                    ),
            ),
        'id' => 'node.full_html.field_subhome',
        'field_name' => 'field_subhome',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Subhome',
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
                                'subhomes' => 'subhomes',
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
$collection->write('field.field.node.full_html.field_subhome', array (
    'label' => 'Rubrique',
));


$field = FieldConfig::loadByName('node', 'full_html', 'field_blog_thematic');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_blog_thematic',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Thematic',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_blog_thematic');
$config_group->setData(
    array (
        'uuid' => '6e850c90-2352-4fc6-b46e-0640998d8751',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_thematic',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.blog_thematics',
                    ),
            ),
        'id' => 'node.full_html.field_blog_thematic',
        'field_name' => 'field_blog_thematic',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Thematic',
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
$collection->write('field.field.node.full_html.field_blog_thematic', array (
    'label' => 'Thème',
));



$field = FieldConfig::loadByName('node', 'full_html', 'field_blog_format');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_blog_format',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Type',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.full_html.field_blog_format');
$config_group->setData(
    array (
        'uuid' => '9e691a7c-c0c2-4c15-8661-c75f9768f2d4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog_format',
                        1 => 'node.type.full_html',
                        2 => 'taxonomy.vocabulary.blog_formats',
                    ),
            ),
        'id' => 'node.full_html.field_blog_format',
        'field_name' => 'field_blog_format',
        'entity_type' => 'node',
        'bundle' => 'full_html',
        'label' => 'Type',
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
$collection->write('field.field.node.full_html.field_blog_format', array (
    'label' => 'Format',
));


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.full_html.default');
$config_group->setData(
    array (
        'uuid' => '5e5ca55f-26fa-4b50-9cbb-6e0493d853c9',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.full_html.field_blog_format',
                        1 => 'field.field.node.full_html.field_blog_thematic',
                        2 => 'field.field.node.full_html.field_content',
                        3 => 'field.field.node.full_html.field_display_title',
                        4 => 'field.field.node.full_html.field_end_date',
                        5 => 'field.field.node.full_html.field_industry',
                        6 => 'field.field.node.full_html.field_insight',
                        7 => 'field.field.node.full_html.field_job_profile',
                        8 => 'field.field.node.full_html.field_meta_description',
                        9 => 'field.field.node.full_html.field_meta_title',
                        10 => 'field.field.node.full_html.field_metatags',
                        11 => 'field.field.node.full_html.field_region',
                        12 => 'field.field.node.full_html.field_start_date',
                        13 => 'field.field.node.full_html.field_subhome',
                        14 => 'node.type.full_html',
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
                                        2 => 'group_publish',
                                        3 => 'group_seo',
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
                                        3 => 'field_content',
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
                                        1 => 'field_blog_thematic',
                                        2 => 'field_blog_format',
                                        3 => 'field_insight',
                                        4 => 'field_industry',
                                        5 => 'field_region',
                                        6 => 'field_job_profile',
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
                                        0 => 'group_content_worthy_period',
                                        1 => 'promote',
                                        2 => 'path',
                                        3 => 'field_metatags',
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
                                'label' => 'SEO',
                            ),
                        'group_content_worthy_period' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 20,
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
        'id' => 'node.full_html.default',
        'targetEntityType' => 'node',
        'bundle' => 'full_html',
        'mode' => 'default',
        'content' =>
            array (
                'field_blog_format' =>
                    array (
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_blog_thematic' =>
                    array (
                        'weight' => 33,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_content' =>
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
                        'type' => 'text_textarea',
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
                'field_industry' =>
                    array (
                        'weight' => 36,
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
                        'weight' => 35,
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
                        'weight' => 38,
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
                        'weight' => 11,
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
                'field_metatags' =>
                    array (
                        'weight' => 23,
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
                        'weight' => 37,
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
                'field_subhome' =>
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
                        'weight' => 22,
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
                        'weight' => 21,
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
                'translation' =>
                    array (
                        'weight' => 1,
                        'settings' =>
                            array (
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.full_html.default');
$config_group->setData(
    array (
        'uuid' => '446d7370-d30e-4e73-bf4b-4c04d0dbecad',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.full_html.field_blog_format',
                        1 => 'field.field.node.full_html.field_blog_thematic',
                        2 => 'field.field.node.full_html.field_content',
                        3 => 'field.field.node.full_html.field_display_title',
                        4 => 'field.field.node.full_html.field_end_date',
                        5 => 'field.field.node.full_html.field_industry',
                        6 => 'field.field.node.full_html.field_insight',
                        7 => 'field.field.node.full_html.field_job_profile',
                        8 => 'field.field.node.full_html.field_meta_description',
                        9 => 'field.field.node.full_html.field_meta_title',
                        10 => 'field.field.node.full_html.field_metatags',
                        11 => 'field.field.node.full_html.field_region',
                        12 => 'field.field.node.full_html.field_start_date',
                        13 => 'field.field.node.full_html.field_subhome',
                        14 => 'node.type.full_html',
                    ),
                'module' =>
                    array (
                        0 => 'text',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.full_html.default',
        'targetEntityType' => 'node',
        'bundle' => 'full_html',
        'mode' => 'default',
        'content' =>
            array (
                'field_blog_format' =>
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
                        'region' => 'content',
                    ),
                'field_blog_thematic' =>
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
                        'region' => 'content',
                    ),
                'field_content' =>
                    array (
                        'weight' => 1,
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
                'field_insight' =>
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
                'field_job_profile' =>
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
                'field_region' =>
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
                'field_subhome' =>
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
                'workbench_moderation_control' =>
                    array (
                        'weight' => -20,
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
                'field_display_title' => true,
                'field_end_date' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_start_date' => true,
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(TRUE);


// --------------- Reprise des champs taxonomie créés dans update_8023 pour changer la cardinalité

// field_insight

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// field_geographic

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// field_country

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_country');
$config_group->setData(
    array (
        'uuid' => '6f499935-9052-4948-bf8e-884db2233dd4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                    ),
            ),
        'id' => 'node.field_country',
        'field_name' => 'field_country',
        'entity_type' => 'node',
        'type' => 'string',
        'settings' =>
            array (
                'max_length' => 255,
                'is_ascii' => false,
                'case_sensitive' => false,
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// field_press_type

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// document type

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// document thematic

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// magazine type

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// magazine thematic

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
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);

// -------------- Correction page Document : form display : enlever solution de l'onglet Classify, ajouter document thematic

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
                                        2 => 'field_document_thematic',
                                        3 => 'field_industry',
                                        4 => 'field_region',
                                        5 => 'field_job_profile',
                                        6 => 'field_insight',
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
                'field_insight' =>
                    array (
                        'weight' => 57,
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
                'field_solution' => true,
                'field_thematic' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);
