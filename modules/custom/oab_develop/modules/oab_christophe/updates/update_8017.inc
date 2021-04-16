<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.subhomes');

$config_group->set('display.page_blog.display_options.path', 'subhome_blogs');
$config_group->set('display.page_blog.display_title', '');

$config_group->set('display.page_document.display_options.path', 'subhome_documents');
$config_group->set('display.page_document.display_title', '');

$config_group->set('display.page_customer.display_options.path', 'subhome_customers');
$config_group->set('display.page_customer.display_title', '');

$config_group->set('display.page_magazine.display_options.path', 'subhome_magazine');
$config_group->set('display.page_magazine.display_title', '');

$config_group->set('display.page_partners.display_options.path', 'subhome_partners');
$config_group->set('display.page_partners.display_title', '');

$config_group->set('display.page_catalogue.display_options.path', 'subhome_catalogue');
$config_group->set('display.page_catalogue.display_title', '');

$config_group->set('display.page_press.display_options.path', 'subhome_press');
$config_group->set('display.page_press.display_title', '');

$config_group->save(TRUE);

\Drupal::service('path.alias_storage')->delete(array('source' => '/case-study', 'alias' => '/temoignage-client', 'langcode' => 'fr'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/case-study', 'alias' => '/projects', 'langcode' => 'ru'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/case-study', 'alias' => '/customer-stories', 'langcode' => 'ru-en'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/partners', 'alias' => '/partenaires', 'langcode' => 'fr'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/library', 'alias' => '/mediatheque', 'langcode' => 'fr'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/press', 'alias' => '/presse', 'langcode' => 'fr'));
\Drupal::service('path.alias_storage')->delete(array('source' => '/products', 'alias' => '/produits', 'langcode' => 'fr'));

// subhome_blogs
\Drupal::service('path.alias_storage')->save("/subhome_blogs", "/blogs", "en");
\Drupal::service('path.alias_storage')->save("/subhome_blogs", "/blogs", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_blogs", "/blogs", "ru");

// subhome_documents
\Drupal::service('path.alias_storage')->save("/subhome_documents", "/library", "en");
\Drupal::service('path.alias_storage')->save("/subhome_documents", "/mediatheque", "fr");

// subhome_customers
\Drupal::service('path.alias_storage')->save("/subhome_customers", "/case-study", "en");
\Drupal::service('path.alias_storage')->save("/subhome_customers", "/temoignage-client", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_customers", "/projects", "ru");
\Drupal::service('path.alias_storage')->save("/subhome_customers", "/customer-stories", "ru-en");

// subhome_magazine
\Drupal::service('path.alias_storage')->save("/subhome_magazine", "/magazine", "en");
\Drupal::service('path.alias_storage')->save("/subhome_magazine", "/magazine", "fr");

// subhome_partners
\Drupal::service('path.alias_storage')->save("/subhome_partners", "/partners", "en");
\Drupal::service('path.alias_storage')->save("/subhome_partners", "/partenaires", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_partners", "/partners", "ru");
\Drupal::service('path.alias_storage')->save("/subhome_partners", "/partners", "ru-en");

// subhome_catalogue
\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/products", "en");
\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/produits", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/products", "ru");
\Drupal::service('path.alias_storage')->save("/subhome_catalogue", "/products", "ru-en");

// subhome_press
\Drupal::service('path.alias_storage')->save("/subhome_press", "/press", "en");
\Drupal::service('path.alias_storage')->save("/subhome_press", "/press", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_press", "/press", "ru");
\Drupal::service('path.alias_storage')->save("/subhome_press", "/press", "ru-en");
