<?php

namespace Drupal\oab_marketo\EventSubscriber;


use Drupal\Core\Routing\RouteMatchInterface;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Event\ExceptionEvent;
use Symfony\Component\HttpKernel\Exception\HttpException;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 *  Gestion des exceptions pour les API Altares/Marketo
 *
 * Class ExceptionRewritingEvent
 * @package Drupal\oab_marketo\EventSubscriber
 */
class ExceptionRewritingEvent implements EventSubscriberInterface {

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

    if (strpos($this->routeMatch->getRouteName(), 'oab_marketo.altares_api') === false) {
      return;
    }

    /** @var HttpException $exception */
    $exception = $event->getThrowable();
    if (is_a($exception, HttpException::class)) {

      $msg = strlen($exception->getMessage()) > 0
        ? $exception->getMessage()
        : Response::$statusTexts[$exception->getStatusCode()];

      $event->setResponse(new Response($msg, $exception->getStatusCode()));
    } else {
      // Default, set Http 400 error with status message
      $msg = t("Something bad happened with message %msg", ['%msg' => $exception->getMessage()]);
      $event->setResponse(new Response($msg, 400));
    }

  }
}
