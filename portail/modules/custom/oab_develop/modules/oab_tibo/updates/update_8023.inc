<?php

// suppression de la taxo products et de ses termes
$tids = \Drupal::entityQuery('taxonomy_term')
    ->condition('vid', 'products')
    ->execute();

if (count($tids) > 0) {
    $controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
    $entities = $controller->loadMultiple($tids);
    $controller->delete($entities);
}

$vid  = \Drupal\taxonomy\Entity\Vocabulary::load('products');
$vid->delete();
drupal_set_message('Taxonomie produits supprimée');

// suppression de la taxo Sub families et de ses termes
$tids = \Drupal::entityQuery('taxonomy_term')
    ->condition('vid', 'sub_families')
    ->execute();

if (count($tids) > 0) {
    $controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
    $entities = $controller->loadMultiple($tids);
    $controller->delete($entities);
}

$vid  = \Drupal\taxonomy\Entity\Vocabulary::load('sub_families');
$vid->delete();
drupal_set_message('Taxonomie sous famille supprimée');

