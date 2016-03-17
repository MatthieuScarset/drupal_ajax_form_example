<?php

/**
 * @file
 * Contains \Drupal\migrate_example\Plugin\migrate\source\BeerNode.
 */

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "blogpost_term"
 * )
 */
class BlogPostTerm extends SqlBase {

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
    $query = $this->select('taxonomy_term_data', 't');
    $query->join('taxonomy_term_hierarchy', 'th', 'th.tid = t.tid');
    $query->fields('t', ['tid', 'vid', 'name', 'language', 'weight'])
    ->fields('th', ['parent'])
    ->condition('t.vid', 14, '=')
    ->orderBy('th.parent', 'ASC');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'tid' => $this->t('Term ID'),
      'name' => $this->t('name'),
      'language' => $this->t('language'),
      'weight' => $this->t('Weight'),
      'parent' => $this->t("The Drupal term IDs of the term's parents."),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'tid' => [
        'type' => 'integer',
        'alias' => 't',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    // Find parents for this row.
    /*$parents = $this->select('taxonomy_term_hierarchy', 'th')
    ->fields('th', array('parent', 'tid'))
    ->condition('tid', $row->getSourceProperty('tid'))
    ->execute()
    ->fetchCol();
    $row->setSourceProperty('parent', $parents);*/
    return parent::prepareRow($row);
  }

}
