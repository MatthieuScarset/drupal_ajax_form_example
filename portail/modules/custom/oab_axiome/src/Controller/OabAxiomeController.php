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

    $t2 = microtime();
    $build = array(
      '#type' => 'markup',
      '#markup' => t('Traitement réalisé en '.(($t2-$t1)).'s !'),
    );
    return $build;


  }
}