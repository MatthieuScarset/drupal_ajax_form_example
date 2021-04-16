<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\menu_link_content\Entity\MenuLinkContent;
use Symfony\Component\Yaml\Yaml;
use Drupal\paragraphs\Entity\ParagraphsType;


//	 \Drupal::entityDefinitionUpdateManager()->applyUpdates();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.homepage');
$config_group->setData(
	array (
		'uuid' => '3a10e7ef-1dcc-4e16-ab10-8ce640ce2d57',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'menu_ui',
						1 => 'workbench_access',
					),
			),
		'third_party_settings' =>
			array (
				'menu_ui' =>
					array (
						'available_menus' =>
							array (
								0 => 'main',
								1 => 'main-navigation-fr',
								2 => 'main-navigation-ru',
								3 => 'main-navigation-ru-en',
							),
						'parent' => 'main:',
					),
				'workbench_access' =>
					array (
						'workbench_access_status' => false,
					),
			),
		'name' => 'Homepage',
		'type' => 'homepage',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);



// image style homepage_expertise
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.homepage_expertise');
$config_group->setData(
	array (
		'uuid' => '6e5c4384-8ab6-4bea-b994-040cd6e38b13',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'homepage_expertise',
		'label' => 'Homepage Expertise (345x270)',
		'effects' =>
			array (
				'4f0289a0-5f4f-4221-83e8-be894ecced08' =>
					array (
						'uuid' => '4f0289a0-5f4f-4221-83e8-be894ecced08',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 345,
								'height' => 270,
							),
					),
			),
	)
);
$config_group->save(TRUE);

// image style homepage_news
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.homepage_news');
$config_group->setData(
	array (
		'uuid' => 'cc8926ca-5177-49bb-9ba0-220e495a12d9',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'homepage_news',
		'label' => 'Homepage Top News (380x180)',
		'effects' =>
			array (
				'efe19084-4b06-438d-af57-bfa49592c023' =>
					array (
						'uuid' => 'efe19084-4b06-438d-af57-bfa49592c023',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 380,
								'height' => 180,
							),
					),
			),
	)
);
$config_group->save(TRUE);

// image style homepage_solution_banner
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.homepage_solution_banner');
$config_group->setData(
	array (
		'uuid' => 'c3037bed-fde4-4614-aae7-223f29d98dad',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'homepage_solution_banner',
		'label' => 'Homepage Solution Banner (1400x450)',
		'effects' =>
			array (
				'58b962ac-d609-4a2c-b1b4-0a933258d3b8' =>
					array (
						'uuid' => '58b962ac-d609-4a2c-b1b4-0a933258d3b8',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 1400,
								'height' => 450,
							),
					),
			),
	)
);
$config_group->save(TRUE);

// image style homepage_top_zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.homepage_top_zone');
$config_group->setData(
	array (
		'uuid' => '388d8c48-4f30-4b93-b64e-b0747d5192bf',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'homepage_top_zone',
		'label' => 'Homepage Top Zone Banner (1400x500)',
		'effects' =>
			array (
				'fa31d56a-dcba-4c2d-8f8f-391b7ddeca54' =>
					array (
						'uuid' => 'fa31d56a-dcba-4c2d-8f8f-391b7ddeca54',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 1400,
								'height' => 500,
							),
					),
			),
	)
);
$config_group->save(TRUE);

// image style partner
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.partner');
$config_group->setData(
	array (
		'uuid' => 'a454ce81-8662-44d9-8234-f7f75ea4a3b8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'partner',
		'label' => 'Partner (180x97)',
		'effects' =>
			array (
				'dcb6b1ad-98e9-4d60-a8d2-4ef9701c583a' =>
					array (
						'uuid' => 'dcb6b1ad-98e9-4d60-a8d2-4ef9701c583a',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 180,
								'height' => 97,
							),
					),
			),
	)
);
$config_group->save(TRUE);


// ------------------------------
// Menu
// ------------------------------


