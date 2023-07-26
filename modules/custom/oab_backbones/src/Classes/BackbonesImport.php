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
 * Classe pour les méthodes qui concernent les Imports
 */
class BackbonesImport {
    const TABLE_NAME = 'oab_backbones_import';

    public function getHeaderTable() {
        $header = array(
            'date' => array('data' => t('Date'), 'field' => 'date', 'sort' => 'desc'),
            'top_ten' => array('data' => t('Top Ten'), 'field' => 'top_ten'),
            'status' => array('data' => t('Status'), 'field' => 'status'),
            'comment' => t('Comments')
        );
        return $header;
    }

    /** Méthode qui retourne le tableau des derniers imports pour le BO */
    public function getBackbonesImportTable() {
        $imports = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'i')
                ->extend('Drupal\Core\Database\Query\TableSortExtender');
            $imports = $query->fields('i')
                ->orderByHeader($this->getHeaderTable())
                ->range(0, 6)
                ->execute();
        }
        return $imports;
    }

    /** Crée ou met à jour un import */
    public function saveNewImport($date) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->merge($this::TABLE_NAME)
                ->key(array('date' => $date))
                ->insertFields(array(
                    'date' => $date,
                    'status' => 0
                ))
                ->updateFields(array(
                    'date' => $date
                ))
                ->execute();
        }
    }

    /** Fait une mise à jour de l'import en BDD (status + commentaire) */
    public function updateImportInDB($date, $status, $comment) {
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->update($this::TABLE_NAME)
                ->fields(['status' => $status, 'comment' => $comment])
                ->condition('date', $date, '=')
                ->execute();
        }
    }

    /** Retourne les 4 dates des derniers imports */
    public function getLastImportsForSelection() {
        $imports = array();
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'i');
            $results = $query->fields('i')
                ->condition('i.status', 1, '=')
                ->range(0, 4)
                ->orderBy('i.date', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $imports[$result->date] = substr($result->date, 4, 2) . '/' . substr($result->date, 0, 4);
                }
            }
        }
        return $imports;
    }

    /** Retourne le commentaire saisi pour un import */
    public function getCommentForImport($date) {
        $comment = "";
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'i');
            $results = $query->fields('i')
                ->condition('i.date', $date, '=');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $comment = $result->comment;
                }
            }
        }
        return $comment;
    }


    /** Retourne le dernier import validé avant celui passé en paramètre */
    public function getLastImportBeforeDate($date) {
        $date_import = "";
        if (Database::getConnection()->schema()->tableExists($this::TABLE_NAME)) {
            $query = Database::getConnection()->select($this::TABLE_NAME, 'i');
            $results = $query->fields('i')
                ->condition('i.status', 1, '=')
                ->condition('i.date', $date, '<')
                ->range(0, 1)
                ->orderBy('i.date', 'DESC');
            $results = $query->execute()->fetchAll();

            if (is_array($results) && count($results) > 0) {
                foreach ($results as $result) {
                    $date_import = $result->date;
                }
            }
        }
        return $date_import;
    }
}
