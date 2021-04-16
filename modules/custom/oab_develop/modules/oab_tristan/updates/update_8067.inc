<?php
/**
 * Création du menu d'accès direct pour les sites ES et BR
 */


##version portuguaise BR
if (\Drupal\system\Entity\Menu::load('direct-access-bar-br') == null) {
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'direct-access-bar-br',
            'label' => 'Direct Access Bar BR',
            'description' => 'Menu for Direct Access Bar BR',
            'langcode'  => 'br'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.directaccessbarbr');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.direct-access-bar-br',
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
        'id' => 'directaccessbarbr',
        'theme' => 'theme_boosted',
        'region' => 'prefooter',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:direct-access-bar-br',
        'settings' =>
            array (
                'id' => 'system_menu_block:direct-access-bar-br',
                'label' => 'Direct Access Bar BR',
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
                                'pt-br' => 'pt-br',
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


#version espagnolo ES

if (\Drupal\system\Entity\Menu::load('direct-access-bar-es') == null) {
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'direct-access-bar-es',
            'label' => 'Direct Access Bar ES',
            'description' => 'Menu for Direct Access Bar ES',
            'langcode'  => 'es'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.directaccessbares');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.direct-access-bar-es',
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
        'id' => 'directaccessbares',
        'theme' => 'theme_boosted',
        'region' => 'prefooter',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:direct-access-bar-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:direct-access-bar-es',
                'label' => 'Direct Access Bar ES',
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

