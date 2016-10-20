<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 16:25
 */

namespace Drupal\oab_backbones\Form;


use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_backbones\Plugin\ImportShadowSites;
use Drupal\oab_backbones\Plugin\ShadowSites;

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
      '#markup' => \Drupal::state()->get('bbp_last_import_ss') ? date ('m/d/Y H:i:s', \Drupal::state()->get('bbp_last_import_ss') ) : $this->t('No import executed'),
      '#weight' => 0
    );


    $form['management'] = array(
      '#type' => 'fieldset',
      '#title' => t('Management settings'),
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

    $shadowSitesObject = new ShadowSites();
    $shadowSitesTable = $shadowSitesObject->getShadowSitesTable();

    $options = array();
    $used_values = array();

    // Parcours des sites
    foreach ($shadowSitesTable AS $shadowSite) {

      if ($shadowSite->used == 1) {
        $used_values[$shadowSite->sid] = 1;
      }

      $options[$shadowSite->sid] = array(
        'sid' => $shadowSite->sid,
        'probe_name' => $shadowSite->probe_name,
        'site_label' => array(
          'data' => array (
            '#type' => 'textfield',
            '#title' => 'site_label',
            '#title_display'=>'invisible',
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
      '#header' => $shadowSitesObject->getHeaderTable(),
      '#options' => $options,
      '#empty' => t('No content available.'),
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
    if(!is_dir(ImportShadowSites::$IMPORT_DIRECTORY))
    {
      mkdir(ImportShadowSites::$IMPORT_DIRECTORY);
    }
    $file = file_save_upload('file', array('file_validate_extensions' => ''), ImportShadowSites::$IMPORT_DIRECTORY, null, FILE_EXISTS_REPLACE);
    // If the file passed validation:
    if (!$file[0])
    {
      $form_state->setErrorByName('file', t('No file was uploaded.'));
      print 'else';
    }
  }

  /** Méthode appelée lorsqu'on clique sur le bouton Importer
   * @param array $form
   * @param FormStateInterface $form_state
   */
  public function executeImportHandler(array &$form, FormStateInterface $form_state) {
    $import = new ImportShadowSites();
    $import->executeImport();
  }

  /** Méthode appelée lorsqu'on clique sur les bouton Enregistrer
   * @param array $form
   * @param FormStateInterface $form_state
   */
  public function saveSitesValuesHandler(array &$form, FormStateInterface $form_state) {
    $shadowSitesObject = new ShadowSites();
    $shadowSitesObject->reinitUsedValuesForAllSites();

    $input = &$form_state->getUserInput();
    // On parse les résultats
    foreach ($input["sid"] as $key => $value)
    {
      if (isset($value) && $value <> "")
      {
        if (isset($input["site_label_".$value])
          && $input["site_label_".$value] <> "")
        {
          $shadowSitesObject->updateShadowSiteInDB($value, 1, trim($input["site_label_".$value]));
        }
      }
    }
    drupal_set_message($this->t("Shadow sites updated"));
  }
}