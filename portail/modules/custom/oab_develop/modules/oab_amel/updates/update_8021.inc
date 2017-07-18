<?php

use Drupal\field\Entity\FieldConfig;

$field = FieldConfig::loadByName('node', 'industry', 'field_meta_title');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_title',
'entity_type' => 'node',
'bundle' => 'industry',
'label' => 'Meta title',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'solution', 'field_meta_title');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_title',
'entity_type' => 'node',
'bundle' => 'solution',
'label' => 'Meta title',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'region', 'field_meta_title');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_title',
'entity_type' => 'node',
'bundle' => 'region',
'label' => 'Meta title',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'country', 'field_meta_title');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_title',
'entity_type' => 'node',
'bundle' => 'country',
'label' => 'Meta title',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'industry', 'field_meta_description');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_description',
'entity_type' => 'node',
'bundle' => 'industry',
'label' => 'Meta description',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'solution', 'field_meta_description');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_description',
'entity_type' => 'node',
'bundle' => 'solution',
'label' => 'Meta description',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'region', 'field_meta_description');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_description',
'entity_type' => 'node',
'bundle' => 'region',
'label' => 'Meta description',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('node', 'country', 'field_meta_description');
if(empty($field)) {
$config_array = array(
'field_name' =>  'field_meta_description',
'entity_type' => 'node',
'bundle' => 'country',
'label' => 'Meta description',
'required' => TRUE,
);
FieldConfig::create($config_array)->save();
}