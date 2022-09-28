<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 30/08/2017
 * Time: 17:39
 */
namespace Drupal\oab_synomia_search_engine\Classes;

use Drupal\Core\Entity\EntityFieldManager;
use Drupal\Core\Entity\EntityFieldManagerInterface;
use Drupal\Core\Pager\PagerManagerInterface;
use Drupal\node\Entity\NodeType;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;
use Symfony\Component\DependencyInjection\ContainerInterface;

class SynomiaSearchResponse {

    public $facets = array();
    public $degradations = array();
    public $corrections = array();
    public $nbResultsTotal = 0;
    public $results = array();
    public $currentPage = 0;
    PUBLIC $pager = null;
    public $searchMode = '';


  public function __construct(
    private PagerManagerInterface $pagerManager,
    private EntityFieldManagerInterface $entityFieldManager,
    private $typeSearch = 'default'
  ) {

  }

  public function getTypeSearch() {
    return $this->typeSearch;
  }

    public function readXML($flux_xml, $rubrique) {
        if (!empty($flux_xml)) {
            $dom = new \DOMDocument();
            $dom->loadXML($flux_xml);

            //transfo du flux XML en objet lisible
            $xml_result = new \SimpleXMLElement($flux_xml);

            //récupération de la categorisation des resultats = facets
            $this->getFacetsFromXml($dom);

            //corrections éventuelles
            if (isset($xml_result->corrections) && isset($xml_result->corrections->correction)) {
                $this->corrections = $xml_result->corrections->correction;
            }

            //degradations de requete, uniquement si pas de résultats
            if (isset($xml_result->degradations) && $xml_result->estimatedTotalResultsCount == 0) {
                $this->getDegradationsFromXML($dom);
            }

            //nb de resultats total
            $this->nbResultsTotal = $xml_result->estimatedTotalResultsCount;

            //resultats
            if (isset($xml_result->cluster) || empty($rubrique)) {
                $this->searchMode = "global";
                $this->getResultsClustersArray($dom);
            } else {
                //filtré sur une rubrique particuliere
                $this->searchMode = "rubrique";
                $this->getResultsSimpleArray($xml_result, $rubrique);

                //Pager
                $config_factory = \Drupal::configFactory();
                $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
                if (!empty($config) && !empty($config->get('nb_results_per_page'))) {
                    $nb_results_per_page = $config->get('nb_results_per_page');
                } else {
                    $nb_results_per_page = 10; // 10 par défaut si aucune configuration
                }

                $this->current_page = $this->pagerManager->createPager((int) $xml_result->estimatedTotalResultsCount, $nb_results_per_page);
                $this->current_page->getCurrentPage();
                //$this->pager = theme('pager');
            }
        }
    }

    /**
     * En mode Simple
     * @param unknown $dom
     * @return Ambigous <multitype:multitype: , multitype:NULL >
     */
    private function getResultsSimpleArray($xml_result, $type) {
        $cluster_array = array();
        if ($type != "#SYNAUTRE#") {
            $cluster_array['typeId'] = $type;
            $cluster_array['typeName'] = $this->getTypeLabel($type);
            $cluster_array['nbResults'] = $this->nbResultsTotal;
            $cluster_array['results'] = array();
            if (isset($xml_result->resultElements) && isset($xml_result->resultElements->item)) {
                foreach ($xml_result->resultElements->item as $item) {
                    $my_item = array();
                    $my_item['title'] = $item->extitle;
                    $my_item['URL'] = $item->URL;
                    $my_item['description'] = $item->description;
                    $cluster_array['results'][] = $my_item;
                }
            }
            $this->results[$type] = $cluster_array;
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
            $cluster_array = array();
            $cluster = $cluster->item(0);
            if (isset($cluster)) {
                $aspects = $cluster->getElementsByTagName("aspect");
                foreach ($aspects as $aspect) {
                    $type = $aspect->getAttribute('value');
                    if ($type != "#SYNAUTRE#") {
                        $cluster_array['typeId'] = $type;
                        $cluster_array['typeName'] = $this->getTypeLabel($type);
                        $cluster_array['nbResults'] = $aspect->getAttribute('nb_res');

                        $items = $aspect->getElementsByTagName("item");
                        $cluster_array['results'] = array();
                        foreach ($items as $item) {
                            $my_item = array();
                            if ($item->getElementsByTagName("extitle")->length > 0) {
                                $my_item['title'] = $item->getElementsByTagName("extitle")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("URL")->length > 0) {
                                $my_item['URL'] = $item->getElementsByTagName("URL")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("description")->length > 0) {
                                $my_item['description'] = $item->getElementsByTagName("description")
                                    ->item(0)->nodeValue;
                            }
                            if ($item->getElementsByTagName("rubrique")->length > 0) {
                                $my_item['rubrique'] = $item->getElementsByTagName("rubrique")
                                    ->item(0)->nodeValue;
                            }
                            $cluster_array['results'][] = $my_item;
                        }
                        $this->results[$type] = $cluster_array;
                    }
                }
            }
        }
    }

