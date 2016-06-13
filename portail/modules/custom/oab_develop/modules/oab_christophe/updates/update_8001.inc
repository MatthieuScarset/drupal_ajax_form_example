<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('node.type.office');
$config->set('description', 'Displayed in the office map.');
$config->save(TRUE);

$config = $config_factory->getEditable('node.type.profil_redacteur');
$config->set('description', 'Used to display author informations on a page.');
$config->save(TRUE);

