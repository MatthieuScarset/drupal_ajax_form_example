<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\term;


/**
 *
 * @author LRJV7114
 * @Block(
 *   id = "msscategories_block",
 *   admin_label = @Translation("Categories"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class MssCategoryBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
    public function build() {

      $contents = array();

      $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(['vid' => 'category_mss']);

      foreach ($terms as $term) {
        $contents [$term->tid->value] = $term->name->value;
      }

     $block['#markup'] = $contents;


      return $block;
    }
}
