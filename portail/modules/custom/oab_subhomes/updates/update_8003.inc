<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

// Création du field pour l'aplat dans le press kit
$field_storage = FieldStorageConfig::loadByName('node', 'field_aplat');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_aplat',
        'entity_type' => 'node',
        'type' => 'list_string',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_aplat.yml');
oabt_YmlImport('field.field.node.press_kit.field_aplat.yml');
oabt_YmlImport('core.entity_view_display.node.press_kit.default.yml');
oabt_YmlImport('core.entity_view_display.node.press_kit.subhome.yml');
oabt_YmlImport('core.entity_form_display.node.press_kit.default.yml');
