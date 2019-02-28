<?php

/**
 * Ajout d'une taxo Document Language et d'un field dédié dans les documents pour choisir la langue
 */

use Drupal\taxonomy\Entity\Vocabulary;
use Drupal\taxonomy\Entity\Term;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;


## Création du vocabulaire
$voca_id = "document_language";
$voca = Vocabulary::load($voca_id);
if ($voca === null) {
    $voca = Vocabulary::create([
        'vid' => $voca_id,
        'name' => 'Document language',
        'langcode' => 'en'
    ]);
    $voca->save();
}
oabt_YmlImport('taxonomy.vocabulary.document_language.yml');


## Ajout des termes
$terms_name = ['English', 'Chinese'];
foreach ($terms_name as $term_name) {
    $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties([
        'vid' => $voca_id,
        'name' => $term
    ]);

    if (count($term) === 0) {
        $term = Term::create([
            'vid' => $voca_id,
            'langcode' => 'en',
            'name' => $term_name
        ]);
        $term->save();
    }
}



## Création du field
$field_storage = FieldStorageConfig::loadByName('node', 'field_document_language');
if (empty($field_storage)) {
    $field_storage = FieldStorageConfig::create(array(
        'field_name' => 'field_document_language',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ));
    $field_storage->save();
}
oabt_YmlImport('field.storage.node.field_document_language.yml');

## Ajout du field aux documents
$fieldConfig = FieldConfig::loadByName('node', 'document', 'field_document_language');
if (empty($fieldConfig)) {
    $fieldConfig = FieldConfig::create(array(
        'field_name' => 'field_document_language',
        'entity_type' => 'node',
        'bundle' => 'document',
        'field_type' => 'entity_reference'
    ));
    $fieldConfig->save();
}
oabt_YmlImport('field.field.node.document.field_document_language.yml');


oabt_YmlImport('core.entity_view_display.node.document.default.yml');
oabt_YmlImport('core.entity_form_display.node.document.default.yml');



oabt_YmlImport('views.view.subhomes.yml');
