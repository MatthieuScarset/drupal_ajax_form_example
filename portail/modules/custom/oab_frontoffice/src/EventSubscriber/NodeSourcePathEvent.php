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
        $events[KernelEvents::REQUEST][] = ['onRequest'];

        return $events;
    }

    /**
     * {@inheritdoc}
     *
     * redirect source node url to languaged alias
     */
    public function onRequest(GetResponseEvent $event) {
        $request = $event->getRequest();
        
        if ($request->attributes->has('exception')
          && (get_class($request->attributes->get('exception')) == "Symfony\Component\HttpKernel\Exception\NotFoundHttpException"
            || get_class($request->attributes->get('exception')) == "Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException")) {

            $code = $request->attributes->get('exception')->getStatusCode();
            if (!in_array($code, array(403, 404))) {
                $attr = $event->getRequest()->attributes;
                $is_front_page = \Drupal::service('path.matcher')->isFrontPage();

                if (NULL !== $attr
                    && NULL !== $attr->get('node')
                    && $attr->get('_controller') == '\Drupal\node\Controller\NodeViewController::view'
                    && !$is_front_page
                ) {
                    $node = $attr->get('node');

                    if (is_object($node)
                        && get_class($node) === 'Drupal\node\Entity\Node'
                    ) {
                        $node_language = $node->language();
                        $node_lang_id = $node_language->getId();

                        // if language is undefined, we load the current language page
                        if ($node_lang_id == LanguageInterface::LANGCODE_NOT_SPECIFIED) {
                            $node_language = \Drupal::languageManager()->getCurrentLanguage();
                        }

                        $options = [
                            'language' => $node_language,
                            'query' => $request->query->all()
                        ];
                        $url = Url::fromRoute('entity.node.canonical', ['node' => $node->id()], $options);
                        $new_url = $url->toString();
                        $current_uri = $_SERVER['REQUEST_URI'];

                        if ($new_url != ''
                            && $new_url !== $current_uri
                        ) {
                            $response = new RedirectResponse($new_url, 301);
                            $event->setResponse($response);
                        }
                    }
                }
            }
        } else {
            //page existante avec un acces granted mais pas d'alias
            $attr = $event->getRequest()->attributes;
            $is_front_page = \Drupal::service('path.matcher')->isFrontPage();


            if (NULL !== $attr
                && NULL !== $attr->get('node')
                && $attr->get('_controller') == '\Drupal\node\Controller\NodeViewController::view'
                && !$is_front_page
            ) {
                $node = $attr->get('node');

                if (is_object($node)
                    && get_class($node) === 'Drupal\node\Entity\Node'
                ) {
                    $node_language = $node->language();
                    $node_lang_id = $node_language->getId();

                    // if language is undefined, we load the current language page
                    if ($node_lang_id == LanguageInterface::LANGCODE_NOT_SPECIFIED) {
                        $node_language = \Drupal::languageManager()->getCurrentLanguage();
                    }
                    $options = [
                        'language' => $node_language,
                        'query' => $request->query->all()
                    ];
                    $url = Url::fromRoute('entity.node.canonical', ['node' => $node->id()], $options);
                    $new_url = $url->toString();
                    $current_uri = $_SERVER['REQUEST_URI'];


                    ## Comme un noeud peut avoir plusieurs alias, je les recupère tous
                    ## et je teste s'ils existent dans la liste
                    $path_list = oab_getAllPathFromNID($node->id(), $node_lang_id);


                    if ($new_url != ''
                        && $new_url !== $current_uri
                        && !in_array($current_uri, $path_list)
                    ) {
                        $response = new RedirectResponse($new_url, 301);
                        $event->setResponse($response);
                    }
                }
            }
        }
    }


}
