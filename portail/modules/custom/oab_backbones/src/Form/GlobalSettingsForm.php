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
use Drupal\oab_backbones\Classes\ImportShadowSites;
use Drupal\oab_backbones\Classes\ShadowSites;

class GlobalSettingsForm extends FormBase
{

    /**
     * Returns a unique string identifying the form.
     *
     * @return string
     *   The unique string identifying the form.
     */
    public function getFormId() {
        return 'oab_backbones_global_settings_form';
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
    public function buildForm(array $form, FormStateInterface $form_state) {
        /** variables nid + texte du FO */
        $form['variables'] = array(
            '#type' => 'fieldset',
            '#title' => $this->t('Variables'),
            '#weight' => 1,
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
        );


        $form['variables']['bbp_network_solution_nid'] = array(
            '#type' => 'textfield',
            '#title' => t('nid of the network solution'),
            '#description' => t('could be replaced by another solution nid'),
            '#default_value' => \Drupal::config('oab_backbones.settings')->get('bbp_network_solution_nid'),
            //'#autocomplete_path' => 'admin/obs_backoffice/backbones/autocomplete/content_solution',
            '#size' => 60,
            '#disabled' => true,
            '#maxlength' => 10
        );

        $form['variables']['bbp_simple_page_nid'] = array(
            '#type' => 'textfield',
            '#title' => t('nid of a related simple page'),
            '#description' => t('this simple page will be used in front page'),
            '#default_value' => \Drupal::config('oab_backbones.settings')->get('bbp_simple_page_nid'),
            //'#autocomplete_path' => 'admin/obs_backoffice/backbones/autocomplete/pagette',
            '#size' => 60,
            '#disabled' => true,
            '#maxlength' => 10
        );


        $form['variables']['bbp_front_text'] = array(
            '#type' => 'textarea',
            '#title' => t('Front text of backbone page'),
            '#description' => t('this text will be displayed on the front page'),
            '#default_value' => \Drupal::config('oab_backbones.settings')->get('bbp_front_text'),
            '#size' => 60,
            '#maxlength' => 255
        );

        // Bouton
        $form['button'] = array(
            '#weight' => '2',
            '#type' => 'submit',
            '#value' => $this->t('Save'),
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
    public function submitForm(array &$form, FormStateInterface $form_state) {
        $input = &$form_state->getUserInput();

        \Drupal::configFactory()->getEditable('oab_backbones.settings')
            ->set('bbp_network_solution_nid', $input["bbp_network_solution_nid"])
            ->set('bbp_simple_page_nid', $input["bbp_simple_page_nid"])
            ->set('bbp_front_text', $input["bbp_front_text"])
            ->save();
    }
}
