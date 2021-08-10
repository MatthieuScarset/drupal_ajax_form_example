<?php

/** @var  $service_providers_new_terms
 * type of cloud service new terms
 **/
$service_providers_new_terms = [
  [
    'vid' => 'service_providers',
    'language' => 'en',
    'name' => 'Orange offers'
  ],
  [
    'vid' => 'service_providers',
    'language' => 'en',
    'name' => 'Partner offers'
  ],
  [
    'vid' => 'service_providers',
    'language' => 'fr',
    'name' => 'Offres Orange'
  ],
  [
    'vid' => 'service_providers',
    'language' => 'fr',
    'name' => 'Offres partenaires'
  ]
];

$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();

if (!isset($vocabularies['service_providers'])) {
  $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
    'vid' => 'service_providers',
    'name' => t('Service providers'),
  ));
  $vocabulary->save();
}

foreach ($service_providers_new_terms as $term) {

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
