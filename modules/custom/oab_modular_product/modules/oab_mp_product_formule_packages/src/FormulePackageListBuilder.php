<?php

namespace Drupal\oab_mp_product_formule_packages;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Link;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackageType;

/**
 * Defines a class to build a listing of Formule package entities.
 *
 * @ingroup oab_mp_product_formule_packages
 */
class FormulePackageListBuilder extends EntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['id'] = $this->t('Formule package ID');
    $header['name'] = $this->t('Name');
    $header['bundle'] = $this->t('Formule Type');
    $header['published'] = $this->t("Published");
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackage $entity */
    $row['id'] = $entity->id();

    $row['name'] = Link::createFromRoute(
      $entity->label(),
      'entity.formule_package.edit_form',
      ['formule_package' => $entity->id()]
    );

    $type = FormulePackageType::load($entity->bundle());
    $row['bundle'] = $type->label();
    $row['published'] = $entity->isPublished() ? $this->t("Published") : $this->t("Not Published");
    return $row + parent::buildRow($entity);
  }

}
