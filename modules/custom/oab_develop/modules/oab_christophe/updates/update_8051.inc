<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

// sauvegarder les entity reference du champ "field_partner_type" pour les partenaires => OK
// exporter le form display et le view display => OK
// supprimer le champ du type de contenu partenaires => OK
// créer le storage pour le champ => OK
// créer le champ du type de contenu partenaires => OK
// importer les form display et view display => OK
// reinjecter les données sauvegardées => OK
// importer la config de views => OK

$nids = \Drupal::entityQuery('node')->condition('type','partner')->execute();
$nodes =  \Drupal\node\Entity\Node::loadMultiple($nids);

$saved_values = array();

if (is_array($nodes)
&& !empty($nodes)) {
  foreach ($nodes AS $node) {
    $field_partner_type = $node->get('field_partner_type');
    $saved_values[$node->id()] = $field_partner_type->getValue();
  }
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.partner.default');
$partner_form_display = $config_group->getRawData();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$partner_view_display_default = $config_group->getRawData();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.related_content');
$partner_view_display_related_content = $config_group->getRawData();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.right_linked_content');
$partner_view_display_right_linked_content = $config_group->getRawData();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.subhome');
$partner_view_display_subhome = $config_group->getRawData();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.teaser');
$partner_view_display_teaser = $config_group->getRawData();

$field_storage = FieldStorageConfig::loadByName('node', 'field_partner_type');
if (!empty($field_storage)) {
  $field_storage->delete();

  FieldStorageConfig::create(array(
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
            1 => 'taxonomy',
          ),
      ),
    'id' => 'node.field_partner_type',
    'field_name' => 'field_partner_type',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'taxonomy_term',
      ),
    'module' => 'core',
    'locked' => false,
    'cardinality' => -1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  ))->save();
}

$field = FieldConfig::loadByName('node', 'partner', 'field_partner_type');
if (empty($field)) {
  $config_array = array(
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_partner_type',
            1 => 'node.type.partner',
            2 => 'taxonomy.vocabulary.partner_types',
          ),
      ),
    'id' => 'node.partner.field_partner_type',
    'field_name' => 'field_partner_type',
    'entity_type' => 'node',
    'bundle' => 'partner',
    'label' => 'Partner type',
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
                'partner_types' => 'partner_types',
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
  FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.partner.default');
$config_group->setData($partner_form_display);
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$config_group->setData($partner_view_display_default);
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.related_content');
$config_group->setData($partner_view_display_related_content);
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.right_linked_content');
$config_group->setData($partner_view_display_right_linked_content);
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.subhome');
$config_group->setData($partner_view_display_subhome);
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.teaser');
$config_group->setData($partner_view_display_teaser);
$config_group->save();


if (is_array($nodes)
  && !empty($nodes)) {
  foreach ($nodes AS $node) {
    $node->set('field_partner_type', $saved_values[$node->id()]);
    $node->save();
  }
}


oabt_YmlImport('views.view.subhomes.yml');