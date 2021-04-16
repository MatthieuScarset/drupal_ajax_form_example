<?php

// Add a new language.
$spanish = \Drupal\language\Entity\ConfigurableLanguage::load('es');
if ($spanish == NULL) {
    $languageSpain = \Drupal\language\Entity\ConfigurableLanguage::createFromLangcode('es');
    $languageSpain->save();
}

$portuguese = \Drupal\language\Entity\ConfigurableLanguage::load('pt-br');
if ($portuguese == NULL) {
    $languagePortuguese = \Drupal\language\Entity\ConfigurableLanguage::createFromLangcode('pt-br');
    $languagePortuguese->save();
}


##Chargement des config pour l'url en /br au lieu de /pt-br
oabt_YmlImport('language.negotiation.yml');