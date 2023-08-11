<?php

namespace Drupal\oab_data_import\Form;

use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_data_import\Classes\ProductCategoriesTermsImport;
use Symfony\Component\DependencyInjection\ContainerInterface;


class OabSettingsProductCategoriesTermsImportForm extends FormBase {

  /**
   * @var ProductCategoriesTermsImport
   */
  private ProductCategoriesTermsImport $termsImport;

  public function __construct(ProductCategoriesTermsImport $terms_import) {
    $this->termsImport = $terms_import;
  }

  public static function create(ContainerInterface $container) {
    return new self(
      $container->get('oab_data_import.product_categories_terms_import'),
    );
  }

    /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId() {
        return 'oab_product_categories_terms_import_form';
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
            '#title' => $this->t('Import terms of Product categories File'),
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
        if (!is_dir(ProductCategoriesTermsImport::IMPORT_DIRECTORY)) {
            $fs->mkdir(ProductCategoriesTermsImport::IMPORT_DIRECTORY, NULL, TRUE);
        }

        $file = file_save_upload('file', array('file_validate_extensions' => ''),
          ProductCategoriesTermsImport::IMPORT_DIRECTORY, null,
          FileSystemInterface::EXISTS_REPLACE);

        // If the file passed validation:
        if (!$file[0]) {
            $form_state->setErrorByName('file', t('No file was uploaded.'));
        } else {
          $filename = $file[0]->getFilename();
          $input["filename"] = $filename;
          $form_state->setUserInput($input);
      }
    }

    /** Méthode appelée lorsqu'on clique sur le bouton Importer
     */
    public function executeImportHandler(array &$form, FormStateInterface $form_state) {

        $input = &$form_state->getUserInput();
        $this->termsImport->executeImport($input["filename"]);
    }
}
