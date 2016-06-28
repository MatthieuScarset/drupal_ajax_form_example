<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\MagazineArticle;

use Drupal\Core\Database\Database;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "magazinearticle_term"
 * )
 */
class MagazineArticleTerm extends SqlBase {

  private $correspondanceTaxo = array(21 => "magazine",
                                      10 => "industries",
                                      13 => "solutions",
                                      16 => "partners",
                                      7 => "areas",
                                      17 => "customer_stories");

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
    ->condition('t.vid', array(21, 10, 13, 16, 7, 17), 'IN') // taxo magazine categorie
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
    $parents = $this->select('taxonomy_term_hierarchy', 'th')
    ->fields('th', array('parent'))
    ->condition('th.tid', $row->getSourceProperty('tid'))
    ->execute()
    ->fetchCol();
    $row->setSourceProperty('parent', $parents);
    
    $old_vid = $row->getSourceProperty('vid');
    $row->setSourceProperty('vid', $this->correspondanceTaxo[$old_vid]);

    // on vérifie si le terme n'existe pas déjà
    $migrate_groups = \Drupal\migrate_plus\Entity\MigrationGroup::loadMultiple();
    foreach ($migrate_groups AS $migrate_group){
      $migration_term_name = 'migrate_map_' . $migrate_group->get('id') . '_term';
      //\Drupal::logger('oab_migrate_content')->notice('migrate table : ' . $migration_term_name);

      if (Database::getConnection()->schema()->tableExists($migration_term_name)){
        //\Drupal::logger('oab_migrate_content')->notice('table found');
        $query = Database::getConnection()->select($migration_term_name, 'mtn')
          ->fields('mtn', ['destid1'])
          ->condition('mtn.sourceid1', $row->getSourceProperty('tid'));

        $result = $query->execute()->fetchObject();

        if (is_object($result)) {
          $row->setDestinationProperty('tid', $result->destid1);
        }
      }
    }

    return parent::prepareRow($row);
  }

}
