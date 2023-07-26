<?php

$terms = array(
	// RU
	array("language" => "ru", "name" => "Партнеры", "variable" => "partner_term_tid"),
	array("language" => "ru", "name" => "Блоги", "variable" => "blog_term_tid"),
	array("language" => "ru", "name" => "Проекты", "variable" => "customer_term_tid"),
	array("language" => "ru", "name" => "Новости", "variable" => "press_term_tid"),
	array("language" => "ru", "name" => "Услуги", "variable" => "product_term_tid"),
	//RU-EN
	array("language" => "ru-en", "name" => "Partners", "variable" => "partner_term_tid"),
	array("language" => "ru-en", "name" => "Projects", "variable" => "customer_term_tid"),
	array("language" => "ru-en", "name" => "Newsroom", "variable" => "press_term_tid"),
	array("language" => "ru-en", "name" => "Products", "variable" => "product_term_tid"),
);

$RUConfig = array();
$RUENConfig = array();

foreach ($terms as &$term)
{
	$term_id = "";
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', "subhomes");
	$query->condition('langcode', $term['language']);
	$query->condition('name', $term['name']);
	$entity = $query->execute();

	if (!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		$entity = \Drupal\taxonomy\Entity\Term::create([
			'vid' => "subhomes",
			'name' => $term['name'],
			'langcode' => $term['language'],
		]);
		$entity->save();
		drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
		$term_id = $entity->id();
	}
	else{
		$term_id = key($entity);
	}
	switch($term['language']) {
		case "ru":
			$RUConfig[$term['variable']] = $term_id;
			break;
		case "ru-en":
			$RUENConfig[$term['variable']] = $term_id;
			break;
	}
}

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('oab_subhomes.subhomes', $RUConfig);

$collection = \Drupal::service('config.storage')->createCollection('language.ru-en');
$collection->write('oab_subhomes.subhomes', $RUENConfig);

/**
 * Mise à jour du field "field_related_display_view" pour tous les termes de la taxo Subhome
 * afin de faire fonctionner le fil d'Arianne
 */
$termList = [
	"Newsroom"              => "page_press",
	"Partners"              => "page_partners",
	"Press"                 => "page_press",
	"Products"              => "page_products",
	"Projects"              => "page_customer",
	"Блоги"                 => "page_blog",
	"Новости"               => "page_press",
	"Партнеры"              => "page_partners",
	"Проекты"               => "page_customer",
	"Услуги"                => "page_products"
];

##On boucle sur tous les termes de la taxo Subhomes
foreach ($termList as $taxoTerm => $view) {
	##on cherche l'Objet
//	$termsArray = taxonomy_term_load_multiple_by_name($taxoTerm, "subhomes");

  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $taxoTerm, "vid" => "subhomes"]);

	##On boucle sur tous les termes trouvés (Magazine par exemple..)
	foreach ($termsArray as $term_id => $termObject) {
		#related_display_view
		$termObject->set('field_related_display_view', $view);
		$termObject->save();
	}
}
