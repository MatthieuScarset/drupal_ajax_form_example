<?php
// Modification du vocabulaire région pour le rendre traductible

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.taxonomy_term.regions');
$config_group->setData(
	array (
		'uuid' => 'fa469b38-13bd-458e-965e-752c40204a9f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'taxonomy.vocabulary.regions',
					),
				'module' =>
					array (
						0 => 'content_translation',
					),
			),
		'third_party_settings' =>
			array (
				'content_translation' =>
					array (
						'enabled' => true,
					),
			),
		'id' => 'taxonomy_term.regions',
		'target_entity_type_id' => 'taxonomy_term',
		'target_bundle' => 'regions',
		'default_langcode' => 'site_default',
		'language_alterable' => false,
	)
);
$config_group->save(TRUE);

//Applique les modifications en bdd pour la traduction : ajout des colonnes necessaires
//\Drupal::entityDefinitionUpdateManager()->applyUpdates();


//On supprime d'abord les termes de taxonomies Solutions RU et RU-EN saisis manuellement
$languages = array('fr', 'en');

foreach ($languages as $langcode) {
	$tids = \Drupal::entityQuery('taxonomy_term')
		->condition('vid', 'regions')
		->condition('langcode', $langcode)
		->execute();

	$controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
	$entities = $controller->loadMultiple($tids);
	$controller->delete($entities);
}

$terms = array(
	//Zone géographique
	array( 'vid' => 'regions', 'name' => 'Africa', 'language' => 'en', 'nameFR' => 'Afrique'),
	array( 'vid' => 'regions', 'name' => 'Asia Pacific', 'language' => 'en', 'nameFR' => 'Asie Pacifique'),
	array( 'vid' => 'regions', 'name' => 'Europe', 'language' => 'en', 'nameFR' => 'Europe'),
	array( 'vid' => 'regions', 'name' => 'Latin America', 'language' => 'en', 'nameFR' => 'Amerique Latine'),
	array( 'vid' => 'regions', 'name' => 'Middle East', 'language' => 'en', 'nameFR' => 'Moyen Orient'),
	array( 'vid' => 'regions', 'name' => 'North America', 'language' => 'en', 'nameFR' => 'Amerique du Nord'),
	array( 'vid' => 'regions', 'name' => 'Russia', 'language' => 'en', 'nameFR' => 'Russie'),
);

foreach ($terms as $term)
{
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $term['vid']);
	$query->condition('langcode', $term['language']);
	$query->condition('name', $term['name']);
	$entity = $query->execute();

	if (!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		$newTerm = \Drupal\taxonomy\Entity\Term::create([
			'vid' => $term['vid'],
			'name' => $term['name'],
			'langcode' => $term['language'],
		]);
		//ajout traduction FR
		$newTerm->addTranslation('fr', [
			'name' => $term['nameFR'],
		]);
		$newTerm->save();
		drupal_set_message("-- ".$term['name']." créé ", "status");

	}
}