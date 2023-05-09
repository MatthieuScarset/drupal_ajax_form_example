<?php

namespace Drupal\oab_pdf\PdfGenerator;

use Drupal\Component\Render\MarkupInterface;
use Drupal\Component\Utility\Html;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Extension\ExtensionList;
use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\Extension\ModuleExtensionList;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Render\RendererInterface;
use Drupal\node\NodeInterface;
use Drupal\oab_pdf\Exception\SnappyException;
use Drupal\oab_pdf\Exception\SnappyGeneratorException;
use Knp\Snappy\Pdf;

class NodePdfGenerator extends AbastractPdfGenerator implements PdfGeneratorInterface {
  public function __construct(protected Pdf                       $snappy,
                              protected FileSystemInterface       $fileSystem,
                              private RendererInterface           $renderer,
                              private EntityTypeManagerInterface  $entityTypeManager,
                              private ModuleExtensionList         $moduleExtensionList,
  ) {}

  /**
   * Generate PDF content
   *
   * @param \Drupal\node\NodeInterface $node
   *
   * @return string
   * @throws \Drupal\oab_pdf\Exception\SnappyGeneratorException
   */
  public function generatePdfContent(NodeInterface $node): string {

    try {
      return $this->snappy->getOutputFromHtml($this->getHtml($node), $this->getDefaultOptions($node));
    } catch (\Exception $e) {
      throw new SnappyGeneratorException($e);
    }
  }

  /**
   * Generate PDF File for given node
   *
   * @param \Drupal\node\NodeInterface $node
   * @param string|NULL $dir
   *
   * @return string
   * @throws \Drupal\oab_pdf\Exception\SnappyException
   * @throws \Drupal\oab_pdf\Exception\SnappyGeneratorException
   */
  public function generatePdfFile(NodeInterface $node, string $dir = null): string {
    $pdf_dir = $dir ?? $this->fileSystem->realpath('public://pdf_export');

    if ($this->fileSystem->prepareDirectory($pdf_dir, FileSystemInterface::CREATE_DIRECTORY)) {
      $path = $this->getFilepath($pdf_dir, $node->label());

      try {
        $this->snappy->generateFromHtml($this->getHtml($node), $path, $this->getDefaultOptions($node));
        return $path;
      } catch (\Exception $e) {
        throw new SnappyGeneratorException($e);
      }

    }
    throw new SnappyException("Cannot create output directory $pdf_dir while trying to generate PDF.");
  }

  /**
   * Return the HTML string for current Node
   *
   * @param \Drupal\node\NodeInterface $node
   *
   * @return string
   * @throws \DOMException
   */
  private function getHtml(NodeInterface $node): string {
    $build = $this->entityTypeManager
      ->getViewBuilder($node->getEntityTypeId())
      ->view($node, 'pdf');

    $markup = $this->renderer->renderRoot($build);
    $css_path = $this->fileSystem->realpath($this->moduleExtensionList->getPath('oab_pdf') . '/css/node.css');

    $html = Html::load($markup);
    $this->setHtmlTitle($html, $node->label());
    $this->correctHtml($html);
    $this->addCssFile($html, $css_path);

    return $html->saveHTML();
  }

  /**
   * Return default options for PDF generation
   *
   * @param \Drupal\node\NodeInterface $node
   *
   * @return array
   */
  private function getDefaultOptions(NodeInterface $node): array {

    return [
      'header-html' => $this->getTemplate('header', $node),
      'header-spacing' => 10,
      'footer-html' => $this->getTemplate('footer', $node),
      'footer-right' => "[page]/[topage]",
      'footer-font-size' => 7,
      'footer-spacing' => 10
    ];
  }

  /**
   * Get path for given template
   *
   * @param string $template_name
   * @param \Drupal\node\NodeInterface $node
   *
   * @return string
   */
  private function getTemplate(string $template_name, NodeInterface $node): string {
    $folder = $this->fileSystem->realpath($this->moduleExtensionList->getPath('oab_pdf') . '/templates/');

    return file_exists("$folder/_{$template_name}_{$node->bundle()}.html")
      ? "$folder/_{$template_name}__{$node->bundle()}.html"
      : "$folder/_{$template_name}__default.html";
  }

}
