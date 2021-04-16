<?php
/**
 * Suppression du field_industry dans Industry
	*/

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
						1 => 'field.field.node.industry.field_content',
						2 => 'field.field.node.industry.field_content_owner',
						3 => 'field.field.node.industry.field_display_title',
						4 => 'field.field.node.industry.field_email_owner',
						5 => 'field.field.node.industry.field_end_date',
						6 => 'field.field.node.industry.field_highlight',
						7 => 'field.field.node.industry.field_local_nav',
						8 => 'field.field.node.industry.field_meta_description',
						9 => 'field.field.node.industry.field_meta_title',
						10 => 'field.field.node.industry.field_start_date',
						11 => 'field.field.node.industry.field_top_zone',
						12 => 'field.field.node.industry.field_top_zone_background',
						13 => 'field.field.node.industry.field_visual',
						14 => 'node.type.industry',
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
										2 => 'field_display_title',
										3 => 'field_highlight',
										4 => 'field_top_zone',
										5 => 'field_top_zone_background',
										6 => 'field_visual',
										7 => 'field_local_nav',
										8 => 'field_content',
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
										1 => 'field_job_profile',
										2 => 'field_solution',
										3 => 'field_region',
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
										0 => 'field_meta_title',
										1 => 'field_meta_description',
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
								'weight' => 12,
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
						'weight' => 11,
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
				'field_job_profile' =>
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
				'field_local_nav' =>
					array (
						'weight' => 9,
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
						'weight' => 33,
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
						'weight' => 32,
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
				'field_solution' =>
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
						'weight' => 6,
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
						'weight' => 7,
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
						'weight' => 14,
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
						'weight' => 13,
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
						0 => 'field.field.node.industry.field_content',
						1 => 'field.field.node.industry.field_content_owner',
						2 => 'field.field.node.industry.field_display_title',
						3 => 'field.field.node.industry.field_email_owner',
						4 => 'field.field.node.industry.field_end_date',
						5 => 'field.field.node.industry.field_highlight',
						6 => 'field.field.node.industry.field_local_nav',
						7 => 'field.field.node.industry.field_meta_description',
						8 => 'field.field.node.industry.field_meta_title',
						9 => 'field.field.node.industry.field_start_date',
						10 => 'field.field.node.industry.field_top_zone',
						11 => 'field.field.node.industry.field_top_zone_background',
						12 => 'field.field.node.industry.field_visual',
						13 => 'node.type.industry',
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
				'field_display_title' =>
					array (
						'weight' => 8,
						'label' => 'hidden',
						'settings' =>
							array (
								'format' => 'default',
								'format_custom_false' => '',
								'format_custom_true' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'boolean',
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
				'field_job_profile' =>
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
				'field_meta_description' =>
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
				'field_meta_title' =>
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
				'field_region' =>
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
						'region' => 'content',
					),
				'field_solution' =>
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
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_market_segment' => true,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.related_content');
$config_group->setData(
	array (
		'uuid' => '1c5ad6a4-3f5f-4fb1-952c-2e85a0ccce0b',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.related_content',
						1 => 'field.field.node.industry.field_content',
						2 => 'field.field.node.industry.field_content_owner',
						3 => 'field.field.node.industry.field_display_title',
						4 => 'field.field.node.industry.field_email_owner',
						5 => 'field.field.node.industry.field_end_date',
						6 => 'field.field.node.industry.field_highlight',
						7 => 'field.field.node.industry.field_local_nav',
						8 => 'field.field.node.industry.field_meta_description',
						9 => 'field.field.node.industry.field_meta_title',
						10 => 'field.field.node.industry.field_start_date',
						11 => 'field.field.node.industry.field_top_zone',
						12 => 'field.field.node.industry.field_top_zone_background',
						13 => 'field.field.node.industry.field_visual',
						14 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.industry.related_content',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
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
						'region' => 'content',
					),
				'field_visual' =>
					array (
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'langcode' => true,
				'links' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'b2a2d4ec-4dc5-43d4-855f-229c95d43018',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.industry.field_content',
						2 => 'field.field.node.industry.field_content_owner',
						3 => 'field.field.node.industry.field_display_title',
						4 => 'field.field.node.industry.field_email_owner',
						5 => 'field.field.node.industry.field_end_date',
						6 => 'field.field.node.industry.field_highlight',
						7 => 'field.field.node.industry.field_local_nav',
						8 => 'field.field.node.industry.field_meta_description',
						9 => 'field.field.node.industry.field_meta_title',
						10 => 'field.field.node.industry.field_start_date',
						11 => 'field.field.node.industry.field_top_zone',
						12 => 'field.field.node.industry.field_top_zone_background',
						13 => 'field.field.node.industry.field_visual',
						14 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.industry.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
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
						'region' => 'content',
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.teaser');
$config_group->setData(
	array (
		'uuid' => 'e0152ba5-2071-4fc5-80a4-526722bcab12',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.industry.field_content',
						2 => 'field.field.node.industry.field_content_owner',
						3 => 'field.field.node.industry.field_display_title',
						4 => 'field.field.node.industry.field_email_owner',
						5 => 'field.field.node.industry.field_end_date',
						6 => 'field.field.node.industry.field_highlight',
						7 => 'field.field.node.industry.field_local_nav',
						8 => 'field.field.node.industry.field_meta_description',
						9 => 'field.field.node.industry.field_meta_title',
						10 => 'field.field.node.industry.field_start_date',
						11 => 'field.field.node.industry.field_top_zone',
						12 => 'field.field.node.industry.field_top_zone_background',
						13 => 'field.field.node.industry.field_visual',
						14 => 'node.type.industry',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.industry.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'industry',
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
						'region' => 'content',
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
						'region' => 'content',
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
						'region' => 'content',
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
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.industry.field_industry');
$config_group->delete();

	/**
	 * Suppression du field_industry et field_solution dans Solution
	 */

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
						1 => 'field.field.node.solution.field_content',
						2 => 'field.field.node.solution.field_content_owner',
						3 => 'field.field.node.solution.field_display_title',
						4 => 'field.field.node.solution.field_email_owner',
						5 => 'field.field.node.solution.field_end_date',
						6 => 'field.field.node.solution.field_highlight',
						7 => 'field.field.node.solution.field_local_nav',
						8 => 'field.field.node.solution.field_meta_description',
						9 => 'field.field.node.solution.field_meta_title',
						10 => 'field.field.node.solution.field_start_date',
						11 => 'field.field.node.solution.field_top_zone',
						12 => 'field.field.node.solution.field_top_zone_background',
						13 => 'field.field.node.solution.field_visual',
						14 => 'node.type.solution',
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
										2 => 'field_display_title',
										3 => 'field_highlight',
										4 => 'field_top_zone',
										5 => 'field_top_zone_background',
										6 => 'field_visual',
										7 => 'field_local_nav',
										8 => 'field_content',
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
										1 => 'field_industry',
										2 => 'field_region',
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
										0 => 'field_meta_title',
										1 => 'field_meta_description',
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
						'weight' => 11,
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
				'field_local_nav' =>
					array (
						'weight' => 9,
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
						'weight' => 19,
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
						'weight' => 30,
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
						'weight' => 29,
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
				'field_top_zone' =>
					array (
						'type' => 'text_textarea',
						'weight' => 6,
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
						'weight' => 7,
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
						'settings' =>
							array (
								'display_label' => true,
							),
						'weight' => 16,
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
						0 => 'field.field.node.solution.field_content',
						1 => 'field.field.node.solution.field_content_owner',
						2 => 'field.field.node.solution.field_display_title',
						3 => 'field.field.node.solution.field_email_owner',
						4 => 'field.field.node.solution.field_end_date',
						5 => 'field.field.node.solution.field_highlight',
						6 => 'field.field.node.solution.field_local_nav',
						7 => 'field.field.node.solution.field_meta_description',
						8 => 'field.field.node.solution.field_meta_title',
						9 => 'field.field.node.solution.field_start_date',
						10 => 'field.field.node.solution.field_top_zone',
						11 => 'field.field.node.solution.field_top_zone_background',
						12 => 'field.field.node.solution.field_visual',
						13 => 'node.type.solution',
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
				'field_display_title' =>
					array (
						'weight' => 8,
						'label' => 'hidden',
						'settings' =>
							array (
								'format' => 'default',
								'format_custom_false' => '',
								'format_custom_true' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'boolean',
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
				'field_meta_description' =>
					array (
						'weight' => 11,
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
				'field_region' =>
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
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.related_content');
$config_group->setData(
	array (
		'uuid' => '338aec56-fb47-4e6a-88dd-58e8ba5fafe8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.related_content',
						1 => 'field.field.node.solution.field_content',
						2 => 'field.field.node.solution.field_content_owner',
						3 => 'field.field.node.solution.field_display_title',
						4 => 'field.field.node.solution.field_email_owner',
						5 => 'field.field.node.solution.field_end_date',
						6 => 'field.field.node.solution.field_highlight',
						7 => 'field.field.node.solution.field_local_nav',
						8 => 'field.field.node.solution.field_meta_description',
						9 => 'field.field.node.solution.field_meta_title',
						10 => 'field.field.node.solution.field_start_date',
						11 => 'field.field.node.solution.field_top_zone',
						12 => 'field.field.node.solution.field_top_zone_background',
						13 => 'field.field.node.solution.field_visual',
						14 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.solution.related_content',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
						'region' => 'content',
					),
				'field_visual' =>
					array (
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'langcode' => true,
				'links' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'd4b16fa8-e7fb-429a-991c-d03087204dc9',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.solution.field_content',
						2 => 'field.field.node.solution.field_content_owner',
						3 => 'field.field.node.solution.field_display_title',
						4 => 'field.field.node.solution.field_email_owner',
						5 => 'field.field.node.solution.field_end_date',
						6 => 'field.field.node.solution.field_highlight',
						7 => 'field.field.node.solution.field_local_nav',
						8 => 'field.field.node.solution.field_meta_description',
						9 => 'field.field.node.solution.field_meta_title',
						10 => 'field.field.node.solution.field_start_date',
						11 => 'field.field.node.solution.field_top_zone',
						12 => 'field.field.node.solution.field_top_zone_background',
						13 => 'field.field.node.solution.field_visual',
						14 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.solution.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
						'region' => 'content',
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content' => true,
				'field_content_owner' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.teaser');
$config_group->setData(
	array (
		'uuid' => '6d7a0a23-2edc-4fa0-b9d0-17e6245e8ba0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.solution.field_content',
						2 => 'field.field.node.solution.field_content_owner',
						3 => 'field.field.node.solution.field_display_title',
						4 => 'field.field.node.solution.field_email_owner',
						5 => 'field.field.node.solution.field_end_date',
						6 => 'field.field.node.solution.field_highlight',
						7 => 'field.field.node.solution.field_local_nav',
						8 => 'field.field.node.solution.field_meta_description',
						9 => 'field.field.node.solution.field_meta_title',
						10 => 'field.field.node.solution.field_start_date',
						11 => 'field.field.node.solution.field_top_zone',
						12 => 'field.field.node.solution.field_top_zone_background',
						13 => 'field.field.node.solution.field_visual',
						14 => 'node.type.solution',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.solution.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'solution',
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
						'region' => 'content',
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
						'region' => 'content',
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
						'region' => 'content',
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
				'field_local_nav' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.solution.field_industry');
$config_group->delete();
$config_group = $config_factory->getEditable('field.field.node.solution.field_solution');
$config_group->delete();

	/**
	 * Suppression du field_industry et field_solution dans Region
	 */

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
						1 => 'field.field.node.region.field_content',
						2 => 'field.field.node.region.field_content_owner',
						3 => 'field.field.node.region.field_display_title',
						4 => 'field.field.node.region.field_email_owner',
						5 => 'field.field.node.region.field_end_date',
						6 => 'field.field.node.region.field_highlight',
						8 => 'field.field.node.region.field_meta_description',
						9 => 'field.field.node.region.field_meta_title',
						12 => 'field.field.node.region.field_start_date',
						13 => 'field.field.node.region.field_top_zone',
						14 => 'field.field.node.region.field_top_zone_background',
						15 => 'field.field.node.region.field_visual',
						16 => 'node.type.region',
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
										2 => 'field_display_title',
										3 => 'field_highlight',
										4 => 'field_top_zone',
										5 => 'field_top_zone_background',
										6 => 'field_visual',
										7 => 'field_content',
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
										1 => 'field_solution',
										2 => 'field_industry',
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
										0 => 'field_meta_title',
										1 => 'field_meta_description',
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
								'weight' => 12,
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
						'weight' => 9,
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

				'field_job_profile' =>
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
						'region' => 'content',
					),
				'field_meta_title' =>
					array (
						'weight' => 33,
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
						'type' => 'entity_browser_entity_reference',
						'region' => 'content',
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
						'weight' => 14,
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
						'weight' => 13,
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
						0 => 'field.field.node.region.field_content',
						1 => 'field.field.node.region.field_content_owner',
						2 => 'field.field.node.region.field_display_title',
						3 => 'field.field.node.region.field_email_owner',
						4 => 'field.field.node.region.field_end_date',
						5 => 'field.field.node.region.field_highlight',
						7 => 'field.field.node.region.field_meta_description',
						8 => 'field.field.node.region.field_meta_title',
						11 => 'field.field.node.region.field_start_date',
						12 => 'field.field.node.region.field_top_zone',
						13 => 'field.field.node.region.field_top_zone_background',
						14 => 'field.field.node.region.field_visual',
						15 => 'node.type.region',
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
				'field_display_title' =>
					array (
						'weight' => 12,
						'label' => 'hidden',
						'settings' =>
							array (
								'format' => 'default',
								'format_custom_false' => '',
								'format_custom_true' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'boolean',
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
				'field_meta_description' =>
					array (
						'weight' => 11,
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
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
				'field_start_date' => true,
				'field_top_zone' => true,
				'field_top_zone_background' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.region.field_industry');
$config_group->delete();
$config_group = $config_factory->getEditable('field.field.node.region.field_solution');
$config_group->delete();
$config_group = $config_factory->getEditable('field.field.node.region.field_region');
$config_group->delete();

	/**
	 * Suppression du field_industry et field_solution dans Country
	 */


$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_region');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'type' => 'entity_reference',
	))->save();
}
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'country', 'field_region');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_region',
		'entity_type' => 'node',
		'bundle' => 'country',
		'label' => 'Region',
		'required' => FALSE,
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

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
						3 => 'field.field.node.country.field_display_title',
						4 => 'field.field.node.country.field_email_owner',
						5 => 'field.field.node.country.field_end_date',
						6 => 'field.field.node.country.field_highlight',
						7 => 'field.field.node.country.field_local_nav',
						8 => 'field.field.node.country.field_meta_description',
						9 => 'field.field.node.country.field_meta_title',
						10 => 'field.field.node.country.field_region',
						11 => 'field.field.node.country.field_start_date',
						12 => 'field.field.node.country.field_visual',
						13 => 'node.type.country',
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
										2 => 'field_display_title',
										3 => 'field_highlight',
										4 => 'field_visual',
										5 => 'field_content',
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
										0 => 'field_meta_title',
										1 => 'field_meta_description',
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
								'weight' => 18,
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
						'weight' => 9,
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
						'type' => 'text_textarea',
						'weight' => 6,
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
						'region' => 'content',
					),
				'field_meta_title' =>
					array (
						'weight' => 33,
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
				'field_solution' =>
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
						'type' => 'entity_browser_entity_reference',
						'region' => 'content',
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
						'weight' => 20,
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
						'weight' => 19,
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
						6 => 'field.field.node.country.field_local_nav',
						7 => 'field.field.node.country.field_meta_description',
						8 => 'field.field.node.country.field_meta_title',
						9 => 'field.field.node.country.field_region',
						10 => 'field.field.node.country.field_start_date',
						11 => 'field.field.node.country.field_visual',
						12 => 'node.type.country',
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
				'field_display_title' =>
					array (
						'weight' => 8,
						'label' => 'hidden',
						'settings' =>
							array (
								'format' => 'default',
								'format_custom_false' => '',
								'format_custom_true' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'boolean',
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
				'field_industry' =>
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
				'field_meta_description' =>
					array (
						'weight' => 12,
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
						'weight' => 11,
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
				'field_region' =>
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
						'region' => 'content',
					),
				'field_solution' =>
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
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_job_profile' => true,
				'field_market_segment' => true,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.related_content');
$config_group->setData(
	array (
		'uuid' => '4cca6493-59ca-4387-aa18-d68e182f50da',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.related_content',
						1 => 'field.field.node.country.field_content_owner',
						2 => 'field.field.node.country.field_email_owner',
						3 => 'field.field.node.country.field_end_date',
						4 => 'field.field.node.country.field_highlight',
						5 => 'field.field.node.country.field_start_date',
						6 => 'field.field.node.country.field_visual',
						7 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.country.related_content',
		'targetEntityType' => 'node',
		'bundle' => 'country',
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
						'region' => 'content',
					),
				'field_visual' =>
					array (
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_start_date' => true,
				'langcode' => true,
				'links' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '112f6f86-9434-47b2-b57a-345a4015dea0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.country.field_content_owner',
						2 => 'field.field.node.country.field_email_owner',
						3 => 'field.field.node.country.field_end_date',
						4 => 'field.field.node.country.field_highlight',
						5 => 'field.field.node.country.field_start_date',
						6 => 'field.field.node.country.field_visual',
						7 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.country.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'country',
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
						'region' => 'content',
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_start_date' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.teaser');
$config_group->setData(
	array (
		'uuid' => '404708d9-f706-4513-b2f2-c888c92c466a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.country.field_content_owner',
						2 => 'field.field.node.country.field_email_owner',
						3 => 'field.field.node.country.field_end_date',
						4 => 'field.field.node.country.field_highlight',
						5 => 'field.field.node.country.field_start_date',
						6 => 'field.field.node.country.field_visual',
						7 => 'node.type.country',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.country.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'country',
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
						'region' => 'content',
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_highlight' => true,
				'field_start_date' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.country.field_industry');
$config_group->delete();
$config_group = $config_factory->getEditable('field.field.node.country.field_solution');
$config_group->delete();


// throw new \Drupal\Core\Utility\UpdateException();