<?php

##Modification de l'ordre d'affichage des champs lors de l'edition d'un bloggeur

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.profile.default');
$config_group->setData(
  array (
    'uuid' => 'c035d2f6-80a4-44cb-b256-82d5eb2bd3b5',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'entity_browser.browser.browser_file_modal',
            1 => 'field.field.node.profile.body',
            2 => 'field.field.node.profile.field_first_name',
            3 => 'field.field.node.profile.field_last_name',
            4 => 'field.field.node.profile.field_metatags',
            5 => 'field.field.node.profile.field_social_account',
            6 => 'field.field.node.profile.field_visual',
            7 => 'node.type.profile',
          ),
        'module' =>
          array (
            0 => 'entity_browser',
            1 => 'metatag',
            2 => 'path',
            3 => 'text',
            4 => 'workbench_moderation',
          ),
      ),
    'id' => 'node.profile.default',
    'targetEntityType' => 'node',
    'bundle' => 'profile',
    'mode' => 'default',
    'content' =>
      array (
        'body' =>
          array (
            'type' => 'text_textarea_with_summary',
            'weight' => 4,
            'region' => 'content',
            'settings' =>
              array (
                'rows' => 9,
                'summary_rows' => 3,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_first_name' =>
          array (
            'type' => 'string_textfield',
            'weight' => 2,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_last_name' =>
          array (
            'type' => 'string_textfield',
            'weight' => 1,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_metatags' =>
          array (
            'type' => 'metatag_firehose',
            'weight' => 6,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_social_account' =>
          array (
            'type' => 'string_textfield',
            'weight' => 9,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_visual' =>
          array (
            'type' => 'entity_browser_entity_reference',
            'weight' => 8,
            'region' => 'content',
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
          ),
        'langcode' =>
          array (
            'type' => 'language_select',
            'weight' => 0,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'path' =>
          array (
            'type' => 'path',
            'weight' => 5,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'title' =>
          array (
            'type' => 'string_textfield',
            'weight' => 3,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'translation' =>
          array (
            'weight' => 7,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'uid' =>
          array (
            'type' => 'entity_reference_autocomplete',
            'weight' => 10,
            'region' => 'content',
            'settings' =>
              array (
                'match_operator' => 'CONTAINS',
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
        'promote' => true,
        'sticky' => true,
      ),
  )
);

$config_group->save(TRUE);
