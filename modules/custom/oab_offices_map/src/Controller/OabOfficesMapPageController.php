<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_offices_map\Controller;


use Drupal\block\Entity\Block;
use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\Core\Url;
use Drupal\taxonomy\Plugin\views\wizard\TaxonomyTerm;
use Drupal\views\Views;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabOfficesMapPageController extends ControllerBase {

    public function getPageTitle() {
        return t("Our local offices");
    }

    public function viewPage(Request $request) {

        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        if ($current_language == "fr") {
            //on lance une 404
            throw new NotFoundHttpException();
        }
        else {
            //paramètres :
            $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
            $region_id = (!empty($parameters) && isset($parameters['region']) && $parameters['region'] != 'All') ? $parameters['region'] : 'all';
            $country_id = (!empty($parameters) && isset($parameters['country']) && $parameters['country'] != 'All') ? $parameters['country'] : 'all';

            if (($current_language == "ru" && !empty($country_id) && $country_id =="ru")
                || ($current_language == "ru" && !empty($country_id) && $country_id =="all" && (empty($region_id) || $region_id == "all"))) {
                // si l'url est /ru/contacts ou /ru/contacts?country=ru => on redirige vers le bon id du pays Russia
                $query = \Drupal::entityQuery('taxonomy_term');
                $query->condition('vid', 'office_countries');
                $query->condition('name', 'Russia');
                $entity_countries = $query->execute();

                if (!empty($entity_countries)) {
                    $country_id = array_pop(array_values($entity_countries));
                }
                $current_route = \Drupal::routeMatch()->getRouteName();
                $option = [
                    'query' => array('region' => $region_id, 'country' => $country_id),
                ];
                $url = Url::fromRoute($current_route, array(), $option);
                return new RedirectResponse($url->toString());
            }
            elseif (($current_language == "es" && !empty($country_id) && $country_id =="es")
                || ($current_language == "es" && !empty($country_id) && $country_id =="all" && (empty($region_id) || $region_id == "all"))) {

                $query = \Drupal::entityQuery('taxonomy_term');
                $query->condition('vid', 'regions');
                $query->condition('name', 'Latin America');
                $entity_regions = $query->execute();

                if (!empty($entity_regions)) {
                    $region_id = array_pop(array_values($entity_regions));
                }

                $current_route = \Drupal::routeMatch()->getRouteName();
                $option = [
                    'query' => array('region' => $region_id, 'country' => $country_id),
                ];
                $url = Url::fromRoute($current_route, array(), $option);
                return new RedirectResponse($url->toString());
            }
            elseif (($current_language == "pt-br" && !empty($country_id) && $country_id =="pt-br")
                || ($current_language == "pt-br" && !empty($country_id) && $country_id =="all" && (empty($region_id) || $region_id == "all"))) {
                // si l'url est /br/contacts ou /br/contacts?country=br => on redirige vers le bon id du pays Brazil
                $query = \Drupal::entityQuery('taxonomy_term');
                $query->condition('vid', 'office_countries');
                $query->condition('name', 'Brazil');
                $entity_countries = $query->execute();

                if (!empty($entity_countries)) {
                    $country_id = array_pop(array_values($entity_countries));
                }

                $query = \Drupal::entityQuery('taxonomy_term');
                $query->condition('vid', 'regions');
                $query->condition('name', 'Latin America');
                $entity_regions = $query->execute();

                if (!empty($entity_regions)) {
                    $region_id = array_pop(array_values($entity_regions));
                }

                $current_route = \Drupal::routeMatch()->getRouteName();
                $option = [
                    'query' => array('region' => $region_id, 'country' => $country_id),
                ];
                $url = Url::fromRoute($current_route, array(), $option);
                return new RedirectResponse($url->toString());
            }
            else {
                $offices_map_view = Views::getView('offices_map_view');
                $offices_map_view->setDisplay('offices_map_block');
                $offices_map_view->args = array($region_id, $country_id);
                $offices_map_view->preExecute();
                $offices_map_view->execute();
                $map_block = $offices_map_view->buildRenderable('offices_map_block', array());

                $offices_map_view = Views::getView('offices_map_view');
                $offices_map_view->setDisplay('offices_addresses_list_block');
                $offices_map_view->args = array($region_id, $country_id);
                $offices_map_view->preExecute();
                $offices_map_view->execute();
                $offices_list_block = $offices_map_view->buildRenderable('offices_addresses_list_block', array());

                $regions_countries_form = \Drupal::formBuilder()
                    ->getForm('Drupal\oab_offices_map\Form\MapRegionsCountriesForm');

                $list_label = t('All offices');

                if ($region_id != 'all') {
                    $region = \Drupal\taxonomy\Entity\Term::load($region_id);
                    $list_label = $region->label() . ' offices';
                }

                # The block "page title" is used for Boosted, and hidden for theme One-I
                $page_title = \Drupal::theme()->getActiveTheme()->getName() === 'theme_one_i'
                  ? $this->getPageTitle()
                  : '';

                $library = \Drupal::theme()->getActiveTheme()->getName() === 'theme_one_i'
                  ? 'oab_offices_map/oab_offices_map.one_i'
                  : 'oab_offices_map/oab_offices_map.boosted';


                return array(
                    '#mapBlock' => $map_block,
                    '#officesListBlock' => $offices_list_block,
                    '#regionsCountriesForm' => $regions_countries_form,
                    '#page_title' => $page_title,
                    '#labelList' => $list_label,
                    '#theme' => 'offices_map_page',
                    '#attached' => array(
                        'library' => array(
                            $library
                        ),
                        'drupalSettings' => array(
                            'countriesRegionsTab' => getArrayRegionsCountries(),
                            'allCountriesArray' => getCountriesForJS(),
                            'selectedCountryParameter' => $country_id,
                            'selectedRegionParameter' => $region_id,
                        ),
                    ),
                );
            }
        }
    }
}
