<?php

//Champs Department
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_departments');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'field_name' => 'field_departments',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'translatable' => FALSE,
		'cardinality' => -1,
		'indexes' =>
			array (
			),
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'partner', 'field_departments');
if (empty($field)) {
	$config_array = array(
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_departments',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.departments',
					),
			),
		'field_name' => 'field_departments',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Department',
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
								'departments' => 'departments',
							),
						'sort' =>
							array (
								'field' => 'name',
								'direction' => 'asc',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ Market Segment
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'partner', 'field_market_segment');
if (empty($field)) {
	$config_array = array(
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment',
						1 => 'node.type.partner',
						2 => 'taxonomy.vocabulary.market_segments',
					),
			),
		'field_name' => 'field_market_segment',
		'entity_type' => 'node',
		'bundle' => 'partner',
		'label' => 'Market segment',
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
								'field' => 'name',
								'direction' => 'asc',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


oabt_YmlImport('core.entity_form_display.node.partner.default.yml');
oabt_YmlImport('core.entity_view_display.node.partner.default.yml');


