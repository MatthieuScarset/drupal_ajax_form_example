<?php

namespace Drupal\oab_frontoffice\EventSubscriber;

use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\KernelEvents;
use Symfony\Component\HttpKernel\Event\GetResponseEvent;
use Drupal\Core\Url;
use Drupal\Core\Routing\TrustedRedirectResponse;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Drupal\Core\Language\LanguageInterface;
use Drupal\oab_hub\Controller\OabHubController;
use Symfony\Component\DependencyInjection\ContainerBuilder;


class NodeSourcePathEvent implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents() {
    $events[KernelEvents::EXCEPTION][] = ['checkIf'];

    return $events;
  }

}
