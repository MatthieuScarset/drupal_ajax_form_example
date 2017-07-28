<?php

/**
 * Ajouts de blocs aà la région footer pour la mise en page des menus pour la version mobile
 */

##EN
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topnavbaren_2');
$config_group->setData(
  array (
    'uuid' => '44bf0c72-861a-4688-9190-587408b16a81',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'system.menu.top-navbar-en',
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
    'id' => 'topnavbaren_2',
    'theme' => 'theme_boosted',
    'region' => 'footer',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'system_menu_block:top-navbar-en',
    'settings' =>
      array (
        'id' => 'system_menu_block:top-navbar-en',
        'label' => 'Top navbar EN',
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
                'en' => 'en',
              ),
            'negate' => false,
            'context_mapping' =>
              array (
                'language' => '@language.current_language_context:language_interface',
              ),
          ),
      ),
  )
);
$config_group->save(TRUE);


##FR
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topnavbarfr_2');
$config_group->setData(
  array (
    'uuid' => 'a08c2f9f-27aa-472c-8d0a-56ffeb1562d0',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'system.menu.top-navbar-fr',
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
    'id' => 'topnavbarfr_2',
    'theme' => 'theme_boosted',
    'region' => 'footer',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'system_menu_block:top-navbar-fr',
    'settings' =>
      array (
        'id' => 'system_menu_block:top-navbar-fr',
        'label' => 'Top navbar FR',
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
  )
);
$config_group->save(TRUE);


##RU
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topnavbarru_2');
$config_group->setData(
  array (
    'uuid' => '3e9587e9-f2af-45e1-99e1-9e6f3eac27c8',
    'langcode' => 'fr',
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
    'id' => 'topnavbarru_2',
    'theme' => 'theme_boosted',
    'region' => 'footer',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'system_menu_block:top-navbar-ru',
    'settings' =>
      array (
        'id' => 'system_menu_block:top-navbar-ru',
        'label' => 'Top navbar RU',
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
  )
);
$config_group->save(TRUE);


##RU-EN
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topnavbarruen_2');
$config_group->setData(
  array (
    'uuid' => 'f7800bef-e0e3-442c-a8c6-14ba78f00709',
    'langcode' => 'fr',
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
    'id' => 'topnavbarruen_2',
    'theme' => 'theme_boosted',
    'region' => 'footer',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'system_menu_block:top-navbar-ru-en',
    'settings' =>
      array (
        'id' => 'system_menu_block:top-navbar-ru-en',
        'label' => 'Top navbar RU-EN',
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
  )
);
$config_group->save(TRUE);
