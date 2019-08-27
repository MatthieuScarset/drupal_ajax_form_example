<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_offices_map.offices_map');
$config_group->set('contact_url', '/en'); // juste pour initialiser => à chnger
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.offices_map_view');
$config_group->set('display.default.display_options.row.options.inline', array (
	'field_postal_code' => 'field_postal_code',
	'field_city' => 'field_city',
	'field_region' => 'field_region',
));
$config_group->set('display.offices_addresses_list_block.display_options.row.options.inline', array (
	'field_postal_code' => 'field_postal_code',
	'field_city' => 'field_city',
	'field_region' => 'field_region',
));
$config_group->save();