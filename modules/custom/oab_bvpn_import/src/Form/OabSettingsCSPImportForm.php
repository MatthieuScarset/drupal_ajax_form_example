<?php

namespace Drupal\oab_bvpn_import\Form;

use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_bvpn_import\Classes\CSPImport;
use Symfony\Component\DependencyInjection\ContainerInterface;


class OabSettingsCSPImportForm extends FormBase
{
    /**
     * @var ExtensionPathResolver
     */
    private $pathResolver;
    /**
     * @var FileSystemInterface
     */
    private $fileSystem;
    public function __construct(ExtensionPathResolver $extension_path_resolver,
                                FileSystemInterface $file_system) {
      $this->pathResolver = $extension_path_resolver;
      $this->fileSystem = $file_system;
    }
    public static function create(ContainerInterface $container) {
      return new self(
        $container->get('extension.path.resolver'),
        $container->get('file_system')
      );
    }
    /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId() {
        return 'oab_bvpn_import_csp_import_form';
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

        $form['import'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Import CSP File'),
            '#weight' => 1,
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
        );

        // File
        $form['import']['file'] = array(
            '#type' => 'file',
            '#title' => $this->t('File'),
            '#title_display' => 'before',
            '#size' => 100,
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
        if (!is_dir(CSPImport::IMPORT_DIRECTORY)) {
            $fs->mkdir(CSPImport::IMPORT_DIRECTORY, NULL, TRUE);
        }

        $file = file_save_upload('file', array('file_validate_extensions' => ''),
          CSPImport::IMPORT_DIRECTORY, null,
          FileSystemInterface::EXISTS_REPLACE);

        // If the file passed validation:
        if (!$file[0]) {
            $form_state->setErrorByName('file', t('No file was uploaded.'));
        }
        else{
          $filename = $file[0]->getFilename();
          $input["filename"] = $filename;
          $form_state->setUserInput($input);
      }
    }

    /** Méthode appelée lorsqu'on clique sur le bouton Importer
     */
    public function executeImportHandler(array &$form, FormStateInterface $form_state) {
      $input = &$form_state->getUserInput();
      $import = new CSPImport($this->pathResolver, $this->fileSystem);
      $import->executeImport($input["filename"]);
    }
}
