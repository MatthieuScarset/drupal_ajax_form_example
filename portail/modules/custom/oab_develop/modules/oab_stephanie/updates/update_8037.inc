<?php

//vérification de l'existance du terme pour ce vocabulaire
$query = \Drupal::entityQuery('taxonomy_term');
$query->condition('vid', 'regions');
$query->condition('langcode', 'en');
$query->condition('name', 'Russia');
$entity = $query->execute();

if (!isset($entity) || empty($entity))
{
	//s'il n'existe pas on le crée
	$newTerm = \Drupal\taxonomy\Entity\Term::create([
		'vid' => 'regions',
		'name' => 'Russia',
		'langcode' => 'en',
	]);
	$newTerm->save();
	drupal_set_message("-- Le terme Russia (taxo regions) a été créé ", "status");
}
else{
	drupal_set_message("-- Le terme Russia (taxo regions) existe DEJA ", "status");
}