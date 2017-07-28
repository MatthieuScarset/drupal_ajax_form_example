<?php

//BLOG POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config_group->set(
		'process' ,
			array (
				'type' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'blog_post',
					),
				'title' => 'title',
				'created' => 'created',
				'changed' => 'changed',
				'langcode' => 'language',
				'uid' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 1,
					),
				'field_content/value' => 'content_field',
				'field_content/format' =>
					array (
						'plugin' => 'default_value',
						'default_value' => 'full_html',
					),
				'field_blog_thematic' => 'blog_thematics',
				'field_blog_format' => 'blog_formats',
				'field_industry' => 'industries',
				'field_region' => 'regions',
				'field_subhome' => 'subhomes',
				'field_insight' => 'thematics',
				'field_visual' =>
					array (
						'plugin' => 'migration',
						'migration' => 'blogpost_media',
						'source' => 'images',
					),
				'path' => 'path',
				'field_profile' => 'profile_blogger_id',
				'moderation_state' => 'moderation_state',
				'status' => 'status',
				'field_meta_title' => 'meta_title',
				'field_meta_description' => 'meta_description',
			));
$config_group->save(TRUE);