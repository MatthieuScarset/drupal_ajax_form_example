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

    /*$contentType = [
      'blog_post'       => 'page_blog',
      'customer_story'  => 'page_customer',
      'document'        => 'page_document',
      'magazine'        => 'page_magazine',
      'office'          => '',
      'partner'         => 'page_partners',
      'press_kit'       => 'page_press',
      'press_release'   => 'page_press',
      'produit'         => 'page_catalogue'
    ];*/

/*
    $parameters = $route_match->getParameters()->all();
    if( isset($parameters['node'])
      && $parameters['node']->getType() != 'simple_page' ) {
      Drupal::logger('oab_frontoffice')->notice("Breadcrumbs::build : Hors simple page");
      $breadcrumb = [Link::createFromRoute(t('Home'), '<front>')];
      $breadcrumb[] = Link::createFromRoute(t('Blog2'), '<<<your route for blog>>>');
      kint($breadcrumb);
      return $breadcrumb;
    }
*/

    ##On crée le breadcrumb
    $breadcrumb = new Breadcrumb();
    ##Par défaut, il est vide, sans le "home".


    #$contentPageTypes = ["blog_post", ];
    /*if( isset($parameters['node'])
      && $parameters['node']->getType() != 'simple_page' )
*/





    ##Si c'est une subhome
    if (preg_match('/^view.subhomes/', $route_name)) {
      ##On est dans un subhome
      $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));

      $view = \Drupal\views\Views::getView('subhomes' );
      //kint($view);
      $view->setDisplay($parameters['display_id']);
      $displayObj = $view->getDisplay();

      $displayName = $displayObj->display['display_options']['title'];

      $breadcrumb->addLink(Link::createFromRoute(t($displayName), '<none>' ));

    } else {
      $node = $route_match->getParameter('node');



      // kint($subhomes);
      if (isset($node) && $parameters['node']->getType() != 'simple_page') {

        $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));


        $subhomes = $node->get('field_subhome')->getValue();
        if (is_array($subhomes) && count($subhomes)>0) {
          //$taxo = \Drupal\taxonomy\Entity\Term::load($subhomes[0]['target_id']);
          //$taxo = \Drupal\taxonomy\Entity\Term::load('subhomes');
          //kint($taxo);
          $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($subhomes[0]['target_id']);
          /*$field_content_type = $term->get('field_field_content_type');

          if ($field_content_type != null) {

          }*/
          #$breadcrumb->addLink(Link::createFromRoute('entity.taxonomy_term.canonical', ['taxonomy_term' => $term->tid->value], ['absolute' => TRUE]) );
          #$breadcrumb->addLink(Link::createFromRoute($term->get('name'), '<none>'));
          #$link = url('taxonomy/term/1');
          #kint($term->get('field_content_type'));
          kint($term);
        }




        $contentType = $parameters['node']->getType();

        $view = \Drupal\views\Views::getView('subhomes' );
        //$view->setDisplay($parameters['display_id']);
        //$displayObj = $view->getDisplay();

        //kint($node);

      //  kint($displayObj->view->storage);

        $breadcrumb->addLink(Link::createFromRoute(t($contentType), '<none>'));
      }
    }


    return $breadcrumb;

  }
}