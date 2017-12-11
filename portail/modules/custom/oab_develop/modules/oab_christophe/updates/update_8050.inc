<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

// sauvegarder les entity reference du champ "field_partner_type" pour les partenaires
// exporter le form display et le view display
// supprimer le champ du type de contenu partenaires
// créer le storage pour le champ => OK
// créer le champ du type de contenu partenaires => OK
// importer les form display et view display
// reinjecter les données sauvegardées
// importer la config de views

$field_storage = FieldStorageConfig::loadByName('node', 'field_partner_type');
if (!empty($field_storage)){
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
if(empty($field)) {
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

oabt_YmlImport('views.view.subhomes.yml');