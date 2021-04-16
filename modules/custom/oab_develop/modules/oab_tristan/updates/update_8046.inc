<?php

/**
 * Modification de l'affichage de "Presse" pour le fil d'ariane
 */

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('views.view.subhomes', array (
  'display' =>
    array (
      'page_press' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
            ),
          'display_title' => 'Presse',
        ),
      'page_catalogue' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
              'title' => 'Produits',
            ),
          'display_title' => 'Produits',
        ),
      'page_customer' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                  'field_industry_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par industrie',
                        ),
                    ),
                ),
              'title' => 'Témoignage client',
            ),
          'display_title' => 'Témoignage client',
        ),
      'page_document' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_industry_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par industrie',
                        ),
                    ),
                ),
              'title' => 'Médiathèque',
            ),
          'display_title' => 'Médiathèque',
        ),
      'page_partners' =>
        array (
          'display_options' =>
            array (
              'filters' =>
                array (
                  'field_solution_target_id' =>
                    array (
                      'expose' =>
                        array (
                          'label' => 'Par solution',
                        ),
                    ),
                ),
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
    ),
));
