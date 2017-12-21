<?php
//Traduction du block Find distributor en FR
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('block.block.finddistributorblock', array (
	'settings' =>
		array (
			'title' => 'Trouver un revendeur à proximité',
		),
));