<?php

namespace Drupal\oab_mp_formules;

use Drupal\Core\Entity\ContentEntityStorageInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface;

/**
 * Defines the storage handler class for Product formule entity entities.
 *
 * This extends the base storage class, adding required special handling for
 * Product formule entity entities.
 *
 * @ingroup oab_mp_formules
 */
interface ProductFormuleEntityStorageInterface extends ContentEntityStorageInterface {

  /**
   * Gets a list of Product formule entity revision IDs for a specific Product formule entity.
   *
   * @param \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface $entity
   *   The Product formule entity entity.
   *
   * @return int[]
   *   Product formule entity revision IDs (in ascending order).
   */
  public function revisionIds(ProductFormuleEntityInterface $entity);

  /**
   * Gets a list of revision IDs having a given user as Product formule entity author.
   *
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user entity.
   *
   * @return int[]
   *   Product formule entity revision IDs (in ascending order).
   */
  public function userRevisionIds(AccountInterface $account);

}
