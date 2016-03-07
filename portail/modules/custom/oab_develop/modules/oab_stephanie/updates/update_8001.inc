<?php 
use \Drupal\taxonomy\Entity\Vocabulary;
use \Drupal\taxonomy\Entity\Term;
//use \Drupal\Core\Utility\UpdateException;

//VOCABULAIRE
$vid = "areas";
$name = "Areas";
$vocabularies = Vocabulary::loadMultiple();
drupal_set_message("- Vocabulaires chargés", "status");
//On regarde si Areas existe
if (!isset($vocabularies[$vid])) 
{
	//s'il n'existe pas on le crée
	drupal_set_message("-- Areas non existant", "status");
	$vocabulary = Vocabulary::create(array(
			'vid' => $vid,
			'machine_name' => $vid,
			'name' => $name,
	));
	$vocabulary->save();
	drupal_set_message("-- Areas créé", "status");
}
else {
	// il existe déjà
	drupal_set_message("-- Areas existant", "status");
}

//TERMES
$terms = array('North America', 'Russia', 'Middle East', 'Latin America', 'Asia Pacific', 'Europe', 'Africa');

drupal_set_message("- Création des termes", "status");
foreach ($terms as $my_term)
{
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $vid);
	$query->condition('name', $my_term);
	$entity = $query->execute();
	
	if(!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		drupal_set_message("-- ".$my_term." non existant", "status");
		$newTerm = Term::create([
				'vid' => $vid,
				'langcode' => 'en',
				'name' => $my_term,
		]);
		$newTerm->save();
		drupal_set_message("-- ".$my_term." créé ", "status");
	}
	else {
		drupal_set_message("-- ".$my_term." existant", "status");
	}
}
return '';

//throw new UpdateException();