<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

$field_storage = FieldStorageConfig::loadByName('node', 'field_email_owner');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_email_owner',
		'entity_type' => 'node',
		'type' => 'text_long',
	))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_email_owner');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_email_owner',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Email of content owner',
		'required' => FALSE,
	);
	FieldConfig::create($config_array)->save();
}

$field_storage = FieldStorageConfig::loadByName('node', 'field_content_owner');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_content_owner',
		'entity_type' => 'node',
		'type' => 'text_long',
	))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_content_owner');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_content_owner',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Content owner',
		'required' => FALSE,
	);
	FieldConfig::create($config_array)->save();
}

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
                        15 => 'field.field.node.product.field_product',
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
                'field_market_segment' => true,
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
                        16 => 'field.field.node.product.field_product',
                        17 => 'field.field.node.product.field_region',
                        18 => 'field.field.node.product.field_solution',
                        19 => 'field.field.node.product.field_start_date',
                        20 => 'field.field.node.product.field_sub_family',
                        21 => 'field.field.node.product.field_subhome',
                        22 => 'field.field.node.product.field_top_zone',
                        23 => 'field.field.node.product.field_top_zone_background',
                        24 => 'field.field.node.product.field_visual',
                        25 => 'node.type.product',
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
                        'weight' => 39,
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
$config_group = $config_factory->getEditable('field.field.node.product.field_file');
$config_group->setData(
    array (
        'uuid' => '9b9d560e-0684-4271-8be5-2b6a5041794f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_file',
                        1 => 'media_entity.bundle.file',
                        2 => 'node.type.product',
                    ),
            ),
        'id' => 'node.product.field_file',
        'field_name' => 'field_file',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Upload document',
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
                                'file' => 'file',
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
$config_group = $config_factory->getEditable('field.field.node.product.field_visual');
$config_group->setData(
    array (
        'uuid' => '0af65aa5-df1e-422e-b657-474b6cdc4d41',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_visual',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.product',
                    ),
            ),
        'id' => 'node.product.field_visual',
        'field_name' => 'field_visual',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Ornamental visual',
        'description' => 'Image size : 310 x 125 px',
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
$config_group = $config_factory->getEditable('field.field.node.product.field_top_zone_background');
$config_group->setData(
    array (
        'uuid' => '27560084-d093-4b83-8e70-6a797b70e5c3',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_top_zone_background',
                        1 => 'media_entity.bundle.image',
                        2 => 'node.type.product',
                    ),
            ),
        'id' => 'node.product.field_top_zone_background',
        'field_name' => 'field_top_zone_background',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Top zone background',
        'description' => 'Image size : 1400 * 280 px',
        'required' => false,
        'translatable' => false,
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
$config_group = $config_factory->getEditable('field.field.node.product.field_meta_title');
$config_group->setData(
    array (
        'uuid' => '0995421a-5304-4fb4-8003-cbf5abc37e84',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.product',
                    ),
            ),
        'id' => 'node.product.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Meta title',
        'description' => 'This field is limited to 56 characters (used for SEO-optimization)',
        'required' => true,
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_meta_description');
$config_group->setData(
    array (
        'uuid' => '86731752-52e7-48fb-85cd-6e12e42a4ad1',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.product',
                    ),
            ),
        'id' => 'node.product.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
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

