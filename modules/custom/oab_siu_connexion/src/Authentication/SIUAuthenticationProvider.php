<?php

namespace Drupal\oab_siu_connexion\Authentication;

use Drupal\Core\Authentication\AuthenticationProviderInterface;
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
   * @param \Drupal\oab_siu_connexion\Services\OabSIUConnexionService $SIUConnexionService
   * @param \Drupal\Core\Session\SessionConfigurationInterface $sessionConfiguration
   */
  public function __construct(protected AccountInterface $currentUser,
                              protected CurrentPathStack $currentPath,
                              protected OabSIUConnexionService $SIUConnexionService,
                              protected SessionConfigurationInterface $sessionConfiguration) {
    /*$this->currentUser = $current_user;
    $this->currentPath = $current_path;
    $thi $SIUConnexionService = $siu_connexion_service;
    $this->sessionConfiguration = $session_configuration;
*/
  }

  /**
   * {@inheritdoc}
   */
  public function applies(Request $request) {
    //on récupère les URL protégées par SIU (conf)
    $hasSession = $request->hasSession() && $this->sessionConfiguration->hasSession($request);
    $restrictedUrls = $this->SIUConnexionService->getSIURestrictedURL();
    if( in_array($this->currentPath->getPath($request), $restrictedUrls) && !$this->currentUser->isAuthenticated() && !$hasSession){
      return TRUE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}et
   */
  public function authenticate(Request $request) {
      $idp = $this->SIUConnexionService->getIDPConnexion();
      if(!empty($idp)) {
        $url = Url::fromRoute('oab_siu_connexion.login', ['idp' => $idp, 'returnTo' => $request->getRequestUri()]);
        $redirect = new RedirectResponse($url->toString(), 302);
        $redirect->send();
      }
      return NULL;
  }
}
