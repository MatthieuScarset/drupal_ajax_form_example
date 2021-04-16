<?php

/**
 * Création du webform DVI Contact Distributor pour inclusion dans block dans la page Distributor
 * See JIRA DVI-7 et DVi-16
 */

$form = \Drupal\webform\Entity\Webform::load('dvi_becoming_distributor');

if ($form === null ) {
    $form = \Drupal\webform\Entity\Webform::create([
        'type'      => 'webform',
        'title'     => 'DVI - Becoming distributor',
        'langcode'  => 'en',
        'uid'       => '1',
        'status'    => 'open',
        'id'        => 'dvi_becoming_distributor',
        'elements'  => "'#attributes':
  class:
    - webform-dvi-becoming-distributor
dvi_becoming_distributor_description:
  '#type': processed_text
  '#text': |
    <p><span style=\"color:#e74c3c;\">* Mandatory fields</span></p>
  '#format': full_html
votre_societe_desc:
  '#type': processed_text
  '#text': |
    <h3 class=\"titre4\">Your company</h3>
  '#format': full_html
business_name:
  '#type': textfield
  '#title': 'Business name'
  '#required': true
logo:
  '#type': image_file
  '#title': Logo
  '#required': true
sector:
  '#type': select
  '#title': Sector
  '#options':
    professionnal: Professionnal
    pme_entreprise: 'PME / Entreprise'
    public_sector: 'Public sector'
  '#required': true
address:
  '#type': textfield
  '#title': Address
  '#required': true
zip_code:
  '#type': textfield
  '#title': 'Zip Code'
  '#required': true
city:
  '#type': textfield
  '#title': City
  '#required': true
vous_desc:
  '#type': processed_text
  '#text': |
    <h3 class=\"titre4\">Vous</h3>
  '#format': full_html
last_name:
  '#type': textfield
  '#title': 'Last Name'
  '#required': true
first_name:
  '#type': textfield
  '#title': 'First Name'
e_mail:
  '#type': email
  '#title': E-mail
  '#required': true
tel:
  '#type': tel
  '#title': Tel
  '#required': true
  '#international': true
  '#international_initial_country': FR
additional_information:
  '#type': textarea
  '#title': 'Additional information'
captcha:
  '#type': captcha
  '#captcha_type': recaptcha/reCAPTCHA
  '#captcha_admin_mode': true
actions:
  '#type': webform_actions
  '#title': 'Submit button(s)'
  '#attributes':
    class:
      - dvi-becoming-distributor-submit-container"
    ]);
    $form->save();
}
##Je reload la config complete du webform
oabt_YmlImport('webform.webform.dvi_becoming_distributor.yml');

##creation des trad
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('webform.webform.dvi_becoming_distributor',array (
    'title' => 'DVI - Devenir distributeur',
    'elements' => "dvi_becoming_distributor_description:
  '#text': |
    <p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>
votre_societe_desc:
  '#text': |
    <h3 class=\"titre4\">Votre société</h3>
business_name:
  '#title': 'Raison sociale'
sector:
  '#title': 'Votre secteur'
  '#options':
    professionnal: Professionnel
    public_sector: 'Secteur public'
address:
  '#title': Adresse
zip_code:
  '#title': 'Code postal'
city:
  '#title': Ville
vous_desc:
  '#text': |
    <h3 class=\"titre4\">You</h3>
last_name:
  '#title': Nom
first_name:
  '#title': Prénom
additional_information:
  '#title': 'Informations complémentaires'
",
) );


##creation d'un node specifique pour afficher le webform
$formNode = \Drupal\node\Entity\Node::create([
    'type'    => 'webform',
    'title'   => 'DVI Becoming Distributor',
    'webform' => 'dvi_becoming_distributor',
    'langcode'  => 'fr',
]);
$formNode->save();

\Drupal::service('path.alias_storage')->delete(array('source' => "/node/" . $formNode->id()));
\Drupal::service('path.alias_storage')->save("/node/" . $formNode->id(), "/ventes-indirectes/devenir-revendeur", "fr");