<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\PressKit;

use Drupal\Core\Database\Query\Condition;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "press_kit_media"
 * )
 */
class PressKitMedia extends SqlBase {

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
    $query->join('field_data_field_press_kit_pdf', 'fi', 'fi.field_press_kit_pdf_fid = m.fid');
    $query->join('node', 'n', 'n.nid = fi.entity_id');
    $query->fields('m', ['fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp'])
    ->distinct(TRUE);
    $field1_alias = $query->addField('m', 'fid', 'mid');
    $query->condition('n.type', 'press_kit');
        $query->condition('n.changed', TIMESTAMP_MIGRATION_VALUE, TIMESTAMP_MIGRATION_OPERATOR);

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
    // récupération de la balise description
    $file_query = $this->select('field_data_field_press_kit_pdf', 'fi');
    $file_query->fields('fi', ['field_press_kit_pdf_description'])
    ->condition('fi.field_press_kit_pdf_fid', $row->getSourceProperty('fid'), '=')
    ->condition('fi.bundle', 'press_kit', '=');

    $file_results = $file_query->execute()->fetchAll();

    if (is_array($file_results)) {
      foreach ($file_results AS $file_result) {
        // On vérifie si on a affaire à un objet ou à un tableau
        $file_info = [];
        if (is_object($file_result)) {
          $file_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('file_info', $file_info);
        }
        elseif (is_array($file_result)) {
          $file_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('file_info', $file_info);
        }

      }
    }

    return parent::prepareRow($row);
  }

}
