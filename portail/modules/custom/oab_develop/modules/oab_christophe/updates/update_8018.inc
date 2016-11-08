<?php

use Drupal\Core\Database\Database;
use Drupal\locale;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.node.container.default');
$config->setData(array (
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
          5 => 'field.field.node.container.field_end_date',
          6 => 'field.field.node.container.field_file',
          7 => 'field.field.node.container.field_image',
          8 => 'field.field.node.container.field_industry',
          9 => 'field.field.node.container.field_magazine',
          10 => 'field.field.node.container.field_partner',
          11 => 'field.field.node.container.field_profile',
          12 => 'field.field.node.container.field_rendering_model',
          13 => 'field.field.node.container.field_short_description',
          14 => 'field.field.node.container.field_solution',
          15 => 'field.field.node.container.field_start_date',
          16 => 'field.field.node.container.field_state',
          17 => 'field.field.node.container.field_subtitle',
          18 => 'node.type.container',
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
$config->save(TRUE);


// on récupère ou on crée la chaine source
$match_string = array('source' => 'Content', 'context' => '');
$source = \Drupal::service('locale.storage')->findString($match_string);
if (!$source) {
  // Si la source n'existe pas, on la crée
  $source = \Drupal::service('locale.storage')->createString($match_string);
  $source->save();
}

// On crée et enregistre un objet de traduction (fait l'insertion et l'update)
$connection = Database::getConnection();
$stringDatabaseStorage = new locale\StringDatabaseStorage($connection);
$translation = $stringDatabaseStorage->createTranslation(array('lid' => $source->getId(), 'language' => 'fr', 'translation' => 'Contenu'));
$stringDatabaseStorage->save($translation);

//throw new \Drupal\Core\Utility\UpdateException();