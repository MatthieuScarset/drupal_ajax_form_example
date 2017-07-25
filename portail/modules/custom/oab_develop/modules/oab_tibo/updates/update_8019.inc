<?php

// image style top zone 550px hauteur
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.top_zone_big');
$config_group->setData(
	array (
		'uuid' => 'c55bb1bd-dbd2-41fe-b153-d7ef6d60282d',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'top_zone_big',
		'label' => 'Top zone big',
		'effects' =>
			array (
				'cb946ff7-285a-4ecd-b82c-b55375a0ac81' =>
					array (
						'uuid' => 'cb946ff7-285a-4ecd-b82c-b55375a0ac81',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 1400,
								'height' => 500,
							),
					),
			),
	)
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();