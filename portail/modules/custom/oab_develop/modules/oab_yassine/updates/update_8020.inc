<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\menu_link_content\Entity\MenuLinkContent;
use Symfony\Component\Yaml\Yaml;

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


// ------------------------------
// Menu
// ------------------------------

// Menu Corporate
\Drupal::entityTypeManager()
	->getStorage('menu')
	->create([
		'id' => 'our-regional-presence',
		'label' => 'Our Regional presence',
		'description' => '',
	])
	->save();

$items = array(
	'239' => 'North America',
	'235' => 'Asia Pacific',
	'521' => 'Middle East & Africa',
	'236' => 'Europe',
	'237' => 'Latine America',
);

foreach($items as $nid => $title) {
	$menu_link = MenuLinkContent::create([
		'title' => $title,
		'link' => ['uri' => 'internal://taxonomy/term/	' . $nid],
		'menu_name' => 'our-regional-presence',
		'expanded' => TRUE,
	]);
	$menu_link->save();
}

// ------------------------------
// Paragraphs
// ------------------------------

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

// Paragraphs homepage_news
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

//-------------------------------------------------
// FIELDS
//-------------------------------------------------

// Top zone
createField('field_header_title', 'homepage', 'Title', 'string', TRUE);
createField('field_news_top_zone', 'homepage', 'Top Highlights', 'entity_reference_revisions', false, 'node',
	['settings' =>
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
			)
	]);

createField('field_banner_expertise', 'homepage', 'Banner Expertise', 'entity_reference_revisions', false, 'node',
	['settings' =>
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
			)
	]);
createField('field_banner_left_zone_title', 'homepage', 'Title', 'string');
createField('field_banner_right_zone_title', 'homepage', 'Title', 'string');


// Corporate banner
createField('field_corporate_button_link', 'homepage', 'Button link', 'link');
createField('field_corporate_highlight', 'homepage', 'Highlight', 'text_long');
createField('field_corporate_image', 'homepage', 'Image', 'image', false, 'node',
	['settings' =>
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
		)]
);
createField('field_corporate_menu', 'homepage', 'Menu', 'entity_reference', false, 'node',[
	'settings' =>
		array (
			'handler' => 'default:menu',
			'handler_settings' =>
				array (
					'target_bundles' => NULL,
					'auto_create' => false,
				),
		),
]);
createField('field_corporate_menu_title', 'homepage', 'Menu title', 'string');
createField('field_corporate_show_menu', 'homepage', 'Show Menu', 'boolean');
createField('field_corporate_title', 'homepage', 'Title', 'string');

// Expertise
createField('field_expertise_title', 'homepage', 'Title', 'string');


createField('field_infography', 'homepage', 'Infography', 'entity_reference_revisions', false, 'node',
	['settings' =>
		array (
			'handler' => 'default:paragraph',
			'handler_settings' =>
				array (
					'target_bundles' =>
						array (
							'infography_partner' => 'infography_partner',
						),
					'target_bundles_drag_drop' =>
						array (
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
									'weight' => 8,
									'enabled' => false,
								),
							'infography_partner' =>
								array (
									'enabled' => true,
									'weight' => 9,
								),
							'related_content' =>
								array (
									'weight' => 10,
									'enabled' => false,
								),
						),
				),
		)
	]);
createField('field_meta_description', 'homepage', 'Meta description', 'string');
createField('field_meta_title', 'homepage', 'Meta title', 'string');

createField('field_partner_button_link', 'homepage', 'Button link', 'link', false, 'node',
	['settings' =>
		array (
			'link_type' => 17,
			'title' => 1,
		)
	]);
createField('field_partner_title', 'homepage', 'Title', 'string');
createField('field_solution_banner_highlight', 'homepage', 'Highlight', 'text_long');
createField('.field_solution_banner_image', 'homepage', 'Image', 'image', false, 'node',
	['settings' =>
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
		)
	]);
createField('field_solution_banner_left_zone', 'homepage', 'Left Zone', 'entity_reference_revisions', false, 'node',
	[	'settings' =>
		array (
			'handler' => 'default:paragraph',
			'handler_settings' =>
				array (
					'target_bundles' =>
						array (
							'homepage_banner_item' => 'homepage_banner_item',
						),
					'target_bundles_drag_drop' =>
						array (
							'homepage_banner_item' =>
								array (
									'enabled' => true,
									'weight' => 3,
								),
							'homepage_news' =>
								array (
									'weight' => 4,
									'enabled' => false,
								),
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
							'related_content' =>
								array (
									'weight' => 10,
									'enabled' => false,
								),
						),
				),
		),
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_solution_banner_left_zone',
						1 => 'node.type.homepage',
						2 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
				'module' =>
					array (
						0 => 'entity_reference_revisions',
					),
			)
	]);
