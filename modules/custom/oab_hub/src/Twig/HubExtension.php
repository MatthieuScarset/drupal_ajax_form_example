<?php
namespace Drupal\oab_hub\Twig;
use Drupal\Core\Url;
use Drupal\image\Entity\ImageStyle;
use Drupal\node\Plugin\views\field\Node;
use Drupal\views\Views;
use Drupal\oab_hub\Controller\OabHubController;
use Twig\Extension\AbstractExtension;
use Twig\TwigFilter;
use Twig\TwigFunction;

class HubExtension extends AbstractExtension {

    /**
     * Returns the name of the extension.
     *
     * @return string The extension name
     */
    public function getName() {
        return "OAB/Hub Twig extension";
    }

    public function getFunctions() {
        return [
//            new TwigFunction('hub_getNodeHubUrl', [$this, 'getNodeHubUrl']),
            new TwigFunction('hub_getBaseUrl', [$this, 'getBaseUrl']),
//            new TwigFunction('hub_getHubSubhomeUrl', [$this, 'getHubSubhomeUrl']),
        ];
    }

    public function getFilters() {
        $filters = [
            new TwigFilter('hub_getMenu', [$this, 'getMenu']),
        ];

        return $filters;
    }

    public function getMenu($elements, $menu_name) {
        $ret = [];
        foreach ($elements as $name => $element) {
            if (strpos($name, $menu_name) !== false) {
                $ret = $element;
            }
        }
        return $ret;
    }

    public function getBaseUrl() {
        return OabHubController::getHubBaseUrl();
    }
}
