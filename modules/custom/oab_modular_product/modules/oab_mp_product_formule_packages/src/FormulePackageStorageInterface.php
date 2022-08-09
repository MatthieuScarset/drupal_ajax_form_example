<?php

namespace Drupal\oab_mp_product_formule_packages;

use Drupal\Core\Entity\ContentEntityStorageInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface;

/**
 * Defines the storage handler class for Formule package entities.
 *
 * This extends the base storage class, adding required special handling for
 * Formule package entities.
 *
 * @ingroup oab_mp_product_formule_packages
 */
interface FormulePackageStorageInterface extends ContentEntityStorageInterface {

  /**
   * Gets a list of Formule package revision IDs for a specific Formule package.
   *
   * @param \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface $entity
   *   The Formule package entity.
   *
   * @return int[]
   *   Formule package revision IDs (in ascending order).
   */
  public function revisionIds(FormulePackageInterface $entity);

  /**
   * Gets a list of revision IDs having a given user as Formule package author.
   *
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user entity.
   *
   * @return int[]
   *   Formule package revision IDs (in ascending order).
   */
  public function userRevisionIds(AccountInterface $account);

}
