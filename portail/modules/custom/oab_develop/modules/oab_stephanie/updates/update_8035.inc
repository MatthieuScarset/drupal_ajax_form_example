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

//Champ STREET
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_street');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_street',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' => array(
			'max_length' => 255,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => TRUE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_street');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_street',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Street',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ ADDITIONNAL
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_additionnal');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_additionnal',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' => array(
			'max_length' => 255,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => FALSE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_additionnal');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_additionnal',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Additionnal',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champ CITY
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_city');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_city',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' => array(
			'max_length' => 255,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => FALSE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_city');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_city',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'City',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ POSTAL CODE
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_postal_code');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_postal_code',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' => array(
			'max_length' => 255,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => FALSE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_postal_code');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_postal_code',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Postal code',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ PHONE NUMBER
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_phone_number');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_phone_number',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' => array(
			'max_length' => 255,
			'is_ascii' => FALSE,
			'case_sensitive' => FALSE,
		),
		'translatable' => FALSE,
		'cardinality' => 1,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_phone_number');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_phone_number',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Phone number',
		'field_type' => 'string',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champ PHONE NUMBER
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_email_address');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_email_address',
		'entity_type' => 'node',
		'type' => 'email',
		'settings' => array (
		),
		'module' => 'core',
		'translatable' => FALSE,
		'cardinality' => 1,
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_email_address');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_email_address',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Email address',
		'field_type' => 'email',
		'required' => FALSE,
		'translatable' => FALSE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ COUNTRY
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_office_country');
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
		'field_name' => 'field_office_country',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'translatable' => FALSE,
		'cardinality' => 1,
		'indexes' =>
			array (
			),
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_office_country');
if (empty($field)) {
	$config_array = array(
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_office_country',
						1 => 'node.type.office',
						2 => 'taxonomy.vocabulary.office_countries',
					),
			),
		'field_name' => 'field_office_country',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Country',
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
								'office_countries' => 'office_countries',
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
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

//Champ LOCATION
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_office_location');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'geolocation',
						1 => 'node',
					),
			),
		'field_name' => 'field_office_location',
		'entity_type' => 'node',
		'type' => 'geolocation',
		'settings' =>
			array (
			),
		'module' => 'geolocation',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_office_location');
if (empty($field)) {
	$config_array = array(
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_office_location',
						1 => 'node.type.office',
					),
				'module' =>
					array (
						0 => 'geolocation',
					),
			),
		'field_name' => 'field_office_location',
		'entity_type' => 'node',
		'bundle' => 'office',
		'label' => 'Location',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'geolocation',
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


