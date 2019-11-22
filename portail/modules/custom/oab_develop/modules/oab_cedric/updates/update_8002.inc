<?php

## Création du field block size
use Drupal\field\Entity\FieldConfig;
use Drupal\field\Entity\FieldStorageConfig;

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_block_size');
if (empty($field_storage)) {
  $field_storage = FieldStorageConfig::create(array(
    'field_name' => 'field_block_size',
    'entity_type' => 'paragraph',
    'type' => 'list_string',
  ));
  $field_storage->save();
}
oabt_YmlImport('field.field.storage.paragraph.field_block_size.yml');

$fieldConfig = FieldConfig::loadByName('paragraph', 'homepage_news', 'field_block_size');
if (empty($fieldConfig)) {
  $fieldConfig = FieldConfig::create(array(
    'field_name' => 'field_block_size',
    'entity_type' => 'paragraph',
    'bundle' => 'homepage_news',
    'field_type' => 'list_string'
  ));
  $fieldConfig->save();
}
oabt_YmlImport('field.field.paragraph.homepage_news.field_block_size.yml');


oabt_YmlImport("core.entity_form_display.paragraph.homepage_news.default.yml");
oabt_YmlImport("core.entity_form_display.paragraph.homepage_news.default.yml");
