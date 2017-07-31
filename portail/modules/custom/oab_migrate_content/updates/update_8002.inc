<?php
/**
 * format full html sur le body des profils bloggeurs
 */
//BLOG POST PROFIL
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.blogpost_profile');
$config_group->setData(
	array (
		'uuid' => 'fa3ad2ba-9d83-47ec-af67-7f856cc8175f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'suv9kqfAarRPoAvC4gRoaINcJkeedn_7J3I3yXDVOLA',
			),
		'id' => 'blogpost_profile',
		'migration_tags' => NULL,
		'migration_group' => 'blogpost',
		'label' => 'Blog posts profiles',
		'source' =>
			array (
				'plugin' => 'blogpost_profile',
			),
		'process' =>
			array (
				'type' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'profile',
					),
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'langcode' => 'langcode',
				'title' => 'title',
				'body/value' => 'field_txt_catcher',
				'body/format' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'full_html',
					),
				'field_first_name/value' => 'field_first_name',
				'field_last_name/value' => 'field_last_name',
				'field_social_account' => 'field_social_account',
				'field_visual' =>
					array (
						'plugin' => 'migration',
						'migration' => 'blogpost_profile_media',
						'source' => 'images',
					),
				'path' => 'path',
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'blogpost_profile_media',
					),
			),
	)
);
$config_group->save(TRUE);
