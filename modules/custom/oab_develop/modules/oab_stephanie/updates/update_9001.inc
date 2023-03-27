<?php

use Drupal\Core\File\FileSystemInterface;

const UPDATE_LOGGER = "oab_updates";

const CT_FIELDS = [
    'blog_post' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
    ],
    'profile' => [
      'body'
    ],
    'press_release' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
    ],
    'magazine' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
    ],
    'document' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
    ],
    'product' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
      'field_top_zone',
      'field_axiome_data',
      'field_key_points',
      'field_product_name',
      'field_teaser'
    ],
    'news' => [
      'field_content',
      'field_meta_description',
      'field_meta_title',
    ],
    'customer_story' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
      'field_top_zone',
    ],
    'simple_page' => [
      'field_content',
      'field_highlight',
      'field_meta_description',
      'field_meta_title',
      'field_grouping_title',
    ],
    'full_html' => [
      'field_content',
      'field_meta_description',
      'field_meta_title'
    ],
    'field_p_wysiwyg_rebond' => [
    ]
];

function _processUpdateWithSandbox_9001(&$sandbox, &$log_file) {

  $logger = \Drupal::logger(UPDATE_LOGGER);
  $database = \Drupal::database();

  if (empty($sandbox['ct_todo'])
    && !empty($sandbox['ct_done']) && count($sandbox['ct_done']) >= count(array_keys(CT_FIELDS))) {
    //il n'y a pas de CT a traiter et on a autant de CT done que de CT dans le tableau => c'est fini
    $sandbox['#finished'] = 1;
  }
  else { //il reste des types de contenus à traiter
    if (empty($sandbox['ct_todo'])
      && empty($sandbox['ct_done'])) {
      //si les variables ne sont pas initialisées, on le fait avec les types de contenus à traiter
      foreach (CT_FIELDS as $content_type => $fields) {
        $sandbox['ct_todo'][] = $content_type;
      }
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
      //Si c'est un paragraph rebond :
      if ($sandbox['ct_current'] === 'field_p_wysiwyg_rebond') {
        $query = \Drupal::entityQuery('paragraph');
        $query->sort('id', 'ASC');
        $query->condition('type', "rebond_wysiwyg");
        $query->condition('parent_field_name', "field_p_wysiwyg_rebond");
        $query->condition('field_p_rebond_wysiwyg_contenu', 'Orange Business Services', 'CONTAINS');
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
            $values_field = $paragraph->get('field_p_rebond_wysiwyg_contenu')
              ->getValue();
            foreach ($values_field as $key => $value) {
              if (isset($values_field[$key]["value"])) {
                $values_field[$key]["value"] = str_replace('Orange Business Services', 'Orange Business', $values_field[$key]["value"]);
              }
            }
            $paragraph->set('field_p_rebond_wysiwyg_contenu', $values_field);
            $paragraph->save();

            fputcsv($log_file, [
              $paragraph->getParentEntity()->id(),
              $paragraph->getParentEntity()->getType(),
              $paragraph->getParentEntity()->language()->getId(),
              $paragraph->getParentEntity()->getTitle(),
              'field_p_rebond_wysiwyg_contenu',
              $paragraph->id(),
            ], ";");
          }

          unset($transaction);
          $sandbox['current'] += count($results);

          $logger->notice("Finish %current out of %total for paragraph rebond", [
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
      else {
        $text_fields =  [
          'field_content',
          'field_highlight',
          'field_meta_title',
          'field_meta_description',
          'body',
          'field_top_zone',
          'field_key_points',
          'field_product_name',
          'field_teaser',
        ];
        //on traite le CT dans $sandbox['ct_current']
        $query = \Drupal::entityQuery('node');
        $query->accessCheck(FALSE);
        $query->sort('nid', 'ASC');
        $query->condition('type', $sandbox['ct_current']);
        $query->condition('nid', $sandbox['lastId'], '>');
        $orGroup = $query->orConditionGroup();
        $orGroup->condition('title', 'Orange Business Services', 'CONTAINS');
        foreach (CT_FIELDS[$sandbox['ct_current']] as $field) {
          $orGroup->condition($field, 'Orange Business Services', 'CONTAINS');
        }
        $query->condition($orGroup);
        $query->range(0, 100);
        $results = $query->execute();

        if (empty($sandbox['total'])) {
          $query->range(NULL);
          $sandbox['total'] = $query->count()->execute();
        }

        if (count($results) > 0 && $sandbox['total']>0) {
          //début de la transaction
          $transaction = $database->startTransaction();

          foreach ($results as $revision => $nid) {
            $sandbox['lastId'] = $nid;
            $node = \Drupal\node\Entity\Node::load($nid);

            // On conserve la date de dernière modif de chaque node qu'on touche pour pouvoir la remettre à la fin
            $sandbox['nodes'][$nid] = $node->getChangedTime();

            foreach (CT_FIELDS[$sandbox['ct_current']] as $field) {
              if (in_array($field, $text_fields)) {
                $values_field = $node->get($field)->getValue();
                foreach ($values_field as $key => $value) {
                  if (isset($values_field[$key]["value"])) {
                    $values_field[$key]["value"] = str_replace('Orange Business Services', 'Orange Business', $values_field[$key]["value"]);
                  }
                }
                $node->set($field, $values_field);
              }
              elseif ($field === 'field_axiome_data') {
                $values_field = $node->get('field_axiome_data')->getValue();
                foreach ($values_field as $key => $value) {
                  if (isset($value['value'])) {
                    $axiome_value = unserialize($value['value']);
                    array_walk_recursive($axiome_value, "replaceStringOBSWithStringOB");
                    $values_field[$key]["value"] = serialize($axiome_value);
                  }
                }
                $node->set('field_axiome_data', $values_field);
              }
            }
            $node->setTitle(str_replace('Orange Business Services', 'Orange Business', $node->getTitle()));
            $node->save();

            fputcsv($log_file, [
              $nid,
              $node->getType(),
              $node->language()->getId(),
              $node->getTitle()
            ], ";");
          }
          unset($transaction);
          $sandbox['current'] += count($results);

          $logger->notice("Finish %current out of %total for content type %ct_current", [
            '%current' => $sandbox['current'],
            '%total' => $sandbox['total'],
            '%ct_current' => $sandbox['ct_current']
          ]);
          $avancement = min(1, $sandbox['current'] / $sandbox['total']);
        }
        else {
          // il n'y a pas de contenu à traiter => on considère ce CT fini
          $avancement = 1;
          $logger->notice("No content to update for content type %ct_current", [
            '%ct_current' => $sandbox['ct_current']
          ]);
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



function _reset_changed_date_to_initial($sandbox) {
  $logger = \Drupal::logger(UPDATE_LOGGER);

  if (is_array($sandbox['nodes'])) {
    $logger->notice("Remise en place du changed des %nb_nodesn nodes mis à jour", ['%nb_nodes' => count($sandbox['nodes'])]);
    $database = \Drupal::database();
    $transaction = $database->startTransaction('update_nodes');
    foreach ($sandbox['nodes'] as $nid => $changed) {
      $database->update('node_field_data')
        ->fields(['changed' => $changed])
        ->condition('nid', $nid)
        ->execute();
    }
    unset($transaction);
    $logger->notice("Reset nodes OK");

  } else {
    $logger->warning("Cannot find nodes to updates");
  }
}

function replaceStringOBSWithStringOB(&$value) {
  if (is_string($value)) {
    $value = str_replace('Orange Business Services', 'Orange Business', $value);
  }
}
