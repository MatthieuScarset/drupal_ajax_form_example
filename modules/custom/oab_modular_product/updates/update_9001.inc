<?php

use Drupal\locale\SourceString;

$storage = \Drupal::service('locale.storage');
$translations = [
  "More information" => "En savoir plus",
  "Offer Detail" => "Détail de l'offre",
  "see more" => "voir plus",
  "see less" => "voir moins",
  "Detail of the range" => "Détail de la gamme",
  "Show details" => "Voir le détail",
  "Hide details" => "Masquer le détail",
  "Examples" => "Exemples",
  "Testimonials" => "Témoignages",
  "To go further" => "Aller plus loin",
  "Presentation" => "Présentation",
  "@product_label is made for you" => "@product_label est fait pour vous",
  "Tailor-made services" => "Services sur-mesure",
  "Read the customer story" => "Lire le témoignage complet",
  "Customer story" => "Témoignages",
  "See the range" => "Voir la gamme",
  "Customer space" => "Espace client",
  "See offer" => "Voir l'offre"
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

