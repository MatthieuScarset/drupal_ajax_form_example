<?php


namespace Drupal\oab_axiome\Controller;


use Drupal\Core\Controller\ControllerBase;


class OabAxiomeController extends ControllerBase
{
    /**
     * {@inheritdoc}
     */
    public function test() {

        $axiome_importer = new \Drupal\oab_axiome\AxiomeImporter();

        $build = array(
            '#type' => 'markup',
            '#markup' => t('Hello World!'),
        );
        return $build;


    }
}