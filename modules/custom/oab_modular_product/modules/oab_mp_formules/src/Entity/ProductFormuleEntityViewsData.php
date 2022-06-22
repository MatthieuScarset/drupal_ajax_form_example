<?php

namespace Drupal\oab_mp_formules\Entity;

use Drupal\views\EntityViewsData;

/**
 * Provides Views data for Product formule entity entities.
 */
class ProductFormuleEntityViewsData extends EntityViewsData {

  /**
   * {@inheritdoc}
   */
  public function getViewsData() {
    $data = parent::getViewsData();

    // Additional information for Views integration, such as table joins, can be
    // put here.
    return $data;
  }

}
