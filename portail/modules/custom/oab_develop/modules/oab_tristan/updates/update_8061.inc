<?php

use Symfony\Component\Yaml\Yaml;

$form = \Drupal\webform\Entity\Webform::load('telechargement_documents');

if (null !== $form) {
  #Recuperation de l'array des élements du formulaire.
  $elements = Yaml::parse($form->get('elements'));

  if (!isset($elements['mentions_legales'])) {
    $mentionsLegales = array(
      "#type" => "processed_text",
      "#text" => "
<p><span style=\"font-size:1rem;\">Vous êtes informé(e) que les informations que vous communiquez notamment du fait des formulaires qui sont présents sur ce site permettent de répondre à vos demandes et sont uniquement destinées à Orange, en tant que responsable du traitement, à des fins de gestion administrative et commerciale.<br />
Vous disposez, conformément à la loi française n° 78-17 du 6 janvier 1978 modifiée relative à l’informatique, aux fichiers et aux libertés, d’un droit d’accès, de rectification, de modification et de suppression des données qui vous concernent.<br />
Vous pouvez exercer vos droits d’accès, de rectification, de modification et de suppression en nous contactant par courrier à l’adresse suivante : Orange SA, 78 rue Olivier de Serres, 75505 PARIS cedex 15.</span></p>",
      "#format" => "full_html"
    );

    $newElements = [];

    #Pour l'inserer juste avant le bouton (s'il existe)
    if (isset($elements['submit_button_s_'])) {
      $newElements = array_slice($elements, 0, array_search("submit_button_s_", array_keys($elements)))
        + ['mentions_legales' => $mentionsLegales]
        + array_slice($elements, array_search("submit_button_s_", array_keys($elements)), count($elements));
    } else {
      $elements['mentions_legales'] = $mentionsLegales;
      $newElements = $elements;
    }

    $form->set('elements', $newElements);
    $form->save();
  }
}