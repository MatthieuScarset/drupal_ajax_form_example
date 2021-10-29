<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_ob1_adapter\Ob1AdapterService;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RequestStack;

Abstract class AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  /**
   * @var Ob1AdapterService
   */
  protected $ob1AdapterService;

  public function __construct(Ob1AdapterService $ob1_adapter_service) {
    $this->ob1AdapterService = $ob1_adapter_service;
  }

  public function determineActiveTheme(RouteMatchInterface $route_match) {
    return 'theme_one_i';
  }

  abstract public function applies(RouteMatchInterface $route_match);
}
