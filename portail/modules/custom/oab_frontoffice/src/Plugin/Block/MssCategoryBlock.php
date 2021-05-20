<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\node\Entity\Node;


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

    public function build() {

      $contents = array();
      $block = array();
      $cache = array('contexts' => array('url.path'));

      $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(['vid' => 'category_mss']);

      foreach ($terms as $term) {
        $contents [$term->tid->value] = $term->name->value;
      }


      $node = \Drupal::routeMatch()->getParameter('node');
      $nid = $node->nid->value;

      $nodes = Node::load($nid);

       if ($nodes->hasField('field_categories'))
       {
         $categories_id = $nodes->get('field_categories');

         $categories = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($categories_id->target_id);

         $categories_name= $categories->name->value;

         $block ['variable_categories'] = $categories_name;

       }

     $block['#markup'] = $contents;
     $block['#cache'] = $cache;

      return $block;
    }

}
