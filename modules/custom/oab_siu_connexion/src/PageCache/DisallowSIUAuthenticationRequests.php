<?php

namespace Drupal\oab_siu_connexion\PageCache;

use Drupal\Core\PageCache\RequestPolicyInterface;
use Drupal\Core\Path\CurrentPathStack;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Session\SessionConfigurationInterface;
use Drupal\oab_siu_connexion\Services\OabSIUConnexionService;
use Symfony\Component\HttpFoundation\Request;

/**
 * Cache policy for pages served from basic auth.
 *
 * This policy disallows caching of requests that use basic_auth for security
 * reasons. Otherwise responses for authenticated requests can get into the
 * page cache and could be delivered to unprivileged users.
 */
class DisallowSIUAuthenticationRequests implements RequestPolicyInterface {

  /**
   * @param \Drupal\Core\Session\AccountInterface $currentUser
   * @param \Drupal\Core\Path\CurrentPathStack $currentPath
   * @param \Drupal\oab_siu_connexion\Services\OabSIUConnexionService $SIUConnexionService
   * @param \Drupal\Core\Session\SessionConfigurationInterface $sessionConfiguration
   */
  public function __construct(protected AccountInterface              $currentUser,
                              protected CurrentPathStack              $currentPath,
                              protected OabSIUConnexionService        $SIUConnexionService,
                              protected SessionConfigurationInterface $sessionConfiguration) {

  }

  /**
   * {@inheritdoc}
   */
  public function check(Request $request) {
    $hasSession = $request->hasSession() && $this->sessionConfiguration->hasSession($request);
    $restrictedUrls = $this->SIUConnexionService->getSIURestrictedURL();
    if( in_array($this->currentPath?->getPath($request), $restrictedUrls) && !$this->currentUser?->isAuthenticated() && !$hasSession){
      return self::DENY;
    }
  }
}
