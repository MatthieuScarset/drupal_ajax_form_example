<?php
/**
 * Ajout des configurations pour les mails envoyés à la creation/modification d'un webform
 */

use Drupal\oab_backoffice\Form\OabSettingsGdprForm;


$mail_spoc_object = "[orange-business.com][information] [gdpr:form-title] a été créé";
$mail_spoc_body = "Bonjour [gdpr:spoc-pseudo],\r\nUn formulaire sur le portail orange-business.com vient d’être créé par [gdpr:creator-pseudo] ([gdpr:creator-mail]).\r\n<a href=\"[webform:url]\">Lien vers le formulaire</a>\r\nUn e-mail de validation avant publication vient d’être envoyé à [gdpr:business-owner-mail].\r\nToutefois, si vous notez une irrégularité, nous vous invitons à écrire au plus vite à <a href=\"mailto:digital.mec@orange.com\">digital.mec@orange.com</a>.\r\n\r\nCordialement,\r\nL’équipe Digitale orange-business.com";

$mail_creator_object = "[orange-business.com] [gdpr:form-title] a bien été créé";
$mail_creator_body = "Bonjour,\r\nVotre formulaire « [gdpr:form-title] » a bien été enregistré. Un e-mail de demande de validation a été envoyé à [gdpr:business-owner-mail].\r\nLorsque ce dernier aura validé votre formulaire vous en serez averti et celui-ci sera immédiatement accessible en ligne via cette URL : [webform:url].\r\n\r\nCordialement,\r\nL’équipe Digitale orange-business.com";

$mail_business_owner_object = "[orange-business.com] [gdpr:form-title] est en attente de votre validation";
$mail_business_owner_body =  "Bonjour,\r\nUn formulaire sur le portail orange-business.com vient d’être créé par [gdpr:creator-pseudo] ([gdpr:creator-mail]).\r\n<a href=\"[webform:url]\">Lien vers le formulaire</a>\r\nAvant que celui-ci ne soit en ligne, vous devez le valider.\r\nDans le cadre du respect du traitement des données personnelles, nous vous remercions de bien vérifier l’intégrité de cette demande (champs, message, présence des mentions légales…).\r\n\r\n<span style=\"text-decoration: underline\">Je valide le formulaire et m’engage au respect des données personnelles récoltées.</span>\r\n\r\nSi vous notez une irrégularité, nous vous invitons à écrire au plus vite à <a href=\"mailto:digital.mec@orange.com\">digital.mec@orange.com</a>.\r\n\r\nCordialement,\r\nL’équipe Digitale orange-business.com";

$mail_validation_object = "[orange-business.com] Votre formulaire a été validé";
$mail_validation_body = "Bonjour,\r\nLe formulaire « [gdpr:form-title] » a été validé.\r\nIl est maintenant accessible à l’adresse suivante : <a href=\"[webform:url]\">[webform:url]</a>.\r\nLe formulaire ainsi que ses données seront supprimées le [gdpr:data-delete-date].\r\n\r\nCordialement,\r\nL’équipe Digitale orange-business.com";


$config_factory = \Drupal::configFactory();
$config_factory->getEditable(OabSettingsGdprForm::getConfigName())
    ->set('mail_spoc_object', $mail_spoc_object)
    ->set('mail_spoc_body', $mail_spoc_body)
    ->set('mail_creator_object', $mail_creator_object)
    ->set('mail_creator_body', $mail_creator_body)
    ->set('mail_business_owner_object', $mail_business_owner_object)
    ->set('mail_business_owner_body', $mail_business_owner_body)
    ->set('mail_validation_object', $mail_validation_object)
    ->set('mail_validation_body', $mail_validation_body)
    ->save(true);

