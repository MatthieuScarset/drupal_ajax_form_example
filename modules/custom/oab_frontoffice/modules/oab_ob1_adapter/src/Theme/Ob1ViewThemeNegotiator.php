<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;

class Ob1ViewThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  public function applies(RouteMatchInterface $route_match) {

    $applies = false;

    # Je récupère la vue et le display de la page actuelle
    $current_route = $route_match->getRouteObject();

    if (isset($current_route)) {
      if ($current_route->getDefault('view_id') !== null && $current_route->getDefault('display_id') !== null) {
        $applies = $this->ob1AdapterService->hasView($current_route->getDefault('view_id'), $current_route->getDefault('display_id'));
      }
    }

    return $applies;
  }
}
