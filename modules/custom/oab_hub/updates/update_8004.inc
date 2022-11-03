<?php

/**
 * @var $hub_new_term
 * hub new term
 */
$hub_new_term = [
  'vid' => 'hub',
  'name' => 'MSS Assistance',
  'langcode' => 'fr',
  'field_hub_machine_name_suffixe' => 'mss-assistance',
  'field_hub_url' => 'mss-assistance',
  'field_hub_subhomes' => [
    '1133',
    '212',
    '297'
  ],
  'field_hub_menus' => [
    'top-navbar-mss-assistanc-fr',
    'top-right-navbar-mss-ass-fr',
    'main-menu-mss-assistance-fr',
    'direct-access-mss-assist-fr',
    'main-footer-mss-assistan-fr',
  ],
  'field_hub_blocs' => [
    'topnavbarmssassistancfr',
    'toprightnavbarmssassfr',
    'mainmenumssassistancefr',
    'directaccessmssassistfr',
    'mainfootermssassistanfr',
    'contactbarblockhubmsfr'
  ],
  'skip_auto_generation' => true
];

$entity = \Drupal\taxonomy\Entity\Term::create($hub_new_term);
$entity->save();
