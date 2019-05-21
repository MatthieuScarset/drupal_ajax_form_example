<?php

use Drupal\locale\SourceString;

oabt_YmlImport('field.field.subhome_entity.presse.field_team_title.yml');
oabt_YmlImport('field.field.subhome_entity.presse.field_team_visual.yml');
oabt_YmlImport('field.field.subhome_entity.presse.field_team_button.yml');

$translations = array(
    array("source" => "The field @field in the @group tab is required", "translation" => "Le champ @field dans l'onglet @group est obligatoire"),
    array('source' => "Every field should be fulfilled", "translation" => "Tous les champs doivent être renseignés"),
    array("source" => "Either Aplat or Visual in Corporate Group should be set", "translation" => "Vous devez renseigné soit l'Aplat soit le Visual dans l'onglet Corporate")
);

$storage = \Drupal::service('locale.storage');

foreach ($translations AS $translation) {
    $string = $storage->findString(array(
            'source' => $translation['source'])
    );
    if (is_null($string)) {
        $string = new SourceString();
        $string->setString($translation['source']);
        $string->setStorage($storage);
        $string->save();
    }

    // Create translation. If one already exists, it will be replaced.
    $translation = $storage->createTranslation(array(
        'lid' => $string->lid,
        'language' => 'fr',
        'translation' => $translation['translation']
    ))->save();

}
