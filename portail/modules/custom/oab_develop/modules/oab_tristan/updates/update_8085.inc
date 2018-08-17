<?php

use Drupal\oab_subhomes\Entity\SubhomeEntity;
use Drupal\oab_subhomes\Entity\SubhomeEntityType;

$type_id = 'presse';


$entity_type = SubhomeEntityType::load($type_id);
if ($entity_type === null) {
    $entity_type = SubhomeEntityType::create([
        'id' => $type_id,
        'label' => 'Presse'
    ]);
    $entity_type->save();
}

$terms_fr = taxonomy_term_load_multiple_by_name('Presse', 'subhomes');
if (is_array($terms_fr) && count($terms_fr) > 0 ) {
    // je recupère la 1er occurence (qui est sensée être la seule)
    // pour recuperer l'id de la subhome a setter
    $sid = key($terms_fr);

    $entity = SubhomeEntity::create([
        'type'        => $type_id,
        'name'         => "Presse FR",
        'langcode'      => 'fr',
        'title'         => 'Espace Presse',
        'description'   => "Coucou c'est nous :) ",
        'subhome_id'    => $sid
    ]);
    $entity->save();
}

$terms_en = taxonomy_term_load_multiple_by_name('Press', 'subhomes');
if (is_array($terms_en) && count($terms_en) > 0 ) {
    $sid = 0;

    /** @var Drupal\taxonomy\Entity\Term $term */
    foreach ($terms_en as $term) {
        if ($term->language()->getId() == 'en') {
            $sid = $term->id();
        }
    }

    if ($sid !== 0 ) {
        $entity = SubhomeEntity::create([
            'type' => $type_id,
            'name' => "Presse EN",
            'langcode' => 'en',
            'title' => 'Press',
            'description' => "What's up guys ?????",
            'subhome_id' => $sid
        ]);
        $entity->save();
    }
}

//Ajout de la langue dans les forms du type Press :
oabt_YmlImport('language.content_settings.subhome_entity.presse.yml');
