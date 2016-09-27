<?php

use \Drupal\Core\Utility\UpdateException;
/**
* Création du champ Document type
*/
$new_field_profile = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_document_type');
if(empty($new_field_profile) || $new_field_profile == null) {
  $new_field_profile = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
            1 => 'taxonomy',
          ),
      ),
    'id' => 'node.field_document_type',
    'field_name' => 'field_document_type',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'taxonomy_term',
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
  \Drupal::entityTypeManager()->getStorage('field_storage_config')->create($new_field_profile)->save();
}

/**
 * Création de l'instance du champ document type pour le type de contenu Container
 */
$instance = \Drupal\field\Entity\FieldConfig::loadByName('node', 'container', 'field_document_type');
if(empty($instance) || $instance == null) {
  $instance = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_document_type',
            1 => 'node.type.container',
            2 => 'taxonomy.vocabulary.document_types',
          ),
      ),
    'id' => 'node.container.field_document_type',
    'field_name' => 'field_document_type',
    'entity_type' => 'node',
    'bundle' => 'container',
    'label' => 'Document type',
    'description' => '',
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
                'document_types' => 'document_types',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => false,
            'auto_create_bundle' => '',
          ),
      ),
    'field_type' => 'entity_reference',
  );
  \Drupal::entityTypeManager()->getStorage('field_config')->create($instance)->save();
}

/**
 * Edition de la configuration pour l'ajout du champ au formulaire de création de container
 */
