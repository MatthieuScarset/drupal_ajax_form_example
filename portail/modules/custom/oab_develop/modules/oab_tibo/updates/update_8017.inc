<?php

use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

function renameTaxo($old, $new, $vid, $lang) {
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $vid);
	$query->condition('langcode', $lang);
	$query->condition('name', $old);
	$entity = $query->execute();
	if (isset($entity)) {
		foreach ($entity as $tid => $value) {
			$tidRename = $tid;
		}
	}
	if (isset($tidRename)) {
		$connection = Database::getConnection();
		$query = $connection->update('taxonomy_term_field_data');
		$query->fields([
			'name' => $new,
		]);
		$query->condition('tid',$tidRename);
		$query->execute();
	}
}

// mise à jour des taxonomies existantes

/**
 * Solutions
 */
renameTaxo('Cyber défense', 'Cyberdefense', 'solutions', 'fr');
renameTaxo('IT flexible', 'IT Flexible', 'solutions', 'fr');

renameTaxo('Business innovation', 'Business Innovation', 'solutions', 'en');
renameTaxo('Collaborative workspace', 'Collaborative Workspace', 'solutions', 'en');
renameTaxo('Cyber defense', 'Cyber Defense', 'solutions', 'en');
renameTaxo('Enriched customer relationships', 'Enriched Customer relationships', 'solutions', 'en');
drupal_set_message("-- Taxonomies Solutions mises à jour", "status");

/**
 * Industries
 */
renameTaxo('Banque et Assurance', 'Banque et assurance', 'industries', 'fr');

drupal_set_message("-- Taxonomies Industries mises à jour", "status");

// création des nouvelles taxos

/**
 * Thèmes blog/magazine/mediatheque
 */
$vid_to_add = array(
	'blog_thematics' => 'Blog thematics',
	'blog_formats' => 'Blog formats',
	);
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
foreach ($vid_to_add as $vid => $name) {
	if (!isset($vocabularies[$vid]) ) {
		$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
			'vid' => $vid,
			'name' => $name
		));
		$vocabulary->save();
	}
}
$terms = array(
	array( 'vid' => 'blog_formats', 'name' => 'Experts', 'language' => 'fr'),
	array( 'vid' => 'blog_formats', 'name' => 'Actualités', 'language' => 'fr'),
	array( 'vid' => 'blog_formats', 'name' => 'Bonnes pratiques', 'language' => 'fr'),
	array( 'vid' => 'blog_formats', 'name' => 'Tendances', 'language' => 'fr'),
	array( 'vid' => 'blog_formats', 'name' => 'Analyses (études)', 'language' => 'fr'),
	array( 'vid' => 'blog_formats', 'name' => 'Témoignages', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Sécurité', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Cloud Computing', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Relation Client', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Big Data Analytics', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'IoT', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Collaboration', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Réseaux', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Consulting', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Mobilité ou Mobile', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Innovation', 'language' => 'fr'),
	array( 'vid' => 'blog_thematics', 'name' => 'Santé', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Blog book', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Brochure', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Catalogue', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Document', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'E-book', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Livre blanc', 'language' => 'fr'),
	array( 'vid' => 'document_types', 'name' => 'Magazine', 'language' => 'fr'),
);
foreach ($terms as $term) {
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $term['vid']);
	$query->condition('langcode', $term['language']);
	$query->condition('name', $term['name']);
	$entity = $query->execute();

	if (!isset($entity) || empty($entity)) {
		//s'il n'existe pas on le crée
		$newTerm = \Drupal\taxonomy\Entity\Term::create([
			'vid' => $term['vid'],
			'name' => $term['name'],
			'langcode' => $term['language'],
		]);
		$newTerm->save();
		drupal_set_message("-- ".$term['name']." créé ", "status");
	}
}

/**
 * création des champ field_blog_thematic et field_blog_format pour les taxonomies
 */
$field_storage = FieldStorageConfig::loadByName('node', 'field_blog_thematic');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_blog_thematic',
		'entity_type' => 'node',
		'type' => 'entity_reference',
	))->save();
}

$field = FieldConfig::loadByName('node', 'blog_post', 'field_blog_thematic');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_blog_thematic',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Blog thematic',
		'required' => FALSE,
	);
	FieldConfig::create($config_array)->save();
}

$field_storage = FieldStorageConfig::loadByName('node', 'field_blog_format');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_blog_format',
		'entity_type' => 'node',
		'type' => 'entity_reference',
	))->save();
}

$field = FieldConfig::loadByName('node', 'blog_post', 'field_blog_format');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_blog_format',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Blog format',
		'required' => FALSE,
	);
	FieldConfig::create($config_array)->save();
}

