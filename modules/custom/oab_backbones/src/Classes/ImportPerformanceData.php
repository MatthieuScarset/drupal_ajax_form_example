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
use Drupal\Core\Messenger\MessengerInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Classe qui va faire l'import des données
 */
class ImportPerformanceData
{
    const IMPORT_TMP_DIRECTORY = 'public://backbones/tmp/';
    const IMPORT_DIRECTORY = 'public://backbones/data/';
    const FINAL_FILENAME = 'openstat_backbone_path_performance_1.0_usa_m';

    /**
     * @var MessengerInterface
     */
    private $messenger;

  /**
   * ImportPerformanceData constructor.
   * @param MessengerInterface $messenger
   */
    public function __construct(MessengerInterface $messenger) {
      $this->messenger = $messenger;
    }

  public function executeImport($month) {
        $zip_file_name_complete = $this::IMPORT_DIRECTORY . 'DATA_' . $month . '.csv.zip';
        $path_zip_file_name_nomplete = \Drupal::service('file_system')->realpath($zip_file_name_complete);
        $path_to_folder = \Drupal::service('file_system')->realpath($this::IMPORT_DIRECTORY);
        if (file_exists($path_zip_file_name_nomplete) && filesize($path_zip_file_name_nomplete) > 0) {
            try {
                $zip = new Zip($path_zip_file_name_nomplete);
                $zip->extract($path_to_folder);

                $bb_import = new BackbonesImport();
                $bb_importdata = new BackbonesImportData();
                $bb_import->saveNewImport($month);
                $bb_importdata->deleteAllDataForDates($month);

                $path_file_csv_final = $path_to_folder . '/' . $this::FINAL_FILENAME . $month . ".csv";
                $this->importLines($path_file_csv_final, $month);
            } catch (\Drupal\Core\Archiver\ArchiverException $exception) {
                $this->messenger->addMessage(t('Cannot unzip the uploaded file.' . $path_zip_file_name_nomplete), 'error');
                $this->messenger->addMessage($exception->getMessage(), 'error');
                //exit();
            }


        } else {
            $this->messenger->addMessage(t('The uploaded file was not found. ' . $path_zip_file_name_nomplete), 'error');
            //exit();
        }
    }

    private function importLines($filename, $date) {
        //récupération des shadows sites actifs
        $ss_obj = new ShadowSites();
        $shadow_sites = $ss_obj->getAllInformationsForUsedShadowSites();

        $batch_op = array();
        $num_lines = 0;
        $fp = fopen($filename, 'r');
        while ($row = fgets($fp)) {
            $num_lines++;
            $columns = explode(",", $row);

            if (isset($columns[SID_A]) && $columns[SID_A] <> ""
                && isset($shadow_sites[$columns[SID_A]]) && $shadow_sites[$columns[SID_A]] <> ""
                && isset($columns[SID_B]) && $columns[SID_B] <> ""
                && isset($shadow_sites[$columns[SID_B]]) && $shadow_sites[$columns[SID_B]] <> "") {
                $batch_op[] = array('oab_backbones_import_batch', array($columns, $shadow_sites, $date));
            }
        }

        fclose($fp);
        unlink($filename);

        if (count($batch_op) > 0) {
            $batch = array('title' => t('Data performance import'),
                'operations' => $batch_op,
                'finished' => 'oab_backbones_import_batch_finished',
                'init_message' => t('Performance data import is starting.'),
                'progress_message' => t('Processed @current out of @total.') . '<br/>' . Link::fromTextAndUrl(t('go back to the form'),
                        Url::fromRoute('oab_backbones.performance_data'))->toString(),
                'error_message' => t('Performance data import has encountered an error.'),
                'file' => drupal_get_path('module', 'oab_backbones') . '/oab_backbones_batch_operations.inc',
            );

            batch_set($batch);
        }
        //drupal_set_message(count($batch_op).' opérations lancées.', 'status', TRUE);
    }
}
