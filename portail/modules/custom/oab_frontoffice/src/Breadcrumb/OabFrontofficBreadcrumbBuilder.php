<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal;
use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Link;
use Drupal\Core\Routing\AdminContext;

class OabFrontofficBreadcrumbBuilder implements BreadcrumbBuilderInterface {
  /**
   * @inheritdoc
   */
  public function applies(RouteMatchInterface $route_match) {
    ##ici, on indique si on veut utiliser ou non le breadcrumb perso


    ##Je ne le gère que pour la front page
    $is_admin_route = Drupal::service('router.admin_context')->isAdminRoute();

    if ( !$is_admin_route) {
      return true;
    }

    ##Je ne retourne rien si je ne veux pas toucher au breadcrumb
  }

  /**
   * @inheritdoc
   */
  public function build(RouteMatchInterface $route_match) {
    # Ici, on personnalise le breadcrumb

    $parameters = $route_match->getParameters()->all();

    $current_route_match = Drupal::getContainer()
      ->get('current_route_match');
    $route_name = $current_route_match->getRouteName();


    ##On crée le breadcrumb
    $breadcrumb = new Breadcrumb();
    ##Par défaut, il est vide, sans le "home".
    ##Du coup, s'il ne correspond à aucun des cas ci dessous,
    # rien ne s'affiche, même pas la petite maison


    ## Si la page est une subhome,
    ## on affiche le nom de la subhome, sans lien
    if (preg_match('/^view.subhomes/', $route_name)) {

      ##On commence par afficher la racine du fil d'ariane
      $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));

      ##On recupère la display view correspondante
      $view = \Drupal\views\Views::getView('subhomes' );
      $view->setDisplay($parameters['display_id']);
      $displayObj = $view->getDisplay();

      #Et on en recupère son titre pour l'affichage
      $displayName = $displayObj->display['display_options']['title'];

      ##On ajoute un lien vide au fil d'ariane
      $breadcrumb->addLink(Link::createFromRoute(t($displayName), '<none>' ));

    } else {

      #Liste des types de contenu pour cette config du fil d'ariane
      $contentTypes = ["blog_post","customer_story", "document", "magazine","office", "partner",
        "press_kit", "press_release","product" ];


      $node = $route_match->getParameter('node');

     ##Si on a un bien un node en affichage,
      # et que le type de contenu est dans le tableau ci-dessus
      # et qu'il possède le champs 'field_subhome'
      if (isset($node)
        && in_array($parameters['node']->getType(), $contentTypes)
        && $node->hasField('field_subhome')) {

        ##Affichage du fil d'ariane :
        ## Home > Subhome de rattachement (Lien vers la display view)


        ##On recupère la valeur contenue dans le field_subhome (subhome de rattachement)
        $subhomes = $node->get('field_subhome')->getValue();

        ##On vérifie qu'on a bien un résultat
        if (is_array($subhomes) && count($subhomes)>0) {

          ##Récupération de la taxo pour la target du subhome en question
          $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($subhomes[0]['target_id']);

          ##Si le terme a le field "field_related_view_path'
          #(contient le nom machine de la display view correspondante)
          if ($term->hasField('field_related_view_path')) {
            $value = $term->get('field_related_view_path')->getValue();

            ##on test si on a un resultat
            if (isset($value[0]['value'])) {
              ## On recupère le nom machine de la display view
              $display_machineName = $value[0]['value'];

              ##On charge la vue "Subhome", puis on set avec la display view de la subhome
              $view = \Drupal\views\Views::getView('subhomes');
              $view->execute($display_machineName);
              $displayObj = $view->getDisplay();

              ##On en recupère le nom de la vue (pour le nom du lien)
              $displayName = $displayObj->display['display_options']['title'];

              ##Et la route de la display view (pour en créer l'url)
              $routeName = $displayObj->getRouteName();


              ##On ajoute au fil d'ariane le home et le lien de la subhome de rattachement
              $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));
              $breadcrumb->addLink(Link::createFromRoute(t($displayName), $routeName));
            }
          }
        }

      }
    }


    return $breadcrumb;

  }
}