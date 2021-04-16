<?php

namespace Drupal\oab_hub\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;

class OabHubTacLiteThemeNegotiator implements ThemeNegotiatorInterface {

    /**
     * Check si on doit utiliser notre themeNegotiator
     */
    public function applies(RouteMatchInterface $route_match) {
        $applies = false;

        ##je fais activer le theme back office lorsqu'on veut modifier tac_lite pour un utilisateur
        if ($route_match->getRouteName() == "tac_lite.user_access") {
            $applies = true;
        }

        // Use this theme negotiator.
        return $applies;
    }

    /**
     * Retourne le nom du theme à utiliser
     */
    public function determineActiveTheme(RouteMatchInterface $route_match) {
        return 'theme_obs_backoffice';
    }
}
