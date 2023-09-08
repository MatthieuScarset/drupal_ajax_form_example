<?php

namespace Drupal\oab_didomi\EventSubscriber;

use Drupal\block_content\Entity\BlockContent;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\Language\LanguageManager;
use Drupal\Core\Render\AttachmentsInterface;
use Drupal\Core\Render\Markup;
use Drupal\Core\Render\Renderer;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\ResponseEvent;
use Symfony\Component\HttpKernel\KernelEvents;


/**
 * Class IframeChangeSrcEvent
 *
 * @package Drupal\oab_didomi\EventSubscriber
 */
class IframeChangeSrcEvent implements EventSubscriberInterface {

  use StringTranslationTrait;


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

  public function __construct(
    Renderer          $renderer,
    EntityTypeManager $entity_type_manager,
    LanguageManager   $language_manager
  ) {
    $this->languageManager = $language_manager;
    $this->renderer = $renderer;
    $this->entityTypeManager = $entity_type_manager;
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


    if (!empty($content)) {
      @$html->loadHTML($content);
      if (!empty($html)) {
        $xpath = new \DOMXPath($html);

        /** @var \DOMNodeList $ytb_iframes */
        $ytb_iframes = $xpath->query("//iframe[(contains(@src, 'youtube'))]");

        // Si on a pas d'iframes, on stop le script tout de suite
        if ($ytb_iframes === null || $ytb_iframes->length === 0) {
          return;
        }

        //on load le block didomi contenant le message à afficher et le bouton pour accepter le cookie
        $block_didomi = $this->entityTypeManager->getStorage('block_content')
          ->loadByProperties(['uuid' => 'eb454a17-56da-4d21-b3ca-565449d7c452']);

        $body_html_block_didomi = "";
        if (count($block_didomi) > 0) {
          $block_didomi = reset($block_didomi);
          /** @var BlockContent $block_didomi */

          $current_language_id = $this->languageManager->getCurrentLanguage()->getId();
          if (key_exists($current_language_id, $block_didomi->getTranslationLanguages(TRUE))) {
            $block_didomi = $block_didomi->getTranslation($current_language_id);
          }
          //on récupère le contenu html
          $body_html_block_didomi = $block_didomi->body->value;
        }

        /** @var \DOMElement $iframe */
        foreach ($ytb_iframes as $iframe) {

          //on crée l'element pour afficher le contenu du block
          $div_cookie_block = $html->createElement('div');
          $div_cookie_block->setAttribute('slot', 'cookieBlock');

          //Ajout de l'html du block
          $msg_block_element = $html->createDocumentFragment();
          $msg_block_element->appendXML($body_html_block_didomi);
          $div_cookie_block->appendChild($msg_block_element);

          //on crée une div parent pour y mettre l'iframe + le nouveau block
          $ytb_embed_tag = $html->createElement('ytb-embed');
          $ytb_embed_tag->setAttribute('video-src', $iframe->getAttribute('src'));
          $ytb_embed_tag->setAttribute('video-title', $this->t("Youtube video"));
          $ytb_embed_tag->setAttribute('no-cover-image', 'true');

          // Ajout du cookie msg to the ytb embed tag
          $ytb_embed_tag->appendChild($div_cookie_block);

          // Finally, get the parent node and add the fully ytb-embed tag
          $parent_node = $iframe->parentNode;
          $parent_node->appendChild($ytb_embed_tag);

          // delete the iframe
          $iframe->remove();
        }

        // Ajout des custom elements
        /** @var \DOMElement $body */
        foreach ($xpath->query("//body") as $body) {
          $script_tag = $html->createElement('script');
          $script_tag->setAttribute("src", "/themes/theme_one_i/dist/js/ytb-embed.min.js");
          $body->appendChild($script_tag);
        }

        //on save le nouveau html formé
        $event->getResponse()->setContent($xpath->document->saveHTML());
      }
    }
  }

}
