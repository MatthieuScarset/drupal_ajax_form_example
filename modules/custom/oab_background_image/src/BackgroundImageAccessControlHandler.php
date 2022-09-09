<?php

namespace Drupal\oab_background_image;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Background image entity.
 *
 * @see \Drupal\oab_background_image\Entity\BackgroundImage.
 */
class BackgroundImageAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\oab_background_image\Entity\BackgroundImageInterface $entity */

    switch ($operation) {

      case 'view':

        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished background image entities');
        }


        return AccessResult::allowedIfHasPermission($account, 'view published background image entities');

      case 'update':

        return AccessResult::allowedIfHasPermission($account, 'edit background image entities');

      case 'delete':

        return AccessResult::allowedIfHasPermission($account, 'delete background image entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add background image entities');
  }


}
