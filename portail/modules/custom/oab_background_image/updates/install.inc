<?php

use Drupal\media_entity\Entity\Media;
use Drupal\media_entity\Entity\MediaBundle;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
## Création d'un type de media spécifique

$media_bundle = MediaBundle::load('background');
if ($media_bundle === null) {
    $media_bundle = MediaBundle::create([
        'langcode' => 'en',
        'id' => 'background',
        'label' => 'background',
        'type'  => 'image'
    ]);
    $media_bundle->save();
}
oabt_YmlImport('media_entity.bundle.background.yml');

// Field Image
$field_storage = FieldStorageConfig::loadByName('media', 'field_image');
if (empty($field_storage)) {
    $field_storage = FieldStorageConfig::create(array(
        'field_name' => 'field_image',
        'entity_type' => 'media',
        'type' => 'image',
    ));
    $field_storage->save();
}
oabt_YmlImport('field.storage.media.field_image.yml');

$field_image = FieldConfig::loadByName('media', 'background', 'field_image');
if (empty($field_image)) {
    $config_array = array(
        'field_name' => 'field_image',
        'entity_type' => 'media',
        'bundle' => 'background',
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.media.background.field_image.yml');

// Field Visibility
$field_storage_visibility = FieldStorageConfig::loadByName('media', 'field_visibility');
if (empty($field_storage_visibility)) {
    $field_storage_visibility = FieldStorageConfig::create(array(
        'field_name' => 'field_visibility',
        'entity_type' => 'media',
        'type' => 'string_long',
    ));
    $field_storage_visibility->save();
}
oabt_YmlImport('field.storage.media.field_visibility.yml');

$field_visibility = FieldConfig::loadByName('media', 'background', 'field_visibility');
if (empty($field_visibility)) {
    $config_array = array(
        'field_name' => 'field_visibility',
        'entity_type' => 'media',
        'bundle' => 'background',
    );
    FieldConfig::create($config_array)->save();
}
oabt_YmlImport('field.field.media.background.field_visibility.yml');

oabt_YmlImport('core.entity_form_display.media.background.default.yml');
oabt_YmlImport('core.entity_view_display.media.background.default.yml');
