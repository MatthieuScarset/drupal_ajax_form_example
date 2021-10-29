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
function oab_data_import_terms_product_categories_batch($columns, $lineNumber, &$context)
{

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
  $parentTerm = getTermFromLabelAndVocabulary($terms_data['categ'], 'product_categories', $terms_data['langcode']);
  $parentTid = 0;
  if($parentTerm === false){
    // Terme parent non trouvé ==> à créer
    $newParent = \Drupal\taxonomy\Entity\Term::create(array(
        'name' => $terms_data['categ'],
        'langcode' => $terms_data['langcode'],
        'vid' => 'product_categories'
      )
    );
    $newParent->save();
    $parentTid = $newParent->id();
  }
  else{
    $parentTid = $parentTerm->id();
  }

  //SUB TERM
  $subTerm = getSubTermFromParentAndLabel($terms_data['sub_categ'], $parentTid,'product_categories', $terms_data['langcode']);
  if($subTerm === false){
    // Sub-Term parent non trouvé ==> à créer
    $subTerm = \Drupal\taxonomy\Entity\Term::create(array(
        'name' => $terms_data['sub_categ'],
        'langcode' => $terms_data['langcode'],
        'parent' => $parentTid,
        'vid' => 'product_categories'
      )
    );
    $subTerm->save();
  }
  $subTerm->set('field_simple_description', trim($terms_data['sub_categ_txt']));
  $subTerm->set('field_icon', trim($terms_data['icon']));
  $subTerm->save();
}

/**
 * Méthode appelée à la fin des batchs
 */
function oab_data_import_terms_product_categories_batch_finished($success, $results, $operations)
{
  if ($success) {
    $message = \Drupal::translation()->formatPlural(count($results['total']), 'One line', '@count lines.');
    \Drupal::messenger()->addMessage($message, 'status', TRUE);

    if (count($results['warning']['message']) > 0) {
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
