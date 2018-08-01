<?php
use \Drupal\field\Entity\FieldConfig;
use \Drupal\paragraphs\Entity\ParagraphsType;

// création du bundle de paragraph
$paragraphStorage = ParagraphsType::load('paragraph_block_rebond');
if (empty($paragraphStorage)) {
	$paragraphType = ParagraphsType::create([
		'id' => 'paragraph_block_rebond',
		'label' => 'Paragraph block rebond',
	]);
	$paragraphType->save();
}


//STORAGE du champ description pour le paragraph
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('paragraph', 'field_description');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'paragraphs',
					),
			),
		'field_name' => 'field_description',
		'entity_type' => 'paragraph',
		'type' => 'string',
		'settings' =>
			array (
				'max_length' => 255,
				'is_ascii' => FALSE,
				'case_sensitive' => FALSE,
			),
		'module' => 'core',
		'locked' => false,
		'translatable' => TRUE,
		'cardinality' => 1,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => FALSE,
		'custom_storage' => FALSE,
	))->save();
}

/* INSTANCES DES CHAMPS POUR LE PARAGRAPHE */
//Title
$field = FieldConfig::loadByName('paragraph', 'paragraph_block_rebond', 'field_title');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_title',
		'entity_type' => 'paragraph',
		'bundle' => 'paragraph_block_rebond',
		'label' => 'Title',
		'required' => FALSE,
		'translatable' => false,
		'language' => 'en',
		'field_type' => 'string',
	);
	FieldConfig::create($config_array)->save();
}
//Link
$field = FieldConfig::loadByName('paragraph', 'paragraph_block_rebond', 'field_link_button');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_link_button',
		'entity_type' => 'paragraph',
		'bundle' => 'paragraph_block_rebond',
		'label' => 'Link Button',
		'required' => FALSE,
		'translatable' => false,
		'language' => 'en',
		'field_type' => 'link',
		'settings' =>
			array (
				'link_type' => 17,
				'title' => 2,
			),
	);
	FieldConfig::create($config_array)->save();
}
//Link
$field = \Drupal\field\Entity\FieldConfig::loadByName('paragraph', 'paragraph_block_rebond', 'field_description');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_description',
		'entity_type' => 'paragraph',
		'bundle' => 'paragraph_block_rebond',
		'label' => 'Description',
		'required' => FALSE,
		'translatable' => false,
		'language' => 'en',
		'field_type' => 'string',
		'settings' =>
			array (	),
	);
	FieldConfig::create($config_array)->save();
}


/*****************************************/
/************** PRODUCT ******************/
/*****************************************/

//STORAGE du champ paragraph Try and buy
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_try_and_buy');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'entity_reference_revisions',
						1 => 'node',
						2 => 'paragraphs',
					),
			),
		'field_name' => 'field_try_and_buy',
		'entity_type' => 'node',
		'type' => 'entity_reference_revisions',
		'settings' =>
			array (
				'target_type' => 'paragraph',
			),
		'module' => 'entity_reference_revisions',
		'locked' => false,
		'translatable' => TRUE,
		'cardinality' => 1,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => FALSE,
		'custom_storage' => FALSE,
	))->save();
}

//STORAGE du champ paragraph Test showroom
$field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_test_showroom');
if (empty($field_storage)) {
	\Drupal\field\Entity\FieldStorageConfig::create(array(
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'entity_reference_revisions',
						1 => 'node',
						2 => 'paragraphs',
					),
			),
		'field_name' => 'field_test_showroom',
		'entity_type' => 'node',
		'type' => 'entity_reference_revisions',
		'settings' =>
			array (
				'target_type' => 'paragraph',
			),
		'module' => 'entity_reference_revisions',
		'locked' => false,
		'translatable' => TRUE,
		'cardinality' => 1,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => FALSE,
		'custom_storage' => FALSE,
	))->save();
}


/* INSTANCES DES CHAMPS POUR LE PRODUCT */
//Try and buy
$field = FieldConfig::loadByName('node', 'paragraph_block_rebond', 'field_try_and_buy');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_try_and_buy',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Try and buy',
		'required' => FALSE,
		'translatable' => false,
		'language' => 'en',
		'field_type' => 'entity_reference_revisions',
		'settings' =>
			array(
				'handler' => 'default:paragraph',
				'handler_settings' =>
					array(
						'target_bundles' =>
							array(
								'paragraph_block_rebond' => 'paragraph_block_rebond',
							),
						'target_bundles_drag_drop' =>
							array(
								'paragraph_block_rebond' =>
									array(
										'enabled' => true,
										'weight' => 21,
									),
							),
					),
			),
	);
	FieldConfig::create($config_array)->save();
}
//Try and buy
$field = FieldConfig::loadByName('node', 'paragraph_block_rebond', 'field_test_showroom');
if (empty($field)) {
	$config_array = array(
		'field_name' => 'field_test_showroom',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Test Showroom',
		'required' => FALSE,
		'translatable' => false,
		'language' => 'en',
		'field_type' => 'entity_reference_revisions',
		'settings' =>
			array(
				'handler' => 'default:paragraph',
				'handler_settings' =>
					array(
						'target_bundles' =>
							array(
								'paragraph_block_rebond' => 'paragraph_block_rebond',
							),
						'target_bundles_drag_drop' =>
							array(
								'paragraph_block_rebond' =>
									array(
										'enabled' => true,
										'weight' => 21,
									),
							),
					),
			),
	);
	FieldConfig::create($config_array)->save();
}


// view display et form display du paragraph
oabt_YmlImport('core.entity_view_display.paragraph.paragraph_block_rebond.default.yml');
oabt_YmlImport('core.entity_form_display.paragraph.paragraph_block_rebond.default.yml');

// view display et form display du product
oabt_YmlImport('core.entity_view_display.node.product.default.yml');
oabt_YmlImport('core.entity_form_display.node.product.default.yml');
