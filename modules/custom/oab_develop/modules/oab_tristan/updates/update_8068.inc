<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * Ajout de 2 boutons avec leur lien et leur text pour TopZone Banner Et Solution Banner
 * Ajout d'un select pour la couleur du texte de la Solution Banner
 */

##########################################
##########################################
######## Création des fields et field storage


##################
## HOMEPAGE TITLE
##Texte bouton
$field_storage = FieldStorageConfig::loadByName('node','field_title_btn_text' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_title_btn_text',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_title_btn_text.yml');

$field = FieldConfig::loadByName('node', 'homepage', 'field_title_btn_text');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_title_btn_text',
        'entity_type' => 'node',
        'bundle' => 'homepage',
        'label' => 'Title button text',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.node.homepage.field_title_btn_text.yml');

#lien du bouton
$field_storage = FieldStorageConfig::loadByName('node','field_title_button_link' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_title_button_link',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_title_button_link.yml');

$field = FieldConfig::loadByName('node', 'homepage', 'field_title_button_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_title_button_link',
        'entity_type' => 'node',
        'bundle' => 'homepage',
        'label' => 'Title button link',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.node.homepage.field_title_button_link.yml');


###########################
## HOMEPAGE SOLUTION BANNER
##Texte bouton
$field_storage = FieldStorageConfig::loadByName('node','field_solution_banner_btn_text' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_solution_banner_btn_text',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_solution_banner_btn_text.yml');

$field = FieldConfig::loadByName('node', 'homepage', 'field_solution_banner_btn_text');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_solution_banner_btn_text',
        'entity_type' => 'node',
        'bundle' => 'homepage',
        'label' => 'Solution banner button text',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.node.homepage.field_solution_banner_btn_text.yml');

##Lien du bouton
$field_storage = FieldStorageConfig::loadByName('node','field_solution_banner_btn_link' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_solution_banner_btn_link',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_solution_banner_btn_link.yml');

$field = FieldConfig::loadByName('node', 'homepage', 'field_solution_banner_btn_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_solution_banner_btn_link',
        'entity_type' => 'node',
        'bundle' => 'homepage',
        'label' => 'Solution banner button link',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.node.homepage.field_solution_banner_btn_link.yml');

##Couleur du titre de la banniere
$field_storage = FieldStorageConfig::loadByName('node','field_solution_banner_title_colo' );
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_solution_banner_title_colo',
        'entity_type' => 'node',
        'type' => 'list_string',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_solution_banner_title_colo.yml');

$field = FieldConfig::loadByName('node', 'homepage', 'field_solution_banner_title_colo');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_solution_banner_title_colo',
        'entity_type' => 'node',
        'bundle' => 'homepage',
        'label' => 'Solution banner title color',
        'required' => false,
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.node.homepage.field_solution_banner_title_colo.yml');





##Je recharge la HP : display view default & full + form display
oabt_YmlImport('core.entity_view_display.node.homepage.default.yml');
oabt_YmlImport('core.entity_view_display.node.homepage.full.yml');
oabt_YmlImport('core.entity_form_display.node.homepage.default.yml');