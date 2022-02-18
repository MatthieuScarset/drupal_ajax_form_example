<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_ob1_adapter\Ob1AdapterService;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RequestStack;

class Ob1RouteNameThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {


  public function __construct(Ob1AdapterService $ob1_adapter_service) {
    parent::__construct($ob1_adapter_service);
  }

  public function applies(RouteMatchInterface $route_match) {
    $routes = $this->ob1AdapterService->get('routes');

    if ($route_match->getRouteName() !== null && is_array($routes)) {
      return in_array($route_match->getRouteName(), $routes);
    }

    return false;
  }
}
