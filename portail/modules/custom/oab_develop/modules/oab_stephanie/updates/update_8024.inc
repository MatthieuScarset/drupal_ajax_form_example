<?php
use Drupal\Core\Database\Database;
use Drupal\locale;


$source = \Drupal::service('locale.storage')->findString(array('source' => 'Edit Link'));
if ($source)
{
  $stringDatabaseStorage = new locale\StringDatabaseStorage(Database::getConnection());
  $translation = $stringDatabaseStorage->findTranslation(
    array('lid' => $source->getId(),
      'language' => 'fr',
      'translation' => 'Lien de modification'));
  if($translation)
  {
    $translation->setString('Modifier le lien');
    $stringDatabaseStorage->save($translation);
  }
}
