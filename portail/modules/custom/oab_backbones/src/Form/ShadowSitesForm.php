<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 16:25
 */

namespace Drupal\oab_backbones\Form;


use Drupal\Core\File\FileSystem;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_backbones\Classes\ImportShadowSites;
use Drupal\oab_backbones\Classes\ShadowSites;

class ShadowSitesForm extends FormBase
{

    /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId()
    {
        return 'oab_backbones_shadow_sites_form';
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
    public function buildForm(array $form, FormStateInterface $form_state)
    {
        // lient vers le FO
        $form['link_fontoffice'] = array(
            '#weight' => -50,
            '#type' => 'link',
            '#title' => "Front office",
            '#url' => \Drupal\Core\Url::fromRoute('oab_backbones.view_front_page', array()),
            '#prefix' => "<p>",
            '#suffix' => "</p>",
        );

        /*********************************
         * Formulaire d'import des Shadow Sites
         *********************************/
        $form['import'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Import settings'),
            '#weight' => 1,
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
        );

        // File
        $form['import']['file'] = array(
            '#type' => 'file',
            '#title' => $this->t('Choose a file'),
            '#title_display' => 'invisible',
            '#size' => 22,
            '#theme_wrappers' => array(),
            '#weight' => -10,
        );

        // Bouton
        $form['import']['import'] = array(
            '#type' => 'submit',
            '#value' => $this->t('Import'),
            '#submit' => array('::executeImportHandler'),
            '#validate' => array('::validateImportHandler'),
        );

        // Last import
        $form['import']['last_import'] = array(
            '#type' => 'item',
            '#title' => $this->t('Last import'),
            '#markup' => \Drupal::state()->get('bbp_last_import_ss') ? date('m/d/Y H:i:s', \Drupal::state()->get('bbp_last_import_ss')) : $this->t('No import executed'),
            '#weight' => 0
        );


        /*********************************
         * Formulaire de modification des Shadow Sites
         *********************************/
        $form['management'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Management settings'),
            '#weight' => 2,
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
        );


        // Save
        $form['management']['save1'] = array(
            '#type' => 'submit',
            '#value' => $this->t('Save'),
            '#weight' => -5,
            '#submit' => array('::saveSitesValuesHandler')
        );

        $shadow_sites_object = new ShadowSites();
        $shadow_sitesTable = $shadow_sites_object->getShadowSitesTable();

        $options = array();
        $used_values = array();

        // Parcours des sites
        foreach ($shadow_sitesTable AS $shadowSite) {

            if ($shadowSite->used == 1) {
                $used_values[$shadowSite->sid] = 1;
            }

            $options[$shadowSite->sid] = array(
                'sid' => $shadowSite->sid,
                'probe_name' => $shadowSite->probe_name,
                'site_label' => array(
                    'data' => array(
                        '#type' => 'textfield',
                        '#title' => 'site_label',
                        '#title_display' => 'invisible',
                        '#name' => 'site_label_' . $shadowSite->sid,
                        '#value' => $shadowSite->site_label,
                        '#maxlength' => 50,
                        '#size' => 20,
                    )
                ),
            );
        }
        // On crée le tableau de selection
        $form['management']['sid'] = array(
            '#type' => 'tableselect',
            '#header' => $shadow_sites_object->getHeaderTable(),
            '#options' => $options,
            '#empty' => $this->t('No content available.'),
            '#value' => $used_values,
            '#multiple' => TRUE,
            '#weight' => 0,
        );

        $form['management']['site_label'] = array(
            '#type' => 'value',
        );
        $form['management']['save2'] = array(
            '#type' => 'submit',
            '#value' => $this->t('Save'),
            '#submit' => array('::saveSitesValuesHandler'),
            '#weight' => 5
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
    public function submitForm(array &$form, FormStateInterface $form_state)
    {
        //ne fait rien ici puisque 2 handler différents selon les boutons
    }

    public function validateImportHandler(array &$form, FormStateInterface $form_state)
    {
        if (!is_dir(ImportShadowSites::$IMPORT_DIRECTORY)) {
            $fs = \Drupal::service('file_system');
            $fs->mkdir(ImportShadowSites::$IMPORT_DIRECTORY, NULL, TRUE);
        }
        $file = file_save_upload('file', array('file_validate_extensions' => ''), ImportShadowSites::$IMPORT_DIRECTORY, null, FILE_EXISTS_REPLACE);
        // If the file passed validation:
        if (!$file[0]) {
            $form_state->setErrorByName('file', t('No file was uploaded.'));
        } else {
            $filename = $file[0]->getFilename();
            $input = &$form_state->getUserInput();
            $input["filename"] = $filename;
            $form_state->setUserInput($input);
        }
    }

    /** Méthode appelée lorsqu'on clique sur le bouton Importer
     */
    public function executeImportHandler(array &$form, FormStateInterface $form_state)
    {
        $input = &$form_state->getUserInput();
        $import = new ImportShadowSites();
        $import->executeImport($input['filename']);

    }

    /** Méthode appelée lorsqu'on clique sur les bouton Enregistrer
     */
    public function saveSitesValuesHandler(array &$form, FormStateInterface $form_state)
    {
        $shadow_sites_object = new ShadowSites();
        $shadow_sites_object->reinitUsedValuesForAllSites();

        $input = &$form_state->getUserInput();
        // On parse les résultats
        foreach ($input["sid"] as $key => $value) {
            if (isset($value) && $value <> "") {
                if (isset($input["site_label_" . $value])
                    && $input["site_label_" . $value] <> "") {
                    $shadow_sites_object->updateShadowSiteInDB($value, 1, trim($input["site_label_" . $value]));
                }
            }
        }
        drupal_set_message($this->t("Shadow sites updated"));
    }
}