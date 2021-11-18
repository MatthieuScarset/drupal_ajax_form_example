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
use Drupal\oab_bvpn_import\Classes\CSPImport;
use Drupal\node\Entity\Node;
use Drupal\file\Entity\File;
use Drupal\media\Entity\Media;


/**
 * Méthode executée pour chaque ligne du fichier d'import des CSV
 *
 */
function oab_bvpn_import_batch($columns, $lineNumber, &$context) {

  $context['results']['total'][]  = 1; // pour compter le nombre de lignes traitées après

  //Structure du fichier csv
  $csp = array();
  //0:logo
  $csp['logo'] = $columns[0];
  //1:nom du csp
  $csp['title'] = $columns[1];
  //2:description
  $csp['field_content'] = $columns[2];
  //3:localisation/noms des villes => qu'on n'enregistre pas
  //4:localisation
  $csp['field_csp_location'] = $columns[4];
  //5:Marché (FR ou EN)
  $csp['langcode'] = $columns[5];
  //6:Complexité (M/S/H)
  $csp['field_technical_qualification'] = $columns[6];
  //7:Type de service (Iaas/Saas)
  $csp['field_type_of_cloud_services'] = $columns[7];
  //8:Modèle de facturation
  $csp['field_facturation'] = $columns[8];
  //9:Bande passante (50, 100, 200...)
  $csp['field_bandwidth'] = $columns[9];
  //10:Disponibilité
  //11:Fournisseur (Partenaire ou offre orange)
  $csp['field_provider_type'] = $columns[11];
  //12:Région (taxo Location)
  $csp['field_location'] = $columns[12];

  // Informations de base
  $node = Node::create([
    'type'        => 'cloud_service_provider',
    'title'       => $csp['title'],
    'isNew'       => true,
    'langcode'    => $csp['langcode'],
    'status'      => 0, //draft
    'promoted'    => 0,
    'sticky'      => 0,
  ]);

  // Bandwidth : texte
  $node->set('field_bandwidth', $csp['field_bandwidth']);

  // Content : texte
  $node->set('field_content', $csp['field_content']);

  // Facturation : texte
  $node->set('field_facturation', $csp['field_facturation']);

  // Complexité : texte
  $node->set('field_technical_qualification', $csp['field_technical_qualification']);

  // CSP Location = > champs geolocation multiple
  // format dans le csv : "lat, lng","lat2, lng2",...
  $allCoordinates = array();
  $geolocArray = explode('","',$csp['field_csp_location']);
  if(count($geolocArray) > 0){
    foreach ($geolocArray as $geolocItem){
      $geolocItem = str_replace('"','',$geolocItem);
      $coordinates = explode(',', $geolocItem);
      if(count($coordinates) > 1) {
        $allCoordinates[] = ['lat' => trim($coordinates[0]), 'lng' => trim($coordinates[1])];
      }
      else{
        logErrorMessage($lineNumber, $csp['title'], 'incorrect format gps coordinates (Location) ', $csp['field_csp_location'], $context);
      }
    }
  }
  $node->set('field_csp_location', $allCoordinates);


  // Location - Taxo Location : peuvent être multiples, séparées par des ,
  $locationsLabels = explode(",", $csp['field_location']);
  $tidsLocation = [];
  foreach ($locationsLabels as $label){
    $term = getTermFromLabelAndVocabulary($label, 'location', $csp['langcode']);
    if($term !== false){
      $tidsLocation[] = $term->id();
    }
    else{
      logErrorMessage($lineNumber, $csp['title'], 'incorrect taxonomy term (lang:'.$csp['langcode'].') for Location (term not found) ', $label, $context);
    }
  }
  $node->set('field_location', $tidsLocation);

  // Provider type
  $typeProTerm = getTermFromLabelAndVocabulary($csp['field_provider_type'], 'service_providers', $csp['langcode']);
  if($typeProTerm !== false){
    $node->set('field_provider_type', $typeProTerm->id());
  }
  else{
    logErrorMessage($lineNumber, $csp['title'], 'incorrect taxonomy term for Service providers type (term not found) ', $csp['field_provider_type'], $context);
  }

  // Type of Cloud Service
  $typeCSTerm = getTermFromLabelAndVocabulary($csp['field_type_of_cloud_services'], 'type_of_cloud_service', $csp['langcode']);
  if($typeCSTerm !== false){
    $node->set('field_type_of_cloud_services', $typeCSTerm->id());
  }
  else{
    logErrorMessage($lineNumber, $csp['title'], 'incorrect taxonomy term for Type of Cloud service (term not found) ', $csp['field_type_of_cloud_services'], $context);
  }

  //Logo
  $logoFileName = $csp['logo'];
  $logoFilePathName = CSPImport::LOGOS_DIRECTORY . $logoFileName;
  //test de la présence du fichier
  if(file_exists($logoFilePathName)){
    $filesystem = \Drupal::service('file_system');
    // Create file entity.
    $image = File::create();
    $image->setFileUri($logoFilePathName);
    $image->setOwnerId(\Drupal::currentUser()->id());
    $image->setMimeType('image/' . pathinfo($logoFilePathName, PATHINFO_EXTENSION));
    $image->setFileName($filesystem->basename($logoFilePathName));
    $image->setPermanent();
    $image->save();

    // Create media entity with saved file.
    $image_media = Media::create([
      'bundle' => 'image',
      'uid' => \Drupal::currentUser()->id(),
      'langcode' => $csp['langcode'],
      'status' => 1,
      'field_image' => [
        'target_id' => $image->id(),
        'alt' => $csp['title'],
        'title' => $csp['title'],
      ],
    ]);
    $image_media->save();

    $node->set('field_logo', $image_media->id());
  }
  else{
    logErrorMessage($lineNumber, $csp['title'], 'logo file not found ', $logoFilePathName, $context);
  }
  $node->save();

}

/**
 * Méthode appelée à la fin des batchs
 */
function oab_bvpn_import_batch_finished($success, $results, $operations) {
    if ($success) {
        $message = \Drupal::translation()->formatPlural(count($results['total']), 'One CSP imported.','@count CSP imported.');
        \Drupal::messenger()->addMessage($message, 'status', TRUE);

        if(count($results['warning']['message']) > 0){
          Drupal::messenger()->addMessage("Errors occured in file : ", 'warning', TRUE);
          foreach ($results['warning']['message'] as $message){
            Drupal::messenger()->addMessage($message, 'warning', TRUE);
          }
        }

    } else {
        $message = t('Finished with an error.');
        \Drupal::messenger()->addMessage($message, 'error', TRUE);
    }
}

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
    \Drupal::logger("oab_bvpn_import")->info('terme non trouvé - vid : '.$vocabulary.' - langcode : '.$langCode.' - name: '.trim($termLabel));

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
function logErrorMessage($numLine, $cspTitle, $message, $data, &$context){
  $context['results']['warning']['message'][] =  t('- line @numLine (@cspName) - @message  : @data',
    [
      '@numLine' => $numLine,
      '@cspName' => $cspTitle,
      '@message' => $message,
      '@data' => $data
    ]
  );
}