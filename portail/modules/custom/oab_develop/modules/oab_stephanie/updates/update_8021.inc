<?php

use \Drupal\Core\Utility\UpdateException;
/*************************************
 * Création du champ Metatags
 *************************************/
$new_field = \Drupal\field\Entity\FieldStorageConfig::loadByName('node', 'field_metatags');
if(empty($new_field) || $new_field == null) {
  $new_field = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'metatag',
            1 => 'node',
          ),
      ),
    'id' => 'node.field_metatags',
    'field_name' => 'field_metatags',
    'entity_type' => 'node',
    'type' => 'metatag',
    'settings' =>
      array (
      ),
    'module' => 'metatag',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  );
  \Drupal::entityTypeManager()->getStorage('field_storage_config')->create($new_field)->save();
}

/**************************************************************************/
/************************** INSTANCES *************************************/
/**************************************************************************/
/**
 * Création de l'instance du champ pour le type de contenu CONTAINER
 */
$instance = \Drupal\field\Entity\FieldConfig::loadByName('node', 'container', 'field_metatags');
if(empty($instance) || $instance == null) {
  $instance = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_metatags',
            1 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
          ),
      ),
    'id' => 'node.container.field_metatags',
    'field_name' => 'field_metatags',
    'entity_type' => 'node',
    'bundle' => 'container',
    'label' => 'Metatags',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
        0 =>
          array (
            'value' => 'a:1:{s:5:"title";s:34:"[current-page:title] | [site:name]";}',
          ),
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'metatag',
  );
  \Drupal::entityTypeManager()->getStorage('field_config')->create($instance)->save();
}

/**
 * Création de l'instance du champ pour le type de contenu PROFILE
 */
$instance = \Drupal\field\Entity\FieldConfig::loadByName('node', 'profil_redacteur', 'field_metatags');
if(empty($instance) || $instance == null) {
  $instance = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_metatags',
            1 => 'node.type.profil_redacteur',
          ),
        'module' =>
          array (
            0 => 'metatag',
          ),
      ),
    'id' => 'node.profil_redacteur.field_metatags',
    'field_name' => 'field_metatags',
    'entity_type' => 'node',
    'bundle' => 'profil_redacteur',
    'label' => 'Metatags',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'metatag',
  );
  \Drupal::entityTypeManager()->getStorage('field_config')->create($instance)->save();
}



/**
 * Création de l'instance du champ pour le type de contenu yamlFORM
 */
$instance = \Drupal\field\Entity\FieldConfig::loadByName('node', 'yamlform', 'field_metatags');
if(empty($instance) || $instance == null) {
  $instance = array(
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_metatags',
            1 => 'node.type.yamlform',
          ),
        'module' =>
          array (
            0 => 'metatag',
          ),
      ),
    'id' => 'node.yamlform.field_metatags',
    'field_name' => 'field_metatags',
    'entity_type' => 'node',
    'bundle' => 'yamlform',
    'label' => 'Metatags',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
      array (
        0 =>
          array (
            'value' => 'a:1:{s:5:"title";s:34:"[current-page:title] | [site:name]";}',
          ),
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'metatag',
  );
  \Drupal::entityTypeManager()->getStorage('field_config')->create($instance)->save();
}

