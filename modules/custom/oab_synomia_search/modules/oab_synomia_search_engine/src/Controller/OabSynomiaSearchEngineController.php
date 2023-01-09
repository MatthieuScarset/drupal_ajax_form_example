<?php

namespace Drupal\oab_synomia_search_engine\Controller;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\Core\Pager\PagerManagerInterface;
use Drupal\Core\Render\Element\Container;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Drupal\oab_synomia_search_engine\Classes\SynomiaSearchResponse;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Drupal\pathauto\MessengerInterface;
use Psr\Log\LoggerInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\DependencyInjection\Exception\ServiceNotFoundException;
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
   * @var \Drupal\oab_synomia_search_engine\Classes\SynomiaSearchResponse
   */
  private $searchResponse;

  /**
   * OabSynomiaSearchEngineController constructor.
   */
  public function __construct(
    private ContainerInterface $container,
  ) {
    $this->logger = $this->getLogger('oab_synomia');
    $this->pageManager = \Drupal::service('pager.manager');
  }

    public function getPageTitle() {
        return t('Search results');
    }

    public static function create(ContainerInterface $container) {
      return new static(
        $container
      );
    }

  /** Méthode appelée lorsqu'on appelle la page de recherche */
  public function contentSearch(Request $request, $type_search = 'default') {
    try {
      $this->searchResponse = $this->container->get( "synomia.search_response.$type_search");
    } catch (ServiceNotFoundException $e) {
      $this->logger->error("Cannot found service synomia.search_response.$type_search");
      throw new NotFoundHttpException();
    }

    $render_array = array();
    $current_language = $this->languageManager()->getCurrentLanguage()->getId();
    $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
    $mot_recherche = (!empty($parameters) && isset($parameters['mot'])) ? $parameters['mot'] : '';
    $filtre_rubrique = (!empty($parameters) && isset($parameters['rubrique'])) ? $parameters['rubrique'] : '';
    $num_page = (!empty($parameters) && isset($parameters['page'])) ? $parameters['page'] : '';

    if ($this->searchResponse->getTypeSearch() == 'mss'){
      $search_form = $this->formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaMSSAssistanceSearchEngineForm');
    } else {
      $search_form = $this->formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchEngineForm');
    }

    if (!empty($mot_recherche)) {

      $result = $this->getSynomiaResult($mot_recherche, $filtre_rubrique, $num_page, '');

      if (isset($result) && !empty($result)) {
        $result_label = '';
          $this->searchResponse->readXML($result, $filtre_rubrique);
          if ($this->searchResponse->nbResultsTotal > 0) {
            if ($this->searchResponse->searchMode == 'rubrique') {
              $pager = $this->pageManager->createPager($this->searchResponse->nbResultsTotal, 10);
              $page = $pager->getCurrentPage();
            }
            if ($current_language != 'ru') {
              if ($this->searchResponse->nbResultsTotal == 1) {
                  $result_label = $this->searchResponse->nbResultsTotal . ' ' . t('result') . ' ' . t('for');
              } elseif ($this->searchResponse->nbResultsTotal > 1) {
                  $result_label = $this->searchResponse->nbResultsTotal . ' ' . t('results') . ' ' . t('for');
              }
            } else {
              $rest = $this->searchResponse->nbResultsTotal;
              if ($rest > 9) {
                  $rest = $this->searchResponse->nbResultsTotal % 10;
              }
              switch ($rest) {
                case 0:
                    $result_label = t('Найдено %nbResults результатов по запросу ', array(
                        '%nbResults' => $this->searchResponse->nbResultsTotal
                    ));
                    break;
                case 1:
                    $result_label = t('Найден %nbResults результат по запросу ', array(
                        '%nbResults' => $this->searchResponse->nbResultsTotal
                    ));
                    break;
                case 2:
                case 3:
                case 4:
                    $result_label = t('Найдено %nbResults результата по запросу ', array(
                        '%nbResults' => $this->searchResponse->nbResultsTotal
                    ));
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    $result_label = t('Найдено %nbResults результатов по запросу ', array(
                        '%nbResults' => $this->searchResponse->nbResultsTotal
                    ));
                    break;
              }
            }
          }

          $render_array[] = array(
              '#searchForm' => $search_form,
              '#resultLabel' => $result_label,
              '#searchResults' => $this->searchResponse->getOrderedResultsArray(),
              '#currentPage' => $this->searchResponse->currentPage,
              '#facets' => $this->searchResponse->getOrderedFacetsArray(),
              '#searchMode' => $this->searchResponse->searchMode,
              '#pager' => $this->searchResponse->pager,
              '#corrections' => $this->searchResponse->corrections,
              '#degradations' => $this->searchResponse->degradations,
              '#nbResults' => $this->searchResponse->nbResultsTotal,
              '#currentSearch' => $mot_recherche,
              '#search_route_path' => ($type_search === 'mss') ? 'oab_synomia_search_engine.mss_assistance_engine_url' : 'oab_synomia_search_engine.engine_url',
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
    $key_conf_url_synomia = '';
    if($this->searchResponse->getTypeSearch() == 'mss') {
      $key_conf_url_synomia = 'url_synomia_mss_assistance';
    }
    else {
      $key_conf_url_synomia = 'url_synomia_' . $current_language;
    }
    $url_synomia = \Drupal::state()->get($key_conf_url_synomia);

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

      $ch = curl_init();

      $config_proxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
      if (!empty($config) && !empty($config_proxy->get('proxy_server')) && !empty($config_proxy->get('proxy_port'))) {
          $proxy_server = $config_proxy->get('proxy_server').':'.$config_proxy->get('proxy_port');
      } else {
          $proxy_server = NULL;
      }

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
      \Drupal::logger('oab_synomia_search_engine')->error('Pas d\'url configurée pour la recherche synomia  : ' . $key_conf_url_synomia );
      return null;
    }
  }
}
