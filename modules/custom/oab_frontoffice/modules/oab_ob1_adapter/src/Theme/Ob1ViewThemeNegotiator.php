<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\views\Entity\View;

class Ob1ViewThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  public function applies(RouteMatchInterface $route_match) {

    # Je récupère la vue et le display de la page actuelle
    $current_route = $route_match->getRouteObject();

    if (isset($current_route)) {

      if ($current_route->getDefault('view_id') !== null && $current_route->getDefault('display_id') !== null) {

        /** @var View $view */
        $view = View::load($current_route->getDefault('view_id'));
        $display = $view->getDisplay($current_route->getDefault('display_id'));

        if (!isset($display['display_options']['display_extenders']['theme_settings'])) {
          return false;
        }

        $ob1_settings_values = $display['display_options']['display_extenders']['theme_settings']['ob1_settings'];

        if (isset($ob1_settings_values)) {
          return  $ob1_settings_values['ob1'];
        }
      }
    }

  }
}
