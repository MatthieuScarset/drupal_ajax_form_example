<?php

namespace Drupal\oab_siu_connexion\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Pager\PagerManagerInterface;
use Drupal\Core\Url;
use Drupal\oab_siu_connexion\Entity\SIUProxyUser;
use Drupal\saml_sp\Entity\Idp;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpFoundation\RequestStack;

class SIUController extends ControllerBase
{

  /**
   * @var PagerManagerInterface
   */
  private $pageManager;

  /**
   * @var RequestStack
   */
  private $request;

  /**
   * OabSynomiaSearchEngineController constructor.
   */
  public function __construct() {
    $this->pageManager = \Drupal::service('pager.manager');
    $this->request = \Drupal::service('request_stack');
  }

  /**
   * Initiate a SAML login for the given IdP.
   */
  public function initiate(Idp $idp) {
    $config = $this->config('saml_sp_drupal_login.config');

    //a verifier si l'utilisateur a le rôle siu user
    if ($this->currentUser()->isAuthenticated() && in_array('siu_user', $this->currentUser()->getRoles())) {
      $redirect_path = $this->request->getCurrentRequest()->get('returnTo');
      $url = URL::fromUserInput($redirect_path);
      // the user is already logged in, redirect
      return new RedirectResponse($redirect_path);
    }
    // Start the authentication process; invoke
    $callback = 'oab_siu_connexion__saml_authenticate';
    $forceAuthn = $config->get('force_authentication') ?? FALSE;

    $return = saml_sp_start($idp, $callback, $forceAuthn);
    if (!empty($return)) {
      // Something was returned, echo it to the screen.
      return $return;
    }
  }

}
