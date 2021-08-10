<?php

/** @var  $location_new_terms
 * location new terms
 **/
$location_new_terms = [
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'France'
  ],
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'Europe'
  ],
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'USA'
  ],
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'Latin America'
  ],
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'Africa'
  ],
  [
    'vid' => 'location',
    'language' => 'en',
    'name' => 'Asia Pacific'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'France'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'Europe'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'États-Unis'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'Amérique latine'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'Afrique'
  ],
  [
    'vid' => 'location',
    'language' => 'fr',
    'name' => 'Asie Pacifique'
  ]
];

$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();

if (!isset($vocabularies['location'])) {
  $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
    'vid' => 'location',
    'name' => t('Location'),
  ));
  $vocabulary->save();
}

foreach ($location_new_terms as $term) {

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
