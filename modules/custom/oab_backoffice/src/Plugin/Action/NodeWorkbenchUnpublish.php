<?php

namespace Drupal\oab_backoffice\Plugin\Action;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Action\ActionBase;
use Drupal\Core\Session\AccountInterface;

/**
 * Node workbench unpublish.
 *
 * @Action(
 *   id = "oab_backoffice_node_workbench_unpublish",
 *   label = @Translation("Workbench unpublish content"),
 *   type = "node"
 * )
 */
class NodeWorkbenchUnpublish extends ActionBase {

  /**
   * {@inheritdoc}
   */
  public function execute($entity = NULL) {
    $entity->set('moderation_state', array('target_id' => 'unpublished'));
    $entity->save();
  }

  /**
   * {@inheritdoc}
   */
  public function access($object, AccountInterface $account = NULL, $return_as_object = FALSE) {
    $result = $object->access('update', $account, TRUE)
      ->andif(AccessResult::allowedIfHasPermission($account, 'use draft_draft transition'))
      ->andif(AccessResult::allowedIfHasPermission($account, 'use published_draft transition'))
      ->andif(AccessResult::allowedIfHasPermission($account, 'use needs_review_draft transition'));

    return $return_as_object ? $result : $result->isAllowed();
  }

}