//Champ REGION
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_region');
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
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'office', 'field_region');
if (empty($field)) {
	$config_array = array(
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_region',
						1 => 'node.type.office',
						2 => 'taxonomy.vocabulary.regions',
					),
			),
		'field_name' => 'field_region',
		'entity_type' => 'node',
		'bundle' => 'office',
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
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.base_field_override.node.office.title');
$config_comment->set('label' , 'Office name');
$config_comment->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_form_display.node.office.default');
$config_comment->set('dependencies' , array (
	'config' =>
		array (
			0 => 'field.field.node.office.field_additionnal',
			1 => 'field.field.node.office.field_city',
			2 => 'field.field.node.office.field_email_address',
			3 => 'field.field.node.office.field_office_country',
			4 => 'field.field.node.office.field_office_location',
			5 => 'field.field.node.office.field_phone_number',
			6 => 'field.field.node.office.field_postal_code',
			7 => 'field.field.node.office.field_region',
			8 => 'field.field.node.office.field_street',
			9 => 'node.type.office',
		),
	'module' =>
		array (
			0 => 'field_group',
			1 => 'geolocation',
			2 => 'workbench_moderation',
		),
));
$config_comment->set('third_party_settings' , array (
	'field_group' =>
		array (
			'group_classify' =>
				array (
					'children' =>
						array (
							0 => 'field_office_country',
							1 => 'field_region',
						),
					'parent_name' => 'group_tabs',
					'weight' => 2,
					'format_type' => 'tab',
					'format_settings' =>
						array (
							'id' => '',
							'classes' => '',
							'formatter' => 'closed',
							'description' => '',
							'required_fields' => true,
						),
					'label' => 'Classify',
				),
			'group_write' =>
				array (
					'children' =>
						array (
							0 => 'title',
							1 => 'langcode',
							2 => 'field_street',
							3 => 'field_additionnal',
							4 => 'field_postal_code',
							5 => 'field_city',
							6 => 'field_phone_number',
							7 => 'field_email_address',
							8 => 'field_office_location',
						),
					'parent_name' => 'group_tabs',
					'weight' => 1,
					'format_type' => 'tab',
					'format_settings' =>
						array (
							'id' => '',
							'classes' => '',
							'formatter' => 'closed',
							'description' => '',
							'required_fields' => true,
						),
					'label' => 'Write',
				),
			'group_tabs' =>
				array (
					'children' =>
						array (
							0 => 'group_write',
							1 => 'group_classify',
						),
					'parent_name' => '',
					'weight' => 0,
					'format_type' => 'tabs',
					'format_settings' =>
						array (
							'id' => '',
							'classes' => '',
							'direction' => 'vertical',
						),
					'label' => 'Tabs',
				),
		),
));
$config_comment->set('content' , array (
	'field_additionnal' =>
		array (
			'weight' => 4,
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
	'field_city' =>
		array (
			'weight' => 6,
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
	'field_email_address' =>
		array (
			'weight' => 8,
			'settings' =>
				array (
					'size' => 60,
					'placeholder' => '',
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'email_default',
			'region' => 'content',
		),
	'field_office_country' =>
		array (
			'weight' => 6,
			'settings' =>
				array (
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'options_select',
			'region' => 'content',
		),
	'field_office_location' =>
		array (
			'weight' => 9,
			'settings' =>
				array (
					'default_longitude' => '2.3522219000000177',
					'default_latitude' => '48.856614',
					'auto_client_location' => '1',
					'google_map_settings' =>
						array (
							'height' => '400px',
							'width' => '100%',
							'type' => 'ROADMAP',
							'zoom' => '6',
							'maxZoom' => 18,
							'minZoom' => 0,
							'zoomControl' => 1,
							'scrollwheel' => 1,
							'gestureHandling' => 'auto',
							'draggable' => 1,
							'style' => '',
							'info_auto_display' => 1,
							'marker_icon_path' => '',
							'disableAutoPan' => 1,
							'mapTypeControl' => 0,
							'streetViewControl' => 0,
							'rotateControl' => 0,
							'fullscreenControl' => 0,
							'preferScrollingToZooming' => 0,
							'disableDoubleClickZoom' => 0,
						),
					'auto_client_location_marker' => '0',
					'allow_override_map_settings' => 0,
					'populate_address_field' => '',
					'target_address_field' => NULL,
					'explicite_actions_address_field' => '',
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'geolocation_googlegeocoder',
			'region' => 'content',
		),
	'field_phone_number' =>
		array (
			'weight' => 7,
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
	'field_postal_code' =>
		array (
			'weight' => 5,
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
	'field_region' =>
		array (
			'weight' => 7,
			'settings' =>
				array (
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'options_select',
			'region' => 'content',
		),
	'field_street' =>
		array (
			'weight' => 3,
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
			'settings' =>
				array (
				),
			'third_party_settings' =>
				array (
				),
			'region' => 'content',
		),
	'title' =>
		array (
			'type' => 'string_textfield',
			'weight' => 1,
			'settings' =>
				array (
					'size' => 60,
					'placeholder' => '',
				),
			'third_party_settings' =>
				array (
				),
			'region' => 'content',
		),
));
$config_comment->set('hidden' , array (
	'created' => true,
	'path' => true,
	'promote' => true,
	'sticky' => true,
	'uid' => true,
));
$config_comment->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_view_display.node.office.default');
$config_comment->set('dependencies' , array (
	'config' =>
		array (
			0 => 'field.field.node.office.field_additionnal',
			1 => 'field.field.node.office.field_city',
			2 => 'field.field.node.office.field_email_address',
			3 => 'field.field.node.office.field_office_country',
			4 => 'field.field.node.office.field_office_location',
			5 => 'field.field.node.office.field_phone_number',
			6 => 'field.field.node.office.field_postal_code',
			7 => 'field.field.node.office.field_region',
			8 => 'field.field.node.office.field_street',
			9 => 'node.type.office',
		),
	'module' =>
		array (
			0 => 'geolocation',
			1 => 'user',
		),
));
$config_comment->set('content' ,array (
	'field_additionnal' =>
		array (
			'weight' => 102,
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
	'field_city' =>
		array (
			'weight' => 103,
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
	'field_email_address' =>
		array (
			'weight' => 107,
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
	'field_office_country' =>
		array (
			'weight' => 105,
			'label' => 'above',
			'settings' =>
				array (
					'link' => false,
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'entity_reference_label',
			'region' => 'content',
		),
	'field_office_location' =>
		array (
			'weight' => 108,
			'label' => 'above',
			'settings' =>
				array (
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'geolocation_latlng',
			'region' => 'content',
		),
	'field_phone_number' =>
		array (
			'weight' => 106,
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
	'field_postal_code' =>
		array (
			'weight' => 104,
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
	'field_region' =>
		array (
			'weight' => 109,
			'label' => 'above',
			'settings' =>
				array (
					'link' => true,
				),
			'third_party_settings' =>
				array (
				),
			'type' => 'entity_reference_label',
			'region' => 'content',
		),
	'field_street' =>
		array (
			'weight' => 101,
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
	'links' =>
		array (
			'weight' => 100,
			'settings' =>
				array (
				),
			'third_party_settings' =>
				array (
				),
			'region' => 'content',
		),
) );
$config_comment->save(TRUE);

//traductions
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_street', array (
	'label' => 'Rue',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_additionnal', array (
	'label' => 'Complément',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_city', array (
	'label' => 'Ville',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_postal_code', array (
	'label' => 'Code postal',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_phone_number', array (
	'label' => 'Numéro de téléphone',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_email_address', array (
	'label' => 'Courriel',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_office_country', array (
	'label' => 'Pays',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.office.field_office_location', array (
	'label' => 'Localisation',
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('core.base_field_override.node.office.title', array (
	'label' => 'Bureau',
));