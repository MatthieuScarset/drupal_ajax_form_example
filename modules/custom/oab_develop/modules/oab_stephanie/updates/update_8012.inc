<?php
/**
 * Masque en FO les champs meta title, meta description, owner et email owner
 */

//BLOG POST
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
						'weight' => 118,
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
						'weight' => 114,
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
						'weight' => 109,
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
						'weight' => 115,
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
						'weight' => 103,
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
						'weight' => 101,
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
						'weight' => 116,
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
						'weight' => 110,
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
						'weight' => 117,
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
						'weight' => 108,
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
				'field_solution' =>
					array (
						'weight' => 107,
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
						'weight' => 102,
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
						'weight' => 119,
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
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_visual' => true,
				'langcode' => true,
				'publish_date' => true,
				'unpublish_date' => true,
			),
	)
);
$config_group->save(TRUE);

//COUNTRY
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
						0 => 'field.field.node.country.field_content_owner',
						1 => 'field.field.node.country.field_email_owner',
						2 => 'field.field.node.country.field_end_date',
						3 => 'field.field.node.country.field_highlight',
						4 => 'field.field.node.country.field_start_date',
						5 => 'field.field.node.country.field_visual',
						6 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'user',
					),
			),
		'id' => 'node.country.default',
		'targetEntityType' => 'node',
		'bundle' => 'country',
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

