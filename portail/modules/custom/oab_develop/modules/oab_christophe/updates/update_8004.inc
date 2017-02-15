<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.anonymous');
$config_group->set('permissions', array (
  0 => 'access content',
  1 => 'use text format comments',
  2 => 'view media',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.authenticated');
$config_group->set('permissions', array (
  0 => 'access content',
  1 => 'use text format comments',
  2 => 'view media',
));
$config_group->save(TRUE);
