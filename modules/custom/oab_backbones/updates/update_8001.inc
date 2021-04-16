<?php

$fs = \Drupal::service('file_system');
if (!is_dir(\Drupal\oab_backbones\Classes\ImportShadowSites::IMPORT_DIRECTORY)) {
    $fs->mkdir(\Drupal\oab_backbones\Classes\ImportShadowSites::IMPORT_DIRECTORY, NULL, TRUE);
}

if (!is_dir(\Drupal\oab_backbones\Classes\ImportPerformanceData::IMPORT_DIRECTORY)) {
    $fs->mkdir(\Drupal\oab_backbones\Classes\ImportPerformanceData::IMPORT_DIRECTORY, NULL, TRUE);
}
if (!is_dir(\Drupal\oab_backbones\Classes\ImportPerformanceData::IMPORT_TMP_DIRECTORY)) {
    $fs->mkdir(\Drupal\oab_backbones\Classes\ImportPerformanceData::IMPORT_TMP_DIRECTORY, NULL, TRUE);
}

drupal_set_message("Création des répertoires effectuée", 'status');