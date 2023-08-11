<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Symfony\Component\Yaml\Yaml;
use Drupal\menu_link_content\Entity\MenuLinkContent;

$config_factory = \Drupal::configFactory();

############################
$field_storage = FieldStorageConfig::loadByName('node', 'field_title_color');
if (empty($field_storage)) {
  $field_storage = FieldStorageConfig::create(array(
    'field_name' => 'field_title_color',
    'entity_type' => 'node',
    'type' => 'list_string',
    'module' => 'options',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'allowed_values' => array(),
    'allowed_values_function'=> 'oab_tristan_allowed_values_function',
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  ));
  $field_storage->save();
}

$field = FieldConfig::loadByName('node', 'homepage', 'field_title_color');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_title_color',
    'entity_type' => 'node',
    'bundle' => 'homepage',
    'label' => 'Title color',
    'description' => 'Select the color of the title and the subhead title',
    'required' => true,
    'translatable' => false,
    'default_value' =>
      array (
        0 =>
          array (
            'value' => 'white',
          ),
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'list_string',
  );
  FieldConfig::create($config_array)->save();
}


loadConfigField('field/field', 'field.field.node.homepage.field_title_color');
loadConfigField('field/storage', 'field.storage.node.field_title_color');


##Je les crée avec la base, puis je charge la config complète

#PARTNERS BUTTON TEXT
$field_storage = FieldStorageConfig::loadByName('node', 'field_partners_button_text');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_partners_button_text',
    'entity_type' => 'node',
    'type' => 'string',
  ))->save();
}

$field = FieldConfig::loadByName('node', 'homepage', 'field_partners_button_text');
if (empty($field)) {
  $config_array = array(
    'field_name' =>  'field_partners_button_text',
    'entity_type' => 'node',
    'bundle' => 'homepage',
    'label' => 'Button text',
    'required' => false,
  );
  FieldConfig::create($config_array)->save();
}
loadConfigField('field/field', 'field.field.node.homepage.field_partners_button_text');
loadConfigField('field/storage', 'field.storage.node.field_partners_button_text');


#CORPORATE BUTTON TEXT
$field_storage = FieldStorageConfig::loadByName('node', 'field_corporate_button_text');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_corporate_button_text',
    'entity_type' => 'node',
    'type' => 'string',
  ))->save();
}

$field = FieldConfig::loadByName('node', 'homepage', 'field_corporate_button_text');
if (empty($field)) {
  $config_array = array(
    'field_name' =>  'field_corporate_button_text',
    'entity_type' => 'node',
    'bundle' => 'homepage',
    'label' => 'Button text',
    'required' => false,
  );
  FieldConfig::create($config_array)->save();
}
loadConfigField('field/field', 'field.field.node.homepage.field_corporate_button_text');
loadConfigField('field/storage', 'field.storage.node.field_corporate_button_text');




// import VIEW DISPLAY FULL
$config_path = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_backoffice') . '/config/core/entity_view_display/core.entity_view_display.node.homepage.full.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_view_display.node.homepage.full')->setData($data)->save(TRUE);

// import FORM DISPLAY DEFAULT
$config_path = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_backoffice') . '/config/core/entity_form_display/core.entity_form_display.node.homepage.default.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('core.entity_form_display.node.homepage.default.yml')->setData($data)->save(TRUE);

