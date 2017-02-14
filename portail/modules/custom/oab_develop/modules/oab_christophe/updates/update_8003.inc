<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.default');
$config_group->set('content.field_file', array (
  'weight' => 111,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.default');
$config_group->set('content.field_file', array (
  'weight' => 105,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.default');
$config_group->set('content.field_file', array (
  'weight' => 103,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.default');
$config_group->set('content.field_file', array (
  'weight' => 106,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$config_group->set('content.field_file', array (
  'weight' => 103,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);

