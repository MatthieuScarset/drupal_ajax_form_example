<?php

use Drupal\locale\SourceString;


$translations = array(
	array("source" => "What are you searching for?", "translation" => array("fr" => "Que recherchez vous ?", "ru" => "Что вы ищете?", "ru-en" => "What are you searching for?")),
	array("source" => "Sort by:", "translation" => array("fr" => "Filtrer par:", "ru" => "Фильтр", "ru-en" => "Sort by:")),
	array("source" => "See more", "translation" => array("fr" => "Voir plus", "ru" => "Подробнее", "ru-en" => "See more")),
	array("source" => "More", "translation" => array("fr" => "Plus", "ru" => "Ещё", "ru-en" => "More")),
	array("source" => "Search", "translation" => array("fr" => "Recherche", "ru" => "поиск", "ru-en" => "Search")),
	array("source" => "result", "translation" => array("fr" => "résultat", "ru" => "", "ru-en" => "")),
	array("source" => "results", "translation" => array("fr" => "résultats", "ru" => "", "ru-en" => "")),
	array("source" => "for", "translation" => array("fr" => "pour", "ru" => "", "ru-en" => "")),
	array("source" => "Spelling suggestions", "translation" => array("fr" => "Propositions de recherche", "ru" => "", "ru-en" => "")),
	array("source" => "See all results", "translation" => array("fr" => "Voir tous les résultats", "ru" => "Посмотреть все результаты", "ru-en" => "")),
	array("source" => "Some terms of your search contain results", "translation" => array("fr" => "Certains termes de votre recherche comportent des résultats", "ru" => "", "ru-en" => "")),
	//array("source" => "", "translation" => array("fr" => "", "ru" => "", "ru-en" => "")),
	##Penser à ajouter les versions russes
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