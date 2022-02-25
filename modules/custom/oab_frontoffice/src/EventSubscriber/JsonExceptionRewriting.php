<?php

namespace Drupal\oab_frontoffice\EventSubscriber;


use Drupal\Component\Serialization\Json;
use Drupal\Core\Routing\RouteMatchInterface;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Event\ExceptionEvent;
use Symfony\Component\HttpKernel\Exception\HttpException;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 *  Gestion des exceptions pour la JSON Api
 *
 * Class JsonExceptionRewriting
 * @package Drupal\oab_frontoffice\EventSubscriber
 */
class JsonExceptionRewriting implements EventSubscriberInterface {

  /**
   * @var RouteMatchInterface
   */
  private $routeMatch;

  public function __construct(RouteMatchInterface $route_match) {
    $this->routeMatch = $route_match;
  }

  public static function getSubscribedEvents() {
    return [
      KernelEvents::EXCEPTION => [
        ['onException']
      ]
    ];
  }


  public function onException(ExceptionEvent $event) {
    //On ne gère ici que les erreurs de la JSON Api
    $path = \Drupal::service('path.current')->getPath();
    if (strpos($this->routeMatch->getRouteName(), 'jsonapi') === false && strpos($path, 'jsonapi') === false) {
      return;
    }

    /** @var HttpException $exception */
    $exception = $event->getThrowable();
    if (is_a($exception, HttpException::class)) {
      $response = [];
      $response['error'] = $exception->getMessage();
      $response['status_code'] = $exception->getStatusCode();
      $event->setResponse(new JsonResponse($response, $exception->getStatusCode()));
    } else {
      // Default, set Http 400 error with status message
      $response = [];
      $response['error'] = t("Something bad happened with message %msg", ['%msg' => $exception->getMessage()]);
      $event->setResponse(new JsonResponse($response, 400));
    }

  }
}
