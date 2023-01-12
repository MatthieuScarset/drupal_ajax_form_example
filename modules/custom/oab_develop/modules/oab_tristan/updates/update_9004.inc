<?php

use Drupal\content_moderation\Entity\ContentModerationState;

const UPDATE_LOGGER = "oab_updates";

function _processUpdateWithSandbox_9004(&$sandbox) {

  $logger = \Drupal::logger(UPDATE_LOGGER);

  $database = \Drupal::database();
  $base_query = $database->select('node_field_data', 'nfd');
  $base_query->condition('moderation_state', "published", '!=');
  if (!isset($sandbox['total'])) {
    // Pour éviter de planter. Je le set à 0 seulement s'il y a des enregistrements en BDD
    $sandbox['#finished'] = 1;
    $res = $base_query->countQuery()->execute()->fetchAssoc();



    if (isset($res['expression'])) {

      $sandbox['total'] = $res['expression'];
      $sandbox['current'] = 0;
      $sandbox['#finished'] = 0;
      $logger->notice("Find %nb_nodes to updates", ['%nb_nodes' => $res['expression']]);
    } else {
      $logger->warning("Didn't find any node to update");
    }
  }

  // Si on a rien, on stop ici
  if ($sandbox['total'] === 0) {
    $sandbox['#finished'] = 1;
    return;
  }

  $base_query->fields('nfd', ['nid', 'vid', 'uid', 'type', 'langcode', 'changed', 'moderation_state']);
  $base_query->range(0, 100);
  $rows = $base_query->execute()->fetchAll(\PDO::FETCH_ASSOC);

  // Pour éviter des boucles infinies sur current !== total et qu'il n'y a plus de résultat
  if (count($rows) == 0) {
    $sandbox['#finished'] = 1;
    $logger->notice("Update is finished");
  } else {
    foreach ($rows as $row) {
      ContentModerationState::create([
        'uid' => $row['uid'],
        'langcode' => $row['langcode'],
        'workflow' => 'content',
        'moderation_state' => $row['moderation_state'],
        'content_entity_type_id' => 'node',
        'content_entity_id' => $row['nid'],
        'content_entity_revision_id' => $row['vid']
      ])->save();

      // On save la date de dernière modif de chaque node qu'on touche
      // pour pouvoir la remettre à la fin
      $sandbox['nodes'][$row['nid']] = $row['changed'];
    }

    $sandbox['current'] += count($rows);

    \Drupal::messenger()->addMessage("Finish " . $sandbox['current'] . " out of " . $sandbox['total'], "notice");
    $logger->notice("Finish %current out of %total", ['%current' => $sandbox['current'], '%total' => $sandbox['total']]);
    $sandbox['#finished'] = min(1, $sandbox['current'] / $sandbox['total']);
  }


  if ($sandbox['#finished'] === 1) {
    $logger->log('success', 'Création des nouveaux états fini :)');
  }

}



function _reset_changed_date_to_initial($sandbox) {

  $logger = \Drupal::logger(UPDATE_LOGGER);

  if (is_array($sandbox['nodes'])) {
    $logger->notice("Remise en place du changed des %nb_nodes mis à jour", ['%nb_nodes' => count($sandbox['nodes'])]);
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

/**
 * CHeck if tables have the correct columns to remove Workbench
 * (it failed when following tables doesn't have the "moderation_state" column)
 */
function _check_tables_for_workbench_moderation_uninstallation() {

  \Drupal::logger(UPDATE_LOGGER)->notice("Remise en place de la colonne \"moderation_state\" nécessaire pour la suppression de Workbench");
  $schema = \Drupal::database()->schema();
  $definition = [
    'type' => 'varchar',
    'length' => 45,
  ];
  $tables = [
    'taxonomy_term_field_data',
    'block_content_field_data',
    'crop_field_data',
    'media_field_data',
    'node_field_data',
    'menu_link_content_data',
    'paragraphs_item_field_data',
    'product_formule_entity'
  ];
  foreach ($tables as $table) {
    if (!$schema->fieldExists($table, 'moderation_state')) {
      $schema->addField($table, 'moderation_state', $definition);
      \Drupal::logger(UPDATE_LOGGER)->notice("Ajout de la colonne à $table");
    }
  }
}


function _uninstall_workbench_moderation() {
  $logger= \Drupal::logger(UPDATE_LOGGER);
  $module_handler = \Drupal::moduleHandler();

  $logger->notice("Désinstallation Workbench moderation");
  if ($module_handler->moduleExists('workbench_moderation')) {
    \Drupal::service('module_installer')->uninstall(['workbench_moderation']);
    $logger->notice("Uninstalling Workbench Moderation OK");
  }
}
