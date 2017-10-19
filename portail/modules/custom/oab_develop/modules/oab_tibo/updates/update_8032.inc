<?php

use Drupal\locale\SourceString;

$translations = array(
    array("source" => "Share on", "translation" => array("fr" => "Partager sur" )),
    array("source" => "Share on", "translation" => array("ru" => "Поделиться нa")),
    array("source" => "Subscribe to RSS feed", "translation" => array("fr" => "S'abonner au flux RSS" )),
    array("source" => "Subscribe to RSS feed", "translation" => array("ru" => "Подписаться на RSS лентy")),
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