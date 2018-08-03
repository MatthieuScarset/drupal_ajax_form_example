<?php

/**
 * Implements hook_drush_command().
 * Méthode permettant d'importer les données de D7
 */
function oab_backbones_drush_command() {
    $items = array();
    $items['backbones-import'] = [
        'description' => 'Import Backbones data from D7 to D8',
        'drupal dependencies' => ['oab_backbones'],
        'aliases' => ['backbones:import'],
    ];
    return $items;
}

/**
 * Méthode appelée par Drush lorsqu'on lance drush backbones-import
 */
function drush_oab_backbones_backbones_import() {

    drush_print('DEBUT backbones import.');
    /***********************/
    /*** Connexion à D7 ****/
    /***********************/
    drush_print('Switch de connexion pour D7');
    \Drupal\Core\Database\Database::setActiveConnection('drupal7');
    $db_d7 = \Drupal\Core\Database\Database::getConnection();

    /**** On fait toutes les requetes SQL sur D7 ****/
    //1. Shadow sites
    drush_print('Récupération des Shadows sites sur D7...');
    $query_shadow_sites = $db_d7->select('obs_backbones_shadowsites', 's')
        ->fields('s');
    $results_sites = $query_shadow_sites->execute()->fetchAll();

    //2. Imports
    drush_print('Récupération de l\'historique des imports sur D7...');
    $query_imports = $db_d7->select('obs_backbones_import', 'i')
        ->fields('i');
    $results_imports = $query_imports->execute()->fetchAll();

    //3. Imports DATA
    drush_print('Récupération des données d\'imports sur D7...');
    $query_imports_data = $db_d7->select('obs_backbones_import_data', 'id')
        ->fields('id');
    $results_imports_data = $query_imports_data->execute()->fetchAll();

    /***********************/
    /*** Connexion à D8 ****/
    /***********************/
    drush_print('Switch de connexion pour D8');
    \Drupal\Core\Database\Database::setActiveConnection();

    //1. Import des sites
    drush_print('Enregistrement des sites sur D8...');
    foreach ($results_sites as $site) {
        $query = \Drupal\Core\Database\Database::getConnection()->merge('oab_backbones_shadowsites')
            ->key(array('sid' => $site->sid))
            ->insertFields(array(
                'sid' => $site->sid,
                'probe_name' => $site->probe_name,
                'site_label' => $site->site_label,
                'used' => $site->used

            ))
            ->updateFields(array(
                'probe_name' => $site->probe_name,
                'site_label' => $site->site_label,
                'used' => $site->used
            ))
            ->execute();
    }

    //2. Import des "Imports"
    drush_print('Enregistrement de l\'historique des imports sur D8...');
    foreach ($results_imports as $import) {
        $query = \Drupal\Core\Database\Database::getConnection()->merge('oab_backbones_import')
            ->key(array('date' => $import->date))
            ->insertFields(array(
                'date' => $import->date,
                'status' => $import->status,
                'comment' => $import->comment
            ))
            ->updateFields(array(
                'status' => $import->status,
                'comment' => $import->comment
            ))
            ->execute();
    }

    //3. Import des datas des "Imports"
    drush_print('Enregistrement des données d\'imports sur D8...');
    foreach ($results_imports_data as $data) {
        $query = \Drupal\Core\Database\Database::getConnection()->merge('oab_backbones_import_data')
            ->key(array('date' => $data->date,
                'source_site' => $data->source_site,
                'destination_site' => $data->destination_site
            ))
            ->insertFields(array(
                "date" => $data->date,
                "source_site" => $data->source_site,
                "source_label" => $data->source_label,
                "destination_site" => $data->destination_site,
                "destination_label" => $data->destination_label,
                "RTD" => $data->RTD,
                "JITTER" => $data->JITTER,
                "PLR" => $data->PLR
            ))
            ->updateFields(array(
                "source_label" => $data->source_label,
                "destination_label" => $data->destination_label,
                "RTD" => $data->RTD,
                "JITTER" => $data->JITTER,
                "PLR" => $data->PLR
            ))
            ->execute();
    }


    drush_print('FIN backbones import.');
}
