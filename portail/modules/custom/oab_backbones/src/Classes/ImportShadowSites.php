<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 18/10/2016
 * Time: 10:34
 */

namespace Drupal\oab_backbones\Classes;


class ImportShadowSites
{
  public static $IMPORT_DIRECTORY = 'public://backbones/sites/';
  public static $IMPORT_FILENAME = 'SHADOW_SITE.txt.gz';

  public function executeImport(){
    $fileNameComplete = $this::$IMPORT_DIRECTORY.$this::$IMPORT_FILENAME;
    if(file_exists($fileNameComplete) && filesize($fileNameComplete) > 0){
      $lines = gzfile($fileNameComplete);
      if (count($lines) > 100) {
        // Suppression de la ligne header
        unset($lines[0]);

        //constitution du tableau de sites présents dans le fichier
        $ss_in_file = array();
        foreach ($lines as $line) {
          $parts = explode("\t", $line);
          // 0:RowMd5Digest 1:IPShadowSiteCode 2:IPShadowSiteLabel
          $ss_in_file[trim($parts[1])] = trim($parts[2]);
        }

        //récupération des sites en BDD
        $shadowsSites = new ShadowSites();
        $ss_in_db = $shadowsSites->getShadowSitesArrayFromDB();

        //Comparaison entre le fichier et la BDD : retourne les shadow sites à ajouter par le fichier
        $ss_to_update = array_diff($ss_in_file, $ss_in_db);

        if (count($ss_to_update) > 0) {
          $shadowsSites->saveShadowSitesInDB($ss_to_update);
        }
        //Comparaison entre la BDD et le fichier pour les sites à supprimer
        $ss_to_delete = array_keys(array_diff_key($ss_in_db, $ss_in_file));

        if (count($ss_to_delete) > 0) {
          $shadowsSites->deleteShadowSitesInDB($ss_to_delete);
        }
        //mise à jour de la variable de date du dernier import shadows_sites
        $timestamp = time();
        \Drupal::state()->set('bbp_last_import_ss', $timestamp);

      } else {
        drupal_set_message(t("File SHADOW_SITE.txt.gz has to few lines"), 'error');
      }
    } else {
      drupal_set_message(t("File SHADOW_SITE.txt.gz doesn't exist"), 'error');
    }
  }
}