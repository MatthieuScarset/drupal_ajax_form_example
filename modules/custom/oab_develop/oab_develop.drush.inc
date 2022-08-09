<?php

use Drush\Drush;

/**
* Implements hook_drush_command().
*/
function oab_develop_drush_command() {
  $items = array();
  $items['oab-updb'] = [
    'description' => 'Execute drush commands for updates',
    'drupal dependencies' => ['oab_develop'],
    'aliases' => ['oab:updb', 'oabupdb'],
    ];
  return $items;
}


/**
 * Méthode appelée par Drush lorsqu'on lance
 */
function drush_oab_develop_oab_updb() {
  Drush::output()->writeln('Execution oab-updb...');
  $file_commands = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_develop').'/drush_commands.inc';
  if (file_exists($file_commands)) {
    $num_lines = 0;
    $fp = fopen($file_commands, 'r');
    while ($row = fgets($fp)) {
      if (!empty($row) && !str_starts_with($row, '#')) {
        Drush::output()->writeln('- ' . $row);
        Drush::drush(Drush::aliasManager()->getSelf(), $row);
      }
    }
  }
  Drush::output()->writeln('...Fin d\'execution oab-updb');
}
