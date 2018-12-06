<?php

namespace Drupal\oab_synomia_search_engine\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSynomiaSearchSettingsForm extends ConfigFormBase
{

    public static function getConfigName() {
        return 'oab.synomia.searchSettings';
    }
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_synomia_search';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [ $this->getConfigName() ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config($this->getConfigName());
        $languages = \Drupal::languageManager()->getLanguages();
        //urls synomia selon les langue pour l'appel du flux de recherche
        foreach ($languages as $language) {
            $form['url_synomia_'.$language->getId()] = array(
                '#type' => 'textfield',
                '#title' => 'URL Synomia for '.$language->getName(),
                '#default_value' => \Drupal::state()->get('url_synomia_'.$language->getId()),
            );
        }
        //nombre de résultats par page
        $form['nb_results_per_page'.$language->getId()] = array(
            '#type' => 'textfield',
            '#title' => 'Number of results per page (default : 10)',
            '#default_value' => $config->get('nb_results_per_page'),
        );
        //ordre des tyoes de contenus
        foreach ($languages as $language) {
            $form['order_content_types_'.$language->getId()] = array(
                '#type' => 'textarea',
                '#size' => '200',
                '#title' => 'Content types order for '.$language->getName(),
                '#default_value' => $config->get('order_content_types_'.$language->getId()),
            );
        }
    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $config = $this->config($this->getConfigName());
        $languages = \Drupal::languageManager()->getLanguages();
        foreach ($languages as $language) {
            \Drupal::state()->set('url_synomia_'.$language->getId(), $form_state->getValue('url_synomia_'.$language->getId()));
            $config->set('order_content_types_'.$language->getId(), $form_state->getValue('order_content_types_'.$language->getId()));
        }
        $config->set('nb_results_per_page', $form_state->getValue('nb_results_per_page'));
        $config->save();
    parent::submitForm($form, $form_state);
  }
}
