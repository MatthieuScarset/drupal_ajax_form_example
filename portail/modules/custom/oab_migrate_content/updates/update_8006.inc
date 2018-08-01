<?php

//BLOG POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config_group->set(
		'process' ,
			array (
				'type' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'blog_post',
					),
				'title' => 'title',
				'created' => 'created',
				'changed' => 'changed',
				'langcode' => 'language',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'field_content/value' => 'content_field',
				'field_content/format' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'full_html',
					),
				'field_blog_thematic' => 'blog_thematics',
				'field_blog_format' => 'blog_formats',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_insight' => 'thematics',
				'field_visual' =>
					array (
						'plugin' => 'migration',
						'migration' => 'blogpost_media',
						'source' => 'images',
					),
				'path' => 'path',
				'field_profile' => 'profile_blogger_id',
				'moderation_state' => 'moderation_state',
				'status' => 'status',
				'field_meta_title' => 'meta_title',
				'field_meta_description' => 'meta_description',
			));
$config_group->save(TRUE);

//MAG Article
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazinearticle_node');
$config_group->set(
	'process' ,
	array (
		'type' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'magazine',
			),
		'title' => 'title',
		'created' => 'created',
		'changed' => 'changed',
		'langcode' => 'language',
		'uid' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 1,
			),
		'field_content/value' => 'content_field',
		'field_content/format' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'full_html',
			),
		'field_magazine_thematic' => 'magazine_thematics',
		'field_magazine_type' => 'magazine_types',
		'field_industry' => 'industries',
		'field_region' => 'regions',
		'field_subhome' => 'subhomes',
		'field_insight' => 'thematics',
		'field_visual' =>
			array (
				'plugin' => 'migration',
				'migration' => 'magazinearticle_media',
				'source' => 'images',
			),
		'path' => 'path',
		'moderation_state' => 'moderation_state',
		'status' => 'status',
		'field_meta_title' => 'meta_title',
		'field_meta_description' => 'meta_description',
		'field_highlight' => 'highlight_field',
	));
$config_group->save(TRUE);

//MAG Interview
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazineinterview_node');
$config_group->set(
	'process' ,
	array (
		'type' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'magazine',
			),
		'title' => 'title',
		'created' => 'created',
		'changed' => 'changed',
		'langcode' => 'language',
		'uid' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 1,
			),
		'field_content' =>
			array (
				'plugin' => 'iterator',
				'source' => 'content_field',
				'process' =>
					array (
						'value' => 'value',
						'format' =>
							array (
								'plugin' => 'default_value',
								'default_value' => 'full_html',
							),
					),
			),
		'field_magazine_thematic' => 'magazine_thematics',
		'field_magazine_type' => 'magazine_types',
		'field_industry' => 'industries',
		'field_region' => 'regions',
		'field_subhome' => 'subhomes',
		'field_insight' => 'thematics',
		'field_visual' =>
			array (
				'plugin' => 'migration',
				'migration' => 'magazineinterview_media',
				'source' => 'images',
			),
		'path' => 'path',
		'moderation_state' => 'moderation_state',
		'status' => 'status',
		'field_meta_title' => 'meta_title',
		'field_meta_description' => 'meta_description',
		'field_highlight' => 'highlight_field',
	));
$config_group->save(TRUE);

//press kit
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.press_kit_node');
$config_group->set(
	'process' ,
	array (
		'type' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'press_kit',
			),
		'title' => 'title',
		'created' => 'created',
		'changed' => 'changed',
		'langcode' => 'language',
		'uid' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 1,
			),
		'field_content/value' => 'content_field',
		'field_content/format' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'full_html',
			),
		'field_solution' => 'solutions',
		'field_industry' => 'industries',
		'field_region' => 'regions',
		'field_subhome' => 'subhomes',
		'field_thematic' => 'thematics',
		'field_press_type' => 'press_types',
		'field_file' =>
			array (
				'plugin' => 'migration',
				'migration' => 'press_kit_media',
				'source' => 'files',
			),
		'path' => 'path',
		'moderation_state' => 'moderation_state',
		'status' => 'status',
		'field_meta_title' => 'meta_title',
		'field_meta_description' => 'meta_description',
		'field_highlight' => 'highlight_field',
	));
$config_group->save(TRUE);




//press release
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config_group->set(
	'process' ,
	array (
		'type' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'press_release',
			),
		'title' => 'title',
		'created' => 'created',
		'changed' => 'changed',
		'langcode' => 'language',
		'uid' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 1,
			),
		'field_content/value' => 'content_field',
		'field_content/format' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'full_html',
			),
		'field_solution' => 'solutions',
		'field_industry' => 'industries',
		'field_region' => 'regions',
		'field_subhome' => 'subhomes',
		'field_thematic' => 'thematics',
		'field_press_type' => 'press_types',
		'field_file' =>
			array (
				'plugin' => 'migration',
				'migration' => 'press_release_media',
				'source' => 'files',
			),
		'path' => 'path',
		'field_country' => 'country',
		'field_city' => 'city',
		'moderation_state' => 'moderation_state',
		'status' => 'status',
		'field_meta_title' => 'meta_title',
		'field_meta_description' => 'meta_description',
		'field_highlight' => 'highlight_field',
	));
$config_group->save(TRUE);



//document
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.document_term');
if (!empty($config_group)) {
	$config_group->delete();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.document_node');
$config_group->set(
	'process' ,
	array (
		'type' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'document',
			),
		'title' => 'title',
		'created' => 'created',
		'changed' => 'changed',
		'langcode' => 'language',
		'uid' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 1,
			),
		'field_content/value' => 'content_field',
		'field_content/format' =>
			array (
				'plugin' => 'default_value',
				'default_value' => 'full_html',
			),
		'field_document_type' => 'document_types',
		'field_document_thematic' => 'document_thematics',
		'field_industry' => 'industries',
		'field_region' => 'regions',
		'field_subhome' => 'subhomes',
		'field_insight' => 'thematics',
		'field_file' =>
			array (
				'plugin' => 'migration',
				'migration' => 'document_media_file',
				'source' => 'files',
			),
		'field_visual' =>
			array (
				'plugin' => 'migration',
				'migration' => 'document_media_image',
				'source' => 'images',
			),
		'path' => 'path',
		'moderation_state' => 'moderation_state',
		'status' => 'status',
		'field_meta_title' => 'meta_title',
		'field_meta_description' => 'meta_description',
		'field_highlight' => 'highlight_field',
	));
$config_group->set(
	'migration_dependencies' , array (
	'required' =>
		array (
			0 => 'document_media_file',
			1 => 'document_media_image',
		),
));
$config_group->save(TRUE);