/**************************************************************************/
/*********************** CONFIG FORMULAIRES *******************************/
/**************************************************************************/

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
            2 => 'field.field.node.container.field_city',
            3 => 'field.field.node.container.field_commentaire',
            4 => 'field.field.node.container.field_content_field',
            5 => 'field.field.node.container.field_country',
            6 => 'field.field.node.container.field_customer_story',
            7 => 'field.field.node.container.field_display_title',
            8 => 'field.field.node.container.field_document_type',
            9 => 'field.field.node.container.field_end_date',
            10 => 'field.field.node.container.field_file',
            11 => 'field.field.node.container.field_image',
            12 => 'field.field.node.container.field_industry',
            13 => 'field.field.node.container.field_magazine',
            14 => 'field.field.node.container.field_metatags',
            15 => 'field.field.node.container.field_owner',
            16 => 'field.field.node.container.field_partner',
            17 => 'field.field.node.container.field_profile',
            18 => 'field.field.node.container.field_rendering_model',
            19 => 'field.field.node.container.field_section',
            20 => 'field.field.node.container.field_short_description',
            21 => 'field.field.node.container.field_solution',
            22 => 'field.field.node.container.field_start_date',
            23 => 'field.field.node.container.field_state',
            24 => 'field.field.node.container.field_subtitle',
            25 => 'field.field.node.container.field_topic',
            26 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'comment',
            1 => 'datetime',
            2 => 'entity_browser',
            3 => 'field_group',
            4 => 'metatag',
            5 => 'oab_text',
            6 => 'path',
            7 => 'workflowfield',
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
                    3 => 'field_display_title',
                    4 => 'field_subtitle',
                    5 => 'field_short_description',
                    6 => 'field_profile',
                    7 => 'field_owner',
                    8 => 'group_date_fieldset',
                    9 => 'path',
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
                    8 => 'field_topic',
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
                'weight' => 9,
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
        'field_display_title' =>
          array (
            'type' => 'boolean_checkbox',
            'weight' => 4,
            'settings' =>
              array (
                'display_label' => false,
              ),
            'third_party_settings' =>
              array (
              ),
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
        'field_metatags' =>
          array (
            'weight' => 28,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_firehose',
          ),
        'field_owner' =>
          array (
            'weight' => 8,
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
            'weight' => 7,
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
            'weight' => 6,
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
        'field_topic' =>
          array (
            'weight' => 9,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'options_select',
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
            'weight' => 10,
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
        'field_city' => true,
        'field_country' => true,
        'field_section' => true,
        'promote' => true,
        'sticky' => true,
        'uid' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_form_display.node.profil_redacteur.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.profil_redacteur.default');
$config_group->setData(
  array (
    'uuid' => NULL,
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
            7 => 'field.field.node.profil_redacteur.field_metatags',
            8 => 'field.field.node.profil_redacteur.field_social_accounts',
            9 => 'node.type.profil_redacteur',
          ),
        'module' =>
          array (
            0 => 'entity_browser',
            1 => 'link',
            2 => 'metatag',
            3 => 'path',
            4 => 'text',
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
        'field_metatags' =>
          array (
            'weight' => 26,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_firehose',
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
$config_group->save(TRUE);

/** core.entity_form_display.node.yamlform.default.yml **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.yamlform.default');
$config_group->setData(
  array (
    'uuid' => 'b02bd641-6321-4df1-a08a-23750e48a7df',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.node.yamlform.body',
            1 => 'field.field.node.yamlform.field_metatags',
            2 => 'field.field.node.yamlform.yamlform',
            3 => 'node.type.yamlform',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'path',
            2 => 'text',
            3 => 'yamlform',
          ),
      ),
    '_core' =>
      array (
        'default_config_hash' => 'G1ijbr3eRpKNU5cdbHYWD3YbhRK2n5z1J0p2YFlZsyI',
      ),
    'id' => 'node.yamlform.default',
    'targetEntityType' => 'node',
    'bundle' => 'yamlform',
    'mode' => 'default',
    'content' =>
      array (
        'body' =>
          array (
            'type' => 'text_textarea_with_summary',
            'weight' => 0,
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
            'weight' => 10,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_metatags' =>
          array (
            'weight' => 31,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_firehose',
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
            'weight' => 30,
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
            'weight' => 15,
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
            'weight' => 16,
            'third_party_settings' =>
              array (
              ),
          ),
        'title' =>
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
        'uid' =>
          array (
            'type' => 'entity_reference_autocomplete',
            'weight' => 5,
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
        'yamlform' =>
          array (
            'weight' => 0,
            'settings' =>
              array (
                'match_operator' => 'CONTAINS',
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'yamlform_entity_reference_autocomplete',
          ),
      ),
    'hidden' =>
      array (
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.blog_post **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.blog_post');
$config_group->setData(
  array (
    'uuid' => 'b9e6652e-e021-43fe-bae3-a63136f4331c',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_display.comment.comment.default',
            1 => 'core.entity_view_mode.node.blog_post',
            2 => 'field.field.node.container.field_area',
            3 => 'field.field.node.container.field_blog',
            4 => 'field.field.node.container.field_city',
            5 => 'field.field.node.container.field_commentaire',
            6 => 'field.field.node.container.field_content_field',
            7 => 'field.field.node.container.field_country',
            8 => 'field.field.node.container.field_customer_story',
            9 => 'field.field.node.container.field_display_title',
            10 => 'field.field.node.container.field_document_type',
            11 => 'field.field.node.container.field_end_date',
            12 => 'field.field.node.container.field_file',
            13 => 'field.field.node.container.field_image',
            14 => 'field.field.node.container.field_industry',
            15 => 'field.field.node.container.field_magazine',
            16 => 'field.field.node.container.field_metatags',
            17 => 'field.field.node.container.field_owner',
            18 => 'field.field.node.container.field_partner',
            19 => 'field.field.node.container.field_profile',
            20 => 'field.field.node.container.field_rendering_model',
            21 => 'field.field.node.container.field_section',
            22 => 'field.field.node.container.field_short_description',
            23 => 'field.field.node.container.field_solution',
            24 => 'field.field.node.container.field_start_date',
            25 => 'field.field.node.container.field_state',
            26 => 'field.field.node.container.field_subtitle',
            27 => 'field.field.node.container.field_topic',
            28 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'comment',
            1 => 'metatag',
            2 => 'oab_text',
            3 => 'user',
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
                'view_mode' => 'default',
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
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 5,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
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
        'field_city' => true,
        'field_commentaires' => true,
        'field_country' => true,
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
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.case_study **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.case_study');
$config_group->setData(
  array (
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
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'oab_text',
            2 => 'user',
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
        'field_image' =>
          array (
            'type' => 'entity_reference_entity_view',
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
          ),
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 3,
            'label' => 'hidden',
            'settings' =>
              array (
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
        'field_city' => true,
        'field_commentaire' => true,
        'field_commentaires' => true,
        'field_country' => true,
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
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.default **/
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
            0 => 'core.entity_view_display.comment.comment.default',
            1 => 'field.field.node.container.field_area',
            2 => 'field.field.node.container.field_blog',
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'comment',
            1 => 'metatag',
            2 => 'oab_text',
            3 => 'user',
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
        'field_metatags' =>
          array (
            'weight' => 12,
            'label' => 'above',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_empty_formatter',
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
        'field_city' => true,
        'field_commentaires' => true,
        'field_country' => true,
        'field_customer_story' => true,
        'field_display_title' => true,
        'field_document_type' => true,
        'field_end_date' => true,
        'field_industry' => true,
        'field_owner' => true,
        'field_partner' => true,
        'field_rendering_model' => true,
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.document **/
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
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
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
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 6,
            'label' => 'hidden',
            'settings' =>
              array (
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
        'field_city' => true,
        'field_commentaire' => true,
        'field_commentaires' => true,
        'field_country' => true,
        'field_customer_story' => true,
        'field_display_title' => true,
        'field_end_date' => true,
        'field_industry' => true,
        'field_magazine' => true,
        'field_owner' => true,
        'field_partner' => true,
        'field_profile' => true,
        'field_rendering_model' => true,
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.magazine **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.magazine');
$config_group->setData(
  array (
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
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'oab_text',
            2 => 'user',
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
            'weight' => 1,
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
          ),
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 4,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_profile' =>
          array (
            'weight' => 2,
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
        'field_city' => true,
        'field_commentaire' => true,
        'field_commentaires' => true,
        'field_country' => true,
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
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.press_release **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.container.press_release');
$config_group->setData(
  array (
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
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'oab_text',
            2 => 'user',
          ),
      ),
    'id' => 'node.container.press_release',
    'targetEntityType' => 'node',
    'bundle' => 'container',
    'mode' => 'press_release',
    'content' =>
      array (
        'field_city' =>
          array (
            'type' => 'string',
            'weight' => 1,
            'label' => 'hidden',
            'settings' =>
              array (
                'link_to_entity' => false,
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
        'field_country' =>
          array (
            'type' => 'string',
            'weight' => 0,
            'label' => 'hidden',
            'settings' =>
              array (
                'link_to_entity' => false,
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_file' =>
          array (
            'type' => 'entity_reference_entity_view',
            'weight' => 4,
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
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 5,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_subtitle' =>
          array (
            'weight' => 2,
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
        'field_image' => true,
        'field_industry' => true,
        'field_magazine' => true,
        'field_owner' => true,
        'field_partner' => true,
        'field_profile' => true,
        'field_rendering_model' => true,
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_topic' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.container.teaser **/
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
            3 => 'field.field.node.container.field_city',
            4 => 'field.field.node.container.field_commentaire',
            5 => 'field.field.node.container.field_content_field',
            6 => 'field.field.node.container.field_country',
            7 => 'field.field.node.container.field_customer_story',
            8 => 'field.field.node.container.field_display_title',
            9 => 'field.field.node.container.field_document_type',
            10 => 'field.field.node.container.field_end_date',
            11 => 'field.field.node.container.field_file',
            12 => 'field.field.node.container.field_image',
            13 => 'field.field.node.container.field_industry',
            14 => 'field.field.node.container.field_magazine',
            15 => 'field.field.node.container.field_metatags',
            16 => 'field.field.node.container.field_owner',
            17 => 'field.field.node.container.field_partner',
            18 => 'field.field.node.container.field_profile',
            19 => 'field.field.node.container.field_rendering_model',
            20 => 'field.field.node.container.field_section',
            21 => 'field.field.node.container.field_short_description',
            22 => 'field.field.node.container.field_solution',
            23 => 'field.field.node.container.field_start_date',
            24 => 'field.field.node.container.field_state',
            25 => 'field.field.node.container.field_subtitle',
            26 => 'field.field.node.container.field_topic',
            27 => 'node.type.container',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'user',
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
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 2,
            'label' => 'hidden',
            'settings' =>
              array (
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
        'field_city' => true,
        'field_commentaire' => true,
        'field_content_field' => true,
        'field_country' => true,
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
        'field_section' => true,
        'field_short_description' => true,
        'field_solution' => true,
        'field_start_date' => true,
        'field_state' => true,
        'field_subtitle' => true,
        'field_topic' => true,
        'langcode' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.profil_redacteur.default **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profil_redacteur.default');
$config_group->setData(
  array (
    'uuid' => NULL,
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
            7 => 'field.field.node.profil_redacteur.field_metatags',
            8 => 'field.field.node.profil_redacteur.field_social_accounts',
            9 => 'node.type.profil_redacteur',
          ),
        'module' =>
          array (
            0 => 'link',
            1 => 'metatag',
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
                'view_mode' => 'default',
                'link' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_reference_entity_view',
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
        'field_metatags' =>
          array (
            'type' => 'metatag_empty_formatter',
            'weight' => 9,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
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
$config_group->save(TRUE);

/** core.entity_view_display.node.profil_redacteur.teaser **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profil_redacteur.teaser');
$config_group->setData(
  array (
    'uuid' => NULL,
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
            8 => 'field.field.node.profil_redacteur.field_metatags',
            9 => 'field.field.node.profil_redacteur.field_social_accounts',
            10 => 'node.type.profil_redacteur',
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
        'field_metatags' => true,
        'field_social_accounts' => true,
        'langcode' => true,
        'links' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.yamlform.default **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.yamlform.default');
$config_group->setData(
  array (
    'uuid' => '4502f428-e9bc-46bd-81cd-447d95a91975',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.node.yamlform.body',
            1 => 'field.field.node.yamlform.field_metatags',
            2 => 'field.field.node.yamlform.yamlform',
            3 => 'node.type.yamlform',
          ),
        'module' =>
          array (
            0 => 'metatag',
            1 => 'text',
            2 => 'user',
            3 => 'yamlform',
          ),
      ),
    '_core' =>
      array (
        'default_config_hash' => 'tgdoNn9gnIznsYU0Rv6NRjvo-ae2jA-D-4YZ8IdkSrg',
      ),
    'id' => 'node.yamlform.default',
    'targetEntityType' => 'node',
    'bundle' => 'yamlform',
    'mode' => 'default',
    'content' =>
      array (
        'body' =>
          array (
            'label' => 'hidden',
            'type' => 'text_default',
            'weight' => 101,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_metatags' =>
          array (
            'weight' => 103,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_empty_formatter',
          ),
        'links' =>
          array (
            'weight' => 100,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'yamlform' =>
          array (
            'weight' => 102,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'yamlform_entity_reference_entity_view',
          ),
      ),
    'hidden' =>
      array (
        'langcode' => true,
      ),
  ));
$config_group->save(TRUE);

/** core.entity_view_display.node.yamlform.teaser **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.yamlform.teaser');
$config_group->setData(
  array (
    'uuid' => 'e22ac67a-c2ce-4c1d-9059-e138b356f42f',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.teaser',
            1 => 'field.field.node.yamlform.body',
            2 => 'field.field.node.yamlform.field_metatags',
            3 => 'field.field.node.yamlform.yamlform',
            4 => 'node.type.yamlform',
          ),
        'module' =>
          array (
            0 => 'text',
            1 => 'user',
          ),
      ),
    '_core' =>
      array (
        'default_config_hash' => '6RWSyyrzUOt-ovvP3cO1CbTFckoskSeZXCbBWfXm7Nk',
      ),
    'id' => 'node.yamlform.teaser',
    'targetEntityType' => 'node',
    'bundle' => 'yamlform',
    'mode' => 'teaser',
    'content' =>
      array (
        'body' =>
          array (
            'label' => 'hidden',
            'type' => 'text_summary_or_trimmed',
            'weight' => 101,
            'settings' =>
              array (
                'trim_length' => 600,
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'links' =>
          array (
            'weight' => 100,
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
        'field_metatags' => true,
        'langcode' => true,
        'yamlform' => true,
      ),
  ));
$config_group->save(TRUE);