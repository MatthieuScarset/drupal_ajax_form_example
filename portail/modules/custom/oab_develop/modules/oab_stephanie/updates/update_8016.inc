<?php

use \Drupal\taxonomy\Entity\Vocabulary;
use \Drupal\taxonomy\Entity\Term;

/***********************************************
 * 1. Création de la nouvelle TAXONOMIE Section
 ***********************************************/
$vid = "sections";
$name = "Sections";
$vocabularies = Vocabulary::loadMultiple();
drupal_set_message("- Vocabulaires chargés", "status");
//On regarde s'il existe
if (!isset($vocabularies[$vid]))
{
  //s'il n'existe pas on le crée
  drupal_set_message("-- taxonomie ".$vid." NON existante", "status");
  $vocabulary = Vocabulary::create(array(
    'vid' => $vid,
    'machine_name' => $vid,
    'name' => $name,
    'langcode' => 'en'
  ));
  $vocabulary->save();
  drupal_set_message("-- taxonomie ".$vid." créée ", "status");
}
else {
  // il existe déjà
  drupal_set_message("-- taxonomie ".$vid." existante", "status");
}

/***********************************
 * 2. Champ machine name
 ************************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.taxonomy_term.sections.field_machine_name');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.taxonomy_term.field_machine_name',
            1 => 'taxonomy.vocabulary.sections',
          ),
      ),
    'id' => 'taxonomy_term.sections.field_machine_name',
    'field_name' => 'field_machine_name',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'sections',
    'label' => 'Machine name',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'string',
  ));
$config_group->save(TRUE);

/***********************************
 * 3. Config formulaire
 ************************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.taxonomy_term.sections.default');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.sections.field_machine_name',
            1 => 'taxonomy.vocabulary.sections',
          ),
        'module' =>
          array (
            0 => 'path',
            1 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.sections.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'sections',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
          array (
            'type' => 'text_textfield',
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
        'field_machine_name' =>
          array (
            'weight' => 31,
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
        'name' =>
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
      ),
    'hidden' =>
      array (
      ),

  ));
$config_group->save(TRUE);

/***********************************
 * 4. Config display
 ************************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.taxonomy_term.sections.default');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.sections.field_machine_name',
            1 => 'taxonomy.vocabulary.sections',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.sections.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'sections',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
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
        'field_machine_name' =>
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
      ),
    'hidden' =>
      array (
        'langcode' => true,
      ),

  ));
$config_group->save(TRUE);

/***************************************
 * 5. Configuration langue vocabulaire
 ***************************************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.taxonomy_term.sections');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'taxonomy.vocabulary.sections',
          ),
      ),
    'id' => 'taxonomy_term.sections',
    'target_entity_type_id' => 'taxonomy_term',
    'target_bundle' => 'sections',
    'default_langcode' => 'current_interface',
    'language_alterable' => true,
  ));
$config_group->save(TRUE);

/***************************************
 * 6. Création des termes FR
 ***************************************/
$termsFR = array('corporate' => 'Corporate',
                 'business_solutions' => 'Solutions business',
                 'products_services' => 'Produits et services',
                 'realtimes' => 'Eclairages');

foreach ($termsFR as $machine_name => $name)
{
  //vérification de l'existance du terme pour ce vocabulaire
  $query = \Drupal::entityQuery('taxonomy_term');
  $query->condition('langcode', 'fr');
  $query->condition('vid', $vid);
  $query->condition('field_machine_name', $machine_name);
  $entity = $query->execute();

  if(!isset($entity) || empty($entity))
  {
    //s'il n'existe pas on le crée
    $newTerm = Term::create([
      'vid' => $vid,
      'name' => $name,
      'langcode' => 'fr',
      'field_machine_name' => $machine_name,
    ]);
    $newTerm->save();
    drupal_set_message("-- ".$name." (FR) créé ", "status");
  }
}

/***************************************
 * 7. Création des termes EN
 ***************************************/

$termsEN = array('corporate' => 'Corporate',
  'business_solutions' => 'Business Solutions',
  'products_services' => 'Products and services',
  'realtimes' => 'Realtimes');

foreach ($termsEN as $machine_name => $name)
{
  //vérification de l'existance du terme pour ce vocabulaire
  $query = \Drupal::entityQuery('taxonomy_term');
  $query->condition('langcode', 'en');
  $query->condition('vid', $vid);
  $query->condition('field_machine_name', $machine_name);
  $entity = $query->execute();

  if(!isset($entity) || empty($entity))
  {
    //s'il n'existe pas on le crée
    $newTerm = Term::create([
      'vid' => $vid,
      'name' => $name,
      'langcode' => 'en',
      'field_machine_name' => $machine_name,
    ]);
    $newTerm->save();
    drupal_set_message("-- ".$name." (EN) créé ", "status");
  }
}

return '';