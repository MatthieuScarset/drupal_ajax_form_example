<?php

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
// Creation du block coté BO
$config = $config_factory->getEditable('block.block.rubyversionblock');
$config->setData(array (
  'uuid' => '5abc3dc3-c76b-4491-815d-1c18a46931d7',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'oab_backoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_obs_backoffice',
        ),
    ),
  'id' => 'rubyversionblock',
  'theme' => 'theme_obs_backoffice',
  'region' => 'content',
  'weight' => 0,
  'provider' => NULL,
  'plugin' => 'ruby_version_block',
  'settings' =>
    array (
      'id' => 'ruby_version_block',
      'label' => 'Ruby Version Block',
      'provider' => 'oab_backoffice',
      'label_display' => '0',
      'ruby_version' => '',
    ),
  'visibility' =>
    array (
    ),
));

$config->save(TRUE);

$config = $config_factory->getEditable('block.block.rubyversionblock');
$config->set('settings.ruby_version', 'G1R1C0');

$config->save(TRUE);

// Creation du block coté FO
$config = $config_factory->getEditable('block.block.rubyversionblock_2');
$config->setData(array (
  'uuid' => '0bc08de3-7e97-46bb-81c0-177913ad4a97',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'oab_backoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'rubyversionblock_2',
  'theme' => 'theme_boosted',
  'region' => 'content',
  'weight' => 0,
  'provider' => NULL,
  'plugin' => 'ruby_version_block',
  'settings' =>
    array (
      'id' => 'ruby_version_block',
      'label' => 'Ruby Version Block',
      'provider' => 'oab_backoffice',
      'label_display' => '0',
      'ruby_version' => 'GxRxCx',
    ),
  'visibility' =>
    array (
    ),
));

$config->save(TRUE);

// Montage de version
$config = $config_factory->getEditable('block.block.rubyversionblock_2');
$config->set('settings.ruby_version', 'G1R1C0');

$config->save(TRUE);


//throw new UpdateException();