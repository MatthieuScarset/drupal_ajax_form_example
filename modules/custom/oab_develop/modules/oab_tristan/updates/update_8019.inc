<?php

/**
 * Ajout des traductions des mois
 */

$translations = array(
  array("source" => "January", "translation" => array("fr" => "Janvier")),
  array("source" => "February", "translation" => array("fr" => "Février")),
  array("source" => "March", "translation" => array("fr" => "Mars")),
  array("source" => "April", "translation" => array("fr" => "Avril")),
  array("source" => "May", "translation" => array("fr" => "Mai")),
  array("source" => "June", "translation" => array("fr" => "Juin")),
  array("source" => "July", "translation" => array("fr" => "Juillet")),
  array("source" => "August", "translation" => array("fr" => "Août")),
  array("source" => "September", "translation" => array("fr" => "Septembre")),
  array("source" => "October", "translation" => array("fr" => "Octobre")),
  array("source" => "November", "translation" => array("fr" => "Novembre")),
  array("source" => "December", "translation" => array("fr" => "Décembre")),
);


$storage = \Drupal::service('locale.storage');

foreach ($translations AS $translation) {
  $string = $storage->findString(array('source' => $translation['source']));
  if (is_null($string)) {
    $string = new SourceString();
    $string->setString($translation['source']);
    $string->setStorage($storage);
    $string->save();
  }

  foreach ($translation['translation'] AS $language => $translated_string) {
    // Create translation. If one already exists, it will be replaced.
    $translation = $storage->createTranslation(array(
      'lid' => $string->lid,
      'language' => $language,
      'translation' => $translated_string,
    ))->save();
  }
}