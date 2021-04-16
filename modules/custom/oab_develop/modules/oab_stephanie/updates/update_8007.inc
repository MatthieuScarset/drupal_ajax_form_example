<?php

/**
 * Nouvel onglet SEO dans le formulaire de saisie de contenu
 */
//BLOG-POST
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
						1 => 'field.field.node.blog_post.field_area',
						2 => 'field.field.node.blog_post.field_blog',
						3 => 'field.field.node.blog_post.field_content',
						4 => 'field.field.node.blog_post.field_content_owner',
						5 => 'field.field.node.blog_post.field_customer_story',
						6 => 'field.field.node.blog_post.field_display_title',
						7 => 'field.field.node.blog_post.field_email_owner',
						8 => 'field.field.node.blog_post.field_end_date',
						9 => 'field.field.node.blog_post.field_highlight',
						10 => 'field.field.node.blog_post.field_industry',
						11 => 'field.field.node.blog_post.field_meta_description',
						12 => 'field.field.node.blog_post.field_meta_title',
						13 => 'field.field.node.blog_post.field_metatags',
						14 => 'field.field.node.blog_post.field_partner',
						15 => 'field.field.node.blog_post.field_profile',
						16 => 'field.field.node.blog_post.field_solution',
						17 => 'field.field.node.blog_post.field_start_date',
						18 => 'field.field.node.blog_post.field_subhome',
						19 => 'field.field.node.blog_post.field_visual',
						20 => 'field.field.node.blog_post.publish_date',
						21 => 'field.field.node.blog_post.unpublish_date',
						22 => 'node.type.blog_post',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										1 => 'field_blog',
										2 => 'field_solution',
										3 => 'field_area',
										4 => 'field_customer_story',
										5 => 'field_industry',
										6 => 'field_partner',
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
						'weight' => 29,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
					),
				'field_blog' =>
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
				'field_customer_story' =>
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
						'weight' => 17,
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
						'weight' => 32,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
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
						'weight' => 16,
						'settings' =>
							array (
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
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);
//CUSTOMER STORY
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
						1 => 'field.field.node.customer_story.field_area',
						2 => 'field.field.node.customer_story.field_content',
						3 => 'field.field.node.customer_story.field_content_owner',
						4 => 'field.field.node.customer_story.field_customer_story',
						5 => 'field.field.node.customer_story.field_display_title',
						6 => 'field.field.node.customer_story.field_email_owner',
						7 => 'field.field.node.customer_story.field_end_date',
						8 => 'field.field.node.customer_story.field_file',
						9 => 'field.field.node.customer_story.field_highlight',
						10 => 'field.field.node.customer_story.field_industry',
						11 => 'field.field.node.customer_story.field_meta_description',
						12 => 'field.field.node.customer_story.field_meta_title',
						13 => 'field.field.node.customer_story.field_metatags',
						14 => 'field.field.node.customer_story.field_partner',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										1 => 'field_customer_story',
										2 => 'field_partner',
										3 => 'field_solution',
										4 => 'field_industry',
										5 => 'field_area',
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
										3 => 'path',
										4 => 'field_metatags',
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
					),
			),
		'id' => 'node.customer_story.default',
		'targetEntityType' => 'node',
		'bundle' => 'customer_story',
		'mode' => 'default',
		'content' =>
			array (
				'field_area' =>
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
				'field_customer_story' =>
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
						'weight' => 38,
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
						'weight' => 49,
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
						'weight' => 37,
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
//DOCUMENT
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
						1 => 'field.field.node.document.field_area',
						2 => 'field.field.node.document.field_content',
						3 => 'field.field.node.document.field_content_owner',
						4 => 'field.field.node.document.field_customer_story',
						5 => 'field.field.node.document.field_display_title',
						6 => 'field.field.node.document.field_document_type',
						7 => 'field.field.node.document.field_email_owner',
						8 => 'field.field.node.document.field_end_date',
						9 => 'field.field.node.document.field_file',
						10 => 'field.field.node.document.field_highlight',
						11 => 'field.field.node.document.field_industry',
						12 => 'field.field.node.document.field_meta_description',
						13 => 'field.field.node.document.field_meta_title',
						14 => 'field.field.node.document.field_metatags',
						15 => 'field.field.node.document.field_partner',
						16 => 'field.field.node.document.field_solution',
						17 => 'field.field.node.document.field_start_date',
						18 => 'field.field.node.document.field_subhome',
						19 => 'field.field.node.document.field_topic',
						20 => 'field.field.node.document.field_visual',
						21 => 'node.type.document',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										2 => 'field_topic',
										3 => 'field_area',
										4 => 'field_customer_story',
										5 => 'field_industry',
										6 => 'field_partner',
										7 => 'field_solution',
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
										3 => 'path',
										4 => 'field_metatags',
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
					),
			),
		'id' => 'node.document.default',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'default',
		'content' =>
			array (
				'field_area' =>
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
				'field_customer_story' =>
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
						'weight' => 56,
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
						'weight' => 50,
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
						'weight' => 57,
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
						'weight' => 58,
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
				'field_topic' =>
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
						'weight' => 49,
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
//MAGAZINE
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
						3 => 'field.field.node.magazine.field_customer_story',
						4 => 'field.field.node.magazine.field_display_title',
						5 => 'field.field.node.magazine.field_email_owner',
						6 => 'field.field.node.magazine.field_end_date',
						7 => 'field.field.node.magazine.field_highlight',
						8 => 'field.field.node.magazine.field_industry',
						9 => 'field.field.node.magazine.field_meta_description',
						10 => 'field.field.node.magazine.field_meta_title',
						11 => 'field.field.node.magazine.field_metatags',
						12 => 'field.field.node.magazine.field_partner',
						13 => 'field.field.node.magazine.field_solution',
						14 => 'field.field.node.magazine.field_start_date',
						15 => 'field.field.node.magazine.field_subhome',
						16 => 'field.field.node.magazine.field_visual',
						17 => 'node.type.magazine',
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
										2 => 'field_customer_story',
										3 => 'field_partner',
										4 => 'field_industry',
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
										3 => 'path',
										4 => 'field_metatags',
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
				'field_customer_story' =>
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
						'weight' => 21,
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
						'weight' => 20,
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
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);
//PARTNER
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
						8 => 'field.field.node.partner.field_meta_description',
						9 => 'field.field.node.partner.field_meta_title',
						10 => 'field.field.node.partner.field_metatags',
						11 => 'field.field.node.partner.field_partner',
						12 => 'field.field.node.partner.field_start_date',
						13 => 'field.field.node.partner.field_subhome',
						14 => 'field.field.node.partner.field_visual',
						15 => 'node.type.partner',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										1 => 'field_partner',
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
										3 => 'path',
										4 => 'field_metatags',
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
						'weight' => 38,
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
						'weight' => 37,
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
//PRESS KIT
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
						1 => 'field.field.node.press_kit.field_area',
						2 => 'field.field.node.press_kit.field_content',
						3 => 'field.field.node.press_kit.field_content_owner',
						4 => 'field.field.node.press_kit.field_customer_story',
						5 => 'field.field.node.press_kit.field_display_title',
						6 => 'field.field.node.press_kit.field_email_owner',
						7 => 'field.field.node.press_kit.field_end_date',
						8 => 'field.field.node.press_kit.field_file',
						9 => 'field.field.node.press_kit.field_highlight',
						10 => 'field.field.node.press_kit.field_industry',
						11 => 'field.field.node.press_kit.field_meta_description',
						12 => 'field.field.node.press_kit.field_meta_title',
						13 => 'field.field.node.press_kit.field_metatags',
						14 => 'field.field.node.press_kit.field_partner',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										1 => 'field_customer_story',
										2 => 'field_partner',
										3 => 'field_industry',
										4 => 'field_solution',
										5 => 'field_area',
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
										3 => 'path',
										4 => 'field_metatags',
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
					),
			),
		'id' => 'node.press_kit.default',
		'targetEntityType' => 'node',
		'bundle' => 'press_kit',
		'mode' => 'default',
		'content' =>
			array (
				'field_area' =>
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
				'field_customer_story' =>
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
						'weight' => 45,
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
						'weight' => 52,
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
						'weight' => 44,
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
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);
//PRESS RELEASE
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
						1 => 'field.field.node.press_release.field_area',
						2 => 'field.field.node.press_release.field_city',
						3 => 'field.field.node.press_release.field_content',
						4 => 'field.field.node.press_release.field_content_owner',
						5 => 'field.field.node.press_release.field_country',
						6 => 'field.field.node.press_release.field_customer_story',
						7 => 'field.field.node.press_release.field_display_title',
						8 => 'field.field.node.press_release.field_email_owner',
						9 => 'field.field.node.press_release.field_end_date',
						10 => 'field.field.node.press_release.field_file',
						11 => 'field.field.node.press_release.field_highlight',
						12 => 'field.field.node.press_release.field_industry',
						13 => 'field.field.node.press_release.field_meta_description',
						14 => 'field.field.node.press_release.field_meta_title',
						15 => 'field.field.node.press_release.field_metatags',
						16 => 'field.field.node.press_release.field_partner',
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
										2 => 'group_publish',
										3 => 'group_seo',
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
										1 => 'field_customer_story',
										2 => 'field_solution',
										3 => 'field_industry',
										4 => 'field_partner',
										5 => 'field_area',
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
										3 => 'field_metatags',
										4 => 'path',
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
					),
			),
		'id' => 'node.press_release.default',
		'targetEntityType' => 'node',
		'bundle' => 'press_release',
		'mode' => 'default',
		'content' =>
			array (
				'field_area' =>
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
				'field_customer_story' =>
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
						'weight' => 38,
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
						'weight' => 52,
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
						'weight' => 39,
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
//PAGE SIMPLE
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
										1 => 'field_customer_story',
										2 => 'field_industry',
										3 => 'field_solution',
										4 => 'field_partner',
										5 => 'field_area',
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
										3 => 'path',
										4 => 'field_metatags',
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
		'id' => 'node.simple_page.default',
		'targetEntityType' => 'node',
		'bundle' => 'simple_page',
		'mode' => 'default',
		'content' =>
			array (
				'field_area' =>
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
				'field_customer_story' =>
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
						'weight' => 28,
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
						'weight' => 17,
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
						'weight' => 29,
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
						'weight' => 16,
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
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);