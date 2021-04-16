<?php

$terms = array(
  array("language" => "en", "name" => "Blogs", "variable" => "blog_term_tid"),
  array("language" => "en", "name" => "Customer stories", "variable" => "customer_term_tid"),
  array("language" => "en", "name" => "Library", "variable" => "library_term_tid"),
  array("language" => "en", "name" => "Magazine", "variable" => "magazine_term_tid"),
  array("language" => "en", "name" => "Partners", "variable" => "partner_term_tid"),
  array("language" => "en", "name" => "Press", "variable" => "press_term_tid"),
  array("language" => "en", "name" => "Portfolio", "variable" => "product_term_tid"),
  array("language" => "fr", "name" => "Blogs", "variable" => "blog_term_tid"),
  array("language" => "fr", "name" => "Cas clients", "variable" => "customer_term_tid"),
  array("language" => "fr", "name" => "Médiathèque", "variable" => "library_term_tid"),
  array("language" => "fr", "name" => "Magazine", "variable" => "magazine_term_tid"),
  array("language" => "fr", "name" => "Partenaires", "variable" => "partner_term_tid"),
  array("language" => "fr", "name" => "Presse", "variable" => "press_term_tid"),
  array("language" => "fr", "name" => "Catalogue", "variable" => "product_term_tid"),
);

$EnConfig = array();
$FRConfig = array();

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
    case "en":
      $EnConfig[$term['variable']] = $term_id;
      break;
    case "fr":
      $FRConfig[$term['variable']] = $term_id;
      break;
  }
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->setData($EnConfig);
$config_group->save();

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('oab_subhomes.subhomes', $FRConfig);