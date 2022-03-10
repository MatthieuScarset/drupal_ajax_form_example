<?php

namespace Drupal\oab_bvpn_import\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_bvpn_import\Classes\CSPImport;
use Symfony\Component\DependencyInjection\ContainerInterface;


class OabSettingsCSPImportForm extends FormBase {

  /**
   * @var CSPImport
   */
  private CSPImport $cspImport;

  public function __construct(CSPImport $csp_import) {
    $this->cspImport = $csp_import;
  }

  public static function create(ContainerInterface $container): OabSettingsCSPImportForm {
    return new self(
      $container->get('oab_bvpn_import.csp_import')
    );
  }

  /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId(): string {
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
    public function buildForm(array $form, FormStateInterface $form_state): array {

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
        $file = $this->cspImport->saveFileImport();
        // If the file passed validation:
        if (!$file[0]) {
            $form_state->setErrorByName('file', t('No file was uploaded.'));
        }
        else {
          $filename = $file[0]->getFilename();
          $input["filename"] = $filename;
          $form_state->setUserInput($input);
      }
    }

    /** Méthode appelée lorsqu'on clique sur le bouton Importer
     */
    public function executeImportHandler(array &$form, FormStateInterface $form_state) {

        $input = &$form_state->getUserInput();
        $this->cspImport->executeImport($input["filename"]);
    }
}
