<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 16:25
 */

namespace Drupal\oab_backbones\Form;

use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_backbones\Classes\BackbonesImport;
use Drupal\oab_backbones\Classes\ImportPerformanceData;
use Symfony\Component\DependencyInjection\ContainerInterface;


class PerformanceDataForm extends FormBase {

  /**
   * @var FileSystemInterface
   */
  private $fileSystem;

  /**
   * @var ImportPerformanceData
   */
  private $importPerformanceData;

  /**
   * PerformanceDataForm constructor.
   *
   * @param FileSystemInterface $file_system
   * @param ImportPerformanceData $import_performance_data
   */
  public function __construct(FileSystemInterface $file_system, ImportPerformanceData $import_performance_data) {
      $this->fileSystem = $file_system;
      $this->importPerformanceData = $import_performance_data;
  }

  /**
   * @param ContainerInterface $container
   * @return PerformanceDataForm|static
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('file_system'),
      $container->get('oab_backbones.import_performance_data')
    );
  }

    /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId() {
        return 'oab_backbones_performance_data_form';
    }

    /**
     * Form constructor.
     *
     * @param array $form
     *   An associative array containing the structure of the form.
     * @param \Drupal\Core\Form\FormStateInterface $form_state
     *   The current state of the form.
     *
     * @return array
     *   The form structure.
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        // lien vers le FO
        $form['link_fontoffice'] = array(
            '#weight' => -50,
            '#type' => 'link',
            '#title' => "Front office",
            '#url' => \Drupal\Core\Url::fromRoute('oab_backbones.view_front_page', array()),
            '#prefix' => "<p>",
            '#suffix' => "</p>",
        );

        /*********************************
         * Formulaire d'import des données pour un mois
         *********************************/
        $form['import'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Import settings'),
            '#description' => $this->t('The performance data must be imported every month.'),
            '#weight' => 1,
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
        );

        // File
        $form['import']['file'] = array(
            '#type' => 'file',
            '#title' => $this->t('File'),
            '#description' => $this->t('The month is determined by the filename'),
            '#title_display' => 'before',
            '#size' => 50,
            '#weight' => 2,
        );

        // Bouton
        $form['import']['actions'] = array('#type' => 'actions');
        $form['import']['actions']['import'] = array(
            '#type' => 'submit',
            '#value' => $this->t('Import'),
            '#submit' => array('::executeImportHandler'),
            '#validate' => array('::validateImportHandler'),
        );


        /*********************************
         * Formulaire de validation des import (status + commentaire)
         *********************************/
        $form['validation'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Validation'),
            '#description' => $this->t('Click on the date to see the performance data'),
            '#weight' => 2,
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
        );

        $bi_obj = new BackbonesImport();
        $imports = $bi_obj->getBackbonesImportTable();
        $header = $bi_obj->getHeaderTable();

        $options = array();
        $keys = array();

        foreach ($imports AS $import) {
            $keys[$import->date] = NULL;

            $options[$import->date] = array(
                'date' => array(
                    'data' => array(
                        '#type' => 'link',
                        '#title' => substr($import->date, 0, 4) . '/' . substr($import->date, 4, 2),
                        '#url' => \Drupal\Core\Url::fromRoute('oab_backbones.view_import', array('date_import' => $import->date))
                    )
                ),
                'top_ten' => array(
                    'data' => array(
                        '#type' => 'link',
                        '#title' => t("See top ten values"),
                        '#url' => \Drupal\Core\Url::fromRoute('oab_backbones.top_ten', array('date_import' => $import->date))
                    )
                ),
                'status' => array(
                    'data' => array(
                        '#type' => 'select',
                        '#title' => 'status',
                        '#title_display' => 'invisible',
                        '#name' => 'status_' . $import->date,
                        '#value' => $import->status,
                        '#default_value' => $import->status,
                        '#options' => array(
                            0 => t('Invalid'),
                            1 => t('Valid'),
                        ),
                    )
                ),
                'comment' => array(
                    'data' => array(
                        '#type' => 'textarea',
                        '#title' => 'comment',
                        '#title_display' => 'invisible',
                        '#name' => 'comment_' . $import->date,
                        '#value' => $import->comment,
                        '#maxlength' => 50,
                        '#size' => 20,
                    )
                ),
            );
        }
        //var_dump($options);

