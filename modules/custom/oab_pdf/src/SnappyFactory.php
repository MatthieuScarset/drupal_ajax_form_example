<?php

namespace Drupal\oab_pdf;

use Drupal\oab_pdf\Exception\SnappyNotFoundException;
use h4cc\WKHTMLToPDF\WKHTMLToPDF;
use Knp\Snappy\Pdf;
use Psr\Log\LoggerInterface;

class SnappyFactory {

  /**
   * @param \Psr\Log\LoggerInterface $logger
   */
  public function __construct(private LoggerInterface $logger) {}

  /**
   * @param \Psr\Log\LoggerInterface $logger
   *
   * @return \Knp\Snappy\Pdf
   * @throws \Drupal\oab_pdf\Exception\SnappyNotFoundException
   */
  public function get(LoggerInterface $logger): Pdf {
//    $bin_path = DRUPAL_ROOT . '/vendor/h4cc/wkhtmltopdf-amd64/bin/wkhtmltopdf-amd64';
    $bin_path = WKHTMLToPDF::PATH;
    if (file_exists($bin_path)) {
      ini_set('memory_limit', '-1');
      $snappy = new Pdf($bin_path);
      $snappy->setOption('quiet', true);
      $snappy->setOption('enable-local-file-access', true);
      $snappy->setLogger($logger);

      return $snappy;
    }

    $this->logger->critical("Cannot found Snappy executable at $bin_path");
    throw new SnappyNotFoundException($bin_path);
  }

}
