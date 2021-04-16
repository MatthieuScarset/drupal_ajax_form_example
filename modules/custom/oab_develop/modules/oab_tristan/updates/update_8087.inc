<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


// Suppression du field "field_thematic" qui était en doublon par rapport au field field_insight et n'était utilisé dans
// aucun type de contenu
$bundles = ["blog_post", "customer_story", "document", "magazine", "press_kit", "press_release", "simple_page"];

foreach ($bundles as $bundle) {
    // Deleting field.
    $conf = FieldConfig::loadByName('node', $bundle, 'field_thematic');
    if ($conf !== null) {
        $conf->delete();
    }
}


// Deleting field storage.
$fieldStorage = FieldStorageConfig::loadByName('node', 'field_thematic');
if ($fieldStorage !== null) {
    $fieldStorage->delete();
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Suppression du voca "Insight type" qui n'est utilisé nul part
$vid = "insight_types";

// Je supprime tous les anciens termes
/** @var Drupal\taxonomy\Entity\Term[] $terms */
$terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree($vid,0,NULL,TRUE);

foreach ($terms as $term) {
    $term->delete();
}
$voca = Drupal\taxonomy\Entity\Vocabulary::load($vid);
if ($voca !== null) {
    $voca->delete();
}

