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
   * The current user.
   *
   * @var \Drupal\Core\Session\AccountInterface
   */
  protected $currentUser;

  /**
   * The current path.
   *
   * @var \Drupal\Core\Path\CurrentPathStack
   */
  protected $currentPath;


  /**
   * The session configuration.
   *
   * @var \Drupal\Core\Session\SessionConfigurationInterface
   */
  protected $sessionConfiguration;

  /**
   * Constructs a new SIUAuthenticationProvider instance.
   *
   * @param \Drupal\Core\Session\AccountInterface $current_user
   *   The current user.
   * @param \Drupal\Core\Path\CurrentPathStack $current_path
   *   The current path.
   */
  public function __construct(AccountInterface $current_user, CurrentPathStack $current_path, OabSIUConnexionService $SIUConnexionService, SessionConfigurationInterface $session_configuration) {
    $this->currentUser = $current_user;
    $this->currentPath = $current_path;
    $this->SIUConnexionService = $SIUConnexionService;
    $this->sessionConfiguration = $session_configuration;

  }

  /**
   * {@inheritdoc}
   */
  public function applies(Request $request) {
    //on récupère les URL protégées par SIU (conf)
    $hasSession = $request->hasSession() && $this->sessionConfiguration->hasSession($request);

    \Drupal::logger('oab_siu_connexion')->notice('SIUAuthenticationProvider -> applies , hasSession : %hassession ', ['%hassession' => $hasSession]);
    $restrictedUrls = $this->SIUConnexionService->getSIURestrictedURL();
    if( in_array($this->currentPath->getPath(), $restrictedUrls) && !$this->currentUser->isAuthenticated() && !$hasSession){
      \Drupal::logger('oab_siu_connexion')->notice('SIUAuthenticationProvider -> applies TRUE');
      return TRUE;
    }
    \Drupal::logger('oab_siu_connexion')->notice('SIUAuthenticationProvider -> applies FALSE');
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