createField('field_solution_banner_right_zone', 'homepage', 'Right Zone', 'entity_reference_revisions', false, 'node',
	['settings' =>
		array (
			'handler' => 'default:paragraph',
			'handler_settings' =>
				array (
					'target_bundles' =>
						array (
							'homepage_banner_item' => 'homepage_banner_item',
						),
					'target_bundles_drag_drop' =>
						array (
							'homepage_banner_item' =>
								array (
									'enabled' => true,
									'weight' => 3,
								),
							'homepage_news' =>
								array (
									'weight' => 4,
									'enabled' => false,
								),
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
						),
				),
		),
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_solution_banner_right_zone',
						1 => 'node.type.homepage',
						2 => 'paragraphs.paragraphs_type.homepage_banner_item',
					),
				'module' =>
					array (
						0 => 'entity_reference_revisions',
					),
			)
	]);
createField('field_solution_banner_title', 'homepage', 'Title', 'string');
createField('field_subhead_title_top_zone', 'homepage', 'Subhead Title', 'string');
createField('field_top_zone_image', 'homepage', 'Image', 'image', false, 'node', [
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
		)
]);


// -----------------------
//Paragraph Field
// -----------------------
createField('field_content', 'homepage_banner_experience', 'Content', 'text_long', false, 'paragraph', [
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
		)
]);
createField('field_content_image', 'homepage_banner_experience', 'Highlight', 'image', false, 'paragraph', [
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
		)
]);
createField('field_content_title', 'homepage_banner_experience', 'Content title', 'string', false, 'paragraph', [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_content_title',
					1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
				),
		)
]);
createField('field_tab_picto_class', 'homepage_banner_experience', 'Tab Picto Class', 'string', false, 'paragraph', [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_tab_picto_class',
					1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
				),
		),
	'description' => 'Need help to find a picto class ? Visit the <a href="http://boosted.orange.com/components/" target="_blank">Boosted Components Website</a>',
]);
createField('field_tab_title', 'homepage_banner_experience', 'Tab title', 'string', false, 'paragraph', [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_tab_title',
					1 => 'paragraphs.paragraphs_type.homepage_banner_experience',
				),
		)
]);



createField('field_button_text', 'homepage_banner_item', 'Button text', 'string', false, 'paragraph', [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_button_text',
					1 => 'paragraphs.paragraphs_type.homepage_banner_item',
				),
		)
]);
createField('field_card_link', 'homepage_banner_item', 'Card link', 'link', false, 'paragraph', [
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
	'settings' =>
		array (
			'link_type' => 17,
			'title' => 1,
		)
]);
createField('field_card_text', 'homepage_banner_item', 'Card text', 'text_long', false, 'paragraph', [
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
		)
]);
createField('field_card_title', 'homepage_banner_item', 'Card title', 'string', false, 'paragraph', [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_card_title',
					1 => 'paragraphs.paragraphs_type.homepage_banner_item',
				),
		)
]);


createField('field_chapo', 'homepage_news', 'Chapo', 'text_long', false, 'paragraph',  [
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
		)
]);
createField('field_image', 'homepage_news', 'Image', 'image', false, 'paragraph',  [
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
		)
]);
createField('field_link_news', 'homepage_news', 'Highlight link', 'link', false, 'paragraph',  [
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
	'settings' =>
		array (
			'link_type' => 17,
			'title' => 1,
		)
]);
createField('field_title', 'homepage_news', 'Title', 'string', false, 'paragraph',  [
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.storage.paragraph.field_title',
					1 => 'paragraphs.paragraphs_type.homepage_news',
				),
		)
]);


// ---------------------------
// View Display
// ---------------------------

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_banner_experience.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_banner_experience.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_banner_item.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_banner_item.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.homepage_news.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_news.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.paragraph.infography_partner.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.infography_partner.default')->setData($data)->save(TRUE);

// import view homepage
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.node.homepage.full.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('node.homepage.full')->setData($data)->save(TRUE);

// ---------------------------
// Form Display
// ---------------------------

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_banner_experience.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_banner_experience.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_banner_item.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_banner_item.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.homepage_news.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.homepage_news.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.paragraph.infography_partner.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('paragraph.infography_partner.default')->setData($data)->save(TRUE);

$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.node.homepage.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('node.homepage.default')->setData($data)->save(TRUE);


// ---------------------------
// Views partner
// ---------------------------
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/views/views.view.homepage_partner.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('views.view.homepage_partner')->setData($data)->save(TRUE);

