<?php

namespace Drupal\oab_axiome\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\HttpFoundation\BinaryFileResponse;
use Symfony\Component\HttpFoundation\ResponseHeaderBag;

/**
 * Configure example settings for this site.
 */
class OabAxiomeSettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_axiome';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab.axiome',
    ];
  }

  public static function getConfigName() {
      return 'oab.axiome';
  }


  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('oab.axiome');

    $form['axiome_settings'] = array(
        '#type'     => 'fieldset',
        '#title'    => 'Axiome settings'
    );

    $form['axiome_settings']['axiome_enable_cron'] = array(
      '#type' => 'checkbox',
      '#title' => $this->t('Enable axiome cron'),
      '#default_value' => $config->get('axiome_enable_cron'),
    );

    $form['axiome_settings']['icon_frame_connectivity'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-connectivity'),
      '#default_value' => $config->get('icon_frame_connectivity'),
    );

    $form['axiome_settings']['icon_frame_teamwork'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-teamwork'),
      '#default_value' => $config->get('icon_frame_teamwork'),
    );

    $form['axiome_settings']['icon_frame_my_customers'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-my-customers'),
      '#default_value' => $config->get('icon_frame_my_customers'),
    );

    $form['axiome_settings']['icon_frame_performance'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-performance'),
      '#default_value' => $config->get('icon_frame_performance'),
    );

    $form['axiome_settings']['icon_frame_security'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-security'),
      '#default_value' => $config->get('icon_frame_security'),
    );

    $form['axiome_settings']['icon_frame_care'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-care'),
      '#default_value' => $config->get('icon_frame_care'),
    );

    $form['axiome_settings']['icon_frame_tech'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('icon-frame-tech'),
      '#default_value' => $config->get('icon_frame_tech'),
    );
    $form['archive_management'] = array(
        '#type'     => 'details',
        '#title'    => $this->t('Archive management')
    );

    $form['archive_management']['select_archive'] = array(
      '#type'     => 'select',
      '#title'    => $this->t('Saved Archive List'),
      '#options'    => [
          "Int" => $this->getArchiveListe(),
          "Fr"  => $this->getArchiveListe('fr')
      ]
    );

    $form['archive_management']['download_archive'] = array(
      '#type' => 'submit',
      '#value' => $this->t("Download the selected archive"),
      '#submit' => array(array($this, 'downloadArchive'))
    );

    $form['archive_management']['reimport_archive'] = array(
      '#type' => 'submit',
      '#value' => $this->t("Reimport the selected archive"),
      '#submit' => array(array($this, 'reimportArchive'))
    );


      return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab.axiome')
      ->set('axiome_enable_cron', $form_state->getValue('axiome_enable_cron'))
      ->set('icon_frame_connectivity', $form_state->getValue('icon_frame_connectivity'))
      ->set('icon_frame_teamwork', $form_state->getValue('icon_frame_teamwork'))
      ->set('icon_frame_my_customers', $form_state->getValue('icon_frame_my_customers'))
      ->set('icon_frame_performance', $form_state->getValue('icon_frame_performance'))
      ->set('icon_frame_security', $form_state->getValue('icon_frame_security'))
      ->set('icon_frame_care', $form_state->getValue('icon_frame_care'))
      ->set('icon_frame_tech', $form_state->getValue('icon_frame_tech'))
      ->save();

    parent::submitForm($form, $form_state);
  }


    /**
     * Déplace l'archive selectionner pour repasser l'import Axiome
     */
  public function reimportArchive(&$form, FormStateInterface $form_state) {

      // Je recupère le nom de l'archive
      $archive = $form_state->getValue('select_archive');

      // Je recrée les paths
      $archive_path = $this->getAxiomeSaveDir() . "/$archive";
      $new_path = \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER . "/$archive");


      // Si le fichier n'existe pas, je met une erreur (mais Drupal devrait avoir coupé avant si le fichier n'existe pas)
      if (!file_exists($archive_path)) {
          drupal_set_message($this->t("Selected archive doesn't exist."), 'error');
          return;
      }

      //Je déplace le fichier et j'affiche un message de succès ou d'erreur
      if (!rename($archive_path, $new_path)) {
          drupal_set_message($this->t("Moving archive failed."), 'error');
      } else {
          drupal_set_message($this->t("Moving archive succeed. Archive will be reimport at next cron (max 15min)."), 'success');
      }

  }


    /**
     * Permet de télécharger l'archive sélectionnée
     */
    public function downloadArchive(&$form, FormStateInterface $form_state) {

        // Je recupère l'archive selectionnée
        $archive = $form_state->getValue('select_archive');

        // Recreation du path
        $archive_path = $this->getAxiomeSaveDir() . "/$archive";

        //Petit check si le fichier existe
        if (!file_exists($archive_path)) {
            drupal_set_message($this->t("Selected archive doesn't exist."), 'error');
            return;
        }

        // Je crée une nouvelle reponse à renvoyer à l'utilisateur avec le fichier
        $response = new BinaryFileResponse($archive_path);

        $response->setContentDisposition(
            ResponseHeaderBag::DISPOSITION_ATTACHMENT,
            $archive
        );

        $form_state->setResponse($response);
    }


    /**
     * Renvoie la liste des archives présentes dans le dossier sauvegarde pour une langue donnée (int ou fr)
     */
    private function getArchiveListe($lang = 'int', $size = 10) {
        $dir_path = $this->getAxiomeSaveDir();

        $ret = [];

        $regex = "/ruby_" . $lang . "_\d{8}(-\d{1,2}){4}[.]zip/";

        // Ouverture du dossier sauvegarde
        if ($dir = opendir($dir_path)) {
            $tmp_list = []; //tmp pour trier les fichiers par date

            // Je lis les entrées tant qu'on a pas atteint le nbre d'occurrences passé en param
            while (false !== ($entry = readdir($dir))) {

                if (preg_match($regex, $entry)) {
                    $tmp_list[$entry] = $entry;
                }

            }
            closedir($dir);

            krsort($tmp_list);
            $ret = array_slice($tmp_list, 0, $size);
        }

        return $ret;
    }


    /**
     * Pour recuperer facilement le dossier de sauvegarde
     */
    private function getAxiomeSaveDir() {
        return \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER . '/' . AXIOME_SAVE_FOLDER);
    }

}
