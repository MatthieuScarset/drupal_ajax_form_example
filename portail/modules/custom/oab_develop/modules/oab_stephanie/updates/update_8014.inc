<?php

use \Drupal\Core\Utility\UpdateException;



/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.default');
$config_group->setData(
  array (
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
            5 => 'field.field.node.container.field_document_type',
            6 => 'field.field.node.container.field_end_date',
            7 => 'field.field.node.container.field_file',
            8 => 'field.field.node.container.field_image',
            9 => 'field.field.node.container.field_industry',
            10 => 'field.field.node.container.field_magazine',
            11 => 'field.field.node.container.field_partner',
            12 => 'field.field.node.container.field_profile',
            13 => 'field.field.node.container.field_rendering_model',
            14 => 'field.field.node.container.field_short_description',
            15 => 'field.field.node.container.field_solution',
            16 => 'field.field.node.container.field_start_date',
            17 => 'field.field.node.container.field_state',
            18 => 'field.field.node.container.field_subtitle',
            19 => 'field.field.node.container.field_topic',
            20 => 'node.type.container',
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
            'type' => 'entity_reference_entity_view',
            'weight' => 10,
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
        'field_short_description' =>
          array (
            'weight' => 1,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'basic_string',
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
        'field_document_type' => true,
        'field_end_date' => true,
        'field_industry' => true,
        'field_partner' => true,
        'field_rendering_model' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);



/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.media.image.document');
$config_group->setData(
  array (
    'uuid' => '94cebf28-4da4-488f-818f-703b45002e13',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.media.document',
            1 => 'field.field.media.image.field_image',
            2 => 'field.field.media.image.field_tags',
            3 => 'field.field.media.image.field_thematic',
            4 => 'image.style.miniature_document',
            5 => 'media_entity.bundle.image',
          ),
        'module' =>
          array (
            0 => 'image',
          ),
      ),
    'id' => 'media.image.document',
    'targetEntityType' => 'media',
    'bundle' => 'image',
    'mode' => 'document',
    'content' =>
      array (
        'field_image' =>
          array (
            'type' => 'image',
            'weight' => 0,
            'label' => 'hidden',
            'settings' =>
              array (
                'image_style' => 'miniature_document',
                'image_link' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
      ),
    'hidden' =>
      array (
        'created' => true,
        'field_tags' => true,
        'field_thematic' => true,
        'langcode' => true,
        'name' => true,
        'thumbnail' => true,
        'uid' => true,
      ),
  ));
$config_group->save(TRUE);




/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.document');
$config_group->setData(
  array (
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
            6 => 'field.field.node.container.field_document_type',
            7 => 'field.field.node.container.field_end_date',
            8 => 'field.field.node.container.field_file',
            9 => 'field.field.node.container.field_image',
            10 => 'field.field.node.container.field_industry',
            11 => 'field.field.node.container.field_magazine',
            12 => 'field.field.node.container.field_partner',
            13 => 'field.field.node.container.field_profile',
            14 => 'field.field.node.container.field_rendering_model',
            15 => 'field.field.node.container.field_short_description',
            16 => 'field.field.node.container.field_solution',
            17 => 'field.field.node.container.field_start_date',
            18 => 'field.field.node.container.field_state',
            19 => 'field.field.node.container.field_subtitle',
            20 => 'field.field.node.container.field_topic',
            21 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'comment',
            1 => 'oab_text',
            2 => 'user',
          ),
      ),
    'id' => 'node.container.document',
    'targetEntityType' => 'node',
    'bundle' => 'container',
    'mode' => 'document',
    'content' =>
      array (
        'field_commentaire' =>
          array (
            'weight' => 6,
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
        'field_commentaires' => true,
        'field_customer_story' => true,
        'field_end_date' => true,
        'field_industry' => true,
        'field_magazine' => true,
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
$config_group->save(TRUE);





/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.document');
$config_group->setData(
  array (
    'uuid' => 'a2e889f3-ea86-48f3-b53c-02ea339b69a4',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'media_entity',
          ),
      ),
    'id' => 'media.document',
    'label' => 'Document',
    'targetEntityType' => 'media',
    'cache' => true,
  ));
$config_group->save(TRUE);





/** core.entity_view_display.node.container.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.node.document');
$config_group->setData(
  array (
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
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.miniature_document');
$config_group->setData(
  array (
    'uuid' => '2d03716e-c095-4212-b57c-6593125cba6f',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'name' => 'miniature_document',
    'label' => 'Miniature document 130 x 185',
    'effects' =>
      array (
        'b17f9082-37ee-451e-ac90-3021bb6ec6ca' =>
          array (
            'uuid' => 'b17f9082-37ee-451e-ac90-3021bb6ec6ca',
            'id' => 'image_scale',
            'weight' => 1,
            'data' =>
              array (
                'width' => 130,
                'height' => 185,
                'upscale' => false,
              ),
          ),
      ),
  ));
$config_group->save(TRUE);