<?php

/****** form display powerpage ******/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.solution.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.solution.field_content',
  2 => 'field.field.node.solution.field_content_owner',
  3 => 'field.field.node.solution.field_display_title',
  4 => 'field.field.node.solution.field_email_owner',
  5 => 'field.field.node.solution.field_end_date',
  6 => 'field.field.node.solution.field_highlight',
  7 => 'field.field.node.solution.field_local_nav',
  8 => 'field.field.node.solution.field_meta_description',
  9 => 'field.field.node.solution.field_meta_title',
  10 => 'field.field.node.solution.field_related_content',
  11 => 'field.field.node.solution.field_start_date',
  12 => 'field.field.node.solution.field_top_zone',
  13 => 'field.field.node.solution.field_top_zone_background',
  14 => 'field.field.node.solution.field_visual',
  15 => 'node.type.solution',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_local_nav',
  8 => 'field_content',
  9 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'type' => 'entity_reference_paragraphs',
  'weight' => 11,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.industry.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.industry.field_content',
  2 => 'field.field.node.industry.field_content_owner',
  3 => 'field.field.node.industry.field_display_title',
  4 => 'field.field.node.industry.field_email_owner',
  5 => 'field.field.node.industry.field_end_date',
  6 => 'field.field.node.industry.field_highlight',
  7 => 'field.field.node.industry.field_local_nav',
  8 => 'field.field.node.industry.field_meta_description',
  9 => 'field.field.node.industry.field_meta_title',
  10 => 'field.field.node.industry.field_related_content',
  11 => 'field.field.node.industry.field_start_date',
  12 => 'field.field.node.industry.field_top_zone',
  13 => 'field.field.node.industry.field_top_zone_background',
  14 => 'field.field.node.industry.field_visual',
  15 => 'node.type.industry',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_local_nav',
  8 => 'field_content',
  9 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 44,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.region.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.region.field_content',
  2 => 'field.field.node.region.field_content_owner',
  3 => 'field.field.node.region.field_display_title',
  4 => 'field.field.node.region.field_email_owner',
  5 => 'field.field.node.region.field_end_date',
  6 => 'field.field.node.region.field_highlight',
  7 => 'field.field.node.region.field_meta_description',
  8 => 'field.field.node.region.field_meta_title',
  9 => 'field.field.node.region.field_related_content',
  10 => 'field.field.node.region.field_start_date',
  11 => 'field.field.node.region.field_top_zone',
  12 => 'field.field.node.region.field_top_zone_background',
  13 => 'field.field.node.region.field_visual',
  14 => 'node.type.region',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_content',
  8 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 10,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.country.field_content',
  2 => 'field.field.node.country.field_content_owner',
  3 => 'field.field.node.country.field_display_title',
  4 => 'field.field.node.country.field_email_owner',
  5 => 'field.field.node.country.field_end_date',
  6 => 'field.field.node.country.field_highlight',
  7 => 'field.field.node.country.field_meta_description',
  8 => 'field.field.node.country.field_meta_title',
  9 => 'field.field.node.country.field_region',
  10 => 'field.field.node.country.field_related_content',
  11 => 'field.field.node.country.field_start_date',
  12 => 'field.field.node.country.field_top_zone',
  13 => 'field.field.node.country.field_top_zone_background',
  14 => 'field.field.node.country.field_visual',
  15 => 'node.type.country',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_visual',
  5 => 'field_content',
  6 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 8,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

/****** view display ******/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.solution.field_content',
  1 => 'field.field.node.solution.field_content_owner',
  2 => 'field.field.node.solution.field_display_title',
  3 => 'field.field.node.solution.field_email_owner',
  4 => 'field.field.node.solution.field_end_date',
  5 => 'field.field.node.solution.field_highlight',
  6 => 'field.field.node.solution.field_local_nav',
  7 => 'field.field.node.solution.field_meta_description',
  8 => 'field.field.node.solution.field_meta_title',
  9 => 'field.field.node.solution.field_related_content',
  10 => 'field.field.node.solution.field_start_date',
  11 => 'field.field.node.solution.field_top_zone',
  12 => 'field.field.node.solution.field_top_zone_background',
  13 => 'field.field.node.solution.field_visual',
  14 => 'node.type.solution',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'type' => 'entity_reference_revisions_entity_view',
  'weight' => 12,
  'label' => 'hidden',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'region' => 'content',
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.industry.field_content',
  1 => 'field.field.node.industry.field_content_owner',
  2 => 'field.field.node.industry.field_display_title',
  3 => 'field.field.node.industry.field_email_owner',
  4 => 'field.field.node.industry.field_end_date',
  5 => 'field.field.node.industry.field_highlight',
  6 => 'field.field.node.industry.field_local_nav',
  7 => 'field.field.node.industry.field_meta_description',
  8 => 'field.field.node.industry.field_meta_title',
  9 => 'field.field.node.industry.field_related_content',
  10 => 'field.field.node.industry.field_start_date',
  11 => 'field.field.node.industry.field_top_zone',
  12 => 'field.field.node.industry.field_top_zone_background',
  13 => 'field.field.node.industry.field_visual',
  14 => 'node.type.industry',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 14,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.region.field_content',
  1 => 'field.field.node.region.field_content_owner',
  2 => 'field.field.node.region.field_display_title',
  3 => 'field.field.node.region.field_email_owner',
  4 => 'field.field.node.region.field_end_date',
  5 => 'field.field.node.region.field_highlight',
  6 => 'field.field.node.region.field_meta_description',
  7 => 'field.field.node.region.field_meta_title',
  8 => 'field.field.node.region.field_related_content',
  9 => 'field.field.node.region.field_start_date',
  10 => 'field.field.node.region.field_top_zone',
  11 => 'field.field.node.region.field_top_zone_background',
  12 => 'field.field.node.region.field_visual',
  13 => 'node.type.region',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 13,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.country.field_content',
  1 => 'field.field.node.country.field_content_owner',
  2 => 'field.field.node.country.field_display_title',
  3 => 'field.field.node.country.field_email_owner',
  4 => 'field.field.node.country.field_end_date',
  5 => 'field.field.node.country.field_highlight',
  6 => 'field.field.node.country.field_meta_description',
  7 => 'field.field.node.country.field_meta_title',
  8 => 'field.field.node.country.field_region',
  9 => 'field.field.node.country.field_related_content',
  10 => 'field.field.node.country.field_start_date',
  11 => 'field.field.node.country.field_top_zone',
  12 => 'field.field.node.country.field_top_zone_background',
  13 => 'field.field.node.country.field_visual',
  14 => 'node.type.country',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 15,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);