<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_synomia_search_flux\Controller;


use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Drupal\oab_synomia_search_flux\Classes\SynomiaFluxService;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchFluxController extends ControllerBase {

  /**
   * @var SynomiaFluxService
   */
  private SynomiaFluxService $synomiaFluxService;

  public function __construct(SynomiaFluxService $synomiaFluxService) {
    $this->synomiaFluxService = $synomiaFluxService;
  }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('oab_synomia_search_flux.flux_service')
    );
  }


  /** Méthode appelée lorsqu'on va sur le flux XML Synomia
   *
   * @param \Symfony\Component\HttpFoundation\Request $request
   *
   * @return \Symfony\Component\HttpFoundation\Response
   */
  public function viewFlux(Request $request) {
    $response = new Response();
    $dates = $this->getDates($request);
    if(count($dates) > 0) {
      $xml_feed = $this->synomiaFluxService->getSitemapToIndexBySynomia($dates['start'], $dates['end']);
      $response->setContent($xml_feed);
    }
    else {
      throw new NotFoundHttpException();
    }
    $response->headers->set('Content-Type', 'text/xml');
    return $response;
  }

  public function viewDeletedContentFlux(Request $request) {
    $response = new Response();
    $dates = $this->getDates($request);
    if(count($dates) > 0) {
      $xml_feed = $this->synomiaFluxService->getSitemapToDeleteBySynomia($dates['start'], $dates['end']);
      $response->setContent($xml_feed);
    }
    else {
      throw new NotFoundHttpException();
    }
    $response->headers->set('Content-Type', 'text/xml');
    return $response;
  }

  private function getDates(Request $request) {
    $parameters = $request->query->all();
    $dates = [];
    if (empty($parameters) || !(isset($parameters['startDate']) && isset($parameters['endDate']))) {
      /*
       * Pas de date en paramètre : on calcul l'intervale à prendre en compte :
       * 1. contenus qui ont été modifiés il y a au moins 12h (pour que le cache Akamai soit rafraichi)
       * 2. contenus modifiés sur 48h (par rapport a la date précédente)
       */
      //$time_fin = time();
      $dates['end'] = strtotime("-12 hours", time());
      $dates['start'] = strtotime("-48 hours", $dates['end']);
    }
    elseif (isset($parameters['startDate']) && isset($parameters['endDate'])) {
      if (isValidDate($parameters['startDate'], 'Ymd') && isValidDate($parameters['endDate'], 'Ymd')) {
        $dates['start'] = \DateTime::createFromFormat('Ymd H:i:s', $parameters['startDate'] . '00:00:00')
          ->getTimestamp();
        $dates['end'] = \DateTime::createFromFormat('Ymd H:i:s', $parameters['endDate'] . '23:59:59')
          ->getTimestamp();
      }
    }
    return $dates;
  }

}
