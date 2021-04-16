<?php
namespace Drupal\oab_develop\Logger;

use Drupal\Core\Logger\LogMessageParserInterface;
use Drupal\Core\Logger\RfcLoggerTrait;
use Drupal\Core\Logger\RfcLogLevel;
use Drupal\oab_develop\Form\OabLogSettingsForm;
use Psr\Log\LoggerInterface;

class OabLogger implements LoggerInterface {
    use RfcLoggerTrait;

    /**
     * The message's placeholders parser.
     *
     * @var \Drupal\Core\Logger\LogMessageParserInterface
     */
    protected $parser;

    public function __construct(LogMessageParserInterface $parser) {
        $this->parser = $parser;
    }

    /**
     * {@inheritdoc}
     */
    public function log($level, $message, array $context = array()) {
        $rfc_levels = $this->getLevels();
        $channel = isset($context['channel'])? $context['channel']: '';

        $logger_settings = \Drupal::config(OabLogSettingsForm::getConfigName());
        $is_activated = $logger_settings->get(OabLogSettingsForm::OAB_LOG_ACTIF);
        $authorized_levels = $logger_settings->get(OabLogSettingsForm::LISTE_LEVELS);

        if (!is_array($authorized_levels)) {
            $authorized_levels = [];
        }

        if ($is_activated && (
                substr($channel, 0, 4) === "oab_"
                || in_array($level, array_keys($authorized_levels)))) {

            //Suppression de la backtrace pour ne pas allourdir le fichier
            unset($context['backtrace']);
            if (isset($context['@backtrace_string'])) {
                $context['@backtrace_string'] = '';
            }

            $message_placeholders = $this->parser->parseMessagePlaceholders($message, $context);
            $rendered_msg = strip_tags(t($message, $message_placeholders)->render());

            $stringified_level = isset($rfc_levels[$level]) ? $rfc_levels[$level] : $level;

            //Si je n'ai pas le type de log au début, je l'ajoute
            if (substr($rendered_msg, 0, strlen($level)) !== $level) {
                $rendered_msg = "$stringified_level : $rendered_msg";
            }

            oabt_tracelog($channel, $rendered_msg);
        }
    }

    public static function getLevels() {
        return RfcLogLevel::getLevels();
    }
}
