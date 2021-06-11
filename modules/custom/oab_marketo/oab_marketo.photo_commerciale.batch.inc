<?php

use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\oab_marketo\PhotoCommercialeService;

function oab_marketo_importPhotoCommerciale($file_name, &$context) {


  $file = fopen($file_name, 'r');
  if (isset($context['sandbox']['file_position'])) {
    fseek($file, $context['sandbox']['file_position']);
  } else {
    //Pour vérifier si on avancer dans la lecture du fichier et éviter des boucles infinies
    $context['sandbox']['etat'] = 0;
  }

  /** @var PhotoCommercialeService $service */
  $service = \Drupal::service('oab_marketo.photo_commerciale.service');

  $i = 0;
  while ($i < 100 && false !== ($row = fgetcsv($file, 0, ';'))) {
    if ( $context['sandbox']['etat'] > 0 || $i > 0) { //Pour évier d'importer les titres des colonnes
      if ($service->import($row)) {
        $i++;
      }
    } elseif ( $context['sandbox']['etat'] == 0 && $i == 0 ) {
      $i++;
    }
  }

  $context['sandbox']['file_position'] = ftell($file);
  $context['sandbox']['etat']++;
  \Drupal::logger('oab_import')->info(json_encode($context));
  $context['finished'] = feof($file);

}

function oab_marketo_clearPhotoCommercialeTable(&$context) {

  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_id'] = 0;
    $context['sandbox']['max'] = \Drupal::database()
      ->query('SELECT COUNT(DISTINCT id) FROM photo_commerciale_item')
      ->fetchField();
  }
  $limit = 100;
  $result = \Drupal::database()
    ->select('photo_commerciale_item')
    ->fields('photo_commerciale_item', ['id'])
    ->condition('id', $context['sandbox']['current_id'], '>')
    ->orderBy('id')
    ->range(0, $limit)
    ->execute()
    ->fetchCol('id');

  /** @var EntityStorageInterface $storage */
  $storage = \Drupal::service('entity_type.manager')->getStorage('photo_commerciale_item');
  $entities = $storage->loadMultiple($result);
  $storage->delete($entities);

  $context['sandbox']['progress'] += count($result);
  $context['sandbox']['current_id'] = end($result);

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }

}


function oab_marketo_deleteFile($file, &$context) {
  unlink($file);
}

function oab_marketo_endingBatch($success, $results, $operations) {
  \Drupal::logger('oab_import')->info(t("Fichier importé"));
}
