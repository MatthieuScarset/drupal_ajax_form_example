<?php

namespace Drupal\oab_styleguide\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Symfony\Component\Routing\Route;

/**
 * Our custom Theme Negotiator.
 */
class OabStyleguideThemeNegotiator implements ThemeNegotiatorInterface {

  /**
   * {@inheritdoc}
   */
  public function applies(RouteMatchInterface $route_match) {
    $route = $route_match->getRouteObject();
    if (!$route instanceof Route) {
      return FALSE;
    }

    return (bool) $route->getOption('_custom_theme');
  }

  /**
   * {@inheritdoc}
   */
  public function determineActiveTheme(RouteMatchInterface $route_match) {
    $theme = $route_match->getParameter('theme');
    if (!empty($theme)) {
      return $theme;
    }

    return $route_match->getRouteObject()->getOption('_custom_theme');
  }

}
