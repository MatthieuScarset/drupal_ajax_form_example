<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 18/10/2016
 * Time: 10:40
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Database\Database;

class ShadowSites
{
  public static $TABLE_NAME = 'oab_backbones_shadowsites';

  public function getHeaderTable(){
    $header = array(
      'sid' => array('field' => 'sid', 'data' => t('code'), 'sort'=> 'asc'),
      'probe_name' => array('field' => 'probe_name', 'data' => t('probe name'), 'sort'=> 'asc'),
      'site_label' => array('field' => 'site_label', 'data' => t('site label'), 'sort'=> 'asc')
    );
    return $header;
  }

  public function getShadowSitesTable()
  {
    $shadowSites = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'obs')
        ->orderBy('sid', 'DESC')
        ->extend('Drupal\Core\Database\Query\TableSortExtender');
      $shadowSites = $query->fields('obs')
        ->orderByHeader($this->getHeaderTable())
        ->execute();
    }
    return $shadowSites;
  }

  public function getShadowSitesArrayFromDB(){
    $shadowSites = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'obs')
        ->fields('obs')
        ->orderBy('sid', 'DESC');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $site)
        {
          $shadowSites[$site->sid] = $site->probe_name;
        }
      }
    }
    return $shadowSites;
  }

  public function saveShadowSitesInDB($ss_to_update){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      foreach ($ss_to_update as $key => $name)
      {
        $query = Database::getConnection()->merge($this::$TABLE_NAME)
                                          ->key(array('sid' => $key))
                                          ->insertFields(array(
                                            'sid' => $key,
                                            'probe_name' => $name
                                          ))
                                          ->updateFields(array(
                                            'probe_name' => $name
                                          ))
                                          ->execute();
      }
    }
  }

  public function deleteShadowSitesInDB($ss_to_delete){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
        $query = Database::getConnection()->delete($this::$TABLE_NAME)
          ->condition('sid', $ss_to_delete, 'IN')
          ->execute();

    }
  }

  public function reinitUsedValuesForAllSites(){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->update($this::$TABLE_NAME)
        ->fields(['used' => 0])
        ->execute();
    }
  }

  public function updateShadowSiteInDB($sid, $used, $siteLabel){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->update($this::$TABLE_NAME)
        ->fields(['used' => $used, 'site_label' => $siteLabel])
        ->condition('sid', $sid, '=')
        ->execute();
    }
  }

  public function getAllInformationsForUsedShadowSites(){
    $shadowSites = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'obs')
        ->fields('obs')
        ->condition('obs.used', 1, '=')
        ->orderBy('sid', 'DESC');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $site)
        {
          $shadowSites[$site->sid] = array (
            "sid" 			=> $site->sid,
            "probe_name" 	=> $site->probe_name,
            "site_label" 	=> $site->site_label,
            "used" 			=> $site->used,
          );
        }
      }
    }
    return $shadowSites;
  }

  public function getUsedShadowSitesForSelector(){
    $shadowSites = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'obs')
        ->fields('obs')
        ->condition('obs.used', 1, '=')
        ->orderBy('obs.site_label', 'ASC');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $site)
        {
          $shadowSites[$site->sid] = $site->site_label;
        }
      }
    }
    return $shadowSites;
  }
}