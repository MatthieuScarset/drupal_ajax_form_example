<?php

namespace Drupal\oab_pdf\PdfGenerator;

use Drupal\Component\Render\MarkupInterface;
use Drupal\Component\Utility\Html;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Knp\Snappy\Pdf;

class AbastractPdfGenerator implements PdfGeneratorInterface {

  protected Pdf $snappy;
  protected FileSystemInterface $fileSystem;

  use StringTranslationTrait;

  /**
   * Regroup all functions call to correct HTML
   *
   * @param \DOMDocument $html
   *
   * @return void
   * @throws \DOMException
   */
  protected function correctHtml(\DOMDocument &$html): void {
    $this->correctImgSrc($html);
    $this->correctCssLink($html);
    $this->replaceVideoByLink($html);
  }

  /**
   * Add Title to html before rendering the PDF
   *
   * @param \DOMDocument $html
   * @param string $title
   *
   * @return void
   * @throws \DOMException
   */
  protected function setHtmlTitle(\DOMDocument &$html, string $title): void {
    if (!$html->getElementsByTagName('title')->count()) {
      $head = $html->getElementsByTagName('head');

      $head->item(0)->appendChild($html->createElement('title', $title));
    }
  }

  /**
   * add CSS to HTML
   *
   * @param \DOMDocument $html
   * @param string $path
   *
   * @return void
   * @throws \DOMException
   */
  protected function addCssFile(\DOMDocument &$html, string $path): void {
    if (file_exists($this->fileSystem->realpath($path))) {
      $head = $html->getElementsByTagName('head');
      $link = $html->createElement('link');
      $link->setAttribute('rel', 'stylesheet');
      $link->setAttribute('media', 'all');
      $link->setAttribute('href', $path);
      $head->item(0)->appendChild($link);
    }
  }

  /**
   * Make sure img src are root based
   *
   * @param \DOMDocument $html
   *
   * @return void
   */
  protected function correctImgSrc(\DOMDocument &$html): void {
    /** @var \DOMElement $img */
    foreach ($html->getElementsByTagName('img') as $img) {
      $src = $img->getAttribute('src');

      $src = substr($src, 0, strpos($src, '?') ?: strlen($src)); // Remove token
      $src = str_replace(['/sites/default/files', '/system/files/'], ['public://', 'private://'], $src); // Create file URI

      if (file_exists($this->fileSystem->realpath($src))) {
        $img->setAttribute('src', $this->fileSystem->realpath($src));
      } else {
        $img->parentNode->removeChild($img);
      }

    }
  }

  /**
   * Remove video from PDF, replace with the link
   *
   * @param \DOMDocument $html
   *
   * @return void
   * @throws \DOMException
   */
  protected function replaceVideoByLink(\DOMDocument &$html): void {

    /** @var \DOMElement $video */
    foreach ($html->getElementsByTagName('iframe') as $video) {
      $src = $video->getAttribute('src');

      if (!empty($src)) {
        $src = substr($src, 0, strpos($src, '?') ?: strlen($src));

        $text_before_link = $html->createElement('span', $this->t('To watch the video on Youtube:'));
        $text_before_link->setAttribute('class', 'video-label');
        $video_link = $html->createElement('a', $src);
        $video_link->setAttribute('href', $src);

        $video->parentNode->appendChild($text_before_link);
        $video->parentNode->appendChild($video_link);
      }
      $video->parentNode->removeChild($video);
    }

  }

  /**
   * Correct CSS link to make sure they exist and are root based
   *
   * @param \DOMDocument $html
   *
   * @return void
   */
  protected function correctCssLink(\DOMDocument &$html): void {
    /** @var \DOMElement $meta_link */
    foreach ($html->getElementsByTagName('link') as $meta_link) {

      if ($meta_link->hasAttribute('rel') && $meta_link->getAttribute('rel') === 'stylesheet') {
        $href = $meta_link->getAttribute('href');
        $href = substr($href, 0, strpos($href, '?')); // Remove token
        $meta_link->setAttribute('href', DRUPAL_ROOT . $href);
      }
    }
  }

  /**
   * Create unique filename
   *
   * @param string $path
   * @param string $name
   *
   * @return string
   */
  protected function getFilepath(string $path, string $name): string {
    $name = $this->transliterateFilename($name);
    $filepath = "$path/$name";

    if (file_exists($filepath . '.pdf')) {
      $i = 0;
      while (file_exists($filepath . "_$i.pdf")) {
        $i++;
      }
      $filepath .= "_$i";
    }

    return "$filepath.pdf";
  }

  /**
   * Transliterate Filename to remove special chars
   *
   * @param string $name
   *
   * @return string
   */
  protected function transliterateFilename(string $name): string {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $new_value = \Drupal::transliteration()->transliterate($name, $current_language, '_');
    $new_value = trim(strtolower($new_value));
    $new_value = preg_replace('/[^a-z0-9_]+/', '_', $new_value);
    return preg_replace('/_+/', '_', $new_value);
  }
}
