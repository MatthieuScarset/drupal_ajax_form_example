<?php

## Ajout des related display view dans les subhome
##la liste des termes et du nom de la sous-vue correspondante
$termList = [
    "Products DVI"      => "page_catalogue_dvi",
    "Produits DVI"      => "page_catalogue_dvi",
    "Distributeurs"     => "page_distributor",
    "Distributors"      => "page_distributor"
];

##On boucle sur tous les termes de la taxo Subhomes
foreach ($termList as $taxoTerm => $display_view) {

    ##on cherche l'Objet
    $termsArray = taxonomy_term_load_multiple_by_name($taxoTerm, "subhomes");

    ##On boucle sur tous les termes trouvés (Magazine par exemple..)
    foreach ($termsArray as $term_id => $termObject) {
        #related_display_view
        $termObject->set('field_related_display_view', $display_view);
        $termObject->save();
    }
}


##Je recharge view pour mettre à jour les titres Products DVI et Distributeurs
oabt_YmlImport('views.view.subhomes.yml');


##Ajout des trads de la vue

$trads = array (
    'display' =>
        array (
            'page_press' =>
                array (
                    'display_title' => 'Presse',
                ),
            'page_catalogue' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Produits',
                        ),
                    'display_title' => 'Produits',
                ),
            'page_customer' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Témoignage client',
                        ),
                    'display_title' => 'Témoignage client',
                ),
            'page_document' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Médiathèque',
                        ),
                    'display_title' => 'Médiathèque',
                ),
            'page_partners' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Partenaires',
                        ),
                    'display_title' => 'Partenaires',
                ),
            'default' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Presse',
                        ),
                ),
            'page_catalogue_dvi' =>
                array (
                    'display_title' => 'Produits DVI',
                    'display_options' =>
                        array (
                            'title' => 'Produits DVI',
                        ),
                ),
            'page_distributor' =>
                array (
                    'display_title' => 'Distributeurs',
                    'display_options' =>
                        array (
                            'title' => 'Distributeurs',
                        ),
                ),
        ),
);
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('views.view.subhomes',$trads);
