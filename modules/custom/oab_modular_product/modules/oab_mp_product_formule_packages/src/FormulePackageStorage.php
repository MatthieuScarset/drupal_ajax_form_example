<?php

namespace Drupal\oab_mp_product_formule_packages;

use Drupal\Core\Database\Query\SelectInterface;
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

  /**
   * Array au format [target => value];
   * @param array $values
   * @param string|null $bundle
   */
  public function getBaseQuery(array $values, string $bundle = null): SelectInterface {
    $query = $this->database->select($this->dataTable ?? $this->baseTable, 'e')
      ->fields('e', ['id'])
      ->condition('status', 1);

    if ($bundle !== null) {
      $query->condition('e.type',$bundle);
    }

    $i = 0;
    foreach ($values as $target => $value) {
      $alias = "fv_$i";
      $query->leftJoin(
        $this->baseTable . "__formule_values",
        $alias,
        "$alias.entity_id = e.id"
      );

      $query->condition("$alias.formule_values_formule_field_target", $target);
      $query->condition("$alias.formule_values_value", $value);
      $i++;
    }

    return $query;
  }

  /**
   * Array au format [target => value];
   * @param array $values
   * @param string|null $bundle
   */
  public function getFromFieldValue(array $values, string $bundle = null): array {
    return $this->getBaseQuery($values, $bundle)->execute()->fetchAllAssoc('id');
  }

}
