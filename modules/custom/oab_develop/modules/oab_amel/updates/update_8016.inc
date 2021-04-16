<?php


// Ajout du nouveau vocabulaire de taxonomie : products


$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::load('products');

    if (!isset($vocabularies)) {
        $vocab = \Drupal\taxonomy\Entity\Vocabulary::create(array(
            'vid' => 'products',
            'name' => 'Products'
        ));
        $vocab->save();
    }


