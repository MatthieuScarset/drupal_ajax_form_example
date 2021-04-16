<?php

##Update des traductions des webforms Contact Global et Becoming distributor
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('webform.webform.dvi_becoming_distributor',array (
    'title' => 'DVI - Devenir distributeur',
    'elements' => "dvi_becoming_distributor_description:
  '#text':  |
    <p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>
votre_societe_desc:
  '#text':  |
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
  '#text':  |
    <h3 class=\"titre4\">Vous</h3>
last_name:
  '#title': Nom
first_name:
  '#title': Prénom
additional_information:
  '#title': 'Informations complémentaires'
",
) );

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('webform.webform.dvi_contact_global',array (
    'elements' => "dvi_contact_global_description:
  '#text': \"<p>Vous avez un projet, une question ? Vous êtes intéressé par une de nos solutions ? Merci de renseigner le fomulaire suivant, nous vous contacterons dans les plus brefs délais.</p>\n\n<p>&nbsp;</p>\n\n<hr />\n<p><span style=\"color:#e74c3c;\">* Champs obligatoires</span></p>\n\"
first_name:
  '#title': Prénom
last_name:
  '#title': Nom
company:
  '#title': Société
phone:
  '#title': Téléphone
subject:
  '#title': Objet
actions:
  '#title': Valider
",
  'handlers' =>
  array (
    'email_demandeur' =>
    array (
      'settings' =>
      array (
        'body' => '',
      ),
    ),
    'email_to_dvi' =>
    array (
      'settings' =>
      array (
        'body' => '',
      ),
    ),
  ),
  'settings' =>
  array (
    'confirmation_message' => '',
  ),
) );


##J'en profite pour ajouter les emails au formulaire Becoming Distributor
oabt_YmlImport('webform.webform.dvi_becoming_distributor.yml');
