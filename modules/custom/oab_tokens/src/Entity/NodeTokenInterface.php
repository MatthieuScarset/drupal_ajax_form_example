<?php

namespace Drupal\oab_tokens\Entity;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityPublishedInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining Playlist entities.
 *
 * @ingroup oab_tokens
 */
interface NodeTokenInterface extends ContentEntityInterface {
  /**
   * @return string
   */
  public function getToken(): string;
}

