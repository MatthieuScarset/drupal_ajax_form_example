<?php


namespace Drupal\oab_axiome\Controller;


use Drupal\Core\Controller\ControllerBase;


class OabAxiomeController extends ControllerBase
{
  /**
   * {@inheritdoc}
   */
  public function test() {
    $t1 = microtime();
    $axiome_importer = new \Drupal\oab_axiome\AxiomeImporter();
    $axiome_importer->axiome_search_archive($axiome_importer->axiome_folder_root_path);

    $t2 = microtime();
    echo nl2br ($axiome_importer->message);
    $build = array(
      '#type' => 'markup',
      '#markup' => t('Traitement réalisé en '.(($t2-$t1)).'s !'),
    );
    return $build;


  }
}