<?php

$new_terms = [
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Track and geolocate objects'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'Manage and collect data'
  ],
  [
    'vid' => 'product_use_case',
    'language' => 'en',
    'name' => 'View information and organise resources'
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
    'name' => 'Afficher des informations et organiser des ressources'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Packaged solution'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Modular solution'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Connectivity'
  ],
  [
    'vid' => 'product_type',
    'language' => 'en',
    'name' => 'Center of excellence'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Solution packagée'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Solution modulaire'
  ],
  [
    'vid' => 'product_type',
    'language' => 'fr',
    'name' => 'Connectivité'
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
  kint($entity);
}


