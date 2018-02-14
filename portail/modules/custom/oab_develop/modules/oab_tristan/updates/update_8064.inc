<?php

###################
## Creation du topnavbar ES

if (\Drupal\system\Entity\Menu::load('top-navbar-es') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-navbar-es',
            'label' => 'Top navbar ES',
            'description' => 'Sur-header ES',
            'langcode'  => 'es'
        ])
        ->save();
}

##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topnavbares');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-navbar-es',
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
        'id' => 'topnavbares',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -29,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-es',
                'label' => 'Top navbar ES',
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
                                'es' => 'es',
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

$config_group = $config_factory->getEditable('block.block.topnavbares_2');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-navbar-es',
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
        'id' => 'topnavbares_2',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-es',
                'label' => 'Top navbar ES',
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
                                'es' => 'es',
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



###################
## Creation du topnavbar PT
if (\Drupal\system\Entity\Menu::load('top-navbar-pt') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-navbar-pt',
            'label' => 'Top navbar PT',
            'description' => 'Sur-header PT',
            'langcode'  => 'pt'
        ])
        ->save();
}

$config_group = $config_factory->getEditable('block.block.topnavbarpt');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-navbar-pt',
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
        'id' => 'topnavbarpt',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -28,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-pt',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-pt',
                'label' => 'Top navbar PT',
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
                                'pt-pt' => 'pt-pt',
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

$config_group = $config_factory->getEditable('block.block.topnavbarpt_2');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-navbar-pt',
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
        'id' => 'topnavbarpt_2',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-navbar-pt',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-navbar-pt',
                'label' => 'Top navbar PT',
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
                                'pt-pt' => 'pt-pt',
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
