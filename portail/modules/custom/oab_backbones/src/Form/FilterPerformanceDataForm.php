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
use Drupal\Core\Url;
use Drupal\oab_backbones\Classes\BackbonesImport;
use Drupal\oab_backbones\Classes\ShadowSites;

class FilterPerformanceDataForm extends FormBase
{

  /**
   * Returns a unique string identifying the form.
   *
   * @return string
   *   The unique string identifying the form.
   */
  public function getFormId()
  {
    return 'oab_backbones_filter_performance_data_form';
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
    $ssObj = new ShadowSites();
    $options = $ssObj->getUsedShadowSitesForSelector();
    if(count($options) > 0) {

      $selectedSite = \Drupal::routeMatch()->getParameter('site_sid');
     if(!isset($selectedSite) || empty($selectedSite))
      {
        $selectedSite = array_keys($options)[0];
      }

      // File
      $form['shadowSites'] = array(
        '#weight' => '1',
        '#key_type' => 'associative',
        '#multiple_toggle' => '1',
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $selectedSite,
        '#title' => t('View performance from')
      );

      // Bouton
      $form['button'] = array(
        '#weight' => '2',
        '#type' => 'submit',
        '#value' => $this->t('Apply'),
      );
    }
    //var_dump($form);
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
    $current_route = \Drupal::routeMatch()->getRouteName();
    $date_import = \Drupal::routeMatch()->getParameter('date_import');
    //s'il n'y a pas de date dans la route précédente on prend le dernier import validé
    if($date_import == '')
    {
      $bbImportObj = new BackbonesImport();
      $monthsImport = $bbImportObj->getLastImportsForSelection();
      if(count($monthsImport) > 0){//get sur le dernier import connu
        $date_import = array_keys($monthsImport)[0];
      }
    }
    $input = &$form_state->getUserInput();

    //ne fait rien ici puisque 2 handler différents selon les boutons
    $url = Url::fromRoute($current_route, array(
      'date_import' => $date_import,
      'site_sid' => $input["shadowSites"]));
    $form_state->setRedirectUrl($url);
  }

}