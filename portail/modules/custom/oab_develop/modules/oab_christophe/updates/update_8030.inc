<?php

use Drupal\Core\Database\Database;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-right-navbar-fr');
$config->setData(array (
  'uuid' => '4080b0bf-efe8-4076-b2f9-fcaa420e86a3',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'top-right-navbar-fr',
  'label' => 'top right navbar FR',
  'description' => '	Sur-header à droite FR',
  'locked' => false,
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.toprightnavbarfr');
$config->setData(array (
  'uuid' => 'e355eb79-af3d-42fe-bcfd-b0df8cbbccfc',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.top-right-navbar-fr',
        ),
      'module' =>
        array (
          0 => 'language',
          1 => 'system',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'toprightnavbarfr',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -16,
  'provider' => NULL,
  'plugin' => 'system_menu_block:top-right-navbar-fr',
  'settings' =>
    array (
      'id' => 'system_menu_block:top-right-navbar-fr',
      'label' => 'top right navbar FR',
      'provider' => 'system',
      'label_display' => '0',
      'level' => 1,
      'depth' => 0,
    ),
  'visibility' =>
    array (
      'language' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => '@language.current_language_context:language_interface',
            ),
        ),
    ),
));
$config->save(TRUE);

// création des liens de menu
$menu_links = array(
  array('langcode' => 'fr', 'title' => 'Identifiez-vous', 'menu_name' => 'top-right-navbar-fr', 'link' => 'https://espaceclient.orange-business.com/group/ece2/home?codeContexte=eceDefault', 'weight' => 0),
);

foreach ($menu_links AS $menu_link){
  $connection = Database::getConnection();
  $query = $connection->select('menu_link_content_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.link__uri', $menu_link['link'])
    ->condition('s.langcode', $menu_link['langcode'])
    ->condition('s.menu_name', $menu_link['menu_name']);

  $results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

  if (empty($results)){
    $menu_link_item = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
      'bundle' => 'menu_link_content',
      'langcode' => $menu_link['langcode'],
      'title' => $menu_link['title'],
      'menu_name' => $menu_link['menu_name'],
      'link' => $menu_link['link'],
      'enabled' => '1',
      'parent' => '',
      'weight' => $menu_link['weight']
    ));

    $menu_link_item->save();
  }
}

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.account');
$config->delete();