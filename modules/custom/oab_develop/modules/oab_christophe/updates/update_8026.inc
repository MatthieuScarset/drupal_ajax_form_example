<?php

use Drupal\locale\SourceString;

$translations = array(
  array("source" => "By solution", "translation" => array("fr" => "Par solution")),
  array("source" => "By industry", "translation" => array("fr" => "Par industrie")),
  array("source" => "By type", "translation" => array("fr" => "Par type")),
  array("source" => "By region", "translation" => array("fr" => "Par région")),
  array("source" => "By thematic", "translation" => array("fr" => "Par thématique")),
  array("source" => "By job profile", "translation" => array("fr" => "Par profil")),
  array("source" => "By market segment", "translation" => array("fr" => "Par segment de marché")),
  array("source" => "By year", "translation" => array("fr" => "Par année")),
  array("source" => "By month", "translation" => array("fr" => "Par mois"))
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