<?php


namespace Drupal\oab_marketo;


use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\oab_marketo\Entity\AltaresToken;
use Drupal\oab_marketo\Entity\AltaresTokenInterface;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;

/**
 *
 * Provide a service to manager Altares Token
 *
 * Class AltaresTokenService
 * @package Drupal\oab_marketo
 */
class AltaresTokenService {

  /**
   * @var EntityStorageInterface
   */
  private $storage;

  /** @var ImmutableConfig */
  private $altaresConfig;

  public function __construct(EntityTypeManagerInterface $entity_type_manager, ImmutableConfig $altares_config) {
    $this->storage = $entity_type_manager->getStorage('altares_token');
    $this->altaresConfig = $altares_config;
  }

  /**
   * Check if token is valid
   * Can be either the string token or the AltaresToken object
   *
   * @param string|AltaresTokenInterface $token
   * @return bool
   */
  public function isValid($token): bool {
    if (is_string($token)) {
      $token = $this->getToken($token);
    }

    if (null !== $token && is_a($token, AltaresTokenInterface::class)) {
      return $token->isValid();
    }

    return false;
  }

  /**
   * Get AltaresToken from string token
   *
   * @param string $token
   * @return null|AltaresTokenInterface
   */
  public function getToken(string $token) {
    $tokens = $this->storage->loadByProperties(['token' => $token]);
    if (count($tokens) > 0) {
      return array_shift($tokens);
    }

    return null;
  }

  /**
   * Create new AltaresToken
   *
   * @return \Drupal\Core\Entity\EntityInterface|AltaresToken
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function createToken() {
    $token = AltaresToken::create();
    $token->save();

    return $token;
  }


  public function getMaxRequest(): int {
    return $this->altaresConfig->get(OabAltaresSettingsForm::NB_MAX_REQUEST) ?: 50;
  }

}

