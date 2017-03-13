<?php
/* Mise a jour des formulaire et vue des contenus pour les taxonomies */

//
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
						1 => 'field.field.node.blog_post.field_content',
						2 => 'field.field.node.blog_post.field_content_owner',
						3 => 'field.field.node.blog_post.field_display_title',
						4 => 'field.field.node.blog_post.field_email_owner',
						5 => 'field.field.node.blog_post.field_end_date',
						6 => 'field.field.node.blog_post.field_highlight',
						7 => 'field.field.node.blog_post.field_industry',
						8 => 'field.field.node.blog_post.field_job_profile',
						9 => 'field.field.node.blog_post.field_market_segment',
						10 => 'field.field.node.blog_post.field_meta_description',
						11 => 'field.field.node.blog_post.field_meta_title',
						12 => 'field.field.node.blog_post.field_metatags',
						13 => 'field.field.node.blog_post.field_profile',
						14 => 'field.field.node.blog_post.field_region',
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
										1 => 'field_solution',
										2 => 'field_industry',
										3 => 'field_region',
										4 => 'field_content_type',
										5 => 'field_market_segment',
										6 => 'field_job_profile',
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
					),
				'field_industry' =>
					array (
						'weight' => 28,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_market_segment' =>
					array (
						'weight' => 31,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_solution' =>
					array (
						'weight' => 27,
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
						'weight' => 14,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
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

//core.entity_form_display.node.customer_story.default
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
						3 => 'field.field.node.customer_story.field_display_title',
						4 => 'field.field.node.customer_story.field_email_owner',
						5 => 'field.field.node.customer_story.field_end_date',
						6 => 'field.field.node.customer_story.field_file',
						7 => 'field.field.node.customer_story.field_highlight',
						8 => 'field.field.node.customer_story.field_industry',
						9 => 'field.field.node.customer_story.field_job_profile',
						10 => 'field.field.node.customer_story.field_market_segment',
						11 => 'field.field.node.customer_story.field_meta_description',
						12 => 'field.field.node.customer_story.field_meta_title',
						13 => 'field.field.node.customer_story.field_metatags',
						14 => 'field.field.node.customer_story.field_region',
						15 => 'field.field.node.customer_story.field_solution',
						16 => 'field.field.node.customer_story.field_start_date',
						17 => 'field.field.node.customer_story.field_subhome',
						18 => 'field.field.node.customer_story.field_visual',
						19 => 'node.type.customer_story',
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
								'weight' => 20,
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
										4 => 'field_job_profile',
										5 => 'field_market_segment',
										6 => 'field_content_type',
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
					),
				'field_job_profile' =>
					array (
						'weight' => 51,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
					),
				'field_market_segment' =>
					array (
						'weight' => 52,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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

//core.entity_form_display.node.document.default
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
						1 => 'field.field.node.document.field_content',
						2 => 'field.field.node.document.field_content_owner',
						3 => 'field.field.node.document.field_display_title',
						4 => 'field.field.node.document.field_document_type',
						5 => 'field.field.node.document.field_email_owner',
						6 => 'field.field.node.document.field_end_date',
						7 => 'field.field.node.document.field_file',
						8 => 'field.field.node.document.field_highlight',
						9 => 'field.field.node.document.field_industry',
						10 => 'field.field.node.document.field_job_profile',
						11 => 'field.field.node.document.field_market_segment',
						12 => 'field.field.node.document.field_meta_description',
						13 => 'field.field.node.document.field_meta_title',
						14 => 'field.field.node.document.field_metatags',
						15 => 'field.field.node.document.field_region',
						16 => 'field.field.node.document.field_solution',
						17 => 'field.field.node.document.field_start_date',
						18 => 'field.field.node.document.field_subhome',
						19 => 'field.field.node.document.field_visual',
						20 => 'node.type.document',
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
								'weight' => 20,
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
										6 => 'field_market_segment',
										7 => 'field_content_type',
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
					),
				'field_market_segment' =>
					array (
						'weight' => 57,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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

//core.entity_form_display.node.full_html.default
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
						0 => 'field.field.node.full_html.field_content',
						1 => 'field.field.node.full_html.field_display_title',
						2 => 'field.field.node.full_html.field_end_date',
						3 => 'field.field.node.full_html.field_meta_description',
						4 => 'field.field.node.full_html.field_meta_title',
						5 => 'field.field.node.full_html.field_metatags',
						6 => 'field.field.node.full_html.field_start_date',
						7 => 'node.type.full_html',
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


//core.entity_form_display.node.magazine.default
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
						1 => 'field.field.node.magazine.field_content',
						2 => 'field.field.node.magazine.field_content_owner',
						3 => 'field.field.node.magazine.field_display_title',
						4 => 'field.field.node.magazine.field_email_owner',
						5 => 'field.field.node.magazine.field_end_date',
						6 => 'field.field.node.magazine.field_highlight',
						7 => 'field.field.node.magazine.field_industry',
						8 => 'field.field.node.magazine.field_job_profile',
						9 => 'field.field.node.magazine.field_market_segment',
						10 => 'field.field.node.magazine.field_meta_description',
						11 => 'field.field.node.magazine.field_meta_title',
						12 => 'field.field.node.magazine.field_metatags',
						13 => 'field.field.node.magazine.field_region',
						14 => 'field.field.node.magazine.field_solution',
						15 => 'field.field.node.magazine.field_start_date',
						16 => 'field.field.node.magazine.field_subhome',
						17 => 'field.field.node.magazine.field_visual',
						18 => 'node.type.magazine',
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
										1 => 'field_solution',
										2 => 'field_industry',
										3 => 'field_market_segment',
										4 => 'field_job_profile',
										5 => 'field_region',
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
								'weight' => 6,
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
					),
				'field_industry' =>
					array (
						'weight' => 28,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
					),
				'field_job_profile' =>
					array (
						'type' => 'options_select',
						'weight' => 30,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_market_segment' =>
					array (
						'type' => 'options_select',
						'weight' => 29,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
					),
				'field_region' =>
					array (
						'type' => 'options_select',
						'weight' => 31,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_solution' =>
					array (
						'weight' => 27,
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
						'weight' => 13,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
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












//core.entity_form_display.node.partner.default
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
						17 => 'field.field.node.partner.field_visual',
						18 => 'node.type.partner',
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
								'weight' => 20,
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
										2 => 'field_industry',
										3 => 'field_region',
										4 => 'field_partner_type',
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
					),
				'field_industry' =>
					array (
						'weight' => 46,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_partner_type' =>
					array (
						'weight' => 48,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
					),
				'field_region' =>
					array (
						'weight' => 47,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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

//core.entity_form_display.node.press_kit.default
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
						10 => 'field.field.node.press_kit.field_market_segment',
						11 => 'field.field.node.press_kit.field_meta_description',
						12 => 'field.field.node.press_kit.field_meta_title',
						13 => 'field.field.node.press_kit.field_metatags',
						14 => 'field.field.node.press_kit.field_region',
						15 => 'field.field.node.press_kit.field_solution',
						16 => 'field.field.node.press_kit.field_start_date',
						17 => 'field.field.node.press_kit.field_subhome',
						18 => 'field.field.node.press_kit.field_visual',
						19 => 'node.type.press_kit',
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
								'weight' => 20,
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
										3 => 'field_market_segment',
										4 => 'field_job_profile',
										5 => 'field_region',
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
					),
				'field_market_segment' =>
					array (
						'weight' => 51,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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

//core.entity_form_display.node.press_release.default
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
						12 => 'field.field.node.press_release.field_market_segment',
						13 => 'field.field.node.press_release.field_meta_description',
						14 => 'field.field.node.press_release.field_meta_title',
						15 => 'field.field.node.press_release.field_metatags',
						16 => 'field.field.node.press_release.field_region',
						17 => 'field.field.node.press_release.field_solution',
						18 => 'field.field.node.press_release.field_start_date',
						19 => 'field.field.node.press_release.field_subhome',
						20 => 'field.field.node.press_release.field_visual',
						21 => 'node.type.press_release',
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
								'weight' => 20,
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
										2 => 'field_industry',
										3 => 'field_region',
										4 => 'field_job_profile',
										5 => 'field_market_segment',
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
					),
				'field_industry' =>
					array (
						'weight' => 50,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_market_segment' =>
					array (
						'weight' => 53,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_region' =>
					array (
						'weight' => 51,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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

//core.entity_form_display.node.product.default
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
						0 => 'field.field.node.product.field_content',
						1 => 'field.field.node.product.field_end_date',
						2 => 'field.field.node.product.field_industry',
						3 => 'field.field.node.product.field_job_profile',
						4 => 'field.field.node.product.field_market_segment',
						5 => 'field.field.node.product.field_meta_description',
						6 => 'field.field.node.product.field_meta_title',
						7 => 'field.field.node.product.field_metatags',
						8 => 'field.field.node.product.field_region',
						9 => 'field.field.node.product.field_solution',
						10 => 'field.field.node.product.field_start_date',
						11 => 'field.field.node.product.field_sub_family',
						12 => 'field.field.node.product.field_subhome',
						13 => 'field.field.node.product.field_top_zone',
						14 => 'node.type.product',
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
										2 => 'field_top_zone',
										3 => 'field_content',
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
										0 => 'group_content_worthy_period',
										1 => 'path',
										2 => 'field_metatags',
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
						'group_seo' =>
							array (
								'children' =>
									array (
										0 => 'field_meta_title',
										1 => 'field_meta_description',
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
						'group_classify' =>
							array (
								'children' =>
									array (
										0 => 'field_solution',
										1 => 'field_industry',
										2 => 'field_region',
										3 => 'field_job_profile',
										4 => 'field_market_segment',
										5 => 'field_sub_family',
										6 => 'field_subhome',
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
					),
				'field_industry' =>
					array (
						'weight' => 29,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_market_segment' =>
					array (
						'weight' => 32,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_region' =>
					array (
						'weight' => 30,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_sub_family' =>
					array (
						'weight' => 33,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
					),
				'field_top_zone' =>
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
					),
			),
		'hidden' =>
			array (
				'created' => true,
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_form_display.node.region.default
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
						0 => 'field.field.node.region.field_content_owner',
						1 => 'field.field.node.region.field_email_owner',
						2 => 'field.field.node.region.field_end_date',
						3 => 'field.field.node.region.field_highlight',
						4 => 'field.field.node.region.field_region',
						5 => 'field.field.node.region.field_start_date',
						6 => 'field.field.node.region.field_visual',
						7 => 'node.type.region',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'path',
						2 => 'workbench_moderation',
					),
			),
		'id' => 'node.region.default',
		'targetEntityType' => 'node',
		'bundle' => 'region',
		'mode' => 'default',
		'content' =>
			array (
				'created' =>
					array (
						'type' => 'datetime_timestamp',
						'weight' => 10,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
					),
				'field_end_date' =>
					array (
						'weight' => 33,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
					),
				'field_highlight' =>
					array (
						'weight' => 31,
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
				'field_region' =>
					array (
						'weight' => 37,
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
				'field_start_date' =>
					array (
						'weight' => 32,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
					),
				'field_visual' =>
					array (
						'weight' => 34,
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
					),
				'path' =>
					array (
						'type' => 'path',
						'weight' => 30,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
					),
				'sticky' =>
					array (
						'type' => 'boolean_checkbox',
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 16,
						'third_party_settings' =>
							array (
							),
					),
				'title' =>
					array (
						'type' => 'string_textfield',
						'weight' => -5,
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'uid' =>
					array (
						'type' => 'entity_reference_autocomplete',
						'weight' => 5,
						'settings' =>
							array (
								'match_operator' => 'CONTAINS',
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
			),
	)
);
$config_group->save(TRUE);

//core.entity_form_display.node.simple_page.default
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
						17 => 'node.type.simple_page',
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
										6 => 'field_content_type',
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
					),
				'field_grouping_title' =>
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

//core.entity_view_display.node.blog_post.default
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
						0 => 'field.field.node.blog_post.field_content',
						1 => 'field.field.node.blog_post.field_content_owner',
						2 => 'field.field.node.blog_post.field_display_title',
						3 => 'field.field.node.blog_post.field_email_owner',
						4 => 'field.field.node.blog_post.field_end_date',
						5 => 'field.field.node.blog_post.field_highlight',
						6 => 'field.field.node.blog_post.field_industry',
						7 => 'field.field.node.blog_post.field_job_profile',
						8 => 'field.field.node.blog_post.field_market_segment',
						9 => 'field.field.node.blog_post.field_meta_description',
						10 => 'field.field.node.blog_post.field_meta_title',
						11 => 'field.field.node.blog_post.field_metatags',
						12 => 'field.field.node.blog_post.field_profile',
						13 => 'field.field.node.blog_post.field_region',
						14 => 'field.field.node.blog_post.field_solution',
						15 => 'field.field.node.blog_post.field_start_date',
						16 => 'field.field.node.blog_post.field_subhome',
						17 => 'field.field.node.blog_post.field_visual',
						18 => 'field.field.node.blog_post.publish_date',
						19 => 'field.field.node.blog_post.unpublish_date',
						20 => 'node.type.blog_post',
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_visual' => true,
				'langcode' => true,
				'publish_date' => true,
				'unpublish_date' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.blog_post.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '0b27aa14-fb01-4816-b494-60fa5d7a95bf',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.blog_post.field_content',
						2 => 'field.field.node.blog_post.field_content_owner',
						3 => 'field.field.node.blog_post.field_display_title',
						4 => 'field.field.node.blog_post.field_email_owner',
						5 => 'field.field.node.blog_post.field_end_date',
						6 => 'field.field.node.blog_post.field_highlight',
						7 => 'field.field.node.blog_post.field_industry',
						8 => 'field.field.node.blog_post.field_meta_description',
						9 => 'field.field.node.blog_post.field_meta_title',
						10 => 'field.field.node.blog_post.field_metatags',
						11 => 'field.field.node.blog_post.field_profile',
						12 => 'field.field.node.blog_post.field_solution',
						13 => 'field.field.node.blog_post.field_start_date',
						14 => 'field.field.node.blog_post.field_subhome',
						15 => 'field.field.node.blog_post.field_visual',
						16 => 'field.field.node.blog_post.publish_date',
						17 => 'field.field.node.blog_post.unpublish_date',
						18 => 'node.type.blog_post',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.blog_post.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'blog_post',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_profile' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'publish_date' => true,
				'unpublish_date' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.blog_post.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.teaser');
$config_group->setData(
	array (
		'uuid' => '30a0c0c0-e195-4a5e-a4dd-0a3de2f90381',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.blog_post.field_content',
						2 => 'field.field.node.blog_post.field_content_owner',
						3 => 'field.field.node.blog_post.field_display_title',
						4 => 'field.field.node.blog_post.field_email_owner',
						5 => 'field.field.node.blog_post.field_end_date',
						6 => 'field.field.node.blog_post.field_highlight',
						7 => 'field.field.node.blog_post.field_industry',
						8 => 'field.field.node.blog_post.field_meta_description',
						9 => 'field.field.node.blog_post.field_meta_title',
						10 => 'field.field.node.blog_post.field_metatags',
						11 => 'field.field.node.blog_post.field_profile',
						12 => 'field.field.node.blog_post.field_solution',
						13 => 'field.field.node.blog_post.field_start_date',
						14 => 'field.field.node.blog_post.field_subhome',
						15 => 'field.field.node.blog_post.field_visual',
						16 => 'field.field.node.blog_post.publish_date',
						17 => 'field.field.node.blog_post.unpublish_date',
						18 => 'node.type.blog_post',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.blog_post.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'blog_post',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 2,
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
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_profile' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
				'publish_date' => true,
				'unpublish_date' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.customer_story.default
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
						2 => 'field.field.node.customer_story.field_display_title',
						3 => 'field.field.node.customer_story.field_email_owner',
						4 => 'field.field.node.customer_story.field_end_date',
						5 => 'field.field.node.customer_story.field_file',
						6 => 'field.field.node.customer_story.field_highlight',
						7 => 'field.field.node.customer_story.field_industry',
						8 => 'field.field.node.customer_story.field_job_profile',
						9 => 'field.field.node.customer_story.field_market_segment',
						10 => 'field.field.node.customer_story.field_meta_description',
						11 => 'field.field.node.customer_story.field_meta_title',
						12 => 'field.field.node.customer_story.field_metatags',
						13 => 'field.field.node.customer_story.field_region',
						14 => 'field.field.node.customer_story.field_solution',
						15 => 'field.field.node.customer_story.field_start_date',
						16 => 'field.field.node.customer_story.field_subhome',
						17 => 'field.field.node.customer_story.field_visual',
						18 => 'node.type.customer_story',
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.customer_story.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'eb56c1f2-41ec-46b7-8e10-0248302ca4db',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.customer_story.field_content',
						2 => 'field.field.node.customer_story.field_content_owner',
						3 => 'field.field.node.customer_story.field_display_title',
						4 => 'field.field.node.customer_story.field_email_owner',
						5 => 'field.field.node.customer_story.field_end_date',
						6 => 'field.field.node.customer_story.field_file',
						7 => 'field.field.node.customer_story.field_highlight',
						8 => 'field.field.node.customer_story.field_industry',
						9 => 'field.field.node.customer_story.field_meta_description',
						10 => 'field.field.node.customer_story.field_meta_title',
						11 => 'field.field.node.customer_story.field_metatags',
						12 => 'field.field.node.customer_story.field_solution',
						13 => 'field.field.node.customer_story.field_start_date',
						14 => 'field.field.node.customer_story.field_subhome',
						15 => 'field.field.node.customer_story.field_visual',
						16 => 'node.type.customer_story',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.customer_story.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'customer_story',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.customer_story.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.teaser');
$config_group->setData(
	array (
		'uuid' => '702701ac-00e5-44ee-8d53-5eb3617e4676',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.customer_story.field_content',
						2 => 'field.field.node.customer_story.field_content_owner',
						3 => 'field.field.node.customer_story.field_display_title',
						4 => 'field.field.node.customer_story.field_email_owner',
						5 => 'field.field.node.customer_story.field_end_date',
						6 => 'field.field.node.customer_story.field_file',
						7 => 'field.field.node.customer_story.field_highlight',
						8 => 'field.field.node.customer_story.field_industry',
						9 => 'field.field.node.customer_story.field_meta_description',
						10 => 'field.field.node.customer_story.field_meta_title',
						11 => 'field.field.node.customer_story.field_metatags',
						12 => 'field.field.node.customer_story.field_solution',
						13 => 'field.field.node.customer_story.field_start_date',
						14 => 'field.field.node.customer_story.field_subhome',
						15 => 'field.field.node.customer_story.field_visual',
						16 => 'node.type.customer_story',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.customer_story.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'customer_story',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
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
						'weight' => 100,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'workbench_moderation_control' =>
					array (
						'weight' => -20,
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
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.document.default
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
						0 => 'field.field.node.document.field_content',
						1 => 'field.field.node.document.field_content_owner',
						2 => 'field.field.node.document.field_display_title',
						3 => 'field.field.node.document.field_document_type',
						4 => 'field.field.node.document.field_email_owner',
						5 => 'field.field.node.document.field_end_date',
						6 => 'field.field.node.document.field_file',
						7 => 'field.field.node.document.field_highlight',
						8 => 'field.field.node.document.field_industry',
						9 => 'field.field.node.document.field_job_profile',
						10 => 'field.field.node.document.field_market_segment',
						11 => 'field.field.node.document.field_meta_description',
						12 => 'field.field.node.document.field_meta_title',
						13 => 'field.field.node.document.field_metatags',
						14 => 'field.field.node.document.field_region',
						15 => 'field.field.node.document.field_solution',
						16 => 'field.field.node.document.field_start_date',
						17 => 'field.field.node.document.field_subhome',
						18 => 'field.field.node.document.field_visual',
						19 => 'node.type.document',
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
						'weight' => 8,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'text_default',
					),
				'field_document_type' =>
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
					),
				'field_highlight' =>
					array (
						'weight' => 9,
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.document.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'bea788e2-a1f1-48e9-8668-c0423ba7fc91',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.document.field_content',
						2 => 'field.field.node.document.field_content_owner',
						3 => 'field.field.node.document.field_display_title',
						4 => 'field.field.node.document.field_document_type',
						5 => 'field.field.node.document.field_email_owner',
						6 => 'field.field.node.document.field_end_date',
						7 => 'field.field.node.document.field_file',
						8 => 'field.field.node.document.field_highlight',
						9 => 'field.field.node.document.field_industry',
						10 => 'field.field.node.document.field_meta_description',
						11 => 'field.field.node.document.field_meta_title',
						12 => 'field.field.node.document.field_metatags',
						13 => 'field.field.node.document.field_solution',
						14 => 'field.field.node.document.field_start_date',
						15 => 'field.field.node.document.field_subhome',
						16 => 'field.field.node.document.field_visual',
						17 => 'node.type.document',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.document.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_document_type' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.document.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.teaser');
$config_group->setData(
	array (
		'uuid' => '469467e7-f36b-4eca-8e46-4bb62c1117fe',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.document.field_content',
						2 => 'field.field.node.document.field_content_owner',
						3 => 'field.field.node.document.field_display_title',
						4 => 'field.field.node.document.field_document_type',
						5 => 'field.field.node.document.field_email_owner',
						6 => 'field.field.node.document.field_end_date',
						7 => 'field.field.node.document.field_file',
						8 => 'field.field.node.document.field_highlight',
						9 => 'field.field.node.document.field_industry',
						10 => 'field.field.node.document.field_meta_description',
						11 => 'field.field.node.document.field_meta_title',
						12 => 'field.field.node.document.field_metatags',
						13 => 'field.field.node.document.field_solution',
						14 => 'field.field.node.document.field_start_date',
						15 => 'field.field.node.document.field_subhome',
						16 => 'field.field.node.document.field_visual',
						17 => 'node.type.document',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.document.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
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
						'weight' => 100,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'workbench_moderation_control' =>
					array (
						'weight' => -20,
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
				'field_document_type' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.magazine.default
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
						0 => 'field.field.node.magazine.field_content',
						1 => 'field.field.node.magazine.field_content_owner',
						2 => 'field.field.node.magazine.field_display_title',
						3 => 'field.field.node.magazine.field_email_owner',
						4 => 'field.field.node.magazine.field_end_date',
						5 => 'field.field.node.magazine.field_highlight',
						6 => 'field.field.node.magazine.field_industry',
						7 => 'field.field.node.magazine.field_job_profile',
						8 => 'field.field.node.magazine.field_market_segment',
						9 => 'field.field.node.magazine.field_meta_description',
						10 => 'field.field.node.magazine.field_meta_title',
						11 => 'field.field.node.magazine.field_metatags',
						12 => 'field.field.node.magazine.field_region',
						13 => 'field.field.node.magazine.field_solution',
						14 => 'field.field.node.magazine.field_start_date',
						15 => 'field.field.node.magazine.field_subhome',
						16 => 'field.field.node.magazine.field_visual',
						17 => 'node.type.magazine',
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
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.magazine.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'e99dc5f8-9c8f-4d2a-a36d-440b725aa614',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.magazine.field_content',
						2 => 'field.field.node.magazine.field_content_owner',
						3 => 'field.field.node.magazine.field_display_title',
						4 => 'field.field.node.magazine.field_email_owner',
						5 => 'field.field.node.magazine.field_end_date',
						6 => 'field.field.node.magazine.field_highlight',
						7 => 'field.field.node.magazine.field_industry',
						8 => 'field.field.node.magazine.field_job_profile',
						9 => 'field.field.node.magazine.field_market_segment',
						10 => 'field.field.node.magazine.field_meta_description',
						11 => 'field.field.node.magazine.field_meta_title',
						12 => 'field.field.node.magazine.field_metatags',
						13 => 'field.field.node.magazine.field_region',
						14 => 'field.field.node.magazine.field_solution',
						15 => 'field.field.node.magazine.field_start_date',
						16 => 'field.field.node.magazine.field_subhome',
						17 => 'field.field.node.magazine.field_visual',
						18 => 'node.type.magazine',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.magazine.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'magazine',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.magazine.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.teaser');
$config_group->setData(
	array (
		'uuid' => 'b668b8df-cf97-4070-9366-9b2a80db153d',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.magazine.field_content',
						2 => 'field.field.node.magazine.field_content_owner',
						3 => 'field.field.node.magazine.field_display_title',
						4 => 'field.field.node.magazine.field_email_owner',
						5 => 'field.field.node.magazine.field_end_date',
						6 => 'field.field.node.magazine.field_highlight',
						7 => 'field.field.node.magazine.field_industry',
						8 => 'field.field.node.magazine.field_job_profile',
						9 => 'field.field.node.magazine.field_market_segment',
						10 => 'field.field.node.magazine.field_meta_description',
						11 => 'field.field.node.magazine.field_meta_title',
						12 => 'field.field.node.magazine.field_metatags',
						13 => 'field.field.node.magazine.field_region',
						14 => 'field.field.node.magazine.field_solution',
						15 => 'field.field.node.magazine.field_start_date',
						16 => 'field.field.node.magazine.field_subhome',
						17 => 'field.field.node.magazine.field_visual',
						18 => 'node.type.magazine',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.magazine.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'magazine',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 1,
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
				'field_content' => true,
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
				'field_metatags' => true,
				'field_partner' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);


//core.entity_view_display.node.partner.default
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
						7 => 'field.field.node.partner.field_industry',
						8 => 'field.field.node.partner.field_meta_description',
						9 => 'field.field.node.partner.field_meta_title',
						10 => 'field.field.node.partner.field_metatags',
						11 => 'field.field.node.partner.field_partner_type',
						12 => 'field.field.node.partner.field_region',
						13 => 'field.field.node.partner.field_solution',
						14 => 'field.field.node.partner.field_start_date',
						15 => 'field.field.node.partner.field_subhome',
						16 => 'field.field.node.partner.field_visual',
						17 => 'node.type.partner',
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
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_partner_type' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.partner.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '25a1fb20-1822-41be-b611-d0f8c47fa1ec',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.partner.field_content',
						2 => 'field.field.node.partner.field_content_owner',
						3 => 'field.field.node.partner.field_display_title',
						4 => 'field.field.node.partner.field_email_owner',
						5 => 'field.field.node.partner.field_end_date',
						6 => 'field.field.node.partner.field_file',
						7 => 'field.field.node.partner.field_highlight',
						8 => 'field.field.node.partner.field_meta_description',
						9 => 'field.field.node.partner.field_meta_title',
						10 => 'field.field.node.partner.field_metatags',
						11 => 'field.field.node.partner.field_start_date',
						12 => 'field.field.node.partner.field_subhome',
						13 => 'field.field.node.partner.field_visual',
						14 => 'node.type.partner',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.partner.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'partner',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.partner.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.teaser');
$config_group->setData(
	array (
		'uuid' => '15fc9fa6-36c1-43c9-9470-74e7cba2ea5b',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.partner.field_content',
						2 => 'field.field.node.partner.field_content_owner',
						3 => 'field.field.node.partner.field_display_title',
						4 => 'field.field.node.partner.field_email_owner',
						5 => 'field.field.node.partner.field_end_date',
						6 => 'field.field.node.partner.field_file',
						7 => 'field.field.node.partner.field_highlight',
						8 => 'field.field.node.partner.field_meta_description',
						9 => 'field.field.node.partner.field_meta_title',
						10 => 'field.field.node.partner.field_metatags',
						11 => 'field.field.node.partner.field_start_date',
						12 => 'field.field.node.partner.field_subhome',
						13 => 'field.field.node.partner.field_visual',
						14 => 'node.type.partner',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.partner.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'partner',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
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
						'weight' => 100,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'workbench_moderation_control' =>
					array (
						'weight' => -20,
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
				'field_file' => true,
				'field_highlight' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_kit.default
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
						9 => 'field.field.node.press_kit.field_market_segment',
						10 => 'field.field.node.press_kit.field_meta_description',
						11 => 'field.field.node.press_kit.field_meta_title',
						12 => 'field.field.node.press_kit.field_metatags',
						13 => 'field.field.node.press_kit.field_region',
						14 => 'field.field.node.press_kit.field_solution',
						15 => 'field.field.node.press_kit.field_start_date',
						16 => 'field.field.node.press_kit.field_subhome',
						17 => 'field.field.node.press_kit.field_visual',
						18 => 'node.type.press_kit',
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_kit.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '497ed8e7-356c-415d-a8a8-438764b7cbad',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.press_kit.field_content',
						2 => 'field.field.node.press_kit.field_content_owner',
						3 => 'field.field.node.press_kit.field_display_title',
						4 => 'field.field.node.press_kit.field_email_owner',
						5 => 'field.field.node.press_kit.field_end_date',
						6 => 'field.field.node.press_kit.field_file',
						7 => 'field.field.node.press_kit.field_highlight',
						8 => 'field.field.node.press_kit.field_industry',
						9 => 'field.field.node.press_kit.field_meta_description',
						10 => 'field.field.node.press_kit.field_meta_title',
						11 => 'field.field.node.press_kit.field_metatags',
						12 => 'field.field.node.press_kit.field_solution',
						13 => 'field.field.node.press_kit.field_start_date',
						14 => 'field.field.node.press_kit.field_subhome',
						15 => 'field.field.node.press_kit.field_visual',
						16 => 'node.type.press_kit',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.press_kit.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'press_kit',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_kit.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.teaser');
$config_group->setData(
	array (
		'uuid' => '13586354-8258-491e-9b6c-6762fd0d17eb',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.press_kit.field_content',
						2 => 'field.field.node.press_kit.field_content_owner',
						3 => 'field.field.node.press_kit.field_display_title',
						4 => 'field.field.node.press_kit.field_email_owner',
						5 => 'field.field.node.press_kit.field_end_date',
						6 => 'field.field.node.press_kit.field_file',
						7 => 'field.field.node.press_kit.field_highlight',
						8 => 'field.field.node.press_kit.field_industry',
						9 => 'field.field.node.press_kit.field_meta_description',
						10 => 'field.field.node.press_kit.field_meta_title',
						11 => 'field.field.node.press_kit.field_metatags',
						12 => 'field.field.node.press_kit.field_solution',
						13 => 'field.field.node.press_kit.field_start_date',
						14 => 'field.field.node.press_kit.field_subhome',
						15 => 'field.field.node.press_kit.field_visual',
						16 => 'node.type.press_kit',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.press_kit.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'press_kit',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
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
						'weight' => 100,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'workbench_moderation_control' =>
					array (
						'weight' => -20,
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
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_release.default
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
						11 => 'field.field.node.press_release.field_market_segment',
						12 => 'field.field.node.press_release.field_meta_description',
						13 => 'field.field.node.press_release.field_meta_title',
						14 => 'field.field.node.press_release.field_metatags',
						15 => 'field.field.node.press_release.field_region',
						16 => 'field.field.node.press_release.field_solution',
						17 => 'field.field.node.press_release.field_start_date',
						18 => 'field.field.node.press_release.field_subhome',
						19 => 'field.field.node.press_release.field_visual',
						20 => 'node.type.press_release',
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
					),
				'field_end_date' =>
					array (
						'weight' => 1,
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
						'weight' => 4,
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
				'field_start_date' =>
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
					),
				'links' =>
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_release.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '658654a7-bc82-4843-be5e-f475ce85c799',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
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
						11 => 'field.field.node.press_release.field_meta_description',
						12 => 'field.field.node.press_release.field_meta_title',
						13 => 'field.field.node.press_release.field_metatags',
						14 => 'field.field.node.press_release.field_solution',
						15 => 'field.field.node.press_release.field_start_date',
						16 => 'field.field.node.press_release.field_subhome',
						17 => 'field.field.node.press_release.field_visual',
						18 => 'node.type.press_release',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.press_release.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'press_release',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
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
			),
		'hidden' =>
			array (
				'field_city' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_country' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.press_release.teaser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.teaser');
$config_group->setData(
	array (
		'uuid' => '1958f083-019d-48c8-964c-caa100ed3100',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
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
						11 => 'field.field.node.press_release.field_meta_description',
						12 => 'field.field.node.press_release.field_meta_title',
						13 => 'field.field.node.press_release.field_metatags',
						14 => 'field.field.node.press_release.field_solution',
						15 => 'field.field.node.press_release.field_start_date',
						16 => 'field.field.node.press_release.field_subhome',
						17 => 'field.field.node.press_release.field_visual',
						18 => 'node.type.press_release',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.press_release.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'press_release',
		'mode' => 'teaser',
		'content' =>
			array (
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
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
						'weight' => 100,
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
				'field_city' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_country' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.product.default
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
						0 => 'field.field.node.product.field_content',
						1 => 'field.field.node.product.field_end_date',
						2 => 'field.field.node.product.field_industry',
						3 => 'field.field.node.product.field_job_profile',
						4 => 'field.field.node.product.field_market_segment',
						5 => 'field.field.node.product.field_meta_description',
						6 => 'field.field.node.product.field_meta_title',
						7 => 'field.field.node.product.field_metatags',
						8 => 'field.field.node.product.field_region',
						9 => 'field.field.node.product.field_solution',
						10 => 'field.field.node.product.field_start_date',
						11 => 'field.field.node.product.field_sub_family',
						12 => 'field.field.node.product.field_subhome',
						13 => 'field.field.node.product.field_top_zone',
						14 => 'node.type.product',
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
				'field_end_date' => true,
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_sub_family' => true,
				'field_subhome' => true,
				'field_top_zone' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.region.default
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
						4 => 'field.field.node.region.field_region',
						5 => 'field.field.node.region.field_start_date',
						6 => 'field.field.node.region.field_visual',
						7 => 'node.type.region',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'user',
					),
			),
		'id' => 'node.region.default',
		'targetEntityType' => 'node',
		'bundle' => 'region',
		'mode' => 'default',
		'content' =>
			array (
				'field_end_date' =>
					array (
						'weight' => 103,
						'label' => 'above',
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
						'weight' => 101,
						'label' => 'above',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'basic_string',
					),
				'field_region' =>
					array (
						'weight' => 104,
						'label' => 'above',
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
						'weight' => 102,
						'label' => 'above',
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
				'links' =>
					array (
						'weight' => 100,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'workbench_moderation_control' =>
					array (
						'weight' => -20,
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
				'field_email_owner' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)

);
$config_group->save(TRUE);

//core.entity_view_display.node.simple_page.default
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_region' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.simple_page.right_linked_content
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.simple_page.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'ea3c53ac-4c9d-43f3-aaa8-518bcab14fd7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.simple_page.field_content',
						2 => 'field.field.node.simple_page.field_content_owner',
						3 => 'field.field.node.simple_page.field_display_title',
						4 => 'field.field.node.simple_page.field_email_owner',
						5 => 'field.field.node.simple_page.field_end_date',
						6 => 'field.field.node.simple_page.field_grouping_title',
						7 => 'field.field.node.simple_page.field_highlight',
						8 => 'field.field.node.simple_page.field_industry',
						9 => 'field.field.node.simple_page.field_meta_description',
						10 => 'field.field.node.simple_page.field_meta_title',
						11 => 'field.field.node.simple_page.field_metatags',
						12 => 'field.field.node.simple_page.field_solution',
						13 => 'field.field.node.simple_page.field_start_date',
						14 => 'field.field.node.simple_page.field_subhome',
						15 => 'node.type.simple_page',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.simple_page.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'simple_page',
		'mode' => 'right_linked_content',
		'content' =>
			array (
				'field_highlight' =>
					array (
						'type' => 'basic_string',
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//core.entity_view_display.node.simple_page.teaser
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
						9 => 'field.field.node.simple_page.field_meta_description',
						10 => 'field.field.node.simple_page.field_meta_title',
						11 => 'field.field.node.simple_page.field_metatags',
						12 => 'field.field.node.simple_page.field_solution',
						13 => 'field.field.node.simple_page.field_start_date',
						14 => 'field.field.node.simple_page.field_subhome',
						15 => 'node.type.simple_page',
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
					),
				'links' =>
					array (
						'weight' => 2,
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
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_grouping_title' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);