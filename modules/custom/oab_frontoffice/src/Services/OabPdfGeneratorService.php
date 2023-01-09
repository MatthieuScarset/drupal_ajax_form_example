<?php

namespace Drupal\oab_frontoffice\Services;

use Drupal\Component\Render\MarkupInterface;
use Drupal\Component\Utility\Html;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Render\Markup;
use Drupal\Core\Security\TrustedCallbackInterface;
use Drupal\migrate\Plugin\migrate\process\MachineName;
use Drupal\node\NodeInterface;
use Knp\Snappy\Pdf;

class OabPdfGeneratorService {

  private FileSystemInterface $fileSystem;

  public function __construct() {
    $this->fileSystem = \Drupal::service('file_system');
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

    $header = <<<HTML
<!DOCTYPE html>
<html>
  <head><style>body{ text-align: center }</style></head>
  <body>My Service Space</body>
</html>
HTML;

    $footer = <<<HTML
<!DOCTYPE html>
<html>
    <head><style>body {text-align: center}</style></head>
    <body>[title] - Generated at [date]</body>
</html>
HTML;

    $pager = "[title] - [page]/[topage]";

    return $snappy->getOutputFromHtml($this->correctHtml($markup, $title), [
      'header-html' => $header,
      'footer-html' => str_replace(['[title]', '[date]'], [$title, date('d/m/Y')], $footer),
      'footer-right' => $pager,
      'header-line' => true,
      'footer-line' => true
    ]);
  }

  public function generatePdfFile(MarkupInterface|String $markup, $name, string $dir = null): string {
    $pdf_dir = $dir ?? $this->fileSystem->realpath('public://pdf_export');

    if ($this->fileSystem->prepareDirectory($pdf_dir, FileSystemInterface::CREATE_DIRECTORY)) {
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

    return $html->saveHTML();
  }

  private function correctImgSrc(\DOMDocument &$html) {
    /** @var \DOMElement $img */
    foreach ($html->getElementsByTagName('img') as $img) {
      $src = $img->getAttribute('src');

      $src = substr($src, 0, strpos($src, '?') ?: strlen($src)); // Remove token
      $src = str_replace('/sites/default/files', 'public://', $src); // Create file URI
      if (file_exists($this->fileSystem->realpath($src))) {
        $img->setAttribute('src', $this->fileSystem->realpath($src));
      } else {
        $img->parentNode->removeChild($img);
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
