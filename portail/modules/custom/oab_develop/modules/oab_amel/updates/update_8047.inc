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

if (\Drupal\system\Entity\Menu::load('main-navigation-br') == null) {
// Menu Navigation PT
    \Drupal::entityTypeManager()
        ->getStorage('menu')
        ->create([
            'id' => 'main-navigation-br',
            'label' => 'Main navigation BR',
            'description' => 'PT Site section links',
            'langcode'  => 'pt-br'
        ])
        ->save();
}

oabt_YmlImport('block.block.mainnavigationbr.yml');


oabt_YmlImport('block.block.mainnavigationes.yml');

