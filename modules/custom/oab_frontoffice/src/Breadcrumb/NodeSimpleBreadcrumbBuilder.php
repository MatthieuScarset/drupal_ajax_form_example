<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal;
use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Link;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\node\NodeInterface;
use Drupal\oab_hub\HubFrontUrlTrait;

class NodeSimpleBreadcrumbBuilder implements BreadcrumbBuilderInterface {

  use HubFrontUrlTrait;

  public function applies(RouteMatchInterface $route_match) {
    ##Je ne le gère que pour la front page
    $is_admin_route = Drupal::service('router.admin_context')->isAdminRoute();

    if (!$is_admin_route) {
      ##ici, on indique si on veut utiliser ou non le breadcrumb perso
      $node = $route_match->getParameter('node');

      #on appliquera ce breadcrumb uniquement aux contenus de type Product qui ont le champs product category
      if ($node instanceof NodeInterface && $node->bundle() === 'corporate') {
        return TRUE;
      }
    }
  }

  public function build(RouteMatchInterface $route_match) {
    #on récupère le node
    $node = $route_match->getParameter('node');

    ##On crée le breadcrumb
    $breadcrumb = new Breadcrumb();

    ## Gestion du cache du breadcrumb (on lui dit qu'il est lié à cette url et ce noeud seulement)
    $breadcrumb->addCacheContexts(["url"]);

    # By adding "cache tags" for this specific node, the cache is invalidated when the node is edited.
    if (isset($node->nid->value) && !empty($node->nid->value)) {
      $breadcrumb->addCacheTags(["node:{$node->nid->value}"]);
    }

    $breadcrumb->addLink(Link::fromTextAndUrl(t('Home'), $this->getHubFrontUrl()));
    $breadcrumb->addLink(Link::createFromRoute($node->getTitle(), '<none>'));

    return $breadcrumb;
  }
}
