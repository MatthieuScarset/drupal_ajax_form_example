<?php

namespace Drupal\oab_akamai\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabAkamaiForm extends ConfigFormBase
{
    public static function getConfigName() {
        return 'oab.akamai_settings';
    }

    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_settings_akamai';
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

        $form['settings'] = array(
            '#type' => 'fieldset',
            '#title' => t('Akamai Settings'),
        );

        $form['settings']['enable_hook'] = array(
            '#type' => 'checkbox',
            '#title' => $this->t('Activer le vidage des caches à la sauvegarde d\'un noeud'),
            '#default_value' => $config->get('enable_hook'),
        );

        $form['settings']['auth_prefixe'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Authentification prefixe'),
            '#default_value' => str_replace(' ', '', $config->get('auth_prefixe')),
        );

        $form['settings']['base_url'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Base URL'),
            '#default_value' => $config->get('base_url'),
            '#description'  => "URL de l'API akamai, sans le https://"
        );

        $form['settings']['req_path'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Requete path'),
            '#default_value' => $config->get('req_path')
        );

        $form['settings']['access_token'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Access Token'),
            '#default_value' => $config->get('access_token')
        );

        $form['settings']['client_token'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Client Token'),
            '#default_value' => $config->get('client_token')
        );

        $form['settings']['client_secret'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Client Secrect'),
            '#default_value' => $config->get('client_secret')
        );

        $form['test'] = array(
            '#type' => 'details',
            '#title' => t('Tester les vidages de cache'),
            '#description'  => "Entrez une url pour tester le flush akamai",
        );

        $form['test']['test_url'] = array(
            '#type' => 'textfield',
            '#title' => t("URL")
        );

        $form['test']['test_host'] = array(
            '#type' => 'textfield',
            '#title' => t("Host"),
            '#description' => t("L'URL sans le path et la langue")
        );

        $form['test']['test_submit'] = array(
            '#type' => 'submit',
            '#value' => t('Essayer'),
            '#submit' => array('oab_akamai_testDrushAkamai')
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config(self::getConfigName())
            ->set('enable_hook', $form_state->getValue('enable_hook') )
            ->set('auth_prefixe', $form_state->getValue('auth_prefixe') . " ")
            ->set('req_path', $form_state->getValue('req_path') )
            ->set('base_url', $form_state->getValue('base_url') )
            ->set('access_token', $form_state->getValue('access_token') )
            ->set('client_token', $form_state->getValue('client_token') )
            ->set('client_secret', $form_state->getValue('client_secret') )
            ->save();

        parent::submitForm($form, $form_state);
    }

}
