<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsWebformCustomTemplateForm extends ConfigFormBase {

    const CUSTOM_TEMPLATE = 'custom_template';

    public static function getConfigName() {
        return 'oab.webform_email_custom_template_settings';
    }
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_webform_custome_email_template_settings';
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
        $config = $this->config($this->getConfigName());

        $default_value = $config->get(self::CUSTOM_TEMPLATE);

        $form[self::CUSTOM_TEMPLATE] = array(
            '#type' => "text_format",
            '#format' => isset($default_value['format']) ? $default_value['format'] : "full_html",
            '#title' => t('Custom template form webform email handler'),
            '#description'  => t("Template custom pour les email handlers des webforms"),
            '#default_value' => isset($default_value['value']) ? $default_value['value'] : ""
        );
        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set(self::CUSTOM_TEMPLATE, $form_state->getValue(self::CUSTOM_TEMPLATE))
            ->save();

        parent::submitForm($form, $form_state);
    }
}
