<?php

use Symfony\Component\Yaml\Yaml;
// import view subhomes
$config_path = drupal_get_path('module', 'oab_backoffice') . '/config/content_settings/language.content_settings.node.webform.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('language.content_settings.node.webform')->setData($data)->save(TRUE);