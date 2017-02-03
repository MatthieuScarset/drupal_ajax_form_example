<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Document;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "document_node"
 * )
 */
class DocumentNode extends SqlBase {

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
    ->condition('n.type', 'content_document_type', '=');
    //->range(0, 10);

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Document ID'),
      'title' => $this->t('title'),
      'language' => $this->t('language'),
      'areas' => $this->t('areas'),
      'topics' => $this->t('topics'),
      'solutions' => $this->t('solutions'),
      'industries' => $this->t('industries'),
      'customer_stories' => $this->t('customer_stories'),
      'partners' => $this->t('partners'),
      'body' => $this->t('body'),
      'image' => $this->t('image'),
      'file' => $this->t('file'),
      'short_description' => $this->t('short_description'),
      'subtitle' => $this->t('subtitle'),
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

    //Taxonomie de la Section
    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree('subhomes', 0, NULL, TRUE);
    $subhomes = array();
    foreach ($terms AS $key => $term){
      $machine_name = $term->get('field_machine_name')->value;
      $langCode = $term->get('langcode')->value;
      if ($machine_name == 'realtimes' && $langCode == $row->getSourceProperty('language')){
        $sections[] = $term->get('tid')->value;
      }
    }
    $row->setSourceProperty('subhomes', $subhomes);

    // récupération du body
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'content_document_type', '=');

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

    // récupération du subtitle
    $descriptif_query = $this->select('field_data_field_descriptif_court', 'd');
    $descriptif_query->fields('d', ['field_descriptif_court_value'])
      ->condition('d.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('d.bundle', 'content_document_type', '=');

    $descriptif_results = $descriptif_query->execute()->fetchAll();

    if (is_array($descriptif_results)){
      foreach ($descriptif_results AS $descriptif_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($descriptif_result) && isset($descriptif_result->field_descriptif_court_value)){
          $row->setSourceProperty('subtitle', $descriptif_result->field_descriptif_court_value);
        }
        elseif (is_array($descriptif_result) && isset($descriptif_result['field_descriptif_court_value'])){
          $row->setSourceProperty('subtitle', $descriptif_result['field_descriptif_court_value']);
        }
      }
    }

    // récupération de la short description (txt_catcher)
    $catcher_query = $this->select('field_data_field_txt_catcher', 'c');
    $catcher_query->fields('c', ['field_txt_catcher_value'])
      ->condition('c.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('c.bundle', 'content_document_type', '=');

    $catcher_results = $catcher_query->execute()->fetchAll();

    if (is_array($catcher_results)){
      foreach ($catcher_results AS $catcher_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($catcher_result) && isset($catcher_result->field_txt_catcher_value)){
          $row->setSourceProperty('short_description', $catcher_result->field_txt_catcher_value);
        }
        elseif (is_array($catcher_result) && isset($catcher_result['field_txt_catcher_value'])){
          $row->setSourceProperty('short_description', $catcher_result['field_txt_catcher_value']);
        }
      }
    }

    /*
     * Récuperation des TAGS
     */

    // récupération du tag "document_type"
    $document_type_query = $this->select('field_data_field_taxo_document_type', 'dt');
    $document_type_query->join('taxonomy_term_data', 't', 't.tid = dt.field_taxo_document_type_tid');
    $document_type_query->fields('t', ['tid'])
      ->condition('dt.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('dt.bundle', 'content_document_type', '=');
    $document_type_results = $document_type_query->execute()->fetchAll();
    if (is_array($document_type_results)){
      $document_types = array();
      foreach ($document_type_results AS $document_type_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($document_type_result) && isset($document_type_result->tid)){
          $document_types[] = $document_type_result->tid;
        }
        elseif (is_array($document_type_result) && isset($document_type_result['tid'])){
          $document_types[] = $document_type_result['tid'];
        }
      }
      $row->setSourceProperty('document_types', $document_types);
    }

    // récupération du tag "industries"
    $industrie_query = $this->select('field_data_field_taxo_industrie', 'i');
    $industrie_query->join('taxonomy_term_data', 't', 't.tid = i.field_taxo_industrie_tid');
    $industrie_query->fields('t', ['tid'])
      ->condition('i.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('i.bundle', 'content_document_type', '=');
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

    // récupération du tag "solution"
    $solution_query = $this->select('field_data_field_taxo_solution', 's');
    $solution_query->join('taxonomy_term_data', 't', 't.tid = s.field_taxo_solution_tid');
    $solution_query->fields('t', ['tid'])
      ->condition('s.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('s.bundle', 'content_document_type', '=');
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

    // récupération du tag "partner"
    $partner_query = $this->select('field_data_field_taxo_partner', 'p');
    $partner_query->join('taxonomy_term_data', 't', 't.tid = p.field_taxo_partner_tid');
    $partner_query->fields('t', ['tid'])
      ->condition('p.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('p.bundle', 'content_document_type', '=');
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

    // récupération du tag "area"
    $area_query = $this->select('field_data_field_taxo_area', 'a');
    $area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
    $area_query->fields('t', ['tid'])
      ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('a.bundle', 'content_document_type', '=');
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

    // récupération du tag "case studies"
    $customer_stories_query = $this->select('field_data_field_taxo_customer_stories', 'cs');
    $customer_stories_query->join('taxonomy_term_data', 't', 't.tid = cs.field_taxo_customer_stories_tid');
    $customer_stories_query->fields('t', ['name'])
      ->condition('cs.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('cs.bundle', 'content_document_type', '=');
    $customer_stories_results = $customer_stories_query->execute()->fetchAll();
    if (is_array($customer_stories_results)){
      $customers = array();
      foreach ($customer_stories_results AS $customer_stories_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($customer_stories_result) && isset($customer_stories_result->tid)){
          $customers[] = $customer_stories_result->tid;
        }
        elseif (is_array($customer_stories_result) && isset($customer_stories_result['tid'])){
          $customers[] = $customer_stories_result['tid'];
        }
      }
      $row->setSourceProperty('customer_stories', $customers);
    }

    // récupération du tag "topic"
    $topic_query = $this->select('field_data_field_taxo_topic', 'tao');
    $topic_query->join('taxonomy_term_data', 't', 't.tid = tao.field_taxo_topic_tid');
    $topic_query->fields('t', ['tid'])
      ->condition('tao.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tao.bundle', 'content_document_type', '=');
    $topic_results = $topic_query->execute()->fetchAll();
    if (is_array($topic_results)){
      $topics = array();
      foreach ($topic_results AS $topic_result){

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($topic_result) && isset($topic_result->tid)){
          $topics[] = $topic_result->tid;
        }
        elseif (is_array($topic_result) && isset($topic_result['tid'])){
          $topics[] = $topic_result['tid'];
        }
      }
      $row->setSourceProperty('topics', $topics);
    }

    // récupération des fichiers PDF
    $files_query = $this->select('field_data_field_file_upl', 'fi');
    $field1_alias = $files_query->addField('fi', 'field_file_upl_fid', 'mid');
    $field2_alias = $files_query->addField('fi', 'delta');
    $files_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'content_document_type', '=')
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

    // récupération des images
    $images_query = $this->select('field_data_field_image', 'fi');
    $field1_alias = $images_query->addField('fi', 'field_image_fid', 'mid');
    $field2_alias = $images_query->addField('fi', 'delta');
    $images_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'content_document_type', '=')
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

    /*
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
    */

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
