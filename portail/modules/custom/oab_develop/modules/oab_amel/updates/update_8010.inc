<?php

// Bloc navigation principale EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.navigationprincipaleen');
$config->setData(
    array(
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(
                'config' =>
                    array(
                        0 => 'system.menu.navigation-principale-en',
                    ),
                'module' =>
                    array(
                        0 => 'language',
                        1 => 'system',
                    ),
                'theme' =>
                    array(
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'navigationprincipaleen',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -9,
        'provider' => NULL,
        'plugin' => 'system_menu_block:navigation-principale-en',
        'settings' =>
            array(
                'id' => 'system_menu_block:navigation-principale-en',
                'label' => 'Navigation principale EN',
                'provider' => 'system',
                'label_display' => '0',
                'level' => 1,
                'depth' => 0,
            ),
        'visibility' =>
            array(
                'language' =>
                    array(
                        'id' => 'language',
                        'langcodes' =>
                            array(
                                'en' => 'en',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array(
                                'language' => '@language.current_language_context:language_interface',
                            ),
                    ),
            ),
    )
));
$config->save(TRUE);

// Bloc navigation principale FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_navigationprincipale');
$config->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.main',
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
        'id' => 'theme_boosted_navigationprincipale',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -10,
        'provider' => NULL,
        'plugin' => 'system_menu_block:main',
        'settings' =>
            array (
                'id' => 'system_menu_block:main',
                'label' => 'Navigation principale',
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
));
$config->save(TRUE);

// Bloc navigation "sur header" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbaren');
$config->setData(
    array (
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
        'id' => 'topnavbaren',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -15,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-en',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-en',
                'label' => 'top navbar EN',
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
));
$config->save(TRUE);

// Bloc navigation "sur header" FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarmenu');
$config->setData(
    array(
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(
                'config' =>
                    array(
                        0 => 'system.menu.top-navbar-menu',
                    ),
                'module' =>
                    array(
                        0 => 'language',
                        1 => 'system',
                    ),
                'theme' =>
                    array(
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'topnavbarmenu',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -16,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-menu',
        'settings' =>
            array(
                'id' => 'system_menu_block:top-navbar-menu',
                'label' => 'Top navbar menu',
                'provider' => 'system',
                'label_display' => '0',
                'level' => 1,
                'depth' => 0,
            ),
        'visibility' =>
            array(
                'language' =>
                    array(
                        'id' => 'language',
                        'langcodes' =>
                            array(
                                'fr' => 'fr',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array(
                                'language' => '@language.current_language_context:language_interface',
                            ),
                    ),
            ),
    )
));
$config->save(TRUE);


// Bloc sur-header "Service space" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.servicespace');
$config->setData(
    array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array(
                'config' =>
                    array(
                        0 => 'system.menu.service-space',
                    ),
                'module' =>
                    array(
                        0 => 'language',
                        1 => 'system',
                    ),
                'theme' =>
                    array(
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'servicespace',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -13,
        'provider' => NULL,
        'plugin' => 'system_menu_block:service-space',
        'settings' =>
            array(
                'id' => 'system_menu_block:service-space',
                'label' => 'Service space',
                'provider' => 'system',
                'label_display' => '0',
                'level' => 1,
                'depth' => 0,
            ),
        'visibility' =>
            array(
                'language' =>
                    array(
                        'id' => 'language',
                        'langcodes' =>
                            array(
                                'en' => 'en',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array(
                                'language' => '@language.current_language_context:language_interface',
                            ),
                    ),
            ),
    )
));
$config->save(TRUE);

// Bloc sur-header "Identifiez vous" FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.menuducomptedelutilisateur');
$config->setData(
    array(
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(
                'config' =>
                    array(
                        0 => 'system.menu.account',
                    ),
                'module' =>
                    array(
                        0 => 'language',
                        1 => 'system',
                    ),
                'theme' =>
                    array(
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'menuducomptedelutilisateur',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -14,
        'provider' => NULL,
        'plugin' => 'system_menu_block:account',
        'settings' =>
            array(
                'id' => 'system_menu_block:account',
                'label' => 'Menu du compte de l\'utilisateur',
                'provider' => 'system',
                'label_display' => '0',
                'level' => 1,
                'depth' => 0,
            ),
        'visibility' =>
            array(
                'language' =>
                    array(
                        'id' => 'language',
                        'langcodes' =>
                            array(
                                'fr' => 'fr',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array(
                                'language' => '@language.current_language_context:language_interface',
                            ),
                    ),
            ),

    ));
$config->save(TRUE);