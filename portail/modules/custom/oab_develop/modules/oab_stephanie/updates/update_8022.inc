<?php

use \Drupal\Core\Utility\UpdateException;


/***
 * Ajout d'une configuration pour ne pas indexer les offices par défaut
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('metatag.metatag_defaults.node__office');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'id' => 'node__office',
    'label' => 'Contenu: Office',
    'tags' =>
      array (
        'robots' => 'noindex',
      ),
  ));
$config_group->save(TRUE);
