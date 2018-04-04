<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

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
oab_hub_ymlImport('taxonomy.vocabulary.hub.yml');
oab_hub_ymlImport('language.content_settings.taxonomy_term.hub.yml');

###################################
## Ajout des fields au vocabulaire

## Liste des blocs
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_blocs' );
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_blocs',
        'field_name' => 'field_hub_blocs',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oab_hub_ymlImport('field.storage.taxonomy_term.field_hub_blocs.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_blocs');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_blocs',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Blocs du hub',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oab_hub_ymlImport('field.field.taxonomy_term.hub.field_hub_blocs.yml');


## Liste des menus
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_menus' );
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_menus',
        'field_name' => 'field_hub_menus',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oab_hub_ymlImport('field.storage.taxonomy_term.field_hub_menus.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_menus');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_menus',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Menus du hub',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oab_hub_ymlImport('field.field.taxonomy_term.hub.field_hub_menus.yml');

## liste des subhomes
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_subhomes' );
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_subhomes',
        'field_name' => 'field_hub_subhomes',
        'entity_type' => 'taxonomy_term',
        'type' => 'entity_reference',
    ))->save();
}
oab_hub_ymlImport('field.storage.taxonomy_term.field_hub_subhomes.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_subhomes');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_subhomes',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'Subhomes du hub',
        'required' => true,
    );
    FieldConfig::create($config_array)->save();
}
oab_hub_ymlImport('field.field.taxonomy_term.hub.field_hub_subhomes.yml');


## URL des contenus
$field_storage = FieldStorageConfig::loadByName('taxonomy_term','field_hub_url' );
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'taxonomy_term.field_hub_url',
        'field_name' => 'field_hub_url',
        'entity_type' => 'taxonomy_term',
        'type' => 'string',
    ))->save();
}
oab_hub_ymlImport('field.storage.taxonomy_term.field_hub_url.yml');

$field = FieldConfig::loadByName('taxonomy_term', 'hub', 'field_hub_url');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_hub_url',
        'entity_type' => 'taxonomy_term',
        'bundle' => 'hub',
        'label' => 'URL du hub',
        'required' => true,
    );
    FieldConfig::create($config_array)->save();
}
oab_hub_ymlImport('field.field.taxonomy_term.hub.field_hub_url.yml');


## Load des entity displays views et form display views
oab_hub_ymlImport('core.entity_form_display.taxonomy_term.hub.default.yml');

