<?php

namespace Drupal\oab_pdf\Services;

use Drupal\Component\Render\MarkupInterface;
use Drupal\Component\Utility\Html;
use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Render\Markup;
use Drupal\Core\Security\TrustedCallbackInterface;
use Drupal\migrate\Plugin\migrate\process\MachineName;
use Drupal\node\NodeInterface;
use Knp\Snappy\Pdf;

class OabPdfGeneratorService {

  public function __construct(
    protected FileSystemInterface   $file_system,
    protected ExtensionPathResolver $path_resolver,
  ) {
  }

  /**
   * @throws \Exception
   */
  private function getSnappy(): Pdf {

    $bin_path = DRUPAL_ROOT . '/vendor/h4cc/wkhtmltopdf-amd64/bin/wkhtmltopdf-amd64';
    if (file_exists($bin_path)) {
      ini_set('memory_limit', '-1');
      $snappy = new Pdf($bin_path);
      $snappy->setOption('quiet', true);
      $snappy->setLogger(\Drupal::logger('snappy_pdf'));

      return $snappy;
    }

    throw new \Exception("There is a problem with Snappy");
  }

  /**
   * @throws \Exception
   */
  public function getOutput(MarkupInterface|String $markup, $title): string {
    $snappy = $this->getSnappy();

    $path_to_folder = $this->file_system->realpath($this->path_resolver->getPath('module', 'oab_pdf') . '/templates/');
    $header = $path_to_folder . "/_header.html";
    $footer = $path_to_folder . '/_footer.html';

    $pager = "[page]/[topage]";

    return $snappy->getOutputFromHtml($this->correctHtml($markup, $title), [
      'header-html' => $header,
      'header-spacing' => 10,
      'footer-html' => $footer,
      'footer-right' => $pager,
      'footer-font-size' => 7,
      'footer-spacing' => 10
    ]);
  }

  public function generatePdfFile(MarkupInterface|String $markup, $name, string $dir = null): string {
    $pdf_dir = $dir ?? $this->file_system->realpath('public://pdf_export');

    if ($this->file_system->prepareDirectory($pdf_dir, FileSystemInterface::CREATE_DIRECTORY)) {
      $path = $this->getFilepath($pdf_dir, $name);
      try {
        $this->getSnappy()->generateFromHtml($this->correctHtml($markup), $path);
      } catch (\Exception $e) {
        echo ($e->getMessage());
      }

      return $path;
    }
    throw new \Exception("There is a problem with Snappy");
  }

  private function correctHtml(MarkupInterface|string $markup, $title) {
    $html = Html::load($markup);

    if (!$html->getElementsByTagName('title')->count()) {
      $head = $html->getElementsByTagName('head');

      $head->item(0)->appendChild($html->createElement('title', $title));
    }

    if ($html->getElementsByTagName('style')->count()) {
      $style = $html->getElementsByTagName('style');
      $style->item(0)->textContent .= "row, col-* {page-break-after: always;}";

    } else {
      $html->getElementsByTagName('head')->item(0)->appendChild(
        $html->createElement('style', "row, col-* {page-break-after: always;}")
      );
    }

    $this->correctImgSrc($html);
    $this->correctCssLink($html);
    $this->replaceVideoByLink($html);

    return $html->saveHTML();
  }

  private function correctImgSrc(\DOMDocument &$html) {
    /** @var \DOMElement $img */
    foreach ($html->getElementsByTagName('img') as $img) {
      $src = $img->getAttribute('src');

      $src = substr($src, 0, strpos($src, '?') ?: strlen($src)); // Remove token
      $src = str_replace(['/sites/default/files', '/system/files/'], ['public://', 'private://'], $src); // Create file URI

      if (file_exists($this->file_system->realpath($src))) {
        $img->setAttribute('src', $this->file_system->realpath($src));
      } else {
        $img->parentNode->removeChild($img);
      }

    }
  }

  private function replaceVideoByLink(\DOMDocument &$html) {

    /** @var \DOMElement $video */
    foreach ($html->getElementsByTagName('iframe') as $video) {
      $src = $video->getAttribute('src');

      if (!empty($src)) {
        $src = substr($src, 0, strpos($src, '?') ?: strlen($src));

        $text_before_link = $html->createElement('span', 'To watch the video on Youtube:');
        $text_before_link->setAttribute('class', 'video-label');
        $video_link = $html->createElement('a', $src);
        $video_link->setAttribute('href', $src);

        $video->parentNode->appendChild($text_before_link);
        $video->parentNode->appendChild($video_link);
        $video->parentNode->removeChild($video);
      } else {
        $video->parentNode->removeChild($video);
      }
    }

  }

  private function correctCssLink(\DOMDocument &$html) {
    /** @var \DOMElement $meta_link */
    foreach ($html->getElementsByTagName('link') as $meta_link) {

      if ($meta_link->hasAttribute('rel') && $meta_link->getAttribute('rel') === 'stylesheet') {
        $href = $meta_link->getAttribute('href');
        $href = substr($href, 0, strpos($href, '?')); // Remove token
        $meta_link->setAttribute('href', DRUPAL_ROOT . $href);
      }
    }
  }


  private function getFilepath(string $path, string $name): string {
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

  private function transliterateFilename(string $name): string {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $new_value = \Drupal::transliteration()->transliterate($name, $current_language, '_');
    $new_value = trim(strtolower($new_value));
    $new_value = preg_replace('/[^a-z0-9_]+/', '_', $new_value);
    return preg_replace('/_+/', '_', $new_value);
  }

}
