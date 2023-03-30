<?php

namespace Drupal\oab_frontoffice\EventSubscriber;

use Drupal\Core\Http\Exception\CacheableAccessDeniedHttpException;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\ExceptionEvent;
use Symfony\Component\HttpKernel\Event\RequestEvent;
use Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;
use Symfony\Component\HttpKernel\KernelEvents;
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
    public function onRequest(RequestEvent $event) {

        // Pour être sur, pour les API Marketo/Altares.
        // Gestion des exceptions dans leur module
        $route_name = \Drupal::routeMatch()->getRouteName();
        if (str_contains($route_name, 'oab_marketo.altares_api')
          || str_contains($route_name, 'oab_mp_product_formule_packages')) {
          return;
        }

        $request = $event->getRequest();

        if ($request->attributes->has('exception')
          && (is_a($request->attributes->get('exception'), NotFoundHttpException::class)
            || is_a($request->attributes->get('exception'), AccessDeniedHttpException::class))
        ) {

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

                          \Drupal::logger('node_source_redirect')
                              ->debug('1. Redirect from %source to %dest. Is front : %is_front', [
                                '%source' => $current_uri,
                                '%dest' => $new_url,
                                '%is_front' => \Drupal::service('path.matcher')->isFrontPage() ? "oui" : "non"
                              ]);

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

                    $lang_prefixes = \Drupal::config('language.negotiation')->get('url.prefixes');
                    $node_lang_prefix = $lang_prefixes[$node_lang_id] ?? '';

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
                    $current_uri = $request->getRequestUri();

                    $real_front_url = "/" . $node_lang_prefix . \Drupal::config("system.site")->get('page.front');

                    ## Comme un noeud peut avoir plusieurs alias, je les recupère tous
                    ## et je teste s'ils existent dans la liste
                    $path_list = oab_getAllPathFromNID($node->id(), $node_lang_id);
                    if ($new_url != ''
                      && $new_url !== $current_uri
                      && !in_array($this->removeOptionsFromUrl($current_uri), $path_list)
                      // Bug avec $isFront() qui peut répondre "non" alors que si,
                      // et "/" n'est pas un alias du node, donc /fr/ pouvait être redirigé vers /fr/node/{nid}
                      && $real_front_url !== $this->removeOptionsFromUrl($new_url)
                    ) {

                      \Drupal::logger('node_source_redirect')
                        ->debug('2. Redirect from %source to %dest. uri_wo_options: %uri_wo_options ' .
                          '| path_list : %path_list | Is front : %is_front', [
                          '%source' => $current_uri,
                          '%dest' => $new_url,
                          '%path_list' => implode(' | ', $path_list),
                          '%uri_wo_options' => $this->removeOptionsFromUrl($current_uri),
                          '%is_front' => \Drupal::service('path.matcher')->isFrontPage() ? "oui" : "non"
                        ]);

                        $response = new RedirectResponse($new_url, 301);
                        $event->setResponse($response);
                    }
                }
            }
        }
    }

    private function removeOptionsFromUrl(string $url): string {
      return str_contains($url, '?')
        ? substr($url, 0, strpos($url, '?'))
        : $url;
    }
}
