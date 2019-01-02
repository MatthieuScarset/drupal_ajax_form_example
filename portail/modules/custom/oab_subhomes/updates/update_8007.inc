<?php

oabt_YmlImport('views.view.subhomes.yml');
oabt_YmlImport('views.view.subhomes_archive.yml');

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$config_fr = $collection->read('views.view.subhomes');

$config_fr["display"]["page_press"]["display_options"]["empty"]["area"]["content"] = array(
    "value" => "<p>Aucun élément ne correspond à votre requête. Veuillez élargir votre recherche.</p>",
    "format" => "full_html"
);

$collection->write('views.view.subhomes', $config_fr);


## Ajout des nouveaux alias RU/ES/BR

/** @var Drupal\Core\Path\AliasStorage $alias_storage */
$alias_storage = \Drupal::service('path.alias_storage');

$alias_storage->delete(['source' => '/subhome_press', 'langcode' => 'ru' ]);
$alias_storage->delete(['source' => '/subhome_press', 'langcode' => 'es' ]);
$alias_storage->delete(['source' => '/subhome_press', 'langcode' => 'br' ]);

$alias_storage->save("/subhome_press_old", "/press", "ru");
$alias_storage->save("/subhome_press_old", "/prensa", "es");
$alias_storage->save("/subhome_press_old", "/imprensa", "br");

# Ajout des trads dans la vue

$langs = ['es', 'br', 'ru'];

foreach($langs as $lang) {

    $collection = \Drupal::service('config.storage')->createCollection('language.' . $lang);
    $config = $collection->read('views.view.subhomes');

    $config["display"]["page_press_old"] = $config["display"]["page_press"];

    $collection->write('views.view.subhomes', $config);
}
