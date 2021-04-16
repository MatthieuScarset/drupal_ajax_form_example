<?php

/**
 * @file
 * Controls the batch for import performance data
 *
 */
/**
 * Les CONSTATES sont définies dans le fichier .MODULE
 */

use Drupal\Core\Messenger\MessengerInterface;


/**
 * Méthode executée pour chaque ligne du fichier d'import Performance Data
 *
 */
function oab_backbones_import_batch($columns, $shadow_sites, $month, &$context) {
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
                \Drupal::logger('oab_backbones')->notice('traitement de : ' . $columns[SID_A] . ' -> ' .
                    $columns[SID_B] . ' : ' . $context['results']['data'][$columns[SID_A]][$columns[SID_B]]);
                $context['results']['data'][$columns[SID_A]][$columns[SID_B]] = 1;
                $bb_import_data_obj = new \Drupal\oab_backbones\Classes\BackbonesImportData();

                $data_array_atob = array(
                    "date" => $month,
                    "source_site" => intval($shadow_sites[$columns[SID_A]]["sid"]),
                    "source_label" => $shadow_sites[$columns[SID_A]]["site_label"],
                    "destination_site" => intval($shadow_sites[$columns[SID_B]]["sid"]),
                    "destination_label" => $shadow_sites[$columns[SID_B]]["site_label"],
                    "RTD" => $columns[RTD],
                    "JITTER" => $columns[JITTER_AB],
                    "PLR" => $columns[PLR_AB]);
                $bb_import_data_obj->saveDataLine($month, intval($shadow_sites[$columns[SID_A]]["sid"]), intval($shadow_sites[$columns[SID_B]]["sid"]), $data_array_atob);

                $data_array_btoa = array(
                    "date" => $month,
                    "source_site" => (int) $shadow_sites[$columns[SID_B]]["sid"],
                    "source_label" => $shadow_sites[$columns[SID_B]]["site_label"],
                    "destination_site" => (int) $shadow_sites[$columns[SID_A]]["sid"],
                    "destination_label" => $shadow_sites[$columns[SID_A]]["site_label"],
                    "RTD" => $columns[RTD],
                    "JITTER" => $columns[JITTER_BA],
                    "PLR" => $columns[PLR_BA]
                );
                $bb_import_data_obj->saveDataLine($month, intval($shadow_sites[$columns[SID_B]]["sid"]), intval($shadow_sites[$columns[SID_A]]["sid"]), $data_array_btoa);

                $title = $shadow_sites[$columns[SID_A]]["site_label"] .
                    " to " .
                    $shadow_sites[$columns[SID_B]]["site_label"] .
                    " and " .
                    $shadow_sites[$columns[SID_B]]["site_label"] .
                    " to " .
                    $shadow_sites[$columns[SID_A]]["site_label"];
                $context['results']['title'][] = $title;
                $context['message'] = $title;
            } else {
                $context['results']['fault']['doublon'][] = $context['results']['total'];
                //\Drupal::logger('oab_backbones')->notice('**************************************************** ');
                //\Drupal::logger('oab_backbones')->notice('premier ELSE '.$columns[SID_A].' -> '.$columns[SID_B]. ' : '
                //.$context['results']['data'][$columns[SID_A]][$columns[SID_B]]);
                //\Drupal::logger('oab_backbones')->notice('**************************************************** ');

            }
        } else {
            $context['results']['fault']['emptyValue'][] = $context['results']['total'];
            //\Drupal::logger('oab_backbones')->notice('**************************************************** ');
            //\Drupal::logger('oab_backbones')->notice('une des colonnes vides '.$columns[SID_A].' -> '.$columns[SID_B].
            //' : '.$columns[RTD]. ' - '.$columns[JITTER_AB]. ' - '.$columns[JITTER_BA]. ' - '.$columns[PLR_AB]. ' - '.
            //$columns[PLR_BA]. ' ; ');
            //\Drupal::logger('oab_backbones')->notice('**************************************************** ');
        }
    }
}

/**
 * Méthode appelée à la fin des batchs
 */
function oab_backbones_import_batch_finished($success, $results, $operations) {
    if ($success) {
        $message = \Drupal::translation()->formatPlural(count($results['title']), 'One performance data processed.',
            '@count performance data processed.');
        Drupal::messenger()->addMessage($message, 'status', TRUE);
        // 18/09/17 - SJO : je mets en commentaire les warnings/errors et info sur les lignes car les personnes réalisant l'import ne veulent pas ces infos.
        // Ca n'a jamais fonctionné sur D7 (erreur nommage méthode et appel) donc ils sont perturbés par les informations qu'on donne
        /*
        if (isset($results['fault']['doublon'])
          && count($results['fault']['doublon']) > 0) {
          $message = \Drupal::translation()->formatPlural(count($results['fault']['doublon']),
        'One non-imported line (duplicate source and destination sites).', '@count non-imported lines (duplicate source and destination sites).');
          drupal_set_message($message, 'warning', TRUE);
        }
        if (isset($results['fault']['emptyValue'])
          && count($results['fault']['emptyValue']) > 0) {
          $message = \Drupal::translation()->formatPlural(count($results['fault']['emptyValue']),
        'One line containing empty values.', '@count lines containing empty values.');
          drupal_set_message($message, 'warning', TRUE);
        }*/
    } else {
        $message = t('Finished with an error.');
        Drupal::messenger()->addError($message, TRUE);
    }
}
