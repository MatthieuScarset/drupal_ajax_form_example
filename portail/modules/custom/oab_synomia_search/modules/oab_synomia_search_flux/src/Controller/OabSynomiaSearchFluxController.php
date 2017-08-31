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
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchFluxController extends ControllerBase
{

  /** Méthode appelée pour l'onglet Global Settings de la partie BO */
  public function viewFlux(Request $request){

		$response = new Response();
		$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
		if(empty($parameters))
		{
			$response->setContent($this->getSitemapSynomiaSimple());
		}
		elseif (isset($parameters['startDate']) && isset($parameters['endDate']))
		{
			if(isValidDate($parameters['startDate'],'Ymd') && isValidDate($parameters['endDate'],'Ymd'))
			{
				$response->setContent($this->getSitemapSynomiaByDates($parameters['startDate'], $parameters['endDate']));
			}
		}
		else{
			throw new NotFoundHttpException();
		}
		$response->headers->set('Content-Type','text/xml');
		return $response;
  }


	private function getSitemapSynomiaSimple()
	{
		$contentTypes = $this->getContentTypeToIndex();

		//calcul de l'intervalle de temps à prendre en compte :
		// 1. on prend les contenus qui ont été modifiés il y a au moins 12h (pour que le cache Akamai soit rafraichi) :
		$timeFin = strtotime("-12 hours", time());
		//$timeFin =  time(); // pour les tests
		// 2. on prend les contenus modifiés sur 48h (par rapport a la date précédente) :
		$timeDebut = strtotime("-48 hours", $timeFin);

		$xml_feed = $this->get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes);
		return $xml_feed;
	}

  private function getSitemapSynomiaByDates($debut, $fin)
	{
		$contentTypes = $this->getContentTypeToIndex();

		$startDate = \DateTime::createFromFormat('Ymd H:i:s', $debut.'00:00:00');
		$timeDebut = $startDate->getTimestamp();

		$endDate = \DateTime::createFromFormat('Ymd H:i:s', $fin.'23:59:59');
		$timeFin = $endDate->getTimestamp();

		$xml_feed = $this->get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes);
		return $xml_feed;
	}

	private function get_sitemap_synomia_by_dates($timeDebut, $timeFin, $contentTypes)
	{
		$base_url = \Drupal::request()->getSchemeAndHttpHost();
		$current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

		$xml_feed = '';
		// Création du flux XML
		$xml_feed .= '<?xml version=\'1.0\' encoding=\'utf-8\'?><urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">';

		//On prend les éléments supprimés
		$query = Database::getConnection()->select('synomia_deleted_content', 's');
		$query->condition('s.content_type', $contentTypes, 'IN');
		$query->condition('s.language', array($current_language, 'und'), 'IN');
		$query->condition('s.deleted', array($timeDebut, $timeFin), 'BETWEEN');
		$query->fields('s');
		$results_deleted = $query->execute()->fetchAll();

		foreach($results_deleted as $deleted){
			$xml_feed .= '<url>
					<loc><![CDATA['.$base_url.'/'.$current_language. $deleted->url.']]></loc>
					<lastmod><![CDATA['.date("Y-m-d H:i",$deleted->deleted).']]></lastmod>
					<changefreq>daily</changefreq>
    			<priority>1</priority>
				</url>';
		}

		//Noeuds qui ont été ajoutés ou modifiés
		$query_nodes = Database::getConnection()->select('node_field_data', 'n');
		$query_nodes->condition('n.type', $contentTypes, 'IN');
		$query_nodes->condition('n.status', 1, '=');
		$query_nodes->condition('n.langcode', array($current_language, 'und'), 'IN');
		$query_nodes->condition('n.changed', array($timeDebut, $timeFin), 'BETWEEN');
		$query_nodes->fields('n', array('nid', 'langcode', 'changed'));
		$results_nodes = $query_nodes->execute()->fetchAll();

		foreach($results_nodes as $node){
			$alias = \Drupal::service('path.alias_manager')->getAliasByPath('/node/' .$node->nid, $node->langcode);
			if($node->language == 'und')
			{
				$xml_feed .= '<url>
							<loc><![CDATA['.$base_url. '/'.$current_language.$alias.']]></loc>
							<lastmod><![CDATA['.date("Y-m-d H:i",$node->changed).']]></lastmod>
							<changefreq>daily</changefreq>
							<priority>1</priority>
						</url>';
			}
			else
			{
				$xml_feed .= '<url>
							<loc><![CDATA['.$base_url. '/'.$node->langcode.$alias.']]></loc>
							<lastmod><![CDATA['.date("Y-m-d H:i",$node->changed).']]></lastmod>
							<changefreq>daily</changefreq>
							<priority>1</priority>
						</url>';
			}
		}
		$xml_feed .= '</urlset>';
		return $xml_feed;
	}

	/** Retourne la liste des types de contenus à indexer (dans la config)
	 * @return array
	 */
	private function getContentTypeToIndex(){
  	$types = array();
		$config_factory = \Drupal::configFactory();
		//on récupère la configuration oab.synomia.contentTypes
		$config = $config_factory->get('oab.synomia.contentTypes');
		//on charge la liste des types de contenus
		$contentTypes = \Drupal::service('entity.manager')->getStorage('node_type')->loadMultiple();
		foreach ($contentTypes as $contentType) {
			$value = $config->get($contentType->id());
			if(isset($value) && $value == "1")
			{
				$types[] = $contentType->id();
			}
		}
		//oabt($types);die();
		return $types;
	}

}