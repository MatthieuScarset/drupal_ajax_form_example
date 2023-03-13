<?php

use Drupal\locale\SourceString;
use Symfony\Component\Yaml\Yaml;

// traductions
$translations = array(
    array("source" => "Solution", "translation" => array("fr" => "Solution")),
    array("source" => "Industry", "translation" => array("fr" => "Secteur d'activité")),
    array("source" => "Type", "translation" => array("fr" => "Format")),
    array("source" => "Region", "translation" => array("fr" => "Région")),
    array("source" => "Category", "translation" => array("fr" => "Catégorie")),
    array("source" => "Geography", "translation" => array("fr" => "Géographie")),
    array("source" => "Thematic", "translation" => array("fr" => "Thématique")),
    array("source" => "Profession", "translation" => array("fr" => "Métier")),
    array("source" => "Market segment", "translation" => array("fr" => "Segment de marché")),
    array("source" => "Year", "translation" => array("fr" => "Année")),
    array("source" => "Month", "translation" => array("fr" => "Mois"))
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

// import view subhomes
$config_path = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_backoffice'). '/config/views/views.view.subhomes.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('views.view.subhomes')->setData($data)->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();
