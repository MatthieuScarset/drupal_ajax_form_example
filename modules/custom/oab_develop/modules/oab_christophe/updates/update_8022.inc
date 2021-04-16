<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.contactbar');
$config_group->setData(array(
  'uuid' => '49af0b2f-33d1-41ae-8b4b-5608d1f06716',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'oab_frontoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'contactbar',
  'theme' => 'theme_boosted',
  'region' => 'prefooter',
  'weight' => -19,
  'provider' => NULL,
  'plugin' => 'contact_bar_block',
  'settings' =>
    array (
      'id' => 'contact_bar_block',
      'label' => 'Contact Bar',
      'provider' => 'oab_frontoffice',
      'label_display' => '0',
      'content' => '',
      'content_format' => 'full_html',
    ),
  'visibility' =>
    array (
    ),
));
$config_group->save();