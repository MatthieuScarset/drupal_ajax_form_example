<?php

namespace Drupal\oab_pdf\Controller;

use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\node\NodeInterface;
use Drupal\oab_pdf\Exception\SnappyException;
use Drupal\oab_pdf\PdfGenerator\NodePdfGenerator;
use Psr\Container\ContainerInterface;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class NodePdfController extends ControllerBase implements ContainerInjectionInterface {

  public function __construct(private NodePdfGenerator $nodePdfGenerator,
                              private CacheBackendInterface $cacheBackend) {
  }

  public static function create(ContainerInterface $container) {
    return new self(
      $container->get('oab_pdf.node_pdf_generator'),
      $container->get('oab_pdf.pdf_cache')
    );
  }

  /**
   * @throws \Exception
   */
  public function getNodePdf(NodeInterface $node): Response {

    if ($node->bundle() !== "mss_article" || $node->field_typology?->value !== "article") {
      // Temporaire -- Si ce n'est pas un article MSS => 404 Not Found
      throw new NotFoundHttpException($this->t("Page not found"));
    }

    $cid = "node_pdf_{$node->id()}";
    try {
      if (($cached_data = $this->cacheBackend->get($cid)) !== false) {
        $content = $cached_data->data;
      } else {
        $content = $this->nodePdfGenerator->generatePdfContent($node);
        $this->cacheBackend->set($cid, $content, $node->getCacheMaxAge(), $node->getCacheTags());
      }
      return new Response(
        $content,
        headers: ['Content-type' => 'application/pdf']
      );
    } catch (SnappyException $e) {
      $this->getLogger('oab_pdf')->alert($e->getMessage());
    }

    // Si on est là, c'est qu'on n'a pas retourné le PDF plus haut. Retour en 400
    return new Response(
      $this->t("Something went wrong while generating PDF for @node.", ['@node' => $node->label()]),
      400
    );
  }
}
