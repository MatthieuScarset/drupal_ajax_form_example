<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Document;

use Drupal\Core\Database\Query\Condition;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "document_media_image"
 * )
 */
class DocumentMediaImage extends SqlBase {

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
    $query = $this->select('file_managed', 'm');
    $query->join('field_data_field_image', 'fi', 'fi.field_image_fid = m.fid');
    $query->join('node', 'n', 'n.nid = fi.entity_id');
    $query->fields('m', ['fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp']);
    $field1_alias = $query->addField('m', 'fid', 'mid');
    $query->condition('n.type', 'content_document_type')
    ->condition('n.status', 1, '=')//;
    ->range(0, 10);

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'mid' => $this->t('Media ID'),
      'bundle' => $this->t('Media bundle'),
      'name' => $this->t('Media name'),
      'field_image_alt' => $this->t('Media Alt'),
      'field_image_title' => $this->t('Media Title'),
      'field_image_width' => $this->t('Media Width'),
      'field_image_height' => $this->t('Media Height'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'fid' => [
        'type' => 'integer',
        'alias' => 'm',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    // récupération de la balise alt et title
    $image_query = $this->select('field_data_field_image', 'fi');
    $image_query->fields('fi', ['field_image_title', 'field_image_alt', 'field_image_width', 'field_image_height'])
    ->condition('fi.field_image_fid', $row->getSourceProperty('fid'), '=')
    ->condition('fi.bundle', 'content_document_type', '=');

    $image_results = $image_query->execute()->fetchAll();

    if (is_array($image_results)){
      foreach ($image_results AS $image_result){
        // On vérifie si on a affaire à un objet ou à un tableau
        $image_info = [];
        if (is_object($image_result)){
          $image_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('image_info', $image_info);
          //$row->setSourceProperty('field_image_alt', $image_result->field_image_alt);
          //$row->setSourceProperty('field_image_title', $image_result->field_image_title);
          //$row->setSourceProperty('field_image_width', $image_result->field_image_width);
          //$row->setSourceProperty('field_image_height', $image_result->field_image_height);
        }
        elseif (is_array($image_result)){
          $image_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('image_info', $image_info);
          //$row->setSourceProperty('field_image_alt', $image_result['field_image_alt']);
          //$row->setSourceProperty('field_image_title', $image_result['field_image_title']);
          //$row->setSourceProperty('field_image_width', $image_result['field_image_width']);
          //$row->setSourceProperty('field_image_height', $image_result['field_image_height']);
        }

      }
    }

    return parent::prepareRow($row);
  }

}
