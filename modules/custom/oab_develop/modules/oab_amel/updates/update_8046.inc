<?php

$vid= 'subhomes';
$languages = array('es','pt-br');
$terms = array(
    array('name'=> 'Blogs', 'conf' => 'blog_term_tid', 'tid' => 0),
    array('name'=> 'Press', 'conf' => 'press_term_tid', 'tid' => 0),
    array('name'=> 'Library', 'conf' => 'library_term_tid', 'tid' => 0),
    array('name'=> 'Case Studies', 'conf' => 'customer_term_tid', 'tid' => 0),
);

foreach ($languages as $lang)
{
    foreach ($terms as $key => $term) {
        //vérification de l'existance du terme pour ce vocabulaire
        $query = \Drupal::entityQuery('taxonomy_term');
        $query->condition('vid', $vid);
        $query->condition('langcode', $lang);
        $query->condition('name', $term['name']);
        $entity = $query->execute();

        if (!isset($entity) || empty($entity)) {
            //s'il n'existe pas on le crée
            $newTerm = \Drupal\taxonomy\Entity\Term::create([
                'vid' => $vid,
                'name' => $term['name'],
                'langcode' => $lang,
            ]);
            $newTerm->save();
            $terms[$key]['tid'] = $newTerm->id();
            drupal_set_message("-- term subhomes :  " . $term['name'] . " (" . $lang . ") et tid = " . $terms[$key]['tid'] . " créé ", "status");
        }
    }

    $Config = array();
    $collection = \Drupal::service('config.storage')->createCollection('language.' . $lang);
    $Config = $collection->read('oab_subhomes.subhomes');
    foreach ($terms as $key => $term) {
        $Config[$term['conf']] =$term['tid'];
    }
    $collection->write('oab_subhomes.subhomes', $Config);

}



