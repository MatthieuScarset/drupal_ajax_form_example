<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Link;
use Drupal\oab_hub\Controller\OabHubController;
use Drupal\taxonomy\Entity\Term;
use Drupal\views\Views;


class ProductBreadcrumbBuilder implements BreadcrumbBuilderInterface
{
  /**
   * @inheritdoc
   */
  public function applies(RouteMatchInterface $route_match)
  {
    ##ici, on indique si on veut utiliser ou non le breadcrumb perso
    $node = $route_match->getParameter('node');
    $parameters = $route_match->getParameters()->all();
    #on appliquera ce breadcrumb uniquement aux contenus de type Product qui ont le champs product category
    if (isset($node)
      && method_exists(get_class($parameters['node']), 'getType')
      && $parameters['node']->getType() == "product"
      && $node->hasField('field_product_category')) {
      return true;
    }
    ##Je ne retourne rien si je ne veux pas toucher au breadcrumb
  }

  /**
   * @inheritdoc
   */
  public function build(RouteMatchInterface $route_match)
  {
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

    ##On recupère la valeur contenue dans le field_product_category
    $product_categories = $node->get('field_product_category')->getValue();

    ##On vérifie qu'on a bien un résultat
    if (is_array($product_categories) && count($product_categories) > 0) {
      ##Récupération de la taxo
      $termId = $product_categories[0]['target_id'];
      #on vérifie si c'est un terme parent ou terme enfant en récupérant la liste de ses parents
      $parents = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadAllParents($termId);
      # si le term est un enfant, on redirige vers le term parent
      if(count($parents) > 1){ //count($parents) = depth
        $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadParents($termId);
        $term = reset($term);
        $termId = $term->id();
      }
      else{
        $term = Term::load($termId);
      }

      ##On charge la vue Category product
      $view = Views::getView('category_page');
      $view->execute("category_page");
      $view->setArguments(array($termId));
      $display_obj = $view->getDisplay();
      $url = $display_obj->getUrl();

      ##On ajoute au fil d'ariane le home et le lien de la page categ du produit
      $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));
      $breadcrumb->addLink(Link::fromTextAndUrl($term->getName(), $url));
    }
    else{
      // on est sur un produit sans Product Category => on reprend l'ancien fil d'ariane
      if ($node->hasField('field_subhome')) {

        ##Affichage du fil d'ariane :
        ## Home > Subhome de rattachement (Lien vers la display view)

        ##On recupère la valeur contenue dans le field_subhome (subhome de rattachement)
        $subhomes = $node->get('field_subhome')->getValue();

        ##On vérifie qu'on a bien un résultat
        if (is_array($subhomes) && count($subhomes) > 0) {
          ##Récupération de la taxo pour la target du subhome en question
          $term = \Drupal::entityTypeManager()
            ->getStorage('taxonomy_term')
            ->load($subhomes[0]['target_id']);

          ##Si le terme a le field "field_related_view_path'
          #(contient le nom machine de la display view correspondante)
          if (isset($term) && $term->hasField('field_related_display_view')) {
            $value = $term->get('field_related_display_view')->getValue();

            ##on test si on a un resultat
            if (isset($value[0]['value'])) {
              ## On recupère le nom machine de la display view
              $display_machine_name = $value[0]['value'];

              ##On charge la vue "Subhome", puis on set avec la display view de la subhome
              $view = Views::getView('subhomes');
              $view->execute($display_machine_name);
              $display_obj = $view->getDisplay();

              ##On en recupère le nom de la vue (pour le nom du lien)
              $display_name = ucfirst($display_obj->display['display_title']);

              ##Et la route de la display view (pour en créer l'url)
              $display_route_name = $display_obj->getRouteName();

              ##On ajoute au fil d'ariane le home et le lien de la subhome de rattachement
              $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));


              $url = OabHubController::getHubSubhomeUrl(\Drupal\Core\Url::fromRoute($display_route_name));

              if (is_string($url)) {
                $url = \Drupal\Core\Url::fromUri($url);
              }

              $breadcrumb->addLink(Link::fromTextAndUrl($display_name, $url));
            }
          }
        }
      }
    }

    return $breadcrumb;
  }
}
