<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\Cache;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;
use Symfony\Component\DependencyInjection\ContainerInterface;


/**
 *
 * @author LRJV7114
 * @Block(
 *   id = "msscategories_block",
 *   admin_label = @Translation("MSS Categories"),
 *   category = @Translation("Blocks"),
 *   context_definitions = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */
class MssCategoryBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  private $entityTypeManager;


  public function __construct(array $configuration, $plugin_id, $plugin_definition,
                              EntityTypeManagerInterface $entity_type_manager) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->entityTypeManager = $entity_type_manager;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new self(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('entity_type.manager')
    );
  }

  public function build() {

    $contents = array();
    $contents_url = array();
    $block = array();

    /** @var Term[] $terms */
    $terms = $this->entityTypeManager
      ->getStorage('taxonomy_term')
      ->loadByProperties(['vid' => 'category_mss']);


    foreach ($terms as $term) {
      $contents[] = $term->label();
      $contents_url[$term->label()] = $term->field_category_mss_url->value;
    }

    $node = $this->getContextValue('node');

    if ($node instanceof Node && $node->hasField('field_categories')) {
      $category = Term::load($node->field_categories->target_id ?? 0);
      if ($category) {
        $block['variable_categories'] = $category->label();
      }
    }

    $block['#markup'] = $contents;
    $block['categories_url'] = $contents_url;

    return $block;
  }

  public function getCacheContexts() {
    return Cache::mergeContexts(parent::getCacheContexts(), ['url.path']);
  }

}
