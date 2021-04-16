<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.settings');
$config_group->setData(
  array (
    'anonymous' => 'Anonymous',
    'verify_mail' => true,
    'notify' =>
      array (
        'cancel_confirm' => true,
        'password_reset' => true,
        'status_activated' => true,
        'status_blocked' => false,
        'status_canceled' => false,
        'register_admin_created' => true,
        'register_no_approval_required' => true,
        'register_pending_approval' => true,
      ),
    'register' => 'admin_only',
    'cancel_method' => 'user_cancel_block',
    'password_reset_timeout' => 86400,
    'password_strength' => true,
    'langcode' => 'en',
    '_core' =>
      array (
        'default_config_hash' => 'r4kwhOM0IWXVMUZDz744Yc16EOh37ZhYbA8kGOhSmLk',
      ),
  )
);
$config_group->save(TRUE);