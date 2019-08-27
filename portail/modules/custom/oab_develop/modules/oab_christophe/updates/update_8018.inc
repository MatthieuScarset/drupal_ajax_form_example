<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.subhomes');

$config_group->set('display.page_blog.display_title', 'blogs');
$config_group->set('display.page_catalogue.title', 'Blogs');

$config_group->set('display.page_document.display_title', 'documents');
$config_group->set('display.page_document.title', 'Library');

$config_group->set('display.page_customer.display_title', 'customer stories');
$config_group->set('display.page_customer.title', 'Case study');

$config_group->set('display.page_magazine.display_title', 'magazine');
$config_group->set('display.page_magazine.title', 'Magazine');

$config_group->set('display.page_partners.display_title', 'partners');
$config_group->set('display.page_partners.title', 'Partners');

$config_group->set('display.page_catalogue.display_title', 'products');
$config_group->set('display.page_catalogue.title', 'Products');

$config_group->set('display.page_press.display_title', 'press');
$config_group->set('display.page_press.title', 'Press');

$config_group->save(TRUE);


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('views.view.subhomes', array (
  'display' =>
    array (
      'page_press' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                  'field_document_type_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par type',
                        ),
                    ),
                ),
            ),
          'display_title' => 'Communiqués de presse',
        ),
      'page_blog' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
            ),
        ),
      'page_catalogue' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
              'title' => 'Produits',
            ),
          'display_title' => 'Produits',
        ),
      'page_customer' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                  'field_industry_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par industrie',
                        ),
                    ),
                ),
              'title' => 'Témoignage client',
            ),
          'display_title' => 'Témoignage client',
        ),
      'page_document' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                  'field_industry_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par industrie',
                        ),
                    ),
                ),
              'title' => 'Médiathèque',
            ),
          'display_title' => 'Médiathèque',
        ),
      'page_magazine' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
            ),
        ),
      'page_partners' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
              'title' => 'Partenaires',
            ),
          'display_title' => 'Partenaires',
        ),
      'default' =>
        array (
          'display_options' =>
            array (
              'title' => 'Communiqués de presse',
            ),
        ),
    ),
));

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
          'display_title' => '',
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
          'display_title' => 'Newsroom',
        ),
    ),
));


// terms views subhomes

$terms = array(
  // RU
  array("language" => "ru", "name" => "Блоги", "variable" => "blog_term_tid"),
  array("language" => "ru", "name" => "Проекты", "variable" => "customer_term_tid"),
  array("language" => "ru", "name" => "Новости", "variable" => "press_term_tid"),
  array("language" => "ru", "name" => "Услуги", "variable" => "product_term_tid"),
  //RU-EN
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