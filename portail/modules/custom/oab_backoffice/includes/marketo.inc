<?php

use Drupal\taxonomy\Entity\Term;

/**
 * Regroupement de toutes les fonctions spécifiques au formulaire marketo pour ne pas surcharger le fichier .module
 */

/**
 * @param $field
 * @return string|null
 * une fonction qui retourne la liste des terms associé à un seul contenu
 */
function _oab_get_labels_from_term($field) {
  $ret = [];
  $field_values = $field->getValue();
  if (is_array($field_values)) {
    foreach ($field_values as $value) {
      if (isset($value['target_id'])) {
        $term = Term::load($value['target_id']);
        $ret[] = strtolower($term->label());
      }
    }
  }
  return count($ret) ? implode('|', $ret) : null;
}
