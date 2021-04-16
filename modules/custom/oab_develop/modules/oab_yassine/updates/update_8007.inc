<?php

// ajout du bypass pour password policy
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.localnav');
$config_group->setData(
	array (
		'uuid' => '0a953f33-4f5e-4d94-b041-1a1a9a1ca8aa',
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
		'id' => 'localnav',
		'theme' => 'theme_boosted',
		'region' => 'top_zone',
		'weight' => 0,
		'provider' => NULL,
		'plugin' => 'local_nav_block',
		'settings' =>
			array (
				'id' => 'local_nav_block',
				'label' => 'Local Nav',
				'provider' => 'oab_frontoffice',
				'label_display' => '0',
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
								'industry' => 'industry',
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