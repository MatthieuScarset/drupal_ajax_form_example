<?php

$view = \Drupal\views\Entity\View::load('subhome_archive');

if ($view === null) {
    $view = \Drupal\views\Entity\View::create([
        'langcode' => 'en',
        'id'=> 'subhome_archive',
        'label'=> 'Subhome Archive',
        'module' => 'views',
        'base_table' => 'node_field_data',
        'base_field' => 'nid'
    ]);

    $view->save();
}

oabt_YmlImport('views.view.subhome_archive.yml');

