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
            #new \Twig_SimpleFilter('format_bytes', [$this, 'format_bytes']),
        ];

        return $filters;
    }


    public function getHubUrl(\Drupal\node\Entity\Node $node) {
        return OabHubController::getNodeUrl($node->id());
    }
}