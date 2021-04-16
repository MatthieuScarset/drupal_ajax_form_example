<?php

namespace  Drupal\oab_frontoffice\EventSubscriber;

use Drupal\pathauto\Entity\PathautoPattern;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpKernel\KernelEvents;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;
use Drupal\Core\Url;
use Symfony\Component\HttpKernel\Event\GetResponseForExceptionEvent;
use \Symfony\Component\HttpFoundation\RedirectResponse;


/**
 * Class SmartRedirectionEvent
 *
 * Classe pour rediriger les 403 et 404
 * => Si 404, on redirige vers
 *      - La subhome si on est dans une subhome
 *      - La homepage sinon
 * => Si 403 et utilisateur non loggé, redirection vers la HP
 * @package Drupal\oab_frontoffice\EventSubscriber
 */
class SmartRedirectionEvent implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents() {
    ##Lorsqu'il y a une exception levée par Drupal, on appel la fonction checkRedirection
    $events[KernelEvents::EXCEPTION][] = ['checkRedirection'];

    return $events;
  }


  public function checkRedirection(GetResponseForExceptionEvent $event) {

    // Pour être sur, pour les API Marketo/Altares.
    // Gestion des exceptions dans leur module
    $route_name = \Drupal::routeMatch()->getRouteName();
    if (strpos($route_name, 'oab_marketo.altares_api') !== false) {
      return;
    }


    #On vérifie le code de retour (S'il existe, et si 404 ou 403)
    if (method_exists($event->getException(), "getStatusCode")
      && $event->getException()->getStatusCode() == 404) {

      ########################
      ## CAS DES 404
      $request_url = $event->getRequest()->getRequestUri();        #Recuperation de l'URL
      if (substr($request_url, 0, 1) == "/") {      #Si l'URL commence par /, je le supprime (pour le découpage)
        $request_url =  substr($request_url, 1);
      }
      $url_parts = explode("/", $request_url);             #Découpage de l'URL, via le /
      ##kint(count($urlParts));
      if (count($url_parts) == 2) {
        #Si on a 2 elements, on redirige vers la home
        #(cas des subhomes => /fr/blogs)
        $response = new RedirectResponse(Url::fromRoute('<front>')->toString());
        $event->setResponse($response);
      } elseif (count($url_parts) > 2) {
        #Si on a plus, on redirige vers la subhome en question
        #Si elle n'existe pas, elle sera ensuite redirigé vers la home par la partie d'au-dessus
        $response = new RedirectResponse("/".$url_parts[0] . "/" .$url_parts[1]);
        $event->setResponse($response);
      }

    } elseif (method_exists($event->getException(), "getStatusCode")
      && $event->getException()->getStatusCode() == 403) {
      ########################
      ## CAS DES 403

      // Petit check pour les requetes AJAX de l'API OBL
      $route_name = \Drupal::routeMatch()->getRouteName();

      if (\Drupal::currentUser()->isAnonymous() && strpos($route_name, 'oab_obl') !== 0) {
        # Si user n'est pas loggué, on redirige vers la home
        $response = new RedirectResponse(Url::fromRoute('<front>')->toString());
        $event->setResponse($response);
      } elseif (strpos($route_name, 'oab_obl') === 0) {
        $event->setResponse(new JsonResponse(["Access denied"], 403));
      }
    }

  }
}
