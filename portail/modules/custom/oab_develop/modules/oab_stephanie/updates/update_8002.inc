<?php 
use \Drupal\taxonomy\Entity\Vocabulary;
use \Drupal\taxonomy\Entity\Term;
//use \Drupal\Core\Utility\UpdateException;


//TERMES
$terms = array('blog_post' => 'Blog post',
								'magazine' => 'Magazine');

foreach ($terms as $machine_name => $name)
{
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', 'rendering_model');
	$query->condition('field_machine_name', $machine_name);
	$entity = $query->execute();

	if(!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		drupal_set_message("-- ".$name." non existant", "status");
		$newTerm = Term::create([
				'vid' => 'rendering_model',
				'name' => $name,
        'langcode' => 'en',
        'field_machine_name' => $machine_name,
		]);
		$newTerm->save();
		/*
		$termFR = $newTerm->addTranslation('fr');
		$termFR->set()*/
		drupal_set_message("-- ".$name." créé ", "status");
	}
	else {
		drupal_set_message("-- ".$name." existant", "status");
	}
}
 return '';