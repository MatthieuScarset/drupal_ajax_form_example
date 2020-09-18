<?php

/**
 * Création de la subhome actualité
 * Les 2 nouveaux terms + les 2 subhomes entités + les bons alias
 */

use Drupal\oab_subhomes\Entity\SubhomeEntity;
use Drupal\taxonomy\Entity\Term;

$langcodes = ['en', 'fr'];

foreach ($langcodes as $langcode) {
  $term_data = [
    'vid' => "subhomes",
    'label' => $label[$langcode],
    'langcode' => $langcode,
    'field_related_display_view' => "page_press"
  ];

  $term = Term::create($term_data);
  $term->save();

  $subome_data = [
    'type' => 'presse',
    'langcode' => $langcode,
    'name' => "News $langcode",
    'title' => "News",
    'description' => "Some news description",
    'subhome_id' => $term->id(),
    'field_afficher_bloc_notre_equipe' => false
  ];

  $subhome = SubhomeEntity::create($subome_data);
  $subhome->save();

}

$aliases = [
  [
    'system' => '/subhome-archive-news',
    'alias' => '/press/news',
    'lang' => 'en'
  ],
  [
    'system' => '/subhome-archive-news',
    'alias' => '/presse/actualites',
    'lang' => 'fr'
  ]
];

$path_service = \Drupal::service('path.alias_storage');
foreach ($aliases as $alias) {
  $path_service->save($alias['system'], $alias['alias'], $alias['lang']);
}


