<?php

/**
 * @file
 * Contains \Drupal\workbench_access\Plugin\EntityReferenceSelection\TaxonomyHierarchySelection.
 */

namespace Drupal\oab_backoffice\Plugin\EntityReferenceSelection;

use Drupal\Component\Utility\Html;
use Drupal\Core\Database\Query\SelectInterface;
use Drupal\Core\Entity\Plugin\EntityReferenceSelection\DefaultSelection;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\NodeType;
use Drupal\node\Plugin\EntityReferenceSelection\NodeSelection;

/**
 * Provides specific access control for the node entity type.
 *
 * @EntityReferenceSelection(
 *   id = "workbench_access:content_type",
 *   label = @Translation("Restricted Node selection"),
 *   entity_types = {"node"},
 *   group = "workbench_access",
 *   weight = 1
 * )
 */
class NodeHierarchySelection extends NodeSelection {

  /**
   * {@inheritdoc}
   */
  public function getReferenceableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    // Get the base options list from the normal handler. We will filter later.
    if ($match || $limit) {
      $options = parent::getReferenceableEntities($match, $match_operator, $limit);
    }
    else {
      $options = array();

      $bundles = $this->entityManager->getBundleInfo('node');
      $handler_settings = $this->configuration['handler_settings'];
      $bundle_names = !empty($handler_settings['target_bundles']) ? $handler_settings['target_bundles'] : array_keys($bundles);

      foreach ($bundle_names as $bundle) {
        if ($nodetype = NodeType::load($bundle)) {
          $query = \Drupal::entityQuery('node');
          $query->condition('type', $bundle);
          $entity_ids = $query->execute();
          if ($nodes = \Drupal::entityTypeManager()->getStorage('node')->loadMultiple($entity_ids)) {
            foreach ($nodes as $node) {
              $options[$bundle][$node->id()] = str_repeat('-', 1)
                  . Html::escape($this->entityManager->getTranslationFromContext($node->getTitle()));
            }
          }
        }
      }
    }
    // Now, filter the options by permission.
    // If assigned to the top level or a superuser, no alteration.
    $account = \Drupal::currentUser();
    if ($account->hasPermission('bypass workbench access')) {
      return $options;
    }
    // Check each section for access.
    $manager = \Drupal::getContainer()->get('plugin.manager.workbench_access.scheme');
    $user_sections = $manager->getUserSections($account->id());
    foreach ($options as $key => $values) {
      if ($manager->checkTree([$key], $user_sections)) {
        continue;
      }
      else {
        foreach ($values as $id => $value) {
          if (!$manager->checkTree([$id], $user_sections)) {
            unset($options[$key][$id]);
          }
        }
      }
    }
    print_r($options);
    die;
    return $options;
  }

}
