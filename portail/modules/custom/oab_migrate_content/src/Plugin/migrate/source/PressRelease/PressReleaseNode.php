<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\PressRelease;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "press_release_node"
 * )
 */
class PressReleaseNode extends SqlBase {

  /**
   * {@inheritdoc}
   */
  public function query() {
    /**
     * An important point to note is that your query *must* return a single row
     * for each item to be imported. Here we might be tempted to add a join to
     * migrate_example_beer_topic_node in our query, to pull in the
     * relationships to our categories. Doing this would cause the query to
     * return multiple rows for a given node, once per related value, thus
     * processing the same node multiple times, each time with only one of the
     * multiple values that should be imported. To avoid that, we simply query
     * the base node data here, and pull in the relationships in prepareRow()
     * below.
     */
    $query = $this->select('node', 'n')
    ->fields('n', ['nid', 'title', 'language', 'created', 'changed', 'status'])
    ->condition('n.type', 'content_press_release', '=');
    //->range(0, 10);

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Press Release ID'),
      'title' => $this->t('title'),
      'language' => $this->t('language'),
      'areas' => $this->t('areas'),
      'content_field' => $this->t('content_field'),
      'file' => $this->t('file'),
      'country' => $this->t('country'),
      'city' => $this->t('city'),
      'solutions' => $this->t('solutions'),
      'industries' => $this->t('industries'),
			'status' => $this->t('status'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'nid' => [
        'type' => 'integer',
        'alias' => 'n',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
		//META TITRE
		$title = $row->getSourceProperty('title');
		$title = mb_substr($title,0, 55);
		$row->setSourceProperty('meta_title', $title) ;

		//META DESCRIPTION - récupération de la short description (txt_catcher)
		$meta_description = "";
		$catcher_query = $this->select('field_data_field_txt_catcher', 'c');
		$catcher_query->fields('c', ['field_txt_catcher_value'])
			->condition('c.entity_id', $row->getSourceProperty('nid'), '=')
			->condition('c.bundle', 'content_press_release', '=');

		$catcher_results = $catcher_query->execute()->fetchAll();

		if (is_array($catcher_results)){
			foreach ($catcher_results AS $catcher_result){

				// On vérifie si on a affaire à un objet ou à un tableau
				if (is_object($catcher_result) && isset($catcher_result->field_txt_catcher_value)){
					$meta_description = $catcher_result->field_txt_catcher_value;
				}
				elseif (is_array($catcher_result) && isset($catcher_result['field_txt_catcher_value'])){
					$meta_description = $catcher_result['field_txt_catcher_value'];
				}
			}
		}
		if(isset($meta_description) && !empty($meta_description))
		{
			$meta_description = mb_substr($meta_description,0, 155);
			$row->setSourceProperty('meta_description', $meta_description) ;
		}

    //Taxonomie de la Subhome
		$subhomes = \Drupal::state()->get('subhomes_ids_for_migration');
		if(isset($subhomes['press'][$row->getSourceProperty('language')])
			&& isset($subhomes['press'][$row->getSourceProperty('language')]['tid_D8'])
			&& !empty($subhomes['press'][$row->getSourceProperty('language')]['tid_D8']))
		{
			$row->setSourceProperty('subhomes', $subhomes['press'][$row->getSourceProperty('language')]['tid_D8']);
		}


    // récupération de Country
    $country_query = $this->select('field_data_field_txt_country', 'c');
    $country_query->fields('c', ['field_txt_country_value'])
      ->condition('c.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('c.bundle', 'content_press_release', '=');

    $country_results = $country_query->execute()->fetchAll();

    if (is_array($country_results)){
      foreach ($country_results AS $country_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($country_result) && isset($country_result->field_txt_country_value)){
          $row->setSourceProperty('country', $country_result->field_txt_country_value);
        }
        elseif (is_array($country_result) && isset($country_result['field_txt_country_value'])){
          $row->setSourceProperty('country', $country_result['field_txt_country_value']);
        }
      }
    }

    // récupération de City
    $city_query = $this->select('field_data_field_location', 'l');
    $city_query->fields('l', ['field_location_value'])
      ->condition('l.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('l.bundle', 'content_press_release', '=');

    $city_results = $city_query->execute()->fetchAll();

    if (is_array($city_results)){
      foreach ($city_results AS $city_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($city_result) && isset($city_result->field_location_value)){
          $row->setSourceProperty('city', $city_result->field_location_value);
        }
        elseif (is_array($city_result) && isset($city_result['field_location_value'])){
          $row->setSourceProperty('city', $city_result['field_location_value']);
        }
      }
    }


    // récupération du body (content)
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'content_press_release', '=');

    $body_results = $body_query->execute()->fetchAll();

    if (is_array($body_results)){
      foreach ($body_results AS $body_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($body_result) && isset($body_result->body_value)){
          $body_value = $body_result->body_value;
          $body_value = preg_replace(array('@<br>\r\n@', '@<br>\n\r@', '@<br>\n@', '@<br>\r@'), '<br>', $body_value);
          $body_value = oab_migrate_wysiwyg_images($body_value, $row->getSourceProperty('nid'));
          $row->setSourceProperty('content_field', $body_value);
        }
        elseif (is_array($body_result) && isset($body_result['body_value'])){
          $body_value = $body_result['body_value'];
          $body_value = preg_replace(array('@<br>\r\n@', '@<br>\n\r@', '@<br>\n@', '@<br>\r@'), '<br>', $body_value);
          $body_value = oab_migrate_wysiwyg_images($body_value, $row->getSourceProperty('nid'));
          $row->setSourceProperty('content_field', $body_value);
        }
      }
    }


    /*
     * Récupération des TAGS
     */

    // récupération du tag "industries"
		$industries = array();
		$correspondance_taxo_industry = \Drupal::state()->get('correspondence_taxo_industry');
		if(count($correspondance_taxo_industry) > 0) {

			$industrie_query = $this->select('field_data_field_taxo_industrie', 'i');
			$industrie_query->join('taxonomy_term_data', 't', 't.tid = i.field_taxo_industrie_tid');
			$industrie_query->fields('t', ['tid'])
				->condition('i.entity_id', $row->getSourceProperty('nid'), '=')
				->condition('i.bundle', 'content_press_release', '=');

			$industrie_results = $industrie_query->execute()->fetchAll();

			if (is_array($industrie_results)){
				$industries = array();
				foreach ($industrie_results AS $industrie_result){
					$industry_id = '';
					// On vérifie si on a affaire à un objet ou à un tableau
					if (is_object($industrie_result) && isset($industrie_result->tid)){
						$industry_id = $industrie_result->tid;
					}
					elseif (is_array($industrie_result) && isset($industrie_result['tid'])){
						$industry_id = $industrie_result['tid'];
					}
					if (isset($correspondance_taxo_industry[$industry_id]) && isset($correspondance_taxo_industry[$industry_id]['tid_D8'])) {
						//prendre le tid D8
						if (isset($correspondance_taxo_industry[$industry_id]['tid_D8']) && !empty($correspondance_taxo_industry[$industry_id]['tid_D8']) && $correspondance_taxo_industry[$industry_id]['tid_D8'] != "") {
							$industries[] = $correspondance_taxo_industry[$industry_id]['tid_D8'];
						}
					}
				}
				$row->setSourceProperty('industries', $industries);
			}
		}

    // récupération du tag "solution"
		$thematics = array();
		$correspondance_taxo_solution_to_thematic = \Drupal::state()->get('correspondence_taxo_solution_to_thematic');
		$correspondance_taxo_solution = \Drupal::state()->get('correspondence_taxo_solution');
		if(count($correspondance_taxo_solution) > 0) {
			$solutions = array();
			$solution_query = $this->select('field_data_field_taxo_solution', 's');
			$solution_query->join('taxonomy_term_data', 't', 't.tid = s.field_taxo_solution_tid');
			$solution_query->fields('t', ['tid'])
				->condition('s.entity_id', $row->getSourceProperty('nid'), '=')
				->condition('s.bundle', 'content_press_release', '=');

			$solution_results = $solution_query->execute()->fetchAll();

			if (is_array($solution_results)) {
				foreach ($solution_results AS $solution_result) {
					$solution_id = '';
					// On vérifie si on a affaire à un objet ou à un tableau
					if (is_object($solution_result) && isset($solution_result->tid)) {
						$solution_id = $solution_result->tid;
					}
					elseif (is_array($solution_result) && isset($solution_result['tid'])) {
						$solution_id = $solution_result['tid'];
					}

					if (isset($correspondance_taxo_solution[$solution_id]) && isset($correspondance_taxo_solution[$solution_id]['tid_D8'])) {
						if (isset($correspondance_taxo_solution[$solution_id]['tid_D8']) && !empty($correspondance_taxo_solution[$solution_id]['tid_D8']) && $correspondance_taxo_solution[$solution_id]['tid_D8'] != "") {
							$solutions[] = $correspondance_taxo_solution[$solution_id]['tid_D8'];
						}
					}

					//on regarde si on doit mettre une thematique pour cette solution
					if (isset($correspondance_taxo_solution_to_thematic[$solution_id]) && isset($correspondance_taxo_solution_to_thematic[$solution_id]['tid_D8'])) {
						if (isset($correspondance_taxo_solution_to_thematic[$solution_id]['tid_D8']) && !empty($correspondance_taxo_solution_to_thematic[$solution_id]['tid_D8']) && $correspondance_taxo_solution_to_thematic[$solution_id]['tid_D8'] != "") {
							$thematics[] = $correspondance_taxo_solution_to_thematic[$solution_id]['tid_D8'];
						}
					}
				}
				$row->setSourceProperty('solutions', $solutions);
				// s'il y a une thématique, on l'affecte
				if(isset($thematics) && count($thematics) >0)	{
					$row->setSourceProperty('thematics', $thematics);
				}
			}
		}

    // récupération du tag "area"
		$regions = array();
		$correspondance_taxo_region = \Drupal::state()->get('correspondence_taxo_region');
		if(count($correspondance_taxo_region) > 0) {
			$area_query = $this->select('field_data_field_taxo_area', 'a');
			$area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
			$area_query->fields('t', ['tid'])
				->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
				->condition('a.bundle', 'content_press_release', '=');
			$area_results = $area_query->execute()->fetchAll();
			if (is_array($area_results)){
				$regions = array();
				foreach ($area_results AS $area_result){
					$region_id = '';
					// On vérifie si on a affaire à un objet ou à un tableau
					if (is_object($area_result) && isset($area_result->tid)){
						$region_id = $area_result->tid;
					}
					elseif (is_array($area_result) && isset($area_result['tid'])){
						$region_id = $area_result['tid'];
					}
					if (isset($correspondance_taxo_region[$region_id]) && isset($correspondance_taxo_region[$region_id]['tid_D8'])) {
						if (isset($correspondance_taxo_region[$region_id]['tid_D8']) && !empty($correspondance_taxo_region[$region_id]['tid_D8']) && $correspondance_taxo_region[$region_id]['tid_D8'] != "") {
							$regions[] = $correspondance_taxo_region[$region_id]['tid_D8'];
						}
					}
				}
				$row->setSourceProperty('regions', $regions);
			}
		}

    // récupération des fichiers
    $files_query = $this->select('field_data_field_file_upl', 'fi');
    $field1_alias = $files_query->addField('fi', 'field_file_upl_fid', 'mid');
    $field2_alias = $files_query->addField('fi', 'delta');
    $files_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'content_press_release', '=')
    ->orderBy('fi.delta', 'ASC');


