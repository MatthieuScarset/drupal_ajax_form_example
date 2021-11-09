<?php

namespace Drupal\oab_hub\EventSubscriber;

use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\RequestEvent;
use Symfony\Component\HttpKernel\KernelEvents;


class DisableRedirectIfMultiAliasEvent implements EventSubscriberInterface {

    /**
     * {@inheritdoc}
     *
     * Publish the Event.
     */
    public static function getSubscribedEvents() {
        # Il faut que je passe avant l'event du module Redirect de normalisation pour setter un param de la requete,
        # donc je mets un gros Coef pour être sur d'etre avant
        $events[KernelEvents::REQUEST][] = ['onRequest', 31];

        return $events;
    }

    /**
     * {@inheritdoc}
     *
     * Desactivation de la "normalisation" par le module Redirect
     * qui cause des 301 lors des multi alias pour un même noeud
     */
    public function onRequest(RequestEvent $event) {
        $request = $event->getRequest();


        $attr = $event->getRequest()->attributes;
        $is_front_page = \Drupal::service('path.matcher')->isFrontPage();

        ## Recuperation du node et qques vérifications pour éviter les erreurs
        if (NULL !== $attr
            && NULL !== $attr->get('node')
            && $attr->get('_controller') == '\Drupal\node\Controller\NodeViewController::view'
            && !$is_front_page
        ) {
            $node = $attr->get('node');

            if (is_object($node)
                && get_class($node) === 'Drupal\node\Entity\Node'
            ) {
                $node_lang_id = $node->language()->getId();
                $path_list = oab_getAllPathFromNID($node->id(), $node_lang_id);
                ## Je vérifie que l'URL fait partie de la liste des alias du node
                if (in_array($request->getRequestUri(), $path_list)) {
                    $request->attributes->set('_disable_route_normalizer', true);
                }
            }
        }

    }


}
