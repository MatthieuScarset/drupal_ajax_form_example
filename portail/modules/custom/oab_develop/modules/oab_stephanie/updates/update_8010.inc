<?php

use \Drupal\Core\Utility\UpdateException;
use \Drupal\taxonomy\Entity\Vocabulary;

/**
 * Création de la nouvelle taxonomie pour les documents : Document_type
 */
$vid = "document_types";
$name = "Document types";
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
  ));
  $vocabulary->save();
  drupal_set_message("-- taxonomie ".$vid." créée ", "status");
}
else {
  // il existe déjà
  drupal_set_message("-- taxonomie ".$vid." existante", "status");
}

$vid = "topic";
$name = "Topics";
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
  ));
  $vocabulary->save();
  drupal_set_message("-- taxonomie ".$vid." créée ", "status");
}
else {
  // il existe déjà
  drupal_set_message("-- taxonomie ".$vid." existante", "status");
}