if (\Drupal\system\Entity\Menu::load('our-regional-presence') == null) {
// Menu Corporate
	\Drupal::entityTypeManager()
		->getStorage('menu')
		->create([
			'id' => 'our-regional-presence',
			'label' => 'Our Regional presence',
			'description' => '',
		])
		->save();
}
$items = array(
	'394' => 'Americas',
	'393' => 'Asia Pacific',
	'399' => 'Middle East & Africa',
	'397' => 'Europe',
);

foreach ($items as $nid => $title) {
	$menu_link = MenuLinkContent::create([
		'title' => $title,
		'link' => ['uri' => 'internal://taxonomy/term/' . $nid],
		'menu_name' => 'our-regional-presence',
		'expanded' => TRUE,
	]);
	$menu_link->save();
}


// ------------------------------
// Paragraphs
// ------------------------------

/*$paragraphStorage = ParagraphsType::load('homepage_banner_experience');
if (empty($paragraphStorage)) {
	$paragraphType = ParagraphsType::create([
		'id' => 'homepage_banner_experience',
		'label' => 'Homepage Banner Expertise',
		'revision' => false
	]);
	$paragraphType->save();
}*/


// Paragraphs homepage_banner_experience
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('paragraphs.paragraphs_type.homepage_banner_experience');
$config_group->setData(
	array (
		'uuid' => '1b92d0d7-bfe7-49de-9d5d-c0f07868a6ef',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'homepage_banner_experience',
		'label' => 'Homepage Banner Expertise',
		'behavior_plugins' =>
			array (
			),
	)
);
$config_group->save(TRUE);

/* $paragraphStorage = ParagraphsType::load('homepage_banner_item');
if (empty($paragraphStorage)) {
	$paragraphType = ParagraphsType::create([
		'id' => 'homepage_banner_item',
		'label' => 'Homepage Solution Banner Item',
		'revision' => false
	]);
	$paragraphType->save();
}*/

// Paragraphs homepage_banner_item
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('paragraphs.paragraphs_type.homepage_banner_item');
$config_group->setData(
	array (
		'uuid' => 'a274da56-53a3-48df-ab4d-6a06d4e4777f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'homepage_banner_item',
		'label' => 'Homepage Solution Banner Item',
		'behavior_plugins' =>
			array (
			),
	)
);
$config_group->save(TRUE);

// Paragraphs homepage_news

/*$paragraphStorage = ParagraphsType::load('homepage_news');
if (empty($paragraphStorage)) {
	$paragraphType = ParagraphsType::create([
		'id' => 'homepage_news',
		'label' => 'Highlight on top (max. 3)',
		'revision' => false
	]);
	$paragraphType->save();
}*/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('paragraphs.paragraphs_type.homepage_news');
$config_group->setData(
	array (
		'uuid' => '3662c1a9-8eb6-4379-a0d0-51097951436e',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'homepage_news',
		'label' => 'Highlight on top (max. 3)',
		'behavior_plugins' =>
			array (
			),
	)
);
$config_group->save(TRUE);

// Paragraphs infography_partner
/*$paragraphStorage = ParagraphsType::load('infography_partner');
if (empty($paragraphStorage)) {
	$paragraphType = ParagraphsType::create([
		'id' => 'infography_partner',
		'label' => 'Infography partner (max. 5)',
		'revision' => false
	]);
	$paragraphType->save();
}*/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('paragraphs.paragraphs_type.infography_partner');
$config_group->setData(
	array (
		'uuid' => '68264280-8919-4e77-a330-33e1bd469452',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'infography_partner',
		'label' => 'Infography partner',
		'behavior_plugins' =>
			array (
			),
	)
);
$config_group->save(TRUE);




// -----------------------
//Paragraph Field
// -----------------------

// ############ homepage_banner_experience ###############

