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
    ->fields('n', ['nid', 'title', 'language', 'created', 'changed', 'status'])
    ->condition('n.type', 'content_document_type', '=');
        $query->condition('n.changed', TIMESTAMP_MIGRATION_VALUE, TIMESTAMP_MIGRATION_OPERATOR);
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
        $title = mb_substr($title, 0, 55);
        $row->setSourceProperty('meta_title', $title) ;

        //META DESCRIPTION - récupération de la short description (txt_catcher)
        $meta_description = "";
        $catcher_query = $this->select('field_data_field_txt_catcher', 'c');
        $catcher_query->fields('c', ['field_txt_catcher_value'])
            ->condition('c.entity_id', $row->getSourceProperty('nid'), '=')
            ->condition('c.bundle', 'content_document_type', '=');

        $catcher_results = $catcher_query->execute()->fetchAll();

        if (is_array($catcher_results)) {
            foreach ($catcher_results AS $catcher_result) {

                // On vérifie si on a affaire à un objet ou à un tableau
                if (is_object($catcher_result) && isset($catcher_result->field_txt_catcher_value)) {
                    $meta_description = $catcher_result->field_txt_catcher_value;
                }
                elseif (is_array($catcher_result) && isset($catcher_result['field_txt_catcher_value'])) {
                    $meta_description = $catcher_result['field_txt_catcher_value'];
                }
            }
        }
        if (isset($meta_description) && !empty($meta_description)) {
            $row->setSourceProperty('highlight_field', $meta_description) ;
            $meta_description_short = mb_substr($meta_description, 0, 155);
            $row->setSourceProperty('meta_description', $meta_description_short) ;
        }

        //Taxonomie de la Subhome
        $subhomes = \Drupal::state()->get('subhomes_ids_for_migration');
        if (isset($subhomes['library'][$row->getSourceProperty('language')])
            && isset($subhomes['library'][$row->getSourceProperty('language')]['tid_D8'])
            && !empty($subhomes['library'][$row->getSourceProperty('language')]['tid_D8'])) {
            $row->setSourceProperty('subhomes', $subhomes['library'][$row->getSourceProperty('language')]['tid_D8']);
        }

    // récupération du body
    $body_query = $this->select('field_data_body', 'b');
    $body_query->fields('b', ['body_value'])
      ->condition('b.entity_id', $row->getSourceProperty('nid'), '=')
      ->condition('b.bundle', 'content_document_type', '=');

    $body_results = $body_query->execute()->fetchAll();

    if (is_array($body_results)) {
      foreach ($body_results AS $body_result) {

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($body_result) && isset($body_result->body_value)) {
          $body_value = $body_result->body_value;
          $body_value = preg_replace(array('@<br>\r\n@', '@<br>\n\r@', '@<br>\n@', '@<br>\r@'), '<br>', $body_value);
          $body_value = oab_migrate_wysiwyg_images($body_value, $row->getSourceProperty('nid'));
          $row->setSourceProperty('content_field', $body_value);
        }
        elseif (is_array($body_result) && isset($body_result['body_value'])) {
          $body_value = $body_result['body_value'];
          $body_value = preg_replace(array('@<br>\r\n@', '@<br>\n\r@', '@<br>\n@', '@<br>\r@'), '<br>', $body_value);
          $body_value = oab_migrate_wysiwyg_images($body_value, $row->getSourceProperty('nid'));
          $row->setSourceProperty('content_field', $body_value);
        }
      }
    }


    /*
     * Récuperation des TAGS
     */

        // récupération du tag "document_type"
        $doc_types = get_correspondance_tid_D7_tid_D8('correspondence_format_document',
            'field_data_field_taxo_document_type',
            'field_taxo_document_type_tid',
            $row->getSourceProperty('nid'),
            'content_document_type');
        if (count($doc_types) > 0) {
            $row->setSourceProperty('document_types', $doc_types);
        }

        // récupération du tag "industries"
        $industries = get_correspondance_tid_D7_tid_D8('correspondence_taxo_industry',
            'field_data_field_taxo_industrie',
            'field_taxo_industrie_tid',
            $row->getSourceProperty('nid'),
            'content_document_type');
        if (count($industries) > 0) {
            $row->setSourceProperty('industries', $industries);
        }

        // récupération du tag "solution vers document thematic
        $doc_theme = get_correspondance_tid_D7_tid_D8('correspondence_solution_to_theme_doc',
            'field_data_field_taxo_solution',
            'field_taxo_solution_tid',
            $row->getSourceProperty('nid'),
            'content_document_type');
        if (count($doc_theme) > 0) {
            $row->setSourceProperty('document_thematics', $doc_theme);
        }
        // solution vers insight
        $insight = get_correspondance_tid_D7_tid_D8('correspondence_taxo_solution_to_thematic',
            'field_data_field_taxo_solution',
            'field_taxo_solution_tid',
            $row->getSourceProperty('nid'),
            'content_document_type');
        if (count($insight) > 0) {
            $row->setSourceProperty('thematics', $insight);
        }

        // récupération du tag "area"
        $regions = get_correspondance_tid_D7_tid_D8('correspondence_taxo_region',
            'field_data_field_taxo_area',
            'field_taxo_area_tid',
            $row->getSourceProperty('nid'),
            'content_document_type');
        if (count($regions) > 0) {
            $row->setSourceProperty('regions', $regions);
        }

    // récupération des fichiers PDF
    $files_query = $this->select('field_data_field_file_upl', 'fi');
    $field1_alias = $files_query->addField('fi', 'field_file_upl_fid', 'mid');
    $field2_alias = $files_query->addField('fi', 'delta');
    $files_query->condition('fi.entity_id', $row->getSourceProperty('nid'), '=')
    ->condition('fi.bundle', 'content_document_type', '=')
    ->orderBy('fi.delta', 'ASC');


    $files_results = $files_query->execute()->fetchAll();

    if (is_array($files_results)) {
      $files = array();
      foreach ($files_results AS $files_result) {

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($files_result) && isset($files_result->mid)) {
          $files[] = $files_result->mid;
        }
        elseif (is_array($files_result) && isset($files_result['mid'])) {
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

    if (is_array($images_results)) {
      $images = array();
      foreach ($images_results AS $images_result) {

        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($images_result) && isset($images_result->mid)) {
          $images[] = $images_result->mid;
        }
        elseif (is_array($images_result) && isset($images_result['mid'])) {
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

    if (is_array($workflow_results)) {
      foreach ($workflow_results AS $workflow_result) {
        $sid = '';
        // On vérifie si on a affaire à un objet ou à un tableau
        if (is_object($workflow_result) && isset($workflow_result->sid)) {
          $sid = $workflow_result->sid;
        }
        elseif (is_array($workflow_result) && isset($workflow_result['sid'])) {
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

    if (is_object($path_results)) {
            $row->setSourceProperty('path', array('alias' => '/' . $path_results->alias, 'pathauto' => 'false'));
    }

    return parent::prepareRow($row);
  }

}
