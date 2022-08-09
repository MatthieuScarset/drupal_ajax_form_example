<?php

namespace Drupal\oab_marketo\EventSubscriber;


use Drupal\Core\Render\HtmlResponse;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\ResponseEvent;
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
   *
   * @param ResponseEvent $event
   */
  public function onResponse(ResponseEvent $event) {

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
