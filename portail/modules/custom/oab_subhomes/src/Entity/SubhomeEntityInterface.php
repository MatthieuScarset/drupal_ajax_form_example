<?php

namespace Drupal\oab_subhomes\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining Subhome entity entities.
 *
 * @ingroup oab_subhomes
 */
interface SubhomeEntityInterface extends ContentEntityInterface, EntityChangedInterface {

  // Add get/set methods for your configuration properties here.

  /**
   * Gets the Subhome entity name.
   *
   * @return string
   *   Name of the Subhome entity.
   */
  public function getName();

  /**
   * Sets the Subhome entity name.
   *
   * @param string $name
   *   The Subhome entity name.
   *
   * @return \Drupal\oab_subhomes\Entity\SubhomeEntityInterface
   *   The called Subhome entity entity.
   */
  public function setName($name);

  /**
   * Gets the Subhome entity creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Subhome entity.
   */
  public function getCreatedTime();

  /**
   * Sets the Subhome entity creation timestamp.
   *
   * @param int $timestamp
   *   The Subhome entity creation timestamp.
   *
   * @return \Drupal\oab_subhomes\Entity\SubhomeEntityInterface
   *   The called Subhome entity entity.
   */
  public function setCreatedTime($timestamp);


    /**
     * Get the subhome of the entity
     *
     * @return \Drupal\taxonomy\Entity\term
     */
    public function getSubhome();

    /**
     * Get the ID of the subhome of the entity
     */
    public function getSubhomeId();

    /**
     * Set the ID of the subhome of the entity
     */
    public function setSubhomeId($tid);


    /**
     * {@inheritdoc}
     */
    public function getTitle();

    /**
     * {@inheritdoc}
     */
    public function setTitle($title);

    /**
     * {@inheritdoc}
     */
    public function getDescription();

    /**
     * {@inheritdoc}
     */
    public function setDescription($description);


    /**
     * @param $tid int
     *      the id of the taxo term of the subhome
     * @return \Drupal\taxonomy\Entity\Term[]
     */
    public static function loadBySubhomeId($tid);
}
