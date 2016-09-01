<?php

use \Drupal\Core\Utility\UpdateException;

/**
 * Format d'affichage de la date de création pour les nodes : mois complet
 */

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.date_format.node_created_date');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'node_created_date',
  'label' => 'node created date',
  'locked' => false,
  'pattern' => 'd F Y',
));
$config->save(TRUE);

// Gestion de la traduction
$connection = \Drupal\Core\Database\Database::getConnection();
$query_delete = $connection->delete('config')
  ->condition('collection', 'language.en')
  ->condition('name', 'core.date_format.node_created_date')
  ->execute();

$query_create = $connection->insert('config')
  ->fields(array(
    'collection' => 'language.en',
    'name' => 'core.date_format.node_created_date',
    'data' => serialize(array(
      'pattern' => 'F, d Y',
    ))
  ))
  ->execute();

