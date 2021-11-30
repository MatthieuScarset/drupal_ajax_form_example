<?php

namespace Drupal\oab_didomi\EventSubscriber;

use Drupal\block_content\Entity\BlockContent;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\Render\Renderer;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;
use Symfony\Component\HttpKernel\Event\ResponseEvent;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 * Class IframeChangeSrcEvent
 *
 * @package Drupal\oab_didomi\EventSubscriber
 */
class IframeChangeSrcEvent implements EventSubscriberInterface {

  private $renderer;
  private $entityTypeManager;

  public function __construct(Renderer $renderer, EntityTypeManager $entityTypeManager) {
    $this->renderer = $renderer;
    $this->entityTypeManager = $entityTypeManager;
  }
  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents() {
    $events[KernelEvents::RESPONSE][] = ['onResponse'];
    return $events;
  }

  public function onResponse(ResponseEvent $event) {
    $html = new \DOMDocument();
    @$html->loadHTML($event->getResponse()->getContent());

    $xpath = new \DOMXPath($html);
    /** @var \DOMElement $iframe */
    foreach($xpath->query("//iframe[(contains(@src, 'youtube'))]") as $iframe) {

      //on change les attributs de l'iframe youtube pour passer le src en data-src
      $iframe->setAttribute('data-src', $iframe->getAttribute('src'));
      $iframe->removeAttribute('src');
      $iframe->setAttribute('style', 'display: none;');

      //on load le block didomi contenant le message à afficher et le bouton pour accepter le cookie
      $block_didomi = $this->entityTypeManager->getStorage('block_content')->loadByProperties(['uuid' => 'eb454a17-56da-4d21-b3ca-565449d7c452' ]);
      if(count($block_didomi) > 0) {
        $block_didomi = reset($block_didomi);
        //on récupère le contenu html
        $body_html_block_didomi = $block_didomi->get('body')->getValue();
        if(count($body_html_block_didomi) > 0) {
          $body_html_block_didomi = reset($body_html_block_didomi);
          if(isset($body_html_block_didomi['value'])){
            //on crée l'element pour afficher le contenu du block
            $new_block_element = $html->createDocumentFragment();
            $new_block_element->appendXML($body_html_block_didomi['value']);
            $div_parent_block = $html->createElement('div');
            $div_parent_block->setAttribute('class', 'divParentBlockMessageCookie');
            $div_parent_block->setAttribute('style', 'display: none;');
            $div_parent_block->appendChild($new_block_element);

            //on crée une div parent pour y mettre l'iframe + le nouveau block
            $super_div_parent = $html->createElement('div');
            $super_div_parent->setAttribute('class', 'divParentIframeYoutube');
            $super_div_parent->setAttribute('is', 'div-iframe-youtube');
            $parentNode = $iframe->parentNode;
            $super_div_parent->appendChild($iframe);
            $super_div_parent->appendChild($div_parent_block);
            $parentNode->appendChild($super_div_parent);

            //on save le nouveau html formé
            $event->getResponse()->setContent($xpath->document->saveHTML());
          }
        }
      }
    }
  }
 }
