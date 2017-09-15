<?php

use Drupal\node\Entity\NodeType;

$content_types = NodeType::loadMultiple();
if (is_array($content_types) && !empty($content_types)) {
  foreach ($content_types AS $type_name => $type_object) {
    $config_factory = \Drupal::configFactory();
    $config_string = "core.entity_form_display.node." . $type_name . ".default";
    $config_group = $config_factory->getEditable($config_string);

    // ajout du champ "authored by" à tous les types de contenu
    $fieldAuthor = $config_group->get('content.uid');

    if (is_null($fieldAuthor)) {
      $config_group->set('content.uid', array(
        'type' => 'entity_reference_autocomplete',
        'weight' => 1,
        'region' => 'content',
        'settings' =>
          array(
            'match_operator' => 'CONTAINS',
            'size' => 60,
            'placeholder' => '',
          ),
        'third_party_settings' =>
          array(),
      ));
      $config_group->save(true);
    }

    // ajout du champ "authored on" à tous les types de contenu
    $fieldCreated = $config_group->get('content.created');

    if (is_null($fieldAuthor)) {
      $config_group->set('content.created', array(
        'type' => 'datetime_timestamp',
        'weight'=> 2,
        'region' => 'content',
        'settings' => array(),
        'third_party_settings' => array(),
      ));
      $config_group->save(true);
    }
  }
}