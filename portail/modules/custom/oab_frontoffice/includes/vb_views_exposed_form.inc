<?php

// Gestion de l'affichage des forms spécifiques à la view business-insight via une fonction pour ne pas surcharger le .module

function vb_views_exposed_form(&$form) {

  if (strpos($form['#id'], 'views-exposed-form-business-insight-business-insight-page') !== false) {

    foreach ($form AS $key => $value) {

      if (isset($value['#type'])
        && $value['#type'] == "textfield") {

        if ($key === "vb_thematic") {
          $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::load('thematic');
        }

        if (is_object($vocabulary)) {

          if (strpos($form['#id'], 'views-exposed-form-business-insight-business-insight-page') !== false) {
            $properties = [
              "vid" => 'thematic',
              "langcode" => \Drupal::languageManager()->getCurrentLanguage()->getId()
            ];
          }

          $terms = \Drupal::entityManager()->getStorage('taxonomy_term')->loadByProperties($properties);
          if (is_array($terms)
            && !empty($terms)) {
            $options = array('All' => t($vocabulary->get('name')));
            foreach ($terms AS $term) {
              $term_name = $term->getName();
              $options[$term_name] = $term_name;
            }
            $form[$key]['#type'] = "select";
            $form[$key]['#options'] = $options;
            $form[$key]['#default_value'] = 'All';
            $form[$key]['#validated'] = TRUE;
            $form[$key]['#size'] = null;
          } else {
            unset($form[$key]);
          }
        }


      }
    }
  }



}
