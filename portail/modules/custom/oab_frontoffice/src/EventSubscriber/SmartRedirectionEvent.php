<?php

namespace  Drupal\oab_frontoffice\EventSubscriber;

use Drupal\node\Plugin\views\field\Path;
use Drupal\pathauto\Entity\PathautoPattern;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
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

    #On vérifie le code de retour (S'il existe, et si 404 ou 403)
    if (method_exists($event->getException(), "getStatusCode")
      && $event->getException()->getStatusCode() == 404) {

      ########################
      ## CAS DES 404
      $requestUrl = $event->getRequest()->getRequestUri();        #Recuperation de l'URL
      if (substr ( $requestUrl , 0, 1) == "/") {      #Si l'URL commence par /, je le supprime (pour le découpage)
        $requestUrl =  substr($requestUrl , 1);
      }
      $urlParts = explode("/", $requestUrl);             #Découpage de l'URL, via le /
      ##kint(count($urlParts));
      if (count($urlParts) == 2 ) {
        #Si on a 2 elements, on redirige vers la home
        #(cas des subhomes => /fr/blogs)
        $response = new RedirectResponse(Url::fromRoute('<front>')->toString());
        $event->setResponse($response);
      } elseif (count($urlParts) > 2) {
        #Si on a plus, on redirige vers la subhome en question
        #Si elle n'existe pas, elle sera ensuite redirigé vers la home par la partie d'au-dessus
        $response = new RedirectResponse("/".$urlParts[0] . "/" .$urlParts[1]);
        $event->setResponse($response);
      }

    } elseif (method_exists($event->getException(), "getStatusCode")
      && $event->getException()->getStatusCode() == 403) {
      ########################
      ## CAS DES 403
      if (\Drupal::currentUser()->isAnonymous()) {
        # Si user n'est pas loggué, on redirige vers la home
        $response = new RedirectResponse(Url::fromRoute('<front>')->toString());
        $event->setResponse($response);
      }
    }

  }
}
