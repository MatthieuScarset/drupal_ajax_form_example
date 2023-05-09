<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\node\NodeInterface;


class Ob1ContentThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  public function applies(RouteMatchInterface $route_match) {

    /** @var NodeInterface $current_node */
    $current_node = $route_match->getParameter('node');

    if ($current_node) {
      return $current_node->type->entity->getThirdPartySetting('oab_modular_product', 'ob1_theme');
    }

    return false;
  }
}
