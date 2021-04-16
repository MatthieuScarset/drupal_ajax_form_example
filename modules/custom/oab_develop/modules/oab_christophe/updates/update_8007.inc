<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.chief_editor');
$permissions = $config_group->get('permissions');
if (in_array('administer meta tags', $permissions)) {
  $key = array_search('administer meta tags', $permissions);
  $config_group->clear('permissions.'.$key);
  $config_group->save(TRUE);
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.digital_admin');
$permissions = $config_group->get('permissions');
if (!in_array('administer meta tags', $permissions)) {
  $permissions[] = 'administer meta tags';
  $config_group->set('permissions', $permissions);
  $config_group->save(TRUE);
}
