<?php
use Drupal\locale\SourceString;

/**
 * Ajout de l'ordre d'affichage des types de contenus
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_synomia_search.synomia.searchSettings');
$config_group->set('order_content_types_en', 'product, region, country, solution, industry, customer_story, partner, press_release, press_kit, document, blog_post, magazine, full_html');
$config_group->set('order_content_types_fr', 'product, solution, industry, customer_story, partner, press_release, press_kit, document, blog_post, magazine, full_html, region, country');
$config_group->set('order_content_types_ru', 'product, solution, industry, customer_story, partner, press_release, press_kit, document, blog_post, magazine, full_html, region, country');
$config_group->set('order_content_types_ru-en', 'product, solution, industry, customer_story, partner, press_release, press_kit, document, blog_post, magazine, full_html');
$config_group->save(TRUE);



$translations = array(
	array("source" => "Content", "translation" => array("fr" => "Contenu", "ru" => "Cодержание")),
	array("source" => "Article", "translation" => array("fr" => "Article", "ru" => "Cтатья")),
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