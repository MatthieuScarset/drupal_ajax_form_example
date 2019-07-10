<?php

namespace Drupal\oab_orange_business_lounge\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;



/**
 * Configure example settings for this site.
 */
class OabOblForm extends ConfigFormBase {

    public static function getConfigName() {
        return 'oab.orange_business_lounge_settings';
    }

    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_settings_orange_business_lounge';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            self::getConfigName(),
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config(self::getConfigName());

        $form['global'] = array(
            '#type' => 'fieldset',
            '#title' => t('Global Settings'),
        );

        $form['global']['url_api'] = array(
            '#type' => 'url',
            '#title' => $this->t('Url de l\'API'),
            '#default_value' => $config->get('url_api'),
            '#description' => 'API domain : ' . $config->get('url_api'),
            '#size'=> 80,
        );

        $form['global']['test_submit'] = array(
            '#type' => 'submit',
            '#value' => t('Test'),
            '#submit' => array('::isValid')
        );

        return parent::buildForm($form, $form_state);
    }


    /**
     * @param $form
     * @param FormStateInterface $form_state
     */
    function isValid($form, FormStateInterface $form_state) {

        $url = $form_state->getValue('url_api');

        /** @var \Drupal\oab_orange_business_lounge\Services\OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $obl_service->isValid($url);
    }


    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set('url_api', $form_state->getValue('url_api'))
            ->save();

        parent::submitForm($form, $form_state);
    }

}
