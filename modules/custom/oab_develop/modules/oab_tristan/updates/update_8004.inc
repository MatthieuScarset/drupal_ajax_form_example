<?php
use \Drupal\Core\Utility\UpdateException;
use Drupal\Core\Database\Database;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;



/***********************
 * Desactivation du module easy-breadcrumb afin de gérer
 * les fils d'ariane par un module perso
 ***********************/
$config_factory = \Drupal::configFactory();

##Je recupère la config des modules
$config_group = $config_factory->getEditable('core.extension');

##Je recupère la liste des modules actifs dans la config
$modules = $config_group->get('module');

##Si je trouve le module easy_breadcrumbre
if (isset($modules['easy_breadcrumb'])) {

  ##Je supprime le module de la config
  unset($modules['easy_breadcrumb']);

  ##je resset le tableau des modules
  $config_group->set('module', $modules);

  ##Je save la config
  $config_group->save(TRUE);

  ##Je recupère la config du module et je la supprime
  $config_easybreadcrumb = $config_factory->getEditable('easy_breadcrumb.settings');
  $config_easybreadcrumb->delete();

}


#################
## Ajout du nouveau field pour les terms des subhomes

$field_storage = FieldStorageConfig::loadByName('taxonomy_term', 'field_related_display_view');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_related_display_view',
    'entity_type' => 'taxonomy_term',
    'type' => 'string',
  ))->save();
}

$field = FieldConfig::loadByName('taxonomy_term', 'subhomes', 'field_related_display_view');
if (empty($field)) {
  $config_array = array(
    'field_name' =>  'field_related_display_view',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'label' => 'related_display_view',
    'required' => TRUE,
  );
  FieldConfig::create($config_array)->save();
}


$config_group = $config_factory->getEditable('field.field.taxonomy_term.subhomes.field_related_display_view');
$config_group->setData(
  array (
    'uuid' => '7a77e91d-f790-4ddc-a603-357484d3613b',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.taxonomy_term.field_related_display_view',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.field_related_display_view',
    'field_name' => 'field_related_display_view',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'label' => 'related_display_view',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'string',
  )
);

$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.storage.taxonomy_term.field_related_display_view');
$config_group->setData(
  array (
    'uuid' => 'e3ccb4c4-5239-44f0-8abd-5eeffa106884',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'taxonomy',
          ),
      ),
    'id' => 'taxonomy_term.field_related_display_view',
    'field_name' => 'field_related_display_view',
    'entity_type' => 'taxonomy_term',
    'type' => 'string',
    'settings' =>
      array (
        'max_length' => 50,
        'is_ascii' => false,
        'case_sensitive' => false,
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
  )

);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_form_display.taxonomy_term.subhomes.default');
$config_group->setData(
  array (
    'uuid' => 'dc3414b1-293e-4271-82c9-3a1cab2e793d',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.subhomes.field_related_display_view',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
        'module' =>
          array (
            0 => 'path',
            1 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
          array (
            'type' => 'text_textarea',
            'weight' => 1,
            'region' => 'content',
            'settings' =>
              array (
                'placeholder' => '',
                'rows' => 5,
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_related_display_view' =>
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
            'region' => 'content',
          ),
        'langcode' =>
          array (
            'type' => 'language_select',
            'weight' => 2,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'name' =>
          array (
            'type' => 'string_textfield',
            'weight' => 0,
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
        'path' =>
          array (
            'type' => 'path',
            'weight' => 3,
            'region' => 'content',
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
      ),
  )
);
$config_group->save(TRUE);


$config_group = $config_factory->getEditable('core.entity_view_display.taxonomy_term.subhomes.default');
$config_group->setData(
  array (
    'uuid' => '89f78ff7-f890-42c0-bd2f-f42725d6c1bc',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.subhomes.field_related_display_view',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
          array (
            'label' => 'hidden',
            'type' => 'text_default',
            'weight' => 0,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_related_display_view' =>
          array (
            'weight' => 3,
            'label' => 'above',
            'settings' =>
              array (
                'link_to_entity' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'string',
            'region' => 'content',
          ),
      ),
    'hidden' =>
      array (
        'langcode' => true,
      ),
  )

);
$config_group->save(TRUE);

##la liste des termes et du nom de la sous-vue correspondante
$termList = [
  "Cas clients"       => "page_customer",
  "Catalogue"         => "page_catalogue",
  "Customer Stories"  => "page_customer",
  "Library"           => "page_document",
  "Magazine"          => "page_magazine",
  "Médiathèque"       => "page_document",
  "Partenaires"       => "page_partners",
  "Partners"          => "page_partners",
  "Portfolio"         => "page_catalogue",
  "Press"             => "page_press",
  "Presse"            => "page_press"
];

##On boucle sur tous les termes de la taxo Subhomes
foreach ($termList as $taxoTerm => $view) {

  ##on cherche l'Objet
//  $termsArray = taxonomy_term_load_multiple_by_name($taxoTerm, "subhomes");
  // Correction depréciation pour exemple
  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $taxoTerm, "vid" => "subhomes"]);

  ##On boucle sur tous les termes trouvés (Magazine par exemple..)
  foreach ($termsArray as $term_id => $termObject) {
    #related_display_view
    $termObject->set('field_related_display_view', $view);

    $termObject->save();

  }
}


#A enlever à la fin des tests
//throw new UpdateException();
