<?php

namespace Drupal\oab_custom_assets;

use Drupal\Core\Config\Entity\ConfigEntityListBuilder;
use Drupal\Core\Entity\EntityInterface;

/**
 * Provides a listing of Custom asset entities.
 */
class CustomAssetListBuilder extends ConfigEntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader(): array {
    $header['id'] = $this->t('Machine name');
    $header['label'] = $this->t('Custom asset');
    $header['paths'] = $this->t('Paths');
    $header['languages'] = $this->t('Languages');
    $header['has_css'] = $this->t('Has CSS');
    $header['has_js'] = $this->t('Has JS');
    $header['has_bottom_js'] = $this->t('Has bottom JS');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity): array {
    $row['id'] = $entity->id();
    $row['label'] = $entity->label();

    $row['paths'] = $entity->getPaths() ?? $this->t("No path configured");

    $langs = $entity->getLanguages();
    $row['languages'] = !empty($langs) ? implode(", ", $langs) : $this->t("All");

    $row['has_css'] = $entity->getCss() ? $this->t("Yes") : $this->t('No');
    $row['has_js'] = $entity->getJs() ? $this->t("Yes") : $this->t('No');
    $row['has_bottom_js'] = $entity->getBottomJs() ? $this->t("Yes") : $this->t('No');

    // You probably want a few more properties here...
    return $row + parent::buildRow($entity);
  }

}
