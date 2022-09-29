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

\Drupal::moduleHandler()->loadInclude('oab_data_import', 'inc','includes/product_categories_data_import_operations');
\Drupal::moduleHandler()->loadInclude('oab_data_import', 'inc', 'includes/product_categories_terms_import_operations');


/** Retourne l'objet Term à partir du vocab, de son libellé et de la langue
 * @param string $termLabel
 * @param string $vocabulary
 * @param string $langCode
 * @return \Drupal\Core\Entity\EntityInterface
 * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
 * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
 */
function getTermFromLabelAndVocabulary($termLabel, $vocabulary, $langCode = "en"){

  $entities = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
    [
      'vid' => $vocabulary,
      'langcode' => $langCode,
      'name' => trim($termLabel)
    ]
  );
  if (isset($entities) && !empty($entities)) {
    return array_shift($entities);
  }
  else{
    \Drupal::logger("oab_data_import")->info('terme non trouvé - vid : '.$vocabulary.' - langcode : '.$langCode.' - name: '.trim($termLabel));
    return false;
  }
}
/** Retourne l'objet Term à partir du vocab, de son libellé, de la langue ET de son PARENT
 * @param string $termLabel
 * @param string $parentLabel
 * @param string $vocabulary
 * @param string $langCode
 * @return \Drupal\Core\Entity\EntityInterface
 * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
 * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
 */
function getSubTermFromParentAndLabel($termLabel, $parentTid, $vocabulary, $langCode = "en"){

    $entities = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
      [
        'vid' => $vocabulary,
        'langcode' => $langCode,
        'name' => trim($termLabel),
        'parent' => $parentTid
      ]
    );
    if (isset($entities) && !empty($entities)) {
      \Drupal::logger("oab_data_import")->info('terme  trouvé - vid : ' . $vocabulary . ' - langcode : ' . $langCode . ' - name: ' . trim($termLabel). ' - Parent : '.$parentLabel);
      return array_shift($entities);
    } else {
      \Drupal::logger("oab_data_import")->info('terme non trouvé - vid : ' . $vocabulary . ' - langcode : ' . $langCode . ' - name: ' . trim($termLabel). ' - Parent : '.$parentLabel);
      return false;
    }
}


/*** Enreigstre un message d'erreur qui sera affiché à l'utilisateur à la fin du traitement batch
 * @param $numLine Numéro de la ligne en traitement
 * @param $cspTitle Nom du CSP
 * @param $message message d'erreur
 * @param $data donnée en erreur dans le fichier
 * @param $context contexte où doit etre enregistré le message
 */
function logErrorMessage($numLine, $productName, $message, $data, &$context){
  $context['results']['warning']['message'][] =  t('- line @numLine (@productName) - @message  : @data',
    [
      '@numLine' => $numLine,
      '@productName' => $productName,
      '@message' => $message,
      '@data' => $data
    ]
  );
}
