<?php

$storage = \Drupal::service('locale.storage');

#############################
#############################
##Ajouts de taxos ES / PT-BR pour le voca Région (En gros : trad des régions)
$termes = array(
    "Asia Pacific" => "Asia Pacific",
    "Middle East & Africa" => "Middle East & Africa",
    "Europe" => "Europe",
    "Latin America" => "Latin America",
    "North America" => "North America",
    "Russia" => "Russia"
);

foreach ($termes as $term => $trad) {
//    $termsArray = taxonomy_term_load_multiple_by_name($term, 'regions');

  // Correction depréciation pour exemple
  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $term, "vid" => "regions"]);
    foreach ($termsArray as $foundterm) {
        if (!empty($foundterm) && !$foundterm->hasTranslation('es')) {
            $entity_array = $foundterm->toArray();
            $translated_fields = [];
            $translated_fields['name'] = $trad;
            $translated_entity_array = array_merge($entity_array, $translated_fields);
            $foundterm->addTranslation('es', $translated_entity_array)->save();
        }
    }
}

foreach ($termes as $term => $trad) {
//    $termsArray = taxonomy_term_load_multiple_by_name($term, 'regions');
  // Correction depréciation pour exemple
  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $term, "vid" => "regions"]);
  
    foreach ($termsArray as $foundterm) {
        if (!empty($foundterm) && !$foundterm->hasTranslation('pt-br')) {
            $entity_array = $foundterm->toArray();
            $translated_fields = [];
            $translated_fields['name'] = $trad;
            $translated_entity_array = array_merge($entity_array, $translated_fields);
            $foundterm->addTranslation('pt-br', $translated_entity_array)->save();
        }
    }
}

