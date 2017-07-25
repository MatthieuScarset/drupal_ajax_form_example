<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.subhome');
$config_group->setData(array(
  'uuid' => '1c9fb3d3-3e32-4522-95aa-99e73cc671dc',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.subhome',
          1 => 'field.field.node.document.field_blog_thematic',
          2 => 'field.field.node.document.field_content',
          3 => 'field.field.node.document.field_content_owner',
          4 => 'field.field.node.document.field_display_title',
          5 => 'field.field.node.document.field_document_type',
          6 => 'field.field.node.document.field_email_owner',
          7 => 'field.field.node.document.field_end_date',
          8 => 'field.field.node.document.field_file',
          9 => 'field.field.node.document.field_highlight',
          10 => 'field.field.node.document.field_industry',
          11 => 'field.field.node.document.field_job_profile',
          12 => 'field.field.node.document.field_market_segment',
          13 => 'field.field.node.document.field_meta_description',
          14 => 'field.field.node.document.field_meta_title',
          15 => 'field.field.node.document.field_metatags',
          16 => 'field.field.node.document.field_region',
          17 => 'field.field.node.document.field_solution',
          18 => 'field.field.node.document.field_start_date',
          19 => 'field.field.node.document.field_subhome',
          20 => 'field.field.node.document.field_thematic',
          21 => 'field.field.node.document.field_visual',
          22 => 'node.type.document',
        ),
      'module' =>
        array (
          0 => 'user',
        ),
    ),
  'id' => 'node.document.subhome',
  'targetEntityType' => 'node',
  'bundle' => 'document',
  'mode' => 'subhome',
  'content' =>
    array (
      'field_file' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 1,
          'region' => 'content',
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'default',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_solution' =>
        array (
          'type' => 'entity_reference_label',
          'weight' => 2,
          'region' => 'content',
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_visual' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 0,
          'region' => 'content',
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'subhome_image',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'field_blog_thematic' => true,
      'field_content' => true,
      'field_content_owner' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_email_owner' => true,
      'field_end_date' => true,
      'field_highlight' => true,
      'field_industry' => true,
      'field_job_profile' => true,
      'field_market_segment' => true,
      'field_meta_description' => true,
      'field_meta_title' => true,
      'field_metatags' => true,
      'field_region' => true,
      'field_start_date' => true,
      'field_subhome' => true,
      'field_thematic' => true,
      'langcode' => true,
      'links' => true,
      'workbench_moderation_control' => true,
    ),
));
$config_group->save(TRUE);