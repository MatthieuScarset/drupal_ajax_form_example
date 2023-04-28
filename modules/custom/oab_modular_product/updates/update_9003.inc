<?php

use Drupal\taxonomy\Entity\Term;
use Drupal\media\Entity\Media;

$file_name_complete = 'modules/custom/oab_modular_product/files/Illustrations_PP_ID_Media.csv';

if (file_exists($file_name_complete) && filesize($file_name_complete) > 0) {

  $fp = fopen($file_name_complete, 'r');

  $header = fgetcsv($fp); // skip première ligne

  while ($row = fgetcsv($fp)) {
    $term_name = $row[0];
    $mid = $row[1];

    $separator = "-";
    $tab = explode($separator, $term_name);

    $category_name = $tab[0];
    $parent_terms = $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
      [
        'vid' => 'product_categories',
        'name' => $category_name
      ]
    );
    /** @var Term $parent_term */
    $parent_term = reset($parent_terms);

    if ($parent_term) {
      $parent_term_id = $parent_term->id();
      $sub_category_name = $tab[1];
      $sub_terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(
        [
          'vid' => 'product_categories',
          'name' => $sub_category_name
        ]
      );

      if (count($sub_terms) > 1) {
        foreach ($sub_terms as $element) {
          if ($element->parent->target_id === $parent_term_id) {
            break;
          }
        }
      } else {
        $element = reset($sub_terms);
      };
      if ($element) {
        $element->set('field_image_illustration', Media::load($mid));
        $element->save();
      }
    }
  }

  fclose($fp);
  unlink($file_name_complete);
}







