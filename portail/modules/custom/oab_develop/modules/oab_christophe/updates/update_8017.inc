<?php

use Drupal\Core\Database\Database;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.date_format.node_created_date');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'node_created_date',
  'label' => 'node created date',
  'locked' => false,
  'pattern' => 'd M Y',
));
$config->save(TRUE);

// Gestion de la traduction
// je n'ai pas trouvé d'autre moyen que de faire des requètes SQL
$connection = Database::getConnection();
$query_delete = $connection->delete('config')
  ->condition('collection', 'language.en')
  ->condition('name', 'core.date_format.node_created_date')
  ->execute();

$query_create = $connection->insert('config')
  ->fields(array(
    'collection' => 'language.en',
    'name' => 'core.date_format.node_created_date',
    'data' => serialize(array(
      'pattern' => 'M, d Y',
    ))
  ))
  ->execute();


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.node.profil_redacteur.default');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.profil_redacteur.body',
          1 => 'field.field.node.profil_redacteur.field_first_name',
          2 => 'field.field.node.profil_redacteur.field_image',
          3 => 'field.field.node.profil_redacteur.field_job',
          4 => 'field.field.node.profil_redacteur.field_last_name',
          5 => 'field.field.node.profil_redacteur.field_link',
          6 => 'field.field.node.profil_redacteur.field_location',
          7 => 'field.field.node.profil_redacteur.field_social_accounts',
          8 => 'node.type.profil_redacteur',
        ),
      'module' =>
        array (
          0 => 'entity_browser',
          1 => 'link',
          2 => 'path',
          3 => 'text',
        ),
    ),
  'id' => 'node.profil_redacteur.default',
  'targetEntityType' => 'node',
  'bundle' => 'profil_redacteur',
  'mode' => 'default',
  'content' =>
    array (
      'body' =>
        array (
          'type' => 'text_textarea_with_summary',
          'weight' => 2,
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
      'created' =>
        array (
          'type' => 'datetime_timestamp',
          'weight' => 11,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_first_name' =>
        array (
          'weight' => 4,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_image' =>
        array (
          'weight' => 3,
          'settings' =>
            array (
              'entity_browser' => 'browse_media_modal',
              'field_widget_display' => 'rendered_entity',
              'field_widget_edit' => '1',
              'field_widget_remove' => '1',
              'field_widget_display_settings' =>
                array (
                  'view_mode' => 'teaser',
                ),
              'open' => 0,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_browser_entity_reference',
        ),
      'field_job' =>
        array (
          'weight' => 6,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_last_name' =>
        array (
          'weight' => 5,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_link' =>
        array (
          'weight' => 8,
          'settings' =>
            array (
              'placeholder_url' => '',
              'placeholder_title' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'link_default',
        ),
      'field_location' =>
        array (
          'weight' => 7,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'field_social_accounts' =>
        array (
          'weight' => 9,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
        ),
      'langcode' =>
        array (
          'type' => 'language_select',
          'weight' => 1,
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
          'weight' => 15,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'promote' =>
        array (
          'type' => 'boolean_checkbox',
          'settings' =>
            array (
              'display_label' => true,
            ),
          'weight' => 13,
          'third_party_settings' =>
            array (
            ),
        ),
      'sticky' =>
        array (
          'type' => 'boolean_checkbox',
          'settings' =>
            array (
              'display_label' => true,
            ),
          'weight' => 14,
          'third_party_settings' =>
            array (
            ),
        ),
      'title' =>
        array (
          'type' => 'string_textfield',
          'weight' => 0,
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
          'weight' => 12,
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
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.profil_redacteur.default');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.node.profil_redacteur.body',
          1 => 'field.field.node.profil_redacteur.field_first_name',
          2 => 'field.field.node.profil_redacteur.field_image',
          3 => 'field.field.node.profil_redacteur.field_job',
          4 => 'field.field.node.profil_redacteur.field_last_name',
          5 => 'field.field.node.profil_redacteur.field_link',
          6 => 'field.field.node.profil_redacteur.field_location',
          7 => 'field.field.node.profil_redacteur.field_social_accounts',
          8 => 'node.type.profil_redacteur',
        ),
      'module' =>
        array (
          0 => 'link',
          1 => 'oab_media_browser',
          2 => 'text',
          3 => 'user',
        ),
    ),
  'id' => 'node.profil_redacteur.default',
  'targetEntityType' => 'node',
  'bundle' => 'profil_redacteur',
  'mode' => 'default',
  'content' =>
    array (
      'body' =>
        array (
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => 3,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_first_name' =>
        array (
          'weight' => 1,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_image' =>
        array (
          'weight' => 4,
          'label' => 'above',
          'settings' =>
            array (
              'image_style' => '',
              'view_mode' => 'default',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_image',
        ),
      'field_job' =>
        array (
          'weight' => 5,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_last_name' =>
        array (
          'weight' => 2,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_link' =>
        array (
          'weight' => 7,
          'label' => 'above',
          'settings' =>
            array (
              'trim_length' => 80,
              'url_only' => false,
              'url_plain' => false,
              'rel' => '',
              'target' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'link',
        ),
      'field_location' =>
        array (
          'weight' => 6,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'field_social_accounts' =>
        array (
          'weight' => 8,
          'label' => 'above',
          'settings' =>
            array (
              'link_to_entity' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string',
        ),
      'links' =>
        array (
          'weight' => 0,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'langcode' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.node.profil_redacteur.teaser');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.teaser',
          1 => 'field.field.node.profil_redacteur.body',
          2 => 'field.field.node.profil_redacteur.field_first_name',
          3 => 'field.field.node.profil_redacteur.field_image',
          4 => 'field.field.node.profil_redacteur.field_job',
          5 => 'field.field.node.profil_redacteur.field_last_name',
          6 => 'field.field.node.profil_redacteur.field_link',
          7 => 'field.field.node.profil_redacteur.field_location',
          8 => 'field.field.node.profil_redacteur.field_social_accounts',
          9 => 'node.type.profil_redacteur',
        ),
      'module' =>
        array (
          0 => 'text',
          1 => 'user',
        ),
    ),
  'id' => 'node.profil_redacteur.teaser',
  'targetEntityType' => 'node',
  'bundle' => 'profil_redacteur',
  'mode' => 'teaser',
  'content' =>
    array (
      'body' =>
        array (
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => 0,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_image' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'teaser',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'field_first_name' => true,
      'field_job' => true,
      'field_last_name' => true,
      'field_link' => true,
      'field_location' => true,
      'field_social_accounts' => true,
      'langcode' => true,
      'links' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('user.role.anonymous');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
    ),
  '_core' =>
    array (
      'default_config_hash' => 'j5zLMOdJBqC0bMvSdth5UebkprJB8g_2FXHqhfpJzow',
    ),
  'id' => 'anonymous',
  'label' => 'Anonymous user',
  'weight' => 0,
  'is_admin' => false,
  'permissions' =>
    array (
      0 => 'access content',
      1 => 'use text format restricted_html',
      2 => 'access comments',
      3 => 'access site-wide contact form',
      4 => 'search content',
      5 => 'create processus_1 workflow_transition',
      6 => 'create publication_page_simple workflow_transition',
      7 => 'create workflow_page_simple workflow_transition',
      8 => 'view media',
      9 => 'create content_workflow workflow_transition',
      10 => 'post comments',
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('language.content_settings.comment.comment');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'comment.type.comment',
        ),
      'module' =>
        array (
          0 => 'content_translation',
        ),
    ),
  'third_party_settings' =>
    array (
      'content_translation' =>
        array (
          'enabled' => false,
        ),
    ),
  'id' => 'comment.comment',
  'target_entity_type_id' => 'comment',
  'target_bundle' => 'comment',
  'default_langcode' => 'current_interface',
  'language_alterable' => false,
));
$config->save(TRUE);

/**
 * Création du champ email
 */
$new_field_comment = \Drupal\field\Entity\FieldStorageConfig::loadByName('comment', 'field_email');
if(empty($new_field_comment) || $new_field_comment == null) {
  $new_field_comment = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'comment',
          ),
      ),
    'id' => 'comment.field_email',
    'field_name' => 'field_email',
    'entity_type' => 'comment',
    'type' => 'email',
    'settings' =>
      array (
      ),
    'module' => 'core',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  );
  \Drupal::entityTypeManager()->getStorage('field_storage_config')->create($new_field_comment)->save();
}

/**
 * Création de l'instance email
 */
$instance = \Drupal\field\Entity\FieldConfig::loadByName('comment', 'comment', 'field_email');
if(empty($instance) || $instance == null) {
  $instance = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'comment.type.comment',
            1 => 'field.storage.comment.field_email',
          ),
      ),
    'id' => 'comment.comment.field_email',
    'field_name' => 'field_email',
    'entity_type' => 'comment',
    'bundle' => 'comment',
    'label' => 'Votre email',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'email',
  );
  \Drupal::entityTypeManager()->getStorage('field_config')->create($instance)->save();
}


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.comment.comment.default');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'comment.type.comment',
          1 => 'field.field.comment.comment.comment_body',
          2 => 'field.field.comment.comment.field_email',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => 'ooVjelXSXbiQtp-hYb7LS44vR5UO-Kqu4vf484ggR8w',
    ),
  'id' => 'comment.comment.default',
  'targetEntityType' => 'comment',
  'bundle' => 'comment',
  'mode' => 'default',
  'content' =>
    array (
      'author' =>
        array (
          'weight' => 0,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'comment_body' =>
        array (
          'type' => 'text_textarea',
          'weight' => 2,
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_email' =>
        array (
          'type' => 'email_default',
          'weight' => 1,
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
      'langcode' => true,
      'subject' => true,
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.comment.comment.default');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'comment.type.comment',
          1 => 'field.field.comment.comment.comment_body',
          2 => 'field.field.comment.comment.field_email',
        ),
      'module' =>
        array (
          0 => 'text',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => '1yBeJcGufCbnbSolmaYgTIXZWYUaO7kw6xszGA8TYs8',
    ),
  'id' => 'comment.comment.default',
  'targetEntityType' => 'comment',
  'bundle' => 'comment',
  'mode' => 'default',
  'content' =>
    array (
      'comment_body' =>
        array (
          'label' => 'hidden',
          'type' => 'text_default',
          'weight' => 1,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_email' =>
        array (
          'weight' => 0,
          'label' => 'above',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'email_mailto',
        ),
      'links' =>
        array (
          'weight' => 2,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'langcode' => true,
    ),
));
$config->save(TRUE);

// Gestion de la traduction
// je n'ai pas trouvé d'autre moyen que de faire des requètes SQL
$connection = Database::getConnection();
$query_delete = $connection->delete('config')
  ->condition('collection', 'language.en')
  ->condition('name', 'field.field.comment.comment.field_email')
  ->execute();

$query_create = $connection->insert('config')
  ->fields(array(
    'collection' => 'language.en',
    'name' => 'field.field.comment.comment.field_email',
    'data' => serialize(array(
      'label' => 'Your email',
    ))
  ))
  ->execute();

//throw new \Drupal\Core\Utility\UpdateException();