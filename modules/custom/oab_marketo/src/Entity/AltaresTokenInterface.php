<?php

namespace Drupal\oab_marketo\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining Playlist entities.
 *
 * @ingroup oab_marketo
 */
interface AltaresTokenInterface extends ContentEntityInterface {


  /**
   * @return string
   */
  public function getToken(): string;

  /**
   * @return int
   */
  public function getExpires(): int;

  /**
   * @return boolean
   */
  public function isValid(): bool;

  /**
   * @return int
   */
  public function getCount(): int;

  /**
   * Increment count and return the current count
   * @return void
   */
  public function incrementCount(): int;
}

