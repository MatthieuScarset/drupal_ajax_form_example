<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.field.node.container.field_rendering_model');
$config->set('label', 'Model');
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_form_display.node.container.default');
$config->set('third_party_settings', array(
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
              5 => 'group_date_fieldset',
              6 => 'path',
            ),
          'parent_name' => 'group_onglets',
          'weight' => 1,
          'label' => 'Général',
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
          'label' => 'Taxonomie',
          'format_type' => 'tab',
          'format_settings' =>
            array (
              'open' => false,
              'required_fields' => true,
              'classes' => '',
              'id' => '',
              'formatter' => 'closed',
              'description' => '',
              'direction' => 'vertical',
            ),
        ),
      'group_medias' =>
        array (
          'children' =>
            array (
              0 => 'field_image',
            ),
          'parent_name' => 'group_onglets',
          'weight' => 3,
          'label' => 'Médias',
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
      'group_contenu' =>
        array (
          'children' =>
            array (
              0 => 'field_content_field',
            ),
          'parent_name' => 'group_onglets',
          'weight' => 4,
          'label' => 'Contenu',
          'format_type' => 'tab',
          'format_settings' =>
            array (
              'formatter' => 'closed',
              'description' => '',
              'classes' => '',
              'id' => '',
              'required_fields' => true,
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
          'weight' => 6,
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
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_blog');
$config->set('cardinality', -1);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_customer_story');
$config->set('cardinality', -1);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_industry');
$config->set('cardinality', -1);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_magazine');
$config->set('cardinality', -1);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_partner');
$config->set('cardinality', -1);
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.storage.node.field_solution');
$config->set('cardinality', -1);
$config->save(TRUE);


//throw new \Drupal\Core\Utility\UpdateException();