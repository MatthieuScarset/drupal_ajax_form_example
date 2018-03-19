<?php

namespace Drupal\oab_cookie_compliance\EventSubscriber;

use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\KernelEvents;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;

use Drupal\oab_cookie_compliance\Plugin\Block\CookieComplianceBlock;

class CookieManagementEvent implements EventSubscriberInterface {

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
     * Gère les cookies pour l'affichage du bandeau
     */
    public function onResponse(FilterResponseEvent $event)
    {
        /*kint($event); die();
                if ($event->getResponse()->getStatusCode() == 200) {
                    if (!isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME])
                        && !isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT]) ) {
                        CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT);

                    } elseif (isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT])) {
                        CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT, -1);
                        CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME);
                    }
                }
      */
    }
}