<?php

namespace Drupal\oab_mp_product_formule_packages\Entity;

use Drupal\views\EntityViewsData;

/**
 * Provides Views data for Formule package entities.
 */
class FormulePackageViewsData extends EntityViewsData {

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
