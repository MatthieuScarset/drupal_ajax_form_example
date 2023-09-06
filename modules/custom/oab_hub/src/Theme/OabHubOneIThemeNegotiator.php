<?php

namespace Drupal\oab_hub\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_hub\Controller\OabHubController;
use Drupal\oab_ob1_adapter\Ob1AdapterService;

class OabHubOneIThemeNegotiator extends OabHubThemeNegotiator implements ThemeNegotiatorInterface {

  public function __construct(private Ob1AdapterService $ob1_adapter_service) {
  }

  public function applies(RouteMatchInterface $route_match) {
    return parent::applies($route_match) && $this->ob1_adapter_service->hasHub(OabHubController::getActifHub());
  }

  public function determineActiveTheme(RouteMatchInterface $route_match) {
    return 'theme_oab_hub_one_i';
  }

}
