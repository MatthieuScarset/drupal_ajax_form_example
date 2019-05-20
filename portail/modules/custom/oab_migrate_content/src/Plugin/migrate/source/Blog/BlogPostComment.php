<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\Core\Database\Database;
use Drupal\Core\Database\Query\Condition;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "blogpost_comment"
 * )
 */
class BlogPostComment extends SqlBase {

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


    $query = $this->select('comment', 'c');
    $query->join('field_data_comment_body', 'b', 'c.cid = b.entity_id');
    $query->join('node', 'n', 'n.nid = c.nid');
    $query->fields('c', ['cid', 'pid', 'nid', 'uid', 'subject', 'hostname', 'created', 'changed', 'status', 'thread', 'name', 'mail', 'homepage', 'language']);
    $query->fields('b', ['comment_body_value', 'comment_body_format']);
    $query->distinct(TRUE);
        //$query->condition('n.nid', array(1887,12968,825,862,868,928,944), 'IN');
    //$query->condition('n.type', 'blog_post');
        //$query->condition('n.changed', BLOGPOST_SELECT_DATE, '>');
    $query->condition('c.status', 1, '=');
    $query->orderBy('c.changed', 'ASC');
    $query->condition('n.changed', TIMESTAMP_MIGRATION_VALUE, TIMESTAMP_MIGRATION_OPERATOR);


        return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'cid' => $this->t('cid'),
      'pid' => $this->t('pid'),
      'nid' => $this->t('nid'),
      'uid' => $this->t('uid'),
      'subject' => $this->t('subject'),
      'hostname' => $this->t('hostname'),
      'created' => $this->t('created'),
      'changed' => $this->t('changed'),
      'status' => $this->t('status'),
      'thread' => $this->t('thread'),
      'name' => $this->t('name'),
      'mail' => $this->t('mail'),
      'homepage' => $this->t('homepage'),
      'language' => $this->t('language'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'cid' => [
        'type' => 'integer',
        'alias' => 'c',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    //comment parent
    $comment_parent_query = Database::getConnection()->select('migrate_map_blogpost_comment', 'c');
    $comment_parent_query->fields('c', ['sourceid1', 'destid1'])
      ->condition('c.sourceid1', $row->getSourceProperty('pid'));
    $comment_parent_results = $comment_parent_query->execute()->fetchAll();

    if (is_array($comment_parent_results)) {
      foreach ($comment_parent_results AS $parent) {
        if (is_object($parent) && isset($parent->destid1) ) {
          $row->setSourceProperty('pid_parent', $parent->destid1);
        }
        elseif (is_array($parent) && isset($parent['destid1'])) {
          $row->setSourceProperty('pid_parent', $parent['destid1']);
        }
      }
    }
    else{
      $row->setSourceProperty('pid_parent', '0');
    }

        $row->setSourceProperty('comment_body', array('value' => $row->getSourceProperty('comment_body_value'), 'format' => 'comments'));

    $row->setSourceProperty('langcode', $row->getSourceProperty('language'));
    $row->setSourceProperty('default_langcode', '1');
    $row->setSourceProperty('uid', '0');


    return parent::prepareRow($row);
  }

}
