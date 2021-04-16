<?php

/**
 * Modification des fichiers de config pour la migratoin des images : prise en compte des balises ALT et TITLE
 */

//DOCUMENT
$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.document_media_image');
$config_comment->setData(
	array (
		'uuid' => '591639e9-1470-4283-a740-2f898582b37a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'WskzfkpiewwuPmIqNfivTpmpZOiiUJMbm0SC2WnOxJc',
			),
		'id' => 'document_media_image',
		'migration_tags' => NULL,
		'migration_group' => 'document',
		'label' => 'Document image medias',
		'source' =>
			array (
				'plugin' => 'document_media_image',
			),
		'process' =>
			array (
				'bundle' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'image',
					),
				'langcode' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'und',
					),
				'name' => 'filename',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'status' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'created' => 'timestamp',
				'changed' => 'timestamp',
				'field_image/target_id' =>
					array (
						'plugin' => 'migration',
						'migration' => 'document_image',
						'source' => 'image_info',
					),
				'field_image/alt' => 'field_image_alt',
				'field_image/title' => 'field_image_title',
			),
		'destination' =>
			array (
				'plugin' => 'entity:media',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'document_image',
					),
			),
	)
	);
$config_comment->save(TRUE);

//MAG ARTICLE
$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.magazinearticle_media');
$config_comment->setData(
	array (
		'uuid' => '20037605-6ff2-452e-95a7-b81271d333ad',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'OlaKehXSg7j5AAWtDlnXgWa2zTYhJiv7660pcZImGLg',
			),
		'id' => 'magazinearticle_media',
		'migration_tags' => NULL,
		'migration_group' => 'magazinearticle',
		'label' => 'Magazine articles medias',
		'source' =>
			array (
				'plugin' => 'magazinearticle_media',
			),
		'process' =>
			array (
				'bundle' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'image',
					),
				'langcode' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'und',
					),
				'name' => 'filename',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'status' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'created' => 'timestamp',
				'changed' => 'timestamp',
				'field_image/target_id' =>
					array (
						'plugin' => 'migration',
						'migration' => 'magazinearticle_image',
						'source' => 'image_info',
					),
				'field_image/alt' => 'field_image_alt',
				'field_image/title' => 'field_image_title',
			),
		'destination' =>
			array (
				'plugin' => 'entity:media',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'magazinearticle_image',
					),
			),
	)
);
$config_comment->save(TRUE);

//MAG INTERVIEW
$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.magazineinterview_media');
$config_comment->setData(
	array (
		'uuid' => 'd77319e6-3dff-477c-acfb-2f604c9ce67e',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'aL1GBb3UIPe4bfJ7OHcPXt2H-3tAkB--gF9BINoVxVI',
			),
		'id' => 'magazineinterview_media',
		'migration_tags' => NULL,
		'migration_group' => 'magazineinterview',
		'label' => 'Magazine interviews medias',
		'source' =>
			array (
				'plugin' => 'magazineinterview_media',
			),
		'process' =>
			array (
				'bundle' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'image',
					),
				'langcode' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'und',
					),
				'name' => 'filename',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'status' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'created' => 'timestamp',
				'changed' => 'timestamp',
				'field_image/target_id' =>
					array (
						'plugin' => 'migration',
						'migration' => 'magazineinterview_image',
						'source' => 'image_info',
					),
				'field_image/alt' => 'field_image_alt',
				'field_image/title' => 'field_image_title',
			),
		'destination' =>
			array (
				'plugin' => 'entity:media',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'magazineinterview_image',
					),
			),
	)
);
$config_comment->save(TRUE);


//BLOG POST
$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.blogpost_media');
$config_comment->setData(
	array (
		'uuid' => 'c49ff4aa-cc4e-44ac-b7ff-89271dd066e0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => '19COxlKygx1wRRV5UDH7ohwvVCOIbO8FQ5tdqJ4xhX0',
			),
		'id' => 'blogpost_media',
		'migration_tags' => NULL,
		'migration_group' => 'blogpost',
		'label' => 'Blog posts medias',
		'source' =>
			array (
				'plugin' => 'blogpost_media',
			),
		'process' =>
			array (
				'bundle' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'image',
					),
				'langcode' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'und',
					),
				'name' => 'filename',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'status' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'created' => 'timestamp',
				'changed' => 'timestamp',
				'field_image/target_id' =>
					array (
						'plugin' => 'migration',
						'migration' => 'blogpost_image',
						'source' => 'image_info',
					),
				'field_image/alt' => 'field_image_alt',
				'field_image/title' => 'field_image_title',
			),
		'destination' =>
			array (
				'plugin' => 'entity:media',
			),
		'migration_dependencies' =>
			array (
			),
	)
);
$config_comment->save(TRUE);
