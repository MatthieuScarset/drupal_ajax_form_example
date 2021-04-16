<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('roleassign.settings');
$config_group->setData(
  array(
    'roleassign_roles' =>
      array (
        'chief_editor' => 'chief_editor',
        'digital_admin' => 'digital_admin',
        'webform_manager' => 'webform_manager',
        'contributor' => 'contributor',
        'administrator' => '0',
        'fh_backbones' => '0',
      ),
    '_core' =>
      array (
        'default_config_hash' => 'iKucdYPrf1EPMz6Y3s71EADiRcAiwoLTIw9_JoxH-Jg',
      ),
  )
);
$config_group->save(TRUE);