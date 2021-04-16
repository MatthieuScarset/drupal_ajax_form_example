<?php


$translations = array(
  array("source" => "January", "translation" => array("ru" => "Январь")),
  array("source" => "February", "translation" => array("ru" => "Февраль")),
  array("source" => "March", "translation" => array("ru" => "Март")),
  array("source" => "April", "translation" => array("ru" => "Апрель")),
  array("source" => "May", "translation" => array("ru" => "Май")),
  array("source" => "June", "translation" => array("ru" => "Июнь")),
  array("source" => "July", "translation" => array("ru" => "Июль")),
  array("source" => "August", "translation" => array("ru" => "Август")),
  array("source" => "September", "translation" => array("ru" => "Сентябрь")),
  array("source" => "October", "translation" => array("ru" => "Октябрь")),
  array("source" => "November", "translation" => array("ru" => "Ноябрь")),
  array("source" => "December", "translation" => array("ru" => "Декабрь")),
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