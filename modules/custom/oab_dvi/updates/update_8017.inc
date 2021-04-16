<?php

$terms = array(
    array("language" => "fr", "name" => "Distributeurs", "variable" => "distributor_term_tid"),
    array("language" => "en", "name" => "Distributors", "variable" => "distributor_term_tid"),
);

$FRConfig = array();
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$FRConfig = $collection->read('oab_subhomes.subhomes');
foreach ($terms as &$term) {
    $term_id = "";
    //vérification de l'existance du terme pour ce vocabulaire
    $query = \Drupal::entityQuery('taxonomy_term');
    $query->condition('vid', "subhomes");
    $query->condition('langcode', $term['language']);
    $query->condition('name', $term['name']);
    $entity = $query->execute();

    if (!isset($entity) || empty($entity)) {
        //s'il n'existe pas on le crée
        $entity = \Drupal\taxonomy\Entity\Term::create([
            'vid' => "subhomes",
            'name' => $term['name'],
            'langcode' => $term['language'],
        ]);
        $entity->save();
        drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
        $term_id = $entity->id();
    } else {
        $term_id = key($entity);
    }

    if ($term['language'] == 'en') {
        $config_factory = \Drupal::configFactory();
        $config_group = $config_factory->getEditable('oab_subhomes.subhomes');
        $config_group->set('distributor_term_tid', $term_id);
        $config_group->save(TRUE);
    } elseif ($term['language'] == 'fr') {
        $FRConfig[$term['variable']] = $term_id;
        $collection->write('oab_subhomes.subhomes', $FRConfig);
    }
}


oabt_YmlImport("views.view.product_autocomplete.yml");
oabt_YmlImport("field.field.node.distributor.field_products.yml");


oabt_YmlImport("node.type.distributor.yml");









