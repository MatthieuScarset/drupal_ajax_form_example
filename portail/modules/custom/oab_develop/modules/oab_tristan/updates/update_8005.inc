<?php

$terms = array(
  //en
  array("language" => "en", "name" => "Blogs", "variable" => "blog_term_tid"),
  array("language" => "en", "name" => "Customer stories", "variable" => "customer_term_tid"),
  array("language" => "en", "name" => "Library", "variable" => "library_term_tid"),
  array("language" => "en", "name" => "Magazine", "variable" => "magazine_term_tid"),
  array("language" => "en", "name" => "Partners", "variable" => "partner_term_tid"),
  array("language" => "en", "name" => "Press", "variable" => "press_term_tid"),
  array("language" => "en", "name" => "Portfolio", "variable" => "product_term_tid"),
  // FR
  array("language" => "fr", "name" => "Blogs", "variable" => "blog_term_tid"),
  array("language" => "fr", "name" => "Cas clients", "variable" => "customer_term_tid"),
  array("language" => "fr", "name" => "Médiathèque", "variable" => "library_term_tid"),
  array("language" => "fr", "name" => "Magazine", "variable" => "magazine_term_tid"),
  array("language" => "fr", "name" => "Partenaires", "variable" => "partner_term_tid"),
  array("language" => "fr", "name" => "Presse", "variable" => "press_term_tid"),
  array("language" => "fr", "name" => "Catalogue", "variable" => "product_term_tid"),
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


$config = array();

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
    //drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
    $term_id = $entity->id();
  }
  else{
    $term_id = key($entity);
  }

  $config[$term['language']][$term['variable']] = $term_id;

}

##On crée les champs en anglais
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->setData($config['en']);
$config_group->save();

##Plus besoin de l'anglais, je l'enlève du tableau
unset($config['en']);

##Pour les autres langues, on crée une collection de la langue
foreach ($config as $language => $l_config ) {
  ##Pour les autres langues, on crée une collection de la langue
  $collection = \Drupal::service('config.storage')->createCollection('language.' . $language);
  $collection->write('oab_subhomes.subhomes', $l_config);
}

#A enlever à la fin des tests
//throw new UpdateException();