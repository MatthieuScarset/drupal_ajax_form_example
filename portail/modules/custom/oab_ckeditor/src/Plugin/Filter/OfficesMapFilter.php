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

	public function process($text, $langcode) {
		//Pattern de recherche pour une MAP dans un WYSIWYG
		$searchResults = array();
		$error = false;
		//Recherche du pattern
		while(preg_match($this->pattern, $text, $searchResults) && !$error)
		{
			$chaineTrouvee = $searchResults[0];
			//on teste s'il y a plusieurs maps dans un résultat
			$count = mb_substr_count($chaineTrouvee, "}||");
			if($count > 1)
			{
				$pos = strpos($chaineTrouvee, "}||" ); //on cherche la premiere fin
				$sousChaine = substr($chaineTrouvee, 0, $pos+2);
				$sousChaineRemplacee = $this->render_offices_map_block($sousChaine);
				$text = str_replace($sousChaine, $sousChaineRemplacee, $text);
			}
			else {
				//il n'y a qu'une map a remplacer
				$newChaine = $this->render_offices_map_block($chaineTrouvee);
				$text = str_replace($searchResults[0], $newChaine, $text);
			}
		}
		$result = new FilterProcessResult($text);
		$result->addAttachments( array( 'library' => ['oab_offices_map/oab_offices_map.markers']));
		return $result;
	}

	function render_offices_map_block($chaineARemplacer) {
		$newText = "";
		$region_id = "";
		$country_id = "";
		$chaine_json = str_replace("||", "", $chaineARemplacer);
		$tag_info = json_decode($chaine_json);

		if(isset($tag_info->block_id) && $tag_info->block_id == "offices_map_block"){

			$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
			if(!empty($parameters) && isset($parameters['region'])){
				$region_id = $parameters['region'];
			}elseif (!empty($tag_info->region_id)){
				$region_id = $tag_info->region_id;
			}
			else{
				$region_id = 'all';
			}

			if(!empty($parameters) && isset($parameters['country'])){
				$country_id = $parameters['country'];
			}elseif (!empty($tag_info->country_id)){
				$country_id = $tag_info->country_id;
			}
			else{
				$country_id = 'all';
			}
			$regionsCountriesForm = \Drupal::formBuilder()
				->getForm('Drupal\oab_offices_map\Form\MapRegionsCountriesForm', array('region_id' => $region_id, 'country_id' => $country_id));



			//on doit remplacer la chaine par le rendu du block
			$officesMapView = Views::getView('offices_map_view');
			$officesMapView->setDisplay('offices_map_block');
			$officesMapView->args = array($region_id, $country_id);
			$officesMapView->preExecute();
			$officesMapView->execute();
			$mapBlock = $officesMapView->buildRenderable('offices_map_block', array());

			$officesMapView = Views::getView('offices_map_view');
			$officesMapView->setDisplay('offices_addresses_list_block');
			$officesMapView->args = array($region_id, $country_id);
			$officesMapView->preExecute();
			$officesMapView->execute();
			$officesListBlock = $officesMapView->buildRenderable('offices_addresses_list_block', array());
		}
		$newText = '<div class="officeMapBlock">'.
			'<div class="region region-content col-md-12 col-sm-12" >'.
									'<div class="form_filter_regions_countries col col-md-12 col-sm-12">'.
											render($regionsCountriesForm).
            			'</div>'.
            			'<div class="block_principal_offices_map col-lg-12 col-md-12 col-sm-12">'.
               			' <div class="block_carte col-lg-9 col-md-8 col-sm-12">'.
												render($mapBlock).
                		'</div>'.
                		'<div class="col-lg-3 col-md-4 col-sm-12 addresses-list">'.
                    	'<div class="col-lg-12 col-md-12 col-sm-12 labelList">'.'label'.'</div>'.
                  		 ' <div class="col-lg-12 col-md-12 col-sm-12 list">'.
													 render($officesListBlock).'</div>'.
               				' </div>'.
           					' </div>'.
           					' </div>'.
										'</div>';

		return $newText;
	}
}

