<?php

$storage = \Drupal::service('locale.storage');
$translations = [
  "Filter" => "Filtrer",
  "Customer Service Providers" => "Fournisseurs de service",
  "more information" => "+ d'informations",
  "CSP Name" => "Nom du CSP",
  "Clear" => "Effacer"
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

