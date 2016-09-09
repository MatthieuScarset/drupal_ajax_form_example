<?php

use Drupal\Core\Database\Database;


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.navigationprincipaleru');
$config->setData(array (
  'uuid' => 'e5357b0c-0a64-4d77-bea8-14599d3129a5',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.navigation-principale-ru',
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
  'id' => 'navigationprincipaleru',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -8,
  'provider' => NULL,
  'plugin' => 'system_menu_block:navigation-principale-ru',
  'settings' =>
    array (
      'id' => 'system_menu_block:navigation-principale-ru',
      'label' => 'Navigation principale RU',
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
$config = $config_factory->getEditable('block.block.navigationprincipaleruen');
$config->setData(array (
  'uuid' => 'd2a77255-329a-4fc2-9890-06f20202db19',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'system.menu.navigation-principale-ru-en',
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
  'id' => 'navigationprincipaleruen',
  'theme' => 'theme_boosted',
  'region' => 'header',
  'weight' => -7,
  'provider' => NULL,
  'plugin' => 'system_menu_block:navigation-principale-ru-en',
  'settings' =>
    array (
      'id' => 'system_menu_block:navigation-principale-ru-en',
      'label' => 'Navigation principale RU-EN',
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

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_navigationprincipaleru');
$config->set('weight', -7);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_navigationprincipaleruen');
$config->set('weight', -6);
$config->save(TRUE);