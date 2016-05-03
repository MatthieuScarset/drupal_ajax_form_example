<?php

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Blog;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 *
 * @MigrateSource(
 *   id = "blogpost_profile"
 * )
 */
class BlogPostProfile extends SqlBase {

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
    $query = $this->select('users', 'u');
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $query->fields('u', ['uid'])
    ->condition('ur.rid', 4, '=')
    ->condition('u.uid', 1, '!=');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'uid' => $this->t('User ID'),
      'name' => $this->t('name'),
    ];

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'uid' => [
        'type' => 'integer',
        'alias' => 'u',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    $title = '';
    $fields = [];
    $fields['field_first_name'] = ['field_first_name_value'];
    $fields['field_last_name'] = ['field_last_name_value'];
    $fields['field_txt_catcher'] = ['field_txt_catcher_value'];
    $fields['field_txt_biography_fr'] = ['field_txt_biography_fr_value'];
    $fields['field_profil'] = ['field_profil_value'];
    $fields['field_profil_fr'] = ['field_profil_fr_value'];
    $fields['field_location'] = ['field_location_value'];
    $fields['field_location_fr'] = ['field_location_fr_value'];
    $fields['field_link'] = ['field_link_url'];
    $fields['field_twitter_account'] = ['field_twitter_account_url'];
    $fields['field_linkin_account'] = ['field_linkin_account_url'];
    $fields['field_viadeo_account'] = ['field_viadeo_account_url'];
    $fields['field_googleplus_account'] = ['field_googleplus_account_value'];

    foreach ($fields AS $key => $value) {
      $table = 'field_data_' . $key;
      $profile = $this->select('profile', 'p');
      $profile->join($table, 'fi', 'fi.entity_id = p.pid');
      $profile->fields('fi', $value)
        ->condition('p.uid', $row->getSourceProperty('uid'))
        ->condition('fi.entity_type', 'profile2')
        ->condition('fi.bundle', 'main');

      $profile_results = $profile->execute()->fetchAll();

      if (is_array($profile_results)){
        foreach ($profile_results AS $profile_result){

          foreach ($value AS $field) {

            // On vérifie si on a affaire à un objet ou à un tableau
            if (is_object($profile_result) && isset($profile_result->$field)) {
              $row->setSourceProperty($key, $profile_result->$field);
            }
            elseif (is_array($profile_result) && isset($profile_result[$field])) {
              $row->setSourceProperty($key, $profile_result[$field]);
            }

            if ($key == 'field_first_name') {
              if (is_object($profile_result) && isset($profile_result->$field)) {
                $title .= trim($profile_result->field_first_name_value) . ' ';
              }
              elseif (is_array($profile_result) && isset($profile_result[$field])) {
                $title .= trim($profile_result['field_first_name_value']) . ' ';
              }
            }
            if ($key == 'field_last_name') {
              if (is_object($profile_result) && isset($profile_result->{$field})) {
                $title .= trim($profile_result->field_last_name_value);
              }
              elseif (is_array($profile_result) && isset($profile_result[$field])) {
                $title .= trim($profile_result['field_last_name_value']);
              }
            }
          }
        }
      }
    }

    $social_accounts = [];
    if ($field_twitter_account = $row->getSourceProperty('field_twitter_account')){
      $social_accounts[0] = $field_twitter_account;
    }
    else{
      $social_accounts[0] = ' ';
    }
    if ($field_linkin_account = $row->getSourceProperty('field_linkin_account')){
      $social_accounts[1] = $field_linkin_account;
    }
    else{
      $social_accounts[1] = ' ';
    }
    if ($field_viadeo_account = $row->getSourceProperty('field_viadeo_account')){
      $social_accounts[2] = $field_viadeo_account;
    }
    else{
      $social_accounts[2] = ' ';
    }
    if ($field_googleplus_account = $row->getSourceProperty('field_googleplus_account')){
      $social_accounts[3] = $field_googleplus_account;
    }
    else{
      $social_accounts[3] = ' ';
    }
    $row->setSourceProperty('field_social_accounts', $social_accounts);

    //$job_values = [];
    //$job_values[] = [['langcode' => 'fr', 'value' => 'test FR'], ['langcode' => 'rn', 'value' => 'test EN']];
    //$job_values[] = ['fr' => ['value' => 'test FR'], 'en' => ['value' => 'test EN']];
    //$job_values[] = ['value' => 'test FR'];
    //$job_values['fr'] = [0 => ['value' => 'test FR']];
    //$job_values['en'] = [0 => ['value' => 'test EN']];
    //$job_values[] = ['langcode' => 'en', 'value' => 'test FR'];

    //$row->setSourceProperty('field_profil/langcode', 'en');
    //$row->setSourceProperty('field_profil/value', 'test');

    if ($title == '') $title = 'test';
    $row->setSourceProperty('title', $title);

    // récupération des images
    $images_query = $this->select('field_data_field_image', 'fi');
    $images_query->join('profile', 'p', 'p.pid = fi.entity_id');
    $field1_alias = $images_query->addField('fi', 'field_image_fid', 'mid');
    $field2_alias = $images_query->addField('fi', 'delta');
    $images_query->condition('p.uid', $row->getSourceProperty('uid'), '=')
    ->condition('fi.entity_type', 'profile2', '=')
    ->condition('fi.bundle', 'main', '=')
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

    // path
    $url_source = 'user/' . $row->getSourceProperty('uid');
    $path_query = $this->select('url_alias', 'ua')
      ->fields('ua')
      ->condition('ua.source', $url_source, 'LIKE');

    $path_results = $path_query->execute()->fetchObject();

    if (is_object($path_results)){
      $row->setSourceProperty('path', '/' . $path_results->alias);
    }

    return parent::prepareRow($row);
  }
}
