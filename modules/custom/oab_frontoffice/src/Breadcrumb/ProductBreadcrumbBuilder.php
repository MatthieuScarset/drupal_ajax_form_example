<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Link;
use Drupal\node\NodeInterface;
use Drupal\oab_hub\Controller\OabHubController;
use Drupal\taxonomy\Entity\Term;
use Drupal\views\Views;


class ProductBreadcrumbBuilder implements BreadcrumbBuilderInterface
{


  /**
   * @var \Drupal\taxonomy\TermStorageInterface
   */
  private $termStorage;

  public function __construct(EntityTypeManagerInterface $entityTypeManager) {

    $this->termStorage = $entityTypeManager->getStorage('taxonomy_term');
  }

  /**
   * @inheritdoc
   */
  public function applies(RouteMatchInterface $route_match)
  {

    ##Je ne le gère que pour la front page
    $is_admin_route = \Drupal::service('router.admin_context')->isAdminRoute();

    if (!$is_admin_route) {
      ##ici, on indique si on veut utiliser ou non le breadcrumb perso
      $node = $route_match->getParameter('node');

      #on appliquera ce breadcrumb uniquement aux contenus de type Product qui ont le champs product category
      if ($node instanceof NodeInterface
        && in_array($node->bundle(), ['product', 'modular_product'])
        && $node->hasField('field_product_category')) {
        return TRUE;
      }
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

    # On load le 1er term du field
    $term = Term::load($node->field_product_category->target_id ?? 0);

    ##On vérifie qu'on a bien un résultat
    if ($term) {
      #on vérifie si c'est un terme parent ou terme enfant en récupérant la liste de ses parents
      $parents = $this->termStorage->loadAllParents($term->id());
      # si le term est un enfant, on redirige vers le term parent
      if(count($parents) > 1){ //count($parents) = depth
        $term = $this->termStorage->loadParents($term->id());
        $term = reset($term);
      }

      ##On charge la vue Category product
      $view = Views::getView('category_page');
      $view->execute("category_page");
      $view->setArguments([$term->id()]);
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
//        $subhomes = $node->get('field_subhome')->getValue();

        $term = Term::load($node->field_subhome->target_id);

        ##Si le terme a le field "field_related_view_path'
        #(contient le nom machine de la display view correspondante)
        if ($term && $term->hasField('field_related_display_view')) {
          $value = $term->field_related_display_view->value;

          ##on test si on a un resultat
          if ($value) {
            ## On recupère le nom machine de la display view
            $display_machine_name = $value;

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

    return $breadcrumb;
  }
}
