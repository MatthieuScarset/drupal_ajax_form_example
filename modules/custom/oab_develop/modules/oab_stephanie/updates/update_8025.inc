<?php

//RELATED CONTENT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.related_content');
$config_group->setData(
	array (
		'uuid' => 'fce1ee2d-391f-4a6c-9054-87ee68ef0eff',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.related_content',
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
						0 => 'user',
					),
			),
		'id' => 'node.document.related_content',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'related_content',
		'content' =>
			array (
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
					),
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
								'view_mode' => 'default',
								'link' => false,
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
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_region' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
				'links' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_view_display.node.document.related_content');
$config_group->set('content.field_visual', array (
	'type' => 'entity_reference_entity_view',
	'weight' => 0,
	'label' => 'hidden',
	'settings' =>
		array (
			'view_mode' => 'related_content_image',
			'link' => false,
		),
	'third_party_settings' =>
		array (
		),
));
$config_group->save(TRUE);

//SUBHOME
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.subhome');
$config_group->setData(
	array (
		'uuid' => '1c9fb3d3-3e32-4522-95aa-99e73cc671dc',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.subhome',
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
						1 => 'user',
					),
			),
		'id' => 'node.document.subhome',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'subhome',
		'content' =>
			array (
				'field_file' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 3,
						'label' => 'hidden',
						'settings' =>
							array (
								'view_mode' => 'default',
								'link' => false,
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_solution' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 2,
						'label' => 'hidden',
						'settings' =>
							array (
								'view_mode' => 'default',
								'link' => false,
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_start_date' =>
					array (
						'type' => 'datetime_default',
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
								'format_type' => 'medium',
								'timezone_override' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 1,
						'label' => 'hidden',
						'settings' =>
							array (
								'view_mode' => 'subhome_image',
								'link' => false,
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
				'field_highlight' => true,
				'field_industry' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_region' => true,
				'field_subhome' => true,
				'langcode' => true,
				'links' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

//RIGHT LINKED CONTENT
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