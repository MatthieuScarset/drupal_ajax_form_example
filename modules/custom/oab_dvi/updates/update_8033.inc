<?php

// Ajout du nouveaux vocabulaire :
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies['market_segments_dvi']) ) {
	$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
		'vid' => 'market_segments_dvi',
		'name' => 'Market segments DVI'
	));
	$vocabulary->save();
}


$terms = array(
	//Market Segment pour DVI
	array( 'vid' => 'market_segments_dvi', 'name' => 'secteur-public', 'language' => 'fr'),
	array( 'vid' => 'market_segments_dvi', 'name' => 'moins-50-salaries', 'language' => 'fr'),
	array( 'vid' => 'market_segments_dvi', 'name' => 'plus-50-salaries', 'language' => 'fr'),
	array( 'vid' => 'market_segments_dvi', 'name' => 'public-sector', 'language' => 'en'),
	array( 'vid' => 'market_segments_dvi', 'name' => 'less-50-employees', 'language' => 'en'),
	array( 'vid' => 'market_segments_dvi', 'name' => 'more-50-employees', 'language' => 'en'),
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
		drupal_set_message("-- term market segment DVI :  ".$term['name']." (".$term['language'].") créé ", "status");
	}
}