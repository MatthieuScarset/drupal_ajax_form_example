<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\node\Entity\NodeType;
use Drupal\node\NodeInterface;
use Drupal\node\NodeTypeInterface;


class Ob1ContentThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  public function applies(RouteMatchInterface $route_match) {

    /** @var NodeInterface $current_node */
    $current_node = $route_match->getParameter('node');

    if ($current_node) {
      /** @var NodeTypeInterface $node_type */
      $node_type = NodeType::load($current_node->bundle());
      $ob1 = $node_type->getThirdPartySetting('oab_modular_product', 'ob1_theme');

      if ($ob1 === 1) {
        return true;
      }
    }

//    // Toutes les routes ou le thème doit s'appliquer
//    // ie. le front, mais aussi les pages de prévi et revisions
//    $routes_to_apply = [
//      'entity.node.latest_version',
//      'entity.node.canonical',
//      'entity.node.revision'
//    ];
//
//    if (isset($current_node) && in_array($route_match->getRouteName(), $routes_to_apply)) {
//        return
//          (isset($current_node->field_use_theme_ob1) && $current_node->field_use_theme_ob1->value == 1)
//          || $this->ob1AdapterService->hasContent($current_node->bundle());
//    }
//
    return false;
  }
}
