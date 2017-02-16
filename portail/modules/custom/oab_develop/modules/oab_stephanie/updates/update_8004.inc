<?php
/**
 * Configuration de la visibilité du champs Ornemental visual sur les différents types de contenus
 */

/*******************************
 * Mode affichage DEFAULT *
 ******************************/
//BLOG-POST DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//COUNTRY DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//CUSTOMER STORY DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//DOCUMENT DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//INDUSTRY DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//MAGAZINE DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//PARTNER DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//PRESS KIT DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//PRESS RELEASE DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//REGION DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);

//SOLUTION DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.default');
$config_group->clear('content.field_visual');
$config_group->set('hidden.field_visual', 'true');
$config_group->save(TRUE);



/*******************************
 * Mode affichage TEASER *
 ******************************/

//BLOG-POST TEASER
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
				'field_area' => true,
				'field_blog' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
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

//COUNTRY TEASER
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
				'field_end_date' => true,
				'field_highlight' => true,
				'field_start_date' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//CUSTOMER STORY TEASER
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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//DOCUMENT TEASER
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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
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
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'field_topic' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//INDUSTRY TEASER
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
				'field_end_date' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_start_date' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//MAGAZINE TEASER
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
		'id' => 'node.magazine.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'magazine',
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
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//PARTNER TEASER
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
				'field_partner' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//PRESS KIT TEASER
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
				'field_area' => true,
				'field_content' => true,
				'field_content_owner' => true,
				'field_customer_story' => true,
				'field_display_title' => true,
				'field_email_owner' => true,
				'field_end_date' => true,
				'field_file' => true,
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//PRESS RELEASE TEASER
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
				'field_highlight' => true,
				'field_industry' => true,
				'field_meta_description' => true,
				'field_meta_title' => true,
				'field_metatags' => true,
				'field_partner' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'field_subhome' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);

//REGION TEASER
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.teaser');
$config_group->setData(
	array (
		'uuid' => 'f79b2ac8-e5b6-4439-92c5-c85e808e6e90',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
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
		'id' => 'node.region.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'region',
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

//SOLUTION TEASER
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
				'field_end_date' => true,
				'field_highlight' => true,
				'field_solution' => true,
				'field_start_date' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);
