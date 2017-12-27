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
    'settings' =>
        array (
            'confirmation_back_label' => 'Retour au formulaire',
        ),
) );

