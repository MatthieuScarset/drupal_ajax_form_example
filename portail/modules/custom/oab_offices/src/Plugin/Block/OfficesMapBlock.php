<?php

namespace Drupal\oab_offices\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Locale\CountryManager;

/**
 *
 * @Block(
 *   id = "offices_map_block",
 *   admin_label = @Translation("Offices Map Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class OfficesMapBlock extends BlockBase {

  public function build(){
    $config = $this->getConfiguration(); 
    $offices_map_custom_text = isset($config['offices_map_custom_text']) ? $config['offices_map_custom_text'] : '';

    // Construction du tableau code pays => nom pays traduit
    $countriesNames = array();
    $countriesStandard = CountryManager::getStandardList();
    foreach( $countriesStandard as $key => $value)
    {
    	$countriesNames[$key] = t($value->getUntranslatedString());
    }
    // récupération des offices de la bdd
    $offices = $this->getAllOffices();
    // construction des markers pour le JS google map
    $markers = $this->getMarkers($offices, $countriesNames);

    // récupération des listes de régions et pays de la bdd
    $regions = array();
    $regions['all'] = t('All');
    $regions_countries = array();
    $this->getListsRegionsAndCountries($regions,$regions_countries);
    
    // tableau de rendu : régions, pays, markers
    return array(
    	'#regions' => $regions,
    	'#regions_countries' => $regions_countries,
    	'#countries_name' => $countriesNames,
    	'#theme' => 'oab_offices',
    	'#attached' => array(
    			'library' =>  array(
						          'oab_offices/oab_offices'
						        ),
    			'drupalSettings' =>  array(
    					'contact_offices' => $offices,
    					'markers' => $markers
    			),
    	),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();

    // Add a form field to the existing block configuration form.
    $form['offices_map_custom_text'] = array(
        '#type' => 'text_format',
        '#title' => t('Custom text'),
        '#default_value' => isset($config['offices_map_custom_text']['value']) ? $config['offices_map_custom_text']['value'] : '',
        '#format' => isset($config['offices_map_custom_text']['format']) ? $config['offices_map_custom_text']['format'] : 'full_html',
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {
  	
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    // Save our custom settings when the form is submitted.
    $this->setConfigurationValue('offices_map_custom_text', $form_state->getValue('offices_map_custom_text'));
  }
  
  /**
   * Méthode permettant de récupérer tous les offices de la bdd
   */
  protected function getAllOffices()
  {
  	$offices = array();
  	
  	// offices publiés
  	$query = db_select('node', 'n');
  	$query->fields('n');
  	$query->leftJoin('node_field_data', 'd', 'd.nid = n.nid AND d.vid = n.vid');
  	$query->condition('n.type', 'office', '=');
  	$query->condition('d.status', '1', '=');
  	$office_nid = $query->execute()->fetchAll();

  	//on parse chaque office pour récupérer les infos nécessaires
	foreach($office_nid as $office)
	{
		$node_office = \Drupal\node\Entity\Node::load($office->nid);
		$new_office = array();
		$new_office['nid'] = $node_office->id();
		$new_office['type'] = $node_office->get('type')->getValue();
		$new_office['title'] = $node_office->get('title')->getValue();
		$new_office['field_address'] = $node_office->get('field_address')->getValue();
		if($node_office->get('field_areas') != null && !empty($node_office->get('field_areas')->getValue()) )
		{
			$tids = $node_office->get('field_areas')->getValue();
			//on récupère les infos de la région
			if(isset($tids[0]['target_id']))
			{
				$taxonomy_term = \Drupal\taxonomy\Entity\Term::load($tids[0]['target_id']);
        if (is_object($taxonomy_term)) {
          $new_office['field_areas'] = array();
          $new_office['field_areas'][0] = array();
          $new_office['field_areas'][0]['area_tid'] = $tids[0]['target_id'];
          $new_office['field_areas'][0]['area_title'] = $taxonomy_term->getName();
        }
			}
		}
		$new_office['field_description'] = $node_office->get('field_description')->getValue();
		$new_office['field_gps_coordinates'] = $node_office->get('field_gps_coordinates')->getValue();
		//ajout de l'office au tableau final
		$offices[] = $new_office;			
	}	
  	return $offices;
  }
  
  /**
   * Méthode permettant la construction des markers à partir du tableau d'office et du tableau de nom des pays
   * @param unknown $offices
   * @param unknown $countriesNames
   */
  protected function getMarkers($offices, $countriesNames)
  {
  	$markers = array();
  	//parcourt de chaque office
  	for ($i = 0; $i < count($offices); $i++)
  	{
  		//construction du HTML de la popup du marker (infobox)
  		$contentString = '<div class="gmap-popup">';
  		if(count($offices[$i]['title']) > 0)
  		{
  			$contentString .= '<div class="titre">'.$offices[$i]['title'][0]['value'].'</div>';
  		}
  		
  		if(count($offices[$i]['field_address']) > 0)
  		{
  			$contentString .=	'<div class="adress">'.
						  			'<div class="location vcard">'.
							  			'<div class="adr">'.
							  				'<div class="street-address">'. $offices[$i]['field_address'][0]['address_line1'] 
							  				. '<br/>' 
							  				. $offices[$i]['field_address'][0]['address_line2']   .'</div>'.
							  				'<span class="postal-code">'. $offices[$i]['field_address'][0]['postal_code'] .'</span>'.
							  				'<span class="locality"> '. $offices[$i]['field_address'][0]['locality']   .'</span>'.
							  				'<br/>' .'<span class="country"> '. $countriesNames[$offices[$i]['field_address'][0]['country_code']]   .'</span>'.
							  			'</div>'.
						  			'</div>'.
					  			'</div>';
  		}
  		$contentString .=		'<div class="bottom">';
  		if(count($offices[$i]['field_areas']) > 0)
  		{
  			$contentString .=				'<div class="country_region">'.
  			'<div class="region">'.
  			'<a class="more" title="Read more about '.$offices[$i]['field_areas'][0]['area_title'].'" href="#"><span class="icon icon-more"></span>'.$offices[$i]['field_areas'][0]['area_title'].'</a>'.
  			'</div>'.
  			'</div>';
  		}
  		//$contentString .=				'<div class="contact"><a class="more" title="" href="/en/contact-us"><span class="icon icon-more"></span>'.'Contact'.'</a>'.'</div>'.
  		$contentString .='<div style="clear:both"></div>'.
  		'</div>'.
  		'<div class="fleche">&nbsp;</div>'.
  		'</div>'.
  		'</div>';
  		//construction du marker
  		$marker = array();
  		$marker['textInfoBox'] = $contentString;
  		$marker['title'] = $offices[$i]['title']['value'];
  		$marker['nid'] = $offices[$i]['nid'];
  		$marker['field_gps_coordinates'] = $offices[$i]['field_gps_coordinates'];
  		$markers[] = $marker;
  	}  	
  	return $markers;  	
  }  

  /**
   * Méthode qui va permettre de remplir les tableau régions et country à envoyer au template du block
   * @param unknown $regions
   * @param unknown $regions_countries
   */
  protected function getListsRegionsAndCountries(&$regions, &$regions_countries)
  {
  	$all_countries = array();
  	// on récupère la liste des code_pays / région des offices de la bdd
  	$query = db_select('node', 'n');  	
  	$query->fields('ad', array('field_address_country_code')); //code pays
  	$query->fields('ar', array('field_areas_target_id')); // id région
  	$query->fields('n', array('nid'));
	$query->distinct(true); // couple de valeurs unique
  	$query->leftJoin('node_field_data', 'd', 'd.nid = n.nid AND d.vid = n.vid');
  	$query->leftJoin('node__field_address', 'ad', 'ad.entity_id = n.nid');
  	$query->leftJoin('node__field_areas', 'ar', 'ar.entity_id = n.nid');
  	$query->condition('n.type', 'office', '=');
  	$query->condition('d.status', '1', '=');  	
  	$countries_nodes = $query->execute()->fetchAll();
  	
  	 // on crée 2 tableaux : l'un de régions et l'autre de couple region/pays pour avoir la liste des pays selon la région
	foreach($countries_nodes as $country_node)
	{
		if(!in_array($country_node->field_areas_target_id, $regions))
		{
			$taxonomy_term = \Drupal\taxonomy\Entity\Term::load($country_node->field_areas_target_id);
      if (is_object($taxonomy_term)) {
        $regions[$country_node->field_areas_target_id] = $taxonomy_term->getName();
      }
		}
		if(!in_array($country_node->field_address_country_code, $all_countries))
		{
			$all_countries[] = $country_node->field_address_country_code;
		}
		if(!in_array($country_node->field_address_country_code, $regions_countries[$country_node->field_areas_target_id]))
		{
			$regions_countries[$country_node->field_areas_target_id][] = $country_node->field_address_country_code;
		}		
	}
	$regions_countries['all'] = $all_countries;
  }
}