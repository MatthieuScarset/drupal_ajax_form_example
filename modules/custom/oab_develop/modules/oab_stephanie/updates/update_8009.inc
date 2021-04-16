<?php
/**
 * Nouveau mode d'affichage : right_linked_content + config pour les type de contenu
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.node.right_linked_content');
$config_group->setData(
	array (
		'uuid' => 'dd14f40d-1171-439d-84df-8f25cb7fbda3',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
					),
			),
		'id' => 'node.right_linked_content',
		'label' => 'Right Linked Content',
		'targetEntityType' => 'node',
		'cache' => true,
	)
);
$config_group->save(TRUE);




//Config de ce mode pour les types de contenus :


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
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
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
						11 => 'field.field.node.partner.field_partner',
						12 => 'field.field.node.partner.field_start_date',
						13 => 'field.field.node.partner.field_subhome',
						14 => 'field.field.node.partner.field_visual',
						15 => 'node.type.partner',
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
				'field_partner' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
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
						1 => 'field.field.node.industry.field_content_owner',
						2 => 'field.field.node.industry.field_email_owner',
						3 => 'field.field.node.industry.field_end_date',
						4 => 'field.field.node.industry.field_highlight',
						5 => 'field.field.node.industry.field_industry',
						6 => 'field.field.node.industry.field_start_date',
						7 => 'field.field.node.industry.field_visual',
						8 => 'node.type.industry',
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
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_industry' => true,
				'field_start_date' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_document_type' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_topic' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
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
						1 => 'field.field.node.solution.field_content_owner',
						2 => 'field.field.node.solution.field_email_owner',
						3 => 'field.field.node.solution.field_end_date',
						4 => 'field.field.node.solution.field_highlight',
						5 => 'field.field.node.solution.field_solution',
						6 => 'field.field.node.solution.field_start_date',
						7 => 'field.field.node.solution.field_visual',
						8 => 'node.type.solution',
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
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

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
						1 => 'field.field.node.simple_page.field_area',
						2 => 'field.field.node.simple_page.field_content',
						3 => 'field.field.node.simple_page.field_content_owner',
						4 => 'field.field.node.simple_page.field_customer_story',
						5 => 'field.field.node.simple_page.field_display_title',
						6 => 'field.field.node.simple_page.field_email_owner',
						7 => 'field.field.node.simple_page.field_end_date',
						8 => 'field.field.node.simple_page.field_grouping_title',
						9 => 'field.field.node.simple_page.field_highlight',
						10 => 'field.field.node.simple_page.field_industry',
						11 => 'field.field.node.simple_page.field_meta_description',
						12 => 'field.field.node.simple_page.field_meta_title',
						13 => 'field.field.node.simple_page.field_metatags',
						14 => 'field.field.node.simple_page.field_partner',
						15 => 'field.field.node.simple_page.field_solution',
						16 => 'field.field.node.simple_page.field_start_date',
						17 => 'field.field.node.simple_page.field_subhome',
						18 => 'node.type.simple_page',
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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_grouping_title' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.right_linked_content');
$config_group->setData(
	array (
		'uuid' => '842f1b88-d831-41c4-888f-545acc2965e6',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.right_linked_content',
						1 => 'field.field.node.region.field_content_owner',
						2 => 'field.field.node.region.field_email_owner',
						3 => 'field.field.node.region.field_end_date',
						4 => 'field.field.node.region.field_highlight',
						5 => 'field.field.node.region.field_start_date',
						6 => 'field.field.node.region.field_visual',
						7 => 'node.type.region',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.region.right_linked_content',
		'targetEntityType' => 'node',
		'bundle' => 'region',
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
				'field_content_owner' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_start_date' => true,
				'field_visual' => true,
				'langcode' => true,
				'workbench_moderation_control' => true,
			),
	)
);
$config_group->save(TRUE);

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
				'field_area' => true,
				'field_city' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_country' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_visual' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
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
				'field_area' => true,
				'field_blog' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
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