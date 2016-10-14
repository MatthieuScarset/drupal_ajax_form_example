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
    ->fields('n', ['nid', 'title', 'language', 'created', 'changed'])
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
      'catcher' => $this->t('catcher'),
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
    // On change le current user car l'utilisateur anonyme (0) pose des problèmes avec le workflow
    $admin_user = \Drupal\user\Entity\User::load(1);
    \Drupal::getContainer()->set('current_user', $admin_user);

    //Id du rendering_model
    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree('rendering_model', 0, NULL, TRUE);

    foreach ($terms AS $key => $term){
      $machine_name = $term->get('field_machine_name')->value;
      if ($machine_name == 'press_release'){
        $row->setSourceProperty('rendering_model_id', $term->get('tid')->value);
      }
    }

    //Taxonomie de la Section
    $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree('sections', 0, NULL, TRUE);
    $sections = array();
    foreach ($terms AS $key => $term){
      $machine_name = $term->get('field_machine_name')->value;
      $langCode = $term->get('langcode')->value;
      if ($machine_name == 'corporate' && $langCode == $row->getSourceProperty('language')){
        $sections[] = $term->get('tid')->value;
      }
    }
    $row->setSourceProperty('sections', $sections);

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
          $row->setSourceProperty('city', $city_results->field_location_value);
        }
        elseif (is_array($city_results) && isset($city_results['field_location_value'])){
          $row->setSourceProperty('city', $city_results['field_location_value']);
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

    // récupération de la short description (txt_catcher)
    $catcher_query = $this->select('field_data_field_txt_catcher', 'tc');
    $catcher_query->fields('tc', ['field_txt_catcher_value'])
      ->condition('tc.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tc.bundle', 'content_press_release', '=');

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
     * Récupération des TAGS
     */

    // récupération du tag "industries"
    $industrie_query = $this->select('field_data_field_taxo_industrie', 'ti');
    $industrie_query->join('taxonomy_term_data', 't', 't.tid = ti.field_taxo_industrie_tid');
    $industrie_query->fields('t', ['tid'])
      ->condition('ti.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('ti.bundle', 'content_press_release', '=');

    $industrie_results = $industrie_query->execute()->fetchAll();

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

    // récupération du tag "solution"
    $solution_query = $this->select('field_data_field_taxo_solution', 'a');
    $solution_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_solution_tid');
    $solution_query->fields('t', ['tid'])
      ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('a.bundle', 'content_press_release', '=');
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
    $partner_query = $this->select('field_data_field_taxo_partner', 'tp');
    $partner_query->join('taxonomy_term_data', 't', 't.tid = tp.field_taxo_partner_tid');
    $partner_query->fields('t', ['tid'])
      ->condition('tp.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('tp.bundle', 'content_press_release', '=');

    $partner_results = $partner_query->execute()->fetchAll();

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


    // récupération du tag "area"
    $area_query = $this->select('field_data_field_taxo_area', 'a');
    $area_query->join('taxonomy_term_data', 't', 't.tid = a.field_taxo_area_tid');
    $area_query->fields('t', ['tid'])
      ->condition('a.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('a.bundle', 'content_press_release', '=');
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
    $customer_stories_query->fields('t', ['tid'])
      ->condition('cs.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('cs.bundle', 'content_press_release', '=');
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
