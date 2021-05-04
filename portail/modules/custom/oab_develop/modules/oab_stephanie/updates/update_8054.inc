<?php
$geolocation_terms = [
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'France',
      'geolocation' => [ 'lat' => '46.227638', 'long' => '2.213749']
    ],
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'Europe',
      'geolocation' => [ 'lat' => '54.525961', 'long' => '15.255119']
    ],
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'USA',
      'geolocation' => [ 'lat' => '37.090240', 'long' => '-95.712891']
    ],
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'Latin America',
      'geolocation' => [ 'lat' => '-14.242914500000001', 'long' => '-53.1892665']
    ],
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'Africa',
      'geolocation' => [ 'lat' => '14.842924079257289', 'long' => '17.32976836043403']
    ],
    [
      'vid' => 'location',
      'language' => 'en',
      'name' => 'Asia Pacific',
      'geolocation' => [ 'lat' => '-2.5187220000000003', 'long' => '118.01556799999997']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'France',
      'geolocation' => [ 'lat' => '46.227638', 'long' => '2.213749']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'Europe',
      'geolocation' => [ 'lat' => '54.525961', 'long' => '15.255119']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'États-Unis',
      'geolocation' => [ 'lat' => '37.090240', 'long' => '-95.712891']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'Amérique latine',
      'geolocation' => [ 'lat' => '-14.242914500000001', 'long' => '-53.1892665']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'Afrique',
      'geolocation' => [ 'lat' => '14.842924079257289', 'long' => '17.32976836043403']
    ],
    [
      'vid' => 'location',
      'language' => 'fr',
      'name' => 'Asie Pacifique',
      'geolocation' => [ 'lat' => '-2.5187220000000003', 'long' => '118.01556799999997']
    ]
  ];

foreach ($geolocation_terms as $term)
{
  $entity_type_manager = \Drupal::entityTypeManager();
  $entities = $entity_type_manager->getStorage('taxonomy_term')->loadByProperties(
    [
      'vid' => $term['vid'],
      'langcode' => $term['language'],
      'name' => $term['name']
    ]
  );

  if (isset($entities) && !empty($entities)) {
    foreach ( $entities as $tid => $termObj ){
      $termObj->set('field_location', array('lat' => $term['geolocation']['lat'], 'lng' => $term['geolocation']['long']));
      $termObj->save();
    }
  }
}
