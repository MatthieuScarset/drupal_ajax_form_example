<?php

/******** Création du MENU menu-main-navigation-es ***********/
//main-navigation-es

if (\Drupal\system\Entity\Menu::load('main-navigation-es') == null) {
// Menu Navigation ES
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'main-navigation-es',
            'label' => 'Main navigation ES',
            'description' => 'ES Site section links',
            'langcode'  => 'es'
        ])
        ->save();
}

/******** Création du MENU menu-main-navigation-pt ***********/

if (\Drupal\system\Entity\Menu::load('main-navigation-pt') == null) {
// Menu Navigation PT
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'main-navigation-pt',
            'label' => 'Main navigation PT',
            'description' => 'PT Site section links',
            'langcode'  => 'pt-pt'
        ])
        ->save();
}
