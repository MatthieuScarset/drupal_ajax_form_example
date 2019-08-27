<?php

namespace Drupal\oab_synomia_search_flux\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsSynomiaContentTypesForm extends ConfigFormBase
{
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_synomia_contentTypes';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['oab_synomia_search.synomia.contentTypes',];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {

        $config = $this->config('oab_synomia_search.synomia.contentTypes');
        $content_types = \Drupal::service('entity.manager')->getStorage('node_type')->loadMultiple();
        $form['label'] = array(
            '#type' => 'label',
            '#title' => 'Select the types of content you want to index by Synomia search',
        );
        foreach ($content_types as $contentType) {
            $form[$contentType->id()] = array(
                '#type' => 'checkbox',
                '#title' => $contentType->label(),
                '#default_value' => $config->get($contentType->id()),
            );
        }
        $form['creationDateLimit'] = array(
            '#type' => 'date',
            '#title' => "Creation date limit",
            '#default_value' => $config->get('creationDateLimit'),
        );
    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $config = $this->config('oab_synomia_search.synomia.contentTypes');
        $content_types = \Drupal::service('entity.manager')->getStorage('node_type')->loadMultiple();
        foreach ($content_types as $contentType) {
            $config->set($contentType->id(), $form_state->getValue($contentType->id()));
        }

        $config->set('creationDateLimit', $form_state->getValue('creationDateLimit'));
        $config->save();
    parent::submitForm($form, $form_state);
  }
}
