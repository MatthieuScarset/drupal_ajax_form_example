<?php


/**
 * Mise à jour du field "field_related_display_view" pour tous les termes de la taxo Subhome
 * afin de faire fonctionner le fil d'Arianne
 */
$termList = [
  "Blogs"                 => "page_blog",
  "Case studies"          => "page_customer",
  "Catalogue des offres"  => "page_catalogue",
  "Library"               => "page_document",
  "Magazine"              => "page_magazine",
  "Médiathèque"           => "page_document",
  "Newsroom"              => "page_press",
  "Partenaires"           => "page_partners",
  "Partners"              => "page_partners",
  "Press"                 => "page_press",
  "Presse"                => "page_press",
  "Products"              => "page_products",
  "Projects"              => "page_customer",
  "Témoignages clients"   => "page_customer",
  "Блоги"                 => "page_blog",
  "Новости"               => "page_press",
  "Партнеры"              => "page_partners",
  "Проекты"               => "page_customer",
  "Услуги"                => "page_products"
];

##On boucle sur tous les termes de la taxo Subhomes
foreach ($termList as $taxoTerm => $view) {

  ##on cherche l'Objet
//  $termsArray = taxonomy_term_load_multiple_by_name($taxoTerm, "subhomes");
  // Correction depréciation pour exemple
  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $taxoTerm, "vid" => "subhomes"]);

  ##On boucle sur tous les termes trouvés (Magazine par exemple..)
  foreach ($termsArray as $term_id => $termObject) {
  #related_display_view
  $termObject->set('field_related_display_view', $view);

  $termObject->save();

  }
}
