<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\Core\Database\Query\Condition;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "blogpost_profile_media"
 * )
 */
class BlogPostProfileMedia extends SqlBase {

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
    $query->distinct();
    $query->join('field_data_field_image', 'fi', 'fi.field_image_fid = m.fid');
    $query->join('profile', 'p', 'p.pid = fi.entity_id');
    $query->join('users', 'u', 'u.uid = p.uid');
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->fields('m', ['fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp']);
    $field1_alias = $query->addField('m', 'fid', 'mid');
    $query->condition('fi.entity_type', 'profile2')
    ->condition('fi.bundle', 'main')
    ->condition('ur.rid', 4, '=')
    //        ->condition('ur.rid', 99999, '=')
    ->orderBy('m.fid', 'DESC');

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
    $row->setSourceProperty('image_info', [$row->getSourceProperty('mid')]);

    /*
    // récupération de la balise alt et title
    $image_query = $this->select('field_data_field_image', 'fi');
    $image_query->fields('fi', ['field_image_title', 'field_image_alt', 'field_image_width', 'field_image_height'])
    ->condition('fi.field_image_fid', $row->getSourceProperty('fid'), '=')
    ->condition('fi.entity_type', 'profile2')
    ->condition('fi.bundle', 'main');

    $image_results = $image_query->execute()->fetchAll();

    if (is_array($image_results)) {
      foreach ($image_results AS $image_result) {
        // On vérifie si on a affaire à un objet ou à un tableau
        $image_info = [];
        if (is_object($image_result)) {
          $image_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('image_info', $image_info);
        }
        elseif (is_array($image_result)) {
          $image_info[] = $row->getSourceProperty('mid');
          $row->setSourceProperty('image_info', $image_info);
        }
        
      }
    }
    */

    return parent::prepareRow($row);
  }

}
