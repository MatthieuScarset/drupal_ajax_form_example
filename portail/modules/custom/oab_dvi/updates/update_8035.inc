<?php

$terms = array(
    //Subhome pour DVI
    array( 'vid' => 'subhomes', 'name' => 'Produits DVI', 'language' => 'fr'),
    array( 'vid' => 'subhomes', 'name' => 'Products DVI', 'language' => 'en'),
);

$termsTID = array();
foreach ($terms as $term) {
    //vérification de l'existance du terme pour ce vocabulaire
    $query = \Drupal::entityQuery('taxonomy_term');
    $query->condition('vid', $term['vid']);
    $query->condition('langcode', $term['language']);
    $query->condition('name', $term['name']);
    $entity = $query->execute();

    if (!isset($entity) || empty($entity)) {
        //s'il n'existe pas on le crée
        $newTerm = \Drupal\taxonomy\Entity\Term::create([
            'vid' => $term['vid'],
            'name' => $term['name'],
            'langcode' => $term['language'],
        ]);
        $newTerm->save();
        $termsTID[$term["language"]] = $newTerm->id();
        drupal_set_message("-- term subhome :  ".$term['name']." (".$term['language'].") créé ", "status");

    } else {
        $termsTID[$term["language"]] = key($entity);
    }

}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->set('product_dvi_term_tid', $termsTID["en"]);
$config_group->save(TRUE);


$FRConfig = array();
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$FRConfig = $collection->read('oab_subhomes.subhomes');
$FRConfig["product_dvi_term_tid"] = $termsTID["fr"];
$collection->write('oab_subhomes.subhomes', $FRConfig);


