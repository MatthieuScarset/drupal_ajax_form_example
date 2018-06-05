<?php

/**
 * ajout de trads des mois pour les sites ES et PT-BR
 */

$translations_LMNcontext = array(

    array("source" => "January", "translation" => array("fr" => "janvier", "es" => "Enero", "pt-br" => "Janeiro")),
    array("source" => "February", "translation" => array("fr" => "février", "es" => "Febrero", "pt-br" => "Fevereiro")),
    array("source" => "March", "translation" => array("fr" => "mars", "es" => "Marzo", "pt-br" => "Março")),
    array("source" => "April", "translation" => array("fr" => "avril", "es" => "Abril", "pt-br" => "Abril")),
    array("source" => "May", "translation" => array("fr" => "mai", "es" => "Mayo", "pt-br" => "Maio")),
    array("source" => "June", "translation" => array("fr" => "juin", "es" => "Junio", "pt-br" => "Junho")),
    array("source" => "July", "translation" => array("fr" => "juillet", "es" => "Julio", "pt-br" => "Julho")),
    array("source" => "August", "translation" => array("fr" => "août", "es" => "Agosto", "pt-br" => "Agosto")),
    array("source" => "September", "translation" => array("fr" => "septembre", "es" => "Setiembre", "pt-br" => "Setembro")),
    array("source" => "October", "translation" => array("fr" => "octobre", "es" => "Octubre", "pt-br" => "Outubro")),
    array("source" => "November", "translation" => array("fr" => "novembre", "es" => "Noviembre", "pt-br" => "Novembro")),
    array("source" => "December", "translation" => array("fr" => "décembre", "es" => "Diciembre", "pt-br" => "Dezembro")),
);

$storage = \Drupal::service('locale.storage');

foreach ($translations_LMNcontext AS $translation) {
    $string = $storage->findString(array(
            'source' => $translation['source'],
            'context'  => 'Long month name')
    );
    if (is_null($string)) {
        $string = new SourceString();
        $string->setString($translation['source']);
        $string->setStorage($storage);
        $string->save();
    }

    foreach ($translation['translation'] AS $language => $translated_string) {
        // Create translation. If one already exists, it will be replaced.
        $translation = $storage->createTranslation(array(
            'lid' => $string->lid,
            'language' => $language,
            'translation' => $translated_string
        ))->save();
    }
}


## Rechargement des trads FR/ES/BR pour les subhomes

$conf_fr = array (
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
                            'exposed_form' =>
                                array (
                                    'options' =>
                                        array (
                                            'submit_button' => 'Filtrer',
                                        ),
                                ),
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
$collection->write('views.view.subhomes', $conf_fr);

$conf_es = array (
    'display' =>
        array (
            'default' =>
                array (
                    'display_options' =>
                        array (
                            'exposed_form' =>
                                array (
                                    'options' =>
                                        array (
                                            'submit_button' => 'Aplicar',
                                        ),
                                ),
                            'title' => 'Prensa',
                        ),
                ),
            'page_catalogue' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Producto',
                        ),
                    'display_title' => 'Producto',
                ),
            'page_customer' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Nuestros clientes',
                        ),
                    'display_title' => 'Nuestros clientes',
                ),
            'page_document' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Libreria',
                        ),
                    'display_title' => 'Libreria',
                ),
            'page_distributor' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Distribuidores',
                        ),
                    'display_title' => 'Distribuidores',
                ),
            'page_magazine' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Revista',
                        ),
                    'display_title' => 'Revista',
                ),
            'page_partners' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Socios de negocio',
                        ),
                    'display_title' => 'Socios de negocio',
                ),
            'page_press' =>
                array (
                    'display_title' => 'Prensa',
                ),
        ),
);
$collection = \Drupal::service('config.storage')->createCollection('language.es');
$collection->write('views.view.subhomes', $conf_es);

$conf_br =array (
    'display' =>
        array (
            'default' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Imprensa',
                            'exposed_form' =>
                                array (
                                    'options' =>
                                        array (
                                            'submit_button' => 'Aplique',
                                        ),
                                ),
                        ),
                ),
            'page_catalogue' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Produto',
                        ),
                    'display_title' => 'Produto',
                ),
            'page_customer' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Nossos Clientes',
                        ),
                    'display_title' => 'Nossos Clientes',
                ),
            'page_distributor' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Distribuidores',
                        ),
                    'display_title' => 'Distribuidores',
                ),
            'page_document' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Mediateca',
                        ),
                    'display_title' => 'Mediateca',
                ),
            'page_magazine' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Revista',
                        ),
                    'display_title' => 'Revista',
                ),
            'page_partners' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Parceiros',
                        ),
                    'display_title' => 'Parceiros',
                ),
            'page_press' =>
                array (
                    'display_title' => 'Imprensa',
                ),
        ),
);
$collection = \Drupal::service('config.storage')->createCollection('language.pt-br');
$collection->write('views.view.subhomes', $conf_br);
