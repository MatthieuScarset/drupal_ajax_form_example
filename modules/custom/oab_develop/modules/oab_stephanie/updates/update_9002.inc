<?php

use Drupal\Core\File\FileSystemInterface;

const CONTENT_TYPES = [
    'media',
    'paragraph_related_content'
];

function _processUpdateWithSandbox_9002(&$sandbox, &$log_file) {

  $logger = \Drupal::logger(UPDATE_LOGGER);
  $database = \Drupal::database();

  if (empty($sandbox['ct_todo'])
    && !empty($sandbox['ct_done']) && count($sandbox['ct_done']) >= count(array_keys(CONTENT_TYPES))) {
    //il n'y a pas de CT a traiter et on a autant de CT done que de CT dans le tableau => c'est fini
    $sandbox['#finished'] = 1;
  }
  else { //il reste des types de contenus à traiter
    if (empty($sandbox['ct_todo'])
      && empty($sandbox['ct_done'])) {
      //si les variables ne sont pas initialisées, on le fait avec les types de contenus à traiter
      $sandbox['ct_todo'] = CONTENT_TYPES;
    }

    // si on n'est pas en train de traiter un type de contenu, on prends le premier du tableau des CT à traiter
    if (empty($sandbox['ct_current'])) {
      $sandbox['ct_current'] = array_shift($sandbox['ct_todo']);
      $sandbox['current'] = 0;
      $sandbox['lastId'] = 0;
      $sandbox['total'] = 0;
      $logger->notice("New content type to update : %ct_current", [
        '%ct_current' => $sandbox['ct_current']
      ]);
    }

    if (empty($sandbox['ct_current'])) {
      //il n'y avait pas de type de contenu suivant => on a fini, plus de CT à traiter
      $sandbox['#finished'] = 1;
    }
    else {
      //Si c'est un paragraph related content :
      if ($sandbox['ct_current'] === 'paragraph_related_content') {
        $query = \Drupal::entityQuery('paragraph');
        $query->sort('id', 'ASC');
        $query->condition('type', "related_content");
        $query->condition('field_catcher', 'Orange Business Services', 'CONTAINS');
        $query->condition('id', $sandbox['lastId'], '>');
        $query->range(0, 100);
        $results = $query->execute();

        if (empty($sandbox['total'])) {
          $query->range(NULL);
          $sandbox['total'] = $query->count()->execute();
        }

        if (count($results) > 0 && $sandbox['total']>0) {
          //début de la transaction
          $transaction = $database->startTransaction();
          foreach ($results as $revision => $id) {
            $sandbox['lastId'] = $id;
            /** @var Drupal\paragraphs\Entity\Paragraph $paragraph */
            $paragraph = \Drupal\paragraphs\Entity\Paragraph::load($id);
            $values_field = $paragraph->get('field_catcher')
              ->getValue();
            foreach ($values_field as $key => $value) {
              if (isset($values_field[$key]["value"])) {
                $values_field[$key]["value"] = str_replace('Orange Business Services', 'Orange Business', $values_field[$key]["value"]);
              }
            }
            $paragraph->set('field_catcher', $values_field);
            $paragraph->save();

            fputcsv($log_file, [
              $paragraph->getParentEntity()->id(),
              $paragraph->getParentEntity()->getType(),
              $paragraph->getParentEntity()->language()->getId(),
              $paragraph->getParentEntity()->getTitle(),
              'paragraph related content field_catcher',
              $paragraph->id(),
            ], ";");
          }
          //fin de transaction
          unset($transaction);
          $sandbox['current'] += count($results);

          $logger->notice("Finish %current out of %total for paragraph related content - field catcher", [
            '%current' => $sandbox['current'],
            '%total' => $sandbox['total']
          ]);
          $avancement = min(1, $sandbox['current'] / $sandbox['total']);
        }
        else {
          // il n'y a pas de contenu à traiter => on considère ce CT fini
          $avancement = 1;
          $logger->notice("No content to update for paragraphs");
        }

      }
      elseif ($sandbox['ct_current'] === 'media') {

        //on traite les médias
        $query = \Drupal::entityQuery('media');
        $query->sort('mid', 'ASC');
        $orGroup = $query->orConditionGroup();
        $orGroup->condition('field_image.title', 'Orange Business Services', 'CONTAINS');
        $orGroup->condition('field_image.alt', 'Orange Business Services', 'CONTAINS');
        $orGroup->condition('thumbnail.title', 'Orange Business Services', 'CONTAINS');
        $orGroup->condition('thumbnail.alt', 'Orange Business Services', 'CONTAINS');
        $query->condition($orGroup);
        $query->condition('mid', $sandbox['lastId'], '>');
        $query->range(0, 100);
        $results = $query->execute();
       // $logger->notice("la query : ".$query);

        if (empty($sandbox['total'])) {
          $query->range(NULL);
          $sandbox['total'] = $query->count()->execute();
        }

        if (count($results) > 0 && $sandbox['total']>0) {
          //début de la transaction
          $transaction = $database->startTransaction();
          foreach ($results as $revision => $mid) {
            $sandbox['lastId'] = $mid;
            /** @var \Drupal\media\Entity\Media $media */
            $media = \Drupal\media\Entity\Media::load($mid);

            $image_fields = [
              'field_image',
              'thumbnail'
            ];

            // On conserve la date de dernière modif de chaque media qu'on touche pour pouvoir la remettre à la fin
            $sandbox['medias'][$mid] = $media->getChangedTime();

            foreach ($media->getFields() as $field) {
              if (in_array($field->getName(), $image_fields)) {
                $values_field = $media->get($field->getName())->getValue();
                foreach ($values_field as $key => $value) {
                  if (isset($values_field[$key]["alt"])) {
                    $values_field[$key]["alt"] = str_replace('Orange Business Services', 'Orange Business', $values_field[$key]["alt"]);
                  }
                  if (isset($values_field[$key]["title"])) {
                    $values_field[$key]["title"] = str_replace('Orange Business Services', 'Orange Business', $values_field[$key]["title"]);
                  }
                }
                $media->set($field->getName(), $values_field);
              }
            }
            $media->save();

            fputcsv($log_file, [
              $media->id(),
              "",
              $media->language()->getId(),
              $media->getName()
            ], ";");
          }
          //fin de la transaction
          unset($transaction);
          $sandbox['current'] += count($results);

          $logger->notice("Finish %current out of %total for medias", [
            '%current' => $sandbox['current'],
            '%total' => $sandbox['total']
          ]);
          $avancement = min(1, $sandbox['current'] / $sandbox['total']);
        }
        else {
          // il n'y a pas de contenu à traiter => on considère ce CT fini
          $avancement = 1;
          $logger->notice("No content to update for medias");
        }
      }

      if ($avancement === 1) { // on a fini ce type de contenu
        $logger->notice('Tous les contenus mis a jour pour ' . $sandbox['ct_current']);
        $sandbox['ct_done'][] = $sandbox['ct_current'];
        unset($sandbox['ct_current']);
      }
      $sandbox['#finished'] = 0;// pour repasser dans la boucle
    }
  }
}



function _reset_changed_date_to_initial_medias($sandbox) {
  $logger = \Drupal::logger(UPDATE_LOGGER);

  if (is_array($sandbox['medias'])) {
    $logger->notice("Remise en place du changed des %nb_medias medias mis à jour", ['%nb_medias' => count($sandbox['medias'])]);
    $database = \Drupal::database();
    $transaction = $database->startTransaction('update_medias');
    foreach ($sandbox['medias'] as $mid => $changed) {
      $database->update('media_field_data')
        ->fields(['changed' => $changed])
        ->condition('mid', $mid)
        ->execute();
    }
    unset($transaction);
    $logger->notice("Reset medias OK");

  } else {
    $logger->warning("Cannot find medias to updates");
  }
}
