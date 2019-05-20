<?php

/**
 * @file
 * Contains \Drupal\form_overwrite\Routing\RouteSubscriber.
 */

namespace Drupal\oab_media_browser\Routing;

use Drupal\Core\Routing\RouteSubscriberBase;
use Symfony\Component\Routing\RouteCollection;

/**
 * Listens to the dynamic route events.
 */
class RouteSubscriber extends RouteSubscriberBase {

  /**
   * {@inheritdoc}
   */
  protected function alterRoutes(RouteCollection $collection) {
      if ($route = $collection->get('entity_embed.dialog')) {
      $route->setDefault('_form', '\Drupal\oab_media_browser\Form\EntityEmbedDialogOab');
    }
  }
}
