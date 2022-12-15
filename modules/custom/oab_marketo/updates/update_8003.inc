<?php

use \Drupal\oab_backoffice\Form\OabSettingsPardotForm;
use \Drupal\paragraphs\Entity\Paragraph;

/** @var \Drupal\Core\Config\Config $mktoDefaultConfig */
$mktoDefaultConfig = \Drupal::configFactory()->getEditable(OabSettingsPardotForm::getConfigName());

$mktoDefaultFollowUp = $mktoDefaultConfig->get('marketo.document.mkto_form_follow_up_message');

$paragraphEN = Paragraph::create([
  'langcode' => 'en',
  'type' => 'marketo',
  'field_form_id' => $mktoDefaultConfig->get('marketo.document.mkto_form_id'),
  'field_title' => $mktoDefaultConfig->get('marketo.document.mkto_form_name'),
  'field_message_of_thanks' => [
    'value' => $mktoDefaultFollowUp['value'] ?: "",
    'format' => $mktoDefaultFollowUp['format'] ?: 'full_html',
  ],
  'field_redirection_url' => $mktoDefaultConfig->get('marketo.document.mkto_custom_follow_up_url'),
  'field_requires_altares' => FALSE,
]);

$paragraphEN->save();
\Drupal::logger('oab_marketo')->warning('Paragraph pour la config marketo EN créé');

$langcodes = ['fr', 'es', 'pt-br'];
$paragraphIds = array();

foreach ($langcodes as $langcode) {
  /** @var Drupal\language\Config\LanguageConfigOverride $configLanguage */
  $configLanguage = \Drupal::languageManager()->getLanguageConfigOverride($langcode, OabSettingsPardotForm::getConfigName());
  $mktoFollowUp = $configLanguage->get('marketo.document.mkto_form_follow_up_message');

  $paragraph = Paragraph::create([
    'langcode' => $langcode,
    'type' => 'marketo',
    'field_form_id' => $configLanguage->get('marketo.document.mkto_form_id') ?: $mktoDefaultConfig->get('marketo.document.mkto_form_id'),
    'field_title' => $configLanguage->get('marketo.document.mkto_form_name') ?: $mktoDefaultConfig->get('marketo.document.mkto_form_name'),
    'field_message_of_thanks' => [
      'value' => $mktoFollowUp['value'] ?: $mktoDefaultFollowUp['value'],
      'format' => $mktoFollowUp['format'] ?: 'full_html',
    ],
    'field_redirection_url' => $configLanguage->get('marketo.document.mkto_custom_follow_up_url') ?: $mktoDefaultConfig->get('marketo.document.mkto_custom_follow_up_url') ,
    'field_requires_altares' => FALSE,
  ]);
  $paragraph->save();
  $paragraphIds[$langcode] = $paragraph->id();
  \Drupal::logger('oab_marketo')->warning('Paragraph pour la config marketo '.$langcode.' créé');
}

//on efface les config pour y mettre les id des paragraphes
$mktoDefaultConfig->clear('marketo.document');
$mktoDefaultConfig->set('marketo.document.paragraph_id', $paragraphEN->id());
$mktoDefaultConfig->save();

foreach ($langcodes as $langcode) {
  /** @var Drupal\language\Config\LanguageConfigOverride $configLanguage */
  $configLanguage = \Drupal::languageManager()
    ->getLanguageConfigOverride($langcode, OabSettingsPardotForm::getConfigName());
  $configLanguage->clear('marketo.document');
  $configLanguage->set('marketo.document.paragraph_id', $paragraphIds[$langcode]);
  $configLanguage->save();
}
