<?php

namespace Drupal\oab_tokens\Services;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\node\Entity\Node;
use Drupal\oab_tokens\Entity\NodeToken;
use Drupal\oab_tokens\Entity\NodeTokenInterface;

class NodeTokenService {

  /**
   * @var EntityStorageInterface
   */
  private $storage;

  /**
   */
  public function __construct(EntityTypeManagerInterface $entity_type_manager) {
    $this->storage = $entity_type_manager->getStorage('node_token');
  }

  /** Crée un NodeToken pour ce Node (nid+vid)
   * @param \Drupal\node\Entity\Node $node
   *
   * @return int
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function createNodeToken(Node $node): int {
    $token = NodeToken::create([
      "nid" => $node->id(),
      "vid" => $node->getRevisionId(),
    ]);
    return $token->save();
  }

  /** Supprime un NodeToken pour ce Node (nid, vid)
   * @param \Drupal\node\Entity\Node $node
   *
   * @return void
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function deleteNodeTokenForNode(Node $node) {
    if ($node->id() !== NULL && $node->getRevisionId() !== NULL) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
        "vid" => $node->getRevisionId(),
      ]);
      foreach ($tokens as $token) {
        $token->delete();
      }
    }
  }

  /** Supprime tous les NodeToken pour ce Node (nid)
   * @param \Drupal\node\Entity\Node $node
   *
   * @return void
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function deleteAllNodeTokenForNode(Node $node) {
    if ($node->id() !== NULL) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
      ]);
      foreach ($tokens as $token) {
        $token->delete();
      }
    }
  }

  /** Met a jour le NodeToken ayant cet nid avec le vid du node passé en paramètre
   * @param \Drupal\node\Entity\Node $node
   *
   * @return void
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function updateRevisionForNodeToken(Node $node) {
    if ($node->id() !== NULL && $node->getRevisionId() !== NULL) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
      ]);
      /** @var NodeToken $token */
      foreach ($tokens as $token) {
        $token->set('vid', $node->getRevisionId());
        $token->save();
      }
    }
  }

  /**
   * Get NodeToken from nid, vid
   *
   * @param \Drupal\node\Entity\Node $node
   * @return null|NodeTokenInterface
   */
  public function getToken(Node $node): ?NodeTokenInterface {
    if ($node->id() !== null && $node->getRevisionId() !== NULL) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
        "vid" => $node->getRevisionId(),
      ]);
      if (count($tokens) > 0) {
        return array_shift($tokens);
      }
    }
    return null;
  }
  /**
   * Check if the token is correct
   *
   * @param int $nid
   * @param int $vid
   * @param string $token
   * @return boolean
   */
  public function isValidToken(int $nid, int $vid, string $token): bool {
    $tokens = $this->storage->loadByProperties([
      'nid' => $nid,
      'vid' => $vid,
      'token' => $token,
      ]);
    if (count($tokens) > 0) {
      return true;
    }
    return false;
  }
}
