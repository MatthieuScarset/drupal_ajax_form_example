<?php

use Drupal\Core\Database\Database;
use \Drupal\Core\Utility\UpdateException;

/***
 * Fichier de configuration pour le placement des blocs dans le menu en fonction de la langue
 */

/*****************************
 * SYSTEM.MENU.XXX : config menu
 *****************************/

// Bloc system menu navigation principale EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.navigation-principale-en');
$config->setData(
    array(
        'uuid' => '6b4cfe56-c46d-4352-b1df-bc09f3bc62a7',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'navigation-principale-en',
        'label' => 'Navigation principale EN',
        'description' => 'Liens du Header EN',
        'locked' => false,
    )
);
$config->save(TRUE);

// Bloc system menu service space
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.service-space');
$config->setData(
    array(
        'uuid' => 'ada0a45e-ee5a-4e52-945d-44ef776557b6',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'service-space',
        'label' => 'Service space',
        'description' => 'Espace client pour le site EN',
        'locked' => false,
    )
);

// Bloc system menu top navbar EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-navbar-en');
$config->setData(
    array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'top-navbar-en',
        'label' => 'top navbar EN',
        'description' => 'Sur-header EN',
        'locked' => false,
    )
);
$config->save(TRUE);

// Bloc system menu mon compte
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.account');
$config->setData(
    array(
        'uuid' => 'd8b3b2e6-96f5-409f-9e00-e0e5866340ee',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'account',
        'label' => 'Menu du compte de l\'utilisateur',
        'description' => 'Liens associés au compte utilisateur courant',
        'locked' => true,
    )
);
$config->save(TRUE);


// Bloc system menu top navbar FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.top-navbar-menu');
$config->setData(
    array(
        'uuid' => '9a64a531-c9d9-4a74-8e05-5a2af55fd68c',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'top-navbar-menu',
        'label' => 'Top navbar menu',
        'description' => 'Sur-header FR',
        'locked' => false,
    )
);
$config->save(TRUE);


// Bloc system menu navigation principale FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.main');
$config->setData(
    array(
        'uuid' => 'ce9db4c7-6466-4299-8d00-a1f0c31cd652',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'main',
        'label' => 'Navigation principale',
        'description' => 'Liens de section du site',
        'locked' => true,
    )
);
$config->save(TRUE);





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
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/Regional-presence',
        'enabled' => '1',
        'parent' => ''
    ));

    $menu_topnavbaren->save();
    $menuparent = $menu_topnavbaren->uuid();

    // création des sous menus du sur-header EN : regional presence : france/europe/asia/ etc...

    $menu_topnavbaren_france = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'France',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/fr',
        'weight' => '-50',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_topnavbaren_france->save();

    $menu_topnavbaren_europe = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'Europe',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/europe',
        'weight' => '-49',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_topnavbaren_europe->save();

    $menu_topnavbaren_asia = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'Asia/Pacific',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/asia',
        'weight' => '-48',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_topnavbaren_asia->save();

    $menu_topnavbaren_la_america = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'Latina America',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/latina-america',
        'weight' => '-47',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));

    $menu_topnavbaren_la_america->save();

    $menu_topnavbaren_middle_east = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'Middle East',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/middle-east',
        'weight' => '-46',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_topnavbaren_middle_east->save();

    $menu_topnavbaren_no_america = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'fr',
        'title' => 'North America',
        'menu_name' => 'top-navbar-en',
        'link' => 'internal:/north-america',
        'weight' => '-45',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_topnavbaren_no_america->save();
}
//throw new \Drupal\Core\Utility\UpdateException();


// Bloc navigation principale EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.navigationprincipaleen');
$config->setData(
    array (
        'uuid' => '96153f07-573c-4419-8d98-86bc514118c0',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.navigation-principale-en',
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
        'id' => 'navigationprincipaleen',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -17,
        'provider' => NULL,
        'plugin' => 'system_menu_block:navigation-principale-en',
        'settings' =>
            array (
                'id' => 'system_menu_block:navigation-principale-en',
                'label' => 'Navigation principale EN',
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
    ));
$config->save(TRUE);

// Bloc navigation principale FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.theme_boosted_navigationprincipale');
$config->setData(
    array (
        'uuid' => NULL,
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
     ));
$config->save(TRUE);

// Bloc navigation "sur header" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbaren');
$config->setData(
    array (
        'uuid' => 'ed58051a-ff14-4d14-a443-06d7f79b8139',
        'langcode' => 'en',
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
        'weight' => -16,
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
    ));
$config->save(TRUE);

// Bloc navigation "sur header" FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.topnavbarmenu');
$config->setData(
    array (
        'uuid' => NULL,
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-navbar-menu',
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
        'id' => 'topnavbarmenu',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -15,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-menu',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-menu',
                'label' => 'Top navbar menu',
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


// Bloc sur-header "Service space" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.servicespace');
$config->setData(
    array (
        'uuid' => NULL,
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.service-space',
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
        'id' => 'servicespace',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -13,
        'provider' => NULL,
        'plugin' => 'system_menu_block:service-space',
        'settings' =>
            array (
                'id' => 'system_menu_block:service-space',
                'label' => 'Service space',
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
    ));
$config->save(TRUE);

// Bloc sur-header "Identifiez vous" FR
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.menuducomptedelutilisateur');
$config->setData(
    array(
        array (
            'uuid' => NULL,
            'langcode' => 'fr',
            'status' => true,
            'dependencies' =>
                array (
                    'config' =>
                        array (
                            0 => 'system.menu.account',
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
            'id' => 'menuducomptedelutilisateur',
            'theme' => 'theme_boosted',
            'region' => 'header',
            'weight' => -14,
            'provider' => NULL,
            'plugin' => 'system_menu_block:account',
            'settings' =>
                array (
                    'id' => 'system_menu_block:account',
                    'label' => 'Menu du compte de l\'utilisateur',
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
        ),
    ));
$config->save(TRUE);



//throw new \Drupal\Core\Utility\UpdateException();