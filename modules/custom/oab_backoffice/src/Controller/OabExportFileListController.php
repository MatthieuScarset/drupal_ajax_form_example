<?php
namespace Drupal\oab_backoffice\Controller;

define('SESSION_NAME', 'oab_backoffice.export_file_download');

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\File\FileUrlGenerator;
use Drupal\Core\Routing\UrlGeneratorInterface;
use Drupal\Core\StackMiddleware\Session;
use Drupal\Core\TypedData\Plugin\DataType\Uri;
use Drupal\Core\Url;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\file\Entity\File;
use Drupal\system\FileDownloadController;
use Drupal\taxonomy\Entity\Term;
use Drupal\views\Views;
use JetBrains\PhpStorm\ArrayShape;
use Symfony\Cmf\Component\Routing\VersatileGeneratorInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\BinaryFileResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;
use Drupal\Core\TempStore\PrivateTempStoreFactory;
use Symfony\Component\HttpFoundation\RedirectResponse;

class OabExportFileListController extends ControllerBase {
    private static $dir = "public://export_document";
    private static $logName = "oab_export_file";

  /**
   * @var FileSystemInterface
   */
    private $fileSystem;

  /**
   * @var Url
   */
    private $url;

  /**
   * @var FileUrlGenerator
   */
  private $fileUrlGenerator;


