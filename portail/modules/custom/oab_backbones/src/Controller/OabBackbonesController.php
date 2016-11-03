<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 09:29
 */

namespace Drupal\oab_backbones\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Url;
use Drupal\oab_backbones\Classes\BackbonesImport;
use Drupal\oab_backbones\Classes\BackbonesImportData;
use Drupal\oab_backbones\Form\FilterPerformanceDataForm;
use Drupal\oab_backbones\Form\GlobalSettingsForm;
use Symfony\Component\HttpFoundation\Request;

class OabBackbonesController extends ControllerBase
{
  public function viewDataImportAdmin(Request $request, $date_import, $site_sid){

    //Récupération du formulaire
    $form = \Drupal::formBuilder()->getForm(FilterPerformanceDataForm::class);

    //pas de sid dans l'URL on prend la premiere valeur du formulaire
    if($site_sid == '')
    {
      $site_sid = $form['shadowSites']['#default_value'];
    }

    //récupération des datas
    $bbImportDataObj = new BackbonesImportData();
    $data = $bbImportDataObj->getDatasForSiteAndDate($date_import, $site_sid);

    //construction des tableaux pour le rendu (résultats sur 2 tableaux)
    $tabs = array();
    for ($i = 0; $i < count($data); $i++)
    {
      if ($i < count($data) / 2) {
        $tabs[0][] = $data[$i];
      } else {
        $tabs[1][] = $data[$i];
      }
    }

    return array(
      '#intro' => \Drupal::config('oab_backbones.settings')->get('bbp_front_text'),
      '#performanceDatas' => $tabs,
      '#filterForm' => $form,
      '#theme' => 'backbones_performance_data_admin'
    );
  }

  public function viewFrontPage(Request $request, $date_import, $site_sid){

    //Récupération du formulaire
    $form = \Drupal::formBuilder()->getForm(FilterPerformanceDataForm::class);

    $bbImportObj = new BackbonesImport();
    $monthsImport = $bbImportObj->getLastImportsForSelection();
    if($date_import == '' && count($monthsImport) > 0){
      //get sur le dernier import connu
      $date_import = array_keys($monthsImport)[0];
    }

    //pas de sid dans l'URL on prend la premiere valeur du formulaire
    if($site_sid == '')
    {
      $site_sid = $form['shadowSites']['#default_value'];
    }

    //récupération des datas
    $bbImportDataObj = new BackbonesImportData();
    $data = $bbImportDataObj->getDatasForSiteAndDate($date_import, $site_sid);
    $comment = $bbImportObj->getCommentForImport($date_import);

    //construction des tableaux pour le rendu (résultats sur 2 tableaux)
    $tabs = array();
    for ($i = 0; $i < count($data); $i++)
    {
      if ($i < count($data) / 2) {
        $tabs[0][] = $data[$i];
      } else {
        $tabs[1][] = $data[$i];
      }
    }

    return array(
      '#intro' => \Drupal::config('oab_backbones.settings')->get('bbp_front_text'),
      '#monthsImport' => $monthsImport,
      '#performanceDatas' => $tabs,
      '#filterForm' => $form,
      '#currentImportDate' => $date_import,
      '#comment' => $comment,
      '#theme' => 'backbones_performance_front_office',
      '#attached' => array(
        'library' =>  array(
          'oab_backbones/oab_backbones.front_office'
        ),
      ),
    );
  }

  public function viewGlobalSettings(Request $request){

    $biObj = new BackbonesImport();
    $imports = $biObj->getBackbonesImportTable()->fetchAll();

    //documentation
    $pathDoc= file_create_url(drupal_get_path('module', 'oab_backbones'). '/BackbonesNotice.pdf');
    //Récupération du formulaire
    $form = \Drupal::formBuilder()->getForm(GlobalSettingsForm::class);

    return array(
      '#lastsImports' => $imports,
      '#documentation' => $pathDoc,
      '#variablesForm' => $form,
      '#theme' => 'backbones_global_settings'
    );
  }
}