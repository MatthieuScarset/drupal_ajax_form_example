<?php

//titre block phone number
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.phonenumber');
$config_group->set('settings.block_title', 'To contact him by phone');
$config_group->save(TRUE);

//Traduction
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('block.block.phonenumber', array (
	'settings' =>
		array (
			'block_title' => 'Pour le contacter par téléphone',
		),
));