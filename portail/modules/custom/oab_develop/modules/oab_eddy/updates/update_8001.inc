<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\locale\SourceString;

/**
 *  Création taxo analyste + ajout aux simples pages
 */


$storage = \Drupal::service('locale.storage');

$translations = [
    ['source' => "Analyst", "translation" => [ "fr" =>"Analyste"]] //Tableau des termes à traduire
];

// On va chercher la traduction
foreach ($translations AS $translation) {
    $string = $storage->findString(array(
            'source' => $translation['source'])
    );

    //Si elle n'existe pas, on l'a crée
    if (is_null($string)) {
        $string = new SourceString();
        $string->setString($translation['source']);
        $string->setStorage($storage);
        $string->save();
    }

    foreach ($translation['translation'] AS $language => $translated_string) {
        // Create translation. If one already exists, it will be replaced.
        $translation = $storage->createTranslation(array(
            'lid' => $string->lid,
            'language' => $language,
            'translation' => $translated_string
        ))->save();
    }
}


$voc_id = "analyst";
$voc_name = "Analyst";
$terms = ['Frost & Sullivan', 'Gartner', 'GlobalData', 'IDC', 'Ovum Decision Matrix', 'The Forrester Wave', 'Vertical Systems Group'];

//On va charger les termes
$voc_entity = \Drupal\taxonomy\Entity\Vocabulary::load($voc_id);
if ($voc_entity === null) {
    $voc_entity = \Drupal\taxonomy\Entity\Vocabulary::create([
        'vid' => $voc_id,
        'name' => $voc_name
    ])->save();
}

oabt_YmlImport('taxonomy.vocabulary.analyst.yml');


foreach($terms as $term) {
    $query = \Drupal::entityQuery('taxonomy_term');
    $query->condition('vid', $voc_id);
    $query->condition('langcode', 'en');
    $query->condition('name', $term);
    $entity = $query->execute();

    if (!isset($entity) || empty($entity)) {
        //s'il n'existe pas on le crée
        $entity = \Drupal\taxonomy\Entity\Term::create([
            'vid' => $voc_id,
            'name' => $term,
            'langcode' => 'en'
        ]);
        $entity->save();
    }
}


$field_id = "node.field_analysts";
$field_name = "field_analysts";
$field_type = 'entity_reference';

$field_storage = FieldStorageConfig::loadByName('node', $field_name);
if (empty($field_storage)) {
    $field_storage = FieldStorageConfig::create([
        'field_name' => $field_name,
        'entity_type' => 'node',
        'type' => $field_type,
     ]);

    $field_storage->save();
}

oabt_YmlImport('field.storage.node.field_analysts.yml');

$field = FieldConfig::loadByName('node', 'simple_page', $field_name);
if (empty($field)) {
    $config_array = [
        'field_name' => $field_name,
        'entity_type' => 'node',
        'bundle' => 'simple_page',
    ];

    FieldConfig::create($config_array)->save();
}

oabt_YmlImport('field.field.node.simple_page.field_analysts.yml');

oabt_YmlImport('core.entity_form_display.node.simple_page.default.yml');
oabt_YmlImport('core.entity_view_display.node.simple_page.default.yml');
oabt_YmlImport('views.view.subhomes.yml');
