<?php

namespace Drupal\oab_mp_product_formule_packages;

use Drupal\Core\Entity\EntityAccessControlHandler;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

/**
 * Access controller for the Formule package entity.
 *
 * @see \Drupal\oab_mp_product_formule_packages\Entity\FormulePackage.
 */
class FormulePackageAccessControlHandler extends EntityAccessControlHandler {

  /**
   * {@inheritdoc}
   */
  protected function checkAccess(EntityInterface $entity, $operation, AccountInterface $account) {
    /** @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface $entity */

    switch ($operation) {

      case 'view':

        if (!$entity->isPublished()) {
          return AccessResult::allowedIfHasPermission($account, 'view unpublished formule package entities');
        }


        return AccessResult::allowedIfHasPermission($account, 'view published formule package entities');

      case 'update':

        return AccessResult::allowedIfHasPermission($account, 'edit formule package entities');

      case 'delete':

        return AccessResult::allowedIfHasPermission($account, 'delete formule package entities');
    }

    // Unknown operation, no opinion.
    return AccessResult::neutral();
  }

  /**
   * {@inheritdoc}
   */
  protected function checkCreateAccess(AccountInterface $account, array $context, $entity_bundle = NULL) {
    return AccessResult::allowedIfHasPermission($account, 'add formule package entities');
  }


}
