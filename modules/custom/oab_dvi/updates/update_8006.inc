<?php

/**
 * Création du webform DVI Contact Global
 * See JIRA DVI-6
 */

$form = \Drupal\webform\Entity\Webform::load('dvi_contact_global');

if ($form === null ) {
  $form = \Drupal\webform\Entity\Webform::create([
    'type'      => 'webform',
      'title'     => 'DVI - Contact global',
      'langcode'  => 'fr',
      'uid'       => '1',
      'status'    => 'open',
      'id'        => 'dvi_contact_global',
      'elements'  => "'#attributes':
  class:
    - webform-dvi-contact-global
dvi_contact_global_description:
  '#type': processed_text
  '#text': |
    <p>Vous avez un projet, une question ? Vous êtes intéressé par une de nos solutions ? Merci de renseigner le fomulaire suivant, nous vous contacterons dans les plus brefs délais.</p>
    
    <p>&nbsp;</p>
    
    <hr />
    <p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>
  '#format': full_html
last_name:
  '#type': textfield
  '#title': 'Last Name'
  '#required': true
first_name:
  '#type': textfield
  '#title': 'First Name'
company:
  '#type': textfield
  '#title': Company
  '#required': true
e_mail:
  '#type': email
  '#title': E-mail
  '#required': true
phone:
  '#type': tel
  '#title': Phone
  '#required': true
subject:
  '#type': textfield
  '#title': Subject
  '#required': true
message:
  '#type': textarea
  '#title': Message
  '#required': true
captcha_dvi_global:
  '#type': captcha
  '#captcha_type': recaptcha/reCAPTCHA
actions:
  '#type': webform_actions
  '#title': 'Submit button(s)'
  '#attributes':
    class:
      - dvi-contact-global-submit-container
  '#submit__attributes':
    class:
      - dvi-contact-global-submit"
  ]);
  $form->save();
}

oabt_YmlImport('webform.webform.dvi_contact_global.yml');


$formNode = \Drupal\node\Entity\Node::create([
  'type'    => 'webform',
  'title'   => 'DVI Contact Global',
  'webform' => 'dvi_contact_global',
  'langcode'  => 'fr',
]);

$formNode->save();

\Drupal::service('path.alias_storage')->delete(array('source' => "/node/" . $formNode->id()));
\Drupal::service('path.alias_storage')->save("/node/" . $formNode->id(), "/ventes-indirectes/contact", "fr");