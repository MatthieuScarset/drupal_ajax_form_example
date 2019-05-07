<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 30/08/2017
 * Time: 17:39
 */
namespace Drupal\oab_synomia_search_engine\Classes;

use Drupal\node\Entity\NodeType;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;

class SynomiaSearchResponse
{

    public $facets = array();
    public $degradations = array();
    public $corrections = array();
    public $nbResultsTotal = 0;
    public $results = array();
    public $currentPage = 0;
    PUBLIC $pager = null;
    public $searchMode = '';

    public function __construct() {

    }

    public function readXML($fluxXML, $rubrique) {
        if (!empty($fluxXML)) {
            $dom = new \DOMDocument();
            $dom->loadXML($fluxXML);

            //transfo du flux XML en objet lisible
            $xmlResult = new \SimpleXMLElement($fluxXML);

            //récupération de la categorisation des resultats = facets
            $this->getFacetsFromXml($dom);

            //corrections éventuelles
            if (isset($xmlResult->corrections) && isset($xmlResult->corrections->correction)) {
                $this->corrections = $xmlResult->corrections->correction;
            }

            //degradations de requete, uniquement si pas de résultats
            if (isset($xmlResult->degradations) && $xmlResult->estimatedTotalResultsCount == 0) {
                $this->getDegradationsFromXML($dom);
            }

            //nb de resultats total
            $this->nbResultsTotal = $xmlResult->estimatedTotalResultsCount;

            //resultats
            if (isset($xmlResult->cluster) || empty($rubrique)) {
                $this->searchMode = "global";
                $this->getResultsClustersArray($dom);
            } else {
                //filtré sur une rubrique particuliere
                $this->searchMode = "rubrique";
                $this->getResultsSimpleArray($xmlResult, $rubrique);

                //Pager
                $config_factory = \Drupal::configFactory();
                $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
                if (!empty($config) && !empty($config->get('nb_results_per_page'))) {
                    $nbResultsPerPage = $config->get('nb_results_per_page');
                } else {
                    $nbResultsPerPage = 10; // 10 par défaut si aucune configuration
                }

                $this->currentPage = pager_default_initialize($xmlResult->estimatedTotalResultsCount, $nbResultsPerPage);
                //$this->pager = theme('pager');
            }
        }
    }

    /**
     * En mode Simple
     * @param unknown $dom
     * @return Ambigous <multitype:multitype: , multitype:NULL >
     */
    private function getResultsSimpleArray($xmlResult, $type) {
        $clusterArray = array();
        if ( $type != "#SYNAUTRE#") {
            $clusterArray['typeId'] = $type;
            $clusterArray['typeName'] = $this->getTypeLabel($type);
            $clusterArray['nbResults'] = $this->nbResultsTotal;
            $clusterArray['results'] = array();
            if (isset($xmlResult->resultElements) && isset($xmlResult->resultElements->item)) {
                foreach ($xmlResult->resultElements->item as $item) {
                    $myItem = array();
                    $myItem['title'] = $item->extitle;
                    $myItem['URL'] = $item->URL;
                    $myItem['description'] = $item->description;
                    $clusterArray['results'][] = $myItem;
                }
            }
            $this->results[$type] = $clusterArray;
        }
    }

    /**
     * En mode Cluster
     * @param unknown $dom
     * @return Ambigous <multitype:multitype: , multitype:NULL >
     */
    public function getResultsClustersArray($dom) {
        $cluster = $dom->getElementsByTagName("cluster");
        if (isset($cluster)) {
            $clusterArray = array();
            $cluster = $cluster->item(0);
            if (isset($cluster)) {
                $aspects = $cluster->getElementsByTagName("aspect");
                foreach ($aspects as $aspect) {
                    $type = $aspect->getAttribute('value');
                    if ( $type != "#SYNAUTRE#") {
                        $clusterArray['typeId'] = $type;
                        $clusterArray['typeName'] = $this->getTypeLabel($type);
                        $clusterArray['nbResults'] = $aspect->getAttribute('nb_res');

                        $items = $aspect->getElementsByTagName("item");
                        $clusterArray['results'] = array();
                        foreach ($items as $item) {
                            $myItem = array();
                            if ($item->getElementsByTagName("extitle")->length > 0) {
                                $myItem['title'] = $item->getElementsByTagName("extitle")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("URL")->length > 0) {
                                $myItem['URL'] = $item->getElementsByTagName("URL")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("description")->length > 0) {
                                $myItem['description'] = $item->getElementsByTagName("description")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("rubrique")->length > 0) {
                                $myItem['rubrique'] = $item->getElementsByTagName("rubrique")
                                    ->item(0)->nodeValue;
                            }
                            $clusterArray['results'][] = $myItem;
                        }
                        $this->results[$type] = $clusterArray;
                    }
                }
            }
            //oabt($this->results, true);
        }
    }

    /**
     * Lit le XML pour en déduire le tableau des facettes avec facet id => nb resultats
     * @param unknown $flux
     */
    private function getFacetsFromXml($dom) {
        //oabt($dom, true);
        $facetsTag = $dom->getElementsByTagName("facets");
        if (isset($facetsTag)) {
            $facetsTag = $facetsTag->item(0);
            if (isset($facetsTag)) {
                $facets = $facetsTag->getElementsByTagName("aspect");
                foreach ($facets as $facet) {
                    if ( $facet->firstChild->nodeValue != "#SYNAUTRE#") {
                        $this->facets[str_replace(' ','_',$facet->firstChild->nodeValue)] = array('facetName' => $this->getTypeLabel(str_replace(' ','_',$facet->firstChild->nodeValue)), 'nbresults' => $facet->getAttribute('nb_res'));
                    }
                }
            }
        }
    }


    /**
     * Lit le XML pour en déduire les dégradations de requête
     * @param unknown $flux
     */
    private function getDegradationsFromXML($dom) {
        $degradationsTag = $dom->getElementsByTagName("degradations");
        if (isset($degradationsTag)) {
            $degradationsTag = $degradationsTag->item(0);
            if (isset($degradationsTag)) {
                $degradations = $degradationsTag->getElementsByTagName("degradation");
                foreach ($degradations as $degradation) {
                    $this->degradations[$degradation->getAttribute('combi')] = $degradation->nodeValue;
                }
            }
        }
    }

    /** Retourne le libellé du Type passé en paramètre
     * @param $type_id
     */
    private function getTypeLabel($type_id) {
        $typeName = "";
        switch ($type_id) {
            case 'full_html':
                $typeName = 'Content';
                break;
            case 'simple_page':
                $typeName = 'Article';
                break;
            default:
                $typeObject = NodeType::load($type_id);
                if (isset($typeObject) && !empty($typeObject)) {
                    $typeName = $typeObject->label();
                }

        }
        return $typeName;
    }
}

