<?php

//Creation du champ pour Twitter


$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_social_account');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'field_name' => 'field_social_account',
		'entity_type' => 'node',
		'type' => 'string',
	))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_social_account');
$config_group->setData(
	array (
		'uuid' => '95643518-ff7d-476f-97fc-83d80b835b1f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
					),
			),
		'id' => 'node.field_social_account',
		'field_name' => 'field_social_account',
		'entity_type' => 'node',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 255,
				'is_ascii' => false,
				'case_sensitive' => false,
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => 1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.profile.field_social_account');
$config_group->setData(
	array (
		'uuid' => 'ff1a34e0-7e7c-4313-83a9-727cc984db42',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_social_account',
						1 => 'node.type.profile',
					),
			),
		'id' => 'node.profile.field_social_account',
		'field_name' => 'field_social_account',
		'entity_type' => 'node',
		'bundle' => 'profile',
		'label' => 'Social account',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
			),
		'field_type' => 'string',
	)
);
$config_group->save(TRUE);



//Suppression des champs Job, Location, Link, Social accounts

//core.entity_form_display.node.profile.default
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.profile.default');
$config_group->setData(
	array (
		'uuid' => 'c035d2f6-80a4-44cb-b256-82d5eb2bd3b5',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.profile.body',
						2 => 'field.field.node.profile.field_first_name',
						3 => 'field.field.node.profile.field_last_name',
						4 => 'field.field.node.profile.field_metatags',
						5 => 'field.field.node.profile.field_social_account',
						6 => 'field.field.node.profile.field_visual',
						7 => 'node.type.profile',
					),
				'module' =>
					array (
						0 => 'entity_browser',
						1 => 'metatag',
						2 => 'path',
						3 => 'text',
						4 => 'workbench_moderation',
					),
			),
		'id' => 'node.profile.default',
		'targetEntityType' => 'node',
		'bundle' => 'profile',
		'mode' => 'default',
		'content' =>
			array (
				'body' =>
					array (
						'type' => 'text_textarea_with_summary',
						'weight' => 4,
						'settings' =>
							array (
								'rows' => 9,
								'summary_rows' => 3,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_first_name' =>
					array (
						'weight' => 27,
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string_textfield',
					),
				'field_last_name' =>
					array (
						'weight' => 1,
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string_textfield',
					),
				'field_metatags' =>
					array (
						'weight' => 11,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'metatag_firehose',
					),
				'field_social_account' =>
					array (
						'weight' => 28,
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string_textfield',
					),
				'field_visual' =>
					array (
						'weight' => 26,
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
						'type' => 'entity_browser_entity_reference',
					),
				'langcode' =>
					array (
						'type' => 'language_select',
						'weight' => 0,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'path' =>
					array (
						'type' => 'path',
						'weight' => 10,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'title' =>
					array (
						'type' => 'string_textfield',
						'weight' => 3,
						'settings' =>
							array (
								'size' => 60,
								'placeholder' => '',
							),
						'third_party_settings' =>
							array (
							),
					),
				'translation' =>
					array (
						'weight' => 12,
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
				'created' => true,
				'promote' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);



//core.entity_view_display.node.profile.default
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.default');
$config_group->setData(
	array (
		'uuid' => 'dc5a8a94-48f2-4c6b-9a9d-3a8df4b3ae9f',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.field.node.profile.body',
						1 => 'field.field.node.profile.field_first_name',
						2 => 'field.field.node.profile.field_last_name',
						3 => 'field.field.node.profile.field_metatags',
						4 => 'field.field.node.profile.field_social_account',
						5 => 'field.field.node.profile.field_visual',
						6 => 'node.type.profile',
					),
				'module' =>
					array (
						0 => 'metatag',
						1 => 'text',
						2 => 'user',
					),
			),
		'id' => 'node.profile.default',
		'targetEntityType' => 'node',
		'bundle' => 'profile',
		'mode' => 'default',
		'content' =>
			array (
				'body' =>
					array (
						'label' => 'hidden',
						'type' => 'text_default',
						'weight' => 101,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_first_name' =>
					array (
						'weight' => 111,
						'label' => 'above',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string',
					),
				'field_last_name' =>
					array (
						'weight' => 109,
						'label' => 'hidden',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string',
					),
				'field_metatags' =>
					array (
						'weight' => 106,
						'label' => 'hidden',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'metatag_empty_formatter',
					),
				'field_social_account' =>
					array (
						'weight' => 112,
						'label' => 'above',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string',
					),
				'field_visual' =>
					array (
						'weight' => 110,
						'label' => 'hidden',
						'settings' =>
							array (
								'link' => true,
								'view_mode' => 'default',
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'entity_reference_entity_view',
					),
				'links' =>
					array (
						'weight' => 100,
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
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);


//core.entity_view_display.node.profile.subhome
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.subhome');
$config_group->setData(
	array (
		'uuid' => 'bab46afa-7fe1-4e6f-9f8e-56e56c33bad9',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.subhome',
						1 => 'field.field.node.profile.body',
						2 => 'field.field.node.profile.field_first_name',
						3 => 'field.field.node.profile.field_last_name',
						4 => 'field.field.node.profile.field_metatags',
						5 => 'field.field.node.profile.field_social_account',
						6 => 'field.field.node.profile.field_visual',
						7 => 'node.type.profile',
					),
				'module' =>
					array (
						0 => 'user',
					),
			),
		'id' => 'node.profile.subhome',
		'targetEntityType' => 'node',
		'bundle' => 'profile',
		'mode' => 'subhome',
		'content' =>
			array (
				'field_first_name' =>
					array (
						'weight' => 1,
						'label' => 'hidden',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string',
					),
				'field_last_name' =>
					array (
						'weight' => 0,
						'label' => 'hidden',
						'settings' =>
							array (
								'link_to_entity' => false,
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'string',
					),
			),
		'hidden' =>
			array (
				'body' => true,
				'field_metatags' => true,
				'field_social_account' => true,
				'field_visual' => true,
				'langcode' => true,
				'links' => true,
			),
	)
);
$config_group->save(TRUE);


//core.entity_view_display.node.profile.teaser
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
						3 => 'field.field.node.profile.field_last_name',
						4 => 'field.field.node.profile.field_metatags',
						5 => 'field.field.node.profile.field_social_account',
						6 => 'field.field.node.profile.field_visual',
						7 => 'node.type.profile',
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
								'view_mode' => 'blogger_insert',
								'link' => false,
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
				'field_metatags' => true,
				'field_social_account' => true,
				'langcode' => true,
			),
	)
);
$config_group->save(TRUE);



$config_group = $config_factory->getEditable('field.field.node.profile.field_job');
$config_group->delete();


$config_group = $config_factory->getEditable('field.field.node.profile.field_link');
$config_group->delete();


$config_group = $config_factory->getEditable('field.field.node.profile.field_location');
$config_group->delete();


$config_group = $config_factory->getEditable('field.field.node.profile.field_social_accounts');
$config_group->delete();


$fields_to_delete = array('field_job', 'field_link', 'field_location', 'field_social_accounts');
foreach ($fields_to_delete as $field_to_delete)
{
	$field = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', $field_to_delete);
	$field->delete();
}

