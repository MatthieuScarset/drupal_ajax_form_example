<?php

namespace Drupal\oab_cookie_compliance\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class CookieComplianceSettingsForm extends ConfigFormBase {

    const CONFIG_NAME = 'oab_cookie_compliance.cookie_compliance';
    public static function getConfigName() {
        return self::CONFIG_NAME;
    }
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_cookie_compliance_settings';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            self::CONFIG_NAME,
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config($this->getConfigName());

        $form['cookie_text'] = array(
            '#type' => 'textarea',
            '#title' => $this->t('Block Text'),
            '#default_value' => $config->get('cookie_text'),
        );

        $form['cookie_link_text'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Link text'),
            '#default_value' => $config->get('cookie_link_text'),
        );

        $form['cookie_url'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Link URL'),
            '#default_value' => $config->get('cookie_url'),
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set('cookie_text', $form_state->getValue('cookie_text'))
            ->set('cookie_link_text', $form_state->getValue('cookie_link_text'))
            ->set('cookie_url', $form_state->getValue('cookie_url'))
            ->save();

        parent::submitForm($form, $form_state);
    }
}
