<?php
use \Drupal\locale\SourceString;
/**
 * Update 8037 : rechargement de l'entite Produit pour ajouter un boolean "is DVI Product"
 * + ajouts de trad pour des erreurs dans le formulaire du produit
 */
oabt_YmlImport('core.entity_view_display.node.product.default.yml');
oabt_YmlImport('core.entity_form_display.node.product.default.yml');


$translations = array(
    array("source" => "Since you declare the product as DVI, you need to select at least one element of the DVI Market Segment taxonomy",
        "translation" => array("fr" => "Comme vous avez déclaré le produit comme étant DVI, vous devez selectionner au moins un terme de la taxonomy Segment de Marché DVI")),
    array("source" => "Since you declare the product as DVI, you must select \"Products DVI\" as a subhome",
        "translation" => array("fr" => "Comme vous avez déclaré le produit comme DVI, vous devez selectionner \"Produits DVI\" comme subhome"))
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
