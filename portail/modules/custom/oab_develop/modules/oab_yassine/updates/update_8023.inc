<?php
/**
 * Ajout d'un field pour les images top zone en mobile
 */
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


// ============ Field for homepage ======================
$contentTypes = [
	'industry',
	'solution',
	'country',
	'region',
];

$fieldName = "field_top_zone_bg_mobile";
$label = "Top zone background for mobile";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => $fieldName,
		'entity_type' => 'node',
		'type' => 'entity_reference',
	))->save();
}
foreach ($contentTypes as $contentType) {
	$field = FieldConfig::loadByName('node', $contentType, $fieldName);
	if (empty($field)) {
		$config_array = array(
			'field_name' =>  $fieldName,
			'entity_type' => 'node',
			'bundle' => $contentType,
			'label' => $label,
			'required' => false,
		);
		FieldConfig::create($config_array)->save();
	}
}

##Mise en place du field dans les différents contenus
foreach ($contentTypes as $contentType) {
	oabt_YmlImport("field.field.node.$contentType.field_top_zone_bg_mobile.yml");
	oabt_YmlImport("core.entity_view_display.node.$contentType.default.yml");
	oabt_YmlImport("core.entity_form_display.node.$contentType.default.yml");
}



// ============ Field for homepage ======================
$contentTypes = [
	'homepage',
];

$fieldName = "field_top_zone_image_mobile";
$label = "Image Mobile";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => $fieldName,
		'entity_type' => 'node',
		'type' => 'image',
	))->save();
}
foreach ($contentTypes as $contentType) {
	$field = FieldConfig::loadByName('node', $contentType, $fieldName);
	if (empty($field)) {
		$config_array = array(
			'field_name' =>  $fieldName,
			'entity_type' => 'node',
			'bundle' => $contentType,
			'label' => $label,
			'required' => false,
		);
		FieldConfig::create($config_array)->save();
	}
}


$fieldName = "field_solution_image_mobile";
$label = "Image Mobile";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => $fieldName,
		'entity_type' => 'node',
		'type' => 'image',
	))->save();
}
foreach ($contentTypes as $contentType) {
	$field = FieldConfig::loadByName('node', $contentType, $fieldName);
	if (empty($field)) {
		$config_array = array(
			'field_name' =>  $fieldName,
			'entity_type' => 'node',
			'bundle' => $contentType,
			'label' => $label,
			'required' => false,
		);
		FieldConfig::create($config_array)->save();
	}
}

##Mise en place du field dans les différents contenus
foreach ($contentTypes as $contentType) {
	oabt_YmlImport("field.field.node.$contentType.field_solution_image_mobile.yml");
	oabt_YmlImport("field.field.node.$contentType.field_top_zone_image_mobile.yml");
	oabt_YmlImport("core.entity_view_display.node.$contentType.full.yml");
	oabt_YmlImport("core.entity_form_display.node.$contentType.default.yml");
}
