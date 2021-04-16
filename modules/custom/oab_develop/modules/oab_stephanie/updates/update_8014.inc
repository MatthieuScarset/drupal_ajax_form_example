<?php

use Drupal\field\Entity\FieldStorageConfig;

// Ajout des nouveaux vocabulaires de taxonomie : regions, market segment, partner type, subfamilies, content types
$vids_to_add = array('regions' => 'Regions',
'market_segments' => 'Market Segments',
'partner_types' => 'Partner Types',
'sub_families' => 'Sub-families',
'jobs_profiles' => 'Jobs profiles'
);
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
foreach ($vids_to_add as $vid => $name) {
	if (!isset($vocabularies[$vid]) ) {
	$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
		'vid' => $vid,
		'name' => $name
	));
	$vocabulary->save();
	}
}

//ajout des champs


//field.storage.node.field_sub_family
$field_storage = FieldStorageConfig::loadByName('node', 'field_sub_family');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_sub_family',
    'entity_type' => 'node',
    'type' => 'entity_reference',
  ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_sub_family');
$config_group->setData(
	array (
		'uuid' => '17d80de4-088b-46c1-ab7a-4737f7522de3',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_sub_family',
		'field_name' => 'field_sub_family',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

//field.storage.node.field_region
$field_storage = FieldStorageConfig::loadByName('node', 'field_region');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_region',
    'entity_type' => 'node',
    'type' => 'entity_reference',
  ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_region');
$config_group->setData(
	array (
		'uuid' => '5ff668d7-eab6-49a4-8df8-f0de7cf5d5ea',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

//field.storage.node.field_partner_type
$field_storage = FieldStorageConfig::loadByName('node', 'field_partner_type');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_partner_type',
    'entity_type' => 'node',
    'type' => 'entity_reference',
  ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_partner_type');
$config_group->setData(
	array (
		'uuid' => '18b079ce-0bec-42a8-8cbc-c49a2e41a2ee',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_partner_type',
		'field_name' => 'field_partner_type',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

//field.storage.node.field_market_segment
$field_storage = FieldStorageConfig::loadByName('node', 'field_market_segment');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_market_segment',
    'entity_type' => 'node',
    'type' => 'entity_reference',
  ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_market_segment');
$config_group->setData(
	array (
		'uuid' => '26e363af-9751-4db1-b8f7-1d937a448e6e',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

//field.storage.node.field_job_profile
$field_storage = FieldStorageConfig::loadByName('node', 'field_job_profile');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_job_profile',
    'entity_type' => 'node',
    'type' => 'entity_reference',
  ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '370d4fd3-fedf-44e2-89e5-0ec5ddd933c5',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)

);
$config_group->save(TRUE);

//field.field.node.simple_page.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_region');
$config_group->setData(
	array (
		'uuid' => 'e780f7f0-64ce-46eb-aa0a-47ca86935859',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.simple_page',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.simple_page.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'simple_page',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.simple_page.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_market_segment');
$config_group->setData(
	array (
		'uuid' => 'fa7823e6-2e74-4092-a554-d14b8bd287d8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.simple_page',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.simple_page.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'simple_page',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.simple_page.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '0ad38961-9d7d-4084-8650-30e29b462c00',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.simple_page',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.simple_page.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'simple_page',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.region.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_region');
$config_group->setData(
	array (
		'uuid' => '73150b1d-bfff-4afb-9da9-bf43269cac5d',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.region',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.region.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'region',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_subhome
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_subhome');
$config_group->setData(
	array (
		'uuid' => '4615bcd5-1d38-4cd7-b696-cf90c3960903',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_subhome',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.subhomes',
					),
			),
		'id' => 'node.product.field_subhome',
		'field_name' => 'field_subhome',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Subhome',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'subhomes' => 'subhomes',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_sub_family
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_sub_family');
$config_group->setData(
	array (
		'uuid' => 'ca4fba31-6cb8-48bb-a4c6-db952ba6fe0c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_sub_family',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.sub_families',
					),
			),
		'id' => 'node.product.field_sub_family',
		'field_name' => 'field_sub_family',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Sub-family',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'sub_families' => 'sub_families',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_solution
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_solution');
$config_group->setData(
	array (
		'uuid' => '537bfbc6-3d6a-4bb7-911d-890881c84f3a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_solution',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.solutions',
					),
			),
		'id' => 'node.product.field_solution',
		'field_name' => 'field_solution',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Solution',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'solutions' => 'solutions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_region');
$config_group->setData(
	array (
		'uuid' => 'e67d5844-15ba-451f-9ea7-d822359518e0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.product.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_market_segment');
$config_group->setData(
	array (
		'uuid' => '4e78069e-8c17-45c4-8a95-50647f44dbe7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.product.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_job_profile');
$config_group->setData(
	array (
		'uuid' => 'c6bf1054-176e-4625-8491-ff1d665ad4e8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.product.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.product.field_industry
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_industry');
$config_group->setData(
	array (
		'uuid' => '36632fec-90c3-498a-843a-6c29da5007d4',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_industry',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.industries',
					),
			),
		'id' => 'node.product.field_industry',
		'field_name' => 'field_industry',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Industrie',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'industries' => 'industries',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_release.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_region');
$config_group->setData(
	array (
		'uuid' => '0cdadd44-5f5f-405e-8dfc-766a4313c6d7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.press_release',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.press_release.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'press_release',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_release.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_market_segment');
$config_group->setData(
	array (
		'uuid' => '1fd9c594-f99e-4d03-91e1-14a2b657f2dd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.press_release',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.press_release.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'press_release',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_release.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '076abf21-842c-4531-873d-b99f754ef9fe',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.press_release',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.press_release.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'press_release',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_kit.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_region');
$config_group->setData(
	array (
		'uuid' => '56b04a18-9a37-4992-a1d9-0dd0f043aa09',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.press_kit',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.press_kit.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'press_kit',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_kit.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_market_segment');
$config_group->setData(
	array (
		'uuid' => '9b5679da-0c52-4d18-9aa3-8c3a60907cb8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.press_kit',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.press_kit.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'press_kit',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.press_kit.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_job_profile');
$config_group->setData(
	array (
		'uuid' => 'b63da216-3a78-44bd-8052-6f1bfeb6b009',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.press_kit',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.press_kit.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'press_kit',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.partner.field_solution
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_solution');
$config_group->setData(
	array (
		'uuid' => '6dd5e228-e2fe-469b-832a-535f5f78a2c8',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_solution',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.solutions',
					),
			),
		'id' => 'node.partner.field_solution',
		'field_name' => 'field_solution',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Solution',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'solutions' => 'solutions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.partner.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_region');
$config_group->setData(
	array (
		'uuid' => 'ee6d574d-2861-4d47-8822-40800f5c126f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.partner.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.partner.field_partner_type
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_partner_type');
$config_group->setData(
	array (
		'uuid' => '1faae6cb-8682-4e7e-b712-7f32d823b9eb',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_partner_type',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.partner_types',
					),
			),
		'id' => 'node.partner.field_partner_type',
		'field_name' => 'field_partner_type',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Partner type',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'partner_types' => 'partner_types',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.partner.field_industry
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_industry');
$config_group->setData(
	array (
		'uuid' => 'e5593778-8aa0-4ad2-9bac-7970a04762bd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_industry',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.industries',
					),
			),
		'id' => 'node.partner.field_industry',
		'field_name' => 'field_industry',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Industrie',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'industries' => 'industries',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.magazine.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_region');
$config_group->setData(
	array (
		'uuid' => '6e096ded-3e52-479b-9e00-94de157cce66',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.magazine',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.magazine.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'magazine',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.magazine.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_market_segment');
$config_group->setData(
	array (
		'uuid' => 'b8ce976b-a844-4388-a676-04336b26d8b1',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.magazine',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.magazine.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'magazine',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.magazine.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_job_profile');
$config_group->setData(
	array (
		'uuid' => 'addec776-ff5b-4755-b64a-8cf7392f953c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.magazine',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.magazine.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'magazine',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.document.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_region');
$config_group->setData(
	array (
		'uuid' => '70ffffbb-6cbd-43a3-9577-7139209e84c0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.document.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.document.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_market_segment');
$config_group->setData(
	array (
		'uuid' => 'c32a71b0-59dc-4c8b-ba64-509ab7d0bf17',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.document.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.document.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '2a0d1aae-5486-42a2-9006-6736002a3168',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.document.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.customer_story.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_region');
$config_group->setData(
	array (
		'uuid' => '3b59394d-a7ca-45b7-820c-7109c8b91f03',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.customer_story',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.customer_story.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'customer_story',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.customer_story.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_market_segment');
$config_group->setData(
	array (
		'uuid' => 'e56dd159-7a23-4750-8e1a-9a1065949713',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.customer_story',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.customer_story.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'customer_story',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.customer_story.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '6af4c92e-c064-48c9-bd76-801a83699df2',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.customer_story',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.customer_story.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'customer_story',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.blog_post.field_region
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_region');
$config_group->setData(
	array (
		'uuid' => 'aca35d57-7934-4b97-b634-e1cac9549632',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.blog_post',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'id' => 'node.blog_post.field_region',
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Region',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'regions' => 'regions',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.blog_post.field_market_segment
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_market_segment');
$config_group->setData(
	array (
		'uuid' => 'f755d68f-f2c2-4635-acb8-c4e7b6420fa7',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.blog_post',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'id' => 'node.blog_post.field_market_segment',
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Market segment',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'market_segments' => 'market_segments',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

//field.field.node.blog_post.field_job_profile
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_job_profile');
$config_group->setData(
	array (
		'uuid' => 'fb7fb25d-fa69-42f9-a7ba-6ee7919adfb5',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.blog_post',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.blog_post.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);



