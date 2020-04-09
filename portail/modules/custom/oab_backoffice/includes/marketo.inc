<?php

use Drupal\taxonomy\Entity\Term;

/**
 * Regroupement de toutes les fonctions spécifiques au formulaire marketo pour ne pas surcharger le fichier .module
 */

function marketo_get_taxo_term_document_thematic($node) {

  if ($node->bundle() == 'document') {
    //taxo : Documents thematics / mkt_theme
    $tid_document_thematic = $node->get('field_document_thematic')->target_id;
    if ($tid_document_thematic != null) {
      $term = Term::load($tid_document_thematic);
      return $term->getName();
    }
  }
}


function marketo_get_taxo_term_subhome($node) {

  if ($node->bundle() == 'document') {
    //taxo : Subhome / mktoPdfRubrique
    $tid_subhome = $node->get('field_subhome')->target_id;
    if ($tid_subhome != null) {
      $term = Term::load($tid_subhome);
      return $term->getName();
    }
  }
}


function marketo_get_taxo_term_solutions($node) {

  if($node->bundle() == 'document') {
    //taxo : Solutions / mktoPdfSolution
    $tid_solutions = $node->get('field_solution')->target_id;
    if ($tid_solutions != null) {
      $term = Term::load($tid_solutions);
      return $term->getName();
    }
  }
}


function marketo_get_taxo_term_document_type($node) {

  if ($node->bundle() == 'document') {
    //taxo : Documents type/ mktoPdfType
    $tid_document_type = $node->get('field_document_type')->target_id;
    if ($tid_document_type != null) {
      $term = Term::load($tid_document_type);
      return $term->getName();
    }
  }
}


function marketo_get_taxo_term_job_profile($node) {

  if ($node->bundle() == 'document') {
    //taxo : Profession / mktoPdfJobroles
    $tid_job_profile = $node->get('field_job_profile')->target_id;
    if ($tid_job_profile != null) {
      $term = Term::load($tid_job_profile);
      return $term->getName();
    }
  }
}


function marketo_get_taxo_term_industry($node) {

  if ($node->bundle() == 'document') {
    //taxo : Industry / mktoPdfIndustrie
    $tid_industry = $node->get('field_industry')->target_id;
    if ($tid_industry != null) {
      $term = Term::load($tid_industry);
      return $term->getName();
    }
  }
}
