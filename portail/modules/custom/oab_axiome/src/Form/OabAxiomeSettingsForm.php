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
  public static function getConfigName() {
    return 'oab.axiome_settings';
  }
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_axiome_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'oab.axiome_settings',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    $form['axiome_settings'] = array(
        '#type'     => 'fieldset',
        '#title'    => 'Axiome settings'
    );

    $form['axiome_settings']['axiome_enable_cron'] = array(
      '#type' => 'checkbox',
      '#title' => $this->t('Enable axiome cron'),
      '#default_value' => $config->get('axiome_enable_cron'),
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
      '#submit' => array(array($this, 'download_archive'))
    );

    $form['archive_management']['reimport_archive'] = array(
      '#type' => 'submit',
      '#value' => $this->t("Reimport the selected archive"),
      '#submit' => array(array($this, 'reimport_archive'))
    );


    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config($this->getConfigName())
      ->set('axiome_enable_cron', $form_state->getValue('axiome_enable_cron'))
      ->save();

    parent::submitForm($form, $form_state);
  }


  public function reimport_archive(&$form, FormStateInterface $form_state) {

      $archive = $form_state->getValue('select_archive');

      $archive_path = $this->getAxiomeSaveDir() . "/$archive";
      $new_path = \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER . "/$archive");

      if (!file_exists($archive_path)) {
          drupal_set_message($this->t("Selected archive doesn't exist."), 'error');
          return;
      }

      if (!rename($archive_path, $new_path)) {
          drupal_set_message($this->t("Moving archive failed."), 'error');
      } else {
          drupal_set_message($this->t("Moving archive succeed. Archive will be reimport at next cron (max 15min)."), 'success');
      }

  }


    public function download_archive(&$form, FormStateInterface $form_state) {

        $archive = $form_state->getValue('select_archive');

        $archive_path = $this->getAxiomeSaveDir() . "/$archive";


        if (!file_exists($archive_path)) {
            drupal_set_message($this->t("Selected archive doesn't exist."), 'error');
            return;
        }

        $response = new BinaryFileResponse($archive_path);

        $response->setContentDisposition(
            ResponseHeaderBag::DISPOSITION_ATTACHMENT,
            $archive
        );

        $form_state->setResponse($response);
    }


    /**
     * @param string $lang
     * @param int $size
     * @return array
     */
    private function getArchiveListe($lang = 'int', $size = 10) {
        $dir_path = $this->getAxiomeSaveDir();

        $ret = [];
        if ($dir = opendir($dir_path)) {
            while (false !== ($entry = readdir($dir)) && count($ret) < $size ) {
                $regex = "/ruby_".$lang."_\d{8}-\d{2}-\d{2}-\d{2}-\d{2}[.]zip/";
                if (preg_match($regex, $entry)) {
                    $ret[$entry] = $entry;
                }
            }

            closedir($dir);
        }

        return $ret;
    }


    private function getAxiomeSaveDir() {
        return \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER . '/' . AXIOME_SAVE_FOLDER);
    }

}
