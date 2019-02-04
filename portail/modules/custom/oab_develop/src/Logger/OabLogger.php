<?php
namespace Drupal\oab_develop\Logger;

use Drupal\Core\Logger\RfcLoggerTrait;
use Drupal\Core\Logger\RfcLogLevel;
use Psr\Log\LoggerInterface;
use \Drupal\oab_develop\Form\OabLogSettingsForm;

class OabLogger implements LoggerInterface {
    use RfcLoggerTrait;

    /**
     * {@inheritdoc}
     */
    public function log($level, $message, array $context = array()) {
        $rfcLevels = RfcLogLevel::getLevels();
        $channel = isset($context['channel'])? $context['channel']: '';

        $logger_settings = \Drupal::config(OabLogSettingsForm::getConfigName());
        $is_activated = $logger_settings->get(OabLogSettingsForm::OAB_LOG_ACTIF);
        $authorized_levels = $logger_settings->get(OabLogSettingsForm::LISTE_LEVELS);

        if(!is_array($authorized_levels)) {
            $authorized_levels = [];
        }

        if ($is_activated && (
                substr($channel, 0, 4) === "oab_"
                || in_array($level, array_keys($authorized_levels)))) {

            $stringifiedLevel = isset($rfcLevels[$level]) ? $rfcLevels[$level] : $level;
            $new_message = "$stringifiedLevel : $message";
            oabt_tracelog($channel, $new_message);
        }
    }

    public static function getLevels() {
        return RfcLogLevel::getLevels();
    }
}
