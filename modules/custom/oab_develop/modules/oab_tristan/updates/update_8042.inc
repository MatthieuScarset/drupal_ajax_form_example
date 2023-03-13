<?php

##Modification de la traduction du field "Document thematic" dans les contenus Document
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.document.field_document_thematic',
  array (
    'label' => 'Thème',
  )
);


##Suppression d'un term de taxo
$vocaList = [
  "partner_types" => [
    "System Integrators",
  ],
];

foreach ($vocaList as $voca => $termlist) {
  foreach ($termlist as $key => $term) {
    ##on cherche l'Objet
//    $termsArray = taxonomy_term_load_multiple_by_name($term, $voca);

    $termsArray = \Drupal::entityTypeManager()
      ->getStorage("taxonomy_term")
      ->loadByProperties(["name" => $term, "vid" => $voca]);

    ##Je supprime les termes trouvés
    foreach ($termsArray as $termObject) {
      $termObject->delete();
    }
  }
}
