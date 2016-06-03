<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\DossierPresse;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "dossier_presse_node"
 * )
 */
class DossierPresseNode extends SqlBase {

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
    ->fields('n', ['nid', 'title', 'language'])
    ->condition('n.type', 'press_kit', '=');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Dossier Presse ID'),
      'title' => $this->t('title'),
      'language' => $this->t('language'),
      'area' => $this->t('areas'),
      'body' => $this->t('body'),
      'solution' => $this->t('solution'),
      'industrie' => $this->t('industrie'),
      'partner' => $this->t('partner'),
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

    // récupération du body (short description)
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
    ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('b.bundle', 'press_kit', '=');

    $body_results = $body_query->execute()->fetchAll();

    if (is_array($body_results)){
      foreach ($body_results AS $body_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($body_result) && isset($body_result->body_value)){
          $row->setSourceProperty('body', $body_result->body_value);
        }
        elseif (is_array($body_result) && isset($body_result['body_value'])){
          $row->setSourceProperty('body', $body_result['body_value']);
        }
      }
    }

    // récupération du tag "area"
    $area_query = $this->select('field_data_field_taxo_area', 'a');
    $area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
    $area_query->fields('t', ['name'])
    ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('a.bundle', 'press_kit', '=');

    $area_results = $area_query->execute()->fetchAll();

    if (is_array($area_results)){
      foreach ($area_results AS $area_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($area_result) && isset($area_result->name)){
          $area_name = $area_result->name;
        }
        elseif (is_array($area_result) && isset($area_result['name'])){
          $area_name = $area_result['name'];
        }

        // on cherche le terme déjà existant dans la taxonomie
        if ($area_name){
          $terms = taxonomy_term_load_multiple_by_name($area_name, 'areas');

          foreach ($terms AS $key => $term){
            $row->setSourceProperty('area', $key);
          }
        }
      }
    }

    // récupération du tag "solution"
    $solution_query = $this->select('field_data_field_taxo_solution', 'a');
    $solution_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_solution_tid');
    $solution_query->fields('t', ['name'])
    ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('a.bundle', 'press_kit', '=');

    $solution_results = $solution_query->execute()->fetchAll();

    if (is_array($solution_results)){
      foreach ($solution_results AS $solution_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($solution_result) && isset($solution_result->name)){
          $solution_name = $solution_result->name;
        }
        elseif (is_array($solution_result) && isset($solution_result['name'])){
          $solution_name = $solution_result['name'];
        }

        // on cherche le terme déjà existant dans la taxonomie
        if ($solution_name){
          $terms = taxonomy_term_load_multiple_by_name($solution_name, 'solutions');

          foreach ($terms AS $key => $term){
            $row->setSourceProperty('solution', $key);
          }
        }
      }
    }

    // récupération du tag "industrie"
    $industrie_query = $this->select('field_data_field_taxo_industrie', 'a');
    $industrie_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_industrie_tid');
    $industrie_query->fields('t', ['name'])
    ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('a.bundle', 'press_kit', '=');

    $industrie_results = $industrie_query->execute()->fetchAll();

    if (is_array($industrie_results)){
      foreach ($industrie_results AS $industrie_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($industrie_result) && isset($industrie_result->name)){
          $industrie_name = $industrie_result->name;
        }
        elseif (is_array($industrie_result) && isset($industrie_result['name'])){
          $industrie_name = $industrie_result['name'];
        }

        // on cherche le terme déjà existant dans la taxonomie
        if ($industrie_name){
          $terms = taxonomy_term_load_multiple_by_name($industrie_name, 'industries');

          foreach ($terms AS $key => $term){
            $row->setSourceProperty('industrie', $key);
          }
        }
      }
    }

    // récupération du tag "partner"
    $partner_query = $this->select('field_data_field_taxo_partner', 'a');
    $partner_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_partner_tid');
    $partner_query->fields('t', ['name'])
    ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('a.bundle', 'press_kit', '=');

    $partner_results = $partner_query->execute()->fetchAll();

    if (is_array($partner_results)){
      foreach ($partner_results AS $partner_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($partner_result) && isset($partner_result->name)){
          $partner_name = $partner_result->name;
        }
        elseif (is_array($partner_result) && isset($partner_result['name'])){
          $partner_name = $partner_result['name'];
        }

        // on cherche le terme déjà existant dans la taxonomie
        if ($partner_name){
          $terms = taxonomy_term_load_multiple_by_name($partner_name, 'partners');

          foreach ($terms AS $key => $term){
            $row->setSourceProperty('partner', $key);
          }
        }
      }
    }

    // récupération des images
    $files_query = $this->select('field_data_field_press_kit_pdf', 'fi');
    $field1_alias = $files_query->addField('fi', 'field_press_kit_pdf_fid', 'mid');
    $field2_alias = $files_query->addField('fi', 'delta');
    $files_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'press_kit', '=')
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

    $row->setSourceProperty('path', '/' . $row->getSourceProperty('title'));

    return parent::prepareRow($row);
  }

}