  public function __construct(FileSystemInterface $file_system, UrlGeneratorInterface $url_interface, FileUrlGenerator $file_url_generator) {
      $this->fileSystem = $file_system;
      $this->url = $url_interface;
      $this->fileUrlGenerator = $file_url_generator;
    }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('file_system'),
      $container->get('url_generator'),
      $container->get('file_url_generator')
    );
  }

  public function runBatch(Request $request) {

        $origin_path = $request->headers->get('referer');

        ##Je tente de regarder s'il y a des paramètres dans l'URL
        # ie. si des filtres ont été ajoutés à la vue
        $params = [];
        $origin_path_parts = explode("?", $origin_path);
        if (count($origin_path_parts) > 1) {
            $parameters = explode("&", $origin_path_parts[1]);
            foreach ($parameters as $param_string) {
                $param = explode("=", $param_string);
                if (isset($param[0]) && isset($param[1])) {
                    $params[$param[0]] = $param[1];
                }
            }
        }

        ## Si le dossier n'existe pas, je tente de le créer
        if (!file_exists(self::$dir)) {
            try {
                mkdir(self::$dir, 0775);
            } catch (\exception $e) {
                $this->messenger->addError("Erreur lors de la création du dossier d'export. Voir en log pour plus d'informations", true);
                \Drupal::logger(self::$logName)
                    ->notice("Erreur lors de la création du dossier d'export avec le message : " . $e->getMessage());
                $response = new RedirectResponse($origin_path);
                $response->send();
            }
        }


        $view = Views::getView('document_list');
        $view->get_total_rows = true;
        $view->setDisplay('document_list_page');
        $view->setExposedInput($params);        # Je set les paramètres recupérés dans l'URL pour
        # mettre les memes filtres que la vue qui s'est affichée

        ## Je supprime le pager pour recuperer tous les éléments
        #$view->display_handler->options['pager']['type'] = 'none';
        $view->execute();

        ##Création du nom unique du fichier final
        $file_name = date('Ymd-His') . "-document-list-" . rand() . ".csv";

        $operations = array();
        $first_row = 0;

        $view->setItemsPerPage(100);

        while ($first_row < $view->total_rows) {
            $operations[] = [
              '\Drupal\oab_backoffice\Controller\OabExportFileListController::exportFileList', [$first_row, $file_name, $params]
            ];
            $first_row += 100;
        }


        ##Setting up du batch
        $batch = array(
            'title' => t("Export document list"),
            'operations'  => $operations,
            'progress_message' => t('Processed @current out of @total.'),
        );


        #Je recupère le nom des colonnes pour la 1ere ligne du fichier
        $col_name = array();
        foreach ($view->field as $field_name => $field_data) {
           $col_name[] = $field_data->options['label'];
        }

        ## On remonte une erreur si on n'arrive pas à écrire le fichier
        if (false === $this->write_file(array($col_name), $file_name)) {
            \Drupal::logger(self::$logName)->notice("Erreur lors de la creation du fichier");
            $this->messenger->addError("Erreur lors de la creation du fichier", true);
            $response = new RedirectResponse($origin_path);
            $response->send();
        }

        ##j'enregistre l'URL d'origine (utilisée pour créer un lien de retour à la fin du batch)
        $tempstore = \Drupal::service('tempstore.private')->get(SESSION_NAME);
        $tempstore->set('origin_url', $origin_path);
        $tempstore->set('file_path', self::$dir . "/" .$file_name);


        ## Lien de la page à afficher à la fin de la création du fichier
        $route = $this->url->generateFromRoute('oab_backoffice.download_file_list');

        batch_set($batch);
        return batch_process($route);
    }


    /**
     * Méthode appelée quand on va voir le détail d'un import en BO
     */
    static public function exportFileList($first_row, $file_name, $params, &$context) {

        $view = Views::getView('document_list');
        $view->get_total_rows = true;
        $view->setDisplay('document_list_page');
        $view->setItemsPerPage(100);
        $view->setExposedInput($params);
        $view->setOffset($first_row);
        $view->preview();

        ## Tableau pour recuperer toutes les infos
        $ret = array();

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
                if ($entity->hasField($field_real_name)) {
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
                    if ($relationship->hasField($field_real_name)) {
                        $values = $relationship->get($field_real_name)->getValue();


                        foreach ($values as $key => $value) {
                            if ($key == 0) {
                                $value_string .= self::getValueFromValueArray($value);
                            } else {
                                $value_string .= ", " . self::getValueFromValueArray($value);
                            }
                        }
                    }
                    $row[$field_name] = $value_string;
                }

            }
            $ret[] = $row;
        }


        $success = self::write_file($ret, $file_name);
        #On remonte une erreur si le fichier n'est pas ecrit
        if ($success === false) {
            \Drupal::logger(self::$logName)->notice("Erreur lors de la creation du fichier");
            \Drupal::messenger()->addError("Erreur lors de la creation du fichier", true);

            $context['results'][] = 'Erreur lors de la creation du fichier';
            $context['finished'] = 1.0;

        }


    }


    public function endingBatch($file_name, $success, $results, $operations) {
        if (file_exists(self::$dir . "/" .$file_name)) {

        } else {
            \Drupal::logger(self::$logName)->notice("le fichier d'export est introuvable");
        }
    }


    #[ArrayShape([
      "#theme" => "string",
      "#file_url" => "string",
      "#origin_url" => "mixed"
    ])] public function endingPage(Request $request): array {

        $referer = $request->headers->get('referer');
        if ($referer === null) {
            throw new \Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException();
        }

        ##Je recupère les deux données sauvées pour l'affichage
        $tempstore = \Drupal::service('tempstore.private')->get(SESSION_NAME);
        $file_path = $tempstore->get('file_path');
        $origin = $tempstore->get('origin_url');

        if (!file_exists($file_path)) {
            throw new \Symfony\Component\HttpKernel\Exception\NotFoundHttpException('Le fichier demandé n\'existe pas');
        }


        $url = $this->fileUrlGenerator->generateAbsoluteString($file_path);

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
        if ($dir = opendir(self::$dir)) {
            while (false !== ($entry = readdir($dir))) {
                if ($entry != "." && $entry != "..") {
                    unlink(self::$dir . "/" . $entry);
                }
            }
            closedir($dir);
        }
    }



    private static function write_file($tab, $file_name): bool|int {
        $to_write = "";
        foreach ($tab as $key => $row) {
            $to_write .= implode(";", $row);
            $to_write .= "\r\n";
        }
        $path = self::$dir."/$file_name";
        #$file = file_unmanaged_save_data($to_write, $path);
        return file_put_contents($path, $to_write, FILE_APPEND);


    }


    private static function getValueFromValueArray($value_array) {
        $ret = "";

        ##Gestion des Targetsid
        if (isset($value_array['target_id'])) {
            $target_id = intval($value_array['target_id']);
            if ($target_id == 0) {
                return $value_array['target_id'];
            }
            $entity = Term::load($target_id);
            if (!is_null($entity) and is_a($entity, 'Drupal\taxonomy\Entity\Term')) {
                return $entity->getName();
            }

            $entity = File::load($target_id);
            if (!is_null($entity)) {
                $uri = $entity->getFileUri();
                return \Drupal::service('file_system')->realpath($uri);
            }
        }

          ##Cas des "value"
          if (isset($value_array['value'])) {
            # Cas d'un timestamp
            if (strlen($value_array['value']) === 10 && is_numeric($value_array['value'])) {
              $date = date('d/m/Y H:i:s', $value_array['value']);
              if ( false != $date) {
                return $date;
              }
            }

            return $value_array['value'];
          }

        return $ret;
    }
}
