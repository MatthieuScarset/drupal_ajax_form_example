<?php

namespace Drupal\oab_mp_product_formule_packages\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;

/**
 * Provides an interface for defining Formule package entities.
 *
 * @ingroup oab_mp_product_formule_packages
 */
interface FormulePackageInterface extends ContentEntityInterface, RevisionLogInterface, EntityChangedInterface, EntityPublishedInterface {

  /**
   * Add get/set methods for your configuration properties here.
   */

  /**
   * Gets the Formule package name.
   *
   * @return string
   *   Name of the Formule package.
   */
  public function getName();

  /**
   * Sets the Formule package name.
   *
   * @param string $name
   *   The Formule package name.
   *
   * @return \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface
   *   The called Formule package entity.
   */
  public function setName($name);

  /**
   * Gets the Formule package creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Formule package.
   */
  public function getCreatedTime();

  /**
   * Sets the Formule package creation timestamp.
   *
   * @param int $timestamp
   *   The Formule package creation timestamp.
   *
   * @return \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface
   *   The called Formule package entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Gets the Formule package revision creation timestamp.
   *
   * @return int
   *   The UNIX timestamp of when this revision was created.
   */
  public function getRevisionCreationTime();

  /**
   * Sets the Formule package revision creation timestamp.
   *
   * @param int $timestamp
   *   The UNIX timestamp of when this revision was created.
   *
   * @return \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface
   *   The called Formule package entity.
   */
  public function setRevisionCreationTime($timestamp);

  /**
   * Gets the Formule package revision author.
   *
   * @return \Drupal\user\UserInterface
   *   The user entity for the revision author.
   */
  public function getRevisionUser();

  /**
   * Sets the Formule package revision author.
   *
   * @param int $uid
   *   The user ID of the revision author.
   *
   * @return \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface
   *   The called Formule package entity.
   */
  public function setRevisionUserId($uid);

}
