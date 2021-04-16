<?php

/**
 * @file
 * Contains \Drupal\workbench_access\Plugin\AccessControlHierarchy\Taxonomy.
 */

namespace Drupal\oab_backoffice\Plugin\AccessControlHierarchy;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Entity\ContentEntityType;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\node\Entity\NodeType;
use Drupal\workbench_access\AccessControlHierarchyBase;
use Drupal\workbench_access\UserSectionStorageInterface;
use Drupal\workbench_access\WorkbenchAccessManagerInterface;
use Drupal\node\Entity\Node;

/**
 * Defines a hierarchy based on a Content Types.
 *
 * @AccessControlHierarchy(
 *   id = "content_type",
 *   module = "node",
 *   base_entity = "node_type",
 *   entity = "node",
 *   label = @Translation("Content Type"),
 *   description = @Translation("Uses a content type as an access control hierarchy.")
 * )
 */
class ContentType extends AccessControlHierarchyBase {

  /**
   * The access tree array.
   *
   * @var array
   */
  public $tree;

  /**
   * @var EntityStorageInterface
   */
  private $storage;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, UserSectionStorageInterface $user_section_storage, ConfigFactoryInterface $configFactory,
                              EntityTypeManagerInterface $entityTypeManager) {
    parent::__construct($configuration, $plugin_id, $plugin_definition,$user_section_storage, $configFactory,$entityTypeManager);
    $this->storage = $this->entityTypeManager->getStorage('field_config');
  }

  /**
   * @inheritdoc
   */
  public function getTree() {
    if (!isset($this->tree)) {
      $config = $this->config('workbench_access.settings');
      $parents = $config->get('parents');
      $tree = array();
      foreach ($parents as $id => $label) {
        if ($nodetype = NodeType::load($id)) {
          $tree[$id][$id] = array(
            'label' => $nodetype->label(),
            'depth' => 0,
            'parents' => [],
            'weight' => 0,
            'description' => $nodetype->label(),
          );

          $query = \Drupal::entityQuery('node');
          $query->condition('type', $id);
          $entity_ids = $query->execute();
          $data = \Drupal::entityTypeManager()->getStorage('node')->loadMultiple($entity_ids);
          $this->tree = $this->buildTree($id, $data, $tree);
        }
      }
    }

    return $this->tree;
  }

  /**
   * Traverses the taxonomy tree and builds parentage arrays.
   *
   * Note: this method is necessary to load all parents to the array.
   *
   * @param $id
   *   The root id of the section tree.
   * @param array $data
   *   An array of menu tree or subtree data.
   * @param array &$tree
   *   The computed tree array to return.
   *
   * @return array $tree
   *   The compiled tree data.
   */
  public function buildTree($id, $data, &$tree) {
    foreach ($data as $node) {
      $tree[$id][$node->id()] = array(
        'id' => $node->id(),
        'label' => $node->getTitle(),
        'parents' => array($id),
        'depth' => 1,
        'weight' => 0,
      );
    }
    return $tree;
  }

  /**
   * @inheritdoc
   */
  public function getFields($entity_type, $bundle, $parents) {
    $list = [];
    $query = \Drupal::entityQuery('field_config')
      ->condition('status', 1)
      ->condition('entity_type', $entity_type)
      ->condition('bundle', $bundle)
      ->condition('field_type', 'entity_reference')
      ->sort('label')
      ->execute();
    $fields = $this->storage->loadMultiple(array_keys($query));
    foreach ($fields as $id => $field) {
      $handler = $field->getSetting('handler');
      $settings = $field->getSetting('handler_settings');
      if (substr_count($handler, 'taxonomy_term') > 0) {
        foreach ($settings['target_bundles'] as $key => $target) {
          if (isset($parents[$key])) {
            $list[$field->getName()] = $field->label();
          }
        }
      }
    }
    return $list;
  }

  /**
   * {@inheritdoc}
   */
  public function alterOptions($field, WorkbenchAccessManagerInterface $manager) {
    $element = $field;
    if (isset($element['widget']['#options'])) {
      $user_sections = $manager->getUserSections();
      foreach ($element['widget']['#options'] as $id => $data) {
        $sections = [$id];
        if (empty($manager->checkTree($sections, $user_sections))) {
          unset($element['widget']['#options'][$id]);
        }
      }
    }
    // Check for autocomplete fields. In this case, we replace the selection
    // handler with our own, which likely breaks Views-based handlers, but that
    // can be handled later. We swap out the default handler for our own, since
    // we don't have another way to filter the autocomplete results.
    // @TODO: test this against views-based handlers.
    // @see \Drupal\workbench_access\Plugin\EntityReferenceSelection\TaxonomyHierarchySelection
    else {
      foreach ($element['widget'] as $key => $item) {
        if (is_array($item) && isset($item['target_id']['#type']) && $item['target_id']['#type'] == 'entity_autocomplete') {
          $element['widget'][$key]['target_id']['#selection_handler'] = 'workbench_access:content_type';
        }
      }
    }

    return $element;
  }

}
