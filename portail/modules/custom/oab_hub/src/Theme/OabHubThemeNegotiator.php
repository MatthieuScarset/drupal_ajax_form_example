<?php

namespace Drupal\oab_hub\Theme;

use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Theme\ThemeNegotiatorInterface;
use Drupal\oab_hub\Controller\OabHubController;

class OabHubThemeNegotiator implements ThemeNegotiatorInterface {

    /**
     * Check si on doit utiliser notre themeNegotiator
     * Je regarde si le 1er element de l'URL est une définie par un des hubs
     */
    public function applies(RouteMatchInterface $route_match) {
        $applies = false;

        #Path du noeud (sous la forme /node/id
        $url = \Drupal::request()->getRequestUri();

        if (strpos($url, '?') !== false) {
            $url = substr($url, 0, strpos($url, '?'));
        }

        ##Je recupère toutes les parties de la route
        $route_parts = explode('/', $url);

        #Je supprime le 1er element qui est vide
        if (isset($route_parts[0]) && strlen($route_parts[0]) == 0) {
            array_shift($route_parts);
        }

        # Je recupère les URLS des hubs
        $urls = \Drupal::config(OabHubController::CONFIG_ID)->get(OabHubController::CONFIG_URL_LIST);

        if (isset($route_parts[1])) {
            ##Je teste si on a bien recu un tableau, au cas ou...
            if (is_array($urls)) {
                #l'URL du hub est le 1er element du tableau
                $applies = in_array($route_parts[1], $urls);
            }
        }


        // Use this theme negotiator.
        return $applies;
    }

    /**
     * Retourne le nom du theme à utiliser
     */
    public function determineActiveTheme(RouteMatchInterface $route_match) {
        return 'theme_oab_hub';
    }
}
