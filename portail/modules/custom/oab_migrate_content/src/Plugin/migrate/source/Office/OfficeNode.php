<?php

/**
 * @file
 * Contains \Drupal\migrate_example\Plugin\migrate\source\BeerNode.
 */

namespace Drupal\oab_migrate_content\Plugin\migrate\source\Office;

use Drupal\migrate\Annotation\MigrateSource;
use Drupal\migrate\Plugin\migrate\source\SqlBase;
use Drupal\migrate\Row;

/**
 * Source plugin for beer content.
 *
 * @MigrateSource(
 *   id = "office_node"
 * )
 */
class OfficeNode extends SqlBase {

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
    ->condition('n.type', 'content_presence_worldwide', '=');
    return $query;
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
    $fields = [
      'nid' => $this->t('Office ID'),
      'title' => $this->t('title'),
      'latitude' => $this->t('latitude'),
      'longitude' => $this->t('longitude'),
      'street' => $this->t('street'),
      'city' => $this->t('city'),
      'additional' => $this->t('additional'),
      'postal_code' => $this->t('postal code'),
      'country' => $this->t('country'),
      'area' => $this->t('areas'),
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
    // récupération de l'adresse
    $address_query = $this->select('location_instance', 'li');
    $address_query->join('location', 'l', 'l.lid = li.lid');
    $address_query->fields('l', ['latitude', 'longitude', 'street', 'city', 'additional', 'postal_code'])
    ->condition('li.nid', $row->getSourceProperty('nid'), '=');

    $address_results = $address_query->execute()->fetchObject();

    if (is_object($address_results)) {
      foreach ($address_results AS $key => $value) {
          $row->setSourceProperty($key, $value);
      }
    }

        // récupération de l'email
        $email_query = $this->select('location_instance', 'li');
        $email_query->join('location_email', 'l', 'l.lid = li.lid');
        $email_query->fields('l', ['email'])
            ->condition('li.nid', $row->getSourceProperty('nid'), '=');
        $email_results = $email_query->execute()->fetchAll();
        $email_value = "";

        if (is_array($email_results)) {
            foreach ($email_results AS $email) {

                // On vérifie si on a affaire à un objet ou à un tableau
                if (is_object($email) && isset($email->email)) {
                    $email_value = $email->email;
                }
                elseif (is_array($email) && isset($email['email'])) {
                    $email_value = $email['email'];
                }
            }
        }
        if (isset($email_value) && !empty($email_value)) {
            $row->setSourceProperty('email_address', $email_value) ;
        }

        // récupération du num de telephone
        $phone_query = $this->select('location_instance', 'li');
        $phone_query->join('location_phone', 'l', 'l.lid = li.lid');
        $phone_query->fields('l', ['phone'])
            ->condition('li.nid', $row->getSourceProperty('nid'), '=');
        $phone_results = $phone_query->execute()->fetchAll();
        $phone_value = "";

        if (is_array($phone_results)) {
            foreach ($phone_results AS $phone_result) {

                // On vérifie si on a affaire à un objet ou à un tableau
                if (is_object($phone_result) && isset($phone_result->phone)) {
                    $phone_value = $phone_result->phone;
                }
                elseif (is_array($phone_result) && isset($phone_result['phone'])) {
                    $phone_value = $phone_result['phone'];
                }
            }
        }
        if (isset($phone_value) && !empty($phone_value)) {
            $row->setSourceProperty('phone_number', $phone_value) ;
        }

        // taxonomie region
        $regions = get_correspondance_tid_D7_tid_D8('correspondence_taxo_region',
            'field_data_field_taxo_area',
            'field_taxo_area_tid',
            $row->getSourceProperty('nid'),
            'content_presence_worldwide');
        if (count($regions) > 0) {

            $row->setSourceProperty('regions', $regions);
        }


        // récupération du pays
        $country_query = $this->select('location_instance', 'li');
        $country_query->join('location', 'l', 'l.lid = li.lid');
        $country_query->join('location_country', 'c', 'l.country = c.code');
        $country_query->fields('c', ['code', 'name'])
            ->condition('li.nid', $row->getSourceProperty('nid'), '=');

        $country_result = $country_query->execute()->fetchObject();

        if (is_object($country_result) && isset($country_result->code)) {
            $tid_country = get_country_term($country_result->code, $country_result->name);
            if (isset($tid_country)) {
                $row->setSourceProperty('country', $tid_country);
            }
        }

    $row->setSourceProperty('path', '/' . $row->getSourceProperty('title'));

    return parent::prepareRow($row);
  }

}
