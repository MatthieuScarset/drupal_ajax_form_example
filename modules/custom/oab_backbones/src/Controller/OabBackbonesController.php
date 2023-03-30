<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 09:29
 */

namespace Drupal\oab_backbones\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\File\FileUrlGenerator;
use Drupal\Core\Url;
use Drupal\oab_backbones\Classes\BackbonesImport;
use Drupal\oab_backbones\Classes\BackbonesImportData;
use Drupal\oab_backbones\Form\FilterPerformanceDataForm;
use Drupal\oab_backbones\Form\GlobalSettingsForm;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabBackbonesController extends ControllerBase {

  /**
   * @var FileUrlGenerator
   */
  private $fileUrlGenerator;

  /**
   * @var ExtensionPathResolver
   */
  private $pathResolver;

  public function __construct(FileUrlGenerator $file_url_generator, ExtensionPathResolver $extension_path_resolver) {
    $this->fileUrlGenerator = $file_url_generator;
    $this->pathResolver = $extension_path_resolver;
  }

  public static function create(ContainerInterface $container) {
    return new self(
      $container->get('file_url_generator'),
      $container->get('extension.path.resolver')
    );
  }

  /** Méthode appelée quand on va voir le détail d'un import en BO
     */
    public function viewDataImportAdmin(Request $request, $date_import, $site_sid) {

        //Récupération du formulaire
        $form = \Drupal::formBuilder()->getForm(FilterPerformanceDataForm::class);

        //pas de sid dans l'URL on prend la premiere valeur du formulaire
        if ($site_sid == '') {
            $site_sid = $form['shadowSites']['#default_value'];
        }

        //récupération des datas
        $bb_import_data_obj = new BackbonesImportData();
        $data = $bb_import_data_obj->getDatasForSiteAndDate($date_import, $site_sid);

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
            '#performanceDatas' => $tabs,
            '#filterForm' => $form,
            '#theme' => 'backbones_performance_data_admin',
            '#attached' => array(
                'library' => array(
                    'oab_backbones/oab_backbones.admin'
                ),
            ),
        );
    }

    /** Méthode appelée par la partie FO pour afficher toutes les données */
    public function viewFrontPage(Request $request, $date_import, $site_sid) {
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        if ($current_language != "en") {
            //on lance une 404
            throw new NotFoundHttpException();
        } else {
            //Récupération du formulaire
            $form = \Drupal::formBuilder()->getForm(FilterPerformanceDataForm::class);

            $bb_import_obj = new BackbonesImport();
            $months_import = $bb_import_obj->getLastImportsForSelection();
            if ($date_import == '' && count($months_import) > 0) {
                //get sur le dernier import connu
                $date_import = array_keys($months_import)[0];
            }

            //pas de sid dans l'URL on prend la premiere valeur du formulaire
            if ($site_sid == '') {
                $site_sid = $form['shadowSites']['#default_value'];
            }

            //récupération des datas
            $bb_import_data_obj = new BackbonesImportData();
            $data = $bb_import_data_obj->getDatasForSiteAndDate($date_import, $site_sid);
            $comment = $bb_import_obj->getCommentForImport($date_import);

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
                '#monthsImport' => $months_import,
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
    public function viewGlobalSettings(Request $request) {

        $bi_obj = new BackbonesImport();
        $imports = $bi_obj->getBackbonesImportTable()->fetchAll();

        //documentation
        $path_doc = $this->fileUrlGenerator->generateAbsoluteString(
          $this->pathResolver->getPath('module', 'oab_backbones') . '/BackbonesNotice.pdf');
        //Récupération du formulaire
        $form = \Drupal::formBuilder()->getForm(GlobalSettingsForm::class);

        return array(
            '#lastsImports' => $imports,
            '#documentation' => $path_doc,
            '#variablesForm' => $form,
            '#theme' => 'backbones_global_settings'
        );
    }


    /**
     * Méthode appelée quand on va sur la page See top ten d'un import
     */
    public function viewTopTenAdmin(Request $request, $date_import) {
        //récupération des datas
        $bb_import_data_obj = new BackbonesImportData();
        $return_rtd = $bb_import_data_obj->getTopTenDataForRTD($date_import);
        $data_plr = $bb_import_data_obj->getTopTenDataForPLR($date_import);
        $data_jitter = $bb_import_data_obj->getTopTenDataForJITTER($date_import);

        //construction des tableaux pour le rendu (résultats sur 2 tableaux)
        $last_import = $return_rtd["lastimport"];
        $data_rtd = $return_rtd["data"];
        $tabs_rtd = array();
        for ($i = 0; $i < count($data_rtd); $i++) {
            if ($i < count($data_rtd) / 2) {
                $tabs_rtd[0][] = $data_rtd[$i];
            } else {
                $tabs_rtd[1][] = $data_rtd[$i];
            }
        }

        $tabs_plr = array();
        for ($i = 0; $i < count($data_plr); $i++) {
            if ($i < count($data_plr) / 2) {
                $tabs_plr[0][] = $data_plr[$i];
            } else {
                $tabs_plr[1][] = $data_plr[$i];
            }
        }

        $tabs_jitter = array();
        for ($i = 0; $i < count($data_jitter); $i++) {
            if ($i < count($data_jitter) / 2) {
                $tabs_jitter[0][] = $data_jitter[$i];
            } else {
                $tabs_jitter[1][] = $data_jitter[$i];
            }
        }

        return array(
            '#actualimport' => substr($date_import, 4, 2) . '/' . substr($date_import, 0, 4),
            '#lastimport' => substr($last_import, 4, 2) . '/' . substr($last_import, 0, 4),
            '#dataRTD' => $tabs_rtd,
            '#dataPLR' => $tabs_plr,
            '#dataJITTER' => $tabs_jitter,
            '#theme' => 'backbones_top_ten_data_admin',
            '#attached' => array(
                'library' => array(
                    'oab_backbones/oab_backbones.admin'
                ),
            ),
        );

    }
}
