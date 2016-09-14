<?php

use Drupal\Core\Database\Database;

$connection = Database::getConnection();
$query = $connection->select('taxonomy_term_field_data', 't')
  ->fields('t', array('tid'))
  ->condition('t.vid', 'rendering_model')
  ->condition('t.name', 'Case study');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

if (empty($results)){
  $term = \Drupal\taxonomy\Entity\Term::create(array(
    'vid' => 'rendering_model',
    'name' => 'Case study',
    'langcode' => 'und',
    'field_machine_name' => 'case_study',
  ));
  $term->save();
}
