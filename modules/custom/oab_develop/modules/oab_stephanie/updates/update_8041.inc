<?php

use Drupal\locale\SourceString;

$translations = array(
	array("source" => "Load More", "translation" => array("fr" => "Voir plus")),
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