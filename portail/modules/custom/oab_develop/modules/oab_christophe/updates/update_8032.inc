<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_mode.node.blog_post');
$config->setData(array (
  'uuid' => '6dc752b4-4035-4adc-82da-b013ffd0a945',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'node.blog_post',
  'label' => 'Blog post',
  'targetEntityType' => 'node',
  'cache' => true,
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_mode.node.case_study');
$config->setData(array (
  'uuid' => '88a3d3a1-a9b4-4beb-8c49-a88530b00f05',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'node.case_study',
  'label' => 'Case study',
  'targetEntityType' => 'node',
  'cache' => true,
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_mode.node.document');
$config->setData(array (
  'uuid' => 'f48bf3af-6301-4041-9d3f-af8fe988f90d',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'node.document',
  'label' => 'Document',
  'targetEntityType' => 'node',
  'cache' => true,
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_mode.node.magazine');
$config->setData(array (
  'uuid' => '939868ef-2b76-4e8c-b7fa-09ee1da53799',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'node.magazine',
  'label' => 'Magazine',
  'targetEntityType' => 'node',
  'cache' => true,
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_mode.node.press_release');
$config->setData(array (
  'uuid' => '64024482-e7fd-4e3d-8e37-ed64bb2c4c2c',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'node.press_release',
  'label' => 'Press release',
  'targetEntityType' => 'node',
  'cache' => true,
));
$config->save(TRUE);



$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.blog_post');
$config->setData(array (
  'uuid' => 'b9e6652e-e021-43fe-bae3-a63136f4331c',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.blog_post',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'comment',
          1 => 'oab_text',
          2 => 'user',
        ),
    ),
  'id' => 'node.container.blog_post',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'blog_post',
  'content' =>
    array (
      'field_blog' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 0,
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
      'field_commentaire' =>
        array (
          'weight' => 4,
          'label' => 'above',
          'settings' =>
            array (
              'pager_id' => 0,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'comment_default',
        ),
      'field_content_field' =>
        array (
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_profile' =>
        array (
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'teaser',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
        ),
      'field_subtitle' =>
        array (
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_area' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_image' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.case_study');
$config->setData(array (
  'uuid' => '63cc58a0-561e-49f8-bc85-cf18ddedfced',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.case_study',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.case_study',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'case_study',
  'content' =>
    array (
      'field_content_field' =>
        array (
          'weight' => 4,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_image' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_subtitle' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_area' => true,
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_profile' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.default');
$config->setData(array (
  'uuid' => NULL,
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.container.field_area',
          1 => 'field.field.node.container.field_blog',
          2 => 'field.field.node.container.field_commentaire',
          3 => 'field.field.node.container.field_content_field',
          4 => 'field.field.node.container.field_customer_story',
          5 => 'field.field.node.container.field_display_title',
          6 => 'field.field.node.container.field_document_type',
          7 => 'field.field.node.container.field_end_date',
          8 => 'field.field.node.container.field_file',
          9 => 'field.field.node.container.field_image',
          10 => 'field.field.node.container.field_industry',
          11 => 'field.field.node.container.field_magazine',
          12 => 'field.field.node.container.field_owner',
          13 => 'field.field.node.container.field_partner',
          14 => 'field.field.node.container.field_profile',
          15 => 'field.field.node.container.field_rendering_model',
          16 => 'field.field.node.container.field_short_description',
          17 => 'field.field.node.container.field_solution',
          18 => 'field.field.node.container.field_start_date',
          19 => 'field.field.node.container.field_state',
          20 => 'field.field.node.container.field_subtitle',
          21 => 'field.field.node.container.field_topic',
          22 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'comment',
          1 => 'oab_text',
          2 => 'user',
        ),
    ),
  'id' => 'node.container.default',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'default',
  'content' =>
    array (
      'field_area' =>
        array (
          'type' => 'entity_reference_label',
          'weight' => 10,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_blog' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 6,
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
      'field_commentaire' =>
        array (
          'weight' => 11,
          'label' => 'above',
          'settings' =>
            array (
              'pager_id' => 0,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'comment_default',
        ),
      'field_content_field' =>
        array (
          'weight' => 4,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_file' =>
        array (
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'default',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
        ),
      'field_image' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_magazine' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 7,
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
      'field_profile' =>
        array (
          'weight' => 5,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'teaser',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
        ),
      'field_subtitle' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_industry' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.document');
$config->setData(array (
  'uuid' => '0dc24957-d6c3-459c-90f8-2c5ea91f5370',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.document',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.document',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'document',
  'content' =>
    array (
      'field_content_field' =>
        array (
          'type' => 'oab_text_default',
          'weight' => 5,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_document_type' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_label',
        ),
      'field_file' =>
        array (
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'default',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
        ),
      'field_image' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'document',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_subtitle' =>
        array (
          'type' => 'string',
          'weight' => 4,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_topic' =>
        array (
          'weight' => 1,
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
        ),
    ),
  'hidden' =>
    array (
      'field_area' => true,
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_end_date' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_profile' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.magazine');
$config->setData(array (
  'uuid' => '32b8beb1-83d5-439b-b0ac-00bcc6a5dc16',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.magazine',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.magazine',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'magazine',
  'content' =>
    array (
      'field_content_field' =>
        array (
          'weight' => 4,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_magazine' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 7,
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
      'field_profile' =>
        array (
          'weight' => 5,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'teaser',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
        ),
      'field_subtitle' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_area' => true,
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_image' => true,
      'field_industry' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.press_release');
$config->setData(array (
  'uuid' => '1530fbb7-f0fa-4249-b9f4-ffda456972dd',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.press_release',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.press_release',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'press_release',
  'content' =>
    array (
      'field_area' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_content_field' =>
        array (
          'weight' => 3,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_subtitle' =>
        array (
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_image' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_profile' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.container.simple_page');
$config->setData(array (
  'uuid' => 'fee634a8-9327-4b49-af99-2fe675d549b5',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.simple_page',
          1 => 'field.field.node.container.field_area',
          2 => 'field.field.node.container.field_blog',
          3 => 'field.field.node.container.field_commentaire',
          4 => 'field.field.node.container.field_content_field',
          5 => 'field.field.node.container.field_customer_story',
          6 => 'field.field.node.container.field_display_title',
          7 => 'field.field.node.container.field_document_type',
          8 => 'field.field.node.container.field_end_date',
          9 => 'field.field.node.container.field_file',
          10 => 'field.field.node.container.field_image',
          11 => 'field.field.node.container.field_industry',
          12 => 'field.field.node.container.field_magazine',
          13 => 'field.field.node.container.field_owner',
          14 => 'field.field.node.container.field_partner',
          15 => 'field.field.node.container.field_profile',
          16 => 'field.field.node.container.field_rendering_model',
          17 => 'field.field.node.container.field_short_description',
          18 => 'field.field.node.container.field_solution',
          19 => 'field.field.node.container.field_start_date',
          20 => 'field.field.node.container.field_state',
          21 => 'field.field.node.container.field_subtitle',
          22 => 'field.field.node.container.field_topic',
          23 => 'node.type.container',
        ),
      'module' =>
        array (
          0 => 'oab_text',
          1 => 'user',
        ),
    ),
  'id' => 'node.container.simple_page',
  'targetEntityType' => 'node',
  'bundle' => 'container',
  'mode' => 'simple_page',
  'content' =>
    array (
      'field_content_field' =>
        array (
          'weight' => 4,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'oab_text_default',
        ),
      'field_image' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_subtitle' =>
        array (
          'weight' => 0,
          'label' => 'hidden',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
    ),
  'hidden' =>
    array (
      'field_area' => true,
      'field_blog' => true,
      'field_commentaire' => true,
      'field_commentaires' => true,
      'field_customer_story' => true,
      'field_display_title' => true,
      'field_document_type' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_industry' => true,
      'field_magazine' => true,
      'field_owner' => true,
      'field_partner' => true,
      'field_profile' => true,
      'field_rendering_model' => true,
      'field_short_description' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_state' => true,
      'field_topic' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);