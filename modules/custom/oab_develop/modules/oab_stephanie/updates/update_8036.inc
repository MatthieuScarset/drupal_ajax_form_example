<?php

//Nouvelle taxonomie Pays pour office
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies['office_countries']) ) {
	$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
		'vid' => 'office_countries',
		'name' => 'Office Countries'
	));
	$vocabulary->save();
}

//Champ COUNTRY CODE
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('taxonomy_term', 'field_country_code');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_country_code',
		'entity_type' => 'taxonomy_term',
		'type' => 'string',
		'settings' => array(
			'max_length' => 5,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => FALSE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('taxonomy_term', 'office_countries', 'field_country_code');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_country_code',
		'entity_type' => 'taxonomy_term',
		'bundle' => 'office_countries',
		'label' => 'Country code',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_form_display.taxonomy_term.office_countries.default');
$config_comment->setData(array (
	'langcode' => 'en',
	'status' => true,
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.field.taxonomy_term.office_countries.field_country_code',
					1 => 'taxonomy.vocabulary.office_countries',
				),
			'module' =>
				array (
					0 => 'path',
					1 => 'text',
				),
		),
	'id' => 'taxonomy_term.office_countries.default',
	'targetEntityType' => 'taxonomy_term',
	'bundle' => 'office_countries',
	'mode' => 'default',
	'content' =>
		array (
			'description' =>
				array (
					'type' => 'text_textfield',
					'weight' => 0,
					'region' => 'content',
					'settings' =>
						array (
							'size' => 60,
							'placeholder' => '',
						),
					'third_party_settings' =>
						array (
						),
				),
			'field_country_code' =>
				array (
					'weight' => 31,
					'settings' =>
						array (
							'size' => 60,
							'placeholder' => '',
						),
					'third_party_settings' =>
						array (
						),
					'type' => 'string_textfield',
					'region' => 'content',
				),
			'langcode' =>
				array (
					'type' => 'language_select',
					'weight' => 2,
					'region' => 'content',
					'settings' =>
						array (
						),
					'third_party_settings' =>
						array (
						),
				),
			'name' =>
				array (
					'type' => 'string_textfield',
					'weight' => -5,
					'region' => 'content',
					'settings' =>
						array (
							'size' => 60,
							'placeholder' => '',
						),
					'third_party_settings' =>
						array (
						),
				),
			'path' =>
				array (
					'type' => 'path',
					'weight' => 30,
					'region' => 'content',
					'settings' =>
						array (
						),
					'third_party_settings' =>
						array (
						),
				),
		),
	'hidden' =>
		array (
		),
));
$config_comment->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_view_display.taxonomy_term.office_countries.default');
$config_comment->setData(array (
	'langcode' => 'en',
	'status' => true,
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'field.field.taxonomy_term.office_countries.field_country_code',
					1 => 'taxonomy.vocabulary.office_countries',
				),
			'module' =>
				array (
					0 => 'text',
				),
		),
	'id' => 'taxonomy_term.office_countries.default',
	'targetEntityType' => 'taxonomy_term',
	'bundle' => 'office_countries',
	'mode' => 'default',
	'content' =>
		array (
			'description' =>
				array (
					'label' => 'hidden',
					'type' => 'text_default',
					'weight' => 0,
					'region' => 'content',
					'settings' =>
						array (
						),
					'third_party_settings' =>
						array (
						),
				),
			'field_country_code' =>
				array (
					'weight' => 1,
					'label' => 'above',
					'settings' =>
						array (
							'link_to_entity' => false,
						),
					'third_party_settings' =>
						array (
						),
					'type' => 'string',
					'region' => 'content',
				),
		),
	'hidden' =>
		array (
			'langcode' => true,
		),
));
$config_comment->save(TRUE);