<?php

//BLOG POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.office_node');
$config_group->set('dependencies', array (
	'module' =>
		array (
			0 => 'migrate_plus',
			1 => 'node',
		),
));
$config_group->set('process',array (
	'type' =>
		array (
			'plugin' => 'default_value',
			'default_value' => 'office',
		),
	'title' => 'title',
	'created' => 'created',
	'changed' => 'changed',
	'status' => 'status',
	'langcode' => 'language',
	'uid' =>
		array (
			'plugin' => 'default_value',
			'default_value' => 1,
		),
	'field_office_location/lat' => 'latitude',
	'field_office_location/lng' => 'longitude',
	'field_office_country' => 'country',
	'field_city' => 'city',
	'field_postal_code' => 'postal_code',
	'field_phone_number' => 'phone_number',
	'field_street' => 'street',
	'field_additionnal' => 'additional',
	'field_email_address' => 'email_address',
	'field_region' => 'regions',
));
$config_group->save(TRUE);