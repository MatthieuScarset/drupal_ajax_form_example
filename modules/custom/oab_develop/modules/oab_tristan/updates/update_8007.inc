<?php

/**
 * Ajout de la traduction des tailles de fichiers
 */


use Drupal\locale\SourceString;


$translations = array(
  array("source" => "B", "translation" => array("fr" => "o")),
  array("source" => "KB", "translation" => array("fr" => "Ko")),
  array("source" => "MB", "translation" => array("fr" => "Mo")),
  array("source" => "GB", "translation" => array("fr" => "Go")),
  array("source" => "TB", "translation" => array("fr" => "To")),
  ##Penser à ajouter les versions russes
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