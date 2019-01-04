<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

// Voca Insight (dont le vid est 'thematic'
$vid = "thematic";


// Je supprime tous les anciens termes
/** @var Drupal\taxonomy\Entity\Term[] $terms */
$terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree($vid,0,NULL,TRUE);

foreach ($terms as $term) {
    $term->delete();
}

// J'ajoute les nouveaux
$new_terms = [
    "Blogs EN" =>          ['fr' => "Blogs"],
    "Débats EN" =>         ['fr' => "Débats"],
    "Atualités EN" =>      ['fr' => "Atualités"],
    "Témoignages EN" =>    ['fr' => "Témoignages"],
    "Dossier EN" =>        ['fr' => "Dossier"]
];


foreach ($new_terms as $base_term => $trads) {
    /** @var Drupal\taxonomy\Entity\Term $term */
    $term = Drupal\taxonomy\Entity\Term::create([
        'vid' => $vid,
        'name' => $base_term,
        'langcode' => 'en'
    ]);
    $term->save();

    foreach ( $trads as $lang => $value) {
       $term_translated = Drupal\taxonomy\Entity\Term::create([
            'vid' => $vid,
            'name' => $value,
            'langcode' => $lang
        ]);
        $term_translated->save();
    }

}

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


////////////////////////////////
/// Ajout du field aux elements
///

$bundles = ["custom_page", "press_kit", "press_release", "product"];

foreach ($bundles as $bundle) {
    $field = FieldConfig::loadByName('node', $bundle, 'field_insight');
    if (empty($field)) {
        $config_array = array(
            'field_name' =>  'field_insight',
            'entity_type' => 'node',
            'bundle' => $bundle,
            'required' => false,
        );
        FieldConfig::create($config_array)->save();
    }

    oabt_YmlImport('field.field.node.' . $bundle . '.field_insight.yml');
    oabt_YmlImport('core.entity_form_display.node.' . $bundle . '.default.yml');
    oabt_YmlImport('core.entity_view_display.node.' . $bundle . '.default.yml');
}

