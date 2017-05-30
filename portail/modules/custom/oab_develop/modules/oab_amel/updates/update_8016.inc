<?php
/*
//taxonomy.vocabulary.products
array (
    'uuid' => 'f088b03e-2f0e-4dda-a1be-7fc7069c0d1b',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
        ),
    'name' => 'Products',
    'vid' => 'products',
    'description' => '',
    'hierarchy' => 0,
    'weight' => 0,
)
    //language.content_settings.taxonomy_term.products

    array (
        'uuid' => '374beeb4-2feb-48a3-87cf-3fbc9b447298',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'taxonomy.vocabulary.products',
                    ),
            ),
        'id' => 'taxonomy_term.products',
        'target_entity_type_id' => 'taxonomy_term',
        'target_bundle' => 'products',
        'default_langcode' => 'site_default',
        'language_alterable' => false,
    )
*/

// Ajout du nouveau vocabulaire de taxonomie : products
$vids_to_add = array('products' => 'Products');
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
foreach ($vids_to_add as $vid => $name){
    if (!isset($vocabularies[$vid]) ) {
        $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
            'vid' => $vid,
            'name' => $name
        ));
        $vocabulary->save();
    }
}

