<?php

/**
 * Récupération de la config d'ob1 adapter
 */
/** @var \Drupal\Core\Config\ConfigFactoryInterface $config_factory */
$config_factory = \Drupal::configFactory();

$config = $config_factory->getEditable('oab_ob1_adapter.theme_settings');

/**
 * Récupération des données de config français et anglais
 */
$data_fr = $config->get('fr');
$data_en = $config->get('en');

// on vérifie si le content_type poc_test_module est déjà dans la config "FR", si non on l'ajoute
if(!in_array('poc_test_module', $data_fr['contents'])) {
  $data_fr['contents'][] = 'poc_test_module';
}

// on vérifie si le content_type poc_test_module est déjà dans la config "EN", si non on l'ajoute
if (!in_array('poc_test_module', $data_en['contents'])) {
  $data_en['contents'][] = 'poc_test_module';
}

// on rajoute les nouvelles données à la config
$config->set('fr', $data_fr);
$config->set('en', $data_en);

// on enregistre la nouvelle config
$config->save(TRUE);
