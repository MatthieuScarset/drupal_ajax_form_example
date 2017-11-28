<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\node\Entity\NodeType;

##Création type de contenu Distributeur
$nodeStorage = NodeType::load('distributor');
if(empty($nodeStorage)) {
    $nodeType = NodeType::create([
        'name' => 'Distributor',
        'type' => 'distributor',
    ]);
    $nodeType->save();
}

//yml node.type.distributor.yml
oabt_YmlImport("node.type.distributor.yml");

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.distributor', array (
    'label' => 'Distributeur',
));


##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', 'field_certification_obs');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_certification_obs',
        'entity_type' => 'node',
        'type' => 'boolean',
    ))->save();
}
oabt_YmlImport("field.storage.node.field_certification_obs.yml");

$field = FieldConfig::loadByName('node', 'distributor', 'field_certification_obs');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_certification_obs',
        'entity_type' => 'node',
        'bundle' => 'distributor',
        'label' => 'Certification OBS',
        'description' => '',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport("field.field.node.distributor.field_certification_obs.yml");


$field_storage = FieldStorageConfig::loadByName('node', 'field_logo');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_logo',
        'entity_type' => 'node',
        'type' => 'image',
    ))->save();
}
oabt_YmlImport("field.storage.node.field_logo.yml");

$field = FieldConfig::loadByName('node', 'distributor', 'field_logo');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_logo',
        'entity_type' => 'node',
        'bundle' => 'distributor',
        'label' => 'Logo',
        'description' => '',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport("field.field.node.distributor.field_logo.yml");


$field_storage = FieldStorageConfig::loadByName('node', 'field_departments');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_departments',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport("field.storage.node.field_departments.yml");

$field = FieldConfig::loadByName('node', 'distributor', 'field_departments');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_departments',
        'entity_type' => 'node',
        'bundle' => 'distributor',
        'label' => 'Departments',
        'description' => '',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport("field.field.node.distributor.field_departments.yml");


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.distributor.field_departments', array (
    'label' => 'Départements',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.distributor.field_market_segment', array (
    'label' => 'Segment de marché',
));

##Distributor's existing fields

oabt_YmlImport("field.field.node.distributor.field_additionnal.yml");
oabt_YmlImport("field.field.node.distributor.field_city.yml");
oabt_YmlImport("field.field.node.distributor.field_email_address.yml");
oabt_YmlImport("field.field.node.distributor.field_highlight.yml");
oabt_YmlImport("field.field.node.distributor.field_market_segment.yml");
oabt_YmlImport("field.field.node.distributor.field_meta_description.yml");
oabt_YmlImport("field.field.node.distributor.field_meta_title.yml");
oabt_YmlImport("field.field.node.distributor.field_navigation_link.yml");
oabt_YmlImport("field.field.node.distributor.field_phone_number.yml");
oabt_YmlImport("field.field.node.distributor.field_postal_code.yml");
oabt_YmlImport("field.field.node.distributor.field_solution.yml");
oabt_YmlImport("field.field.node.distributor.field_street.yml");


$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.distributor.field_postal_code', array (
    'label' => 'code Postal',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.distributor.field_street', array (
    'label' => 'Rue',
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.distributor.field_phone_number', array (
    'label' => 'Numéro de téléphone',
));

##Distributor's view
oabt_YmlImport("core.entity_form_display.node.distributor.default.yml");
oabt_YmlImport("core.entity_view_display.node.distributor.default.yml");
