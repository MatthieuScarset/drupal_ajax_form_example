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
    public function getName()
    {
        return "OAB/Hub Twig extension";
    }

    public function getFunctions()
    {
        return [
            new \Twig_SimpleFunction('hub_getHubUrl', [$this, 'getHubUrl']),
        ];
    }

    public function getFilters()
    {
        $filters = [
            new \Twig_SimpleFilter('hub_getMenu', [$this, 'getMenu']),
        ];

        return $filters;
    }


    public function getHubUrl(\Drupal\node\Entity\Node $node) {
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

}