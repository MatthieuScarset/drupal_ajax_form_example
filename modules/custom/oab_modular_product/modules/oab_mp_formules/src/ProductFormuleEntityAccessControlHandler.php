<?php

namespace Drupal\oab_mp_formules;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Product formule entity entity.
 *
 * @see \Drupal\oab_mp_formules\Entity\ProductFormuleEntity.
 */
class ProductFormuleEntityAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface $entity */

    switch ($operation) {
      case 'view':
        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished product formule entity entities');
        }
        return AccessResult::allowedIfHasPermission($account, 'view published product formule entity entities');

      case 'update':
        return AccessResult::allowedIfHasPermission($account, 'edit product formule entity entities');

      case 'delete':
        return AccessResult::allowedIfHasPermission($account, 'delete product formule entity entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add product formule entity entities');
  }


}
