<?php

namespace Drupal\oab_develop\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_develop\Logger\OabLogger;

/**
 * Configure example settings for this site.
 */
class OabLogSettingsForm extends ConfigFormBase {

    const OAB_LOG_ACTIF = 'oab_logger_actif';
    const MAILS_DESTINATAIRE = 'mails_destinataires';
    const LISTE_LEVELS = "liste_levels";

    public static function getConfigName() {
        return 'oab.log_settings';
    }
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_log_settings';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            'oab.log_settings',
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config($this->getConfigName());

        $form[self::OAB_LOG_ACTIF] = array(
            '#type' => 'checkbox',
            '#title' => $this->t('Activer le log alternatif OAB'),
            '#description'  => "Lorsque Drupal::Logger sera appelé pour un channel commencant par 'oab_', les messages seront "
              . "loggés dans le fichier files/log/oabt/log.txt qui est ensuite envoyé par mail. Cf la fonction oabt_tracelog()",
            '#default_value' => $config->get(self::OAB_LOG_ACTIF),
        );

        $form[self::LISTE_LEVELS] = array(
            '#type' => 'select',
            '#title' => "Liste des levels à logger par le log alternatif OAB",
            '#default_value' => $config->get(self::LISTE_LEVELS),
            '#options' => OabLogger::getLevels(),
            '#multiple' => true,
            '#size' => count(OabLogger::getLevels()),
            '#description' => "En plus des channels commencant par 'oab_', le log alternatif loggera les logs ayant les levels selectionnés"
        );

        $form[self::MAILS_DESTINATAIRE] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Liste destinataires'),
            '#description' => "Separez les mails par une virgule et un espace."
              . " Un cron enverra les logs recueillis dans le fichier ci-dessus",
            '#default_value' => $config->get(self::MAILS_DESTINATAIRE),
        );

        return parent::buildForm($form, $form_state);
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $this->config($this->getConfigName())
            ->set(self::OAB_LOG_ACTIF, $form_state->getValue(self::OAB_LOG_ACTIF))
            ->set(self::MAILS_DESTINATAIRE, $form_state->getValue(self::MAILS_DESTINATAIRE))
            ->set(self::LISTE_LEVELS, $form_state->getValue(self::LISTE_LEVELS))
            ->save();

        parent::submitForm($form, $form_state);
    }
}
