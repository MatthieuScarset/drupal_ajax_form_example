<?php

// Add a new language.
$spanish = \Drupal\language\Entity\ConfigurableLanguage::load('es');
if($spanish == NULL){
    $languageSpain = \Drupal\language\Entity\ConfigurableLanguage::createFromLangcode('es');
    $languageSpain->save();
}

$portuguese = \Drupal\language\Entity\ConfigurableLanguage::load('pt-pt');
if($portuguese == NULL) {
    $languagePortuguese = \Drupal\language\Entity\ConfigurableLanguage::createFromLangcode('pt-pt');
    $languagePortuguese->save();
}