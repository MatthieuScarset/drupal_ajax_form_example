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
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabBackbonesController extends ControllerBase
{
  /** Méthode appelée quand on va voir le détail d'un import en BO
   */
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
      '#theme' => 'backbones_performance_data_admin',
      '#attached' => array(
        'library' =>  array(
          'oab_backbones/oab_backbones.admin'
        ),
      ),
    );
  }

  /** Méthode appelée par la partie FO pour afficher toutes les données */
  public function viewFrontPage(Request $request, $date_import, $site_sid)
  {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    if($current_language != "en")
    {
      //on lance une 404
      throw new NotFoundHttpException();
    }
    else {
      //Récupération du formulaire
      $form = \Drupal::formBuilder()->getForm(FilterPerformanceDataForm::class);

      $bbImportObj = new BackbonesImport();
      $monthsImport = $bbImportObj->getLastImportsForSelection();
      if ($date_import == '' && count($monthsImport) > 0) {
        //get sur le dernier import connu
        $date_import = array_keys($monthsImport)[0];
      }

      //pas de sid dans l'URL on prend la premiere valeur du formulaire
      if ($site_sid == '') {
        $site_sid = $form['shadowSites']['#default_value'];
      }

      //récupération des datas
      $bbImportDataObj = new BackbonesImportData();
      $data = $bbImportDataObj->getDatasForSiteAndDate($date_import, $site_sid);
      $comment = $bbImportObj->getCommentForImport($date_import);

      //construction des tableaux pour le rendu (résultats sur 2 tableaux)
      $tabs = array();
      for ($i = 0; $i < count($data); $i++) {
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
          'library' => array(
            'oab_backbones/oab_backbones.front_office'
          ),
        ),
      );
    }
  }

  /** Méthode appelée pour l'onglet Global Settings de la partie BO */
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


  /**
   * Méthode appelée quand on va sur la page See top ten d'un import
   */
  public function viewTopTenAdmin(Request $request, $date_import)
  {
    //récupération des datas
    $bbImportDataObj = new BackbonesImportData();
    $returnRTD = $bbImportDataObj->getTopTenDataForRTD($date_import);
    $dataPLR = $bbImportDataObj->getTopTenDataForPLR($date_import);
    $dataJITTER = $bbImportDataObj->getTopTenDataForJITTER($date_import);

    //construction des tableaux pour le rendu (résultats sur 2 tableaux)
    $lastimport = $returnRTD["lastimport"];
    $dataRTD = $returnRTD["data"];
    $tabsRTD = array();
    for ($i = 0; $i < count($dataRTD); $i++)
    {
      if ($i < count($dataRTD) / 2) {
        $tabsRTD[0][] = $dataRTD[$i];
      } else {
        $tabsRTD[1][] = $dataRTD[$i];
      }
    }

    $tabsPLR = array();
    for ($i = 0; $i < count($dataPLR); $i++)
    {
      if ($i < count($dataPLR) / 2) {
        $tabsPLR[0][] = $dataPLR[$i];
      } else {
        $tabsPLR[1][] = $dataPLR[$i];
      }
    }

    $tabsJITTER = array();
    for ($i = 0; $i < count($dataJITTER); $i++)
    {
      if ($i < count($dataJITTER) / 2) {
        $tabsJITTER[0][] = $dataJITTER[$i];
      } else {
        $tabsJITTER[1][] = $dataJITTER[$i];
      }
    }

    return array(
      '#actualimport' => substr($date_import, 4, 2) . '/' . substr($date_import, 0, 4) ,
      '#lastimport' => substr($lastimport, 4, 2) . '/' . substr($lastimport, 0, 4)  ,
      '#dataRTD' => $tabsRTD,
      '#dataPLR' => $tabsPLR,
      '#dataJITTER' => $tabsJITTER,
      '#theme' => 'backbones_top_ten_data_admin',
      '#attached' => array(
        'library' =>  array(
          'oab_backbones/oab_backbones.admin'
        ),
      ),
    );

  }
}