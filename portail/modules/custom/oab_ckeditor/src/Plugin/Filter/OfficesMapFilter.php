<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 30/10/2017
 */

namespace Drupal\oab_ckeditor\Plugin\Filter;

use Drupal\Component\Utility\UrlHelper;
use Drupal\filter\FilterProcessResult;
use Drupal\filter\Plugin\FilterBase;
use Drupal\views\Views;

/**
 * @Filter(
 *   id = "offices_map_filter",
 *   title = @Translation("Offices Map Filter"),
 *   description = @Translation("Insert a map of the offices in a wysiwyg"),
 *   type = Drupal\filter\Plugin\FilterInterface::TYPE_MARKUP_LANGUAGE,
 * )
 */
class OfficesMapFilter extends FilterBase {

    private $pattern = '/\|\|.*?\|\|/s';
    private $regionId = "";
    private $countryId = "";
    private $boolParamsUrl = false;

    public function process($text, $langcode) {
        $result = new FilterProcessResult($text);

        //on regarde d'abord s'il y a des paramètres dans l'url
        $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
        if (!empty($parameters) && isset($parameters['region'])) {
            $this->boolParamsUrl = true;
            $this->regionId = $parameters['region'];
        } else {
            $this->regionId = 'all';
        }

        if (!empty($parameters) && isset($parameters['country'])) {
            $this->countryId = $parameters['country'];
            $this->boolParamsUrl = true;
        } else {
            $this->countryId = 'all';
        }

        //Pattern de recherche pour une MAP dans un WYSIWYG
        $search_results = array();
        $error = false;
        $has_map_filter = false;
        //Recherche du pattern
        while (preg_match($this->pattern, $text, $search_results) && !$error) {
            $has_map_filter = true;
            $chaine_trouvee = $search_results[0];
            //on teste s'il y a plusieurs maps dans un résultat
            $count = mb_substr_count($chaine_trouvee, "}||");
            if ($count > 1) {
                $pos = strpos($chaine_trouvee, "}||" ); //on cherche la premiere fin
                $sous_chaine = substr($chaine_trouvee, 0, $pos+2);
                $sous_chaine_remplacee = $this->render_offices_map_block($sous_chaine);
                $text = str_replace($sous_chaine, $sous_chaine_remplacee, $text);
            } else {
                //il n'y a qu'une map a remplacer
                $new_chaine = $this->render_offices_map_block($chaine_trouvee);
                $text = str_replace($search_results[0], $new_chaine, $text);
            }
        }

        if ($has_map_filter) {
          $result->addAttachments(
              array(
                  'library' => ['oab_offices_map/oab_offices_map.markers'],
                  'drupalSettings' => array(
                      'countriesRegionsTab' => getArrayRegionsCountries(),
                      'allCountriesArray' => getCountriesForJS(),
                      'selectedCountryParameter' => $this->countryId,
                      'selectedRegionParameter' => $this->regionId,
                  ),
                  )
          );
        }

        return $result;
    }

    public function render_offices_map_block($chaine_a_remplacer) {
        $new_text = "";
        $chaine_json = str_replace("||", "", $chaine_a_remplacer);
        $tag_info = json_decode($chaine_json);

        if (isset($tag_info->block_id) && $tag_info->block_id == "offices_map_block") {

            $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
            if (!$this->boolParamsUrl && !empty($tag_info->region_id)) {
                $this->regionId = $tag_info->region_id;
            }

            if (!$this->boolParamsUrl && !empty($tag_info->country_id)) {
                $this->countryId = $tag_info->country_id;
            }
            $regions_countries_form = \Drupal::formBuilder()
                ->getForm(
                    'Drupal\oab_offices_map\Form\MapRegionsCountriesForm',
                    array('region_id' => $this->regionId, 'country_id' => $this->countryId)
                );



            //on doit remplacer la chaine par le rendu du block
            $offices_map_view = Views::getView('offices_map_view');
            $offices_map_view->setDisplay('offices_map_block');
            $offices_map_view->args = array($this->regionId,  $this->countryId);
            $offices_map_view->preExecute();
            $offices_map_view->execute();
            $map_block = $offices_map_view->buildRenderable('offices_map_block', array());

            $offices_map_view = Views::getView('offices_map_view');
            $offices_map_view->setDisplay('offices_addresses_list_block');
            $offices_map_view->args = array($this->regionId,  $this->countryId);
            $offices_map_view->preExecute();
            $offices_map_view->execute();
            $offices_list_block = $offices_map_view->buildRenderable('offices_addresses_list_block', array());
        }
        $new_text = '<div class="officeMapBlock">'.
            '<div class="region region-content col-md-12 col-sm-12" >'.
                                    '<div class="form_filter_regions_countries col col-md-12 col-sm-12">'.
                                            render($regions_countries_form).
                        '</div>'.
                        '<div class="block_principal_offices_map col-lg-12 col-md-12 col-sm-12">'.
                        ' <div class="block_carte col-lg-9 col-md-8 col-sm-12">'.
                                                render($map_block).
                        '</div>'.
                        '<div class="col-lg-3 col-md-4 col-sm-12 addresses-list">'.
                         ' <div class="col-lg-12 col-md-12 col-sm-12 list">'.
                                                     render($offices_list_block).'</div>'.
                            ' </div>'.
                            ' </div>'.
                            ' </div>'.
                                        '</div>';

        return $new_text;
    }
}

