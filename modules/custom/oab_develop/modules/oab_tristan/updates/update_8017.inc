<?php

/**
 * Modification de la place de 2 éléments dans la form display + masquage de l'ornemental visuel
 * et ajout du workflow au type de contenu Pays (pour que les boutons save soient plus cohérents
 */

$config_factory = \Drupal::configFactory();

############################
##Modification du formulaire
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');

##On reset
$config_group->setData(array (
  'uuid' => '1f8a80eb-afb8-43ea-bbbc-e82b705e0d23',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
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
        ),
      'module' =>
        array (
          0 => 'datetime',
          1 => 'entity_browser',
          2 => 'field_group',
          3 => 'paragraphs',
          4 => 'path',
          5 => 'text',
          6 => 'workbench_moderation',
        ),
    ),
  'third_party_settings' =>
    array (
      'field_group' =>
        array (
          'group_onglets' =>
            array (
              'children' =>
                array (
                  0 => 'group_write',
                  1 => 'group_classify',
                  2 => 'group_seo',
                  3 => 'group_publish',
                ),
              'parent_name' => '',
              'weight' => 0,
              'format_type' => 'tabs',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'direction' => 'vertical',
                ),
              'label' => 'Onglets',
            ),
          'group_write' =>
            array (
              'children' =>
                array (
                  0 => 'langcode',
                  1 => 'title',
                  2 => 'field_display_title',
                  3 => 'field_highlight',
                  4 => 'field_top_zone',
                  5 => 'field_top_zone_background',
                  6 => 'field_related_content',
                  7 => 'field_content',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 7,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Write',
            ),
          'group_seo' =>
            array (
              'children' =>
                array (
                  0 => 'field_meta_title',
                  1 => 'field_meta_description',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 9,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'SEO',
            ),
          'group_classify' =>
            array (
              'children' =>
                array (
                  0 => 'field_region',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 8,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Classify',
            ),
          'group_publish' =>
            array (
              'children' =>
                array (
                  0 => 'field_content_owner',
                  1 => 'field_email_owner',
                  2 => 'group_content_worthy_period',
                  3 => 'promote',
                  4 => 'path',
                ),
              'parent_name' => 'group_onglets',
              'weight' => 10,
              'format_type' => 'tab',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'formatter' => 'closed',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Publish',
            ),
          'group_content_worthy_period' =>
            array (
              'children' =>
                array (
                  0 => 'field_start_date',
                  1 => 'field_end_date',
                ),
              'parent_name' => 'group_publish',
              'weight' => 18,
              'format_type' => 'fieldset',
              'format_settings' =>
                array (
                  'id' => '',
                  'classes' => '',
                  'description' => '',
                  'required_fields' => true,
                ),
              'label' => 'Content worthy period',
            ),
        ),
    ),
  'id' => 'node.country.default',
  'targetEntityType' => 'node',
  'bundle' => 'country',
  'mode' => 'default',
  'content' =>
    array (
      'field_content' =>
        array (
          'weight' => 10,
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'text_textarea',
          'region' => 'content',
        ),
      'field_content_owner' =>
        array (
          'weight' => 16,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
          'region' => 'content',
        ),
      'field_display_title' =>
        array (
          'weight' => 4,
          'settings' =>
            array (
              'display_label' => true,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'boolean_checkbox',
          'region' => 'content',
        ),
      'field_email_owner' =>
        array (
          'weight' => 17,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
          'region' => 'content',
        ),
      'field_end_date' =>
        array (
          'weight' => 14,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
          'region' => 'content',
        ),
      'field_highlight' =>
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
          'region' => 'content',
        ),
      'field_industry' =>
        array (
          'weight' => 35,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
          'region' => 'content',
        ),
      'field_job_profile' =>
        array (
          'weight' => 28,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
          'region' => 'content',
        ),
      'field_local_nav' =>
        array (
          'type' => 'text_textarea',
          'weight' => 6,
          'region' => 'content',
          'settings' =>
            array (
              'rows' => 5,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_market_segment' =>
        array (
          'weight' => 29,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
          'region' => 'content',
        ),
      'field_meta_description' =>
        array (
          'weight' => 34,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
          'region' => 'content',
        ),
      'field_meta_title' =>
        array (
          'weight' => 33,
          'settings' =>
            array (
              'size' => 60,
              'placeholder' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'string_textfield',
          'region' => 'content',
        ),
      'field_region' =>
        array (
          'weight' => 36,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
          'region' => 'content',
        ),
      'field_related_content' =>
        array (
          'weight' => 9,
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
        ),
      'field_solution' =>
        array (
          'weight' => 32,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'options_select',
          'region' => 'content',
        ),
      'field_start_date' =>
        array (
          'weight' => 13,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'datetime_default',
          'region' => 'content',
        ),
      'field_top_zone' =>
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
          'type' => 'text_textarea',
          'region' => 'content',
        ),
      'field_top_zone_background' =>
        array (
          'type' => 'entity_browser_entity_reference',
          'region' => 'content',
          'weight' => 7,
          'settings' =>
            array (
              'entity_browser' => 'browse_media_modal',
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
          'weight' => 2,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'region' => 'content',
        ),
      'path' =>
        array (
          'type' => 'path',
          'weight' => 20,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'region' => 'content',
        ),
      'promote' =>
        array (
          'type' => 'boolean_checkbox',
          'settings' =>
            array (
              'display_label' => true,
            ),
          'weight' => 19,
          'third_party_settings' =>
            array (
            ),
          'region' => 'content',
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
          'region' => 'content',
        ),
      'uid' =>
        array (
          'type' => 'entity_reference_autocomplete',
          'weight' => 1,
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
      'field_visual' => true,
      'sticky' => true,
    ),
));

##On save
$config_group->save(TRUE);



############################
##Ajout du workflow
$config_group = $config_factory->getEditable('node.type.country');

##On reset
$config_group->setData(array (
  'uuid' => 'd41b95f2-6aa0-464e-92f0-339b8c74143a',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'menu_ui',
          1 => 'workbench_access',
          2 => 'workbench_moderation',
        ),
    ),
  'third_party_settings' =>
    array (
      'menu_ui' =>
        array (
          'available_menus' =>
            array (
            ),
          'parent' => '',
        ),
      'workbench_access' =>
        array (
          'workbench_access_status' => false,
        ),
      'workbench_moderation' =>
        array (
          'enabled' => true,
          'allowed_moderation_states' =>
            array (
              0 => 'published',
              1 => 'archived',
              2 => 'draft',
              3 => 'needs_review',
              4 => 'unpublished',
            ),
          'default_moderation_state' => 'draft',
        ),
    ),
  'name' => 'Country',
  'type' => 'country',
  'description' => '',
  'help' => '',
  'new_revision' => true,
  'preview_mode' => 1,
  'display_submitted' => false,
));

##On save
$config_group->save(TRUE);
