<?php

/** création du webform Formulaire de Contact */
$form = \Drupal\webform\Entity\Webform::load('formulaire_de_contact_presse');

if ($form == null) {

    $form = \Drupal\webform\Entity\Webform::create([
        'type'      => 'webform',
        'title'     => 'Formulaire de contact Presse',
        'langcode'  => 'fr',
        'uid'       => '1',
        'status'    => 'open',
        'id'        => 'formulaire_de_contact_presse',
    ]);

    $form->save();
}

// Rajouter un les éléments pour la GDPR (les ID utilisateurs ne sont pas les mêmes en dev, prp et prod


// Chargement de la conf du webform pour la conf
oabt_YmlImport('webform.webform.formulaire_de_contact_presse.yml');


$trad = array (
    'elements' => 'processed_text:
  \'#text\': "<p>Subscribe to our publications</p>\r\n"
nom_et_prenom:
  \'#title\': \'Full name\'
  \'#placeholder\': \'Full name*\'
media:
  \'#title\': Media
  \'#placeholder\': \'Media*\'
votre_email:
  \'#title\': Email
  \'#placeholder\': \'Email*\'
utilisation_des_donnees:
  \'#title\': \'Data use\'
  \'#description\': "<p>I explicitly accept the use of my personal data using this form.</p>\n"
actions:
  \'#submit__label\': Submit
',
    'settings' =>
        array (
            'confirmation_message' => '<p style="font-size: 2rem;"><strong> Your request has been successfully registered.</strong></p>
<p style = "font-size: 1.6rem;">A confirmation email has been sent to the address you provided.</p>',
        ),
    'handlers' =>
        array (
            'email' =>
                array (
                    'settings' =>
                        array (
                            'subject' => 'Orange-business.com : Subscription to our publications',
                            'body' => '<p>Hello, <br />You are now subscribed to our publications and we thank you. We remain at your disposal for any question to <a href="mailto:contact@orange-business.com">contact@orange-business.com</a><br />Best regards,<br />The Orange Business Services Press Team</p>',
                        ),
                ),
        ),
);

$collection = \Drupal::service('config.storage')->createCollection('language.en');
$collection->write('webform.webform.formulaire_de_contact_presse', $trad);
