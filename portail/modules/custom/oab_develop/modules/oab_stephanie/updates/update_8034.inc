<?php

/*
 * Ajout du type de commentaire Comment Blog
 */
$new_type = \Drupal\comment\Entity\CommentType::load('comment_blog');
if (empty($new_type)) {
	$new_type = \Drupal\comment\Entity\CommentType::create(array(
		'id' => 'comment_blog',
		'label' => 'Blogs Comments',
		'target_entity_type_id' => 'node',
		'description' => 'Comment for blog post',
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('comment', 'comment_blog', 'comment_body');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'comment_body',
		'entity_type' => 'comment',
		'bundle' => 'comment_blog',
		'label' => 'Comment',
		'field_type' => 'text_long',
		'required' => TRUE,
		'translatable' => TRUE,
		'default_value' => array(
		),
		'settings' => array()
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_form_display.comment.comment_blog.default');
$config_comment->set('langcode' , 'en');
$config_comment->set('status' , true);
$config_comment->set('dependencies' ,
	array (
		'config' =>
			array (
				0 => 'comment.type.comment_blog',
				1 => 'field.field.comment.comment_blog.comment_body',
			),
		'module' =>
			array (
				0 => 'text',
			),
	));
$config_comment->set('id' , 'comment.comment_blog.default');
$config_comment->set('targetEntityType' , 'comment');
$config_comment->set('bundle' , 'comment_blog');
$config_comment->set('mode' , 'default');
$config_comment->set('content' ,
	array (
		'author' =>
			array (
				'weight' => -2,
				'region' => 'content',
			),
		'comment_body' =>
			array (
				'type' => 'text_textarea',
				'weight' => 11,
				'settings' =>
					array (
						'rows' => 5,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'langcode' =>
			array (
				'type' => 'language_select',
				'weight' => 2,
				'region' => 'content',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
			),
		'subject' =>
			array (
				'type' => 'string_textfield',
				'weight' => 10,
				'region' => 'content',
				'settings' =>
					array (
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
			),
	));
$config_comment->set('hidden' ,
	array (
	));
$config_comment->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_view_display.comment.comment_blog.default');
$config_comment->set(	'langcode' , 'en');
$config_comment->set(	'status' , true);
$config_comment->set(	'dependencies' ,
	array (
		'config' =>
			array (
				0 => 'comment.type.comment_blog',
				1 => 'field.field.comment.comment_blog.comment_body',
			),
		'module' =>
			array (
				0 => 'text',
			),
	));
$config_comment->set(	'id' , 'comment.comment_blog.default');
$config_comment->set(	'targetEntityType' , 'comment');
$config_comment->set(	'bundle' , 'comment_blog');
$config_comment->set(	'mode' , 'default');
$config_comment->set(	'content' ,
	array (
		'comment_body' =>
			array (
				'label' => 'hidden',
				'type' => 'text_default',
				'weight' => 0,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'links' =>
			array (
				'weight' => 100,
				'region' => 'content',
			),
	));
$config_comment->set(	'hidden' ,
	array (
		'langcode' => true,
	));
$config_comment->save(TRUE);

/*
 * Ajout du champ commentaires au type de contenu Blogpost
 */
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_comments');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_comments',
		'entity_type' => 'node',
		'type' => 'comment',
		'cardinality' => 1,
		'langcode' => 'en',
		'module' => 'comment',
		'settings' => array(
			'comment_type' => 'comment_blog'
		)
	))->save();
}

$field = \Drupal\field\Entity\FieldConfig::loadByName('node', 'blog_post', 'field_comments');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_comments',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'field_type' => 'comment',
		'label' => 'Comments',
		'required' => FALSE,
		'default_value' => array(
			array(
				'status' => 1,
				'cid' => 0
			)
		),
		'settings' => array(
			'default_mode' => 1,
			'per_page' => 50,
			'anonymous' => 0,
			'form_location' => true,
			'preview' => 0,
		)
	);
	\Drupal\field\Entity\FieldConfig::create($config_array)->save();
}


$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_form_display.node.blog_post.default');
$config_comment->set('langcode','en');
$config_comment->set('status', true);
$config_comment->set('dependencies' ,
	array (
		'config' =>
			array (
				0 => 'entity_browser.browser.browse_media_modal',
				1 => 'field.field.node.blog_post.field_blog_format',
				2 => 'field.field.node.blog_post.field_blog_thematic',
				3 => 'field.field.node.blog_post.field_comments',
				4 => 'field.field.node.blog_post.field_content',
				5 => 'field.field.node.blog_post.field_content_owner',
				6 => 'field.field.node.blog_post.field_display_title',
				7 => 'field.field.node.blog_post.field_email_owner',
				8 => 'field.field.node.blog_post.field_end_date',
				9 => 'field.field.node.blog_post.field_highlight',
				10 => 'field.field.node.blog_post.field_industry',
				11 => 'field.field.node.blog_post.field_insight',
				12 => 'field.field.node.blog_post.field_job_profile',
				13 => 'field.field.node.blog_post.field_market_segment',
				14 => 'field.field.node.blog_post.field_meta_description',
				15 => 'field.field.node.blog_post.field_meta_title',
				16 => 'field.field.node.blog_post.field_metatags',
				17 => 'field.field.node.blog_post.field_profile',
				18 => 'field.field.node.blog_post.field_region',
				19 => 'field.field.node.blog_post.field_solution',
				20 => 'field.field.node.blog_post.field_start_date',
				21 => 'field.field.node.blog_post.field_subhome',
				22 => 'field.field.node.blog_post.field_thematic',
				23 => 'field.field.node.blog_post.field_visual',
				24 => 'field.field.node.blog_post.publish_date',
				25 => 'field.field.node.blog_post.unpublish_date',
				26 => 'node.type.blog_post',
			),
		'module' =>
			array (
				0 => 'comment',
				1 => 'datetime',
				2 => 'entity_browser',
				3 => 'field_group',
				4 => 'inline_entity_form',
				5 => 'metatag',
				6 => 'path',
				7 => 'text',
				8 => 'workbench_moderation',
			),
	));
$config_comment->set('third_party_settings' ,
	array (
		'field_group' =>
			array (
				'group_onglets' =>
					array (
						'children' =>
							array (
								0 => 'group_write',
								1 => 'group_classify',
								2 => 'group_seo',
								3 => 'group_publish',
							),
						'parent_name' => '',
						'weight' => 0,
						'format_type' => 'tabs',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'direction' => 'vertical',
							),
						'label' => 'Onglets',
					),
				'group_write' =>
					array (
						'children' =>
							array (
								0 => 'langcode',
								1 => 'title',
								2 => 'field_display_title',
								3 => 'field_highlight',
								4 => 'field_profile',
								5 => 'field_content',
								6 => 'field_visual',
							),
						'parent_name' => 'group_onglets',
						'weight' => 4,
						'format_type' => 'tab',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'formatter' => 'closed',
								'description' => '',
								'required_fields' => true,
							),
						'label' => 'Write',
					),
				'group_classify' =>
					array (
						'children' =>
							array (
								0 => 'field_subhome',
								1 => 'field_industry',
								2 => 'field_region',
								3 => 'field_job_profile',
								4 => 'field_blog_thematic',
								5 => 'field_blog_format',
								6 => 'field_insight',
							),
						'parent_name' => 'group_onglets',
						'weight' => 5,
						'format_type' => 'tab',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'formatter' => 'closed',
								'description' => '',
								'required_fields' => true,
							),
						'label' => 'Classify',
					),
				'group_publish' =>
					array (
						'children' =>
							array (
								0 => 'field_content_owner',
								1 => 'field_email_owner',
								2 => 'group_content_worthy_period',
								3 => 'group_scheduled_updates',
								4 => 'promote',
								5 => 'path',
								6 => 'field_metatags',
							),
						'parent_name' => 'group_onglets',
						'weight' => 7,
						'format_type' => 'tab',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'formatter' => 'closed',
								'description' => '',
								'required_fields' => true,
							),
						'label' => 'Publish',
					),
				'group_content_worthy_period' =>
					array (
						'children' =>
							array (
								0 => 'field_start_date',
								1 => 'field_end_date',
							),
						'parent_name' => 'group_publish',
						'weight' => 14,
						'format_type' => 'fieldset',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'description' => '',
								'required_fields' => true,
							),
						'label' => 'Content worthy period',
					),
				'group_scheduled_updates' =>
					array (
						'children' =>
							array (
								0 => 'publish_date',
								1 => 'unpublish_date',
							),
						'parent_name' => 'group_publish',
						'weight' => 15,
						'format_type' => 'fieldset',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'description' => '',
								'required_fields' => false,
							),
						'label' => 'Scheduled Updates',
					),
				'group_seo' =>
					array (
						'children' =>
							array (
								0 => 'field_meta_title',
								1 => 'field_meta_description',
							),
						'parent_name' => 'group_onglets',
						'weight' => 6,
						'format_type' => 'tab',
						'format_settings' =>
							array (
								'id' => '',
								'classes' => '',
								'formatter' => 'closed',
								'description' => '',
								'required_fields' => true,
							),
						'label' => 'SEO',
					),
			),
	));
