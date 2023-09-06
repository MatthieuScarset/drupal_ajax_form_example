<?php

namespace Drupal\oab_ob1_adapter\Theme;

use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_ob1_adapter\Ob1AdapterService;
use Drupal\views\Entity\View;

class Ob1ViewThemeNegotiator extends AbstractOb1ThemeNegotiator implements ThemeNegotiatorInterface {

  /**
   * @var \Drupal\Core\Language\LanguageManagerInterface
   */
  private LanguageManagerInterface $languageManager;

  public function __construct(Ob1AdapterService $ob1_adapter_service, LanguageManagerInterface $language_manager) {
    parent::__construct($ob1_adapter_service);
    $this->languageManager = $language_manager;
  }

  public function applies(RouteMatchInterface $route_match) {

    # Je récupère la vue et le display de la page actuelle
    $current_route = $route_match->getRouteObject();

    if (isset($current_route)
        && $current_route->hasDefault('view_id')
        && $current_route->hasDefault('display_id')
    ) {

      /** @var View $view */
      $view = View::load($current_route->getDefault('view_id'));

      if ($view) {
        $display = $view->getDisplay($current_route->getDefault('display_id'));
        $current_language = $this->languageManager->getCurrentLanguage()->getId();

        if (isset($display['display_options']['display_extenders']['oab_theme_settings']['theme'][$current_language])) {
         return $display['display_options']['display_extenders']['oab_theme_settings']['theme'][$current_language] === 'ob1';
        }
      }
    }
    return false;
  }
}
