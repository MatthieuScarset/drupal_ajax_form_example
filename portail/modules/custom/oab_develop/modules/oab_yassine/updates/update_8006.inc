<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

$field_storage = FieldStorageConfig::loadByName('node', 'field_local_nav');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_local_nav',
		'entity_type' => 'node',
		'type' => 'text_long',
	))->save();
}

$field = FieldConfig::loadByName('node', 'solution', 'field_local_nav');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_local_nav',
		'entity_type' => 'node',
		'bundle' => 'solution',
		'label' => 'Local nav',
		'required' => true,
		'default_value' =>
			array (
				0 =>
					array (
						'value' => "<div class='local_nav sub_local_menu container-fluid' id='local_nav'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li></ul></div></div>",
      			'format' => 'full_html',
    			),
 			),
	);
	FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'industry', 'field_local_nav');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_local_nav',
		'entity_type' => 'node',
		'bundle' => 'industry',
		'label' => 'Local nav',
		'required' => true,
		'default_value' =>
			array (
				0 =>
					array (
						'value' => "<div class='local_nav sub_local_menu container-fluid' id='local_nav'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li></ul></div></div>",
						'format' => 'full_html',
					),
			),
	);
	FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'country', 'field_local_nav');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_local_nav',
		'entity_type' => 'node',
		'bundle' => 'country',
		'label' => 'Local nav',
		'required' => true,
		'default_value' =>
			array (
				0 =>
					array (
						'value' => "<div class='local_nav sub_local_menu container-fluid' id='local_nav'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li></ul></div></div>",
						'format' => 'full_html',
					),
			),
	);
	FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'region', 'field_local_nav');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_local_nav',
		'entity_type' => 'node',
		'bundle' => 'region',
		'label' => 'Local nav',
		'required' => true,
		'default_value' =>
			array (
				0 =>
					array (
						'value' => "<div class='local_nav sub_local_menu container-fluid' id='local_nav'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li></ul></div></div>",
						'format' => 'full_html',
					),
			),
	);
	FieldConfig::create($config_array)->save();
}

