<?php

namespace Drupal\oab_synomia_search_engine\Controller;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchEngineController extends ControllerBase
{

  /** Méthode appelée lorsqu'on appelle la page de recherche */
  public function contentSearch(Request $request){
		$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
		$mot_recherche = (!empty($parameters) && isset($parameters['mot'])) ? $parameters['mot'] : '';
		$filtre_rubrique = (!empty($parameters) && isset($parameters['rubrique'])) ? $parameters['rubrique'] : '';
		$numPage = (!empty($parameters) && isset($parameters['page'])) ? $parameters['page'] : '';

		$results = $this->getSynomiaResult($mot_recherche, $filtre_rubrique, $numPage, '');
		var_dump($results);
		if(empty($results))
		{
			$erreur = "erreur pas de resultat";
		}
		else{

		}

		$searchForm = \Drupal::formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchEngineForm');

		return array(
			//'#mapBlock' => $mapBlock,
			//'#officesListBlock' => $officesListBlock,
			'#searchForm' => $searchForm,
			'#searchResults' => array(),
			//'#labelList' => $listLabel,
			'#theme' => 'synomia_search_results_page',
			'#attached' => array(
		//		'library' =>  array(
		//			'oab_offices_map/oab_offices_map.markers'
		//		),
		//		'drupalSettings' =>  array(
		//			'countriesRegionsTab' => $this->getArrayRegionsCountries(),
		//		),
			),
		);
  }

  private function getSynomiaResult($mot_recherche, $filtre_rubrique, $numPage, $sortBy){
		$current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
		$urlSynomia = \Drupal::state()->get('url_synomia_'.$current_language);
		if(!empty($urlSynomia))
		{
			$path = $urlSynomia;
			if ($current_language == 'ru') {
				$path .= "&exactSearch=" . urlencode($mot_recherche) . "&sortBy=" . $sortBy . "&nbCoocDisplay=5";
			}
			else {
				$path .= "&q=" . urlencode($mot_recherche) . "&sortBy=" . $sortBy . "&nbCoocDisplay=5";
			}

			//on récupère le nb de résultats par page
			$config_factory = \Drupal::configFactory();
			$config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
			if(!empty($config) && !empty($config->get('nb_results_per_page')))
			{
				$nbResultsPerPage = $config->get('nb_results_per_page');
			}
			else{
				$nbResultsPerPage = 10; // 10 par défaut si aucune configuration
			}

			if(isset($numPage) && !empty($numPage)){
				$offset = $numPage * $nbResultsPerPage;
				$path .= "&offsetDisplay=".$offset;
			}

			//on ajoute les facettes
			$path .= "&sortie=facette";

			//filtre sur le type de contenu
			if(!isset($filtre_rubrique) || empty($filtre_rubrique))
			{
				//$path .= "&cluster=rubrique"; //sur D7
				$path .= "&sortie=facette";
			}
			else
			{
				$path .= "&filtres[]=rubrique:".$filtre_rubrique;
			}

			$ch = curl_init();
/*
			$proxy_server =  variable_get('proxy_server', null);
			if ($proxy_server != null) {
				$proxy_server .= ':' . variable_get('proxy_port', '');
			}
			*/
			$proxy_server = null;
			//var_dump($path);
			curl_setopt_array
			(
				$ch,
				array
				(
					CURLOPT_CONNECTTIMEOUT => 2,
					CURLOPT_TIMEOUT => 5,
					CURLOPT_PROXY => $proxy_server,
					CURLOPT_SSLVERSION => 0,
					CURLOPT_HEADER => false,
					CURLOPT_RETURNTRANSFER => true,
					CURLOPT_URL => $path,
				)
			);
			$retValue = curl_exec($ch);
			curl_close($ch);
			return $retValue;
		}
		else{
			return null;
		}
	}
}