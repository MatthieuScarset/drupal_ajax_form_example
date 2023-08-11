<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 20/10/2016
 * Time: 14:07
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Database\Database;

/**
 * Classe pour les méthodes qui concernent les données d'import
 */
class BackbonesImportData {
    const TABLE_NAME = 'oab_backbones_import_data';

    /** Méthode qui supprimes toutes les data pour un import */
    public function deleteAllDataForDates($date) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->delete($this::TABLE_NAME)
                ->condition('date', $date, '=')
                ->execute();
        }
    }

    /** Méthode qui crée ou met à jour une ligne de données pour un meme site source, site destination et date */
    public function saveDataLine($date, $source_site, $destination_site, $data_array) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->merge($this::TABLE_NAME)
                ->key(array('date' => $date,
                    'source_site' => $source_site,
                    'destination_site' => $destination_site
                ))
                ->fields($data_array)
                ->execute();
        }
    }

    /** Retourne toutes les données pour un site source et une date */
    public function getDatasForSiteAndDate($date, $site) {
        $datas = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'd');
            $query->join(ShadowSites::TABLE_NAME, 'ss1', 'd.destination_site = ss1.sid');
            $query->join(ShadowSites::TABLE_NAME, 'ss2', 'd.source_site = ss2.sid');
            $results = $query->fields('d')
                ->condition('d.date', $date, '=')
                ->condition('d.source_site', $site)
                ->condition('ss1.used', 1)
                ->condition('ss2.used', 1)
                //     ->groupBy('destination_site') //ne sert à rien puisqu'il n'y a pas de calculs
                ->orderBy('destination_label');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $datas[] = array(
                        "label" => $result->destination_label,
                        "RTD" => round($result->RTD),
                        "PLR" => round($result->PLR, 2),
                        "JITTER" => round($result->JITTER, 1),
                    );
                }
            }
        }
        return $datas;
    }

    /** le top ten des plus grands écarts de RTD par rapport au moins précédent :
     * il faut comparer les données avec le mois précédent et remonter les plus gros écarts (en ms)
     * pour détecter d'un coup d'oeil s'il y a des anomalies entre certains sites : site départ, site destination, delta
     * avec le mois précédent */
    public function getTopTenDataForRTD($date) {
        $data = array();
        $bb_import = new BackbonesImport();
        $last_import = $bb_import->getLastImportBeforeDate($date);
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'd1');
            $query->join(ShadowSites::TABLE_NAME, 'ss1', 'd1.destination_site = ss1.sid');
            $query->join(ShadowSites::TABLE_NAME, 'ss2', 'd1.source_site = ss2.sid');
            $query->join($this::TABLE_NAME, 'd2', 'd1.source_site = d2.source_site AND d1.destination_site = d2.destination_site');
            $query->addExpression('d2.RTD - d1.RTD', 'delta');
            $query->fields('d1', array('date', 'source_label', 'destination_label', 'RTD'));
            $query->fields('d2', array('date', 'RTD'));
            $query->condition('d1.date', $date, '=');
            $query->condition('d2.date', $last_import, '=')
                ->condition('ss1.used', 1)
                ->condition('ss2.used', 1)
                ->range(0, 10)
                ->orderBy('delta', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $data[] = array(
                        "d1_date" => $result->date,
                        "source_label" => $result->source_label,
                        "destination_label" => $result->destination_label,
                        "d1_RTD" => round($result->RTD),
                        "d2_date" => $result->d2_date,
                        "d2_RTD" => round($result->d2_RTD),
                        "delta" => round($result->delta, 2),
                    );
                }
            }
        }
        $values["lastimport"] = $last_import;
        $values["data"] = $data;
        return $values;
    }

    /** Retourne les 10 valeurs les plus élevées pour la valeur PLR de l'import */
    public function getTopTenDataForPLR($date) {
        $data = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'd');
            $query->join(ShadowSites::TABLE_NAME, 'ss1', 'd.destination_site = ss1.sid');
            $query->join(ShadowSites::TABLE_NAME, 'ss2', 'd.source_site = ss2.sid');
            $results = $query->fields('d')
                ->condition('d.date', $date, '=')
                ->condition('ss1.used', 1)
                ->condition('ss2.used', 1)
                ->range(0, 10)
                //     ->groupBy('destination_site') //ne sert à rien puisqu'il n'y a pas de calculs
                ->orderBy('PLR', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $data[] = array(
                        "source_label" => $result->source_label,
                        "destination_label" => $result->destination_label,
                        "PLR" => round($result->PLR, 2)
                    );
                }
            }
        }
        return $data;
    }

    /** Retourne les 10 valeurs les plus élevées pour la valeur JITTER de l'import */
    public function getTopTenDataForJITTER($date) {
        $data = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'd');
            $query->join(ShadowSites::TABLE_NAME, 'ss1', 'd.destination_site = ss1.sid');
            $query->join(ShadowSites::TABLE_NAME, 'ss2', 'd.source_site = ss2.sid');
            $results = $query->fields('d')
                ->condition('d.date', $date, '=')
                ->condition('ss1.used', 1)
                ->condition('ss2.used', 1)
                ->range(0, 10)
                //     ->groupBy('destination_site') //ne sert à rien puisqu'il n'y a pas de calculs
                ->orderBy('JITTER', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $data[] = array(
                        "source_label" => $result->source_label,
                        "destination_label" => $result->destination_label,
                        "JITTER" => round($result->JITTER, 1),
                    );
                }
            }
        }
        return $data;
    }
}
