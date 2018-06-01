<?php

/**
 * ajout de trads des mois pour les sites ES et PT-BR
 */

$translations_LMNcontext = array(

    array("source" => "January", "translation" => array("fr" => "janvier", "es" => "Enero", "pt-br" => "Janeiro")),
    array("source" => "February", "translation" => array("fr" => "février", "es" => "Febrero", "pt-br" => "Fevereiro")),
    array("source" => "March", "translation" => array("fr" => "mars", "es" => "Marzo", "pt-br" => "Março")),
    array("source" => "April", "translation" => array("fr" => "avril", "es" => "Abril", "pt-br" => "Abril")),
    array("source" => "May", "translation" => array("fr" => "mai", "es" => "Mayo", "pt-br" => "Maio")),
    array("source" => "June", "translation" => array("fr" => "juin", "es" => "Junio", "pt-br" => "Junho")),
    array("source" => "July", "translation" => array("fr" => "juillet", "es" => "Julio", "pt-br" => "Julho")),
    array("source" => "August", "translation" => array("fr" => "août", "es" => "Agosto", "pt-br" => "Agosto")),
    array("source" => "September", "translation" => array("fr" => "septembre", "es" => "Setiembre", "pt-br" => "Setembro")),
    array("source" => "October", "translation" => array("fr" => "octobre", "es" => "Octubre", "pt-br" => "Outubro")),
    array("source" => "November", "translation" => array("fr" => "novembre", "es" => "Noviembre", "pt-br" => "Novembro")),
    array("source" => "December", "translation" => array("fr" => "décembre", "es" => "Diciembre", "pt-br" => "Dezembro")),
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