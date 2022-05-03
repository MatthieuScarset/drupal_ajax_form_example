<?php

use Drupal\locale\SourceString;

$storage = \Drupal::service('locale.storage');
$translations = [
  "More information" => "En savoir plus",
  "Offer Detail" => "Détail de l'offre",
  "see all" => "voir tout",
  "see less" => "voir moins",
  "Detail of the range" => "Détail de la gamme",
  "See details" => "Voir le détail",
  "Reduce" => "Réduire",
  "Examples" => "Exemples",
  "Testimonials" => "Témoignages",
  "To go further" => "Aller plus loin",
  "Presentation" => "Présentation",
  "is made for you" => "est fait pour vous",
  "Tailor-made services" => "Services sur-mesure",
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

