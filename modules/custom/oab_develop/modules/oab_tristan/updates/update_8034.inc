<?php

use Drupal\locale\SourceString;

/**
 * Ajout des traductions russes des mois
 */
$translations = array(
  //Génériques
  array("source" => "Apply", "translation" => array("ru" => "Найти")),
  array("source" => "Thematic", "translation" => array("ru" => "Тема")),
  array("source" => "Solution", "translation" => array("ru" => "Решения")),
  array("source" => "Industry", "translation" => array("ru" => "Oтрасли")),
  array("source" => "Share", "translation" => array("ru" => "Поделиться")),
  array("source" => "Share", "translation" => array("fr" => "Partager")),
  array("source" => "Follow us", "translation" => array("ru" => "Подпишитесь на наши новости")),
  array("source" => "Download", "translation" => array("fr" => "Télécharger")),

  //Mois & Années
  array("source" => "January", "translation" => array("ru" => "Января")),
  array("source" => "February", "translation" => array("ru" => "Февраля")),
  array("source" => "March", "translation" => array("ru" => "Марта")),
  array("source" => "April", "translation" => array("ru" => "Апреля")),
  array("source" => "May", "translation" => array("ru" => "Мая")),
  array("source" => "June", "translation" => array("ru" => "Июня")),
  array("source" => "July", "translation" => array("ru" => "Июля")),
  array("source" => "August", "translation" => array("ru" => "Августа")),
  array("source" => "September", "translation" => array("ru" => "Сентября")),
  array("source" => "October", "translation" => array("ru" => "Октября")),
  array("source" => "November", "translation" => array("ru" => "Ноября")),
  array("source" => "December", "translation" => array("ru" => "Декабря")),
  array("source" => "Year", "translation" => array("ru" => "Год")),
  array("source" => "Year", "translation" => array("fr" => "Année")),
  array("source" => "Month", "translation" => array("ru" => "Месяц")),
  array("source" => "Month", "translation" => array("fr" => "Mois")),

  //Subhome Presse
  array("source" => "Press release", "translation" => array("ru" => "Новость")),
  array("source" => "Press release", "translation" => array("fr" => "Communiqué de presse")),
  array("source" => "Press folder", "translation" => array("fr" => "Dossier de presse")),

  //Subhome Docuement
  array("source" => "Document", "translation" => array("ru" => "Брошюра")),
  array("source" => "Download", "translation" => array("ru" => "Скачать")),
  array("source" => "Read more", "translation" => array("ru" => "Читать дальше")),
  array("source" => "Load more", "translation" => array("ru" => "Читать дальше")),
  array("source" => "Load More", "translation" => array("ru" => "Читать дальше")),

  //Where we are - Contacts - Our local offices
  array("source" => "All offices", "translation" => array("ru" => "Офисы")),
  array("source" => "Contact", "translation" => array("ru" => "Контакт")),
  array("source" => "Our local offices", "translation" => array("ru" => "Контакты")),
  array("source" => "All", "translation" => array("ru" => "Все")),
  array("source" => "Country", "translation" => array("ru" => "Cтрана")),
  array("source" => "Region", "translation" => array("ru" => "Pегионы")),
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

//////////////////////////////////
/// Ajout des trads pour le context "Long month name"
///

//Mois dans le context "Long month name"
$translations_LMNcontext = array(
  array("source" => "January", "translation" => array("ru" => "Января")),
  array("source" => "February", "translation" => array("ru" => "Февраля")),
  array("source" => "March", "translation" => array("ru" => "Марта")),
  array("source" => "April", "translation" => array("ru" => "Апреля")),
  array("source" => "May", "translation" => array("ru" => "Мая")),
  array("source" => "June", "translation" => array("ru" => "Июня")),
  array("source" => "July", "translation" => array("ru" => "Июля")),
  array("source" => "August", "translation" => array("ru" => "Августа")),
  array("source" => "September", "translation" => array("ru" => "Сентября")),
  array("source" => "October", "translation" => array("ru" => "Октября")),
  array("source" => "November", "translation" => array("ru" => "Ноября")),
  array("source" => "December", "translation" => array("ru" => "Декабря")),

  array("source" => "January", "translation" => array("fr" => "Janvier")),
  array("source" => "February", "translation" => array("fr" => "Février")),
  array("source" => "March", "translation" => array("fr" => "Mars")),
  array("source" => "April", "translation" => array("fr" => "Avril")),
  array("source" => "May", "translation" => array("fr" => "Mai")),
  array("source" => "June", "translation" => array("fr" => "Juin")),
  array("source" => "July", "translation" => array("fr" => "Juillet")),
  array("source" => "August", "translation" => array("fr" => "Août")),
  array("source" => "September", "translation" => array("fr" => "Septembre")),
  array("source" => "October", "translation" => array("fr" => "Octobre")),
  array("source" => "November", "translation" => array("fr" => "Novembre")),
  array("source" => "December", "translation" => array("fr" => "Décembre")),
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



#############################
#############################
##Ajouts de taxos russes pour le voca Région (En gros : trad des régions en RU)
$termes = array(
  "Asia Pacific" => "Азия",
  "Middle East & Africa" => "Ближний Восток и Африка",
  "Europe" => "Европа",
  "Latin America" => "Латинская Америка",
  "North America" => "Северная Америка",
  "Russia" => "Россия"
);

foreach ($termes as $term => $trad) {
  $termsArray = taxonomy_term_load_multiple_by_name($term, 'regions');
  foreach ($termsArray as $foundterm) {
    if (!empty($foundterm) && !$foundterm->hasTranslation('ru')) {
      $entity_array = $foundterm->toArray();
      $translated_fields = [];
      $translated_fields['name'] = $trad;
      $translated_entity_array = array_merge($entity_array, $translated_fields);
      $foundterm->addTranslation('ru', $translated_entity_array)->save();
    }
  }
}


##Ajout d'un format de date RU pour le format "Node created date"
$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('core.date_format.node_created_date', array (
  'pattern' => 'd F Y',
));