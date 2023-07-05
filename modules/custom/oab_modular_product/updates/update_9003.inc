<?php

use Drupal\locale\SourceString;

$storage = \Drupal::service('locale.storage');
$translations = [
  "Business needs" => "Vos enjeux",
];

foreach ($translations AS $source => $translation) {
  $string = $storage->findString(array(
      'source' => $source
    )
  );
  if (is_null($string)) {
    $string = new SourceString();
    $string->setString($source);
    $string->setStorage($storage);
    $string->save();
  }

  $trad = $storage->createTranslation(array(
    'lid' => $string->lid,
    'language' => 'fr',
    'translation' => $translation
  ))->save();
}

