<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsGdprForm extends ConfigFormBase {
    public static function getConfigName() {
        return 'oab_backoffice.gdpr_settings';
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
            'oab_backoffice.gdpr_settings',
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config($this->getConfigName());

        #############################
        ## Mail to SPOC
        $form['mail_spoc'] = array(
            '#type' => 'details',
            '#open' => true,
            '#title' => t('Mail SPOC'),
            '#description'    => t("Mail envoyé au SPOC Securité à la création d'un webform"),
        );

        $form['mail_spoc']['mail_spoc_object'] = array(
            '#type' => 'textfield',
            "#format" => "full_html",
            '#title' => $this->t('Object'),
            '#default_value' => $config->get('mail_spoc_object')
        );

        $form['mail_spoc']['mail_spoc_body'] = array(
            '#type' => 'textarea',
            '#title' => $this->t('Body'),
            '#default_value' => $config->get('mail_spoc_body'),
            '#description'  => "Paste the full html mail. Please see available tokens in webform page."
        );

        #############################
        ## Mail to Creator
        $form['mail_creator'] = array(
            '#type' => 'details',
            '#open' => true,
            '#title' => t('Mail Creator'),
            '#description'    => t("Mail envoyé au céateur d'un webform à sa création"),
        );

        $form['mail_creator']['mail_creator_object'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Object'),
            '#default_value' => $config->get('mail_creator_object'),
        );

        $form['mail_creator']['mail_creator_body'] = array(
            '#type' => 'textarea',
            "#format" => "full_html",
            '#title' => $this->t('Body'),
            '#default_value' => $config->get('mail_creator_body'),
            '#description'  => t("Paste the full html mail. Please see available tokens in webform page.")
        );


        #############################
        ## Mail to Business Owner
        $form['mail_business_owner'] = array(
            '#type' => 'details',
            '#open' => true,
            '#title' => t('Mail Business Owner'),
            '#description'    => t("Mail envoyé au Business Owner à la création d'un webform"),
        );

        $form['mail_business_owner']['mail_business_owner_object'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Object'),
            '#default_value' => $config->get('mail_business_owner_object'),
        );

        $form['mail_business_owner']['mail_business_owner_body'] = array(
            '#type' => 'textarea',
            "#format" => "full_html",
            '#title' => $this->t('Body'),
            '#default_value' => $config->get('mail_business_owner_body'),
            '#description'  => t("Paste the full html mail. Please see available tokens in webform page.")
        );

        #############################
        ## Validation mail
        $form['mail_validation'] = array(
            '#type' => 'details',
            '#open' => true,
            '#title' => t('webform validation mail'),
            '#description'    => t("Validation mail to SPOC, creator and Business Owner"),
        );

        $form['mail_validation']['mail_validation_object'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Object'),
            '#default_value' => $config->get('mail_validation_object'),
        );

        $form['mail_validation']['mail_validation_body'] = array(
            '#type' => 'textarea',
            "#format" => "full_html",
            '#title' => $this->t('Body'),
            '#default_value' => $config->get('mail_validation_body'),
            '#description'  => t("Paste the full html mail. Please see available tokens in webform page.")
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set('mail_spoc_object', $form_state->getValue('mail_spoc_object'))
            ->set('mail_spoc_body', $form_state->getValue('mail_spoc_body'))
            ->set('mail_creator_object', $form_state->getValue('mail_creator_object'))
            ->set('mail_creator_body', $form_state->getValue('mail_creator_body'))
            ->set('mail_business_owner_object', $form_state->getValue('mail_business_owner_object'))
            ->set('mail_business_owner_body', $form_state->getValue('mail_business_owner_body'))
            ->set('mail_validation_object', $form_state->getValue('mail_validation_object'))
            ->set('mail_validation_body', $form_state->getValue('mail_validation_body'))
            ->save();

        parent::submitForm($form, $form_state);
    }
}