/******** INDUSTRY *********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.default');
$config_group->setData(
	array (
		'uuid' => 'e8869272-4cf2-481b-ad12-c571dd1daa23',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.field.node.industry.field_content_owner',
						1 => 'field.field.node.industry.field_email_owner',
						2 => 'field.field.node.industry.field_end_date',
						3 => 'field.field.node.industry.field_highlight',
						4 => 'field.field.node.industry.field_industry',
						5 => 'field.field.node.industry.field_local_nav',
						6 => 'field.field.node.industry.field_start_date',
						7 => 'field.field.node.industry.field_top_zone',
						8 => 'field.field.node.industry.field_top_zone_background',
						9 => 'field.field.node.industry.field_visual',
						10 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'text',
						1 => 'user',
					),
			),
		'id' => 'node.industry.default',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
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
				'field_local_nav' =>
					array (
						'weight' => 7,
						'label' => 'above',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'text_default',
						'region' => 'content',
					),
				'field_region' =>
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.industry.default');
$config_group->setData(
	array (
		'uuid' => '85031f3a-be20-43bc-bbe6-447651a7b1c3',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.industry.field_content_owner',
						2 => 'field.field.node.industry.field_email_owner',
						3 => 'field.field.node.industry.field_end_date',
						4 => 'field.field.node.industry.field_highlight',
						5 => 'field.field.node.industry.field_industry',
						6 => 'field.field.node.industry.field_local_nav',
						7 => 'field.field.node.industry.field_start_date',
						8 => 'field.field.node.industry.field_top_zone',
						9 => 'field.field.node.industry.field_top_zone_background',
						10 => 'field.field.node.industry.field_visual',
						11 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
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
										2 => 'field_top_zone',
										3 => 'field_top_zone_background',
										4 => 'field_local_nav',
										5 => 'field_highlight',
										6 => 'field_visual',
									),
								'parent_name' => 'group_onglets',
								'weight' => 17,
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
										0 => 'field_industry',
									),
								'parent_name' => 'group_onglets',
								'weight' => 18,
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
						'group_seo' =>
							array (
								'children' =>
									array (
									),
								'parent_name' => 'group_onglets',
								'weight' => 19,
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
						'group_publish' =>
							array (
								'children' =>
									array (
										0 => 'field_content_owner',
										1 => 'field_email_owner',
										2 => 'group_content_worthy_period',
										3 => 'promote',
										4 => 'path',
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
								'weight' => 11,
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
		'id' => 'node.industry.default',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
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
				'field_email_owner' =>
					array (
						'type' => 'string_textfield',
						'weight' => 10,
						'region' => 'content',
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
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
				'field_highlight' =>
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
						'region' => 'content',
					),
				'field_industry' =>
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
				'field_job_profile' =>
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
				'field_local_nav' =>
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
				'field_market_segment' =>
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
				'field_meta_description' =>
					array (
						'weight' => 1,
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
						'type' => 'string_textfield',
						'weight' => 0,
						'region' => 'content',
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_region' =>
					array (
						'weight' => 25,
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
						'weight' => 24,
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
				'field_top_zone' =>
					array (
						'type' => 'text_textarea',
						'weight' => 4,
						'region' => 'content',
						'settings' =>
							array (
								'rows' => 5,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_top_zone_background' =>
					array (
						'type' => 'entity_browser_entity_reference',
						'weight' => 5,
						'region' => 'content',
						'settings' =>
							array (
								'entity_browser' => 'browse_media_modal',
								'field_widget_display' => 'rendered_entity',
								'field_widget_edit' => true,
								'field_widget_remove' => true,
								'open' => true,
								'selection_mode' => 'selection_append',
								'field_widget_display_settings' =>
									array (
										'view_mode' => 'teaser',
									),
							),
						'third_party_settings' =>
							array (
							),
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
						'weight' => 13,
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
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 12,
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
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);




/******** SOLUTION *********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.solution.default');
$config_group->setData(
	array (
		'uuid' => 'ded733d8-3084-4cab-87e2-7542b0f06974',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.solution.field_content_owner',
						2 => 'field.field.node.solution.field_email_owner',
						3 => 'field.field.node.solution.field_end_date',
						4 => 'field.field.node.solution.field_highlight',
						5 => 'field.field.node.solution.field_local_nav',
						6 => 'field.field.node.solution.field_solution',
						7 => 'field.field.node.solution.field_start_date',
						8 => 'field.field.node.solution.field_top_zone',
						9 => 'field.field.node.solution.field_top_zone_background',
						10 => 'field.field.node.solution.field_visual',
						11 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
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
										5 => 'field_local_nav',
										6 => 'field_visual',
									),
								'parent_name' => 'group_onglets',
								'weight' => 17,
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
										0 => 'field_solution',
									),
								'parent_name' => 'group_onglets',
								'weight' => 18,
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
						'group_seo' =>
							array (
								'children' =>
									array (
									),
								'parent_name' => 'group_onglets',
								'weight' => 19,
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
						'group_publish' =>
							array (
								'children' =>
									array (
										0 => 'field_content_owner',
										1 => 'field_email_owner',
										2 => 'group_content_worthy_period',
										3 => 'promote',
										4 => 'path',
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
					),
			),
		'id' => 'node.solution.default',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
						'weight' => 16,
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
						'weight' => 17,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_local_nav' =>
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
				'field_market_segment' =>
					array (
						'weight' => 18,
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
						'weight' => 19,
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
				'field_region' =>
					array (
						'weight' => 15,
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
						'weight' => 14,
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
				'field_top_zone' =>
					array (
						'type' => 'text_textarea',
						'weight' => 5,
						'region' => 'content',
						'settings' =>
							array (
								'rows' => 5,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_top_zone_background' =>
					array (
						'type' => 'entity_browser_entity_reference',
						'weight' => 6,
						'region' => 'content',
						'settings' =>
							array (
								'entity_browser' => 'browse_media_modal',
								'field_widget_display' => 'rendered_entity',
								'field_widget_edit' => true,
								'field_widget_remove' => true,
								'open' => true,
								'selection_mode' => 'selection_append',
								'field_widget_display_settings' =>
									array (
										'view_mode' => 'teaser',
									),
							),
						'third_party_settings' =>
							array (
							),
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
						'weight' => 16,
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
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 15,
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
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.default');
$config_group->setData(
	array (
		'uuid' => 'dd6a5788-1324-4b14-84cd-7bdf016bb502',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.field.node.solution.field_content_owner',
						1 => 'field.field.node.solution.field_email_owner',
						2 => 'field.field.node.solution.field_end_date',
						3 => 'field.field.node.solution.field_highlight',
						4 => 'field.field.node.solution.field_local_nav',
						5 => 'field.field.node.solution.field_solution',
						6 => 'field.field.node.solution.field_start_date',
						7 => 'field.field.node.solution.field_top_zone',
						8 => 'field.field.node.solution.field_top_zone_background',
						9 => 'field.field.node.solution.field_visual',
						10 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'text',
						1 => 'user',
					),
			),
		'id' => 'node.solution.default',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
				'field_industry' =>
					array (
						'type' => 'entity_reference_label',
						'weight' => 5,
						'region' => 'content',
						'label' => 'hidden',
						'settings' =>
							array (
								'link' => true,
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_local_nav' =>
					array (
						'weight' => 6,
						'label' => 'above',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'text_default',
						'region' => 'content',
					),
				'field_solution' =>
					array (
						'type' => 'entity_reference_label',
						'weight' => 4,
						'region' => 'content',
						'label' => 'hidden',
						'settings' =>
							array (
								'link' => true,
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
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);


/******** REGION *********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.region.default');
$config_group->setData(
	array (
		'uuid' => 'fafecffa-fff7-4acd-85fc-37adbc281168',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.region.field_content_owner',
						2 => 'field.field.node.region.field_email_owner',
						3 => 'field.field.node.region.field_end_date',
						4 => 'field.field.node.region.field_highlight',
						5 => 'field.field.node.region.field_local_nav',
						6 => 'field.field.node.region.field_region',
						7 => 'field.field.node.region.field_start_date',
						8 => 'field.field.node.region.field_visual',
						9 => 'node.type.region',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
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
										2 => 'field_local_nav',
										3 => 'field_highlight',
										4 => 'field_visual',
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
								'label' => 'Write',
							),
						'group_classify' =>
							array (
								'children' =>
									array (
										0 => 'field_region',
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
								'label' => 'Classify',
							),
						'group_seo' =>
							array (
								'children' =>
									array (
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
								'label' => 'SEO',
							),
						'group_publish' =>
							array (
								'children' =>
									array (
										0 => 'field_content_owner',
										1 => 'field_email_owner',
										2 => 'group_c',
										3 => 'promote',
										4 => 'path',
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
								'label' => 'Publish',
							),
						'group_c' =>
							array (
								'children' =>
									array (
										0 => 'field_start_date',
										1 => 'field_end_date',
									),
								'parent_name' => 'group_publish',
								'weight' => 11,
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
		'id' => 'node.region.default',
		'targetEntityType' => 'node',
		'bundle' => 'region',
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
				'field_email_owner' =>
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
				'field_end_date' =>
					array (
						'weight' => 8,
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
				'field_job_profile' =>
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
				'field_local_nav' =>
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
						'type' => 'text_textarea',
						'region' => 'content',
					),
				'field_market_segment' =>
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
						'weight' => 21,
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
						'weight' => 20,
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
				'field_region' =>
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
				'field_solution' =>
					array (
						'weight' => 25,
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
						'weight' => 7,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
						'region' => 'content',
					),
				'field_top_zone' =>
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
				'field_top_zone_background' =>
					array (
						'weight' => 7,
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
				'field_visual' =>
					array (
						'weight' => 6,
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
						'weight' => 13,
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
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 12,
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
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.default');
$config_group->setData(
	array (
		'uuid' => 'd93f57d7-8441-47bd-b0b3-598c3df704f0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.field.node.region.field_content_owner',
						1 => 'field.field.node.region.field_email_owner',
						2 => 'field.field.node.region.field_end_date',
						3 => 'field.field.node.region.field_highlight',
						4 => 'field.field.node.region.field_local_nav',
						5 => 'field.field.node.region.field_region',
						6 => 'field.field.node.region.field_start_date',
						7 => 'field.field.node.region.field_visual',
						8 => 'node.type.region',
					),
				'module' =>
					array (
						0 => 'text',
						1 => 'user',
					),
			),
		'id' => 'node.region.default',
		'targetEntityType' => 'node',
		'bundle' => 'region',
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
				'field_local_nav' =>
					array (
						'weight' => 7,
						'label' => 'above',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'text_default',
						'region' => 'content',
					),
				'field_region' =>
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

/******** COUNTRY *********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');
$config_group->setData(
	array (
		'uuid' => '1f8a80eb-afb8-43ea-bbbc-e82b705e0d23',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.country.field_content',
						2 => 'field.field.node.country.field_content_owner',
						3 => 'field.field.node.country.field_email_owner',
						4 => 'field.field.node.country.field_end_date',
						5 => 'field.field.node.country.field_highlight',
						6 => 'field.field.node.country.field_local_nav',
						7 => 'field.field.node.country.field_start_date',
						8 => 'field.field.node.country.field_visual',
						9 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
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
										2 => 'field_local_nav',
										3 => 'field_highlight',
										4 => 'field_content',
										5 => 'field_visual',
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
								'label' => 'Write',
							),
						'group_seo' =>
							array (
								'children' =>
									array (
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
								'label' => 'SEO',
							),
						'group_classify' =>
							array (
								'children' =>
									array (
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
								'weight' => 17,
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
		'id' => 'node.country.default',
		'targetEntityType' => 'node',
		'bundle' => 'country',
		'mode' => 'default',
		'content' =>
			array (
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
						'weight' => 15,
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
								'display_label' => true,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'boolean_checkbox',
						'region' => 'content',
					),
				'field_email_owner' =>
					array (
						'weight' => 16,
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
				'field_job_profile' =>
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
				'field_local_nav' =>
					array (
						'type' => 'text_textarea',
						'weight' => 4,
						'region' => 'content',
						'settings' =>
							array (
								'rows' => 5,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_market_segment' =>
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
				'field_meta_description' =>
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
				'field_meta_title' =>
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
				'field_region' =>
					array (
						'weight' => 25,
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
						'weight' => 24,
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
						'weight' => 12,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
						'region' => 'content',
					),
				'field_top_zone' =>
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
				'field_top_zone_background' =>
					array (
						'weight' => 7,
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
				'field_visual' =>
					array (
						'weight' => 7,
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
						'weight' => 19,
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
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 18,
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
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.default');
$config_group->setData(
	array (
		'uuid' => '1b599147-7899-418c-a9e2-74442607a028',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.field.node.country.field_content',
						1 => 'field.field.node.country.field_content_owner',
						2 => 'field.field.node.country.field_display_title',
						3 => 'field.field.node.country.field_email_owner',
						4 => 'field.field.node.country.field_end_date',
						5 => 'field.field.node.country.field_highlight',
						6 => 'field.field.node.country.field_industry',
						7 => 'field.field.node.country.field_job_profile',
						8 => 'field.field.node.country.field_market_segment',
						9 => 'field.field.node.country.field_meta_description',
						10 => 'field.field.node.country.field_meta_title',
						11 => 'field.field.node.country.field_region',
						12 => 'field.field.node.country.field_solution',
						13 => 'field.field.node.country.field_start_date',
						14 => 'field.field.node.country.field_top_zone',
						15 => 'field.field.node.country.field_top_zone_background',
						16 => 'field.field.node.country.field_visual',
						17 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'text',
						1 => 'user',
					),
			),
		'id' => 'node.country.default',
		'targetEntityType' => 'node',
		'bundle' => 'country',
		'mode' => 'default',
		'content' =>
			array (
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
				'field_highlight' =>
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
						'region' => 'content',
					),
				'field_region' =>
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
				'links' =>
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
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);