// storage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_blog_thematic');
$config_group->setData(
	array (
		'uuid' => '34230e52-d735-4c17-b335-529ea2a4ec27',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_blog_thematic',
		'field_name' => 'field_blog_thematic',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
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
$config_group = $config_factory->getEditable('field.storage.node.field_blog_format');
$config_group->setData(
	array (
		'uuid' => 'fa6980a4-4174-40d6-9699-ddf357063ba2',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
						1 => 'taxonomy',
					),
			),
		'id' => 'node.field_blog_format',
		'field_name' => 'field_blog_format',
		'entity_type' => 'node',
		'type' => 'entity_reference',
		'settings' =>
			array (
				'target_type' => 'taxonomy_term',
			),
		'module' => 'core',
		'locked' => false,
		'cardinality' => -1,
		'translatable' => true,
		'indexes' =>
			array (
			),
		'persist_with_no_fields' => false,
		'custom_storage' => false,
	)
);
$config_group->save(TRUE);

// fields
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_blog_thematic');
$config_group->setData(
	array (
		'uuid' => '23990e3f-ae0c-4547-9f4a-f443f71ebfdc',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_blog_thematic',
						1 => 'node.type.blog_post',
						2 => 'taxonomy.vocabulary.blog_thematics',
					),
			),
		'id' => 'node.blog_post.field_blog_thematic',
		'field_name' => 'field_blog_thematic',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Blog thematic',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'blog_thematics' => 'blog_thematics',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.magazine.field_blog_thematic');
$config_group->setData(
	array (
		'uuid' => '248aa275-1792-48bd-b295-29ee08b23f43',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_blog_thematic',
						1 => 'node.type.magazine',
						2 => 'taxonomy.vocabulary.blog_thematics',
					),
			),
		'id' => 'node.magazine.field_blog_thematic',
		'field_name' => 'field_blog_thematic',
		'entity_type' => 'node',
		'bundle' => 'magazine',
		'label' => 'Magazine thematic',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'blog_thematics' => 'blog_thematics',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.document.field_blog_thematic');
$config_group->setData(
	array (
		'uuid' => '3347a7a9-cd1f-40f7-a824-f423d8b448e0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_blog_thematic',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.blog_thematics',
					),
			),
		'id' => 'node.document.field_blog_thematic',
		'field_name' => 'field_blog_thematic',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Document thematic',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'blog_thematics' => 'blog_thematics',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.blog_post.field_blog_format');
$config_group->setData(
	array (
		'uuid' => '7d5218e0-d512-447c-ad41-522ef5449f30',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_blog_format',
						1 => 'node.type.blog_post',
						2 => 'taxonomy.vocabulary.blog_formats',
					),
			),
		'id' => 'node.blog_post.field_blog_format',
		'field_name' => 'field_blog_format',
		'entity_type' => 'node',
		'bundle' => 'blog_post',
		'label' => 'Blog format',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'blog_formats' => 'blog_formats',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.magazine.field_blog_format');
$config_group->setData(
	array (
		'uuid' => '8f8e12db-81cd-475a-8506-4ad47dbc8f66',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_blog_format',
						1 => 'node.type.magazine',
						2 => 'taxonomy.vocabulary.blog_formats',
					),
			),
		'id' => 'node.magazine.field_blog_format',
		'field_name' => 'field_blog_format',
		'entity_type' => 'node',
		'bundle' => 'magazine',
		'label' => 'Magazine format',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'blog_formats' => 'blog_formats',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.document.field_document_type');
$config_group->setData(
	array (
		'uuid' => '9a8e1e34-dff7-48e1-8300-3a2ca11d9290',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_document_type',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.document_types',
					),
			),
		'id' => 'node.document.field_document_type',
		'field_name' => 'field_document_type',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Document type',
		'description' => '',
		'required' => true,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'document_types' => 'document_types',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.document.field_job_profile');
$config_group->setData(
	array (
		'uuid' => '2a0d1aae-5486-42a2-9006-6736002a3168',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.field_job_profile',
						1 => 'node.type.document',
						2 => 'taxonomy.vocabulary.jobs_profiles',
					),
			),
		'id' => 'node.document.field_job_profile',
		'field_name' => 'field_job_profile',
		'entity_type' => 'node',
		'bundle' => 'document',
		'label' => 'Job profile',
		'description' => '',
		'required' => false,
		'translatable' => true,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'handler' => 'default:taxonomy_term',
				'handler_settings' =>
					array (
						'target_bundles' =>
							array (
								'jobs_profiles' => 'jobs_profiles',
							),
						'sort' =>
							array (
								'field' => '_none',
							),
						'auto_create' => false,
						'auto_create_bundle' => '',
					),
			),
		'field_type' => 'entity_reference',
	)
);
$config_group->save(TRUE);

