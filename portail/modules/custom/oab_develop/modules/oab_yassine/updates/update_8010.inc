<?php

// image style document 210*270px
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.document_visual_image');
$config_group->setData(
	array (
		'uuid' => '322b06f9-a62d-4dda-8b16-afcb7003404b',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'document_visual_image',
		'label' => 'Document visual image',
		'effects' =>
			array (
				'172a8680-0908-4c8b-90aa-58da3beac3f9' =>
					array (
						'uuid' => '172a8680-0908-4c8b-90aa-58da3beac3f9',
						'id' => 'image_scale',
						'weight' => 2,
						'data' =>
							array (
								'width' => 210,
								'height' => 270,
								'upscale' => false,
							),
					),
			),
	)
);
$config_group->save(TRUE);

// image style media view
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.document_visual');
$config_group->setData(
	array (
		'uuid' => '3f58c828-676d-4996-8178-b97a04391ee3',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'media_entity',
					),
			),
		'id' => 'media.document_visual',
		'label' => 'Document visual',
		'targetEntityType' => 'media',
		'cache' => true,
	)
);
$config_group->save(TRUE);

// image style media view display
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.media.image.document_visual');
$config_group->setData(
	array (
		'uuid' => 'db630192-41a0-4bda-904f-7a6d1fbcf698',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.media.document_visual',
						1 => 'field.field.media.image.field_image',
						2 => 'field.field.media.image.field_tags',
						3 => 'field.field.media.image.field_thematic',
						4 => 'image.style.document_visual_image',
						5 => 'media_entity.bundle.image',
					),
				'module' =>
					array (
						0 => 'image',
					),
			),
		'id' => 'media.image.document_visual',
		'targetEntityType' => 'media',
		'bundle' => 'image',
		'mode' => 'document_visual',
		'content' =>
			array (
				'field_image' =>
					array (
						'weight' => 2,
						'label' => 'hidden',
						'settings' =>
							array (
								'image_style' => 'document_visual_image',
								'image_link' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'image',
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'created' => true,
				'field_tags' => true,
				'field_thematic' => true,
				'langcode' => true,
				'name' => true,
				'thumbnail' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);


// Node Document view display
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
						18 => 'field.field.node.document.field_thematic',
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
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
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