<?php

/**
 * @file
 * Contains \Drupal\migrate_example\Plugin\migrate\source\BeerNode.
 */

namespace Drupal\oab_migrate_content\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "office_node"
 * )
 */
class OfficeNode extends SqlBase {

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
    ->fields('n', ['nid', 'title'])
    ->condition('n.type', 'content_presence_worldwide', '=');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Office ID'),
      'title' => $this->t('title'),
      'latitude' => $this->t('latitude'),
      'longitude' => $this->t('longitude'),
      'street' => $this->t('street'),
      'city' => $this->t('city'),
      'additional' => $this->t('additional'),
      'postal_code' => $this->t('postal code'),
      'country' => $this->t('country'),
      'area' => $this->t('areas'),
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
    // récupération de l'adresse
    $address_query = $this->select('location_instance', 'li');
    $address_query->join('location', 'l', 'l.lid = li.lid');
    $address_query->fields('l', ['latitude', 'longitude', 'street', 'city', 'additional', 'postal_code', 'country'])
    ->condition('li.nid', $row->getSourceProperty('nid'), '=');

    $address_results = $address_query->execute()->fetchObject();

    if (is_object($address_results)){
      foreach ($address_results AS $key => $value){
        if ($key == 'country'){
          $row->setSourceProperty($key, strtoupper($value));
        }
        else{
          $row->setSourceProperty($key, $value);
        }
      }
    }
    $row->setSourceProperty('langcode', 'fr');


    // récupération du tag "area"
    $area_query = $this->select('field_data_field_taxo_area', 'a');
    $area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
    $area_query->fields('t', ['name'])
    ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('a.bundle', 'content_presence_worldwide', '=');

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

    return parent::prepareRow($row);
  }

}
