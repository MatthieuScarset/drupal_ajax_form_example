<?php
use Drupal\locale\SourceString;


/**
 * Création d'une vue contenant 2 display view de type "Entity Ref"
 * afin de modifier le retour des autocomplete de la zone rebond
 */

##Création de la vue et des deux displays views
oabt_YmlImport('views.view.rebond_entity_reference.yml');


##Modification des 3 fields concernés dans les différents types de contenu

$contentTypes = [
  "blog_post",
  "customer_story",
  "document",
  "full_html",
  "magazine",
  "partner",
  "press_release",
  "simple_page",
  "webform",
];

foreach ($contentTypes as $contentType) {
  oabt_YmlImport("field.field.node.$contentType.field_rebond_document.yml");
  oabt_YmlImport("field.field.node.$contentType.field_page_du_site_1.yml");
  oabt_YmlImport("field.field.node.$contentType.field_page_du_site_2.yml");
}

##############################
# AJOUT DE QQUES TRADS pour le block rebond\Product

$translations = array(
  array("source" => "Create an account", "translation" => array("fr" => "Créer un compte")),
  array("source" => "https://dro.orange-business.com/authentification?TYPE=33554433&REALMOID=06-0000e733-54df-1266-8576-5e0e0a63d064&GUID=&SMAUTHREASON=0&METHOD=GET&SMAGENTNAME=-SM-TPZ0eHv9wdQAe0KqXWVXK5B%2b8mUfc6au28lAfEL%2bvsCray2ghF0v8nhYk9lzcjpc&TARGET=-SM-https%3a%2f%2fmy--service--space.orange--business.com%2f&codeContexte=MSS",
              "translation" => array("fr" => "http://www.orange-business.com/fr/ece")),
  array("source" => "http://www.orange-business.com/en/my-service-space-account-request",
              "translation" => array("fr" => "https://espaceclient.orange-business.com/web/ece2/creation")),
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