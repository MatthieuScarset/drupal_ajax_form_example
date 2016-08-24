<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('system.menu.top-navbar-en');
$config_group->setData(
    array (
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'top-navbar-en',
        'label' => 'top navbar EN',
        'description' => 'Sur-header EN',
        'locked' => false,
    )
);
$config_group->save(TRUE);

// création du menu du sur-header EN : regional presence
$connection = Database::getConnection();
$query = $connection->select('menu_link_content_data', 's')
->fields('s', array('link__uri'))
->condition('s.link__uri', 'internal:/Regional-presence');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

if (empty($results)){
$menu_topnavbaren = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
    'bundle' => 'menu_link_content',
    'langcode' => 'fr',
    'title' => 'Regional presence',
    'menu-name' => 'top-navbar-en',
    'link' => 'internal:/Regional-presence',
    'enabled' => '1',
    'parent' => ''
    ));
    $menu_topnavbaren->save();
}
$menuparent = $menu_topnavbaren->uuid();

// création des sous menus du sur-header EN : regional presence : france/europe/asia/ etc...
$connection = Database::getConnection();
$query = $connection->select('menu_link_content_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.link__uri', 'internal:/fr');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

$menu_topnavbaren_france = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
    'bundle' => 'default',
    'langcode' => 'fr',
    'title' => 'France',
    'menu-name' => 'top-navbar-en',
    'link' => 'internal:/fr',
    'weight' => '-50',
    'enabled' => '1',
    'parent' => 'menu_link_content:' . $menuparent
));
$menu_topnavbaren_france->save();


$connection = Database::getConnection();
$query = $connection->select('menu_link_content_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.link__uri', 'internal:/europe');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

$menu_topnavbaren_europe = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
    'bundle' => 'default',
    'langcode' => 'fr',
    'title' => 'Europe',
    'menu-name' => 'top-navbar-en',
    'link' => 'internal:/europe',
    'weight' => '-49',
    'enabled' => '1',
    'parent' => 'menu_link_content:' . $menuparent
));
$menu_topnavbaren_europe->save();

$connection = Database::getConnection();
$query = $connection->select('menu_link_content_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.link__uri', 'internal:/titi');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

$menu_topnavbaren_titi = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
    'bundle' => 'default',
    'langcode' => 'fr',
    'title' => 'Europe',
    'menu-name' => 'top-navbar-en',
    'link' => 'internal:/titi',
    'weight' => '-48',
    'enabled' => '1',
    'parent' => 'menu_link_content:' . $menuparent
));
$menu_topnavbaren_europe->save();

throw new \Drupal\Core\Utility\UpdateException();



