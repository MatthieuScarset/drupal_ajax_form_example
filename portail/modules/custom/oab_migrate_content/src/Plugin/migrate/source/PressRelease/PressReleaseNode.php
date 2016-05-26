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
    ->fields('n', ['nid', 'title', 'language'])
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
      'area' => $this->t('areas'),
      'body' => $this->t('body'),
      'file' => $this->t('file'),
      'country' => $this->t('country'),
      'city' => $this->t('city'),
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

    // récupération de country et city
    $address_query = $this->select('location_instance', 'li');
    $address_query->join('location', 'l', 'l.lid = li.lid');
    $address_query->fields('l', ['city', 'country'])
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
    ->condition('a.bundle', 'content_press_release', '=');


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

    $row->setSourceProperty('path', '/' . $row->getSourceProperty('title'));

    return parent::prepareRow($row);
  }

}
