<?php
/**
 * Création du mode de vue media Automatic Teaser
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.automatic_teaser');
$config_group->setData(
	array (
		'uuid' => 'b5ee3415-eb43-4eba-840b-ab275bf8d331',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'media_entity',
					),
			),
		'id' => 'media.automatic_teaser',
		'label' => 'Automatic teaser',
		'targetEntityType' => 'media',
		'cache' => true,
	)
);
$config_group->save(TRUE);
