<?php

$terms = array(
    //Subhome pour DVI
    array( 'vid' => 'subhomes', 'name' => 'Produits DVI', 'language' => 'fr'),
    array( 'vid' => 'subhomes', 'name' => 'Products DVI', 'language' => 'en'),
);

foreach ($terms as $term)
{
    //vérification de l'existance du terme pour ce vocabulaire
    $query = \Drupal::entityQuery('taxonomy_term');
    $query->condition('vid', $term['vid']);
    $query->condition('langcode', $term['language']);
    $query->condition('name', $term['name']);
    $entity = $query->execute();

    if(!isset($entity) || empty($entity))
    {
        //s'il n'existe pas on le crée
        $newTerm = \Drupal\taxonomy\Entity\Term::create([
            'vid' => $term['vid'],
            'name' => $term['name'],
            'langcode' => $term['language'],
        ]);
        $newTerm->save();
        drupal_set_message("-- term subhome :  ".$term['name']." (".$term['language'].") créé ", "status");

    }
}