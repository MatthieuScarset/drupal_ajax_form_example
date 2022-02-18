<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_ob1_adapter\Ob1AdapterService;
use Drupal\oab_ob1_adapter\Theme\AbstractOb1ThemeNegotiator;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RequestStack;

class Ob1UrlThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  /**
   * @var Request|null
   */
  private $request;

  public function __construct(Ob1AdapterService $ob1_adapter_service, RequestStack $request_stack) {
    parent::__construct($ob1_adapter_service);
    $this->request = $request_stack->getCurrentRequest();
  }

  public function applies(RouteMatchInterface $route_match) {
    $applies = false;

    # Je récupère l'url de la page actuelle
    $url = $this->request->getPathInfo();

//    oabt($this->request->getPathInfo(), true);
    if (isset($url)) {
      $url = str_replace(['/en', '/fr'], '', $url) ?: "/";
      $applies = $this->ob1AdapterService->hasUrl($url);
    }

    return $applies;
  }
}