        // On crée le tableau de selection
        $form['validation']['months'] = array(
            '#type' => 'tableselect',
            '#header' => $header,
            '#options' => $options,
            '#empty' => t('No content available.'),
            '#value' => $keys,
            '#multiple' => TRUE,
        );

        $form['validation']['status'] = array(
            '#type' => 'value',
        );

        $form['validation']['comment'] = array(
            '#type' => 'value',
        );

        $form['validation']['actions'] = array(
            '#type' => 'actions',
        );

        $form['validation']['actions']['validation'] = array(
            '#type' => 'submit',
            '#value' => t('Save'),
            '#submit' => array('::executeValidateHandler'),
            '#weight' => -5
        );

        $form['#attached']['library'][] = 'oab_backbones/oab_backbones.admin';

        return $form;

    }

    /**
     * Form submission handler.
     *
     * @param array $form
     *   An associative array containing the structure of the form.
     * @param \Drupal\Core\Form\FormStateInterface $form_state
     *   The current state of the form.
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
    }


    /** Validation du fichier avant l'import et recopie avec le bon nom
     */
    public function validateImportHandler(array &$form, FormStateInterface $form_state) {
        $fs = \Drupal::service('file_system');
        if (!is_dir(ImportPerformanceData::IMPORT_DIRECTORY)) {
            $fs->mkdir(ImportPerformanceData::IMPORT_DIRECTORY, NULL, TRUE);
        }
        if (!is_dir(ImportPerformanceData::IMPORT_TMP_DIRECTORY)) {
            $fs->mkdir(ImportPerformanceData::IMPORT_TMP_DIRECTORY, NULL, TRUE);
        }
        $file = file_save_upload('file', array('file_validate_extensions' => ''),
            ImportPerformanceData::IMPORT_TMP_DIRECTORY, null,
            $this->fileSystem::EXISTS_REPLACE);
        // If the file passed validation:
        if (!$file[0]) {
            $form_state->setErrorByName('file', t('No file was uploaded.'));
        } else {
            $filename = $file[0]->getFilename();
            // openstat_backbone_path_performance_1.0_usa_mYYYYmm.csv.zip
            if (preg_match('/openstat_backbone_path_performance_1\.0_usa_m([0-9]{6})/', $filename, $matches)) {
                // Move the file into the Drupal file system.
                if ($this->fileSystem->move($file[0]->getFileUri(),
                  ImportPerformanceData::IMPORT_DIRECTORY . 'DATA_' . $matches[1] . '.csv.zip', $this->fileSystem::EXISTS_REPLACE)) {
                    // Save the file for use in the submit handler.
                    $input = &$form_state->getUserInput();
                    $input["month"] = $matches[1];
                    $form_state->setUserInput($input);

                } else {
                    $form_state->setErrorByName('file', t("Failed to write the uploaded file to the site's file folder."));
                }
            } else {
                $form_state->setErrorByName('file', t("Filename isn't correct."));
            }
        }
    }

  /**
   * Méthode appelée lorsqu'on clique sur le bouton Importer
   * @param array $form
   * @param FormStateInterface $form_state
   */
    public function executeImportHandler(array &$form, FormStateInterface $form_state) {
        $input = &$form_state->getUserInput();
        $this->importPerformanceData->executeImport($input['month']);
    }

    /** Méthode appelée pour enregistrer les données saisies (status + commentaire)
     */
    public function executeValidateHandler(array &$form, FormStateInterface $form_state) {
        $input = &$form_state->getUserInput();
        $bb_obj = new BackbonesImport();
        foreach ($input['months'] as $month => $value) {
            if (isset($input['status_' . $month]) && isset($input['comment_' . $month])) {
                $bb_obj->updateImportInDB($month, $input['status_' . $month], $input['comment_' . $month]);
            }
        }
    }
}
