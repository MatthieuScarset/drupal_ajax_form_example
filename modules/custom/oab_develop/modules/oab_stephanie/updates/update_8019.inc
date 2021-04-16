<?php

//On supprime d'abord les termes de taxonomies saisis manuellement
$vidsToClean = array('market_segments');

foreach ($vidsToClean as $vid) {
	$tids = \Drupal::entityQuery('taxonomy_term')
		->condition('vid', $vid)
		->execute();

	$controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
	$entities = $controller->loadMultiple($tids);
	$controller->delete($entities);
}

$terms = array(
	//Solutions FR
	array( 'vid' => 'market_segments', 'name' => 'Haut de marché', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => 'Milieu de marché', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => 'Bas de marché', 'language' => 'fr'),
	//Solutions EN
	array( 'vid' => 'market_segments', 'name' => 'MNC', 'language' => 'en'),

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
		$newTerm->save();
		drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
	}
}