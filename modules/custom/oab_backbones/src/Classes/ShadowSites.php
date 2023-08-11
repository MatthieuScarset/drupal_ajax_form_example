<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 18/10/2016
 * Time: 10:40
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Database\Database;

/**
 * Classe pour les méthodes qui concernent les Shadows sites avec la BDD
 */
class ShadowSites {
    const TABLE_NAME = 'oab_backbones_shadowsites';

    public function getHeaderTable() {
        $header = array(
            'sid' => array('field' => 'sid', 'data' => t('code'), 'sort' => 'asc'),
            'probe_name' => array('field' => 'probe_name', 'data' => t('probe name'), 'sort' => 'asc'),
            'site_label' => array('field' => 'site_label', 'data' => t('site label'), 'sort' => 'asc')
        );
        return $header;
    }

    /** Méthode appelée par le BO, onglet Shadow Sites pour avoir la grille modifiable :
     *      on prend TOUS les sites
     */
    public function getShadowSitesTable() {
        $shadow_sites = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'obs')
                ->orderBy('used', 'DESC')
                ->extend('Drupal\Core\Database\Query\TableSortExtender');
            $shadow_sites = $query->fields('obs')
                ->orderByHeader($this->getHeaderTable())
                ->execute();
        }
        return $shadow_sites;
    }

    /**
     * Méthode appelée pour avoir un array avec toutes les données prise dans la BDD
     */
    public function getShadowSitesArrayFromDB() {
        $shadow_sites = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'obs')
                ->fields('obs')
                ->orderBy('sid', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $site) {
                    $shadow_sites[$site->sid] = $site->probe_name;
                }
            }
        }
        return $shadow_sites;
    }

    /**
     * Méthode permettant de sauvegarder un shadow Site en BDD lors de l'IMPORT donc uniquement SID et probe_name
     */
    public function saveShadowSitesInDB($ss_to_update) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            foreach ($ss_to_update as $key => $name) {
                $query = Database::getConnection()->merge($this::TABLE_NAME)
                    ->key(array('sid' => $key))
                    ->insertFields(array(
                        'sid' => $key,
                        'probe_name' => $name
                    ))
                    ->updateFields(array(
                        'probe_name' => $name
                    ))
                    ->execute();
            }
        }
    }

    /** Méthode qui supprime des shadow sites avec les id en paramètre */
    public function deleteShadowSitesInDB($ss_to_delete) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->delete($this::TABLE_NAME)
                ->condition('sid', $ss_to_delete, 'IN')
                ->execute();

        }
    }

    /** méthode qui réinitialise la valeur used à 0 pour TOUS les shadow sites */
    public function reinitUsedValuesForAllSites() {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->update($this::TABLE_NAME)
                ->fields(['used' => 0])
                ->execute();
        }
    }

    /** Méthode qui sauvegarde les valeurs used et site_label pour un site (formualire BO) */
    public function updateShadowSiteInDB($sid, $used, $site_label) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->update($this::TABLE_NAME)
                ->fields(['used' => $used, 'site_label' => $site_label])
                ->condition('sid', $sid, '=')
                ->execute();
        }
    }

    /** Méthode qui retourne un tableau (key=sid) de tous les sites où used =1 */
    public function getAllInformationsForUsedShadowSites() {
        $shadow_sites = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'obs')
                ->fields('obs')
                ->condition('obs.used', 1, '=')
                ->orderBy('sid', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $site) {
                    $shadow_sites[$site->sid] = array(
                        "sid" => $site->sid,
                        "probe_name" => $site->probe_name,
                        "site_label" => $site->site_label,
                        "used" => $site->used,
                    );
                }
            }
        }
        return $shadow_sites;
    }

    /** Méthode appelée par le formulaire de sélection d'un site source (BO et FO) parmis les sites USED */
    public function getUsedShadowSitesForSelector() {
        $shadow_sites = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'obs')
                ->fields('obs')
                ->condition('obs.used', 1, '=')
                ->orderBy('obs.site_label', 'ASC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $site) {
                    $shadow_sites[$site->sid] = $site->site_label;
                }
            }
        }
        return $shadow_sites;
    }
}
