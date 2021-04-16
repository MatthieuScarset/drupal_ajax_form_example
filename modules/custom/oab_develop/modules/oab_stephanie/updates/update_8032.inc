<?php
/**
 * Ajout du visuel ornemental sur la page simple
 */


/*********************************
 * Ajout du champs sur les types de contenus
 *********************************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_visual');
$config_group->setData(
	array (
		'uuid' => '6db71972-41da-4ac8-939c-e14be3e3f917',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_visual',
						1 => 'media_entity.bundle.image',
						2 => 'node.type.simple_page',
					),
			),
		'id' => 'node.simple_page.field_visual',
		'field_name' => 'field_visual',
		'entity_type' => 'node',
		'bundle' => 'simple_page',
		'label' => 'Ornamental visual',
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

//TRADUCTION

/*********************************
 *  FORM DISPLAY
 *********************************/
//BLOG POST
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
						1 => 'field.field.node.simple_page.field_content',
						2 => 'field.field.node.simple_page.field_content_owner',
						3 => 'field.field.node.simple_page.field_display_title',
						4 => 'field.field.node.simple_page.field_email_owner',
						5 => 'field.field.node.simple_page.field_end_date',
						6 => 'field.field.node.simple_page.field_grouping_title',
						7 => 'field.field.node.simple_page.field_highlight',
						8 => 'field.field.node.simple_page.field_industry',
						9 => 'field.field.node.simple_page.field_job_profile',
						10 => 'field.field.node.simple_page.field_market_segment',
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
								'weight' => 2,
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
										2 => 'field_solution',
										3 => 'field_region',
										4 => 'field_market_segment',
										5 => 'field_job_profile',
										6 => 'field_thematic',
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
				'field_market_segment' =>
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
				'field_solution' =>
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
				'field_thematic' =>
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
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);



/*********************************
 *   VIEW DISPLAY DEFAULT
 *********************************/
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
						0 => 'field.field.node.simple_page.field_content',
						1 => 'field.field.node.simple_page.field_content_owner',
						2 => 'field.field.node.simple_page.field_display_title',
						3 => 'field.field.node.simple_page.field_email_owner',
						4 => 'field.field.node.simple_page.field_end_date',
						5 => 'field.field.node.simple_page.field_grouping_title',
						6 => 'field.field.node.simple_page.field_highlight',
						7 => 'field.field.node.simple_page.field_industry',
						8 => 'field.field.node.simple_page.field_job_profile',
						9 => 'field.field.node.simple_page.field_market_segment',
						10 => 'field.field.node.simple_page.field_meta_description',
						11 => 'field.field.node.simple_page.field_meta_title',
						12 => 'field.field.node.simple_page.field_metatags',
						13 => 'field.field.node.simple_page.field_region',
						14 => 'field.field.node.simple_page.field_solution',
						15 => 'field.field.node.simple_page.field_start_date',
						16 => 'field.field.node.simple_page.field_subhome',
						17 => 'field.field.node.simple_page.field_thematic',
						18 => 'field.field.node.simple_page.field_visual',
						19 => 'node.type.simple_page',
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
				'field_market_segment' => true,
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




$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.simple_page.teaser');
$config_group->setData(
	array (
		'uuid' => 'd2f57eba-3c18-4080-af7d-48b2c34132ee',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.simple_page.field_content',
						2 => 'field.field.node.simple_page.field_content_owner',
						3 => 'field.field.node.simple_page.field_display_title',
						4 => 'field.field.node.simple_page.field_email_owner',
						5 => 'field.field.node.simple_page.field_end_date',
						6 => 'field.field.node.simple_page.field_grouping_title',
						7 => 'field.field.node.simple_page.field_highlight',
						8 => 'field.field.node.simple_page.field_industry',
						9 => 'field.field.node.simple_page.field_job_profile',
						10 => 'field.field.node.simple_page.field_market_segment',
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
						0 => 'user',
					),
			),
		'id' => 'node.simple_page.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'simple_page',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'type' => 'basic_string',
						'weight' => 1,
						'label' => 'above',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 3,
						'region' => 'content',
						'label' => 'hidden',
						'settings' =>
							array (
								'view_mode' => 'automatic_teaser',
								'link' => false,
							),
						'third_party_settings' =>
							array (
							),
					),
				'links' =>
					array (
						'weight' => 2,
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
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_grouping_title' => true,
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_thematic' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);