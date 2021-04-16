<?php

// configuration pour embed.button.node
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.node');
$config_group->setData(array (
	'uuid' => 'd9f2ecc4-63f1-49f5-aaa7-4b64b98107d7',
	'langcode' => 'en',
	'status' => true,
	'dependencies' =>
		array (
			'config' =>
				array (
					0 => 'node.type.blog_post',
					1 => 'node.type.customer_story',
					2 => 'node.type.document',
					3 => 'node.type.magazine',
					4 => 'node.type.partner',
					5 => 'node.type.press_kit',
					6 => 'node.type.simple_page',
				),
			'content' =>
				array (
					0 => 'file:file:d780d689-d62a-4f46-9837-7cb10653a7d6',
				),
			'module' =>
				array (
					0 => 'entity_embed',
					1 => 'node',
				),
		),
	'_core' =>
		array (
			'default_config_hash' => 'xgvZUh-eaMilacE1XYCQ9nLH-2-meOjCyofXSO82gqg',
		),
	'label' => 'Node',
	'id' => 'node',
	'type_id' => 'entity',
	'type_settings' =>
		array (
			'entity_type' => 'node',
			'bundles' =>
				array (
					0 => 'blog_post',
					1 => 'customer_story',
					2 => 'document',
					3 => 'magazine',
					4 => 'partner',
					5 => 'press_kit',
					6 => 'simple_page',
				),
			'display_plugins' =>
				array (
					0 => 'view_mode:node.wysiwyg_node_embed',
				),
			'entity_browser' => '',
			'entity_browser_settings' =>
				array (
					'display_review' => false,
				),
		),
	'icon_uuid' => 'd780d689-d62a-4f46-9837-7cb10653a7d6',
));
$config_group->save();

//throw new \Drupal\Core\Utility\UpdateException();