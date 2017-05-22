<?php
/***********************
 * Article de blog
 ***********************/
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.blog_post', array (
'name' => 'Article de blog',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.blog_post', array (
'name' => 'Blog post',
));


/***********************
 * Pays
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.country', array (
  'name' => 'Pays',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.country', array (
  'name' => 'Country',
));

/***********************
 * Témoignage client
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.customer_story', array (
  'name' => 'Témoignage client',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.customer_story', array (
  'name' => 'Case study',
));

/***********************
 * Document
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.document', array (
  'name' => 'Document',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.document', array (
  'name' => 'Document',
));

/***********************
 * Page full html
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.full_html', array (
  'name' => 'Page full html',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.full_html', array (
  'name' => 'Full html page',
));

/***********************
 * Industrie
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.industry', array (
  'name' => 'Industrie',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.industry', array (
  'name' => 'Industry',
));

/***********************
 * Article de magazine
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.magazine', array (
  'name' => 'Article de magazine',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.magazine', array (
  'name' => 'Magazine article',
));

/***********************
 * Bureau
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.office', array (
  'name' => 'Bureau',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.office', array (
  'name' => 'Office',
));

/***********************
 * Partenaire
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.partner', array (
  'name' => 'Partenaire',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.partner', array (
  'name' => 'Partner',
));

/***********************
 * Dossier de presse
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.partner', array (
  'name' => 'Dossier de presse',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.partner', array (
  'name' => 'Press folder',
));

/***********************
 * Communiqué de presse
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.partner', array (
  'name' => 'Communiqué de presse',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.partner', array (
  'name' => 'Press release',
));

/***********************
 * Produit
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.product', array (
  'name' => 'Produit',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.product', array (
  'name' => 'Product',
));

/***********************
 * Bloggeur
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.profile', array (
  'name' => 'Bloggeur',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.profile', array (
  'name' => 'Blogger',
));

/***********************
 * Région
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.region', array (
  'name' => 'Région',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.region', array (
  'name' => 'Region',
));

/***********************
 * Page simple
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.simple_page', array (
  'name' => 'Page simple',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.simple_page', array (
  'name' => 'Simple page',
));

/***********************
 * Solution
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.solution', array (
  'name' => 'Solution',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.solution', array (
  'name' => 'Solution',
));

/***********************
 * Formulaire
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.webform', array (
  'name' => 'Formulaire',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.webform', array (
  'name' => 'Webform',
));
