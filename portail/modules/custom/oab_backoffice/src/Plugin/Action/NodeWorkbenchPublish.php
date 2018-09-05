<?php

namespace Drupal\oab_backoffice\Plugin\Action;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Action\ActionBase;
use Drupal\Core\Session\AccountInterface;

/**
 * Node workbench publish.
 *
 * @Action(
 *   id = "oab_backoffice_node_workbench_publish",
 *   label = @Translation("Workbench publish content"),
 *   type = "node"
 * )
 */
class NodeWorkbenchPublish extends ActionBase {

  /**
   * {@inheritdoc}
   */
  public function execute($entity = NULL) {
    $entity->set('moderation_state', array('target_id' => 'published'));
    $entity->save();
  }

  /**
   * {@inheritdoc}
   */
  public function access($object, AccountInterface $account = NULL, $return_as_object = FALSE) {
    $result = $object->access('update', $account, TRUE)
        ->andif(AccessResult::allowedIfHasPermission($account, 'use archived_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use draft_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use needs_review_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use published_published transition'));

    return $return_as_object ? $result : $result->isAllowed();
  }

}
