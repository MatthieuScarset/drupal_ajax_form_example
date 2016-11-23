<?php
use Drupal\Core\Database\Database;
use Drupal\locale;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('autologout.settings');
$config->setData(
    array (
        'timeout' => 1200,
        'max_timeout' => 172800,
        'padding' => 10,
        'role_logout' => false,
        'redirect_url' => '/user/login',
        'no_dialog' => false,
        'message' => 'Your session is about to expire. Do you want to reset it?',
        'inactivity_message' => 'You have been logged out due to inactivity.',
        'enforce_admin' => false,
        'jstimer_format' => '%hours%:%mins%:%secs%',
        'jstimer_js_load_option' => false,
        'use_alt_logout_method' => false,
        'use_watchdog' => true,
        '_core' =>
            array (
                'default_config_hash' => 'B77DRkEEMfvFWjtyYFRrMQUbPyaFTBiQ-A4Yg-BJzQk',
            ),
        'langcode' => 'fr',
    )
);
$config->save(TRUE);



/* on récupère ou on crée la chaine source
$match_string = array('source' => 'You have been automatically logged out due to inactivity.');
$source = \Drupal::service('locale.storage')->findString($match_string);
if (!$source) {
    // Si la source n'existe pas, on la crée
    $source = \Drupal::service('locale.storage')->createString($match_string);
    $source->save();
}

// On crée et enregistre un objet de traduction (fait l'insertion et l'update)
$connection = Database::getConnection();
$stringDatabaseStorage = new locale\StringDatabaseStorage($connection);
$translation = $stringDatabaseStorage->createTranslation(array('lid' => $source->getId(), 'language' => 'fr', 'translation' => 'Vous avez été automatiquement déconnecté pour cause d\'inactivité'));
$stringDatabaseStorage->save($translation);
*/