<?php

namespace Drupal\oab_bvpn_import\Classes;

use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\File\FileSystemInterface;
use Drupal\file\FileInterface;

class CSPImport {
  const IMPORT_DIRECTORY = 'public://bvpn/';
  const LOGOS_DIRECTORY = 'public://bvpn_logos/';

  /**
   * @var ExtensionPathResolver
   */
  private ExtensionPathResolver $pathResolver;

  /**
   * @var FileSystemInterface
   */
  private FileSystemInterface $fileSystem;

  public function __construct(ExtensionPathResolver $extension_path_resolver,
                              FileSystemInterface $file_system) {
    $this->pathResolver = $extension_path_resolver;
    $this->fileSystem = $file_system;
  }

  public function executeImport($filename) {

    $path_to_folder = $this->fileSystem->realpath($this::IMPORT_DIRECTORY);
    $path_file_csv = $path_to_folder . '/' .$filename;

    if (file_exists($path_file_csv) && filesize($path_file_csv) > 0) {
      $batch_op = array();
      $num_lines = 0;
      $fp = fopen($path_file_csv, 'r');
      while ($row = fgets($fp)) {
        $num_lines++;
        $columns = explode(";", $row);
        if ($num_lines>1) { //on le prend pas la 1ere ligne qui sont les titres
          $batch_op[] = array('oab_bvpn_import_batch', array($columns, $num_lines));
        }
      }

      fclose($fp);
      unlink($path_file_csv);

      if (count($batch_op) > 0) {
        $batch = array(
          'title' => t('CSP import'),
          'operations' => $batch_op,
          'finished' => 'oab_bvpn_import_batch_finished',
          'init_message' => t('CSP import is starting.'),
          'progress_message' => t('Processed @current out of @total.') ,
          'error_message' => t('CSP data import has encountered an error.'),
          'file' => $this->pathResolver->getPath('module', 'oab_bvpn_import') . '/oab_bvpn_import_batch_operations.inc',
        );

        batch_set($batch);
      }
    }

  }

  /**
   * @return bool|array|FileInterface|null
   */
  public function saveFileImport(): bool|array|FileInterface|null {
    if (!is_dir(self::IMPORT_DIRECTORY)) {
      $this->fileSystem->mkdir(self::IMPORT_DIRECTORY, NULL, TRUE);
    }

    return file_save_upload(
      'file',
      ['file_validate_extensions' => ''],
      self::IMPORT_DIRECTORY,
      replace: FileSystemInterface::EXISTS_REPLACE
    );
  }
}
