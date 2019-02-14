<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *         RUBYPORTAILOBS-3465 [B-Insight] Création d'un nouveau champ visuel
 */

#lien du vocab inside type
$contentTypes = [
    "blog_post",
    "custom_page",
    "customer_story",
    "document",
    "full_html",
    "industry",
    "magazine",
    "press_kit",
    "press_release",
    "product",
    "simple_page",
    "solution"
];

$fieldName = "field_visual_tile";
$label = "Visual tile";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => $fieldName,
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_visual_tile.yml');

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
    oabt_YmlImport('field.field.node.'.$contentType.'.field_visual_tile.yml');
    oabt_YmlImport('core.entity_form_display.node.'.$contentType.'.default.yml');
    oabt_YmlImport('core.entity_view_display.node.'.$contentType.'.tile.yml');
}
