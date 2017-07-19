<?php

// configuration pour embed.button.node
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.node');
$config_group->set('dependencies', array(
	'config' =>
		array (
			0 => 'node.type.blog_post',
			1 => 'node.type.customer_story',
			2 => 'node.type.document',
			3 => 'node.type.magazine',
			4 => 'node.type.partner',
			5 => 'node.type.press_kit',
			6 => 'node.type.press_release',
			7 => 'node.type.simple_page',
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
));
$config_group->save();

//throw new \Drupal\Core\Utility\UpdateException();