<?php

// industrie top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_top_zone');
$config_group->setData(
	array (
		'uuid' => '14c25fb2-1379-4e4c-b4ba-431ad68bb979',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_top_zone',
						1 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'text',
					),
			),
		'id' => 'node.industry.field_top_zone',
		'field_name' => 'field_top_zone',
		'entity_type' => 'node',
		'bundle' => 'industry',
		'label' => 'Top zone',
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
		'field_type' => 'text_long',
	)
);
$config_group->save(TRUE);

// industrie top zone BG
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_top_zone_background');
$config_group->setData(
	array (
		'uuid' => 'c5990b41-9a90-464e-9a50-02780ef5f18d',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_top_zone_background',
						1 => 'media_entity.bundle.image',
						2 => 'node.type.industry',
					),
			),
		'id' => 'node.industry.field_top_zone_background',
		'field_name' => 'field_top_zone_background',
		'entity_type' => 'node',
		'bundle' => 'industry',
		'label' => 'Top zone background',
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

// industrie form_display
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
						6 => 'field.field.node.industry.field_start_date',
						7 => 'field.field.node.industry.field_top_zone',
						8 => 'field.field.node.industry.field_top_zone_background',
						9 => 'field.field.node.industry.field_visual',
						10 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'path',
						3 => 'text',
						4 => 'workbench_moderation',
					),
			),
		'id' => 'node.industry.default',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
		'mode' => 'default',
		'content' =>
			array (
				'created' =>
					array (
						'type' => 'datetime_timestamp',
						'weight' => 3,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'field_content_owner' =>
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
				'field_email_owner' =>
					array (
						'type' => 'string_textfield',
						'weight' => 13,
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
						'weight' => 12,
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
				'field_start_date' =>
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
				'field_top_zone' =>
					array (
						'type' => 'text_textarea',
						'weight' => 15,
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
						'weight' => 14,
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
						'weight' => 10,
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
						'weight' => 6,
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
						'weight' => 4,
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'sticky' =>
					array (
						'type' => 'boolean_checkbox',
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 5,
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'title' =>
					array (
						'type' => 'string_textfield',
						'weight' => 0,
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
				'uid' =>
					array (
						'type' => 'entity_reference_autocomplete',
						'weight' => 2,
						'settings' =>
							array (
								'match_operator' => 'CONTAINS',
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
			),
	)
);
$config_group->save(TRUE);

// solution top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_top_zone');
$config_group->setData(
	array (
		'uuid' => '5ca38a72-7f1f-422e-a47d-f1351990f6a8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_top_zone',
						1 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'text',
					),
			),
		'id' => 'node.solution.field_top_zone',
		'field_name' => 'field_top_zone',
		'entity_type' => 'node',
		'bundle' => 'solution',
		'label' => 'Top zone',
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
		'field_type' => 'text_long',
	)
);
$config_group->save(TRUE);

// solution top zone BG
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_top_zone_background');
$config_group->setData(
	array (
		'uuid' => '59c7cbbd-7220-4c4f-91b5-b45b0e599abd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_top_zone_background',
						1 => 'media_entity.bundle.image',
						2 => 'node.type.solution',
					),
			),
		'id' => 'node.solution.field_top_zone_background',
		'field_name' => 'field_top_zone_background',
		'entity_type' => 'node',
		'bundle' => 'solution',
		'label' => 'Top zone background',
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

// solution form_display
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
						5 => 'field.field.node.solution.field_solution',
						6 => 'field.field.node.solution.field_start_date',
						7 => 'field.field.node.solution.field_top_zone',
						8 => 'field.field.node.solution.field_top_zone_background',
						9 => 'field.field.node.solution.field_visual',
						10 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'path',
						3 => 'text',
						4 => 'workbench_moderation',
					),
			),
		'id' => 'node.solution.default',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
		'mode' => 'default',
		'content' =>
			array (
				'created' =>
					array (
						'type' => 'datetime_timestamp',
						'weight' => 3,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'field_content_owner' =>
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
				'field_email_owner' =>
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
				'field_end_date' =>
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
				'field_solution' =>
					array (
						'weight' => 13,
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
				'field_start_date' =>
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
				'field_top_zone' =>
					array (
						'type' => 'text_textarea',
						'weight' => 15,
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
						'weight' => 14,
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
						'weight' => 10,
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
						'weight' => 6,
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
						'weight' => 4,
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'sticky' =>
					array (
						'type' => 'boolean_checkbox',
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 5,
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'title' =>
					array (
						'type' => 'string_textfield',
						'weight' => 0,
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
				'uid' =>
					array (
						'type' => 'entity_reference_autocomplete',
						'weight' => 2,
						'settings' =>
							array (
								'match_operator' => 'CONTAINS',
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
			),
	)
);
$config_group->save(TRUE);

// image style top zone 550px hauteur
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.top_zone_big');
$config_group->setData(
	array (
		'uuid' => 'c55bb1bd-dbd2-41fe-b153-d7ef6d60282d',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'top_zone_big',
		'label' => 'Top zone big',
		'effects' =>
			array (
				'cb946ff7-285a-4ecd-b82c-b55375a0ac81' =>
					array (
						'uuid' => 'cb946ff7-285a-4ecd-b82c-b55375a0ac81',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 1400,
								'height' => 550,
							),
					),
			),
	)
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();