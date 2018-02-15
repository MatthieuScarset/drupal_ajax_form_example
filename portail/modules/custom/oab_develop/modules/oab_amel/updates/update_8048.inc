<?php

/******** Création du MENU footer-es ***********/
//footer-es

if (\Drupal\system\Entity\Menu::load('footer-es') == null) {
// Menu Navigation ES
\Drupal::entityTypeManager()
->getStorage('menu')
->create([
'id' => 'footer-es',
'label' => 'Footer ES',
'description' => 'ES footer',
'langcode'  => 'es'
])
->save();
}

/******** Création du MENU footer-br ***********/

if (\Drupal\system\Entity\Menu::load('footer-br') == null) {
// Footer BR
\Drupal::entityTypeManager()
->getStorage('menu')
->create([
'id' => 'footer-br',
'label' => 'Footer BR',
'description' => 'Footer BR',
'langcode'  => 'pt-br'
])
->save();
}

oabt_YmlImport('block.block.footerbr.yml');

oabt_YmlImport('block.block.footeres.yml');

