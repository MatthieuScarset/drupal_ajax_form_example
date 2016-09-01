<?php

use Drupal\Core\Database\Database;
use \Drupal\Core\Utility\UpdateException;

// création du menu du sur-header EN : regional presence

$connection = Database::getConnection();

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/a-propos');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'A propos',
        'menu_name' => 'main',
        'link' => 'internal:/a-propos',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/expertise');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Expertise',
        'menu_name' => 'main',
        'link' => 'internal:/expertise',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/produits-et-services');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Produits et services',
        'menu_name' => 'main',
        'link' => 'internal:/produits-et-services',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/eclairages');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Eclairages',
        'menu_name' => 'main',
        'link' => 'internal:/eclairages',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}




throw new \Drupal\Core\Utility\UpdateException();