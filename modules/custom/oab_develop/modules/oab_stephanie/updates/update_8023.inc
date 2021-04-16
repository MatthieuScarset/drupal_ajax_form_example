<?php
// activation workbench moderation sur les press releases

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.press_release');
$config_group->setData(
	array (
		'uuid' => '5af5eb9b-5a2f-499a-9137-d078fa1e969f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'menu_ui',
						1 => 'workbench_access',
						2 => 'workbench_moderation',
					),
			),
		'third_party_settings' =>
			array (
				'menu_ui' =>
					array (
						'available_menus' =>
							array (
							),
						'parent' => '',
					),
				'workbench_access' =>
					array (
						'workbench_access_status' => false,
					),
				'workbench_moderation' =>
					array (
						'enabled' => true,
						'allowed_moderation_states' =>
							array (
								0 => 'published',
								1 => 'archived',
								2 => 'draft',
								3 => 'needs_review',
								4 => 'unpublished',
							),
						'default_moderation_state' => 'draft',
					),
			),
		'name' => 'Communiqué de presse',
		'type' => 'press_release',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

//Applique les modifications en bdd pour la traduction : ajout des colonnes necessaires
\Drupal::entityDefinitionUpdateManager()->applyUpdates();

