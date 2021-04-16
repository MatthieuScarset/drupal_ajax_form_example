<?php

namespace Drupal\oab_marketo\EventSubscriber;


use Drupal\Core\Render\HtmlResponse;
use Drupal\Core\Routing\RouteMatchInterface;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;
use Symfony\Component\HttpKernel\Exception\HttpException;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 *  Add no-cache header if a altares token is sent
 *
 * Class ExceptionRewritingEvent
 * @package Drupal\oab_marketo\EventSubscriber
 */
class AlterHeadersEvent implements EventSubscriberInterface {


  public static function getSubscribedEvents() {
    return [
      KernelEvents::RESPONSE => [
        ['onResponse']
      ]
    ];
  }


  /**
   * Add no-cache header if a altares token is sent
   * @param FilterResponseEvent $event
   */
  public function onResponse(FilterResponseEvent $event) {

    /** @var HtmlResponse $response */
    $response = $event->getResponse();
    if (is_a($response, HtmlResponse::class)) {
      $attachments = $response->getAttachments();
      if (isset($attachments['drupalSettings']['marketo_altares_token'])) {
        $response->headers->set('Cache-Control', 'no-store');
      }
    }
  }
}
