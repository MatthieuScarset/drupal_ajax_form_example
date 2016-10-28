<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 20/10/2016
 * Time: 14:07
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Database\Database;

class BackbonesImport
{
  public static $TABLE_NAME = 'oab_backbones_import';

  public function getHeaderTable(){
    $header = array(
      'date' => array('data' => t('Date'), 'field' => 'date', 'sort' => 'desc'),
      'status' => array('data' => t('Status'), 'field' => 'status'),
      'comment' => t('Comments')
    );
    return $header;
  }

  public function getBackbonesImportTable()
  {
    $imports = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'i')
        ->extend('Drupal\Core\Database\Query\TableSortExtender');
      $imports = $query->fields('i')
        ->orderByHeader($this->getHeaderTable())
        ->range(0, 6)
        ->execute();
    }
    return $imports;
  }


  public function saveNewImport($date)
  {
    if (Database::getConnection()->schema()->tableExists($this->tableName))
    {
      $query = Database::getConnection()->merge($this->tableName)
        ->key(array('date' => $date))
        ->insertFields(array(
          'date' => $date,
          'status' => 0
        ))
        ->updateFields(array(
          'date' => $date
        ))
        ->execute();
    }
  }

  public function updateImportInDB($date, $status, $comment){
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->update($this::$TABLE_NAME)
        ->fields(['status' => $status, 'comment' => $comment])
        ->condition('date', $date, '=')
        ->execute();
    }
  }

  public function getLastImportsForSelection()
  {
    $imports = array();
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'i');
      $results =	$query->fields('i')
        ->condition('i.status', 1, '=')
        ->range(0,4)
        ->orderBy('i.date', 'DESC');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $result)
        {
          $imports[$result->date] = substr($result->date, 4, 2) . '/' . substr($result->date, 0, 4);
        }
      }
    }
    return $imports;
  }

  public function getCommentForImport($date)
  {
    $comment = "";
    if (Database::getConnection()->schema()->tableExists($this::$TABLE_NAME))
    {
      $query = Database::getConnection()->select($this::$TABLE_NAME, 'i');
      $results =	$query->fields('i')
        ->condition('i.date', $date, '=');
      $results = $query->execute()->fetchAll();

      if (is_array($results) && count($results) > 0) {
        foreach ($results as $result)
        {
          $comment = $result->comment;
        }
      }
    }
    return $comment;
  }
}