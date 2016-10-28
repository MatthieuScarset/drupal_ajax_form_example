<?php

if(!is_dir(\Drupal\oab_backbones\Classes\ImportShadowSites::$IMPORT_DIRECTORY))
{
  mkdir(\Drupal\oab_backbones\Classes\ImportShadowSites::$IMPORT_DIRECTORY);
}

if(!is_dir(\Drupal\oab_backbones\Classes\ImportPerformanceData::$IMPORT_DIRECTORY)) {
  mkdir(\Drupal\oab_backbones\Classes\ImportPerformanceData::$IMPORT_DIRECTORY);
}
if(!is_dir(\Drupal\oab_backbones\Classes\ImportPerformanceData::$IMPORT_TMP_DIRECTORY)) {
  mkdir(\Drupal\oab_backbones\Classes\ImportPerformanceData::$IMPORT_TMP_DIRECTORY);
}

drupal_set_message("Création des répertoires effectuée", 'status');