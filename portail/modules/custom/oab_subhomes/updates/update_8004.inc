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
