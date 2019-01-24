<?php
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
  drush_print('Execution oab-updb...');
  $file_commands = drupal_get_path('module', 'oab_develop').'/drush_commands.inc';
  if (file_exists($file_commands)) {
    $num_lines = 0;
    $fp = fopen($file_commands, 'r');
    while ($row = fgets($fp)) {
      if (!empty($row) && substr($row, 0, 1 ) != '#') {
        drush_print('- ' . $row);
        drush_invoke_process('@self', $row);
      }
    }
  }
  drush_print('...Fin d\'execution oab-updb');
}
