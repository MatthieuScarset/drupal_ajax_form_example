<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\Core\Database\Query\Condition;
use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "blogpost_profile_image"
 * )
 */
class BlogPostProfileImage extends SqlBase {

  /**
   * The public file directory path.
   *
   * @var string
   */
  protected $publicPath;

  /**
   * The private file directory path, if any.
   *
   * @var string
   */
  protected $privatePath;

  /**
   * The temporary file directory path.
   *
   * @var string
   */
  protected $temporaryPath;

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


    $query = $this->select('file_managed', 'f');
    $query->distinct();
    $query->join('field_data_field_image', 'fi', 'fi.field_image_fid = f.fid');
    $query->join('profile', 'p', 'p.pid = fi.entity_id');
    $query->join('users', 'u', 'u.uid = p.uid');
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->fields('f', ['fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp'])
    ->condition('fi.entity_type', 'profile2')
    ->condition('fi.bundle', 'main')
    ->condition('ur.rid', 4, '=')
    ->orderBy('f.fid', 'DESC');

    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'fid' => $this->t('File ID'),
      'filename' => $this->t('filename'),
      'uri' => $this->t('uri'),
      'filemime' => $this->t('filemime'),
      'filesize' => $this->t('filesize'),
      'status' => $this->t('status'),
      'timestamp' => $this->t('timestamp'),
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
        'alias' => 'f',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  protected function initializeIterator() {
    $this->publicPath = 'sites/default/files';
    $this->privatePath = NULL;
    $this->temporaryPath = '/tmp';
    return parent::initializeIterator();
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {


		// On change le current user car l'utilisateur anonyme (0) pose des problèmes avec le workflow
		$admin_user = \Drupal\user\Entity\User::load(1);
		\Drupal::getContainer()->set('current_user', $admin_user);

    $imageFolders = ['media', 'pictures', 'Blog', 'Contributor en', 'Contributor fr', 'Editorial Master', 'Events', 'library', 'magazine', 'press', 'webtv',
        'media/agences', 'media/blog', 'media/contributor_en', 'media/editorial_master', 'media/events', 'media/events/events_document', 'media/library', 'media/magazine', 'media/press', 'media/webtv', 'field/image'];
    //$blogPath = 'public://Blog';
    foreach ($imageFolders AS $folder){
      $folderName = 'public://'.$folder;
      file_prepare_directory($folderName, FILE_CREATE_DIRECTORY);
    }
    // Compute the filepath property, which is a physical representation of
    // the URI relative to the Drupal root.
    $saved_path = str_replace('public:/', \Drupal\Core\Site\Settings::get('migration_files_source_path', $this->publicPath.'/OLD'), $row->getSourceProperty('uri'));
    $path = str_replace(['public:/', 'private:/', 'temporary:/'], [$this->publicPath, $this->privatePath, $this->temporaryPath], $row->getSourceProperty('uri'));

    if (file_exists($saved_path)) {
      //rename($saved_path, $path);
      copy($saved_path, $path);
    }
    // At this point, $path could be an absolute path or a relative path,
    // depending on how the scheme's variable was set. So we need to shear out
    // the source_base_path in order to make them all relative.
    // @todo Don't depend on destination configuration.
    // @see https://www.drupal.org/node/2577871
    $path = str_replace($this->migration->get('destination')['source_base_path'], NULL, $path);
    $row->setSourceProperty('filepath', $path);

    $row->setSourceProperty('langcode', 'und');
    $row->setSourceProperty('uid', 1);

    $row->setSourceProperty('current_fid', array($row->getSourceProperty('fid')));

    return parent::prepareRow($row);
  }

}
