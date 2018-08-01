<?php

//Champs Market segment DVI : STORAGE
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_market_segment_dvi');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
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
		'field_name' => 'field_market_segment_dvi',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'translatable' => true,
		'cardinality' => -1,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	))->save();
	drupal_set_message("******** création du config storage pour le nouveau champ : field_market_segment_dvi  - OK", "status");
}


//Champ sur PRODUCT
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'product', 'field_market_segment_dvi');
if (empty($field)) {
	$config_array = array(
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment_dvi',
						1 => 'node.type.product',
						2 => 'taxonomy.vocabulary.market_segments_dvi',
					),
			),
		'id' => 'node.product.field_market_segment_dvi',
		'field_name' => 'field_market_segment_dvi',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Market segment DVI',
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
								'market_segments_dvi' => 'market_segments_dvi',
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
	drupal_set_message("******** création de l'instance du champ field_market_segment_dvi pour product - OK", "status");
}
//Champ sur DISTRIBUTOR
$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'distributor', 'field_market_segment_dvi');
if (empty($field)) {
	$config_array = array(
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_market_segment_dvi',
						1 => 'node.type.distributor',
						2 => 'taxonomy.vocabulary.market_segments_dvi',
					),
			),
		'id' => 'node.distributor.field_market_segment_dvi',
		'field_name' => 'field_market_segment_dvi',
		'entity_type' => 'node',
		'bundle' => 'distributor',
		'label' => 'Market segment DVI',
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
								'market_segments_dvi' => 'market_segments_dvi',
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
	drupal_set_message("******** création de l'instance du champ field_market_segment_dvi pour distributor - OK", "status");
}

//VIEW/FORM DISPLAY POUR PRODUCT
oabt_YmlImport('core.entity_view_display.node.product.default.yml');
oabt_YmlImport('core.entity_form_display.node.product.default.yml');
drupal_set_message("******** config view/form display de Product - OK", "status");
//VIEW/FORM DISPLAY POUR DISTRIBUTOR
oabt_YmlImport('core.entity_view_display.node.distributor.default.yml');
oabt_YmlImport('core.entity_form_display.node.distributor.default.yml');
drupal_set_message("******** config view/form display de Distributor - OK", "status");