// ------- field_content ---------
createField('field_content', 'homepage_banner_experience', 'Content', 'text_long', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_content');
$config_group->setData(
	array (
		'uuid' => '3556f520-1f2e-4b12-932b-dd2a4d9f1965',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
						1 => 'text',
					),
			),
		'id' => 'paragraph.field_content',
		'field_name' => 'field_content',
		'entity_type' => 'paragraph',
		'type' => 'text_long',
		'settings' =>
			array (
			),
		'module' => 'text',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_experience.field_content');
$config_group->setData(
	array (
		'uuid' => '615ced40-f550-4fa9-988e-bcfd3970bffe',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_content',
						1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
				'module' =>
					array (
						0 => 'text',
					),
			),
		'id' => 'paragraph.homepage_banner_experience.field_content',
		'field_name' => 'field_content',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_experience',
		'label' => 'Content',
		'description' => '',
		'required' => false,
		'translatable' => false,
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
// -------

// ------- field_content_image ---------
createField('field_content_image', 'homepage_banner_experience', 'Highlight', 'image', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_content_image');
$config_group->setData(
	array (
		'uuid' => '62743fa8-557d-4048-aa7c-a685447f90a2',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'file',
						1 => 'image',
						2 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_content_image',
		'field_name' => 'field_content_image',
		'entity_type' => 'paragraph',
		'type' => 'image',
		'settings' =>
			array (
				'uri_scheme' => 'public',
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'target_type' => 'file',
				'display_field' => false,
				'display_default' => false,
			),
		'module' => 'image',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_experience.field_content_image');
$config_group->setData(
	array (
		'uuid' => '5cb5d665-2c35-4783-b15e-d3e5e28cf97f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_content_image',
						1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
				'module' =>
					array (
						0 => 'image',
					),
			),
		'id' => 'paragraph.homepage_banner_experience.field_content_image',
		'field_name' => 'field_content_image',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_experience',
		'label' => 'Content Image',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'file_directory' => '[date:custom:Y]-[date:custom:m]',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => '',
				'max_resolution' => '',
				'min_resolution' => '',
				'alt_field' => true,
				'alt_field_required' => false,
				'title_field' => true,
				'title_field_required' => false,
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'handler' => 'default:file',
				'handler_settings' =>
					array (
					),
			),
		'field_type' => 'image',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_content_title ---------
createField('field_content_title', 'homepage_banner_experience', 'Content title', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_content_title');
$config_group->setData(
	array (
		'uuid' => '8f7a48e4-d407-4caa-83f2-fa7909f02cfb',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_content_title',
		'field_name' => 'field_content_title',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 255,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_experience.field_content_title');
$config_group->setData(
	array (
		'uuid' => '4a7e11f9-3213-4a5c-843e-2a1c948c8cd8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_content_title',
						1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
			),
		'id' => 'paragraph.homepage_banner_experience.field_content_title',
		'field_name' => 'field_content_title',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_experience',
		'label' => 'Content title',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_tab_picto_class ---------
createField('field_tab_picto_class', 'homepage_banner_experience', 'Tab Picto Class', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_tab_picto_class');
$config_group->setData(
	array (
		'uuid' => '86ef67d7-802b-4f47-8b46-dea7bd03b695',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_tab_picto_class',
		'field_name' => 'field_tab_picto_class',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 60,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_experience.field_tab_picto_class');
$config_group->setData(
	array (
		'uuid' => '91461960-6448-4fc2-9c26-0bddf62d22cd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_tab_picto_class',
						1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
			),
		'id' => 'paragraph.homepage_banner_experience.field_tab_picto_class',
		'field_name' => 'field_tab_picto_class',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_experience',
		'label' => 'Tab Picto Class',
		'description' => 'Need help to find a picto class ? Visit the <a href="http://boosted.orange.com/components/" target="_blank">Boosted Components Website</a>',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_tab_title ---------
createField('field_tab_title', 'homepage_banner_experience', 'Tab title', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_tab_title');
$config_group->setData(
	array (
		'uuid' => '5a36efb1-7f7e-4b2b-9f49-eea29a95462c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_tab_title',
		'field_name' => 'field_tab_title',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 60,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_experience.field_tab_title');
$config_group->setData(
	array (
		'uuid' => '2d735d94-bc21-4062-bfa0-a5ebd804de70',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_tab_title',
						1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
			),
		'id' => 'paragraph.homepage_banner_experience.field_tab_title',
		'field_name' => 'field_tab_title',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_experience',
		'label' => 'Tab title',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ############ homepage_banner_item ###############

// ------- field_button_text ---------
createField('field_button_text', 'homepage_banner_item', 'Button text', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_button_text');
$config_group->setData(
	array (
		'uuid' => '4d14ee1f-0562-456d-a341-83d36b4863f4',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_button_text',
		'field_name' => 'field_button_text',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 20,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_item.field_button_text');
$config_group->setData(
	array (
		'uuid' => 'a77f01f8-86ec-4d5e-9fd4-0517de7300bf',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_button_text',
						1 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
			),
		'id' => 'paragraph.homepage_banner_item.field_button_text',
		'field_name' => 'field_button_text',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_item',
		'label' => 'Button text',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_card_link ---------
createField('field_card_link', 'homepage_banner_item', 'Card link', 'link', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_card_link');
$config_group->setData(
	array (
		'uuid' => '87499db6-aa3c-4103-8a58-d660727eafa7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'link',
						1 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_card_link',
		'field_name' => 'field_card_link',
		'entity_type' => 'paragraph',
		'type' => 'link',
		'settings' =>
			array (
			),
		'module' => 'link',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_item.field_card_link');
$config_group->setData(
	array (
		'uuid' => '7a737fa4-f5d0-4902-a763-2bcbc33bf8bd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_card_link',
						1 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
				'module' =>
					array (
						0 => 'link',
					),
			),
		'id' => 'paragraph.homepage_banner_item.field_card_link',
		'field_name' => 'field_card_link',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_item',
		'label' => 'Card link',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'link_type' => 17,
				'title' => 1,
			),
		'field_type' => 'link',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_card_text ---------
createField('field_card_text', 'homepage_banner_item', 'Card text', 'text_long', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_card_text');
$config_group->setData(
	array (
		'uuid' => 'b9229cdc-0a5c-471b-8c9d-b47235f94a99',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
						1 => 'text',
					),
			),
		'id' => 'paragraph.field_card_text',
		'field_name' => 'field_card_text',
		'entity_type' => 'paragraph',
		'type' => 'text_long',
		'settings' =>
			array (
			),
		'module' => 'text',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_item.field_card_text');
$config_group->setData(
	array (
		'uuid' => 'b254ea43-3048-4ac1-a8bb-08c7817e8a68',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_card_text',
						1 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
				'module' =>
					array (
						0 => 'text',
					),
			),
		'id' => 'paragraph.homepage_banner_item.field_card_text',
		'field_name' => 'field_card_text',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_item',
		'label' => 'Card text',
		'description' => '',
		'required' => false,
		'translatable' => false,
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
// -------

// ------- field_card_title ---------
createField('field_card_title', 'homepage_banner_item', 'Card title', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_card_title');
$config_group->setData(
	array (
		'uuid' => '55936388-e4d1-41fc-9eca-496a25bcd8ec',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_card_title',
		'field_name' => 'field_card_title',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 100,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_banner_item.field_card_title');
$config_group->setData(
	array (
		'uuid' => '9093da7b-e4c8-47c8-8457-dd5645dfe998',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_card_title',
						1 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
			),
		'id' => 'paragraph.homepage_banner_item.field_card_title',
		'field_name' => 'field_card_title',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_banner_item',
		'label' => 'Card title',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ############ homepage_news ###############

// ------- field_chapo ---------
createField('field_chapo', 'homepage_news', 'Chapo', 'text_long', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_chapo');
$config_group->setData(
	array (
		'uuid' => '1ff7dfd2-62a7-4e0a-b843-eb2b813fb50a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
						1 => 'text',
					),
			),
		'id' => 'paragraph.field_chapo',
		'field_name' => 'field_chapo',
		'entity_type' => 'paragraph',
		'type' => 'text_long',
		'settings' =>
			array (
			),
		'module' => 'text',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_news.field_chapo');
$config_group->setData(
	array (
		'uuid' => 'c7dfe06c-7de5-48e7-88d3-9748942f52b2',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_chapo',
						1 => 'paragraphs.paragraphs_type.homepage_news',
					),
				'module' =>
					array (
						0 => 'text',
					),
			),
		'id' => 'paragraph.homepage_news.field_chapo',
		'field_name' => 'field_chapo',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_news',
		'label' => 'Chapo',
		'description' => '',
		'required' => false,
		'translatable' => false,
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
// -------

// ------- field_image ---------
createField('field_image', 'homepage_news', 'Image', 'image', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_image');
$config_group->setData(
	array (
		'uuid' => '577dae87-4a46-439c-bf04-891e0863b3ae',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'file',
						1 => 'image',
						2 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_image',
		'field_name' => 'field_image',
		'entity_type' => 'paragraph',
		'type' => 'image',
		'settings' =>
			array (
				'uri_scheme' => 'public',
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'target_type' => 'file',
				'display_field' => false,
				'display_default' => false,
			),
		'module' => 'image',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_news.field_image');
$config_group->setData(
	array (
		'uuid' => '6505b7e5-e783-40e3-a126-4b04c8d0ac47',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_image',
						1 => 'paragraphs.paragraphs_type.homepage_news',
					),
				'module' =>
					array (
						0 => 'image',
					),
			),
		'id' => 'paragraph.homepage_news.field_image',
		'field_name' => 'field_image',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_news',
		'label' => 'Image',
		'description' => 'image with size : 380x180px',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'file_directory' => '[date:custom:Y]-[date:custom:m]',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => '',
				'max_resolution' => '',
				'min_resolution' => '',
				'alt_field' => true,
				'alt_field_required' => false,
				'title_field' => true,
				'title_field_required' => false,
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'handler' => 'default:file',
				'handler_settings' =>
					array (
					),
			),
		'field_type' => 'image',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_link_news ---------
createField('field_link_news', 'homepage_news', 'Highlight link', 'link', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_link_news');
$config_group->setData(
	array (
		'uuid' => 'ac5d0d53-7b61-497e-9306-d15a4bc0496c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'link',
						1 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_link_news',
		'field_name' => 'field_link_news',
		'entity_type' => 'paragraph',
		'type' => 'link',
		'settings' =>
			array (
			),
		'module' => 'link',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_news.field_link_news');
$config_group->setData(
	array (
		'uuid' => '37afb6fc-c50a-4504-9085-5d70b3d5bece',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_link_news',
						1 => 'paragraphs.paragraphs_type.homepage_news',
					),
				'module' =>
					array (
						0 => 'link',
					),
			),
		'id' => 'paragraph.homepage_news.field_link_news',
		'field_name' => 'field_link_news',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_news',
		'label' => 'Highlight link',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'link_type' => 17,
				'title' => 1,
			),
		'field_type' => 'link',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_link_news ---------
createField('field_title', 'homepage_news', 'Title', 'string', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_title');
$config_group->setData(
	array (
		'uuid' => 'c9f38d3f-9dea-477c-8423-e4a0edd36daf',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_title',
		'field_name' => 'field_title',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 150,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.homepage_news.field_title');
$config_group->setData(
	array (
		'uuid' => '8878fc5c-c643-4e59-9f1e-0862a5527cfe',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_title',
						1 => 'paragraphs.paragraphs_type.homepage_news',
					),
			),
		'id' => 'paragraph.homepage_news.field_title',
		'field_name' => 'field_title',
		'entity_type' => 'paragraph',
		'bundle' => 'homepage_news',
		'label' => 'Title',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------



// ############ infography_partner ###############

// ------- field_background_image ---------
createField('field_background_image', 'infography_partner', 'Background image', 'image', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_background_image');
$config_group->setData(
	array (
		'uuid' => '2b22e75e-fe8b-4450-8ab9-c2a3f74db278',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'file',
						1 => 'image',
						2 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_background_image',
		'field_name' => 'field_background_image',
		'entity_type' => 'paragraph',
		'type' => 'image',
		'settings' =>
			array (
				'uri_scheme' => 'public',
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'target_type' => 'file',
				'display_field' => false,
				'display_default' => false,
			),
		'module' => 'image',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.infography_partner.field_background_image');
$config_group->setData(
	array (
		'uuid' => 'f1ce4c49-96f8-45eb-8493-41ae581d7733',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_background_image',
						1 => 'paragraphs.paragraphs_type.infography_partner',
					),
				'module' =>
					array (
						0 => 'image',
					),
			),
		'id' => 'paragraph.infography_partner.field_background_image',
		'field_name' => 'field_background_image',
		'entity_type' => 'paragraph',
		'bundle' => 'infography_partner',
		'label' => 'Background image',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'file_directory' => '[date:custom:Y]-[date:custom:m]',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => '',
				'max_resolution' => '',
				'min_resolution' => '',
				'alt_field' => true,
				'alt_field_required' => false,
				'title_field' => true,
				'title_field_required' => false,
				'default_image' =>
					array (
						'uuid' => '',
						'alt' => '',
						'title' => '',
						'width' => NULL,
						'height' => NULL,
					),
				'handler' => 'default:file',
				'handler_settings' =>
					array (
					),
			),
		'field_type' => 'image',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_key_figures ---------
createField('field_key_figures', 'infography_partner', 'Key figures', 'float', false, 'paragraph');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_key_figures');
$config_group->setData(
	array (
		'uuid' => '0a1afab4-5df7-4533-a6b2-33d107c6c34b',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'id' => 'paragraph.field_key_figures',
		'field_name' => 'field_key_figures',
		'entity_type' => 'paragraph',
		'type' => 'float',
		'settings' =>
			array (
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.infography_partner.field_key_figures');
$config_group->setData(
	array (
		'uuid' => '40aaadde-fe48-4478-a6f8-c42b85e7a16a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.paragraph.field_key_figures',
						1 => 'paragraphs.paragraphs_type.infography_partner',
					),
			),
		'id' => 'paragraph.infography_partner.field_key_figures',
		'field_name' => 'field_key_figures',
		'entity_type' => 'paragraph',
		'bundle' => 'infography_partner',
		'label' => 'key figures',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'min' => NULL,
				'max' => NULL,
				'prefix' => '',
				'suffix' => '',
			),
		'field_type' => 'float',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_text_infography ---------
createField('field_text_infography', 'infography_partner', 'Text infography', 'string', false, 'paragraph');
loadConfigField('paragraphs', 'field.field.paragraph.infography_partner.field_text_infography');
loadConfigField('paragraphs', 'field.storage.paragraph.field_text_infography');
// -------

//-------------------------------------------------
// FIELDS
//-------------------------------------------------

// ########### Top zone #############

// ------- field_header_title ---------
createField('field_header_title', 'homepage', 'Title', 'string', TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_header_title');
$config_group->setData(
	array (
		'uuid' => 'c082be72-30a8-4582-8db0-f882b2f27a0e',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
					),
			),
		'id' => 'node.field_header_title',
		'field_name' => 'field_header_title',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 255,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.homepage.field_header_title');
$config_group->setData(
	array (
		'uuid' => '676c99cf-8daf-4d50-b5f4-6b5eb07cb52f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_header_title',
						1 => 'node.type.homepage',
					),
			),
		'id' => 'node.homepage.field_header_title',
		'field_name' => 'field_header_title',
		'entity_type' => 'node',
		'bundle' => 'homepage',
		'label' => 'Title',
		'description' => '',
		'required' => true,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);
// -------

// ------- field_news_top_zone ---------
createField('field_news_top_zone', 'homepage', 'Top Highlights', 'entity_reference_revisions', false, 'node');

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_news_top_zone');
$config_group->setData(
	array (
		'uuid' => '8ae52f2c-1fb7-4991-a123-94f2d4321256',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'entity_reference_revisions',
						1 => 'node',
						2 => 'paragraphs',
					),
			),
		'id' => 'node.field_news_top_zone',
		'field_name' => 'field_news_top_zone',
		'entity_type' => 'node',
		'type' => 'entity_reference_revisions',
		'settings' =>
			array (
				'target_type' => 'paragraph',
			),
		'module' => 'entity_reference_revisions',
		'locked' => false,
		'cardinality' => 3,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.homepage.field_news_top_zone');
$config_group->setData(
	array (
		'uuid' => '07cf7f00-5bd7-419f-9587-bbe451bfb52d',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_news_top_zone',
						1 => 'node.type.homepage',
						2 => 'paragraphs.paragraphs_type.homepage_news',
					),
				'module' =>
					array (
						0 => 'entity_reference_revisions',
					),
			),
		'id' => 'node.homepage.field_news_top_zone',
		'field_name' => 'field_news_top_zone',
		'entity_type' => 'node',
		'bundle' => 'homepage',
		'label' => 'Top Highlights',
		'description' => '',
		'required' => true,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:paragraph',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'homepage_news' => 'homepage_news',
							),
						'target_bundles_drag_drop' =>
							array (
								'infography_partner' =>
									array (
										'weight' => 5,
										'enabled' => false,
									),
								'homepage_banner_experience' =>
									array (
										'weight' => 6,
										'enabled' => false,
									),
								'homepage_banner_item' =>
									array (
										'weight' => 7,
										'enabled' => false,
									),
								'homepage_news' =>
									array (
										'enabled' => true,
										'weight' => 8,
									),
							),
					),
			),
		'field_type' => 'entity_reference_revisions',
	)
);
$config_group->save(TRUE);
// -------


// ------- field_banner_expertise ---------
createField('field_banner_expertise', 'homepage', 'Banner Expertise', 'entity_reference_revisions', false);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_banner_expertise');
$config_group->setData(
	array (
		'uuid' => '5603ff8c-4492-4598-854d-31b701bd0005',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'entity_reference_revisions',
						1 => 'node',
						2 => 'paragraphs',
					),
			),
		'id' => 'node.field_banner_expertise',
		'field_name' => 'field_banner_expertise',
		'entity_type' => 'node',
		'type' => 'entity_reference_revisions',
		'settings' =>
			array (
				'target_type' => 'paragraph',
			),
		'module' => 'entity_reference_revisions',
		'locked' => false,
		'cardinality' => 5,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.homepage.field_banner_expertise');
$config_group->setData(
	array (
		'uuid' => '1262ddef-1060-4d3d-b1cf-fd1d98d6cbba',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_banner_expertise',
						1 => 'node.type.homepage',
						2 => 'paragraphs.paragraphs_type.homepage_banner_experience',
					),
				'module' =>
					array (
						0 => 'entity_reference_revisions',
					),
			),
		'id' => 'node.homepage.field_banner_expertise',
		'field_name' => 'field_banner_expertise',
		'entity_type' => 'node',
		'bundle' => 'homepage',
		'label' => 'Banner Expertise',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:paragraph',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'homepage_banner_experience' => 'homepage_banner_experience',
							),
						'target_bundles_drag_drop' =>
							array (
								'infography_partner' =>
									array (
										'weight' => 5,
										'enabled' => false,
									),
								'homepage_banner_experience' =>
									array (
										'enabled' => true,
										'weight' => 6,
									),
								'homepage_banner_item' =>
									array (
										'weight' => 7,
										'enabled' => false,
									),
								'homepage_news' =>
									array (
										'weight' => 8,
										'enabled' => false,
									),
							),
					),
			),
		'field_type' => 'entity_reference_revisions',
	)
);
$config_group->save(TRUE);
// -------

createField('field_banner_left_zone_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_banner_left_zone_title');
loadConfigField('field/storage', 'field.storage.node.field_banner_left_zone_title');

createField('field_banner_right_zone_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_banner_right_zone_title');
loadConfigField('field/storage', 'field.storage.node.field_banner_right_zone_title');


// Corporate banner
createField('field_corporate_button_link', 'homepage', 'Button link', 'link');
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_button_link');
loadConfigField('field/storage', 'field.storage.node.field_corporate_button_link');

createField('field_corporate_highlight', 'homepage', 'Highlight', 'text_long');
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_highlight');
loadConfigField('field/storage', 'field.storage.node.field_corporate_highlight');

createField('field_corporate_image', 'homepage', 'Image', 'image', false);
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_image');
loadConfigField('field/storage', 'field.storage.node.field_corporate_image');


createFieldReference('field_corporate_menu', 'homepage', 'Menu', 'menu', 'entity_reference', false);
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_menu');
loadConfigField('field/storage', 'field.storage.node.field_corporate_menu');

createField('field_corporate_menu_title', 'homepage', 'Menu title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_menu_title');
loadConfigField('field/storage', 'field.storage.node.field_corporate_menu_title');

createField('field_corporate_show_menu', 'homepage', 'Show Menu', 'boolean');
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_show_menu');
loadConfigField('field/storage', 'field.storage.node.field_corporate_show_menu');

createField('field_corporate_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_title');
loadConfigField('field/storage', 'field.storage.node.field_corporate_title');

// Expertise
createField('field_expertise_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_expertise_title');
loadConfigField('field/storage', 'field.storage.node.field_expertise_title');


createField('field_infography', 'homepage', 'Infography', 'entity_reference_revisions', false);
loadConfigField('field/field', 'field.field.node.homepage.field_infography');
loadConfigField('field/storage', 'field.storage.node.field_infography');

createField('field_meta_description', 'homepage', 'Meta description', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_meta_description');
loadConfigField('field/storage', 'field.storage.node.field_meta_description');

createField('field_meta_title', 'homepage', 'Meta title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_meta_title');
loadConfigField('field/storage', 'field.storage.node.field_meta_title');

createField('field_partner_button_link', 'homepage', 'Button link', 'link', false);
loadConfigField('field/field', 'field.field.node.homepage.field_partner_button_link');
loadConfigField('field/storage', 'field.storage.node.field_partner_button_link');

createField('field_partner_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_partner_title');
loadConfigField('field/storage', 'field.storage.node.field_partner_title');

createField('field_solution_banner_highlight', 'homepage', 'Highlight', 'text_long');
loadConfigField('field/field', 'field.field.node.homepage.field_solution_banner_highlight');
loadConfigField('field/storage', 'field.storage.node.field_solution_banner_highlight');

createField('field_solution_banner_image', 'homepage', 'Image', 'image', false);
loadConfigField('field/field', 'field.field.node.homepage.field_solution_banner_image');
loadConfigField('field/storage', 'field.storage.node.field_solution_banner_image');


createField('field_solution_banner_left_zone', 'homepage', 'Left Zone', 'entity_reference_revisions', false, 'node');
loadConfigField('field/field', 'field.field.node.homepage.field_solution_banner_left_zone');
loadConfigField('field/storage', 'field.storage.node.field_solution_banner_left_zone');


createField('field_solution_banner_right_zone', 'homepage', 'Right Zone', 'entity_reference_revisions', false);
loadConfigField('field/field', 'field.field.node.homepage.field_solution_banner_right_zone');
loadConfigField('field/storage', 'field.storage.node.field_solution_banner_right_zone');


createField('field_solution_banner_title', 'homepage', 'Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_solution_banner_title');
loadConfigField('field/storage', 'field.storage.node.field_solution_banner_title');

createField('field_subhead_title_top_zone', 'homepage', 'Subhead Title', 'string');
loadConfigField('field/field', 'field.field.node.homepage.field_subhead_title_top_zone');
loadConfigField('field/storage', 'field.storage.node.field_subhead_title_top_zone');

createField('field_top_zone_image', 'homepage', 'Image', 'image', false, 'node');
loadConfigField('field/field', 'field.field.node.homepage.field_top_zone_image');
loadConfigField('field/storage', 'field.storage.node.field_top_zone_image');



// ---------------------------
// View Display
// ---------------------------

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_banner_experience.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.paragraph.homepage_banner_experience.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_banner_item.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.paragraph.homepage_banner_item.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_news.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.paragraph.homepage_news.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.infography_partner.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.paragraph.infography_partner.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.node.homepage.full.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.node.homepage.full')->setData($data)->save(TRUE);



// ---------------------------
// Form Display
// ---------------------------

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_banner_experience.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.paragraph.homepage_banner_experience.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_banner_item.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.paragraph.homepage_banner_item.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_news.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.paragraph.homepage_news.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.infography_partner.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.paragraph.infography_partner.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.node.homepage.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.node.homepage.default')->setData($data)->save(TRUE);


// ---------------------------
// Views partner
// ---------------------------
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/views/views.view.homepage_partner.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('views.view.homepage_partner')->setData($data)->save(TRUE);

drupal_set_message("Update done");