// form display
$config_group = $config_factory->getEditable('core.entity_form_display.node.blog_post.default');
$config_group->setData(
	array (
		'uuid' => '7783f827-dedc-4463-b4b9-3a3cf835ef89',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.blog_post.field_blog_format',
						2 => 'field.field.node.blog_post.field_blog_thematic',
						3 => 'field.field.node.blog_post.field_content',
						4 => 'field.field.node.blog_post.field_content_owner',
						5 => 'field.field.node.blog_post.field_display_title',
						6 => 'field.field.node.blog_post.field_email_owner',
						7 => 'field.field.node.blog_post.field_end_date',
						8 => 'field.field.node.blog_post.field_highlight',
						9 => 'field.field.node.blog_post.field_industry',
						10 => 'field.field.node.blog_post.field_job_profile',
						11 => 'field.field.node.blog_post.field_market_segment',
						12 => 'field.field.node.blog_post.field_meta_description',
						13 => 'field.field.node.blog_post.field_meta_title',
						14 => 'field.field.node.blog_post.field_metatags',
						15 => 'field.field.node.blog_post.field_profile',
						16 => 'field.field.node.blog_post.field_region',
						17 => 'field.field.node.blog_post.field_solution',
						18 => 'field.field.node.blog_post.field_start_date',
						19 => 'field.field.node.blog_post.field_subhome',
						20 => 'field.field.node.blog_post.field_thematic',
						21 => 'field.field.node.blog_post.field_visual',
						22 => 'field.field.node.blog_post.publish_date',
						23 => 'field.field.node.blog_post.unpublish_date',
						24 => 'node.type.blog_post',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
						3 => 'inline_entity_form',
						4 => 'metatag',
						5 => 'path',
						6 => 'text',
						7 => 'workbench_moderation',
					),
			),
		'third_party_settings' =>
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
								'weight' => 2,
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
										1 => 'field_solution',
										2 => 'field_industry',
										3 => 'field_region',
										4 => 'field_market_segment',
										5 => 'field_job_profile',
										6 => 'field_thematic',
										7 => 'field_blog_thematic',
										8 => 'field_blog_format',
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
			),
		'id' => 'node.blog_post.default',
		'targetEntityType' => 'node',
		'bundle' => 'blog_post',
		'mode' => 'default',
		'content' =>
			array (
				'field_blog_format' =>
					array (
						'type' => 'options_select',
						'weight' => 34,
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
						'weight' => 33,
						'region' => 'content',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
				'field_job_profile' =>
					array (
						'weight' => 31,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_market_segment' =>
					array (
						'weight' => 30,
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
				'field_solution' =>
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
				'field_thematic' =>
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
			),
		'hidden' =>
			array (
				'created' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_form_display.node.magazine.default');
$config_group->setData(
	array (
		'uuid' => '16d663a1-82ed-4352-aa5e-4a1be3ab230a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.magazine.field_blog_format',
						2 => 'field.field.node.magazine.field_blog_thematic',
						3 => 'field.field.node.magazine.field_content',
						4 => 'field.field.node.magazine.field_content_owner',
						5 => 'field.field.node.magazine.field_display_title',
						6 => 'field.field.node.magazine.field_email_owner',
						7 => 'field.field.node.magazine.field_end_date',
						8 => 'field.field.node.magazine.field_highlight',
						9 => 'field.field.node.magazine.field_industry',
						10 => 'field.field.node.magazine.field_job_profile',
						11 => 'field.field.node.magazine.field_market_segment',
						12 => 'field.field.node.magazine.field_meta_description',
						13 => 'field.field.node.magazine.field_meta_title',
						14 => 'field.field.node.magazine.field_metatags',
						15 => 'field.field.node.magazine.field_region',
						16 => 'field.field.node.magazine.field_solution',
						17 => 'field.field.node.magazine.field_start_date',
						18 => 'field.field.node.magazine.field_subhome',
						19 => 'field.field.node.magazine.field_thematic',
						20 => 'field.field.node.magazine.field_visual',
						21 => 'node.type.magazine',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
						3 => 'metatag',
						4 => 'path',
						5 => 'text',
						6 => 'workbench_moderation',
					),
			),
		'third_party_settings' =>
			array (
				'field_group' =>
					array (
						'group_write' =>
							array (
								'children' =>
									array (
										0 => 'langcode',
										1 => 'title',
										2 => 'field_display_title',
										3 => 'field_highlight',
										4 => 'field_content',
										5 => 'field_visual',
									),
								'parent_name' => 'group_onglets',
								'weight' => 8,
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
										1 => 'field_solution',
										2 => 'field_industry',
										3 => 'field_market_segment',
										4 => 'field_job_profile',
										5 => 'field_region',
										6 => 'field_thematic',
										7 => 'field_blog_thematic',
										8 => 'field_blog_format',
									),
								'parent_name' => 'group_onglets',
								'weight' => 9,
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
										3 => 'promote',
										4 => 'path',
										5 => 'field_metatags',
									),
								'parent_name' => 'group_onglets',
								'weight' => 11,
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
								'weight' => 6,
								'format_type' => 'tabs',
								'format_settings' =>
									array (
										'id' => '',
										'classes' => '',
										'direction' => 'vertical',
									),
								'label' => 'Onglets',
							),
						'group_content_worthy_period' =>
							array (
								'children' =>
									array (
										0 => 'field_start_date',
										1 => 'field_end_date',
									),
								'parent_name' => 'group_publish',
								'weight' => 19,
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
						'group_seo' =>
							array (
								'children' =>
									array (
										0 => 'field_meta_title',
										1 => 'field_meta_description',
									),
								'parent_name' => 'group_onglets',
								'weight' => 10,
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
			),
		'id' => 'node.magazine.default',
		'targetEntityType' => 'node',
		'bundle' => 'magazine',
		'mode' => 'default',
		'content' =>
			array (
				'field_blog_format' =>
					array (
						'type' => 'options_select',
						'weight' => 34,
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
						'weight' => 33,
						'region' => 'content',
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
					),
				'field_content' =>
					array (
						'weight' => 7,
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
						'weight' => 17,
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
						'weight' => 18,
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
				'field_job_profile' =>
					array (
						'type' => 'options_select',
						'weight' => 30,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'field_market_segment' =>
					array (
						'type' => 'options_select',
						'weight' => 29,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
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
						'weight' => 22,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'metatag_firehose',
						'region' => 'content',
					),
				'field_partner' =>
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
				'field_region' =>
					array (
						'type' => 'options_select',
						'weight' => 31,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
					),
				'field_solution' =>
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
				'field_start_date' =>
					array (
						'weight' => 13,
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
				'field_thematic' =>
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
				'field_visual' =>
					array (
						'weight' => 8,
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
						'weight' => 21,
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
						'weight' => 20,
						'settings' =>
							array (
								'display_label' => true,
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
			),
		'hidden' =>
			array (
				'created' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_form_display.node.document.default');
$config_group->setData(
	array (
		'uuid' => '7ab655ee-4a3b-4eaf-b035-2bf9eb907aa6',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'entity_browser.browser.browse_media_modal',
						1 => 'field.field.node.document.field_blog_thematic',
						2 => 'field.field.node.document.field_content',
						3 => 'field.field.node.document.field_content_owner',
						4 => 'field.field.node.document.field_display_title',
						5 => 'field.field.node.document.field_document_type',
						6 => 'field.field.node.document.field_email_owner',
						7 => 'field.field.node.document.field_end_date',
						8 => 'field.field.node.document.field_file',
						9 => 'field.field.node.document.field_highlight',
						10 => 'field.field.node.document.field_industry',
						11 => 'field.field.node.document.field_job_profile',
						12 => 'field.field.node.document.field_market_segment',
						13 => 'field.field.node.document.field_meta_description',
						14 => 'field.field.node.document.field_meta_title',
						15 => 'field.field.node.document.field_metatags',
						16 => 'field.field.node.document.field_region',
						17 => 'field.field.node.document.field_solution',
						18 => 'field.field.node.document.field_start_date',
						19 => 'field.field.node.document.field_subhome',
						20 => 'field.field.node.document.field_thematic',
						21 => 'field.field.node.document.field_visual',
						22 => 'node.type.document',
					),
				'module' =>
					array (
						0 => 'datetime',
						1 => 'entity_browser',
						2 => 'field_group',
						3 => 'metatag',
						4 => 'path',
						5 => 'text',
						6 => 'workbench_moderation',
					),
			),
		'third_party_settings' =>
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
								'weight' => 20,
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
										4 => 'field_visual',
										5 => 'field_file',
										6 => 'field_content',
									),
								'parent_name' => 'group_onglets',
								'weight' => 20,
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
										1 => 'field_document_type',
										2 => 'field_industry',
										3 => 'field_solution',
										4 => 'field_region',
										5 => 'field_job_profile',
										6 => 'field_market_segment',
										7 => 'field_thematic',
										8 => 'field_blog_thematic',
									),
								'parent_name' => 'group_onglets',
								'weight' => 21,
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
										3 => 'promote',
										4 => 'path',
										5 => 'field_metatags',
									),
								'parent_name' => 'group_onglets',
								'weight' => 23,
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
								'weight' => 48,
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
						'group_seo' =>
							array (
								'children' =>
									array (
										0 => 'field_meta_title',
										1 => 'field_meta_description',
									),
								'parent_name' => 'group_onglets',
								'weight' => 22,
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
			),
		'id' => 'node.document.default',
		'targetEntityType' => 'node',
		'bundle' => 'document',
		'mode' => 'default',
		'content' =>
			array (
				'field_blog_thematic' =>
					array (
						'weight' => 59,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_content' =>
					array (
						'weight' => 10,
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
						'weight' => 46,
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
						'weight' => 4,
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
				'field_document_type' =>
					array (
						'weight' => 52,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_email_owner' =>
					array (
						'weight' => 47,
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
						'weight' => 34,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'datetime_default',
						'region' => 'content',
					),
				'field_file' =>
					array (
						'weight' => 9,
						'settings' =>
							array (
								'entity_browser' => 'browser_file_modal',
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
						'region' => 'content',
					),
				'field_highlight' =>
					array (
						'weight' => 6,
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
						'weight' => 53,
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
						'weight' => 56,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_market_segment' =>
					array (
						'weight' => 57,
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
						'weight' => 6,
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
						'weight' => 5,
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
						'weight' => 51,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'metatag_firehose',
						'region' => 'content',
					),
				'field_region' =>
					array (
						'weight' => 55,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_solution' =>
					array (
						'weight' => 54,
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
						'weight' => 33,
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
						'weight' => 51,
						'settings' =>
							array (
							),
						'third_party_settings' =>
							array (
							),
						'type' => 'options_select',
						'region' => 'content',
					),
				'field_thematic' =>
					array (
						'weight' => 58,
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
						'weight' => 8,
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
						'region' => 'content',
					),
				'langcode' =>
					array (
						'type' => 'language_select',
						'weight' => 2,
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
						'weight' => 50,
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
						'weight' => 49,
						'settings' =>
							array (
								'display_label' => true,
							),
						'third_party_settings' =>
							array (
							),
						'region' => 'content',
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
						'region' => 'content',
					),
			),
		'hidden' =>
			array (
				'created' => true,
				'sticky' => true,
				'uid' => true,
			),
	)
);
$config_group->save(TRUE);

// vue des subhomes
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.subhomes');
$config_group->setData(
	array (
		'uuid' => 'ba0eb672-ee75-40c7-bf72-6c3567bb64a6',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'core.entity_view_mode.node.subhome',
						1 => 'node.type.press_kit',
						2 => 'node.type.press_release',
						3 => 'taxonomy.vocabulary.blog_thematics',
						4 => 'taxonomy.vocabulary.document_types',
						5 => 'taxonomy.vocabulary.industries',
						6 => 'taxonomy.vocabulary.jobs_profiles',
						7 => 'taxonomy.vocabulary.market_segments',
						8 => 'taxonomy.vocabulary.partner_types',
						9 => 'taxonomy.vocabulary.regions',
						10 => 'taxonomy.vocabulary.solutions',
					),
				'module' =>
					array (
						0 => 'node',
						1 => 'oab_backoffice',
						2 => 'taxonomy',
						3 => 'user',
						4 => 'views_infinite_scroll',
					),
			),
		'id' => 'subhomes',
		'label' => 'subhomes',
		'module' => 'views',
		'description' => '',
		'tag' => '',
		'base_table' => 'node_field_data',
		'base_field' => 'nid',
		'core' => '8.x',
		'display' =>
			array (
				'default' =>
					array (
						'display_plugin' => 'default',
						'id' => 'default',
						'display_title' => 'Master',
						'position' => 0,
						'display_options' =>
							array (
								'access' =>
									array (
										'type' => 'perm',
										'options' =>
											array (
												'perm' => 'access content',
											),
									),
								'cache' =>
									array (
										'type' => 'tag',
										'options' =>
											array (
											),
									),
								'query' =>
									array (
										'type' => 'views_query',
										'options' =>
											array (
												'disable_sql_rewrite' => false,
												'distinct' => false,
												'replica' => false,
												'query_comment' => '',
												'query_tags' =>
													array (
													),
											),
									),
								'exposed_form' =>
									array (
										'type' => 'basic',
										'options' =>
											array (
												'submit_button' => 'Apply',
												'reset_button' => false,
												'reset_button_label' => 'Reset',
												'exposed_sorts_label' => 'Sort by',
												'expose_sort_order' => true,
												'sort_asc_label' => 'Asc',
												'sort_desc_label' => 'Desc',
											),
									),
								'pager' =>
									array (
										'type' => 'infinite_scroll',
										'options' =>
											array (
												'items_per_page' => 12,
												'offset' => 0,
												'id' => 0,
												'total_pages' => NULL,
												'tags' =>
													array (
														'previous' => '‹ Previous',
														'next' => 'Next ›',
													),
												'expose' =>
													array (
														'items_per_page' => false,
														'items_per_page_label' => 'Items per page',
														'items_per_page_options' => '5, 10, 25, 50',
														'items_per_page_options_all' => false,
														'items_per_page_options_all_label' => '- All -',
														'offset' => false,
														'offset_label' => 'Offset',
													),
												'views_infinite_scroll' =>
													array (
														'button_text' => 'Load More',
														'automatically_load_content' => false,
													),
											),
									),
								'style' =>
									array (
										'type' => 'grid',
										'options' =>
											array (
												'uses_fields' => false,
												'columns' => 4,
												'automatic_width' => true,
												'alignment' => 'horizontal',
												'col_class_default' => true,
												'col_class_custom' => '',
												'row_class_default' => true,
												'row_class_custom' => '',
											),
									),
								'row' =>
									array (
										'type' => 'entity:node',
										'options' =>
											array (
												'relationship' => 'none',
												'view_mode' => 'subhome',
											),
									),
								'fields' =>
									array (
										'title' =>
											array (
												'id' => 'title',
												'table' => 'node_field_data',
												'field' => 'title',
												'entity_type' => 'node',
												'entity_field' => 'title',
												'label' => '',
												'alter' =>
													array (
														'alter_text' => false,
														'make_link' => false,
														'absolute' => false,
														'trim' => false,
														'word_boundary' => false,
														'ellipsis' => false,
														'strip_tags' => false,
														'html' => false,
													),
												'hide_empty' => false,
												'empty_zero' => false,
												'settings' =>
													array (
														'link_to_entity' => true,
													),
												'plugin_id' => 'field',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'exclude' => false,
												'element_type' => '',
												'element_class' => '',
												'element_label_type' => '',
												'element_label_class' => '',
												'element_label_colon' => true,
												'element_wrapper_type' => '',
												'element_wrapper_class' => '',
												'element_default_classes' => true,
												'empty' => '',
												'hide_alter_empty' => true,
												'click_sort_column' => 'value',
												'type' => 'string',
												'group_column' => 'value',
												'group_columns' =>
													array (
													),
												'group_rows' => true,
												'delta_limit' => 0,
												'delta_offset' => 0,
												'delta_reversed' => false,
												'delta_first_last' => false,
												'multi_type' => 'separator',
												'separator' => ', ',
												'field_api_classes' => false,
											),
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'field_solution_target_id' =>
											array (
												'id' => 'field_solution_target_id',
												'table' => 'node__field_solution',
												'field' => 'field_solution_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_solution_target_id_op',
														'label' => 'Solution',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_solution_target_id_op',
														'identifier' => 'field_solution_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'solutions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
									),
								'sorts' =>
									array (
										'created' =>
											array (
												'id' => 'created',
												'table' => 'node_field_data',
												'field' => 'created',
												'order' => 'DESC',
												'entity_type' => 'node',
												'entity_field' => 'created',
												'plugin_id' => 'date',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'exposed' => false,
												'expose' =>
													array (
														'label' => '',
													),
												'granularity' => 'second',
											),
									),
								'title' => 'Press',
								'header' =>
									array (
									),
								'footer' =>
									array (
									),
								'empty' =>
									array (
									),
								'relationships' =>
									array (
									),
								'arguments' =>
									array (
									),
								'display_extenders' =>
									array (
									),
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
					),
				'page_blog' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_blog',
						'display_title' => 'blogs',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_blogs',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'blog_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_blog_thematic_target_id' =>
											array (
												'id' => 'field_blog_thematic_target_id',
												'table' => 'node__field_blog_thematic',
												'field' => 'field_blog_thematic_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_blog_thematic_target_id_op',
														'label' => 'By thematic',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_blog_thematic_target_id_op',
														'identifier' => 'field_blog_thematic_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'blog_thematics',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Blog',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
					),
				'page_catalogue' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_catalogue',
						'display_title' => 'products',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_catalogue',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'product_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_solution_target_id' =>
											array (
												'id' => 'field_solution_target_id',
												'table' => 'node__field_solution',
												'field' => 'field_solution_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_solution_target_id_op',
														'label' => 'By solution',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_solution_target_id_op',
														'identifier' => 'field_solution_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'solutions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'field_industry_target_id' =>
											array (
												'id' => 'field_industry_target_id',
												'table' => 'node__field_industry',
												'field' => 'field_industry_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_industry_target_id_op',
														'label' => 'By industry',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_industry_target_id_op',
														'identifier' => 'field_industry_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'industries',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid' =>
											array (
												'id' => 'tid',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_op',
														'label' => 'By job profile',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_op',
														'identifier' => 'field_jobs_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'jobs_profiles',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid_1' =>
											array (
												'id' => 'tid_1',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_1_op',
														'label' => 'By market segment',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_1_op',
														'identifier' => 'field_market_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'market_segments',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Catalogue',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Products',
					),
				'page_customer' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_customer',
						'display_title' => 'customer stories',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_customers',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'customer_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_solution_target_id' =>
											array (
												'id' => 'field_solution_target_id',
												'table' => 'node__field_solution',
												'field' => 'field_solution_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_solution_target_id_op',
														'label' => 'By solution',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_solution_target_id_op',
														'identifier' => 'field_solution_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'solutions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'field_industry_target_id' =>
											array (
												'id' => 'field_industry_target_id',
												'table' => 'node__field_industry',
												'field' => 'field_industry_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_industry_target_id_op',
														'label' => 'By industry',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_industry_target_id_op',
														'identifier' => 'field_industry_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'industries',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid' =>
											array (
												'id' => 'tid',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_op',
														'label' => 'By job profile',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_op',
														'identifier' => 'field_jobs_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'jobs_profiles',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Customers',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Case study',
					),
				'page_document' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_document',
						'display_title' => 'documents',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_documents',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'library_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_blog_thematic_target_id' =>
											array (
												'id' => 'field_blog_thematic_target_id',
												'table' => 'node__field_blog_thematic',
												'field' => 'field_blog_thematic_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_blog_thematic_target_id_op',
														'label' => 'By thematic',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_blog_thematic_target_id_op',
														'identifier' => 'field_blog_thematic_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'blog_thematics',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'field_document_type_target_id' =>
											array (
												'id' => 'field_document_type_target_id',
												'table' => 'node__field_document_type',
												'field' => 'field_document_type_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_document_type_target_id_op',
														'label' => 'By type',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_document_type_target_id_op',
														'identifier' => 'field_document_type_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'document_types',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid' =>
											array (
												'id' => 'tid',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_op',
														'label' => 'By job profile',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_op',
														'identifier' => 'field_jobs_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'jobs_profiles',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'field_industry_target_id' =>
											array (
												'id' => 'field_industry_target_id',
												'table' => 'node__field_industry',
												'field' => 'field_industry_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_industry_target_id_op',
														'label' => 'By industry',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_industry_target_id_op',
														'identifier' => 'field_industry_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'industries',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Documents',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Library',
					),
				'page_magazine' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_magazine',
						'display_title' => 'magazine',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_magazine',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'magazine_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_blog_thematic_target_id' =>
											array (
												'id' => 'field_blog_thematic_target_id',
												'table' => 'node__field_blog_thematic',
												'field' => 'field_blog_thematic_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_blog_thematic_target_id_op',
														'label' => 'By thematic',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_blog_thematic_target_id_op',
														'identifier' => 'field_blog_thematic_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'blog_thematics',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Magazine',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Magazine',
					),
				'page_partners' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_partners',
						'display_title' => 'partners',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_partners',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'partner_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'title' => false,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'field_solution_target_id' =>
											array (
												'id' => 'field_solution_target_id',
												'table' => 'node__field_solution',
												'field' => 'field_solution_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_solution_target_id_op',
														'label' => 'By solution',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_solution_target_id_op',
														'identifier' => 'field_solution_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'solutions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid' =>
											array (
												'id' => 'tid',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_op',
														'label' => 'By type',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_op',
														'identifier' => 'field_types_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'partner_types',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'tid_1' =>
											array (
												'id' => 'tid_1',
												'table' => 'taxonomy_index',
												'field' => 'tid',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'tid_1_op',
														'label' => 'By region',
														'description' => '',
														'use_operator' => false,
														'operator' => 'tid_1_op',
														'identifier' => 'field_regions_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'regions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'title' => 'Partners',
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Partners',
					),
				'page_press' =>
					array (
						'display_plugin' => 'page',
						'id' => 'page_press',
						'display_title' => 'press',
						'position' => 1,
						'display_options' =>
							array (
								'display_extenders' =>
									array (
									),
								'path' => 'subhome_press',
								'display_description' => '',
								'arguments' =>
									array (
										'field_subhome_target_id' =>
											array (
												'id' => 'field_subhome_target_id',
												'table' => 'node__field_subhome',
												'field' => 'field_subhome_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'default_action' => 'default',
												'exception' =>
													array (
														'value' => 'all',
														'title_enable' => false,
														'title' => 'All',
													),
												'title_enable' => false,
												'title' => '',
												'default_argument_type' => 'config_key',
												'default_argument_options' =>
													array (
														'config_name' => 'oab_subhomes.subhomes',
														'config_key' => 'press_term_tid',
													),
												'default_argument_skip_url' => false,
												'summary_options' =>
													array (
														'base_path' => '',
														'count' => true,
														'items_per_page' => 25,
														'override' => false,
													),
												'summary' =>
													array (
														'sort_order' => 'asc',
														'number_of_records' => 0,
														'format' => 'default_summary',
													),
												'specify_validation' => false,
												'validate' =>
													array (
														'type' => 'none',
														'fail' => 'not found',
													),
												'validate_options' =>
													array (
													),
												'break_phrase' => false,
												'not' => false,
												'plugin_id' => 'numeric',
											),
									),
								'defaults' =>
									array (
										'arguments' => false,
										'filters' => false,
										'filter_groups' => false,
										'pager' => true,
										'use_ajax' => false,
										'style' => true,
										'row' => true,
									),
								'filters' =>
									array (
										'status' =>
											array (
												'value' => '1',
												'table' => 'node_field_data',
												'field' => 'status',
												'plugin_id' => 'boolean',
												'entity_type' => 'node',
												'entity_field' => 'status',
												'id' => 'status',
												'expose' =>
													array (
														'operator' => '',
													),
												'group' => 1,
											),
										'langcode' =>
											array (
												'id' => 'langcode',
												'table' => 'node',
												'field' => 'langcode',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'***LANGUAGE_language_interface***' => '***LANGUAGE_language_interface***',
													),
												'group' => 1,
												'exposed' => false,
												'expose' =>
													array (
														'operator_id' => '',
														'label' => '',
														'description' => '',
														'use_operator' => false,
														'operator' => '',
														'identifier' => '',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'langcode',
												'plugin_id' => 'language',
											),
										'type' =>
											array (
												'id' => 'type',
												'table' => 'node_field_data',
												'field' => 'type',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'in',
												'value' =>
													array (
														'press_kit' => 'press_kit',
														'press_release' => 'press_release',
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'type_op',
														'label' => 'By type',
														'description' => '',
														'use_operator' => false,
														'operator' => 'type_op',
														'identifier' => 'field_type_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => true,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'entity_field' => 'type',
												'plugin_id' => 'bundle',
											),
										'field_solution_target_id' =>
											array (
												'id' => 'field_solution_target_id',
												'table' => 'node__field_solution',
												'field' => 'field_solution_target_id',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => 'or',
												'value' =>
													array (
													),
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'field_solution_target_id_op',
														'label' => 'By solution',
														'description' => '',
														'use_operator' => false,
														'operator' => 'field_solution_target_id_op',
														'identifier' => 'field_solution_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
														'reduce' => false,
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'reduce_duplicates' => false,
												'type' => 'select',
												'limit' => true,
												'vid' => 'solutions',
												'hierarchy' => false,
												'error_message' => true,
												'plugin_id' => 'taxonomy_index_tid',
											),
										'node_year' =>
											array (
												'id' => 'node_year',
												'table' => 'node_field_data',
												'field' => 'node_year',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => '=',
												'value' => '0',
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'node_year_op',
														'label' => 'By year',
														'description' => '',
														'use_operator' => false,
														'operator' => 'node_year_op',
														'identifier' => 'field_year_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'plugin_id' => 'node_year',
											),
										'node_month' =>
											array (
												'id' => 'node_month',
												'table' => 'node_field_data',
												'field' => 'node_month',
												'relationship' => 'none',
												'group_type' => 'group',
												'admin_label' => '',
												'operator' => '=',
												'value' => '01',
												'group' => 1,
												'exposed' => true,
												'expose' =>
													array (
														'operator_id' => 'node_month_op',
														'label' => 'By month',
														'description' => '',
														'use_operator' => false,
														'operator' => 'node_month_op',
														'identifier' => 'field_month_target_id',
														'required' => false,
														'remember' => false,
														'multiple' => false,
														'remember_roles' =>
															array (
																'authenticated' => 'authenticated',
																'anonymous' => '0',
																'administrator' => '0',
																'chief_editor' => '0',
																'digital_admin' => '0',
																'webform_manager' => '0',
																'contributor' => '0',
															),
													),
												'is_grouped' => false,
												'group_info' =>
													array (
														'label' => '',
														'description' => '',
														'identifier' => '',
														'optional' => true,
														'widget' => 'select',
														'multiple' => false,
														'remember' => false,
														'default_group' => 'All',
														'default_group_multiple' =>
															array (
															),
														'group_items' =>
															array (
															),
													),
												'entity_type' => 'node',
												'plugin_id' => 'node_month',
											),
									),
								'filter_groups' =>
									array (
										'operator' => 'AND',
										'groups' =>
											array (
												1 => 'AND',
											),
									),
								'use_ajax' => true,
							),
						'cache_metadata' =>
							array (
								'max-age' => -1,
								'contexts' =>
									array (
										0 => 'languages:language_content',
										1 => 'languages:language_interface',
										2 => 'url',
										3 => 'url.query_args',
										4 => 'user',
										5 => 'user.node_grants:view',
										6 => 'user.permissions',
									),
								'tags' =>
									array (
									),
							),
						'title' => 'Press',
					),
			),
	)
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();