//CUSTOMER STORY
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
						0 => 'field.field.node.customer_story.field_area',
						1 => 'field.field.node.customer_story.field_content',
						2 => 'field.field.node.customer_story.field_content_owner',
						3 => 'field.field.node.customer_story.field_customer_story',
						4 => 'field.field.node.customer_story.field_display_title',
						5 => 'field.field.node.customer_story.field_email_owner',
						6 => 'field.field.node.customer_story.field_end_date',
						7 => 'field.field.node.customer_story.field_file',
						8 => 'field.field.node.customer_story.field_highlight',
						9 => 'field.field.node.customer_story.field_industry',
						10 => 'field.field.node.customer_story.field_meta_description',
						11 => 'field.field.node.customer_story.field_meta_title',
						12 => 'field.field.node.customer_story.field_metatags',
						13 => 'field.field.node.customer_story.field_partner',
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
				'field_area' =>
					array (
						'weight' => 114,
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
						'weight' => 106,
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
						'weight' => 110,
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
						'weight' => 117,
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
						'weight' => 106,
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
						'weight' => 101,
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
						'weight' => 113,
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
						'weight' => 115,
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
						'weight' => 112,
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
				'field_solution' =>
					array (
						'weight' => 111,
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
						'weight' => 116,
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
						'weight' => 118,
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
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//DOCUMENT
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
						0 => 'field.field.node.document.field_area',
						1 => 'field.field.node.document.field_content',
						2 => 'field.field.node.document.field_content_owner',
						3 => 'field.field.node.document.field_customer_story',
						4 => 'field.field.node.document.field_display_title',
						5 => 'field.field.node.document.field_document_type',
						6 => 'field.field.node.document.field_email_owner',
						7 => 'field.field.node.document.field_end_date',
						8 => 'field.field.node.document.field_file',
						9 => 'field.field.node.document.field_highlight',
						10 => 'field.field.node.document.field_industry',
						11 => 'field.field.node.document.field_meta_description',
						12 => 'field.field.node.document.field_meta_title',
						13 => 'field.field.node.document.field_metatags',
						14 => 'field.field.node.document.field_partner',
						15 => 'field.field.node.document.field_solution',
						16 => 'field.field.node.document.field_start_date',
						17 => 'field.field.node.document.field_subhome',
						18 => 'field.field.node.document.field_topic',
						19 => 'field.field.node.document.field_visual',
						20 => 'node.type.document',
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
				'field_area' =>
					array (
						'weight' => 104,
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
						'weight' => 112,
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
						'weight' => 105,
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
				'field_document_type' =>
					array (
						'weight' => 118,
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
						'weight' => 102,
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
						'weight' => 106,
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
						'weight' => 114,
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
						'weight' => 108,
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
						'weight' => 111,
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
						'weight' => 109,
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
				'field_solution' =>
					array (
						'weight' => 110,
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
						'weight' => 103,
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
						'weight' => 120,
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
				'field_topic' =>
					array (
						'weight' => 119,
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
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//INDUSTRY
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
						5 => 'field.field.node.industry.field_start_date',
						6 => 'field.field.node.industry.field_visual',
						7 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'user',
					),
			),
		'id' => 'node.industry.default',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
		'mode' => 'default',
		'content' =>
			array (
				'field_end_date' =>
					array (
						'weight' => 4,
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
						'weight' => 2,
						'label' => 'above',
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
						'weight' => 3,
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
				'field_email_owner' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//MAGAZINE
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
						2 => 'field.field.node.magazine.field_customer_story',
						3 => 'field.field.node.magazine.field_display_title',
						4 => 'field.field.node.magazine.field_email_owner',
						5 => 'field.field.node.magazine.field_end_date',
						6 => 'field.field.node.magazine.field_highlight',
						7 => 'field.field.node.magazine.field_industry',
						8 => 'field.field.node.magazine.field_meta_description',
						9 => 'field.field.node.magazine.field_meta_title',
						10 => 'field.field.node.magazine.field_metatags',
						11 => 'field.field.node.magazine.field_partner',
						12 => 'field.field.node.magazine.field_solution',
						13 => 'field.field.node.magazine.field_start_date',
						14 => 'field.field.node.magazine.field_subhome',
						15 => 'field.field.node.magazine.field_visual',
						16 => 'node.type.magazine',
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
						'weight' => 10,
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
				'field_metatags' =>
					array (
						'weight' => 11,
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
				'field_subhome' =>
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
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//PARTNER
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
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//PRESS KIT
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
						0 => 'field.field.node.press_kit.field_area',
						1 => 'field.field.node.press_kit.field_content',
						2 => 'field.field.node.press_kit.field_content_owner',
						3 => 'field.field.node.press_kit.field_customer_story',
						4 => 'field.field.node.press_kit.field_display_title',
						5 => 'field.field.node.press_kit.field_email_owner',
						6 => 'field.field.node.press_kit.field_end_date',
						7 => 'field.field.node.press_kit.field_file',
						8 => 'field.field.node.press_kit.field_highlight',
						9 => 'field.field.node.press_kit.field_industry',
						10 => 'field.field.node.press_kit.field_meta_description',
						11 => 'field.field.node.press_kit.field_meta_title',
						12 => 'field.field.node.press_kit.field_metatags',
						13 => 'field.field.node.press_kit.field_partner',
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
				'field_area' =>
					array (
						'weight' => 14,
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
				'field_solution' =>
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
						'weight' => 15,
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
			),
	)
);
$config_group->save(TRUE);

//PRESS RELEASE
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
						0 => 'field.field.node.press_release.field_area',
						1 => 'field.field.node.press_release.field_city',
						2 => 'field.field.node.press_release.field_content',
						3 => 'field.field.node.press_release.field_content_owner',
						4 => 'field.field.node.press_release.field_country',
						5 => 'field.field.node.press_release.field_customer_story',
						6 => 'field.field.node.press_release.field_display_title',
						7 => 'field.field.node.press_release.field_email_owner',
						8 => 'field.field.node.press_release.field_end_date',
						9 => 'field.field.node.press_release.field_file',
						10 => 'field.field.node.press_release.field_highlight',
						11 => 'field.field.node.press_release.field_industry',
						12 => 'field.field.node.press_release.field_meta_description',
						13 => 'field.field.node.press_release.field_meta_title',
						14 => 'field.field.node.press_release.field_metatags',
						15 => 'field.field.node.press_release.field_partner',
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
				'field_area' =>
					array (
						'weight' => 117,
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
				'field_city' =>
					array (
						'weight' => 118,
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
						'weight' => 110,
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
						'weight' => 119,
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
				'field_customer_story' =>
					array (
						'weight' => 113,
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
						'weight' => 102,
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
						'weight' => 111,
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
						'weight' => 109,
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
						'weight' => 115,
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
						'weight' => 104,
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
						'weight' => 116,
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
				'field_solution' =>
					array (
						'weight' => 114,
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
						'weight' => 103,
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
						'weight' => 120,
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
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//REGION
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
						4 => 'field.field.node.region.field_start_date',
						5 => 'field.field.node.region.field_visual',
						6 => 'node.type.region',
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
				'field_content' =>
					array (
						'weight' => 7,
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
				'field_end_date' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//SOLUTION
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
						4 => 'field.field.node.solution.field_solution',
						5 => 'field.field.node.solution.field_start_date',
						6 => 'field.field.node.solution.field_visual',
						7 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'user',
					),
			),
		'id' => 'node.solution.default',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
				'field_solution' =>
					array (
						'weight' => 107,
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



