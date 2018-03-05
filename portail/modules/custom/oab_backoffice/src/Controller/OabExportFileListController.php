<?php
namespace Drupal\oab_backoffice\Controller;

define('SESSION_NAME','oab_backoffice.export_file_download' );

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\StackMiddleware\Session;
use Drupal\Core\TypedData\Plugin\DataType\Uri;
use Drupal\Core\Url;
use Drupal\system\FileDownloadController;
use Symfony\Component\HttpFoundation\BinaryFileResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;
use Drupal\user\PrivateTempStoreFactory;

class OabExportFileListController extends ControllerBase {
    private static $dir = "public://export_document";

    public function runBatch(Request $request) {

        $originPath = $request->headers->get('referer');

        ##Je tente de regarder s'il y a des paramètres dans l'URL
        # ie. si des filtres ont été ajoutés à la vue
        $params = [];
        $originPath_parts = explode("?", $originPath);
        if (count($originPath_parts) > 1) {
            $parameters = explode("&", $originPath_parts[1]);
            foreach ($parameters as $param_string) {
                $param = explode("=", $param_string);
                if (isset($param[0]) && isset($param[1])) {
                    $params[$param[0]] = $param[1];
                }
            }
        }

        ##Création du nom unique du fichier final
        $file_name = date('Ymd-His') . "-document-list-" . rand() . ".csv";


        ##Setting up du batch
        $batch = array(
            'title' => t("Export document list"),
            'operations'    => array(
                array(
                    '\Drupal\oab_backoffice\Controller\OabExportFileListController::exportFileList',
                    array($params, $file_name)
                )
            ),
            'progress_message' => t('Exporting document list'),
        );


        ##j'enregistre l'URL d'origine (utilisée pour créer un lien de retour à la fin du batch)
        $tempstore = \Drupal::service('user.private_tempstore')->get(SESSION_NAME);
        $tempstore->set('origin_url', $originPath);

        ## Lien de la page à afficher à la fin de la création du fichier
        $route = \Drupal::url('oab_backoffice.download_file_list');

        batch_set($batch);
        return batch_process($route);
    }


    /**
     * Méthode appelée quand on va voir le détail d'un import en BO
     */
    public function exportFileList($params, $file_name, &$context) {

        ## Recuperation de la vue et du bon display view
        $view = \Drupal\views\Views::getView('document_list');
        $view->setDisplay('document_list_page');
        $view->setExposedInput($params);        # Je set les paramètres recupérés dans l'URL pour
                                                # mettre les memes filtres que la vue qui s'est affichée

        ## Je supprime le pager pour recuperer tous les éléments
        $view->display_handler->options['pager']['type'] = 'none';

        $view->preview();


        ## Tableau pour recuperer toutes les infos
        $ret = array();

        ##Titres dans la premiere row
        $ret[0] = array();

        $fields = array(
            'relation'  => array(),
            'entity'    => array()
        );

        foreach ($view->field as $field_name => $field_data) {
            if ($field_data->relationship !== null) {
                $fields['relation'][$field_name] = $field_data->field;
            } else {
                $fields['entity'][$field_name] = $field_data->field;
            }
            $ret[0][] = $field_data->options['label'];
        }

        ##Boucle pour recueperer tous les résultats, et modif de l'affichag
        # en fonction de chacun, grace à la méthode tout en bas
        $results = $view->result;
        foreach ($results as $result) {
            $row = array();
            $entity = $result->_entity;
            $relationships = $result->_relationship_entities;
            foreach ($fields['entity'] as $field_name => $field_real_name) {
                $value_string = "";
                if ($entity->hasField($field_real_name)){
                    $values = $entity->get($field_real_name)->getValue();
                    $i = 0;
                    foreach ($values as $key => $value) {
                        if ($i == 0) {
                            $i++;
                            $value_string .= self::getValueFromValueArray($value);
                        } else {
                            $value_string .= ", " . self::getValueFromValueArray($value);
                        }
                    }
                }
                $row[$field_name] = $value_string;
            }
            foreach ($fields['relation'] as $field_name => $field_real_name) {
                foreach ($relationships as $relationship) {
                    $value_string = "";
                    if ($relationship->hasField($field_real_name)){
                        $values = $relationship->get($field_real_name)->getValue();


                        foreach ($values as $key => $value) {
                            if ($key == 0)
                                $value_string .= self::getValueFromValueArray($value);
                            else {
                                $value_string .= ", " . self::getValueFromValueArray($value);
                            }
                        }
                    }
                    $row[$field_name] = $value_string;
                }

            }
            $ret[] = $row;
        }
        #kint($ret);


        ## Je check que le dossier existe
        if (!file_exists(self::$dir)) {
            mkdir(self::$dir, 0770, TRUE);
        }

        $toWrite = "";
        foreach ($ret as $key => $row) {
            $toWrite .= implode(";", $row);
            $toWrite .= "\r\n";
        }
        $path = self::$dir."/$file_name";

        $file = file_unmanaged_save_data($toWrite, $path);

        #On remonte une erreur si le fichier ne se crée pas
        if ($file === false) {
            echo "Erreur lors de la création du fichier de résultat";
            die();
        }

        # Je sauvegarde l'uri du fichier
        $tempstore = \Drupal::service('user.private_tempstore')->get(SESSION_NAME);
        $tempstore->set('file_path', $file);


    }


    public function endingPage(Request $request) {

        ##Je recupère les deux données sauvées pour l'affichage
        $tempstore = \Drupal::service('user.private_tempstore')->get(SESSION_NAME);
        $file_url = $tempstore->get('file_path');
        $origin = $tempstore->get('origin_url');

        ##S'il en manque une, j'affiche un message
        if ($file_url === null || $origin === null) {
            throw new \Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException();
        }
        $url = file_create_url($file_url);


        ##J'affiche le résultat
        return [
            "#theme"  => "oab_export_file_list__ending_page",
            "#file_url"   => $url,
            "#origin_url"   => $origin
        ];

    }

    /**
     * Suppression de tous les fichiers du dossier de sauvegarde
     */
    public static function clearStorageDir() {

    }

    private function getValueFromValueArray($valueArray) {
        $ret = "";

        ##Gestion des Targetsid
        if (isset($valueArray['target_id'])) {
            $target_id = intval($valueArray['target_id']);
            if ($target_id == 0 ) {
                return $valueArray['target_id'];
            }
            $entity = \Drupal\taxonomy\Entity\Term::load($target_id);
            if (!is_null($entity) and is_a($entity,'Drupal\taxonomy\Entity\Term' )) {
                return $entity->getName();
            }

            $entity = \Drupal\file\Entity\File::load($target_id);
            if (!is_null($entity)) {
                $uri = $entity->getFileUri();
                return drupal_realpath($uri);
            }
        }

        ##Cas des "value"
        if (isset($valueArray['value'])) {

            # Cas d'un timestamp
            if (strlen($valueArray['value']) == 10) {
                $date = date('d/m/Y H:i:s', $valueArray['value']);
                if ($date !== false) {
                    return $date;
                }
            }

            return $valueArray['value'];
        }

        return $ret;
    }
}
