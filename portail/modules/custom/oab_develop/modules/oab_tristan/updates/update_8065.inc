<?php
###################
## Creation du topnavbar ES

if (\Drupal\system\Entity\Menu::load('top-right-navbar-es') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-right-navbar-es',
            'label' => 'Top right navbar ES',
            'description' => 'Top right navbar ES',
            'langcode'  => 'es'
        ])
        ->save();
}

if (\Drupal\system\Entity\Menu::load('top-right-navbar-footer-es') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-right-navbar-footer-es',
            'label' => 'Top right navbar Footer ES',
            'description' => 'Right navbar\'s links to be displayed in the footer in mobile mode',
            'langcode'  => 'es'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.toprightnavbares');
$config_group->setData(
    array (
        'langcode' => 'es',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-right-navbar-es',
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
        'id' => 'toprightnavbares',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -27,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-right-navbar-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-right-navbar-es',
                'label' => 'Top right navbar ES',
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




$config_group = $config_factory->getEditable('block.block.toprightnavbarfooteres');
$config_group->setData(
    array (
        'langcode' => 'es',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-right-navbar-footer-es',
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
        'id' => 'toprightnavbarfooteres',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-right-navbar-footer-es',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-right-navbar-footer-es',
                'label' => 'Top right navbar Footer ES',
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









###########################
# partie Bresilienne
if (\Drupal\system\Entity\Menu::load('top-right-navbar-br') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-right-navbar-br',
            'label' => 'Top right navbar BR',
            'description' => 'Top right navbar BR',
            'langcode'  => 'pt-br'
        ])
        ->save();
}

if (\Drupal\system\Entity\Menu::load('top-right-navbar-footer-br') == null) {
// Menu Corporate
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'top-right-navbar-footer-br',
            'label' => 'Top right navbar Footer BR',
            'description' => 'Right navbar\'s links to be displayed in the footer in mobile mode',
            'langcode'  => 'br'
        ])
        ->save();
}


##recharge de la config du block
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.toprightnavbarbr');
$config_group->setData(
    array (
        'uuid' => '0ea0ca19-d78b-4d35-ab54-c0462cadfcd8',
        'langcode' => 'pt-br',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-right-navbar-br',
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
        'id' => 'toprightnavbarbr',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -28,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-right-navbar-br',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-right-navbar-br',
                'label' => 'Top right navbar BR',
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




$config_group = $config_factory->getEditable('block.block.toprightnavbarfooterbr');
$config_group->setData(
    array (
        'uuid' => 'edf54396-c835-4c46-a404-d6371b9164d8',
        'langcode' => 'br',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.top-right-navbar-footer-br',
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
        'id' => 'toprightnavbarfooterbr',
        'theme' => 'theme_boosted',
        'region' => 'footer',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'system_menu_block:top-right-navbar-footer-br',
        'settings' =>
            array (
                'id' => 'system_menu_block:top-right-navbar-footer-br',
                'label' => 'Top right navbar Footer BR',
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
