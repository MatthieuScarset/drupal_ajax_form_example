<?php

namespace Drupal\oab_frontoffice\EventSubscriber;

use Drupal\views\Ajax\ViewAjaxResponse;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;
use Symfony\Component\HttpKernel\KernelEvents;

class SubhomeUrlAlterEvent implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents()
  {
    $events[KernelEvents::RESPONSE][] = ['onResponse'];

    return $events;
  }

  /**
   * {@inheritdoc}
   *
   *
   */
  public function onResponse(FilterResponseEvent $event)
  {
    $response = $event->getResponse();

    // Only alter views ajax responses.
    if (!($response instanceof ViewAjaxResponse)) {
      return;
    }

    $view = $response->getView();

    // Only alter commands if view is ours
    if ($view->storage->id() != 'subhomes'){
      return;
    }

    $commands = &$response->getCommands();
    $this->alterCommands($commands);

  }

  /**
   * Alter the views AJAX response commands
  ﻿ * @param array $commands
   */
  protected function alterCommands(&$commands) {
    //oabt($commands);
    /*$commands = array(
      'command' => 'viewsAjaxUrl',
      'method' =>  'replaceWith'
    );*/

    /*array_unshift($commands, array(
      'command' => 'viewsAjaxUrl',
      'method' =>  'replaceWith'
    ));*/

    $commands[] = array(
      'command' => 'viewsAjaxUrl',
      'method' =>  'replaceWith'
    );

    /*foreach ($commands as $delta => &$command) {
      //if (isset($command['method']) && $command['method'] === 'replaceWith') {
        $command['method'] = 'viewsAjaxUrl';
      //}
    }*/

    //oabt($commands, true);
  }
}