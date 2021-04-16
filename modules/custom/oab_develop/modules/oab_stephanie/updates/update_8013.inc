<?php

/**
 * Encart profile bloggeur
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.teaser');
$config_group->setData(
	array (
		'uuid' => 'e3e9f379-0205-41c0-ae2c-de44d430ac57',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.teaser',
						1 => 'field.field.node.profile.body',
						2 => 'field.field.node.profile.field_first_name',
						3 => 'field.field.node.profile.field_job',
						4 => 'field.field.node.profile.field_last_name',
						5 => 'field.field.node.profile.field_link',
						6 => 'field.field.node.profile.field_location',
						7 => 'field.field.node.profile.field_metatags',
						8 => 'field.field.node.profile.field_social_accounts',
						9 => 'field.field.node.profile.field_visual',
						10 => 'node.type.profile',
					),
				'module' =>
					array (
						0 => 'text',
						1 => 'user',
					),
			),
		'id' => 'node.profile.teaser',
		'targetEntityType' => 'node',
		'bundle' => 'profile',
		'mode' => 'teaser',
		'content' =>
			array (
				'body' =>
					array (
						'label' => 'hidden',
						'type' => 'text_default',
						'weight' => 4,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_first_name' =>
					array (
						'type' => 'string',
						'weight' => 2,
						'label' => 'hidden',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_last_name' =>
					array (
						'type' => 'string',
						'weight' => 3,
						'label' => 'hidden',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_visual' =>
					array (
						'type' => 'entity_reference_entity_view',
						'weight' => 1,
						'label' => 'hidden',
						'settings' =>
							array (
								'link' => true,
								'view_mode' => 'default',
							),
						'third_party_settings' =>
							array (
							),
					),
				'links' =>
					array (
						'weight' => 0,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
			),
		'hidden' =>
			array (
				'field_job' => true,
				'field_link' => true,
				'field_location' => true,
				'field_metatags' => true,
				'field_social_accounts' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);



$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_group->set('content.field_profile', array (
	'weight' => 14,
	'label' => 'hidden',
	'settings' =>
		array (
			'link' => false,
			'view_mode' => 'teaser',
		),
	'third_party_settings' =>
		array (
		),
	'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);