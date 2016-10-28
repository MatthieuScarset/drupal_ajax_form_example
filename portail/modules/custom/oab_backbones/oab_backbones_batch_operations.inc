<?php

/**
 * @file
 * Controls the batch for import performance data
 *
 */
/**
 * CONSTATES DEFINIES DANS LE FICHIER .MODULE
 */


/**
 * import_batch
 * Import each line of the uploaded file
 * @param array $columns Correspond to a line in the file
 * @param array $shadowsites Array of all used shadowsites
 * @param string $month Date of import
 * @param array $context
 *
 */
function oab_backbones_import_batch($columns, $shadowSites, $month, &$context){
  if (isset($columns["FINISH"])
    && $columns["FINISH"] == "FINISH") {
    oab_backbones_import_batch_finished($context['success'], $context['results'], $context['operations']);
  } else {
    if (isset($context['results']['total'])
      && $context['results']['total'] <> "") {
      $context['results']['total'] = $context['results']['total']++;
    } else {
      $context['results']['total'] = "1";
    }

    if (isset($columns[RTD]) && $columns[RTD] <> "" &&
      isset($columns[JITTER_AB]) && $columns[JITTER_AB] <> "" &&
      isset($columns[JITTER_BA]) && $columns[JITTER_BA] <> "" &&
      isset($columns[PLR_AB]) && $columns[PLR_AB] <> "" &&
      isset($columns[PLR_BA]) && $columns[PLR_BA] <> "") {

      if (!isset($context['results']['data'][$columns[SID_A]][$columns[SID_B]])
        || $context['results']['data'][$columns[SID_A]][$columns[SID_B]] == "") {
        $context['results']['data'][$columns[SID_A]][$columns[SID_B]] = 1;
        $bbImportDataObj = new \Drupal\oab_backbones\Classes\BackbonesImportData();

        $dataArrayAtoB = array(
          "date" => $month,
          "source_site" => $columns[SID_A],
          "source_label" => $shadowSites[$columns[SID_A]]["site_label"],
          "destination_site" => $columns[SID_B],
          "destination_label" => $shadowSites[$columns[SID_B]]["site_label"],
          "RTD" => $columns[RTD],
          "JITTER" => $columns[JITTER_AB],
          "PLR" => $columns[PLR_AB]);
        $bbImportDataObj->saveDataLine($month, $columns[SID_A], $columns[SID_B], $dataArrayAtoB );

        $dataArrayBtoA = array(
          "date" => $month,
          "source_site" => $columns[SID_B],
          "source_label" => $shadowSites[$columns[SID_B]]["site_label"],
          "destination_site" => $columns[SID_A],
          "destination_label" => $shadowSites[$columns[SID_A]]["site_label"],
          "RTD" => $columns[RTD],
          "JITTER" => $columns[JITTER_BA],
          "PLR" => $columns[PLR_BA]
        );
        $bbImportDataObj->saveDataLine($month, $columns[SID_B], $columns[SID_A], $dataArrayBtoA );

        $title = $shadowSites[$columns[SID_A]]["site_label"] .
          " to ".
          $shadowSites[$columns[SID_B]]["site_label"] .
          " and " .
          $shadowSites[$columns[SID_B]]["site_label"] .
          " to ".
          $shadowSites[$columns[SID_A]]["site_label"];
        $context['results']['title'][] = $title;
        $context['message'] = $title;
      } else {
        $context['results']['fault'][] = $context['results']['total'];

      }
    } else {
      $context['results']['fault'][] = $context['results']['total'];
    }
  }
}

function oab_backbones_import_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = \Drupal::translation()->formatPlural(count($results['title']), 'One performance data processed.', '@count performance data processed.');
    drupal_set_message($message, 'status', TRUE);
    if (isset($results['fault'])
      && count($results['fault']) > 0) {
      $message = \Drupal::translation()->formatPlural(count($results['fault']), 'One performance data in error.', '@count performance data in error.');
      drupal_set_message($message, 'error', TRUE);
    }
  } else {
    $message = t('Finished with an error.');
    drupal_set_message($message, 'error', TRUE);
  }
}