    /**
     * Lit le XML pour en déduire le tableau des facettes avec facet id => nb resultats
     * @param unknown $flux
     */
    private function getFacetsFromXml($dom) {
        $facets_tag = $dom->getElementsByTagName("facets");
        if (isset($facets_tag)) {
            $facets_tag = $facets_tag->item(0);
            if (isset($facets_tag)) {
                $facets = $facets_tag->getElementsByTagName("aspect");
                foreach ($facets as $facet) {
                    if ($facet->firstChild->nodeValue != "#SYNAUTRE#") {
                        $this->facets[str_replace(' ', '_', $facet->firstChild->nodeValue)] = array('facetName' => $this->getTypeLabel(str_replace(' ', '_', $facet->firstChild->nodeValue)), 'nbresults' => $facet->getAttribute('nb_res'));
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
        $degradations_tag = $dom->getElementsByTagName("degradations");
        if (isset($degradations_tag)) {
            $degradations_tag = $degradations_tag->item(0);
            if (isset($degradations_tag)) {
                $degradations = $degradations_tag->getElementsByTagName("degradation");
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
        $type_name = $type_id;
        if($this->typeSearch === 'mss') {
          /**
           * @var \Drupal\Core\Field\FieldDefinitionInterface[]
           */
          $bundle_fields = $this->entityFieldManager->getFieldDefinitions('node', 'mss_article');
          $types_mss = $bundle_fields['field_typology']?->getSetting("allowed_values");
          if(isset($types_mss[$type_id]) && is_string($types_mss[$type_id])) {
            return ucfirst($types_mss[$type_id]);
          }
        }
        else {
          switch ($type_id) {
            case 'full_html':
              $type_name = 'Content';
              break;
            case 'simple_page':
              $type_name = 'Article';
              break;
            default:
              $type_object = NodeType::load($type_id);
              if (isset($type_object) && !empty($type_object)) {
                $type_name = $type_object->label();
              }

          }
        }
        return $type_name;
    }


  /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
   * @param $old_facets_array
   * @return array
   */
  public function getOrderedFacetsArray() {
    $old_facets_array = $this->facets;
    $new_facets_array_ordered = array();
    $content_types = $this->getOrderContentTypesArray();
    if (!empty($content_types)) {
      foreach ($content_types as $contentType) {
        if( isset($old_results_array[$contentType])) {
          $new_facets_array_ordered[$contentType] = $old_facets_array[$contentType];
          unset($old_facets_array[$contentType]);
        }
      }
      return array_merge($new_facets_array_ordered, $old_facets_array);
    }
    return $old_facets_array;
  }

  /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
   * @param $old_facets_array
   * @return array
   */
  public function getOrderedResultsArray() {
    $old_results_array = $this->results;
    $new_results_array_ordered = array();
    $content_types = $this->getOrderContentTypesArray();
    if (!empty($content_types)) {
      foreach ($content_types as $contentType) {
        if( isset($old_results_array[$contentType])) {
          $new_results_array_ordered[$contentType] = $old_results_array[$contentType];
          unset($old_results_array[$contentType]);
        }
      }
      return array_merge($new_results_array_ordered, $old_results_array);
    }
    return $old_results_array;
  }

  private function getOrderContentTypesArray() {
    $content_types = array();
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    //on récupère le nb de résultats par page
    $config_factory = \Drupal::configFactory();
    $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
    if (!empty($config) && !empty($config->get('order_content_types_'.$current_language))) {
      $order_string = "";
      if ($this->typeSearch == 'mss'){
        $order_string = $config->get('order_typology_mss_assistance');
      }
      else {
        $order_string = $config->get('order_content_types_' . $current_language);
      }
      if (!empty($order_string)) {
        $tmp_content_types = explode(',', $order_string);
        foreach ($tmp_content_types as $tmp) {
          $content_types[$tmp] = trim($tmp);
        }
      }
    }
    return $content_types;
  }

}

