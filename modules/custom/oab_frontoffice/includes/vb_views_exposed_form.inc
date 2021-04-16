<?php

// Gestion de l'affichage des forms spécifiques à la view business-insight via une fonction pour ne pas surcharger le .module

function vb_views_exposed_form(&$form) {

  if (strpos($form['#id'], 'views-exposed-form-business-insight-business-insight-page') !== false) {
    $form['vb_thematic'] = change_textfield_to_select('thematic');
  }

}
