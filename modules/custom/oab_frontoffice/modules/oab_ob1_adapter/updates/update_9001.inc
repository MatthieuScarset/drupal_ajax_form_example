<?php

// Enable theme_settings plugin.
$config = \Drupal::service('config.factory')->getEditable('views.settings');
$display_extenders = $config->get('display_extenders') ?: [];
$display_extenders[] = 'oab_theme_settings';
$config->set('display_extenders', $display_extenders);
$config->save();
