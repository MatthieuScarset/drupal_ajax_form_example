<?php

/**
 * MAJ du field "related_display_view" des termes de subhomes "Products" en EN et RU
 */
$termList = [
  "Products"              => "page_catalogue",
  "Услуги"                => "page_catalogue"
];

##On boucle sur tous les termes de la taxo Subhomes
foreach ($termList as $taxoTerm => $view) {

  ##on cherche l'Objet
  $termsArray = taxonomy_term_load_multiple_by_name($taxoTerm, "subhomes");

  ##On boucle sur tous les termes trouvés (Magazine par exemple..)
  foreach ($termsArray as $term_id => $termObject) {
    #related_display_view
    $termObject->set('field_related_display_view', $view);

    $termObject->save();

  }
}