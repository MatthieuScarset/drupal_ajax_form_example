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

\Drupal::moduleHandler()->loadInclude('oab_data_import', 'inc', 'includes/product_categories_data_import_operations');
\Drupal::moduleHandler()->loadInclude('oab_data_import', 'inc', 'includes/product_categories_terms_import_operations');


/** Retourne l'objet Term à partir du vocab, de son libellé et de la langue
 *
 * @param string $term_label
 * @param string $vocabulary
 * @param string $lang_code
 *
 * @return \Drupal\Core\Entity\EntityInterface
 * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
 * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
 */
function getTermFromLabelAndVocabulary($term_label, $vocabulary, $lang_code = "en") {

  $entities = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
    [
      'vid' => $vocabulary,
      'langcode' => $lang_code,
      'name' => trim($term_label)
    ]
  );
  if (isset($entities) && !empty($entities)) {
    return array_shift($entities);
  } else {
    \Drupal::logger("oab_data_import")->info(
      'terme non trouvé - vid : '.$vocabulary.' - langcode : '.$lang_code.' - name: '. trim($term_label));
    return false;
  }
}
/** Retourne l'objet Term à partir du vocab, de son libellé, de la langue ET de son PARENT
 *
 * @param string $term_label
 * @param string $parentLabel
 * @param string $vocabulary
 * @param string $lang_code
 *
 * @return \Drupal\Core\Entity\EntityInterface
 * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
 * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
 */
function getSubTermFromParentAndLabel($term_label, $parent_tid, $vocabulary, $lang_code = "en") {

    $entities = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
      [
        'vid' => $vocabulary,
        'langcode' => $lang_code,
        'name' => trim($term_label),
        'parent' => $parent_tid
      ]
    );
    if (isset($entities) && !empty($entities)) {
      \Drupal::logger("oab_data_import")->info(
        'terme  trouvé - vid : ' . $vocabulary . ' - langcode : ' . $lang_code .
        ' - name: ' . trim($term_label) . ' - Parent : ' . $parent_tid);
      return array_shift($entities);
    } else {
      \Drupal::logger("oab_data_import")->info(
        'terme non trouvé - vid : ' . $vocabulary . ' - langcode : ' . $lang_code .
        ' - name: ' . trim($term_label) . ' - Parent : ' . $parent_tid);
      return false;
    }
}


/*** Enreigstre un message d'erreur qui sera affiché à l'utilisateur à la fin du traitement batch
 *
 * @param $num_line Numéro de la ligne en traitement
 * @param $cspTitle Nom du CSP
 * @param $message message d'erreur
 * @param $data donnée en erreur dans le fichier
 * @param $context contexte où doit etre enregistré le message
 */
function logErrorMessage($num_line, $product_name, $message, $data, &$context) {
  $context['results']['warning']['message'][] =  t('- line @numLine (@productName) - @message  : @data',
    [
      '@numLine' => $num_line,
      '@productName' => $product_name,
      '@message' => $message,
      '@data' => $data
    ]
  );
}
