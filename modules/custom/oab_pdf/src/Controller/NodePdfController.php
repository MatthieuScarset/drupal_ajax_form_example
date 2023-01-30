<?php

namespace Drupal\oab_pdf\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Render\RendererInterface;
use Drupal\node\NodeInterface;
use Drupal\oab_pdf\Services\OabPdfGeneratorService;
use Psr\Container\ContainerInterface;
use Symfony\Component\HttpFoundation\Response;

class NodePdfController extends ControllerBase implements ContainerInjectionInterface {

  public function __construct( protected OabPdfGeneratorService $oabPdfGeneratorService,
                               protected RendererInterface $renderer) {
  }

  public static function create(ContainerInterface $container) {
    return new self(
      $container->get('oab_pdf.pdf_generator'),
      $container->get('renderer')
    );
  }

  /**
   * @throws \Exception
   */
  public function getNodePdf(NodeInterface $node): Response {
    $build = $this->entityTypeManager()->getViewBuilder($node->getEntityTypeId())->view($node, 'pdf');
    $markup = $this->renderer->renderRoot($build);
    $content_response = $this->oabPdfGeneratorService->getOutput($markup, $node->label());
    dd([$build, $markup, $content_response]);
    $response = new Response($content_response);
    $response->headers->set('Content-Type', 'application/pdf');
    return $response;
  }

}
