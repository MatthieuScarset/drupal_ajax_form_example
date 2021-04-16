<?php

use \Drupal\Core\Utility\UpdateException;

$titleSousmenu = t('Sous-menu');
// Solution
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.field.node.solution.field_local_nav');
$config->set('default_value.0.value', "<div class='local_nav sub_local_menu container-fluid' id='local_nav' data-title-mobile='$titleSousmenu'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li><li><a href='#zone2'>Zone 2</a></li><li><a href='#zone3'>Zone 3</a></li><li><a href='#zone4'>Zone 4</a></li><li><a href='#zone5'>Zone 5</a></li></ul></div></div>");
$config->save();

// Industrie
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.field.node.industry.field_local_nav');
$config->set('default_value.0.value', "<div class='local_nav sub_local_menu container-fluid' id='local_nav' data-title-mobile='$titleSousmenu'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li><li><a href='#zone2'>Zone 2</a></li><li><a href='#zone3'>Zone 3</a></li><li><a href='#zone4'>Zone 4</a></li><li><a href='#zone5'>Zone 5</a></li></ul></div></div>");
$config->save();

// Région
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.field.node.region.field_local_nav');
$config->set('default_value.0.value', "<div class='local_nav sub_local_menu container-fluid' id='local_nav' data-title-mobile='$titleSousmenu'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li><li><a href='#zone2'>Zone 2</a></li><li><a href='#zone3'>Zone 3</a></li><li><a href='#zone4'>Zone 4</a></li><li><a href='#zone5'>Zone 5</a></li></ul></div></div>");
$config->save();

// Pays
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('field.field.node.country.field_local_nav');
$config->set('default_value.0.value', "<div class='local_nav sub_local_menu container-fluid' id='local_nav' data-title-mobile='$titleSousmenu'><div class='container'><ul><li><a href='#zone1'>Zone 1</a></li><li><a href='#zone2'>Zone 2</a></li><li><a href='#zone3'>Zone 3</a></li><li><a href='#zone4'>Zone 4</a></li><li><a href='#zone5'>Zone 5</a></li></ul></div></div>");
$config->save();



// throw new UpdateException();