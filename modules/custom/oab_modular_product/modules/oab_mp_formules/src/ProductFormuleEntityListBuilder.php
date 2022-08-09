<?php

namespace Drupal\oab_mp_formules;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Link;

/**
 * Defines a class to build a listing of Product formule entity entities.
 *
 * @ingroup oab_mp_formules
 */
class ProductFormuleEntityListBuilder extends EntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['id'] = $this->t('Product formule entity ID');
    $header['name'] = $this->t('Name');
    $header['language'] = $this->t('Language');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var \Drupal\oab_mp_formules\Entity\ProductFormuleEntity $entity */
    $row['id'] = $entity->id();
    $row['name'] = Link::createFromRoute(
      $entity->label(),
      'entity.product_formule_entity.edit_form',
      ['product_formule_entity' => $entity->id()]
    );
    $row['language'] = $entity->language()->getName();
    return $row + parent::buildRow($entity);
  }

}
