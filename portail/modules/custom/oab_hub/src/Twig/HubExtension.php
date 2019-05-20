<?php
namespace Drupal\oab_hub\Twig;
use Drupal\Core\Url;
use Drupal\image\Entity\ImageStyle;
use Drupal\node\Plugin\views\field\Node;
use Drupal\views\Views;
use Drupal\oab_hub\Controller\OabHubController;

class HubExtension extends \Twig_Extension
{

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
            new \Twig_SimpleFunction('hub_getNodeHubUrl', [$this, 'getNodeHubUrl']),
            new \Twig_SimpleFunction('hub_getBaseUrl', [$this, 'getBaseUrl']),
            new \Twig_SimpleFunction('hub_getHubSubhomeUrl', [$this, 'getHubSubhomeUrl']),
        ];
    }

    public function getFilters() {
        $filters = [
            new \Twig_SimpleFilter('hub_getMenu', [$this, 'getMenu']),
        ];

        return $filters;
    }


    public function getNodeHubUrl(\Drupal\node\Entity\Node $node) {
        return OabHubController::getNodeUrl($node->id());
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

    public function getHubSubhomeUrl($url) {
        return OabHubController::getHubSubhomeUrl($url);
    }
}
