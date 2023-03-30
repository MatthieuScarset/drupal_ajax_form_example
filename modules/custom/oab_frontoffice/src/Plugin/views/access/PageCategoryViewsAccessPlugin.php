<?php

namespace Drupal\oab_frontoffice\Plugin\views\access;

use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Url;
use \Drupal\views\Plugin\views\access\AccessPluginBase;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\Routing\Route;

/**
 * @ingroup views_access_plugins
 *
 * @ViewsAccess(
 *   id = "page_category_views_access_plugin",
 *   title = @Translation("Page category view access Plugin"),
 *   help = @Translation("Access will be granted only for terms of level1 ")
 * )
 */
class PageCategoryViewsAccessPlugin extends AccessPluginBase {
  /**
   * {@inheritdoc}
   */
  public function summaryTitle() {
    return $this->t('Allow access for items level 1 ');
  }


  /**
   * {@inheritdoc}
   */
  public function access(AccountInterface $account) {
    $current_route = \Drupal::routeMatch()->getRouteName();
    if ($current_route == 'view.category_page.category_page') {
      if (\Drupal::routeMatch()->getParameters()->has('tid')) {
        //on vérifie le niveau du terme de taxo passé en paramètre
        $term_id = \Drupal::routeMatch()->getParameters()->get('tid');
        $parents = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadAllParents($term_id);
        // si le term est un enfant, on redirige vers le term parent
        if (count($parents) > 1) { //count($parents) = depth
          $parent = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadParents($term_id);
          $parent = reset($parent);
          $parent_tid = $parent->id();
          //redirection vers le parent
          $url = Url::fromRoute($current_route, array('tid' => $parent_tid));
          $response = new RedirectResponse($url->toString());
          $response->send();
        }
      }
    }
    return $account->hasPermission('access content');
  }


  /**
   * {@inheritdoc}
   */
  public function alterRouteDefinition(Route $route) {
    $route->setRequirement('_permission', 'access content');
  }
}