    $files_results = $files_query->execute()->fetchAll();

    if (is_array($files_results)){
      $files = array();
      foreach ($files_results AS $files_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($files_result) && isset($files_result->mid)){
          $files[] = $files_result->mid;
        }
        elseif (is_array($files_result) && isset($files_result['mid'])){
          $files[] = $files_result['mid'];
        }
      }
      $row->setSourceProperty('files', $files);
    }


    // récupération du workflow
    $workflow_query = $this->select('workflow_node', 'w');
    $workflow_query->fields('w', ['sid'])
      ->condition('w.nid', $row->getSourceProperty('nid'), '=');

    $workflow_results = $workflow_query->execute()->fetchAll();

    if (is_array($workflow_results))
    {
      foreach ($workflow_results AS $workflow_result){
        $sid = '';
        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($workflow_result) && isset($workflow_result->sid)){
          $sid = $workflow_result->sid;
        }
        elseif (is_array($workflow_result) && isset($workflow_result['sid'])){
          $sid = $workflow_result['sid'];
        }

        $workflow_new_state = oab_migrate_workflow_sid_correspondance((int)$sid);
        $row->setSourceProperty('moderation_state', $workflow_new_state);
      }
    }


    // path
    $url_source = 'node/' . $row->getSourceProperty('nid');
    $path_query = $this->select('url_alias', 'ua')
      ->fields('ua')
      ->condition('ua.source', $url_source, '=');

    $path_results = $path_query->execute()->fetchObject();

    if (is_object($path_results)){
      $row->setSourceProperty('path', '/' . $path_results->alias);
    }

    return parent::prepareRow($row);
  }

}
