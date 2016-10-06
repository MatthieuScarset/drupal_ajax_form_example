<?php

use Drupal\Core\Database\Database;

// création du lien Contactez-nous du menu top-right-navbar-fr
$menu_links = array(
array('langcode' => 'fr', 'title' => 'Contactez-nous', 'menu_name' => 'top-right-navbar-fr', 'link' => 'internal:/contact/any_request', 'weight' => 0),
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

// création du lien Contactez-nous du menu service-space (top right navbar en)
$menu_links = array(
    array('langcode' => 'en', 'title' => 'Contact us', 'menu_name' => 'service-space', 'link' => 'internal:/contact/any_request', 'weight' => 0),
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
$config = $config_factory->getEditable('block.block.servicespace');
$config->delete();

//suppression de l'icone "icon-control-centre"
$content_block = \Drupal::entityManager()->getStorage('block_content')->load(1);
$body_value = '<span class="glyphicon glyphicon-search" data-toggle="collapse" data-target="#search-form" aria-hidden="true" font-size="2em"></span><span class="align-right icon icon-share" data-toggle="collapse" data-target="#social-share" aria-hidden="true"></span>';
$content_block->set('body', array("value"=>$body_value,"summary"=>"","format"=>"code_source"));
$content_block->save();