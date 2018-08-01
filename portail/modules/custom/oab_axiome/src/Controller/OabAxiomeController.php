<?php


namespace Drupal\oab_axiome\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\oab_axiome\AxiomeImporter;
use Drupal\oab_axiome\Form\OabAxiomeSettingsForm;


class OabAxiomeController extends ControllerBase
{
  /**
   * {@inheritdoc}
   */
  public function test() {
    $t1 = microtime();
    $axiome_importer = new \Drupal\oab_axiome\AxiomeImporter();
    $axiome_importer->axiome_search_archive($axiome_importer->axiomeFolderRootPath);

    $t2 = microtime();
    echo nl2br($axiome_importer->message);
    $build = array(
      '#type' => 'markup',
      '#markup' => t('Traitement réalisé en '.(($t2-$t1)).'s !'),
    );
    return $build;


  }


  public static function getSousFamille($nid) {
      $config = \Drupal::config(OabAxiomeSettingsForm::getConfigName());
      $values = $config->get(AxiomeImporter::CONFIG_VALUE_NAME);

      $ret = false;
      if (isset($values[$nid])) {
          $ret = $values[$nid];
      }

      return $ret;
  }
}
