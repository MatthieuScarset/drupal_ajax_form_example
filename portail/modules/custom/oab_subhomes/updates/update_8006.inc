<?php
/**
 * Création de la view subhome archive
 */


## suppression de l'ancienne vue (possiblement créées sur dev et certains environnements)
$old_view = \Drupal\views\Entity\View::load('subhome_archive');
if ($old_view === null) {
    $view->delete();
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

\Drupal::service('path.alias_storage')->save("/subhome-archive-press", "/presse/archives", "fr");
\Drupal::service('path.alias_storage')->save("/subhome-archive-press", "/press/archives", "en");
