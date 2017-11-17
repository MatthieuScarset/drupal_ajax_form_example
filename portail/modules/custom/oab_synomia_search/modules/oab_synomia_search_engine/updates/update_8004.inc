<?php
/**
 * Ajout de l'ordre d'affichage des types de contenus
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab.synomia.searchSettings');
$config_group->set('order_content_types_en', 'product, region, country, solution, industry, customer_story, partner, press_release, document, blog_post, magazine, full_html');
$config_group->set('order_content_types_fr', 'product, region, country, solution, industry, customer_story, partner, press_release, document, blog_post, magazine, full_html');
$config_group->set('order_content_types_ru', 'product, region, country, solution, industry, customer_story, partner, press_release, document, blog_post, magazine, full_html');
$config_group->set('order_content_types_ru-en', 'product, region, country, solution, industry, customer_story, partner, press_release, document, blog_post, magazine, full_html');
$config_group->save(TRUE);