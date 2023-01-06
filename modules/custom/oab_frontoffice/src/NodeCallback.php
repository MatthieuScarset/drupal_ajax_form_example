<?php

namespace Drupal\oab_frontoffice;

use Drupal\Core\Render\Markup;
use Drupal\Core\Security\TrustedCallbackInterface;

class NodeCallback implements TrustedCallbackInterface {

  public static function trustedCallbacks() {
    return ['postRender'];
  }

  public static function postRender(Markup $markup, $build) {
    /** @var \Drupal\node\Entity\Node $node */
    $node = $build['#node'];
    \Drupal::service('oab_frontoffice.pdf_generator')
      ->generatePdf($markup, $node->label() . "_postRender");
    return $markup;
  }

}
