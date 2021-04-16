<?php


/**
 * Mise à jour du field "field_related_display_view" pour tous les termes de la taxo Subhome
 * afin de faire fonctionner le fil d'Arianne
 */
$vocaList = [
  "jobs_profiles" => [
    "EN" => [
      "Communications Director",
    ]
  ],
  "industries"  => [
    "EN"  => [
      "Transport and Logistic",
    ]
  ],
  "solutions" => [
    "EN"  => [
      "Enriched Customer relationship"
    ]
  ],
  "document_types" => [
    "FR"  => [
      "Partenaires adhésion",

    ],
    "EN"  => [
      "Blogbook",
      "Partner Brief",
    ]
  ],
];


$doublons = [
  "solutions" => [
    "Enriched connectivity",
  ],
  "document_types"  => [
    "White paper"
  ]
];

foreach ($vocaList as $voca => $languageList) {
  foreach ($languageList as $language => $termlist) {
    foreach ($termlist as $key => $term) {
      ##on cherche l'Objet
      $termsArray = taxonomy_term_load_multiple_by_name($term, $voca);
      ##Je supprime les termes trouvés
      foreach ($termsArray as $termObject) {
        $termObject->delete();
      }
    }
  }
}

foreach ($doublons as $voca => $termlist) {
  foreach ($termlist as $key => $term) {
    ##on cherche l'Objet
    $termsArray = taxonomy_term_load_multiple_by_name($term, $voca);
    ##En cas de doublon à supprimer, je supprime le dernier
    if (count($termsArray) > 1) {
      $termsArray[1]->delete();
    }
  }
}


##Création des termes demandés
$term = \Drupal\taxonomy\Entity\Term::create([
  'name' => 'Connectivity',
  'vid' => 'document_thematics'
]);
$term->set('langcode', 'en');
$term->save();