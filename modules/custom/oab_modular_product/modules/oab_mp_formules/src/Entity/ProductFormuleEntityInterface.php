<?php

namespace Drupal\oab_mp_formules\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;

/**
 * Provides an interface for defining Product formule entity entities.
 *
 * @ingroup oab_mp_formules
 */
interface ProductFormuleEntityInterface extends ContentEntityInterface, RevisionLogInterface, EntityChangedInterface, EntityPublishedInterface {

  /**
   * Add get/set methods for your configuration properties here.
   */

  /**
   * Gets the Product formule entity name.
   *
   * @return string
   *   Name of the Product formule entity.
   */
  public function getName();

  /**
   * Sets the Product formule entity name.
   *
   * @param string $name
   *   The Product formule entity name.
   *
   * @return \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface
   *   The called Product formule entity entity.
   */
  public function setName($name);

  /**
   * Gets the Product formule entity creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Product formule entity.
   */
  public function getCreatedTime();

  /**
   * Sets the Product formule entity creation timestamp.
   *
   * @param int $timestamp
   *   The Product formule entity creation timestamp.
   *
   * @return \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface
   *   The called Product formule entity entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Gets the Product formule entity revision creation timestamp.
   *
   * @return int
   *   The UNIX timestamp of when this revision was created.
   */
  public function getRevisionCreationTime();

  /**
   * Sets the Product formule entity revision creation timestamp.
   *
   * @param int $timestamp
   *   The UNIX timestamp of when this revision was created.
   *
   * @return \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface
   *   The called Product formule entity entity.
   */
  public function setRevisionCreationTime($timestamp);

  /**
   * Gets the Product formule entity revision author.
   *
   * @return \Drupal\user\UserInterface
   *   The user entity for the revision author.
   */
  public function getRevisionUser();

  /**
   * Sets the Product formule entity revision author.
   *
   * @param int $uid
   *   The user ID of the revision author.
   *
   * @return \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface
   *   The called Product formule entity entity.
   */
  public function setRevisionUserId($uid);

}
