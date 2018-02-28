<?php
namespace Drupal\oab_backoffice\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\TypedData\Plugin\DataType\Uri;
use Drupal\Core\Url;
use Drupal\oab_backbones\Classes\BackbonesImport;
use Drupal\oab_backbones\Classes\BackbonesImportData;
use Drupal\oab_backbones\Form\FilterPerformanceDataForm;
use Drupal\oab_backbones\Form\GlobalSettingsForm;
use Drupal\system\FileDownloadController;
use Symfony\Component\HttpFoundation\BinaryFileResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabExportFileListController extends ControllerBase
{
    /** Méthode appelée quand on va voir le détail d'un import en BO
     */
    public function exportFileList(Request $request) {

        ## Recuperation de la vue et du bon display view
        $view = \Drupal\views\Views::getView('document_list');
        $view->setDisplay('document_list_export');

        ## Tableau pour recuperer toutes les infos
        $ret = array();

        ##Titres dans la premiere row
        $ret[0] = array();



        $view->preview();
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
                            $value_string .= $this->getValueFromValueArray($value);
                        } else {
                            $value_string .= ", " . $this->getValueFromValueArray($value);
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
                                $value_string .= $this->getValueFromValueArray($value);
                            else {
                                $value_string .= ", " . $this->getValueFromValueArray($value);
                            }
                        }
                    }
                    $row[$field_name] = $value_string;
                }

            }
            $ret[] = $row;
        }
        #kint($ret);
        $dir = "temporary://export_document";
        $path = "$dir/". date('Ymd-His') . "-document-list-" . rand() . ".csv";

        if (!file_exists($dir)) {
            mkdir($dir, 0770, TRUE);
        }

        $toWrite = "";
        foreach ($ret as $key => $row) {
            $toWrite .= implode(";", $row);
            $toWrite .= "\r\n";
        }
        $file = file_save_data($toWrite, $path);
        //$file->save();
        if ($file === false) {
            echo "Erreur lors de la création du fichier de résultat";
            die();
        }
        $headers = array(
            'Content-Type'     => 'text/csv',
            'Content-Disposition' => 'attachment; filename="'.$file->getFilename().'"'
        );
        #$uri = new Uri($file->getFileUri());

        return new BinaryFileResponse(drupal_realpath($file->getFileUri()), 200, $headers);
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
