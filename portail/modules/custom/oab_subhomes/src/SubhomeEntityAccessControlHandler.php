<?php

namespace Drupal\oab_subhomes;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Subhome entity entity.
 *
 * @see \Drupal\oab_subhomes\Entity\SubhomeEntity.
 */
class SubhomeEntityAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\oab_subhomes\Entity\SubhomeEntityInterface $entity */
    switch ($operation) {
      case 'view':
        return AccessResult::allowedIfHasPermission($account, 'view unpublished subhome entity entities');

      case 'update':
        return AccessResult::allowedIfHasPermission($account, 'edit subhome entity entities');

      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete subhome entity entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add subhome entity entities');
  }

}
