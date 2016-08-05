<?php

use \Drupal\Core\Utility\UpdateException;


/*****************************
 * core.entity_form_display.media.image.default
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.media.image.default');
$config_group->setData(
  array (
    'uuid' => 'e6cb99ad-a67f-4e73-9614-20e6a6b1e0bf',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.media.image.field_image',
            1 => 'field.field.media.image.field_tags',
            2 => 'field.field.media.image.field_thematic',
            3 => 'image.style.thumbnail',
            4 => 'media_entity.bundle.image',
          ),
        'module' =>
          array (
            0 => 'image',
          ),
      ),
    'id' => 'media.image.default',
    'targetEntityType' => 'media',
    'bundle' => 'image',
    'mode' => 'default',
    'content' =>
      array (
        'field_image' =>
          array (
            'weight' => 11,
            'settings' =>
              array (
                'progress_indicator' => 'throbber',
                'preview_image_style' => 'thumbnail',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'image_image',
          ),
        'field_tags' =>
          array (
            'weight' => 12,
            'settings' =>
              array (
                'match_operator' => 'CONTAINS',
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_reference_autocomplete_tags',
          ),
        'field_thematic' =>
          array (
            'weight' => 13,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'name' =>
          array (
            'type' => 'string_textfield',
            'weight' => -5,
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
      ),
    'hidden' =>
      array (
        'created' => true,
        'langcode' => true,
        'uid' => true,
      ),
  ));
$config_group->save(TRUE);



/*****************************
 * field.field.media.image.field_tags
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.media.image.field_tags');
$config_group->setData(
  array (
    'uuid' => '8169a187-6fba-4cd2-890d-13b9f5395194',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.media.field_tags',
            1 => 'media_entity.bundle.image',
            2 => 'taxonomy.vocabulary.media_tags',
          ),
      ),
    'id' => 'media.image.field_tags',
    'field_name' => 'field_tags',
    'entity_type' => 'media',
    'bundle' => 'image',
    'label' => 'tags',
    'description' => 'Les mots clés doivent être séparés par des virgules',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:taxonomy_term',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'media_tags' => 'media_tags',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => true,
            'auto_create_bundle' => '',
          ),
      ),
    'field_type' => 'entity_reference',
  ));
$config_group->save(TRUE);