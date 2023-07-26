<?php

use Symfony\Component\Yaml\Yaml;
// import view subhomes
$config_path = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_backoffice') . '/config/views/views.view.subhomes.yml';
$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable('views.view.subhomes')->setData($data)->save(TRUE);
