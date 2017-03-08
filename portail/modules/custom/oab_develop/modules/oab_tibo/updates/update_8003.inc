<?php

// création taxonomie et termes pour profils métiers
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();
if (!isset($vocabularies['jobs_profiles'])) {
  $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::create(array(
    'vid' => 'jobs_profiles',
    'name' => t('Jobs profiles'),
  ));
  $vocabulary->save();
}
$terms = [t('DSI'),t('DRH'),t('DCOMMERCIAL'),t('DCOMMUNICATION'),t('DMARKETING'),t('DVENTES')];
foreach ($terms as $term_name) {
  $term = \Drupal\taxonomy\Entity\Term::create([
    'vid' => 'jobs_profiles',
    'name' => $term_name,
  ]);
  $term->save();
}
