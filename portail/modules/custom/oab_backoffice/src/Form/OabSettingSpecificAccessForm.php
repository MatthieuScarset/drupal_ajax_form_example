<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Access\AccessResult;
use Drupal\Core\Session\AccountInterface;


/**
 * Configure example settings for this site.
 */
class OabSettingSpecificAccessForm extends ConfigFormBase {
    private $separator = ",";

    private $configKey = "admin_access_id";

    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_settings_specific_access';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            'oab.specific_access',
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config('oab.specific_access');

        $form[$this->configKey] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Admin access IDs'),
            '#default_value' => implode($this->separator . " ", $config->get($this->configKey)),
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {

        $values = $this->getValues($form_state->getValue($this->configKey));
        // Retrieve the configuration
        $this->config('oab.specific_access')
            ->set($this->configKey, $values)
            ->save();

        parent::submitForm($form, $form_state);
    }


    private function getValues($local_values) {

        $values = str_replace(' ', '', $local_values);
        return explode($this->separator, $values);
    }

    public function access(AccountInterface $account) {
        $uid = $account->id();

        $authorized_ids = $this->config('oab.specific_access')->get($this->configKey);

        ## On autorise l'accès que pour l'admin et et les id autorisés
        if ($uid == 1 || in_array($uid, $authorized_ids)) {
            return AccessResult::allowed();
        }

        return AccessResult::forbidden();
    }

}
