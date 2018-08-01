<?php
/**
 * Création d'un filed Wysiwig/champ libre pour la zone Rebond
 */
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

$contentTypes = [
  'blog_post',
  'customer_story',
  'document',
  'magazine',
  'partner',
  'press_release',
  'simple_page',
  'webform'
];

$fieldName = "field_wysiwyg_rebond";
$label = "Wysiwyg rebond";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => $fieldName,
    'entity_type' => 'node',
    'type' => 'text_long',
  ))->save();
}
foreach ($contentTypes as $contentType) {
  $field = FieldConfig::loadByName('node', $contentType, $fieldName);
  if (empty($field)) {
    $config_array = array(
      'field_name' =>  $fieldName,
      'entity_type' => 'node',
      'bundle' => $contentType,
      'label' => $label,
      'required' => false,
    );
    FieldConfig::create($config_array)->save();
  }
}

##Mise en place du field dans les différents contenus
foreach ($contentTypes as $contentType) {
  oabt_YmlImport("field.field.node.$contentType.field_wysiwyg_rebond.yml");
  oabt_YmlImport("core.entity_view_display.node.$contentType.default.yml");
  oabt_YmlImport("core.entity_form_display.node.$contentType.default.yml");
}

#Mise en place du bloc
oabt_YmlImport("block.block.zonerebondwysiwyg.yml");