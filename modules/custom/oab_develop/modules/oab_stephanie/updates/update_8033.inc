<?php

/*********************************
 * Ajout de la config metatags pour les Products
 *********************************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__product');
$config_group->setData(
	array (
		'uuid' => '97a0bc61-7e25-4427-abbe-ffc026c4841f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'node__product',
		'label' => 'Content: Product',
		'tags' =>
			array (
				'description' => '[node:field_meta_description]',
				'title' => '[node:field_meta_title] | [site:name]',
			),
	)
);
$config_group->save(TRUE);
