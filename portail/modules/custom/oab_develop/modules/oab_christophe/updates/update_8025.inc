<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.solution.default');
$config_group->set('third_party_settings.field_group.group_write.children', array(
  0 => 'langcode',
  1 => 'title',
  2 => 'field_highlight',
  3 => 'field_top_zone',
  4 => 'field_top_zone_background',
  5 => 'field_local_nav',
  6 => 'field_content',
  7 => 'field_visual',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.industry.default');
$config_group->set('third_party_settings.field_group.group_write.children', array(
  0 => 'langcode',
  1 => 'title',
  2 => 'field_highlight',
  3 => 'field_top_zone',
  4 => 'field_top_zone_background',
  5 => 'field_local_nav',
  6 => 'field_content',
  7 => 'field_visual',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.region.default');
$config_group->set('third_party_settings.field_group.group_write.children', array(
  0 => 'langcode',
  1 => 'title',
  2 => 'field_highlight',
  3 => 'field_top_zone',
  4 => 'field_top_zone_background',
  5 => 'field_local_nav',
  6 => 'field_content',
  7 => 'field_visual',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');
$config_group->set('third_party_settings.field_group.group_write.children', array(
  0 => 'langcode',
  1 => 'title',
  2 => 'field_highlight',
  3 => 'field_top_zone',
  4 => 'field_top_zone_background',
  5 => 'field_local_nav',
  6 => 'field_content',
  7 => 'field_visual',
));
$config_group->save(TRUE);