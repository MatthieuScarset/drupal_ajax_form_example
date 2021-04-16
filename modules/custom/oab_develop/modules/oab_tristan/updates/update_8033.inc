<?php
/**
 * Suppression de taxos
 */
$vocaList = [
  "solutions" => [
    "Espace collaboratifs",
    "IT Flexible Mobile Workspace"
  ],
];

foreach ($vocaList as $voca => $termlist) {
  foreach ($termlist as $key => $term) {
    ##on cherche l'Objet
    $termsArray = taxonomy_term_load_multiple_by_name($term, $voca);
    ##Je supprime les termes trouvés
    foreach ($termsArray as $termObject) {
      $termObject->delete();
    }
  }
}