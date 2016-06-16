<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\MagazineArticle;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "magazinearticle_node"
 * )
 */
class MagazineArticleNode extends SqlBase {

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
      ->condition('n.type', 'content_magazine_article', '=')
      ->condition('n.status', 1, '=')
      ->condition('n.changed', MAGAZINE_ARTICLE_SELECT_DATE, '>');
    //  ->condition('n.nid', array(4633, 4636, 4638, 4639, 4661, 4662), 'IN');
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
    // On change le current user car l'utilisateur anonyme (0) pose des problèmes avec le workflow
    $admin_user = \Drupal\user\Entity\User::load(1);
    \Drupal::getContainer()->set('current_user', $admin_user);

    //Id du rendering_model
    $terms = taxonomy_term_load_multiple_by_name("magazine", 'rendering_model');

    foreach ($terms AS $key => $term){
      $row->setSourceProperty('rendering_model_id', $key);
    }


    // récupération du BODY
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'content_magazine_article', '=');

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

    // récupération du SUBTITLE
    $subtitle_query = $this->select('field_data_field_descriptif_court', 'd');
    $subtitle_query->fields('d', ['field_descriptif_court_value'])
      ->condition('d.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('d.bundle', 'content_magazine_article', '=');

    $subtitle_results = $subtitle_query->execute()->fetchAll();

    if (is_array($subtitle_results)){
      foreach ($subtitle_results AS $subtitle_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($subtitle_result) && isset($subtitle_result->field_descriptif_court_value)){
          $row->setSourceProperty('subtitle', $subtitle_result->field_descriptif_court_value);
        }
        elseif (is_array($subtitle_result) && isset($subtitle_result['field_descriptif_court_value'])){
          $row->setSourceProperty('subtitle', $subtitle_result['field_descriptif_court_value']);
        }
      }
    }

    // récupération du SHORT DESCRIPTION
    $shortdesc_query = $this->select('field_data_field_txt_catcher', 'tc');
    $shortdesc_query->fields('tc', ['field_txt_catcher_value'])
      ->condition('tc.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tc.bundle', 'content_magazine_article', '=');

    $shortdesc_results = $shortdesc_query->execute()->fetchAll();

    if (is_array($shortdesc_results)){
      foreach ($shortdesc_results AS $shortdesc_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($shortdesc_result) && isset($shortdesc_result->field_txt_catcher_value)){
          $row->setSourceProperty('short_description', $shortdesc_result->field_txt_catcher_value);
        }
        elseif (is_array($shortdesc_result) && isset($shortdesc_result['field_txt_catcher_value'])){
          $row->setSourceProperty('short_description', $shortdesc_result['field_txt_catcher_value']);
        }
      }
    }

    /*
     * récupération des tags
     */

    //MAGAZINE
    $categories_query = $this->select('field_data_field_taxo_magazine', 'tm');
    $categories_query->join('taxonomy_term_data', 't', 't.tid = tm.field_taxo_magazine_tid');
    $categories_query->fields('t', ['tid'])
      ->condition('tm.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tm.bundle', 'content_magazine_article', '=');
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

    //INDUSTRIES
    $industries_query = $this->select('field_data_field_taxo_industrie', 'ti');
    $industries_query->join('taxonomy_term_data', 't', 't.tid = ti.field_taxo_industrie_tid');
    $industries_query->fields('t', ['tid'])
      ->condition('ti.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('ti.bundle', 'content_magazine_article', '=');
    $industries_results = $industries_query->execute()->fetchAll();
    if (is_array($industries_results)){
      $industries = array();
      foreach ($industries_results AS $industries_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($industries_result) && isset($industries_result->tid)){
          $industries[] = $industries_result->tid;
        }
        elseif (is_array($industries_result) && isset($industries_result['tid'])){
          $industries[] = $industries_result['tid'];
        }
      }
      $row->setSourceProperty('industries', $industries);
    }

    //SOLUTIONS
    $solutions_query = $this->select('field_data_field_taxo_solution', 'ts');
    $solutions_query->join('taxonomy_term_data', 't', 't.tid = ts.field_taxo_solution_tid');
    $solutions_query->fields('t', ['tid'])
      ->condition('ts.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('ts.bundle', 'content_magazine_article', '=');
    $solutions_results = $solutions_query->execute()->fetchAll();
    if (is_array($solutions_results)){
      $solutions = array();
      foreach ($solutions_results AS $solutions_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($solutions_result) && isset($solutions_result->tid)){
          $solutions[] = $solutions_result->tid;
        }
        elseif (is_array($solutions_result) && isset($solutions_result['tid'])){
          $solutions[] = $solutions_result['tid'];
        }
      }
      $row->setSourceProperty('solutions', $solutions);
    }

    //PARTNERS
    $partners_query = $this->select('field_data_field_taxo_partner', 'tp');
    $partners_query->join('taxonomy_term_data', 't', 't.tid = tp.field_taxo_partner_tid');
    $partners_query->fields('t', ['tid'])
      ->condition('tp.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tp.bundle', 'content_magazine_article', '=');
    $partners_results = $partners_query->execute()->fetchAll();
    if (is_array($partners_results)){
      $partners = array();
      foreach ($partners_results AS $partners_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($partners_result) && isset($partners_result->tid)){
          $partners[] = $partners_result->tid;
        }
        elseif (is_array($partners_result) && isset($partners_result['tid'])){
          $partners[] = $partners_result['tid'];
        }
      }
      $row->setSourceProperty('partners', $partners);
    }

    //AREAS
    $areas_query = $this->select('field_data_field_taxo_area', 'ta');
    $areas_query->join('taxonomy_term_data', 't', 't.tid = ta.field_taxo_area_tid');
    $areas_query->fields('t', ['tid'])
      ->condition('ta.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('ta.bundle', 'content_magazine_article', '=');
    $areas_results = $areas_query->execute()->fetchAll();
    if (is_array($areas_results)){
      $areas = array();
      foreach ($areas_results AS $areas_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($areas_result) && isset($areas_result->tid)){
          $areas[] = $areas_result->tid;
        }
        elseif (is_array($areas_result) && isset($areas_result['tid'])){
          $areas[] = $areas_result['tid'];
        }
      }
      $row->setSourceProperty('areas', $areas);
    }

    //CUSTOMER STORIES
    $customer_query = $this->select('field_data_field_taxo_customer_stories', 'tcs');
    $customer_query->join('taxonomy_term_data', 't', 't.tid = tcs.field_taxo_customer_stories_tid');
    $customer_query->fields('t', ['tid'])
      ->condition('tcs.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tcs.bundle', 'content_magazine_article', '=');
    $customer_results = $customer_query->execute()->fetchAll();
    if (is_array($customer_results)){
      $customers = array();
      foreach ($customer_results AS $customer_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($customer_result) && isset($customer_result->tid)){
          $customers[] = $customer_result->tid;
        }
        elseif (is_array($customer_result) && isset($customer_result['tid'])){
          $customers[] = $customer_result['tid'];
        }
      }
      $row->setSourceProperty('customer_stories', $customers);
    }

    // récupération des images
    $images_query = $this->select('field_data_field_image', 'fi');
    $field1_alias = $images_query->addField('fi', 'field_image_fid', 'mid');
    $field2_alias = $images_query->addField('fi', 'delta');
    $images_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('fi.bundle', 'content_magazine_article', '=')
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

    // récupération du workflow
    $workflow_query = $this->select('workflow_node', 'w');
    $workflow_query->fields('w', ['sid'])
      ->condition('w.nid', $row->getSourceProperty('nid'), '=');

    $workflow_results = $workflow_query->execute()->fetchAll();

    if (is_array($workflow_results)){
      foreach ($workflow_results AS $workflow_result){
        $sid = '';
        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($workflow_result) && isset($workflow_result->sid)){
          $sid = $workflow_result->sid;
        }
        elseif (is_array($workflow_result) && isset($workflow_result['sid'])){
          $sid = $workflow_result['sid'];
        }

        $row->setSourceProperty('workflow', oab_migrate_workflow_sid_correspondance($sid));
      }
    }

    $workflow_scheduled_query = $this->select('workflow_scheduled_transition', 'wst');
    $workflow_scheduled_query->fields('wst', ['sid', 'scheduled', 'comment'])
      ->condition('wst.nid', $row->getSourceProperty('nid'))
      ->condition('wst.entity_type', 'node');

    $workflow_scheduled_results = $workflow_scheduled_query->execute()->fetchAll();

    if (is_array($workflow_scheduled_results)) {
      foreach ($workflow_scheduled_results AS $workflow_scheduled_result) {
        $scheduled_sid = '';
        $scheduled_timestamp = '';
        $scheduled_comment = '';
        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($workflow_scheduled_result) && isset($workflow_scheduled_result->sid) && isset($workflow_scheduled_result->scheduled)) {
          $scheduled_sid = $workflow_scheduled_result->sid;
          $scheduled_timestamp = $workflow_scheduled_result->scheduled;
          $scheduled_comment = isset($workflow_scheduled_result->comment) ? isset($workflow_scheduled_result->comment) : '';
        }
        elseif (is_array($workflow_scheduled_result) && isset($workflow_scheduled_result['sid']) && isset($workflow_scheduled_result['scheduled'])) {
          $scheduled_sid = $workflow_scheduled_result['sid'];
          $scheduled_timestamp = $workflow_scheduled_result['scheduled'];
          $scheduled_comment = isset($workflow_scheduled_result['comment']) ? isset($workflow_scheduled_result['comment']) : '';
        }

        $row->setSourceProperty('workflow_transition_state', oab_migrate_workflow_sid_correspondance($scheduled_sid));
        $row->setSourceProperty('workflow_transition_time', $scheduled_timestamp);
        $row->setSourceProperty('workflow_transition_comment', $scheduled_comment);
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
