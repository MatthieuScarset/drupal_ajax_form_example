<?php

namespace Drupal\oab_background_image\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;

/**
 * Provides an interface for defining Background image entities.
 *
 * @ingroup oab_background_image
 */
interface BackgroundImageInterface extends ContentEntityInterface, EntityChangedInterface, EntityPublishedInterface {

  /**
   * Add get/set methods for your configuration properties here.
   */

  /**
   * Gets the Background image name.
   *
   * @return string
   *   Name of the Background image.
   */
  public function getName();

  /**
   * Sets the Background image name.
   *
   * @param string $name
   *   The Background image name.
   *
   * @return \Drupal\oab_background_image\Entity\BackgroundImageInterface
   *   The called Background image entity.
   */
  public function setName($name);

  /**
   * Gets the Background image creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Background image.
   */
  public function getCreatedTime();

  /**
   * Sets the Background image creation timestamp.
   *
   * @param int $timestamp
   *   The Background image creation timestamp.
   *
   * @return \Drupal\oab_background_image\Entity\BackgroundImageInterface
   *   The called Background image entity.
   */
  public function setCreatedTime($timestamp);

}
