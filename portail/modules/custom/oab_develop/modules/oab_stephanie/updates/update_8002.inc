<?php 
use \Drupal\taxonomy\Entity\Vocabulary;
use \Drupal\taxonomy\Entity\Term;
//use \Drupal\Core\Utility\UpdateException;


//TERMES
$terms = array('blog_post' => 'Article de blog',
								'magazine' => 'Magazine');

foreach ($terms as $machine_name => $name)
{
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', 'content_type_taxonomy');
	$query->condition('field_nom_machine', $machine_name);
	$entity = $query->execute();

	if(!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		drupal_set_message("-- ".$name." non existant", "status");
		$newTerm = Term::create([
				'vid' => 'content_type_taxonomy',
				'name' => $name,
        'langcode' => 'fr',
        'field_nom_machine' => $machine_name,
		]);
		$newTerm->save();
		drupal_set_message("-- ".$name." créé ", "status");
	}
	else {
		drupal_set_message("-- ".$name." existant", "status");
	}
}
 return '';