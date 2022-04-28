<?php

namespace Drupal\oab_mp_product_formule_packages;

use Drupal\Core\Entity\Sql\SqlContentEntityStorage;
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
class FormulePackageStorage extends SqlContentEntityStorage implements FormulePackageStorageInterface {

  /**
   * {@inheritdoc}
   */
  public function revisionIds(FormulePackageInterface $entity) {
    return $this->database->query(
      'SELECT vid FROM {formule_package_revision} WHERE id=:id ORDER BY vid',
      [':id' => $entity->id()]
    )->fetchCol();
  }

  /**
   * {@inheritdoc}
   */
  public function userRevisionIds(AccountInterface $account) {
    return $this->database->query(
      'SELECT vid FROM {formule_package_field_revision} WHERE uid = :uid ORDER BY vid',
      [':uid' => $account->id()]
    )->fetchCol();
  }

}
