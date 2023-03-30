<?php

/**
 * @file
 * Controls the batch for import performance data
 *
 */
/**
 * Les CONSTATES sont définies dans le fichier .MODULE
 */

use Drupal\oab_data_import\Classes\OabSettingsProductCategoriesDataImportForm;
use Drupal\node\Entity\Node;
use Drupal\file\Entity\File;
use Drupal\media\Entity\Media;


/**
 * @file
 * Controls the batch for import performance data
 *
 */


/**
 * Méthode executée pour chaque ligne du fichier d'import des CSV
 *
 */
function oab_data_import_terms_product_categories_batch($columns, $line_number, &$context) {

  $context['results']['total'][] = 1; // pour compter le nombre de lignes traitées après

  //Structure du fichier csv
  $terms_data = array();
  //0:langcode
  $terms_data['langcode'] = $columns[0];
  //1:categ
  $terms_data['categ'] = $columns[1];
  //2:subcateg
  $terms_data['sub_categ'] = $columns[2];
  //3: description subcateg
  $terms_data['sub_categ_txt'] = $columns[3];
  //4:icon subcateg
  $terms_data['icon'] = $columns[4];

  //PARENT
  $parent_term = getTermFromLabelAndVocabulary($terms_data['categ'], 'product_categories', $terms_data['langcode']);
  $parent_tid = 0;
  if ($parent_term === false) {
    // Terme parent non trouvé ==> à créer
    $new_parent = \Drupal\taxonomy\Entity\Term::create(array(
        'name' => $terms_data['categ'],
        'langcode' => $terms_data['langcode'],
        'vid' => 'product_categories'
      )
    );
    $new_parent->save();
    $parent_tid = $new_parent->id();
  } else {
    $parent_tid = $parent_term->id();
  }

  //SUB TERM
  $sub_term = getSubTermFromParentAndLabel($terms_data['sub_categ'], $parent_tid, 'product_categories', $terms_data['langcode']);
  if ($sub_term === false) {
    // Sub-Term parent non trouvé ==> à créer
    $sub_term = \Drupal\taxonomy\Entity\Term::create(array(
        'name' => $terms_data['sub_categ'],
        'langcode' => $terms_data['langcode'],
        'parent' => $parent_tid,
        'vid' => 'product_categories'
      )
    );
    $sub_term->save();
  }
  $sub_term->set('field_simple_description', trim($terms_data['sub_categ_txt']));
  $sub_term->set('field_icon', trim($terms_data['icon']));
  $sub_term->save();
}

/**
 * Méthode appelée à la fin des batchs
 */
function oab_data_import_terms_product_categories_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = \Drupal::translation()->formatPlural(count($results['total']), 'One line', '@count lines.');
    \Drupal::messenger()->addMessage($message, 'status', TRUE);

    if ($results['warning']['message'] != null && count($results['warning']['message']) > 0) {
      Drupal::messenger()->addMessage("Errors occured in file : ", 'warning', TRUE);
      foreach ($results['warning']['message'] as $message) {
        Drupal::messenger()->addMessage($message, 'warning', TRUE);
      }
    }

  } else {
    $message = t('Finished with an error.');
    \Drupal::messenger()->addMessage($message, 'error', TRUE);
  }
}
