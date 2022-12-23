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

class NodeCallback implements TrustedCallbackInterface {

  public static function trustedCallbacks() {
    return ['postRender'];
  }

  public function generatePdf(MarkupInterface $markup, $build) {

    /** @var \Drupal\Core\File\FileSystemInterface $file_system */
    $file_system = \Drupal::service('file_system');
    $pdf_dir = $file_system->realpath('public://pdf_export');
    $bin_path = DRUPAL_ROOT . '/vendor/h4cc/wkhtmltopdf-amd64/bin/wkhtmltopdf-amd64';

    if (file_exists($bin_path)
      && $file_system->prepareDirectory($pdf_dir, FileSystemInterface::CREATE_DIRECTORY)) {
      ini_set('memory_limit', '-1');
      $snappy = new Pdf($bin_path);
      $snappy->setOption('quiet', true);
      $snappy->setLogger(\Drupal::logger('snappy_pdf'));
      $html = Html::load($markup);

      /** @var \DOMElement $img */
      foreach ($html->getElementsByTagName('img') as $img) {
        $src = $img->getAttribute('src');

        $src = substr($src, 0, strpos($src, '?')); // Remove token
        $src = str_replace('/sites/default/files', 'public://', $src); // Create file URI;
        $img->setAttribute('src', $file_system->realpath($src));
      }

      /** @var \DOMElement $meta_link */
      foreach ($html->getElementsByTagName('link') as $meta_link) {
        if ($meta_link->hasAttribute('rel') && $meta_link->getAttribute('rel') === 'stylesheet') {
          $href = $meta_link->getAttribute('href');
          $href = substr($href, 0, strpos($href, '?')); // Remove token
          $meta_link->setAttribute('href', DRUPAL_ROOT . $file_system->realpath($href));
        }
      }

      try {
        $snappy->generateFromHtml($html->saveHTML(), $pdf_dir . "/" . self::getPdfName($build['#node']));
      } catch (\Exception $e) {
        echo ($e->getMessage());
      }
    }
    return $markup;
  }

  private static function getPdfName(NodeInterface $node): string {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $new_value = \Drupal::transliteration()->transliterate($node->getTitle(), $current_language, '_');
    $new_value = strtolower($new_value);
    $new_value = preg_replace('/[^a-z0-9_]+/', '_', $new_value);
    return preg_replace('/_+/', '_', $new_value) . '.pdf';
  }

}
