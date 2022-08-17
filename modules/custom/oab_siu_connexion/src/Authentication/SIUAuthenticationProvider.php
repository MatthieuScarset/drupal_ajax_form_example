<?php

namespace Drupal\oab_siu_connexion\Authentication;

use Drupal\Core\Authentication\AuthenticationProviderInterface;
use Drupal\Core\Condition\ConditionManager;
use Drupal\Core\Path\CurrentPathStack;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Session\SessionConfigurationInterface;
use Drupal\Core\Session\UserSession;
use Drupal\Core\Url;
use Drupal\oab_siu_connexion\Services\OabSIUConnexionService;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpFoundation\Request;

class SIUAuthenticationProvider implements AuthenticationProviderInterface {

  /**
   * @param \Drupal\Core\Session\AccountInterface $currentUser
   * @param \Drupal\Core\Path\CurrentPathStack $currentPath
   * @param \Drupal\oab_siu_connexion\Services\OabSIUConnexionService $siuConnexionService
   * @param \Drupal\Core\Session\SessionConfigurationInterface $sessionConfiguration
   */
  public function __construct(protected AccountInterface              $currentUser,
                              protected CurrentPathStack              $currentPath,
                              protected OabSIUConnexionService        $siuConnexionService,
                              protected SessionConfigurationInterface $sessionConfiguration,) {
  }

  /**
   * {@inheritdoc}
   */
  public function applies(Request $request) {

    $hasSession = $request->hasSession() && $this->sessionConfiguration->hasSession($request);

    return $this->siuConnexionService->isCurrentPageAllowed() && !$this->currentUser->isAuthenticated() && !$hasSession;
  }

  /**
   * {@inheritdoc}et
   */
  public function authenticate(Request $request) {
      $idp = $this->siuConnexionService->getIDPConnexion();
      if(!empty($idp)) {
        $url = Url::fromRoute('oab_siu_connexion.login', ['idp' => $idp, 'returnTo' => $request->getRequestUri()]);
        $redirect = new RedirectResponse($url->toString(), 302);
        $redirect->send();
      }
      return NULL;
  }
}
