<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\node\NodeInterface;


class Ob1ContentThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  public function applies(RouteMatchInterface $route_match) {

    $applies = false;

    /** @var NodeInterface $current_node */
    $current_node = $route_match->getParameter('node');

    if (isset($current_node) && $route_match->getRouteName() === 'entity.node.canonical') {
      if (isset($current_node->field_use_theme_ob1) && $current_node->field_use_theme_ob1->value == 1) {
        $applies = true;
      } else {
        $current_content_type = $current_node->bundle();
      }
    }

    if ($applies !== true) {
      if (isset($current_content_type)) {
        $applies = $this->ob1AdapterService->hasContent($current_content_type);
      }
    }

    return $applies;
  }
}
