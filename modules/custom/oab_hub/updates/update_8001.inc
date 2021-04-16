<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use \Drupal\oab_hub\Controller\OabHubController;

$config_factory = \Drupal::configFactory();

## Je set à vide la config des urls du hub pour qu'il save un tableau
$url_liste = \Drupal::config(OabHubController::CONFIG_ID)
    ->get(OabHubController::CONFIG_URL_LIST);

if (empty($url_liste) || $url_liste === NULL) {
    $config_factory->getEditable(OabHubController::CONFIG_ID)
        ->set(OabHubController::CONFIG_URL_LIST, array())
        ->save(true);
}



$subhome_to_remove = [
    ['name'=>'Products DVI'],
    ['name'=>'Produits DVI'],
    ['name'=>'Distributeurs'],
    ['name'=>'Distributors']
];
$removed_tids = [];

foreach ($subhome_to_remove as $properties) {
    $terms = \Drupal::entityManager()->getStorage('taxonomy_term')->loadByProperties($properties);
    $term = reset($terms);
    if ($term !== false && $term !== null) {
        $removed_tids[] = $term->id();
    }

}
$config_factory->getEditable(OabHubController::CONFIG_ID)
    ->set(OabHubController::CONFIG_FORM_REMOVED_SUBHOMES_TIDS, $removed_tids)
    ->save(true);


/**
 * Création du vocabulaire "hub"
 */
$vid = "hub";
$name = "Hub";
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies[$vid])) {
    $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
        'vid' => $vid,
        'description' => 'gestion des mini-site',
        'name' => $name,
        'langcode'  => 'en'
    ));
    $vocabulary->save();
}
oabt_YmlImport('taxonomy.vocabulary.hub.yml');
oabt_YmlImport('language.content_settings.taxonomy_term.hub.yml');

###################################
## Ajout des fields au vocabulaire

## Liste des blocs
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_blocs' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_blocs',
        'field_name' => 'field_hub_blocs',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.taxonomy_term.field_hub_blocs.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_blocs');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_blocs',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Blocs du hub',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.taxonomy_term.hub.field_hub_blocs.yml');


## Liste des menus
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_menus' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_menus',
        'field_name' => 'field_hub_menus',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.taxonomy_term.field_hub_menus.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_menus');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_menus',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Menus du hub',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.taxonomy_term.hub.field_hub_menus.yml');

## liste des subhomes
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_subhomes' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_subhomes',
        'field_name' => 'field_hub_subhomes',
        'entity_type' => 'taxonomy_term',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.taxonomy_term.field_hub_subhomes.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_subhomes');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_subhomes',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Subhomes du hub',
        'required' => true,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.taxonomy_term.hub.field_hub_subhomes.yml');


## URL des contenus
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_url' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_url',
        'field_name' => 'field_hub_url',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.taxonomy_term.field_hub_url.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_url');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_url',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'URL du hub',
        'required' => true,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.taxonomy_term.hub.field_hub_url.yml');

## Suffixe des machines names
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_machine_name_suffixe' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_machine_name_suffixe',
        'field_name' => 'field_hub_machine_name_suffixe',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.taxonomy_term.field_hub_machine_name_suffixe.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_machine_name_suffixe');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_machine_name_suffixe',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Suffixe des machine-names',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.taxonomy_term.hub.field_hub_machine_name_suffixe.yml');

## Load des entity displays views et form display views
oabt_YmlImport('core.entity_form_display.taxonomy_term.hub.default.yml');
oabt_YmlImport('core.entity_view_display.taxonomy_term.hub.default.yml');

