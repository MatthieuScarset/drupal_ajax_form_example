<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 20/10/2016
 * Time: 14:07
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Database\Database;

/**
 * Classe pour les méthodes qui concernent les données d'import
 */
class BackbonesImportData
{
  public static $TABLE_NAME = 'oab_backbones_import_data';

  /** Méthode qui supprimes toutes les data pour un import */
  public function deleteAllDataForDates($date)
  {
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->delete($this::$TABLE_NAME)
        ->condition('date', $date, '=')
        ->execute();
    }
  }

  /** Méthode qui crée ou met à jour une ligne de données pour un meme site source, site destination et date */
  public function saveDataLine($date, $sourceSite, $destinationSite, $dataArray){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->merge($this::$TABLE_NAME)
        ->key(array('date' => $date,
          'source_site' => $sourceSite,
          'destination_site' => $destinationSite
        ))
        ->fields($dataArray)
        ->execute();
    }
  }

  /** Retourne toutes les données pour un site source et une date */
  public function getDatasForSiteAndDate($date, $site)
  {
    $datas = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'd');
      $query->join(ShadowSites::$TABLE_NAME, 'ss1', 'd.destination_site = ss1.sid');
      $query->join(ShadowSites::$TABLE_NAME, 'ss2', 'd.source_site = ss2.sid');
      $results =	$query->fields('d')
        ->condition('d.date', $date, '=')
        ->condition('d.source_site', $site)
        ->condition('ss1.used', 1)
        ->condition('ss2.used', 1)
   //     ->groupBy('destination_site') //ne sert à rien puisqu'il n'y a pas de calculs
        ->orderBy('destination_label');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $result)
        {
          $datas[] = array(
            "label" => $result->destination_label,
            "RTD" => round($result->RTD),
            "PLR" => round($result->PLR, 2),
            "JITTER" => round($result->JITTER, 1),
          );
        }
      }
      /*
      if (count($datas) % 2 != 0) {
        $datas[] = array (
          "label" => " ",
          "RTD" => " ",
          "PLR" => " ",
          "JITTER" => " "
        );
      }
      */
    }
    return $datas;
  }
}