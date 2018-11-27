<?php

oabt_YmlImport('views.view.subhomes');

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$config_fr = $collection->read('views.view.subhomes');

$config_fr["display"]["page_press"]["display_options"]["empty"]["area"]["content"] = array(
    "value" => "<p>Aucun élément ne correspond à votre requête. Veuillez élargir votre recherche.</p>",
    "format" => "full_html"
);

$collection->write('views.view.subhomes', $config_fr);