/** core.entity_form_display.node.container.default **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.container.default');
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
            19 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'comment',
            1 => 'datetime',
            2 => 'entity_browser',
            3 => 'field_group',
            4 => 'oab_text',
            5 => 'path',
            6 => 'workflowfield',
          ),
      ),
    'third_party_settings' =>
      array (
        'field_group' =>
          array (
            'group_general' =>
              array (
                'children' =>
                  array (
                    0 => 'field_rendering_model',
                    1 => 'langcode',
                    2 => 'title',
                    3 => 'field_subtitle',
                    4 => 'field_short_description',
                    5 => 'field_profile',
                    6 => 'group_date_fieldset',
                    7 => 'path',
                  ),
                'parent_name' => 'group_onglets',
                'weight' => 1,
                'label' => 'General',
                'format_type' => 'tab',
                'format_settings' =>
                  array (
                    'label' => 'General',
                    'formatter' => 'closed',
                    'description' => '',
                    'required_fields' => true,
                    'id' => '',
                    'classes' => '',
                  ),
              ),
            'group_taxonomie' =>
              array (
                'children' =>
                  array (
                    0 => 'field_blog',
                    1 => 'field_magazine',
                    2 => 'field_customer_story',
                    3 => 'field_solution',
                    4 => 'field_area',
                    5 => 'field_partner',
                    6 => 'field_industry',
                    7 => 'field_document_type',
                  ),
                'parent_name' => 'group_onglets',
                'weight' => 2,
                'label' => 'Taxonomy',
                'format_type' => 'tab',
                'format_settings' =>
                  array (
                    'label' => 'Taxonomy',
                    'formatter' => 'closed',
                    'description' => '',
                    'required_fields' => true,
                    'id' => '',
                    'classes' => '',
                  ),
              ),
            'group_medias' =>
              array (
                'children' =>
                  array (
                    0 => 'field_image',
                    1 => 'field_file',
                  ),
                'parent_name' => 'group_onglets',
                'weight' => 3,
                'label' => 'Medias',
                'format_type' => 'tab',
                'format_settings' =>
                  array (
                    'label' => 'Medias',
                    'formatter' => 'closed',
                    'description' => '',
                    'required_fields' => true,
                    'id' => '',
                    'classes' => '',
                  ),
              ),
            'group_contenu' =>
              array (
                'children' =>
                  array (
                    0 => 'field_content_field',
                  ),
                'parent_name' => 'group_onglets',
                'weight' => 4,
                'label' => 'Content',
                'format_type' => 'tab',
                'format_settings' =>
                  array (
                    'label' => 'Content',
                    'formatter' => 'closed',
                    'description' => '',
                    'required_fields' => true,
                    'id' => '',
                    'classes' => '',
                  ),
              ),
            'group_workflow' =>
              array (
                'children' =>
                  array (
                    0 => 'field_state',
                  ),
                'parent_name' => 'group_onglets',
                'weight' => 5,
                'label' => 'Workflow',
                'format_type' => 'tab',
                'format_settings' =>
                  array (
                    'description' => '',
                    'classes' => '',
                    'id' => '',
                    'required_fields' => true,
                    'open' => false,
                    'formatter' => 'closed',
                    'direction' => 'vertical',
                  ),
              ),
            'group_onglets' =>
              array (
                'children' =>
                  array (
                    0 => 'group_general',
                    1 => 'group_taxonomie',
                    2 => 'group_medias',
                    3 => 'group_contenu',
                    4 => 'group_workflow',
                  ),
                'parent_name' => '',
                'weight' => 0,
                'label' => 'Onglets',
                'format_type' => 'tabs',
                'format_settings' =>
                  array (
                    'label' => 'Onglets',
                    'direction' => 'horizontal',
                    'id' => '',
                    'classes' => '',
                  ),
              ),
            'group_date_fieldset' =>
              array (
                'children' =>
                  array (
                    0 => 'field_start_date',
                    1 => 'field_end_date',
                  ),
                'parent_name' => 'group_general',
                'weight' => 7,
                'label' => 'Content worthy period',
                'format_type' => 'fieldset',
                'format_settings' =>
                  array (
                    'description' => '',
                    'classes' => '',
                    'id' => '',
                    'required_fields' => true,
                  ),
              ),
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
            'weight' => 5,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_blog' =>
          array (
            'weight' => 1,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_blogger' =>
          array (
            'weight' => 27,
            'settings' =>
              array (
                'match_operator' => 'CONTAINS',
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_reference_autocomplete',
          ),
        'field_commentaire' =>
          array (
            'weight' => 26,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'comment_default',
          ),
        'field_content_field' =>
          array (
            'weight' => 3,
            'settings' =>
              array (
                'rows' => '9',
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'oab_text_textfield',
          ),
        'field_customer_story' =>
          array (
            'weight' => 3,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_document_type' =>
          array (
            'weight' => 8,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_end_date' =>
          array (
            'weight' => 7,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'datetime_default',
          ),
        'field_file' =>
          array (
            'type' => 'options_select',
            'weight' => 12,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_image' =>
          array (
            'weight' => 11,
            'settings' =>
              array (
                'entity_browser' => 'browse_media_modal',
                'field_widget_display' => 'rendered_entity',
                'field_widget_edit' => true,
                'field_widget_remove' => true,
                'field_widget_display_settings' =>
                  array (
                    'view_mode' => 'teaser',
                  ),
                'open' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_browser_entity_reference',
          ),
        'field_industry' =>
          array (
            'weight' => 7,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_magazine' =>
          array (
            'weight' => 2,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_partner' =>
          array (
            'weight' => 6,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_profile' =>
          array (
            'weight' => 6,
            'settings' =>
              array (
                'match_operator' => 'CONTAINS',
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_reference_autocomplete',
          ),
        'field_rendering_model' =>
          array (
            'weight' => 1,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_short_description' =>
          array (
            'weight' => 5,
            'settings' =>
              array (
                'rows' => 5,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'string_textarea',
          ),
        'field_solution' =>
          array (
            'weight' => 4,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
          ),
        'field_start_date' =>
          array (
            'weight' => 6,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'datetime_default',
          ),
        'field_state' =>
          array (
            'weight' => 5,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'workflow_default',
          ),
        'field_subtitle' =>
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
        'langcode' =>
          array (
            'type' => 'language_select',
            'weight' => 2,
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
            'weight' => 8,
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
        'promote' => true,
        'sticky' => true,
        'uid' => true,
      ),
  ));
$config_group->save(TRUE);



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
            19 => 'node.type.container',
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
            'weight' => 9,
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
            'weight' => 10,
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
        'field_document_type' =>
          array (
            'weight' => 8,
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
        'field_end_date' => true,
        'field_industry' => true,
        'field_partner' => true,
        'field_rendering_model' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.teaser');
$config_group->setData(
  array (
    'uuid' => 'd7779fb1-64c7-4d06-9e35-5ee7e526644d',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.teaser',
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
            20 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'user',
          ),
      ),
    'id' => 'node.container.teaser',
    'targetEntityType' => 'node',
    'bundle' => 'container',
    'mode' => 'teaser',
    'content' =>
      array (
        'field_image' =>
          array (
            'type' => 'entity_reference_entity_view',
            'weight' => 0,
            'label' => 'above',
            'settings' =>
              array (
                'view_mode' => 'teaser',
                'link' => false,
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'links' =>
          array (
            'weight' => 1,
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
        'field_area' => true,
        'field_blog' => true,
        'field_commentaire' => true,
        'field_content_field' => true,
        'field_customer_story' => true,
        'field_document_type' => true,
        'field_end_date' => true,
        'field_file' => true,
        'field_industry' => true,
        'field_magazine' => true,
        'field_partner' => true,
        'field_profile' => true,
        'field_rendering_model' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_subtitle' => true,
        'langcode' => true,
      ),
  ));
$config_group->save(TRUE);