<?php
use Drupal\locale\SourceString;

$collection = \Drupal::service('config.storage')->createCollection('language.fr');

###########################################################
## Ajout des trads de la vue
$trad_fr = array (
    'display' =>
        array (
            'default' =>
                array (
                    'display_options' =>
                        array (
                            'filters' =>
                                array (
                                    'field_insight_type_target_id' =>
                                        array (
                                            'expose' =>
                                                array (
                                                    'label' => 'Filtrer par',
                                                ),
                                        ),
                                    'field_insight_target_id' =>
                                        array (
                                            'expose' =>
                                                array (
                                                    'label' => 'Visions Business sur',
                                                ),
                                            'group_info' =>
                                                array (
                                                    'description' => '',
                                                ),
                                        ),
                                ),
                        ),
                ),
        ),
);
$collection->write('views.view.business_insight', $trad_fr);



$storage = \Drupal::service('locale.storage');
$translations = [
    "All thematics " => "toutes nos thématiques",
    "See all" => "Tout voir"
];

foreach ($translations AS $source => $translation) {
    $string = $storage->findString(array(
            'source' => $source
        )
    );
    if (is_null($string)) {
        $string = new SourceString();
        $string->setString($source);
        $string->setStorage($storage);
        $string->save();
    }

    $trad = $storage->createTranslation(array(
        'lid' => $string->lid,
        'language' => 'fr',
        'translation' => $translation
    ))->save();
}

