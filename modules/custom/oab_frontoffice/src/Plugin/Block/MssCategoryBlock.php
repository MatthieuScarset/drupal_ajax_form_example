<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\Cache;
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
    $contents_url = array();
    $block = array();

    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties(['vid' => 'category_mss']);


    foreach ($terms as $term) {
      $contents[] = $term->name->value;
      $contents_url[$term->name->value] = $term->field_category_mss_url->value;
    }

    $node = \Drupal::routeMatch()->getParameter('node');
    $nid = $node->nid->value;

    $nodes = Node::load($nid);

    if ($nodes->hasField('field_categories')) {
      $categories_id = $nodes->get('field_categories');

      $categories = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($categories_id->target_id);

      $categories_name = $categories->name->value;

      $block ['variable_categories'] = $categories_name;


    }

    $block['#markup'] = $contents;
    $block['categories_url'] = $contents_url;

    return $block;
  }

  public function getCacheContexts() {
    return Cache::mergeContexts(parent::getCacheContexts(), ['url.path']);
  }


}
