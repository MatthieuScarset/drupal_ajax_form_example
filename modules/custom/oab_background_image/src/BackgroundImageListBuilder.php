<?php

namespace Drupal\oab_background_image;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Link;

/**
 * Defines a class to build a listing of Background image entities.
 *
 * @ingroup oab_background_image
 */
class BackgroundImageListBuilder extends EntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['id'] = $this->t('Background image ID');
    $header['name'] = $this->t('Name');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    /* @var \Drupal\oab_background_image\Entity\BackgroundImage $entity */
    $row['id'] = $entity->id();
    $row['name'] = Link::createFromRoute(
      $entity->label(),
      'entity.background_image.edit_form',
      ['background_image' => $entity->id()]
    );
    return $row + parent::buildRow($entity);
  }

}
