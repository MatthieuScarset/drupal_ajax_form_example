<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('recaptcha.settings');
$config_group->setData(
  array (
    'site_key' => '6LcuCw8UAAAAAMYcQQayj7yW2T-eFJmle59b2Ltl',
    'secret_key' => '6LcuCw8UAAAAAMcqvYsrL2pUKUAF4G8om4S123NL',
    'widget' =>
      array (
        'theme' => 'light',
        'type' => 'image',
        'size' => '',
        'tabindex' => 0,
        'noscript' => false,
      ),
    '_core' =>
      array (
        'default_config_hash' => 'ZKQ03ePk4sH2zESRw4tdZYw__nG2YN4Ru5roPL23g3A',
      ),
    'langcode' => 'fr',
  ));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('captcha.settings');
$config_group->setData(
  array (
    'default_challenge' => 'recaptcha/reCAPTCHA',
    'description' => 'This question is for testing whether or not you are a human visitor and to prevent automated spam submissions.',
    'administration_mode' => false,
    'allow_on_admin_pages' => false,
    'add_captcha_description' => false,
    'default_validation' => 1,
    'persistence' => 1,
    'enable_stats' => false,
    'log_wrong_responses' => false,
    '_core' =>
      array (
        'default_config_hash' => 'pfrv6lPS72f5WG1UB4wHkgQV2invlHwVpaCy_mY-ClQ',
      ),
    'langcode' => 'fr',
  ));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('captcha.captcha_point.comment_comment_form');
$config_group->setData(
  array (
    'uuid' => '31835a1d-fb81-41de-8470-bec0c4d8b0db',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'formId' => 'comment_comment_form',
    'captchaType' => 'recaptcha/reCAPTCHA',
    'label' => 'comment_comment_form',
  ));
$config_group->save(TRUE);