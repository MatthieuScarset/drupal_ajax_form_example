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
      "Transport  and Logistic",
    ]
  ],
  "solutions" => [
    "EN"  => [
      "enriched-connectivity-0" => "Enriched connectivity",
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
      "white-paper-0" => "White paper"
    ]

  ],
];
$i = 0;
foreach ($vocaList as $voca => $languageList) {
  foreach ($languageList as $language => $termlist) {
    foreach ($termlist as $key => $term) {
      ##on cherche l'Objet
      echo $voca . " => " . $term . "\n";
      $termsArray = taxonomy_term_load_multiple_by_name($term, $voca);
      foreach ($termsArray as $term_id => $termObject) {
        $name = $termObject->get('name');
        var_dump($name);
        $lang = $termObject["langcode"];

        echo "$lang \n";
      }
    }
  }
}