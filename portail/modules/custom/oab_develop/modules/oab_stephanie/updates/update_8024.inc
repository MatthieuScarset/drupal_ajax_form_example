<?php

//vérification de l'existance du terme puis suppression
$query = \Drupal::entityQuery('taxonomy_term');
$query->condition('vid', 'industries');
$query->condition('langcode', 'fr');
$query->condition('name', 'Secteur public');
$entity = $query->execute();

if (isset($entity) && !empty($entity) && count($entity) > 0) {
	$id = array_pop(array_values($entity));
	$controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
	$entity = $controller->load($id);
	$entity->delete();
	drupal_set_message("-- industrie Secteur public (FR) supprimée ", "status");
}


//vérification de l'existance du terme et création
$query = \Drupal::entityQuery('taxonomy_term');
$query->condition('vid', 'industries');
$query->condition('langcode', 'fr');
$query->condition('name', 'Gouvernement');
$entity = $query->execute();

if (!isset($entity) || empty($entity))
{
	//s'il n'existe pas on le crée
	$newTerm = \Drupal\taxonomy\Entity\Term::create([
		'vid' => 'industries',
		'name' => 'Gouvernement',
		'langcode' => 'fr',
	]);
	$newTerm->save();
	drupal_set_message("-- industrie Gouvernement (FR) créée ", "status");
}