<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "blogpost_node"
 * )
 */
class BlogPostNode extends SqlBase {

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
    ->condition('n.type', 'blog_post', '=')
    ->condition('n.status', 1, '=')
    ->condition('n.changed', time() - BLOGPOST_SELECT_DATE, '>');
    //->condition('n.nid', array(11430, 11429), 'IN');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Node ID'),
      'title' => $this->t('title'),
      'language' => $this->t('language'),
      'body' => $this->t('body'),
      'image' => $this->t('image'),
      'category' => $this->t('category'),
      'areas' => $this->t('areas'),
      'solutions' => $this->t('solutions'),
      'industries' => $this->t('industries'),
      'customer_stories' => $this->t('customer_stories'),
      'partners' => $this->t('partners'),
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

    //Id du rendering_model TODO : changer la taxo magazine
    $terms = taxonomy_term_load_multiple_by_name("magazine", 'rendering_model');

    foreach ($terms AS $key => $term){
      $row->setSourceProperty('rendering_model_id', $key);
    }

    // récupération du body
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'blog_post', '=');

    $body_results = $body_query->execute()->fetchAll();

    if (is_array($body_results)){
      foreach ($body_results AS $body_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($body_result) && isset($body_result->body_value)){
          $row->setSourceProperty('content_field', $body_result->body_value);
        }
        elseif (is_array($body_result) && isset($body_result['body_value'])){
          $row->setSourceProperty('content_field', $body_result['body_value']);
        }
      }
    }

    // récupération des tags

    //TAG category
    $categories_query = $this->select('field_data_field_taxo_blog', 'tb');
    $field1_alias = $categories_query->addField('tb', 'field_taxo_blog_tid', 'tid');
    $field2_alias = $categories_query->addField('tb', 'delta');
    //->fields('tb', ['field_taxo_blog_tid'])
    $categories_query->condition('tb.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tb.bundle', 'blog_post', '=')
      ->orderBy('tb.delta', 'ASC');


    $categories_results = $categories_query->execute()->fetchAll();

    if (is_array($categories_results)){
      $categories = array();
      foreach ($categories_results AS $categories_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($categories_result) && isset($categories_result->tid)){
          $categories[] = $categories_result->tid;
        }
        elseif (is_array($categories_result) && isset($categories_result['tid'])){
          $categories[] = $categories_result['tid'];
        }
      }
      $row->setSourceProperty('categories', $categories);
    }

    //TAG industry
    $industrie_query = $this->select('field_data_field_taxo_industrie', 'i');
    $industrie_query->join('taxonomy_term_data', 't', 't.tid = i.field_taxo_industrie_tid');
    $industrie_query->fields('t', ['tid'])
      ->condition('i.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('i.bundle', 'blog_post', '=');

    $industrie_results = $industrie_query->execute()->fetchAll();

    if (is_array($industrie_results)){
      $industries = array();
      foreach ($industrie_results AS $industrie_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($industrie_result) && isset($industrie_result->tid)){
          $industries[] = $industrie_result->tid;
        }
        elseif (is_array($industrie_result) && isset($industrie_result['tid'])){
          $industries[] = $industrie_result['tid'];
        }
      }
      $row->setSourceProperty('industries', $industries);
    }

    //TAG Solutions
    $solution_query = $this->select('field_data_field_taxo_solution', 's');
    $solution_query->join('taxonomy_term_data', 't', 't.tid = s.field_taxo_solution_tid');
    $solution_query->fields('t', ['tid'])
      ->condition('s.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('s.bundle', 'blog_post', '=');

    $solution_results = $solution_query->execute()->fetchAll();

    if (is_array($solution_results)){
      $solutions = array();
      foreach ($solution_results AS $solution_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($solution_result) && isset($solution_result->tid)){
          $solutions[] = $solution_result->tid;
        }
        elseif (is_array($solution_result) && isset($solution_result['tid'])){
          $solutions[] = $solution_result['tid'];
        }
      }
      $row->setSourceProperty('solutions', $solutions);
    }

    //tag "partner"
    $partner_query = $this->select('field_data_field_taxo_partner', 'p');
    $partner_query->join('taxonomy_term_data', 't', 't.tid = p.field_taxo_partner_tid');
    $partner_query->fields('t', ['tid'])
      ->condition('p.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('p.bundle', 'blog_post', '=');

    $partner_results = $partner_query->execute()->fetchAll();

    if (is_array($partner_results)){
      $partners = array();
      foreach ($partner_results AS $partner_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($partner_result) && isset($partner_result->tid)){
          $partners[] = $partner_result->tid;
        }
        elseif (is_array($partner_result) && isset($partner_result['tid'])){
          $partners[] = $partner_result['tid'];
        }
      }
      $row->setSourceProperty('partners', $partners);
    }


    // TAG "area"
    $area_query = $this->select('field_data_field_taxo_area', 'a');
    $area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
    $area_query->fields('t', ['tid'])
      ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('a.bundle', 'blog_post', '=');
    $area_results = $area_query->execute()->fetchAll();
    if (is_array($area_results)){
      $areas = array();
      foreach ($area_results AS $area_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($area_result) && isset($area_result->tid)){
          $areas[] = $area_result->tid;
        }
        elseif (is_array($area_result) && isset($area_result['tid'])){
          $areas[] = $area_result['tid'];
        }
      }
      $row->setSourceProperty('areas', $areas);
    }

    // tag "case studies"
    $customer_stories_query = $this->select('field_data_field_taxo_customer_stories', 'cs');
    $customer_stories_query->join('taxonomy_term_data', 't', 't.tid = cs.field_taxo_customer_stories_tid');
    $customer_stories_query->fields('t', ['tid'])
      ->condition('cs.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('cs.bundle', 'blog_post', '=');
    $customer_stories_results = $customer_stories_query->execute()->fetchAll();
    if (is_array($customer_stories_results)){
      $customers = array();
      foreach ($customer_stories_results AS $customer_stories_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($customer_stories_result) && isset($customer_stories_result->tid)){
          $customer_stories_name = $customer_stories_result->tid;
        }
        elseif (is_array($customer_stories_result) && isset($customer_stories_result['tid'])){
          $customer_stories_name = $customer_stories_result['tid'];
        }
      }
      $row->setSourceProperty('customer_stories', $customers);
    }


    // récupération des images
    $images_query = $this->select('field_data_field_image', 'fi');
    $field1_alias = $images_query->addField('fi', 'field_image_fid', 'mid');
    $field2_alias = $images_query->addField('fi', 'delta');
    $images_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'blog_post', '=')
    ->orderBy('fi.delta', 'ASC');


    $images_results = $images_query->execute()->fetchAll();

    if (is_array($images_results)){
      $images = array();
      foreach ($images_results AS $images_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($images_result) && isset($images_result->mid)){
          $images[] = $images_result->mid;
        }
        elseif (is_array($images_result) && isset($images_result['mid'])){
          $images[] = $images_result['mid'];
        }
      }
      $row->setSourceProperty('images', $images);
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
