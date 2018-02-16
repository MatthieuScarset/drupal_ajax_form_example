<?php


if (\Drupal\system\Entity\Menu::load('bottom-footerbar-es') == null) {
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'bottom-footerbar-es',
            'label' => 'Bottom Footerbar ES',
            'description' => 'Bottom Footerbar ES',
            'langcode'  => 'es'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.bottomfooterbares');
$config_group->setData(
    array (
        'langcode' => 'es',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.bottom-footerbar-es',
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
        'id' => 'bottomfooterbares',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:bottom-footerbar-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:bottom-footerbar-es',
                'label' => 'Bottom Footerbar ES',
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



if (\Drupal\system\Entity\Menu::load('bottom-footerbar-br') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'bottom-footerbar-br',
            'label' => 'Bottom Footerbar BR',
            'description' => 'Bottom Footerbar BR',
            'langcode'  => 'pt-br'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.bottomfooterbarbr');
$config_group->setData(
    array (
        'langcode' => 'pt-br',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.bottom-footerbar-br',
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
        'id' => 'bottomfooterbarbr',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:bottom-footerbar-br',
        'settings' =>
            array (
                'id' => 'system_menu_block:bottom-footerbar-br',
                'label' => 'Bottom Footerbar BR',
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