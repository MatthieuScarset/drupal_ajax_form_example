<?php

namespace Drupal\oab_tokens\Services;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\node\Entity\Node;
use Drupal\oab_tokens\Entity\NodeToken;

class NodeTokenService {

  /**
   * @var EntityStorageInterface
   */
  private $storage;

  public function __construct(EntityTypeManagerInterface $entity_type_manager) {
    $this->storage = $entity_type_manager->getStorage('node_token');
  }

  public function createNodeToken(Node $node): int {
    $token = NodeToken::create([
      "nid" => $node->id(),
      "vid" => $node->vid->value
    ]);
    return $token->save();
  }

  public function deleteNodeTokenForNode(Node $node) {
    if ($node->id() !== NULL && isset($node->vid->value)) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
        "vid" => $node->vid->value
      ]);
      foreach ($tokens as $token) {
        $token->delete();
      }
    }
  }

  /**
   * Get NodeToken from nid, vid
   *
   * @param int $nid
   * @param int $vid
   * @return null|NodeTokenInterface
   */
  public function getToken(Node $node): mixed {
    if ($node->id() !== null && isset($node->vid->value)) {
      $tokens = $this->storage->loadByProperties([
        "nid" => $node->id(),
        "vid" => $node->vid->value
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
  public function isValidToken($nid, $vid, $token): bool {
    $tokens = $this->storage->loadByProperties([
      'nid' => $nid,
      'vid' => $vid,
      'token' => $token
      ]);
    if (count($tokens) > 0) {
      return true;
    }
    return false;
  }
}
