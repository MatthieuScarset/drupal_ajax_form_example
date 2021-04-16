<?php

/**
 * Config par défaut pour l'activation du cron d'axiome + ajout de la trad du texte de la config
 */
use Drupal\locale\SourceString;

##Config par défaut (desactivé)
oabt_YmlImport('oab.axiome.yml');

##Ajout de la trad
$translations = array(
  //Génériques
  array("source" => "Enable axiome cron", "translation" => array("fr" => "Activer le cron Axiome")),
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
      'translation' => $translated_string
    ))->save();
  }
}