<?php

$new_terms = [
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Tracking and geolocating objects'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Control and collect data'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Display information'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Optimize resources'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'fr',
    'name' => 'Suivre et géolocaliser les objets'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'fr',
    'name' => 'Piloter et collecter les données'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'fr',
    'name' => 'Afficher des informations'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'fr',
    'name' => 'Optimiser les ressources'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Packaged solutions'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => ' Modular solutions'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Connectivity'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Center of Excellence'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Solutions packagées'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Solutions modulaires'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Connectivités'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => "Centre d'excellence"
  ],
];
foreach ($new_terms as &$term) {

  /** @var \Drupal\Core\Entity\EntityTypeManager $entity_type_manager */
  $entity_type_manager = \Drupal::entityTypeManager();

  $entity = $entity_type_manager->getStorage('taxonomy_term')->loadByProperties(
    [
      'vid' => $term['vid'],
      'langcode' => $term['language'],
      'name' => $term['name']
    ]
  );

  if (!isset($entity) || empty($entity)) {
    $entity = \Drupal\taxonomy\Entity\Term::create([
      'vid' => $term['vid'],
      'name' => $term['name'],
      'langcode' => $term['language'],
    ]);
    $entity->save();
  }
}





