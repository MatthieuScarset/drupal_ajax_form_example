<?php

$new_terms = [
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Account settings'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Billing'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Changes'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Documents'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'General Data Protection'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Incidents & Events'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Maintenance'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Ordering'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Reporting'
  ],
  [
    'vid' => 'category_mss',
    'language' => 'en',
    'name' => 'Solutions'
  ],

];

$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies['category_mss'])) {
  $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
    'vid' => 'category_mss',
    'name' => t('Category MSS'),
  ));
  $vocabulary->save();
}


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
      'langcode' => $term['language'],
      'name' => $term['name'],
    ]);
    $entity->save();
  }
}





