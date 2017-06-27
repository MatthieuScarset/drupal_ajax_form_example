<?php

// ajout du bypass pour password policy
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topzone');
$config_group->setData(
	array (
		'uuid' => '4f93e884-e26f-402b-a392-833e615de361',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'ctools',
						1 => 'oab_frontoffice',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'id' => 'topzone',
		'theme' => 'theme_boosted',
		'region' => 'top_zone',
		'weight' => -17,
		'provider' => NULL,
		'plugin' => 'top_zone_block',
		'settings' =>
			array (
				'id' => 'top_zone_block',
				'label' => 'Top Zone',
				'provider' => 'oab_frontoffice',
				'label_display' => 'visible',
				'context_mapping' =>
					array (
						'node' => '@node.node_route_context:node',
					),
			),
		'visibility' =>
			array (
				'entity_bundle:node' =>
					array (
						'id' => 'entity_bundle:node',
						'bundles' =>
							array (
								'country' => 'country',
								'industry' => 'industry',
								'product' => 'product',
								'region' => 'region',
								'solution' => 'solution',
							),
						'negate' => false,
						'context_mapping' =>
							array (
								'node' => '@node.node_route_context:node',
							),
					),
			),
	)
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();