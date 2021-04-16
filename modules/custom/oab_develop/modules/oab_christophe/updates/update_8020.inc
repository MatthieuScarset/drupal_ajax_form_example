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