<?php

/**
 * Modif des trads FR/RU des mois
 */

//Mois dans le context "Long month name"
$translations_LMNcontext = array(
  array("source" => "January", "translation" => array("ru" => "января")),
  array("source" => "February", "translation" => array("ru" => "февраля")),
  array("source" => "March", "translation" => array("ru" => "марта")),
  array("source" => "April", "translation" => array("ru" => "апреля")),
  array("source" => "May", "translation" => array("ru" => "мая")),
  array("source" => "June", "translation" => array("ru" => "июня")),
  array("source" => "July", "translation" => array("ru" => "июля")),
  array("source" => "August", "translation" => array("ru" => "августа")),
  array("source" => "September", "translation" => array("ru" => "сентября")),
  array("source" => "October", "translation" => array("ru" => "октября")),
  array("source" => "November", "translation" => array("ru" => "ноября")),
  array("source" => "December", "translation" => array("ru" => "декабря")),

  array("source" => "January", "translation" => array("fr" => "janvier")),
  array("source" => "February", "translation" => array("fr" => "février")),
  array("source" => "March", "translation" => array("fr" => "mars")),
  array("source" => "April", "translation" => array("fr" => "avril")),
  array("source" => "May", "translation" => array("fr" => "mai")),
  array("source" => "June", "translation" => array("fr" => "juin")),
  array("source" => "July", "translation" => array("fr" => "juillet")),
  array("source" => "August", "translation" => array("fr" => "août")),
  array("source" => "September", "translation" => array("fr" => "septembre")),
  array("source" => "October", "translation" => array("fr" => "octobre")),
  array("source" => "November", "translation" => array("fr" => "novembre")),
  array("source" => "December", "translation" => array("fr" => "décembre")),
);

$storage = \Drupal::service('locale.storage');

foreach ($translations_LMNcontext AS $translation) {
  $string = $storage->findString(array(
      'source' => $translation['source'],
      'context'  => 'Long month name')
  );
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
      'translation' => $translated_string
    ))->save();
  }
}
