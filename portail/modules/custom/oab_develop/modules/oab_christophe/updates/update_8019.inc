<?php

\Drupal::service('path.alias_storage')->delete(array('source' => '/subhome_press', 'alias' => '/press', 'langcode' => 'fr'));

\Drupal::service('path.alias_storage')->save("/subhome_press", "/presse", "fr");

$terms = array(
  // RU
  array("language" => "ru", "name" => "Партнеры", "variable" => "partner_term_tid"),
  //RU-EN
  array("language" => "ru-en", "name" => "Partners", "variable" => "partner_term_tid"),
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


$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('views.view.subhomes', array (
  'display' =>
    array (
      'default' =>
        array (
          'display_title' => 'Новости',
          'display_options' =>
            array (
              'title' => 'Новости',
            ),
        ),
      'page_blog' =>
        array (
          'display_title' => 'Блоги',
          'display_options' =>
            array (
              'title' => 'Блоги',
            ),
        ),
      'page_catalogue' =>
        array (
          'display_title' => 'Услуги',
          'display_options' =>
            array (
              'title' => 'Услуги',
            ),
        ),
      'page_customer' =>
        array (
          'display_title' => 'Проекты',
          'display_options' =>
            array (
              'title' => 'Проекты',
            ),
        ),
      'page_document' =>
        array (
          'display_title' => '',
        ),
      'page_magazine' =>
        array (
          'display_title' => '',
        ),
      'page_partners' =>
        array (
          'display_title' => 'Партнеры',
          'display_options' =>
            array (
              'title' => 'Партнеры',
            ),
        ),
      'page_press' =>
        array (
          'display_title' => 'Новости',
        ),
    ),
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru-en');
$collection->write('views.view.subhomes', array (
  'display' =>
    array (
      'default' =>
        array (
          'display_title' => 'Newsroom',
          'display_options' =>
            array (
              'title' => 'Newsroom',
            ),
        ),
      'page_blog' =>
        array (
          'display_title' => '',
        ),
      'page_customer' =>
        array (
          'display_title' => 'Projects',
          'display_options' =>
            array (
              'title' => 'Projects',
            ),
        ),
      'page_document' =>
        array (
          'display_title' => '',
        ),
      'page_magazine' =>
        array (
          'display_title' => '',
        ),
      'page_partners' =>
        array (
          'display_title' => 'Partners',
          'display_options' =>
            array (
              'title' => 'Partners',
            ),
        ),
      'page_press' =>
        array (
          'display_title' => 'Newsroom',
        ),
    ),
));