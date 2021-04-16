<?php

$terms = array(
  //Market Segment pour DVI
  array( 'vid' => 'market_segments', 'name' => 'Secteur Public', 'rename' => 'secteur-public', 'language' => 'fr'),
  array( 'vid' => 'market_segments', 'name' => '- 50 salariés', 'rename' => 'moins-50-salaries', 'language' => 'fr'),
  array( 'vid' => 'market_segments', 'name' => '+ 50 salariés', 'rename' => 'plus-50-salaries', 'language' => 'fr'),
  array( 'vid' => 'market_segments', 'name' => '+ 250 salariés', 'rename' => 'plus-250-salaries', 'language' => 'fr'),
  array( 'vid' => 'market_segments', 'name' => 'Public Sector', 'rename' => 'public-sector', 'language' => 'en'),
  array( 'vid' => 'market_segments', 'name' => '- 50 employees', 'rename' => 'less-50-employees', 'language' => 'en'),
  array( 'vid' => 'market_segments', 'name' => '+ 50 employees', 'rename' => 'more-50-employees', 'language' => 'en'),
  array( 'vid' => 'market_segments', 'name' => '+ 250 employees', 'rename' => 'more-250-employees', 'language' => 'en'),
);

foreach ($terms as $term)
{
  //vérification de l'existance du terme pour ce vocabulaire
  $query = \Drupal::entityQuery('taxonomy_term');
  $query->condition('vid', $term['vid']);
  $query->condition('langcode', $term['language']);
  $query->condition('name', $term['name']);
  $entity = $query->execute();

  if (isset($entity) && !empty($entity))
  {
    //s'il n'existe pas on le crée
    $newTerm = \Drupal\taxonomy\Entity\Term::load(key($entity));
    $newTerm->set('name', $term['rename']);
    $newTerm->save();
    drupal_set_message("-- term market segment renommé :  ".$term['name']." en ".$term['rename'], "status");

  }
}