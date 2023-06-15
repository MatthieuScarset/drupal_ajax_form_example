<?php
use Symfony\Component\Yaml\Yaml;


/*
 * RUBYPORTAILOBS-3034 Remplacement favicon drupal8
 */


//$config_path = drupal_get_path('theme', "theme_boosted") . '/config/install/theme_boosted.settings.yml';

//  Correction déprécation juste pour exemple
$config_path = \Drupal::service('extension.path.resolver')
    ->getPath('theme', 'theme_boosted') . '/config/install/theme_boosted.settings.yml';


$data = Yaml::parse($config_path);
\Drupal::configFactory()->getEditable("theme_boosted.settings")->setData($data)->save(TRUE);

