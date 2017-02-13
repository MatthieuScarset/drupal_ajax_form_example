<?php
/**
 * Configuration d'Autologout
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('autologout.settings');
$config_group->setData(
	array (
		'timeout' => 1200,
		'max_timeout' => 172800,
		'padding' => 10,
		'role_logout' => false,
		'redirect_url' => '/user/login',
		'no_dialog' => false,
		'message' => 'Your session is about to expire. Do you want to reset it?',
		'inactivity_message' => 'You have been logged out due to inactivity.',
		'enforce_admin' => true,
		'jstimer_format' => '%hours%:%mins%:%secs%',
		'jstimer_js_load_option' => false,
		'use_alt_logout_method' => true,
		'use_watchdog' => true,
		'_core' =>
			array (
				'default_config_hash' => 'zJS1GknUylh656CJSNXOupqKSqm6Xw200h1cq1eI970',
			),
	)
);
$config_group->save(TRUE);
