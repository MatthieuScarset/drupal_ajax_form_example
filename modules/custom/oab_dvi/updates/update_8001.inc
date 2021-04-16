<?php

$terms = array(
	//Market Segment pour DVI
	array( 'vid' => 'market_segments', 'name' => 'Secteur Public', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => '- 50 salariés', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => '+ 50 salariés', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => '+ 250 salariés', 'language' => 'fr'),
	array( 'vid' => 'market_segments', 'name' => 'Public Sector', 'language' => 'en'),
	array( 'vid' => 'market_segments', 'name' => '- 50 employees', 'language' => 'en'),
	array( 'vid' => 'market_segments', 'name' => '+ 50 employees', 'language' => 'en'),
	array( 'vid' => 'market_segments', 'name' => '+ 250 employees', 'language' => 'en'),
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
		drupal_set_message("-- term market segment :  ".$term['name']." (".$term['language'].") créé ", "status");

	}
}