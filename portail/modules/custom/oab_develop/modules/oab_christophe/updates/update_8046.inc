<?php

use Drupal\Core\Database\Database;
use Drupal\locale;

// on récupère ou on crée la chaine source
$match_string = array('source' => 'Share on', 'context' => '');
$source = \Drupal::service('locale.storage')->findString($match_string);
if (!$source) {
  // Si la source n'existe pas, on la crée
  $source = \Drupal::service('locale.storage')->createString($match_string);
  $source->save();
}

// On crée et enregistre un objet de traduction (fait l'insertion et l'update)
$connection = Database::getConnection();
$stringDatabaseStorage = new locale\StringDatabaseStorage($connection);
$translation = $stringDatabaseStorage->createTranslation(array('lid' => $source->getId(), 'language' => 'fr', 'translation' => 'Partager sur'));
$stringDatabaseStorage->save($translation);