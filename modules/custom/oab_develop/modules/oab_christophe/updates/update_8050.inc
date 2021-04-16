<?php

use Drupal\locale\SourceString;

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('core.date_format.short', array (
  "pattern" => "d/m/Y - H:i"
));

$storage = \Drupal::service('locale.storage');
$string_source = "Scheduled on";
$string = $storage->findString(array('source' => $string_source));
if (is_null($string)) {
  $string = new SourceString();
  $string->setString($string_source);
  $string->setStorage($storage);
  $string->save();
}

// Create translation. If one already exists, it will be replaced.
$translation = $storage->createTranslation(array(
  'lid' => $string->lid,
  'language' => "fr",
  'translation' => "Planifié pour le",
))->save();