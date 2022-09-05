<?php

namespace Drupal\oab_custom_assets\Entity;

use Drupal\Core\Config\Entity\ConfigEntityInterface;

/**
 * Provides an interface for defining Custom asset entities.
 */
interface CustomAssetInterface extends ConfigEntityInterface {

  // Add get/set methods for your configuration properties here.

  public function getPaths(): ?string;
  public function getPathsAsArray(): array;
  public function getCSS(): ?string;
  public function getJs(): ?string;
  public function getBottomJs(): ?string;

}
