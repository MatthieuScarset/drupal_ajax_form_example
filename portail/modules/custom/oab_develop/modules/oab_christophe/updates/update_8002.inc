<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.customer_story.default');
$config_group->set('content.field_file', array (
  'weight' => 9,
  'settings' =>
    array (
      'entity_browser' => 'browser_file_modal',
      'field_widget_display' => 'rendered_entity',
      'field_widget_edit' => true,
      'field_widget_remove' => true,
      'selection_mode' => 'selection_append',
      'field_widget_display_settings' =>
        array (
          'view_mode' => 'default',
        ),
      'open' => false,
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_browser_entity_reference',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.document.default');
$config_group->set('content.field_file', array (
  'weight' => 9,
  'settings' =>
    array (
      'entity_browser' => 'browser_file_modal',
      'field_widget_display' => 'rendered_entity',
      'field_widget_edit' => true,
      'field_widget_remove' => true,
      'selection_mode' => 'selection_append',
      'field_widget_display_settings' =>
        array (
          'view_mode' => 'default',
        ),
      'open' => false,
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_browser_entity_reference',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.partner.default');
$config_group->set('content.field_file', array (
  'weight' => 10,
  'settings' =>
    array (
      'entity_browser' => 'browser_file_modal',
      'field_widget_display' => 'rendered_entity',
      'field_widget_edit' => true,
      'field_widget_remove' => true,
      'selection_mode' => 'selection_append',
      'field_widget_display_settings' =>
        array (
          'view_mode' => 'default',
        ),
      'open' => false,
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_browser_entity_reference',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.press_kit.default');
$config_group->set('content.field_file', array (
  'weight' => 29,
  'settings' =>
    array (
      'entity_browser' => 'browser_file_modal',
      'field_widget_display' => 'rendered_entity',
      'field_widget_edit' => true,
      'field_widget_remove' => true,
      'selection_mode' => 'selection_append',
      'field_widget_display_settings' =>
        array (
          'view_mode' => 'default',
        ),
      'open' => false,
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_browser_entity_reference',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.press_release.default');
$config_group->set('content.field_file', array (
  'weight' => 12,
  'settings' =>
    array (
      'entity_browser' => 'browser_file_modal',
      'field_widget_display' => 'rendered_entity',
      'field_widget_edit' => true,
      'field_widget_remove' => true,
      'selection_mode' => 'selection_append',
      'field_widget_display_settings' =>
        array (
          'view_mode' => 'default',
        ),
      'open' => false,
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_browser_entity_reference',
));
$config_group->save(TRUE);


