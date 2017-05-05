<?php

//Modification de la langue par défaut
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('system.site');
$config_group->set('default_langcode', 'en');
$config_group->save(TRUE);

