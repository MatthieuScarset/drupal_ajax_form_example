<?php
/**
 * Création de la view subhome archive
 */


## suppression de l'ancienne vue (possiblement créées sur dev et certains environnements)
$old_view = \Drupal\views\Entity\View::load('subhome_archive');
if ($old_view !== null) {
    $old_view->delete();
}


## Création de la nouvelle vue
$view = \Drupal\views\Entity\View::load('subhomes_archive');

if ($view === null) {
    $view = \Drupal\views\Entity\View::create([
        'langcode' => 'en',
        'id'=> 'subhomes_archive',
        'label'=> 'Subhome Archive',
        'module' => 'views',
        'base_table' => 'node_field_data',
        'base_field' => 'nid'
    ]);

    $view->save();
}

oabt_YmlImport('views.view.subhomes_archive.yml');




$trad = array (
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
                                            'submit_button' => 'Filtrer',
                                        ),
                                ),
                            'empty' =>
                                array (
                                    'area' =>
                                        array (
                                            'content' =>
                                                array (
                                                    'value' => '<p>Aucun élément ne correspond à votre requête. Veuillez élargir votre recherche.</p>it ',
                                                    'format' => 'full_html',
                                                ),
                                        ),
                                ),
                        ),
                ),
        ),
);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('views.view.subhomes_archive', $trad);



\Drupal::service('path.alias_storage')->save("/subhome-archive-press", "/presse/archives", "fr");
\Drupal::service('path.alias_storage')->save("/subhome-archive-press", "/press/archives", "en");
