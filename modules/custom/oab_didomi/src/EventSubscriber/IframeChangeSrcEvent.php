<?php

namespace Drupal\oab_didomi\EventSubscriber;

use Drupal\block_content\Entity\BlockContent;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\Language\LanguageManager;
use Drupal\Core\Render\Markup;
use Drupal\Core\Render\Renderer;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\ResponseEvent;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 * Class IframeChangeSrcEvent
 *
 * @package Drupal\oab_didomi\EventSubscriber
 */
class IframeChangeSrcEvent implements EventSubscriberInterface {


  /**
   * @var LanguageManager
   */
  private $languageManager;
  /**
   * @var Renderer
   */
  private $renderer;
  /**
   * @var EntityTypeManager
   */
  private $entityTypeManager;

  public function __construct(Renderer $renderer, EntityTypeManager $entityTypeManager, LanguageManager $languageManager) {
    $this->languageManager = $languageManager;
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
    $content = $event->getResponse()?->getContent();

    if ($node = \Drupal::routeMatch()->getParameter('node')) {
      \Drupal::service('generator')->generatePdf(Markup::create($content), ['#node' => $node]);
    }

    if(!empty($content)) {
      @$html->loadHTML($content);
      if (!empty($html)) {
        $xpath = new \DOMXPath($html);
        /** @var \DOMElement $iframe */
        foreach ($xpath->query("//iframe[(contains(@src, 'youtube'))]") as $iframe) {
          //on change les attributs de l'iframe youtube pour passer le src en data-src
          $iframe->setAttribute('data-src', $iframe->getAttribute('src'));
          $iframe->removeAttribute('src');
          $iframe->setAttribute('style', 'display: none;');

          //on load le block didomi contenant le message à afficher et le bouton pour accepter le cookie
          $block_didomi = $this->entityTypeManager->getStorage('block_content')
            ->loadByProperties(['uuid' => 'eb454a17-56da-4d21-b3ca-565449d7c452']);

          if (count($block_didomi) > 0) {
            $block_didomi = reset($block_didomi);
            /** @var BlockContent $block_didomi */
            $languages = $block_didomi->getTranslationLanguages(TRUE);
            if (key_exists($this->languageManager->getCurrentLanguage()
              ->getId(), $languages)) {
              $block_didomi = $block_didomi->getTranslation($this->languageManager->getCurrentLanguage()
                ->getId());
            }
            //on récupère le contenu html
            $body_html_block_didomi = $block_didomi->get('body')->getValue();

            if (count($body_html_block_didomi) > 0) {
              $body_html_block_didomi = reset($body_html_block_didomi);

              if (isset($body_html_block_didomi['value'])) {
                //on crée l'element pour afficher le contenu du block
                $div_parent_block = $html->createElement('div');
                $div_parent_block->setAttribute('class', 'divParentBlockMessageCookie');
                $div_parent_block->setAttribute('style', 'display: none;');

                // la div didomi-message : case noire au fond blanc
                $div_didomi_message = $html->createElement('div');
                $div_didomi_message->setAttribute('class', 'didomi-message');
                //html du block => dans la div didomi-message
                $new_block_element = $html->createDocumentFragment();
                $new_block_element->appendXML($body_html_block_didomi['value']);
                $div_didomi_message->appendChild($new_block_element);

                $a_button = $html->createElement('a');
                $a_button->setAttribute('class', 'btn btn-default btn_accept_cookie_youtube');
                $a_button->textContent = t('Accept');

                $div_didomi_message->appendChild($a_button);

                $div_parent_block->appendChild($div_didomi_message);

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
  }
 }
