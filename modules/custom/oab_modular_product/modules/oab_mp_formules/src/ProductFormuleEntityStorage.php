<?php

namespace Drupal\oab_mp_formules;

use Drupal\Core\Entity\Sql\SqlContentEntityStorage;
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
class ProductFormuleEntityStorage extends SqlContentEntityStorage implements ProductFormuleEntityStorageInterface {

  /**
   * {@inheritdoc}
   */
  public function revisionIds(ProductFormuleEntityInterface $entity) {
    return $this->database->query(
      'SELECT vid FROM {product_formule_entity_revision} WHERE id=:id ORDER BY vid',
      [':id' => $entity->id()]
    )->fetchCol();
  }

  /**
   * {@inheritdoc}
   */
  public function userRevisionIds(AccountInterface $account) {
    return $this->database->query(
      'SELECT vid FROM {product_formule_entity_field_revision} WHERE uid = :uid ORDER BY vid',
      [':uid' => $account->id()]
    )->fetchCol();
  }


}
