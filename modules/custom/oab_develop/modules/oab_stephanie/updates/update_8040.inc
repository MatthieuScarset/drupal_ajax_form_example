<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('xmlsitemap.settings');
$config_group->set('minimum_lifetime', 21600);
$config_group->save(TRUE);