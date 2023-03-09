<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\node\NodeInterface;
use Drupal\oab_develop\Helpers\StringUtilities;
use Drupal\oab_frontoffice\Twig\OabExtension;
use Drupal\oab_hub\HubFrontUrlTrait;
use Drupal\taxonomy\Entity\Term;
use Drupal\views\Views;


class ProductBreadcrumbBuilder implements BreadcrumbBuilderInterface
{

  use HubFrontUrlTrait;

  /**
   * @var \Drupal\taxonomy\TermStorageInterface
   */
  private $termStorage;

  /**
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public function __construct(
    EntityTypeManagerInterface $entity_type_manager,
    protected StringUtilities $stringUtilities) {

    $this->termStorage = $entity_type_manager->getStorage('taxonomy_term');
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
    if ($term && count($parents = $this->termStorage->loadParents($term->id())) > 0) {
      $parent = reset($parents);

      ## On récupère l'url du parent depuis la view
      $parent_url = Url::fromRoute('view.category_page.category_page', ['tid'=> $parent?->id()]);

      ## On rajoute l'ancre à l'URL de la view
      $ancre_term = Url::fromRoute('view.category_page.category_page',
        ['tid'=> $parent?->id()],
        ['fragment'=> $this->stringUtilities->getSlug($term->getName())]
      );

      ## On ajoute au fil d'ariane le home et le lien de la page categ du produit
      $breadcrumb->addLink(Link::fromTextAndUrl(t('Home'), $this->getHubFrontUrl()));
      $breadcrumb->addLink(Link::fromTextAndUrl($parent->getName(), $parent_url));
      $breadcrumb->addLink(Link::fromTextAndUrl($term->getName(), $ancre_term));
    }
    else {
      // on est sur un produit sans Product Category => on reprend l'ancien fil d'ariane
      if ($node->hasField('field_subhome')) {

        ##Affichage du fil d'ariane :
        ## Home > Subhome de rattachement (Lien vers la display view)

        ##On recupère la valeur contenue dans le field_subhome (subhome de rattachement)
//        $subhomes = $node->get('field_subhome')->getValue();

        $term = Term::load($node->field_subhome->target_id ?? 0);

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
            $breadcrumb->addLink(Link::fromTextAndUrl(t('Home'), $this->getHubFrontUrl()));
            $breadcrumb->addLink(Link::createFromRoute($display_name, $display_route_name));
          }
        }
      }
    }

    return $breadcrumb;
  }
}
