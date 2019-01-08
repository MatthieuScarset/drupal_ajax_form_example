<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *             RUBYPORTAILOBS-3450 creation taxonomy insight_type
 */

$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies['insight_type']) ) {
    $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
        'vid' => 'insight_type',
        'name' => 'Insight type'
    ));
    $vocabulary->save();
}

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

$fieldName = "field_insight_type";
$label = "Insight type";

##Création du field et du field storage
$field_storage = FieldStorageConfig::loadByName('node', $fieldName);
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => $fieldName,
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_insight_type.yml');

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
    oabt_YmlImport('field.field.node.'.$contentType.'.field_insight_type.yml');
    oabt_YmlImport('core.entity_form_display.node.'.$contentType.'.default.yml');
}