$config_comment->set('id' , 'node.blog_post.default');
$config_comment->set('targetEntityType', 'node');
$config_comment->set('bundle' , 'blog_post');
$config_comment->set('mode' , 'default');
$config_comment->set('content' ,
	array (
		'field_blog_format' =>
			array (
				'type' => 'options_select',
				'weight' => 31,
				'region' => 'content',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
			),
		'field_blog_thematic' =>
			array (
				'type' => 'options_select',
				'weight' => 30,
				'region' => 'content',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
			),
		'field_comments' =>
			array (
				'weight' => 33,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'comment_default',
				'region' => 'content',
			),
		'field_content' =>
			array (
				'weight' => 8,
				'settings' =>
					array (
						'rows' => 5,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'text_textarea',
				'region' => 'content',
			),
		'field_content_owner' =>
			array (
				'weight' => 12,
				'settings' =>
					array (
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'string_textfield',
				'region' => 'content',
			),
		'field_display_title' =>
			array (
				'weight' => 3,
				'settings' =>
					array (
						'display_label' => false,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'boolean_checkbox',
				'region' => 'content',
			),
		'field_email_owner' =>
			array (
				'weight' => 13,
				'settings' =>
					array (
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'string_textfield',
				'region' => 'content',
			),
		'field_end_date' =>
			array (
				'weight' => 15,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'datetime_default',
				'region' => 'content',
			),
		'field_highlight' =>
			array (
				'weight' => 5,
				'settings' =>
					array (
						'rows' => 5,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'string_textarea',
				'region' => 'content',
			),
		'field_industry' =>
			array (
				'weight' => 27,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'options_select',
				'region' => 'content',
			),
		'field_insight' =>
			array (
				'weight' => 32,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'options_select',
				'region' => 'content',
			),
		'field_job_profile' =>
			array (
				'weight' => 29,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'options_select',
				'region' => 'content',
			),
		'field_meta_description' =>
			array (
				'weight' => 5,
				'settings' =>
					array (
						'size' => 156,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'string_textfield',
				'region' => 'content',
			),
		'field_meta_title' =>
			array (
				'weight' => 4,
				'settings' =>
					array (
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'string_textfield',
				'region' => 'content',
			),
		'field_metatags' =>
			array (
				'weight' => 18,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'metatag_firehose',
				'region' => 'content',
			),
		'field_profile' =>
			array (
				'weight' => 7,
				'settings' =>
					array (
						'match_operator' => 'CONTAINS',
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'entity_reference_autocomplete',
				'region' => 'content',
			),
		'field_region' =>
			array (
				'weight' => 28,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'options_select',
				'region' => 'content',
			),
		'field_start_date' =>
			array (
				'weight' => 14,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'datetime_default',
				'region' => 'content',
			),
		'field_subhome' =>
			array (
				'weight' => 26,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'options_select',
				'region' => 'content',
			),
		'field_visual' =>
			array (
				'type' => 'entity_browser_entity_reference',
				'weight' => 9,
				'settings' =>
					array (
						'entity_browser' => 'browse_media_modal',
						'field_widget_display' => 'rendered_entity',
						'field_widget_edit' => true,
						'field_widget_remove' => true,
						'selection_mode' => 'selection_append',
						'field_widget_display_settings' =>
							array (
								'view_mode' => 'default',
							),
						'open' => false,
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'langcode' =>
			array (
				'type' => 'language_select',
				'weight' => 1,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'path' =>
			array (
				'type' => 'path',
				'weight' => 17,
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'promote' =>
			array (
				'type' => 'boolean_checkbox',
				'weight' => 16,
				'settings' =>
					array (
						'display_label' => true,
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'publish_date' =>
			array (
				'type' => 'inline_entity_form_complex',
				'weight' => 11,
				'settings' =>
					array (
						'override_labels' => true,
						'label_singular' => 'Publish date',
						'label_plural' => 'Publish dates',
						'allow_new' => true,
						'match_operator' => 'CONTAINS',
						'allow_existing' => false,
						'form_mode' => 'default',
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'title' =>
			array (
				'type' => 'string_textfield',
				'weight' => 2,
				'settings' =>
					array (
						'size' => 60,
						'placeholder' => '',
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
		'unpublish_date' =>
			array (
				'type' => 'inline_entity_form_complex',
				'weight' => 12,
				'settings' =>
					array (
						'override_labels' => true,
						'label_singular' => 'Unpublish Date',
						'label_plural' => 'Unpublish Dates',
						'allow_new' => true,
						'match_operator' => 'CONTAINS',
						'allow_existing' => false,
						'form_mode' => 'default',
					),
				'third_party_settings' =>
					array (
					),
				'region' => 'content',
			),
	));
$config_comment->set('hidden' ,
	array (
		'created' => true,
		'field_market_segment' => true,
		'field_solution' => true,
		'field_thematic' => true,
		'sticky' => true,
		'uid' => true,
	));
$config_comment->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_comment->set('langcode' , 'en');
$config_comment->set('status' , true);
$config_comment->set('dependencies' ,
	array (
		'config' =>
			array (
				0 => 'core.entity_view_display.comment.comment_blog.default',
				1 => 'field.field.node.blog_post.field_blog_format',
				2 => 'field.field.node.blog_post.field_blog_thematic',
				3 => 'field.field.node.blog_post.field_comments',
				4 => 'field.field.node.blog_post.field_content',
				5 => 'field.field.node.blog_post.field_content_owner',
				6 => 'field.field.node.blog_post.field_display_title',
				7 => 'field.field.node.blog_post.field_email_owner',
				8 => 'field.field.node.blog_post.field_end_date',
				9 => 'field.field.node.blog_post.field_highlight',
				10 => 'field.field.node.blog_post.field_industry',
				11 => 'field.field.node.blog_post.field_insight',
				12 => 'field.field.node.blog_post.field_job_profile',
				13 => 'field.field.node.blog_post.field_market_segment',
				14 => 'field.field.node.blog_post.field_meta_description',
				15 => 'field.field.node.blog_post.field_meta_title',
				16 => 'field.field.node.blog_post.field_metatags',
				17 => 'field.field.node.blog_post.field_profile',
				18 => 'field.field.node.blog_post.field_region',
				19 => 'field.field.node.blog_post.field_solution',
				20 => 'field.field.node.blog_post.field_start_date',
				21 => 'field.field.node.blog_post.field_subhome',
				22 => 'field.field.node.blog_post.field_thematic',
				23 => 'field.field.node.blog_post.field_visual',
				24 => 'field.field.node.blog_post.publish_date',
				25 => 'field.field.node.blog_post.unpublish_date',
				26 => 'node.type.blog_post',
			),
		'module' =>
			array (
				0 => 'comment',
				1 => 'datetime',
				2 => 'metatag',
				3 => 'text',
				4 => 'user',
			),
	));
$config_comment->set('id' , 'node.blog_post.default');
$config_comment->set('targetEntityType' , 'node');
$config_comment->set('bundle' , 'blog_post');
$config_comment->set('mode' , 'default');
$config_comment->set('content' ,
	array (
		'field_comments' =>
			array (
				'weight' => 12,
				'label' => 'hidden',
				'settings' =>
					array (
						'view_mode' => 'default',
						'pager_id' => 0,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'comment_default',
				'region' => 'content',
			),
		'field_content' =>
			array (
				'weight' => 6,
				'label' => 'hidden',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'text_default',
				'region' => 'content',
			),
		'field_end_date' =>
			array (
				'weight' => 4,
				'label' => 'hidden',
				'settings' =>
					array (
						'format_type' => 'medium',
						'timezone_override' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'datetime_default',
				'region' => 'content',
			),
		'field_highlight' =>
			array (
				'weight' => 2,
				'label' => 'hidden',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'basic_string',
				'region' => 'content',
			),
		'field_industry' =>
			array (
				'weight' => 8,
				'label' => 'hidden',
				'settings' =>
					array (
						'link' => true,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'entity_reference_label',
				'region' => 'content',
			),
		'field_insight' =>
			array (
				'weight' => 11,
				'label' => 'hidden',
				'settings' =>
					array (
						'link' => true,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'entity_reference_label',
				'region' => 'content',
			),
		'field_metatags' =>
			array (
				'weight' => 7,
				'label' => 'hidden',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'metatag_empty_formatter',
				'region' => 'content',
			),
		'field_profile' =>
			array (
				'weight' => 10,
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
				'region' => 'content',
			),
		'field_solution' =>
			array (
				'weight' => 5,
				'label' => 'hidden',
				'settings' =>
					array (
						'link' => true,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'entity_reference_label',
				'region' => 'content',
			),
		'field_start_date' =>
			array (
				'weight' => 3,
				'label' => 'hidden',
				'settings' =>
					array (
						'format_type' => 'medium',
						'timezone_override' => '',
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'datetime_default',
				'region' => 'content',
			),
		'field_subhome' =>
			array (
				'weight' => 9,
				'label' => 'hidden',
				'settings' =>
					array (
						'link' => true,
					),
				'third_party_settings' =>
					array (
					),
				'type' => 'entity_reference_label',
				'region' => 'content',
			),
		'links' =>
			array (
				'weight' => 1,
				'region' => 'content',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
			),
		'workbench_moderation_control' =>
			array (
				'weight' => 0,
				'region' => 'content',
				'settings' =>
					array (
					),
				'third_party_settings' =>
					array (
					),
			),
	));
$config_comment->set('hidden' ,
	array (
		'field_blog_format' => true,
		'field_blog_thematic' => true,
		'field_content_owner' => true,
		'field_display_title' => true,
		'field_email_owner' => true,
		'field_job_profile' => true,
		'field_market_segment' => true,
		'field_meta_description' => true,
		'field_meta_title' => true,
		'field_region' => true,
		'field_thematic' => true,
		'field_visual' => true,
		'langcode' => true,
		'publish_date' => true,
		'unpublish_date' => true,
	));
$config_comment->save(TRUE);