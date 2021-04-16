<?php
/**
 * Ajout du champ Accroche (txt catcher) à migrer
 */
//BLOG POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config_group->setData(
	array (
		'uuid' => '82b33293-4686-42eb-ae43-b0530b292d1a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => '3AwHQriYQ9-G7zCrFJHpu4fxDaV-2Zhs4K7kCCIaekI',
			),
		'id' => 'blogpost_node',
		'migration_tags' => NULL,
		'migration_group' => 'blogpost',
		'label' => 'Blog posts nodes',
		'source' =>
			array (
				'plugin' => 'blogpost_node',
			),
		'process' =>
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
				'field_solution' => 'solutions',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_thematic' => 'thematics',
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
				'field_highlight' => 'highlight_field',
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'blogpost_image',
						1 => 'blogpost_media',
						2 => 'blogpost_profile',
					),
			),
	)
);
$config_group->save(TRUE);

//DOCUMENT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.document_node');
$config_group->setData(
	array (
		'uuid' => '318307fe-2371-4521-a15f-75d09152f1c4',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'JTf2QfvcBxNpEWeLmZ-VQyPVsyKRBsk8CEDrdxNs9jI',
			),
		'id' => 'document_node',
		'migration_tags' => NULL,
		'migration_group' => 'document',
		'label' => 'Document',
		'source' =>
			array (
				'plugin' => 'document_node',
			),
		'process' =>
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
				'field_document_type' =>
					array (
						'plugin' => 'migration',
						'migration' => 'document_term',
						'source' => 'document_types',
					),
				'field_solution' => 'solutions',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_thematic' => 'thematics',
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
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'document_media_file',
						1 => 'document_media_image',
						2 => 'document_term',
					),
			),
	)
);
$config_group->save(TRUE);

//MAGAZINE ARTICLE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazinearticle_node');
$config_group->setData(
	array (
		'uuid' => '7db88dc7-3e87-448a-aa38-d62b261a3e73',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'WWGCFxmfDDThwclpG5ZNdNMDsAPHxoLX9Dw47FfPPbk',
			),
		'id' => 'magazinearticle_node',
		'migration_tags' => NULL,
		'migration_group' => 'magazinearticle',
		'label' => 'Magazine articles nodes',
		'source' =>
			array (
				'plugin' => 'magazinearticle_node',
			),
		'process' =>
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
				'field_solution' => 'solutions',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_thematic' => 'thematics',
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
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'magazinearticle_term',
						1 => 'magazinearticle_media',
					),
			),
	)
);
$config_group->save(TRUE);

//MAGAZINE INTERVIEW
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazineinterview_node');
$config_group->setData(
	array (
		'uuid' => '95be9508-f316-4d3b-a4b5-96201427356b',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'ZX7IxgrBYzfL1-UqeL1mSAq75bpcdL4C1zmqCLXl7ws',
			),
		'id' => 'magazineinterview_node',
		'migration_tags' => NULL,
		'migration_group' => 'magazineinterview',
		'label' => 'Magazine interviews nodes',
		'source' =>
			array (
				'plugin' => 'magazineinterview_node',
			),
		'process' =>
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
				'field_solution' => 'solutions',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_thematic' => 'thematics',
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
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'magazineinterview_term',
						1 => 'magazineinterview_media',
					),
			),
	)
);
$config_group->save(TRUE);

//PRESS KIT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.press_kit_node');
$config_group->setData(
	array (
		'uuid' => 'd4c0690a-2151-4594-b760-045a50318745',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'o6OZxyWD5QVhKzKRgTi1mkXcHse6ZBJSL-3zOGQHrG8',
			),
		'id' => 'press_kit_node',
		'migration_tags' => NULL,
		'migration_group' => 'press_kit',
		'label' => 'Press kit nodes',
		'source' =>
			array (
				'plugin' => 'press_kit_node',
			),
		'process' =>
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
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'press_kit_media',
					),
			),
	)
);
$config_group->save(TRUE);

//PRESS RELEASE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config_group->setData(
	array (
		'uuid' => '8dd5f1b1-98c2-4206-95d6-2b3038e81d03',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => '2qfo4WPsPErRlvsS1zyKeAIzCDvZ4O8QdFlT-wB8ONk',
			),
		'id' => 'press_release_node',
		'migration_tags' => NULL,
		'migration_group' => 'press_release',
		'label' => 'Communiqué de presse',
		'source' =>
			array (
				'plugin' => 'press_release_node',
			),
		'process' =>
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
			),
		'destination' =>
			array (
				'plugin' => 'entity:node',
			),
		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'press_release_media',
					),
			),
	)
);
$config_group->save(TRUE);
