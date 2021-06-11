<?php

namespace Drupal\oab_synomia_search_engine\Controller;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\Core\Pager\PagerManagerInterface;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Drupal\oab_synomia_search_engine\Classes\SynomiaSearchResponse;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchEngineController extends ControllerBase
{

  /**
   * @var PagerManagerInterface
   */
  private $pageManager;

  /**
   * OabSynomiaSearchEngineController constructor.
   */
  public function __construct() {
    $this->pageManager = \Drupal::service('pager.manager');
  }

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
        $num_page = (!empty($parameters) && isset($parameters['page'])) ? $parameters['page'] : '';

        $search_form = \Drupal::formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchEngineForm');

        if (!empty($mot_recherche)) {
            $result = $this->getSynomiaResult($mot_recherche, $filtre_rubrique, $num_page, '');
            if (isset($result) && !empty($result)) {
                $response = new SynomiaSearchResponse();
                $response->readXML($result, $filtre_rubrique);
                if (count($response->nbResultsTotal) > 0) {

                    if ($response->searchMode == 'rubrique') {
                      $pager = $this->pageManager->createPager($response->nbResultsTotal, 10);
                      $page = $pager->getCurrentPage();
                    }
                    $result_label = '';
                  if ($current_language != 'ru') {
                        if (count($response->nbResultsTotal) == 1) {
                            $result_label = $response->nbResultsTotal . ' ' . t('result') . ' ' . t('for');
                        } elseif (count($response->nbResultsTotal) > 1) {
                            $result_label = $response->nbResultsTotal . ' ' . t('results') . ' ' . t('for');
                        }
                    } else {
                        $rest = $response->nbResultsTotal;
                        if ($rest > 9) {
                            $rest = $response->nbResultsTotal % 10;
                        }
                        switch ($rest) {
                            case 0:
                                $result_label = t('Найдено %nbResults результатов по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 1:
                                $result_label = t('Найден %nbResults результат по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 2:
                            case 3:
                            case 4:
                                $result_label = t('Найдено %nbResults результата по запросу ', array(
                                    '%nbResults' => $response->nbResultsTotal
                                ));
                                break;
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                $result_label = t('Найдено %nbResults результатов по запросу ', array(
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
                    '#searchForm' => $search_form,
                    '#resultLabel' => $result_label,
                    '#searchResults' => $response->results,
                    '#currentPage' => $response->currentPage,
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
                    '#searchForm' => $search_form,
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
                '#searchForm' => $search_form,
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

  private function getSynomiaResult($mot_recherche, $filtre_rubrique, $num_page, $sort_by) {
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        $url_synomia = \Drupal::state()->get('url_synomia_'.$current_language);
        //POUR LES TESTS
        //$url_synomia = 'https://www.synomia.fr/search/xml_request.php?mid=fc982d5c25ff37b9768d8057fee2c5b9';

        if (!empty($url_synomia)) {
            $path = $url_synomia;
            if ($current_language == 'ru' || $current_language == 'es' ||$current_language == 'pt-br') {
                $path .= "&exactSearch=" . urlencode($mot_recherche) . "&sortBy=" . $sort_by;
            } else {
                $path .= "&q=" . urlencode($mot_recherche) . "&sortBy=" . $sort_by;
            }

            //on récupère le nb de résultats par page
            $config_factory = \Drupal::configFactory();
            $config = $config_factory->get(OabSynomiaSearchSettingsForm::getConfigName());
            if (!empty($config) && !empty($config->get('nb_results_per_page'))) {
                $nb_results_per_page = $config->get('nb_results_per_page');
            } else {
                $nb_results_per_page = 10; // 10 par défaut si aucune configuration
            }

            if (isset($num_page) && !empty($num_page)) {
                $offset = $num_page * $nb_results_per_page;
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

            $config_proxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
            if (!empty($config) && !empty($config_proxy->get('proxy_server')) && !empty($config_proxy->get('proxy_port'))) {
                $proxy_server = $config_proxy->get('proxy_server').':'.$config_proxy->get('proxy_port');
            } else {
                $proxy_server = NULL;
            }

            //var_dump($path);
            curl_setopt_array($ch, array(
                    CURLOPT_CONNECTTIMEOUT => 2,
                    CURLOPT_TIMEOUT => 5,
                    CURLOPT_PROXY => $proxy_server,
                    CURLOPT_SSLVERSION => 0,
                    CURLOPT_HEADER => false,
                    CURLOPT_RETURNTRANSFER => true,
                    CURLOPT_URL => $path,
                )
            );
            $ret_value = curl_exec($ch);
            curl_close($ch);
            return $ret_value;
        } else {
            return null;
        }
    }

    /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
     * @param $old_facets_array
     * @return array
     */
    private function orderFacetsArray($old_facets_array) {
          $new_facets_array_ordered = array();
        $content_types = $this->getOrderContentTypesArray();
        if (!empty($content_types)) {
            foreach ($content_types as $contentType) {
                $new_facets_array_ordered[$contentType] = $old_facets_array[$contentType];
                unset($old_facets_array[$contentType]);
            }
            return array_merge($new_facets_array_ordered, $old_facets_array);
        }
        return $old_facets_array;
    }

    /** Permet de trier l'ordre des filtres par rapport à ce qui est configuré dans le BO. Si pas de config, pas de tri
     * @param $old_facets_array
     * @return array
     */
    private function orderResultsArray($old_results_array) {
        $new_results_array_ordered = array();
        $content_types = $this->getOrderContentTypesArray();
        if (!empty($content_types)) {
            foreach ($content_types as $contentType) {
                $new_results_array_ordered[$contentType] = $old_results_array[$contentType];
                unset($old_results_array[$contentType]);
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
            $order_string = $config->get('order_content_types_'.$current_language);
            if (!empty($order_string)) {
                $tmp_content_types = explode(',', $order_string);
                foreach ($tmp_content_types as $tmp) {
                    $content_types[] = trim($tmp);
                }
            }
        }
        return $content_types;
    }
}
