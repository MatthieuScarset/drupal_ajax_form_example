<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_synomia_search_flux\Controller;


use Drupal\Core\Controller\ControllerBase;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchFluxController extends ControllerBase
{

  /** Méthode appelée pour l'onglet Global Settings de la partie BO */
  public function viewFlux(Request $request){

		$response = new Response();
		$response->setContent("");
		$response->headers->set('Content-Type','text/xml');
		return $response;
/*
    $imports = $biObj->getBackbonesImportTable()->fetchAll();


    return array(
      '#lastsImports' => $imports,
      '#documentation' => $pathDoc,
      '#variablesForm' => $form,
      '#theme' => 'backbones_global_settings'
    );*/
  }

  private function getSitemapSynomiaByDates($debut, $fin)
	{
		$contentTypes = array();

		$startDate = DateTime::createFromFormat('Ymd H:i:s', $debut.'00:00:00');
		$timeDebut = $startDate->getTimestamp();

		$endDate = DateTime::createFromFormat('Ymd H:i:s', $fin.'23:59:59');
		$timeFin = $endDate->getTimestamp();

		$xml_feed = $this->get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes);
	}

	private function get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes)
	{

	}

}