<?php

/**
 * Configuration de metatags
 */

//BLOG-POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__blog_post');
$config_group->setData(
	array (
		'uuid' => '438d8e3c-e6ee-4342-86ff-ac6e8b8374f6',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__blog_post',
		'label' => 'Content: Article de blog',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//CUSTOMER STORY
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__customer_story');
$config_group->setData(
	array (
		'uuid' => '9dbbae8a-fafe-4a59-be0c-acfd692f3dff',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__customer_story',
		'label' => 'Content: Cas client',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//DOCUMENT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__document');
$config_group->setData(
	array (
		'uuid' => '5fd418a4-e16a-490d-887c-d365c11d11eb',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__document',
		'label' => 'Content: Document',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//MAGAZINE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__magazine');
$config_group->setData(
	array (
		'uuid' => '052432be-b250-45fe-8d92-a68c2e655643',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__magazine',
		'label' => 'Content: Magazine',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//PARTNER
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__partner');
$config_group->setData(
	array (
		'uuid' => '109fd241-6d0f-4f53-89b7-2558557afb84',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__partner',
		'label' => 'Content: Partenaire',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//PRESS KIT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__press_kit');
$config_group->setData(
	array (
		'uuid' => 'bfbd8c99-73c3-4e13-aeda-077371e00f4c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__press_kit',
		'label' => 'Content: Dossier de presse',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//PRESS RELEASE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__press_release');
$config_group->setData(
	array (
		'uuid' => '191d36a1-b0cd-4bf5-b862-963e62685303',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__press_release',
		'label' => 'Content: Communiqué de presse',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
//PAGE SIMPLE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__simple_page');
$config_group->setData(
	array (
		'uuid' => 'f8709c1b-a56d-4753-af59-93873ea11fa7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__simple_page',
		'label' => 'Content: Page simple',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);