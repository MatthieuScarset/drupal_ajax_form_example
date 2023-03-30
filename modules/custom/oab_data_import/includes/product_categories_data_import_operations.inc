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
 * Méthode executée pour chaque ligne du fichier d'import des CSV
 *
 */
function oab_data_import_data_product_categories_batch($columns, $line_number, &$context) {

  $context['results']['total'][] = 1; // pour compter le nombre de lignes traitées après

  //Structure du fichier csv
  $product_data = array();
  //0:nid
  $product_data['nid'] = $columns[0];
  //1:langcode
  $product_data['langcode'] = $columns[1];
  //2:product name
  $product_data['product_name'] = $columns[2];
  //4:product category
  $product_data['category'] = $columns[3];
  $product_data['sub_category'] = $columns[4];
  //3:teaser
  $product_data['teaser'] = $columns[5];
  //5-10 : key points
  $product_data['key_points'] = array($columns[6], $columns[7], $columns[8], $columns[9], $columns[10], $columns[11]);

  // Informations de base
  $node = Node::load($product_data['nid']);
  if (!empty($node)) {
    if ($node->bundle() == 'product') {
      // Product name : texte
      $node->set('field_product_name', $product_data['product_name']);

      // Teaser : texte
      $node->set('field_teaser', $product_data['teaser']);

      //Product category : taxonomy term
      $product_category_term = getTermFromLabelAndVocabulary($product_data['category'], 'product_categories', $product_data['langcode']);
      if ($product_category_term !== false) {
        $sub_term = getSubTermFromParentAndLabel($product_data['sub_category'], $product_category_term->id(),
          'product_categories', $product_data['langcode']);
        if ($sub_term !== false) {
          $node->set('field_product_category', $sub_term->id());
        } else {
          logErrorMessage($line_number, $product_data['product_name'],
            'incorrect taxonomy term for SUB Product category (term not found) ', $product_data['sub_category'], $context);
        }
      } else {
        logErrorMessage($line_number, $product_data['product_name'],
          'incorrect taxonomy term for Product category (term not found) ', $product_data['category'], $context);
      }
      // Key points : text array
      $new_key_points = [];
      foreach ($product_data['key_points'] as $key_point) {
        if (!empty(trim($key_point))) {
          $new_key_points[] = $key_point;
        }
      }
      $node->set('field_key_points', $new_key_points);
      $node->save();
    } else {
      logErrorMessage($line_number, $product_data['product_name'], 'Not is not product ', $product_data['nid'], $context);
    }
  } else {
    logErrorMessage($line_number, $product_data['product_name'], 'Product not found ', $product_data['nid'], $context);
  }
}

/**
 * Méthode appelée à la fin des batchs
 */
function oab_data_import_data_product_categories_batch_finished($success, $results, $operations) {
    if ($success) {
        $message = \Drupal::translation()->formatPlural(count($results['total']), 'One product updates.', '@count products updates.');
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
