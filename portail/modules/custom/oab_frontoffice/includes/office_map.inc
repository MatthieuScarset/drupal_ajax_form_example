<?php

/*******************************************************************************************************************/
/*************** METHODES POUR LES CARTES D'OFFICES QUI DOIVENT ETRE ACCESSIBLES PARTOUT (multi-JIRA) *************/

/*******************************************************************************************************************/

use Drupal\Core\Database\Database;

/**
 * Méthode qui renvoie le tableau des pays pour remplir le filtre Pays en JS
 * @return array
 */
function getCountriesForJS() {
    $keys = array();
    $query = Database::getConnection()->select('node_field_data', 'n');
    $query->leftjoin('node__field_office_country', 'c', 'n.nid = c.entity_id');
    $query->leftjoin('taxonomy_term_field_data', 'oc', 'oc.tid = c.field_office_country_target_id');
    $query->condition('n.type', 'office', '=');
    $query->condition('n.status', 1, '=');
    $query->addField('oc', 'tid', 'country_tid');
    $query->addField('oc', 'name', 'country_name');
    $query->addField('oc', 'langcode', 'country_langcode');
    $query->orderBy('oc.name');
    $results = $query->execute()->fetchAll();

    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $table_countries = array();
    $table_countries['all'] = t('Country');
    foreach ($results as $country) {
        if (!in_array($country->country_tid, $keys) && !empty($country->country_tid) && $country->country_langcode == $current_language) {
            $keys[] = $country->country_tid;
            $table_countries[] = array('id' => $country->country_tid, "name" => $country->country_name);
        }
    }
    //pour ceux qui n'ont pas de traduction, on prend le libellé sans restriction de langue
    foreach ($results as $country) {
        if (!in_array($country->country_tid, $keys) && !empty($country->country_tid)) {
            $keys[] = $country->country_tid;
            $table_countries[] = array('id' => $country->country_tid, "name" => $country->country_name);
        }
    }
    return $table_countries;
}

/**
 * Méthode qui renvoie le tableau d'association [country id] => region_id
 * @return array
 */
function getArrayRegionsCountries() {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    $query = Database::getConnection()->select('node_field_data', 'n');
    $query->leftjoin('node__field_office_country', 'c', 'n.nid = c.entity_id');
    $query->leftjoin('taxonomy_term_field_data', 'oc', 'oc.tid = c.field_office_country_target_id');
    $query->leftjoin('taxonomy_term__field_country_code', 'occ', 'occ.entity_id = c.field_office_country_target_id');
    $query->leftjoin('node__field_region', 'r', 'n.nid = r.entity_id');
    $query->leftjoin('taxonomy_term_field_data', 't', 't.tid = r.field_region_target_id');
    $query->condition('n.type', 'office', '=');
    $query->condition('n.status', 1, '=');
    $query->addField('t', 'tid', 'region_tid');
    $query->addField('t', 'name', 'region_name');
    $query->addField('oc', 'tid', 'country_tid');
    $query->addField('oc', 'name', 'country_name');
    $query->addField('oc', 'langcode', 'country_langcode');
    $query->addField('occ', 'field_country_code_value', 'country_code');
    $results = $query->execute()->fetchAll();
    //tableau [pays id] => region id
    $table_country_region = array();
    foreach ($results as $rowCountryRegion) {
        $table_country_region[$rowCountryRegion->country_tid] = $rowCountryRegion->region_tid;
    }

    return $table_country_region;
}

/**
 * Méthode qui renvoie le tableau de pays (termes de taxo offices countrie) [country id] => country name
 * @return array
 */
function getCountries() {
    $query = Database::getConnection()->select('node_field_data', 'n');
    $query->leftjoin('node__field_office_country', 'c', 'n.nid = c.entity_id');
    $query->leftjoin('taxonomy_term_field_data', 'oc', 'oc.tid = c.field_office_country_target_id');
    $query->condition('n.type', 'office', '=');
    $query->condition('n.status', 1, '=');
    $query->addField('oc', 'tid', 'country_tid');
    $query->addField('oc', 'name', 'country_name');
    $query->addField('oc', 'langcode', 'country_langcode');
    $query->orderBy('oc.name');
    $results = $query->execute()->fetchAll();

    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $table_countries = array();
    $table_countries['all'] = t('Country');

    foreach ($results as $country) {
        if (!array_key_exists($country->country_tid, $table_countries)
            && !empty($country->country_tid)
            && $country->country_langcode == $current_language) {
            $table_countries[$country->country_tid] = $country->country_name;
        }
    }

    foreach ($results as $country) {
        if (!array_key_exists($country->country_tid, $table_countries) && !empty($country->country_tid)) {
            $table_countries[$country->country_tid] = $country->country_name;
        }
    }
    return $table_countries;
}

/**
 * Méthode qui renvoie le tableau de régions (termes de taxo region) [region id] => region name
 * @return array
 */
function getRegions() {
    $query = Database::getConnection()->select('node_field_data', 'n');
    $query->leftjoin('node__field_region', 'r', 'n.nid = r.entity_id');
    $query->leftjoin('taxonomy_term_field_data', 't', 't.tid = r.field_region_target_id');
    $query->condition('n.type', 'office', '=');
    $query->condition('n.status', 1, '=');
    $query->addField('t', 'tid', 'region_tid');
    $query->addField('t', 'name', 'region_name');
    $query->addField('t', 'langcode', 'region_langcode');
    $query->orderBy('t.name');
    $results = $query->execute()->fetchAll();

    $table_regions = array();
    $table_regions['all'] = t('Region');

    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    foreach ($results as $region) {
        if (!array_key_exists($region->region_tid, $table_regions)
            && !empty($region->region_tid)
            && $region->region_langcode == $current_language) {
            $table_regions[$region->region_tid] = $region->region_name;
        }
    }
    return $table_regions;
}
