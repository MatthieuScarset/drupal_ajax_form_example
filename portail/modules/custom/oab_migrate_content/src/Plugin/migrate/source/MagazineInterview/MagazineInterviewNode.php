<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\MagazineInterview;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "magazineinterview_node"
 * )
 */
class MagazineInterviewNode extends SqlBase {

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
      ->fields('n', ['nid', 'title', 'language', 'created', 'changed'])
      ->condition('n.type', 'content_magazine_interview', '=')
      ->condition('n.changed', MAGAZINE_INTERVIEW_SELECT_DATE, '>');
    //->condition('n.nid', array(4836,4837,4838,4839,4840,4841,4842,4843,4844), 'IN');
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
    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree('rendering_model', 0, NULL, TRUE);

    foreach ($terms AS $key => $term){
      $machine_name = $term->get('field_machine_name')->value;
      if ($machine_name == 'magazine_interview'){
        $row->setSourceProperty('rendering_model_id', $term->get('tid')->value);
      }
    }

    // création du verbatim
    $field_txt_citation_1_value = '';
    $field_txt_auteur_1_value = '';
    $field_location_value = '';
    $field_profil_value = '';

    $verbatim_tables = array(
      'field_data_field_txt_citation_1' => 'field_txt_citation_1_value',
      'field_data_field_txt_auteur_1' => 'field_txt_auteur_1_value',
      'field_data_field_location' => 'field_location_value',
      'field_data_field_profil' => 'field_profil_value',
    );

    foreach ($verbatim_tables AS $table => $field){
      $verbatim_query = $this->select($table, 'b');
      $verbatim_query->fields('b', [$field])
        ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
        ->condition('b.bundle', 'content_magazine_interview', '=');

      $verbatim_results = $verbatim_query->execute()->fetchAll();

      if (is_array($verbatim_results)){
        foreach ($verbatim_results AS $verbatim_result){

          // On vérifie si on a affaire à un objet ou à un tableau
          if (is_object($verbatim_result) && isset($verbatim_result->$field)){
            $$field = $verbatim_result->$field;
          }
          elseif (is_array($verbatim_result) && isset($verbatim_result[$field])){
            $$field = $verbatim_result[$field];
          }
        }
      }
    }

    // récupération du BODY
    $body_value = '';
    $body_query = $this->select('field_data_field_content', 'b');
    $body_query->fields('b', ['field_content_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'content_magazine_interview', '=');

    $body_results = $body_query->execute()->fetchAll();

    if (is_array($body_results)){
      foreach ($body_results AS $body_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($body_result) && isset($body_result->field_content_value)){
          $body_value = $body_result->field_content_value;
        }
        elseif (is_array($body_result) && isset($body_result['field_content_value'])){
          $body_value = $body_result['field_content_value'];
        }
      }
    }
    $verbatim_content = '<div class="bg bg_darkgrey">';
    if ($field_txt_citation_1_value !== '') $verbatim_content .= '<p class="highlight">"' . $field_txt_citation_1_value . '"</p>';
    if ($field_txt_auteur_1_value !== '') $verbatim_content .= '<p>' . $field_txt_auteur_1_value . '</p>';
    if ($field_location_value !== '') $verbatim_content .= '<p>' . $field_location_value . '</p>';
    if ($field_profil_value !== '') $verbatim_content .= '<p>' . $field_profil_value . '</p>';
    $verbatim_content .= '</div>';

    $row->setSourceProperty('content_field', array(
      array('value' => $verbatim_content, 'format' => 'full_html', 'zone' => 'default'),
      array('value' => $body_value, 'format' => 'full_html', 'zone' => 'default'),
    ));

    // récupération du SUBTITLE
    $subtitle_query = $this->select('field_data_field_descriptif_court', 'd');
    $subtitle_query->fields('d', ['field_descriptif_court_value'])
      ->condition('d.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('d.bundle', 'content_magazine_interview', '=');

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
      ->condition('tc.bundle', 'content_magazine_interview', '=');

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
      ->condition('tm.bundle', 'content_magazine_interview', '=');
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
      ->condition('ti.bundle', 'content_magazine_interview', '=');
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
      ->condition('ts.bundle', 'content_magazine_interview', '=');
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
      ->condition('tp.bundle', 'content_magazine_interview', '=');
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
      ->condition('ta.bundle', 'content_magazine_interview', '=');
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
      ->condition('tcs.bundle', 'content_magazine_interview', '=');
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
      ->condition('fi.bundle', 'content_magazine_interview', '=')
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

        $workflow_new_state = oab_migrate_workflow_sid_correspondance((int)$sid);
        $row->setSourceProperty('workflow', $workflow_new_state);
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
