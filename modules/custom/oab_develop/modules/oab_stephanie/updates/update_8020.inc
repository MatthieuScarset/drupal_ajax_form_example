<?php
// ajout du style d'image blogger insert

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.blogger_insert');
$config_group->setData(
	array (
		'uuid' => 'b24cd4f5-df41-4b7f-b0cb-0998ee70521c',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'blogger_insert',
		'label' => 'Blogger insert',
		'effects' =>
			array (
				'3aa2356b-84fb-4275-9097-9dc6af6c772d' =>
					array (
						'uuid' => '3aa2356b-84fb-4275-9097-9dc6af6c772d',
						'id' => 'image_scale',
						'weight' => 1,
						'data' =>
							array (
								'width' => 170,
								'height' => 170,
								'upscale' => false,
							),
					),
			),
	)
);
$config_group->save(TRUE);

//traduction du style d'image FR
$connection = \Drupal\Core\Database\Database::getConnection();
$query_create = $connection->insert('config')
	->fields(array(
		'collection' => 'language.fr',
		'name' => 'image.style.blogger_insert',
		'data' => serialize(array (
			'label' => 'Encart bloggeur',
		))
	))
	->execute();



//Ajout du mode d'affichage Media : Blogger insert
$config_group = $config_factory->getEditable('core.entity_view_mode.media.blogger_insert');
$config_group->setData(
	array (
		'uuid' => '77f812c1-4b17-4438-8d36-3bae3d5b8362',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'media_entity',
					),
			),
		'id' => 'media.blogger_insert',
		'label' => 'Blogger insert',
		'targetEntityType' => 'media',
		'cache' => true,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_view_display.media.image.blogger_insert');
$config_group->setData(
	array (
		'uuid' => 'f2271d47-8362-4cc8-8cdd-6d2148e9e891',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.media.blogger_insert',
						1 => 'field.field.media.image.field_image',
						2 => 'field.field.media.image.field_tags',
						3 => 'field.field.media.image.field_thematic',
						4 => 'image.style.blogger_insert',
						5 => 'media_entity.bundle.image',
					),
				'module' =>
					array (
						0 => 'image',
					),
			),
		'id' => 'media.image.blogger_insert',
		'targetEntityType' => 'media',
		'bundle' => 'image',
		'mode' => 'blogger_insert',
		'content' =>
			array (
				'field_image' =>
					array (
						'weight' => 2,
						'label' => 'hidden',
						'settings' =>
							array (
								'image_style' => 'blogger_insert',
								'image_link' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'image',
					),
			),
		'hidden' =>
			array (
				'created' => true,
				'field_tags' => true,
				'field_thematic' => true,
				'langcode' => true,
				'name' => true,
				'thumbnail' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

//Modification du rendu Teaser du profile pour utilisé le rendu blogger insert pour l'image
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.teaser');
$config_group->set('content.field_visual', array (
	'type' => 'entity_reference_entity_view',
	'weight' => 1,
	'label' => 'hidden',
	'settings' =>
		array (
			'view_mode' => 'blogger_insert',
			'link' => false,
		),
	'third_party_settings' =>
		array (
		),
));
$config_group->save(TRUE);