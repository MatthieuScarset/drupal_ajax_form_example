<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_synomia_search_flux\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchFluxController extends ControllerBase
{

  /** Méthode appelée pour l'onglet Global Settings de la partie BO */
  public function viewFlux(Request $request){

		$response = new Response();
		$response->setContent($this->getSitemapSynomiaSimple());
		//$response->headers->set('Content-Type','text/xml');
		return $response;
  }

	private function getSitemapSynomiaSimple()
	{
		$contentTypes = array();


		//calcul de l'intervalle de temps à prendre en compte :
		// 1. on prend les contenus qui ont été modifiés il y a au moins 12h (pour que le cache Akamai soit rafraichi) :
		$timeFin = strtotime("-12 hours", time());
		// 2. on prend les contenus modifiés sur 48h (par rapport a la date précédente) :
		$timeDebut = strtotime("-48 hours", $timeFin);


		$xml_feed = $this->get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes);
		return $xml_feed;
	}

  private function getSitemapSynomiaByDates($debut, $fin)
	{
		$contentTypes = array();

		$startDate = DateTime::createFromFormat('Ymd H:i:s', $debut.'00:00:00');
		$timeDebut = $startDate->getTimestamp();

		$endDate = DateTime::createFromFormat('Ymd H:i:s', $fin.'23:59:59');
		$timeFin = $endDate->getTimestamp();

		$xml_feed = $this->get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes);
		return $xml_feed;
	}

	private function get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes)
	{
		$host = \Drupal::request()->getSchemeAndHttpHost();
		$current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

		/*
		$test = new SynomiaSearchContent();
		$test->setNid(139);
		$test->setContentType('test');
		$test->setDeleted(time());
		$test->setLanguage($current_language);
		$test->setUrl($host);
		$test->save();
		$test->delete();
		*/

		$xml_feed = '';
		// Création du flux XML
		$xml_feed .= '<?xml version=\'1.0\' encoding=\'utf-8\'?><urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">';
		$xml_feed .= '</urlset>';
		return "language: ".$current_language. " - debut: ".$timeDebut. ' - fin: '.$timeFin." - base url: ".$host." ".$xml_feed;
	}

}