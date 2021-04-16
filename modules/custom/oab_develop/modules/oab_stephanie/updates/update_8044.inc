<?php

//Champ field_linked_content
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('taxonomy_term', 'field_linked_content');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_linked_content',
		'entity_type' => 'taxonomy_term',
		'type' => 'entity_reference',
		'module' => 'core',
		'settings' => array(
			'target_type' => 'node',
		),
		'translatable' => TRUE,
		'locked' => FALSE,
		'cardinality' => 1,
		'persist_with_no_fields' => FALSE,
		'custom_storage' => FALSE,
	))->save();
}


$field = \Drupal\field\Entity\FieldConfig::loadByName('taxonomy_term', 'regions', 'field_linked_content');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_linked_content',
		'entity_type' => 'taxonomy_term',
		'bundle' => 'regions',
		'label' => 'Linked Content',
		'field_type' => 'entity_reference',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array(
			'handler' => 'default:node',
			'handler_settings' => array(
				'target_bundles' => array(
					'region' => 'region',
				),
				'sort' => array(
					'field' => '_none',
				),
				'auto_create' => false,
				'auto_create_bundle' => '',

			),
		)
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

oabt_YmlImport('core.entity_form_display.taxonomy_term.regions.default.yml');
oabt_YmlImport('core.entity_view_display.taxonomy_term.regions.default.yml');

//mise a jour de la vue Offices map
oabt_YmlImport('views.view.offices_map_view.yml');
