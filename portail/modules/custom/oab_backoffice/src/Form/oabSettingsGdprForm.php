<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsGdprForm extends ConfigFormBase {
    public static function getConfigName(){
        return 'oab.gdpr_settings';
    }
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_gdpr_settings';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            'oab.gdpr_settings',
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config($this->getConfigName());

        $form['mail_spoc'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Mail to SPOC'),
            '#default_value' => $config->get('mail_spoc'),
        );

        $form['mail_creator'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Mail to creator'),
            '#default_value' => $config->get('mail_creator'),
        );

        $form['mail_creator'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Mail to creator'),
            '#default_value' => $config->get('mail_creator'),
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set('proxy_server', $form_state->getValue('proxy_server'))
            ->set('proxy_port', $form_state->getValue('proxy_port'))
            ->save();

        parent::submitForm($form, $form_state);
    }
}
