<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.top_zone');
$config_group->setData(
	array (
		'uuid' => 'f7846ea5-7648-4499-9445-d87ea096630f',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'top_zone',
		'label' => 'Top zone',
		'effects' =>
			array (
				'7c40d148-7df6-4a44-8c1e-4f4015fc79ec' =>
					array (
						'uuid' => '7c40d148-7df6-4a44-8c1e-4f4015fc79ec',
						'id' => 'image_scale_and_crop',
						'weight' => 1,
						'data' =>
							array (
								'width' => 3000,
								'height' => 280,
							),
					),
			),
	)
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();