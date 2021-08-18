<?php

/** @var  $tocs_new_terms
 * type of cloud service new terms
 **/
$tocs_new_terms = [
  [
    'vid' => 'type_of_cloud_service',
    'language' => 'en',
    'name' => 'IaaS'
  ],
  [
    'vid' => 'type_of_cloud_service',
    'language' => 'en',
    'name' => 'SaaS'
  ],
  [
    'vid' => 'type_of_cloud_service',
    'language' => 'fr',
    'name' => 'IaaS'
  ],
  [
    'vid' => 'type_of_cloud_service',
    'language' => 'fr',
    'name' => 'SaaS'
  ]
];

$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();

if (!isset($vocabularies['type_of_cloud_service'])) {
  $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
    'vid' => 'type_of_cloud_service',
    'name' => t('Type of cloud service'),
  ));
  $vocabulary->save();
}

foreach ($tocs_new_terms as $term) {

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
