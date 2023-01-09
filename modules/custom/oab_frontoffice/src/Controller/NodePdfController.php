<?php

namespace Drupal\oab_frontoffice\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\node\NodeInterface;
use Symfony\Component\HttpFoundation\Response;

class NodePdfController extends ControllerBase {


  /**
   * @throws \Exception
   */
  public function getNodePdf(NodeInterface $node): Response {
    /** @var \Drupal\oab_frontoffice\Services\OabPdfGeneratorService $pdf_generator */
    $pdf_generator = \Drupal::service('oab_frontoffice.pdf_generator');


    /** @var \Drupal\Core\Render\Renderer $renderer */
    $renderer = \Drupal::service('renderer');
    $build = $this->entityTypeManager()->getViewBuilder($node->getEntityTypeId())->view($node);


    $response = new Response($pdf_generator->getOutput($renderer->renderRoot($build), $node->label()));
    $response->headers->set('Content-Type', 'application/pdf');

    return $response;
  }

}
