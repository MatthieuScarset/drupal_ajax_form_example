<?php

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.blogpost_comment');
$config_comment->setData(
	array (
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'blogpost_comment',
		'migration_group' => 'blogpost',
		'label' => 'Blog posts comments',
		'source' =>
			array (
				'plugin' => 'blogpost_comment',
			),
		'destination' =>
			array (
				'plugin' => 'entity:comment',
			),
		'process' =>
			array (
				'comment_type' => array (
					'plugin' => 'default_value',
					'default_value' => 'comment_blog'
				),
				'pid' => 'pid_parent',
				'entity_id' => array (
					'plugin' => 'migration',
					'migration' => 'blogpost_node',
					'source' => 'nid'
				),
				'entity_type' => array (
					'plugin' => 'default_value',
					'default_value' => 'node'
				),
				'field_name' => array (
					'plugin' => 'default_value',
					'default_value' => 'field_comments'
				),
				'uid' => 'uid',
				'subject' => 'subject',
				'hostname' => 'hostname',
				'created' => 'created',
				'changed' => 'changed',
				'status' => 'status',
				'thread' => 'thread',
				'name' => 'name',
				'mail' => 'mail',
				'homepage' => 'homepage',
				'langcode' => 'language',
				'default_langcode' => 'default_langcode',
				'comment_body' => 'comment_body',
			),

		'migration_dependencies' =>
			array (
				'required' =>
					array (
						0 => 'blogpost_node'
					),
			),
	));
$config_comment->save(TRUE);