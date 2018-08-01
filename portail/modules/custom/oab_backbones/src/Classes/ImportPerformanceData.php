<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 18/10/2016
 * Time: 10:34
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Archiver\Zip;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Classe qui va faire l'import des données
 */
class ImportPerformanceData
{
    public static $IMPORT_TMP_DIRECTORY = 'public://backbones/tmp/';
    public static $IMPORT_DIRECTORY = 'public://backbones/data/';
    public static $FINAL_FILENAME = 'openstat_backbone_path_performance_1.0_usa_m';

    public function executeImport($month)
    {
        $zipFileNameComplete = $this::$IMPORT_DIRECTORY . 'DATA_' . $month . '.csv.zip';
        $pathZipFileNameComplete = \Drupal::service('file_system')->realpath($zipFileNameComplete);
        $pathToFolder = \Drupal::service('file_system')->realpath($this::$IMPORT_DIRECTORY);
        if (file_exists($pathZipFileNameComplete) && filesize($pathZipFileNameComplete) > 0) {
            try {
                $zip = new Zip($pathZipFileNameComplete);
                $zip->extract($pathToFolder);

                $bbImport = new BackbonesImport();
                $bbImportData = new BackbonesImportData();
                $bbImport->saveNewImport($month);
                $bbImportData->deleteAllDataForDates($month);

                $pathFileCSVFinal = $pathToFolder . '/' . $this::$FINAL_FILENAME . $month . ".csv";
                $this->importLines($pathFileCSVFinal, $month);
            } catch (\Drupal\Core\Archiver\ArchiverException $exception) {
                drupal_set_message(t('Cannot unzip the uploaded file.' . $pathZipFileNameComplete), 'error');
                drupal_set_message($exception->getMessage(), 'error');
                //exit();
            }


        } else {
            drupal_set_message(t('The uploaded file was not found. ' . $pathZipFileNameComplete), 'error');
            //exit();
        }
    }

    private function importLines($filename, $date)
    {
        //récupération des shadows sites actifs
        $ssObj = new ShadowSites();
        $shadowSites = $ssObj->getAllInformationsForUsedShadowSites();

        $batch_op = array();
        $numLines = 0;
        $fp = fopen($filename, 'r');
        while ($row = fgets($fp)) {
            $numLines++;
            $columns = explode(",", $row);

            if (isset($columns[SID_A]) && $columns[SID_A] <> ""
                && isset($shadowSites[$columns[SID_A]]) && $shadowSites[$columns[SID_A]] <> ""
                && isset($columns[SID_B]) && $columns[SID_B] <> ""
                && isset($shadowSites[$columns[SID_B]]) && $shadowSites[$columns[SID_B]] <> "") {
                $batch_op[] = array('oab_backbones_import_batch', array($columns, $shadowSites, $date));
            }
        }

        fclose($fp);
        unlink($filename);

        if (count($batch_op) > 0) {
            $batch = array('title' => t('Data performance import'),
                'operations' => $batch_op,
                'finished' => 'oab_backbones_import_batch_finished',
                'init_message' => t('Performance data import is starting.'),
                'progress_message' => t('Processed @current out of @total.') . '<br/>' . Link::fromTextAndUrl(t('go back to the form'), Url::fromRoute('oab_backbones.performance_data'))->toString(),
                'error_message' => t('Performance data import has encountered an error.'),
                'file' => drupal_get_path('module', 'oab_backbones') . '/oab_backbones_batch_operations.inc',
            );

            batch_set($batch);
        }
        //drupal_set_message(count($batch_op).' opérations lancées.', 'status', TRUE);
    }
}