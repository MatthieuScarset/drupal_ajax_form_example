<?php

namespace Drupal\oab_synomia_search_engine\Controller;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Drupal\oab_synomia_search_engine\Classes\SynomiaSearchResponse;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchEngineController extends ControllerBase
{

    public function getPageTitle() {
        return t('Search results');
    }

  /** Méthode appelée lorsqu'on appelle la page de recherche */
  public function contentSearch(Request $request) {
        $render_array = array();
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
        $mot_recherche = (!empty($parameters) && isset($parameters['mot'])) ? $parameters['mot'] : '';
        $filtre_rubrique = (!empty($parameters) && isset($parameters['rubrique'])) ? $parameters['rubrique'] : '';
        $numPage = (!empty($parameters) && isset($parameters['page'])) ? $parameters['page'] : '';

        $searchForm = \Drupal::formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchEngineForm');

        if (!empty($mot_recherche))    {
            $result = $this->getSynomiaResult($mot_recherche, $filtre_rubrique, $numPage, '');
            if (isset($result) && !empty($result)) {
                $response = new SynomiaSearchResponse();
                $response->readXML($result, $filtre_rubrique);

                if ($response->nbResultsTotal > 0) {

                    if ($response->searchMode == 'rubrique') {
                        $page = pager_default_initialize($response->nbResultsTotal, 10);
                    }
                    $resultLabel = '';
                    if ($current_language != 'ru') {
                        if (count($response->nbResultsTotal) == 1) {
                            $resultLabel = $response->nbResultsTotal . ' ' . t('result') . ' ' . t('for');
                        } elseif (count($response->nbResultsTotal) > 1) {
                            $resultLabel = $response->nbResultsTotal . ' ' . t('results') . ' ' . t('for');
                        }
                    } else {
                        $rest = $response->nbResultsTotal;
                        if ($rest > 9) {
                            $rest = $response->nbResultsTotal % 10;
                        }
                        switch ($rest) {
                            case 0:
                                $resultLabel = t('Найдено %nbResults результатов по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 1:
                                $resultLabel = t('Найден %nbResults результат по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 2:
                            case 3:
                            case 4:
                                $resultLabel = t('Найдено %nbResults результата по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                $resultLabel = t('Найдено %nbResults результатов по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                        }
                    }
                }

                //kint($response->facets);
                $response->facets = $this->orderFacetsArray($response->facets);
                $response->results = $this->orderResultsArray($response->results);

                $render_array[] = array(
                    '#searchForm' => $searchForm,
                    '#resultLabel' => $resultLabel,
                    '#searchResults' => $response->results,
                    '#currentPage' => $response->current_page,
                    '#facets' => $response->facets,
                    '#searchMode' => $response->searchMode,
                    '#pager' => $response->pager,
                    '#corrections' => $response->corrections,
                    '#degradations' => $response->degradations,
                    '#nbResults' => $response->nbResultsTotal,
                    '#currentSearch' => $mot_recherche,
                    '#theme' => 'synomia_search_results_page',
                    '#attached' => array(
                        'library' => array(
                            'oab_synomia_search_engine/oab_synomia_search_engine.global',
                        ),
                        'drupalSettings' => array(
                            'tealium' => array(
                                'type_page' => 'Recherche',
                                'titre_page' => t('Résultats de recherche')
                            ),
                        )
                    ),
                );
                $render_array[] = ['#type' => 'pager'];
            } else {
                //pas de résultat de Synomia
                $render_array[] = array(
                    '#searchForm' => $searchForm,
                    '#nbResults' => 0,
                    '#resultLabel' => t('Error with search engine'),
                    '#currentSearch' => $mot_recherche,
                    '#theme' => 'synomia_search_results_page',
                    '#attached' => array(
                        'library' => array(
                            'oab_synomia_search_engine/oab_synomia_search_engine.global',
                        ),
                        'drupalSettings' => array(
                            'tealium' => array(
                                'type_page' => 'Recherche',
                                'titre_page' => t('Résultats de recherche')
                            ),
                        )
                    ),
                );
            }
        } else {
            //
            $render_array[] = array(
                '#searchForm' => $searchForm,
                '#nbResults' => 0,
                '#currentSearch' => $mot_recherche,
                '#theme' => 'synomia_search_results_page',
                '#attached' => array(
                    'library' => array(
                        'oab_synomia_search_engine/oab_synomia_search_engine.global',
                    ),
                    'drupalSettings' => array(
                        'tealium' => array(
                            'type_page' => 'Recherche',
                            'titre_page' => t('Résultats de recherche')
                        ),
                    )
                ),
            );
        }
        return $render_array;
  }

  private function getSynomiaResult($mot_recherche, $filtre_rubrique, $numPage, $sortBy) {
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        $urlSynomia = \Drupal::state()->get('url_synomia_'.$current_language);
        //POUR LES TESTS
        //$urlSynomia = 'https://www.synomia.fr/search/xml_request.php?mid=fc982d5c25ff37b9768d8057fee2c5b9';

        if (!empty($urlSynomia)) {
            $path = $urlSynomia;
            if ($current_language == 'ru' || $current_language == 'es' ||$current_language == 'pt-br') {
                $path .= "&exactSearch=" . urlencode($mot_recherche) . "&sortBy=" . $sortBy;
            } else {
                $path .= "&q=" . urlencode($mot_recherche) . "&sortBy=" . $sortBy;
            }

            //on récupère le nb de résultats par page
            $config_factory = \Drupal::configFactory();
            $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
            if (!empty($config) && !empty($config->get('nb_results_per_page'))) {
                $nbResultsPerPage = $config->get('nb_results_per_page');
            } else {
                $nbResultsPerPage = 10; // 10 par défaut si aucune configuration
            }

            if (isset($numPage) && !empty($numPage)) {
                $offset = $numPage * $nbResultsPerPage;
                $path .= "&offsetDisplay=".$offset;
            }

            //on ajoute les facettes
            $path .= "&sortie=facette";

            //filtre sur le type de contenu
            if (!isset($filtre_rubrique) || empty($filtre_rubrique)) {
                $path .= "&cluster=rubrique"; //sur D7
                //$path .= "&sortie=facette";
            } else {
                $path .= "&filtres[]=rubrique:".$filtre_rubrique;
            }

            //oabt($path);die();
            $ch = curl_init();

            $configProxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
            if (!empty($config) && !empty($configProxy->get('proxy_server')) && !empty($configProxy->get('proxy_port')))            {
                $proxy_server = $configProxy->get('proxy_server').':'.$configProxy->get('proxy_port');
            } else {
                $proxy_server = NULL;
            }

            //var_dump($path);
            curl_setopt_array ( $ch, array(
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
        } else{
            return null;
        }
    }

    /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
     * @param $old_facets_array
     * @return array
     */
    private function orderFacetsArray($old_facets_array) {
          $newFacetsArrayOrdered = array();
        $contentTypes = $this->getOrderContentTypesArray();
        if (!empty($contentTypes)) {
            foreach ($contentTypes as $contentType) {
                $newFacetsArrayOrdered[$contentType] = $old_facets_array[$contentType];
                unset($old_facets_array[$contentType]);
            }
            return array_merge($newFacetsArrayOrdered, $old_facets_array);
        }
        return $old_facets_array;
    }

    /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
     * @param $old_facets_array
     * @return array
     */
    private function orderResultsArray($oldResultsArray) {
          $newResultsArrayOrdered = array();
        $contentTypes = $this->getOrderContentTypesArray();
        if (!empty($contentTypes)) {
            foreach ($contentTypes as $contentType) {
                $newResultsArrayOrdered[$contentType] = $oldResultsArray[$contentType];
                unset($oldResultsArray[$contentType]);
            }
            return array_merge($newResultsArrayOrdered, $oldResultsArray);
        }
        return $oldResultsArray;
    }

    private function getOrderContentTypesArray() {
        $contentTypes = array();
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        //on récupère le nb de résultats par page
        $config_factory = \Drupal::configFactory();
        $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
        if (!empty($config) && !empty($config->get('order_content_types_'.$current_language))) {
            $orderString = $config->get('order_content_types_'.$current_language);
            if (!empty($orderString)) {
                $tmpContentTypes = explode(',', $orderString);
                foreach ($tmpContentTypes as $tmp) {
                    $contentTypes[] = trim($tmp);
                }
            }
        }
        return $contentTypes;
    }
}