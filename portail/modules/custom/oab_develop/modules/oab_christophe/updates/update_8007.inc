<?php

use \Drupal\taxonomy\Entity\Term;

$terms = array(
  'document' => 'Document',
  'magazine_interview' => 'Magazine interview',
  'press_kit' => 'Press kit',
  'press_release' => 'Press release',
  'simple_page' => 'Simple page',
);

foreach ($terms as $machine_name => $name)
{
  //vérification de l'existance du terme pour ce vocabulaire
  $query = \Drupal::entityQuery('taxonomy_term');
  $query->condition('vid', 'rendering_model');
  $query->condition('field_machine_name', $machine_name);
  $entity = $query->execute();

  if(!isset($entity) || empty($entity))
  {
    //s'il n'existe pas on le crée
    $newTerm = Term::create([
      'vid' => 'rendering_model',
      'name' => $name,
      'langcode' => 'und',
      'field_machine_name' => $machine_name,
    ]);
    $newTerm->save();
    drupal_set_message("-- ".$name." créé ", "status");
  }
}

//throw new \Drupal\Core\Utility\UpdateException();