<?php

/**
 * Création du webform DVI Contact Distributor pour inclusion dans block dans la page Distributor
 * See JIRA DVI-7 et DVi-16
 */

$form = \Drupal\webform\Entity\Webform::load('dvi_contact_distributor');

if ($form === null ) {
    $form = \Drupal\webform\Entity\Webform::create([
        'type'      => 'webform',
        'title'     => 'DVI - Contact distributor',
        'langcode'  => 'en',
        'uid'       => '1',
        'status'    => 'open',
        'id'        => 'dvi_contact_distributor',
        'elements'  => "'#attributes':
  class:
    - webform-dvi-contact-distributor
last_name:
  '#type': textfield
  '#title': 'Last name'
  '#multiple__header_label': Bla
  '#required': true
first_name:
  '#type': textfield
  '#title': 'First name'
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
  '#international': true
  '#international_initial_country': FR
  '#label': bli
subject:
  '#type': textfield
  '#title': Subject
  '#required': true
message:
  '#type': textarea
  '#title': Message
  '#required': true
captcha_dvi_contact_distributor:
  '#type': captcha
  '#captcha_type': recaptcha/reCAPTCHA
  '#captcha_admin_mode': true
distributeur_email:
  '#type': hidden
  '#title': distributeur-email
distributeur_name:
  '#type': hidden
  '#title': distributeur-name
distributeur_nid:
  '#type': hidden
  '#title': distributeur-nid
dvi_contact_distributor_description:
  '#type': processed_text
  '#text': |
    <p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>
  '#format': full_html"
    ]);
    $form->save();
}
##Je reload la config complete du webform
oabt_YmlImport('webform.webform.dvi_contact_distributor.yml');

##creation des trad
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('webform.webform.dvi_contact_distributor', array (
    "elements" => "last_name:
  '#title': Nom
first_name:
  '#title': Prénom
company:
  '#title': Société
phone:
  '#title': Téléphone
subject:
  '#title': Objet
dvi_contact_distributor_description:
  '#text': '<p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>'
",
  "settings" => 
  array (
    'confirmation_message' => 'Merci pour votre demande. Le distributeur reviendra rapidement vers vous.',
    'confirmation_back_label' => 'Retour au formulaire',
  ),
));


##Création du block
oabt_YmlImport("block.block.dvicontactdistributorblock.yml");
