<?php


namespace Drupal\oab_akamai\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Access\AccessResult;
use Drupal\Core\Session\AccountInterface;

/**
 * Configure example settings for this site.
 */
class OabAkamaiManualFlushForm extends ConfigFormBase
{
    public static function getConfigName() {
        return 'oab.akamai_manual_flush';
    }

    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_akamai_manual_flush';
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

        $form['test'] = array(
            '#type' => 'fieldset',
            '#title' => t('Vider les caches d\'une page'),
            '#description'  => "Entrez une url pour vider les caches Akamai, Varnish et Drupal",
        );

        $form['test']['test_url'] = array(
            '#type' => 'textfield',
            '#title' => t("URL")
        );

        $form['test']['test_host'] = array(
            '#type' => 'textfield',
            '#title' => t("Host"),
            '#description' => t("L'URL sans le path et la langue"),
            '#default_value'  => "https://www.orange-business.com"
        );



        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration

    }


    public function access(AccountInterface $account) {
        $uid = $account->id();
        ## On autorise l'accès que pour l'admin et Nicolas Griffet
        if ($uid == 1 || $uid == 567) {
            return AccessResult::allowed();
        }

        return AccessResult::forbidden();
    }

}
