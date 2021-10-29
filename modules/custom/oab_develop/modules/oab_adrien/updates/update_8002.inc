<?php

//Rajout des 4 termes subhomes pour IoT


$terms = [
  //en
  [
    "language" => "en",
    "name" => "IoT Achievements",
    "display" => "page_achievements_iot",
    "variable" => "achievement_term_tid"
  ],
  [
    "language" => "en",
    "name" => "IoT Products",
    "display" => "page_products_iot",
    "variable" => "iot_product_term_tid"
  ],
  //fr
  [
    "language" => "fr",
    "name" => "Réalisation IoT",
    "display" => "page_achievements_iot",
    "variable" => "achievement_term_tid"
  ],
  [
    "language" => "fr",
    "name" => "Produits IoT",
    "display" => "page_products_iot",
    "variable" => "iot_product_term_tid"
  ],
];

$config = [];


foreach ($terms as &$term) {
  $term_id = "";
//vérification de l'existance du terme pour ce vocabulaire

//  $query = \Drupal::entityQuery('taxonomy_term');
//  $query->condition('vid', "subhomes");
//  $query->condition('langcode', $term['language']);
//  $query->condition('name', $term['name']);
//  $entity = $query->execute();
//

  /** @var \Drupal\Core\Entity\EntityTypeManager $entity_type_manager */
  $entity_type_manager = \Drupal::entityTypeManager();

  $entity = $entity_type_manager->getStorage('taxonomy_term')->loadByProperties(
    [
      'vid' => "subhomes",
      'langcode' => $term['language'],
      'name' => $term['name']
    ]
  );


  if (!isset($entity) || empty($entity)) {
    $entity = \Drupal\taxonomy\Entity\Term::create([
      'vid' => "subhomes",
      'name' => $term['name'],
      'langcode' => $term['language'],
      'field_related_display_view' => $term['display']
    ]);
    $entity->save();
    $term_id = $entity->id();
  } else {
    $term_id = key($entity);
  }

  $config[$term['language']][$term['variable']] = $term_id;

}

//  ##On crée les champs en anglais
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->set('achievement_term_tid', $config['en']['achievement_term_tid']);
$config_group->set('iot_product_term_tid', $config['en']['iot_product_term_tid']);
$config_group->set('iot_achievement_meta', 'IoT Achievements');
$config_group->set('iot_product_meta', 'IoT Products');
$config_group->save();

# Config fr => Je charge la collection déjà existante, je rajoute nos champs, puis je la save
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$config_fr = $collection->read('oab_subhomes.subhomes');
$config_fr['achievement_term_tid'] = $config['fr']['achievement_term_tid'];
$config_fr['iot_product_term_tid'] = $config['fr']['iot_product_term_tid'];
$config_fr['iot_achievement_meta'] = 'Réalisation IoT';
$config_fr['iot_product_meta'] = 'Produits IoT';
$collection->write('oab_subhomes.subhomes', $config_fr);

## Rechargement de la conf des subhomes pour ajouter la nouvelle subhome
oabt_YmlImport('views.view.subhomes.yml');

\Drupal::service('path.alias_storage')->save("/subhome_iot_achievement", "/solutions/iot/customer-stories", "en");
\Drupal::service('path.alias_storage')->save("/subhome_iot_achievement", "/solutions/iot/temoignages-clients", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_iot_products", "/solutions/iot/products", "en");
\Drupal::service('path.alias_storage')->save("/subhome_iot_products", "/solutions/iot/produits", "fr");
