<?php

namespace Drupal\oab_frontoffice\Breadcrumb;

use Drupal;
use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Link;
use Drupal\Core\Routing\AdminContext;
use Drupal\oab_hub\Controller\OabHubController;
use Drupal\views\Views;


class OabFrontofficBreadcrumbBuilder implements BreadcrumbBuilderInterface {
    /**
     * @inheritdoc
     */
    public function applies(RouteMatchInterface $route_match) {
        ##ici, on indique si on veut utiliser ou non le breadcrumb perso


        ##Je ne le gère que pour la front page
        $is_admin_route = Drupal::service('router.admin_context')->isAdminRoute();

        if (!$is_admin_route) {
            return true;
        }

        ##Je ne retourne rien si je ne veux pas toucher au breadcrumb
    }

    /**
     * @inheritdoc
     */
    public function build(RouteMatchInterface $route_match) {
        # Ici, on personnalise le fil d'ariane

        /**
         * 3 cas :
         *    > On est dans une subhome : affichage du home + nom de la subhome non cliquable
         *    > On est dans un article avec une subhome de rattachement
         *        - Affichage du home + nom de la subhome de rattachement cliquable
         *    > On est ailleurs : Pas de fil d'ariane
         */
        $node = $route_match->getParameter('node');

        $parameters = $route_match->getParameters()->all();

        $current_route_match = Drupal::getContainer()
            ->get('current_route_match');
        $route_name = $current_route_match->getRouteName();


        ##On crée le breadcrumb
        $breadcrumb = new Breadcrumb();
        ##Par défaut, il est vide, sans le "home".
        ##Du coup, s'il ne correspond à aucun des cas ci dessous,
        # rien ne s'affiche, même pas la petite maison

        ## Gestion du cache du breadcrumb (on lui dit qu'il est lié à cette url et ce noeud seulement)
        # By setting a "cache context" to the "url", each requested URL gets it's own cache.
        # This way a single breadcrumb isn't cached for all pages on the site.
        $breadcrumb->addCacheContexts(["url"]);

        # By adding "cache tags" for this specific node, the cache is invalidated when the node is edited.
        if (isset($node->nid->value) && !empty($node->nid->value)) {
            $breadcrumb->addCacheTags(["node:{$node->nid->value}"]);
        }

        ## Si la page est une subhome,
        ## on affiche le nom de la subhome, sans lien
        if (preg_match('/^view.subhomes/', $route_name) && isset($parameters['view_id']) && isset($parameters['display_id'])) {

            ##On commence par afficher la racine du fil d'ariane
            $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));

            $subhome_display = str_replace('archive_', 'page_', $parameters['display_id']);

              // Petit hack pour "News" qui renvoie vers la subhome presse
            if ($subhome_display === 'page_news') {
              $subhome_display = "page_press";
            }

            ##On recupère la display view correspondante
            $view = Views::getView('subhomes');
            $view->setDisplay($subhome_display);
            $display_obj = $view->getDisplay();

            #Et on en recupère son titre pour l'affichage
            $display_name = ucfirst($display_obj->display['display_title']);


            if ($parameters['view_id'] === "subhomes") {
                ##On ajoute un lien vide au fil d'ariane

                $breadcrumb->addLink(Link::createFromRoute($display_name, '<none>'));
            } else {  ## Subhome archive

                ##On ajoute un lien vide au fil d'ariane

                $link = Link::createFromRoute($display_name, "view.subhomes." . $subhome_display);
                $link->setUrl(Drupal\Core\Url::fromUri(OabHubController::getHubSubhomeUrl($link->getUrl()->toString())));
                $breadcrumb->addLink($link);

                if ($subhome_display === 'archive_press') {
                  $link_text = t("Archives");
                } else {
                  ##On recupère la display view correspondante
                  $current_view = Views::getView($parameters['view_id']);
                  $current_view->setDisplay($parameters['display_id']);
                  $current_display = $current_view->getDisplay();

                  #Et on en recupère son titre pour l'affichage
                  $link_text = ucfirst($current_display->display['display_title']);
                }

                $breadcrumb->addLink(Link::createFromRoute($link_text, '<none>'));
            }

        } else {

            #Liste des types de contenu pour cette config du fil d'ariane
            $content_types = [
                "blog_post", "customer_story", "document", "magazine",
                "office", "partner", "press_kit", "press_release", "product", "news"];


            ##Si on a un bien un node en affichage,
            # et que le type de contenu est dans le tableau ci-dessus
            # et qu'il possède le champs 'field_subhome'
            if (isset($node)
                && method_exists(get_class($parameters['node']), 'getType')
                && in_array($parameters['node']->getType(), $content_types)
                && $node->hasField('field_subhome')) {

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
            elseif (isset($node)
              && method_exists(get_class($parameters['node']), 'getType')
              && $parameters['node']->getType() == 'cloud_service_provider'){
              //ajout du fil d'ariane pour les CSP de BVPN
              $breadcrumb->addLink(Link::createFromRoute(t('Home'), '<front>'));
              $breadcrumb->addLink(Link::createFromRoute(t('BVPN Galerie - List of Cloud Services'), 'view.bvpn_gallery.csp_list_page'));
            }
        }

        return $breadcrumb;

    }
}
