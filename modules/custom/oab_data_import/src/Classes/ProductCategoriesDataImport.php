<?php

namespace Drupal\oab_data_import\Classes;

class ProductCategoriesDataImport
{
  const IMPORT_DIRECTORY = 'public://data/';

  public function executeImport($filename) {

    $path_to_folder = \Drupal::service('file_system')->realpath($this::IMPORT_DIRECTORY);
    $path_file_csv = $path_to_folder . '/' .$filename;

    if (file_exists($path_file_csv) && filesize($path_file_csv) > 0) {
      $batch_op = array();
      $num_lines = 0;
      $fp = fopen($path_file_csv, 'r');
      while ($row = fgets($fp)) {
        $num_lines++;
        $columns = explode(";", $row);
        if($num_lines>1) { //on le prend pas la 1ere ligne qui sont les titres
          $batch_op[] = array('oab_data_import_data_product_categories_batch', array($columns, $num_lines));
        }
      }

      fclose($fp);
      unlink($path_file_csv);

      if (count($batch_op) > 0) {
        $batch = array(
          'title' => t('Product categories import'),
          'operations' => $batch_op,
          'finished' => 'oab_data_import_data_product_categories_batch_finished',
          'init_message' => t('Product categories import is starting.'),
          'progress_message' => t('Processed @current out of @total.') ,
          'error_message' => t('Product categories data import has encountered an error.'),
          'file' => drupal_get_path('module', 'oab_data_import') . '/oab_data_import_batch_operations.inc',
        );

        batch_set($batch);
      }
    }

  }
}