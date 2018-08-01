<?php
/* Nouveau vocabulaire Thématique*/
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
	if (!isset($vocabularies['thematic'])) {
		$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
			'vid' => 'thematic',
			'name' => 'Thematic'
		));
		$vocabulary->save();
	}

$connection = \Drupal\Core\Database\Database::getConnection();

	$query_delete = $connection->delete('config')
		->condition('collection', 'language.fr')
		->condition('name', 'taxonomy.vocabulary.thematic')
		->execute();

	$query_create = $connection->insert('config')
		->fields(array(
			'collection' => 'language.fr',
			'name' => 'taxonomy.vocabulary.thematic',
			'data' => serialize(array (
				'description' => 'Thématique',
			))
		))
		->execute();


/* Termes */
$terms = array(
	array( 'vid' => 'thematic', 'name' => 'Transformation digitale', 'language' => 'fr'),
	array( 'vid' => 'thematic', 'name' => 'Digital transformation', 'language' => 'en'),
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