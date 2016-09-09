<?php

use Drupal\Core\Database\Database;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.navigation-principale-ru');
$config->setData(array (
  'uuid' => '96f60cae-c19d-4da9-a899-ef12a05c239f',
  'langcode' => 'ru',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'navigation-principale-ru',
  'label' => 'Navigation principale RU',
  'description' => 'Liens du Header RU',
  'locked' => false,
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.navigation-principale-ru-en');
$config->setData(array (
  'uuid' => '529e8521-8488-4ea5-8187-ec3512ce37f0',
  'langcode' => 'ru-en',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'navigation-principale-ru-en',
  'label' => 'Navigation principale RU-EN',
  'description' => 'Liens du Header RU-EN',
  'locked' => false,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-navbar-ru');
$config->setData(array (
  'uuid' => 'e73596e9-4ead-4a3e-9d77-a798e13bec10',
  'langcode' => 'ru',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'top-navbar-ru',
  'label' => 'top navbar RU',
  'description' => 'Sur-header RU',
  'locked' => false,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-navbar-ru-en');
$config->setData(array (
  'uuid' => '58ca9953-a7b9-4a56-a98a-d9300b449a2b',
  'langcode' => 'ru-en',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'top-navbar-ru-en',
  'label' => 'top navbar RU-EN',
  'description' => 'Sur-header RU-EN',
  'locked' => false,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-right-navbar-ru');
$config->setData(array (
  'uuid' => '2cea1d11-df8d-43cd-bfa5-6706765243b0',
  'langcode' => 'ru',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'top-right-navbar-ru',
  'label' => 'top right navbar RU',
  'description' => 'Sur-header à droite RU',
  'locked' => false,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-right-navbar-ru-en');
$config->setData(array (
  'uuid' => '09809652-3660-4b8d-a59b-576c8da411c1',
  'langcode' => 'ru-en',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'top-right-navbar-ru-en',
  'label' => 'top right navbar RU-EN',
  'description' => 'Sur-header à droite RU-EN',
  'locked' => false,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarru');
$config->setData(array (
  'uuid' => '9fbacf1d-db3d-41fc-8cdc-4efa016b573a',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.top-navbar-ru',
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
  'id' => 'topnavbarru',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -17,
  'provider' => NULL,
  'plugin' => 'system_menu_block:top-navbar-ru',
  'settings' =>
    array (
      'id' => 'system_menu_block:top-navbar-ru',
      'label' => 'top navbar RU',
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
              'ru' => 'ru',
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



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.toprightnavbarru');
$config->setData(array (
  'uuid' => '31db676a-7fb1-4236-a5b4-e485a4eea219',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.top-right-navbar-ru',
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
  'id' => 'toprightnavbarru',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -14,
  'provider' => NULL,
  'plugin' => 'system_menu_block:top-right-navbar-ru',
  'settings' =>
    array (
      'id' => 'system_menu_block:top-right-navbar-ru',
      'label' => 'top right navbar RU',
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
              'ru' => 'ru',
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



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarruen');
$config->setData(array (
  'uuid' => '0987959e-dea0-4ac1-8a5e-d4e74d3952a6',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.top-navbar-ru-en',
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
  'id' => 'topnavbarruen',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -15,
  'provider' => NULL,
  'plugin' => 'system_menu_block:top-navbar-ru-en',
  'settings' =>
    array (
      'id' => 'system_menu_block:top-navbar-ru-en',
      'label' => 'top navbar RU-EN',
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
              'ru-en' => 'ru-en',
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



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.toprightnavbarruen');
$config->setData(array (
  'uuid' => '0d0f3583-506d-4311-89cb-a71feade7f05',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.top-right-navbar-ru-en',
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
  'id' => 'toprightnavbarruen',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -13,
  'provider' => NULL,
  'plugin' => 'system_menu_block:top-right-navbar-ru-en',
  'settings' =>
    array (
      'id' => 'system_menu_block:top-right-navbar-ru-en',
      'label' => 'top right navbar RU-EN',
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
              'ru-en' => 'ru-en',
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
  array('langcode' => 'ru', 'title' => 'RU', 'menu_name' => 'top-right-navbar-ru', 'link' => 'internal:/ru', 'weight' => 0),
  array('langcode' => 'ru', 'title' => 'RU EN', 'menu_name' => 'top-right-navbar-ru', 'link' => 'internal:/ru-en', 'weight' => 1),
  array('langcode' => 'ru-en', 'title' => 'RU', 'menu_name' => 'top-right-navbar-ru-en', 'link' => 'internal:/ru', 'weight' => 0),
  array('langcode' => 'ru-en', 'title' => 'RU EN', 'menu_name' => 'top-right-navbar-ru-en', 'link' => 'internal:/ru-en', 'weight' => 1),
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


// ordre des blocs
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarmenu');
$config->set('weight', -18);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbaren');
$config->set('weight', -17);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarru');
$config->set('weight', -16);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarruen');
$config->set('weight', -15);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.toprightnavbarru');
$config->set('weight', -14);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.toprightnavbarruen');
$config->set('weight', -13);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.righticonblock');
$config->set('weight', -12);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.servicespace');
$config->set('weight', -11);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_sitebranding');
$config->set('weight', -10);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.navigationprincipaleen');
$config->set('weight', -9);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_navigationprincipale');
$config->set('weight', -8);
$config->save(TRUE);