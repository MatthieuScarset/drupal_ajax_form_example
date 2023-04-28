<?php

use Drupal\taxonomy\Entity\Term;
use Drupal\media\Entity\Media;

$file_name_complete = 'modules/custom/oab_modular_product/files/Illustrations_PP_ID_Media.csv';

if (file_exists($file_name_complete) && filesize($file_name_complete) > 0) {

  $fp = fopen($file_name_complete, 'r');

  $header = fgetcsv($fp); // skip première ligne

  while ($row = fgetcsv($fp)) {
    $category_fr = $row[1];
    $sub_category_fr = $row[2];
    $category_en = $row[3];
    $sub_category_en = $row[4];
    $mid = $row[5];

    //update for frensh sub category
    $parent_terms_fr = $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
      [
        'vid' => 'product_categories',
        'name' => $category_fr
      ]
    );
    /** @var Term $parent_term_fr */
    $parent_term_fr = reset($parent_terms_fr);

    if ($parent_term_fr) {
      $parent_term_id = $parent_term_fr->id();
      $sub_terms_fr = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
        [
          'vid' => 'product_categories',
          'name' => $sub_category_fr
        ]
      );

      if (count($sub_terms_fr) > 1) {
        foreach ($sub_terms_fr as $element) {
          if ($element->parent->target_id === $parent_term_id) {
            break;
          }
        }
      } else {
        $element = reset($sub_terms_fr);
      };
      if ($element) {
        $element->set('field_image_illustration', Media::load($mid));
        $element->save();
      }
    }

    //update for english sub category
    $parent_terms_en = $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
      [
        'vid' => 'product_categories',
        'name' => $category_en
      ]
    );
    /** @var Term $parent_term_en */
    $parent_term_en = reset($parent_terms_en);

    if ($parent_term_en) {
      $parent_term_id = $parent_term_en->id();
      $sub_terms_en = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
        [
          'vid' => 'product_categories',
          'name' => $sub_category_en
        ]
      );

      if (count($sub_terms_en) > 1) {
        foreach ($sub_terms_en as $element) {
          if ($element->parent->target_id === $parent_term_id) {
            break;
          }
        }
      } else {
        $element = reset($sub_terms_en);
      };
      if ($element) {
        $element->set('field_image_illustration', Media::load($mid));
        $element->save();
      }
    }
  }

  fclose($fp);
  //unlink($file_name_complete);
}







