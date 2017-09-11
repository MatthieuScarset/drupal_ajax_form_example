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

  //Where we are
  array("source" => "All offices", "translation" => array("ru" => "Офисы")),
  array("source" => "Contact", "translation" => array("ru" => "Контакт")),
  array("source" => "Our local offices", "translation" => array("ru" => "Контакты")),
  array("source" => "All", "translation" => array("ru" => "Все")),
  array("source" => "Country", "translation" => array("ru" => "Cтрана")),
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