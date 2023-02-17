<?php

namespace Drupal\oab_hub;

use Drupal\Core\Url;
use Drupal\oab_hub\Controller\OabHubController;

trait HubFrontUrlTrait {


  protected function getHubFrontUrl(): Url {
    $hub = OabHubController::getHubBaseUrl();

    if ($hub !== false) {
      return URL::fromUserInput($hub);
    }

    return URL::fromRoute('<front>');
  }
}
