<?php

namespace Drupal\oab_develop\Commands;

use Drush\Drush;
use Drush\Commands\DrushCommands;


/**
 * A Drush commandfile.
 *
 * In addition to this file, you need a drush.services.yml
 * in root of your module, and a composer.json file that provides the name
 * of the services file to use.
 *
 * See these files for an example of injecting Drupal services:
 *   - http://cgit.drupalcode.org/devel/tree/src/Commands/DevelCommands.php
 *   - http://cgit.drupalcode.org/devel/tree/drush.services.yml
 */
class OabDevelopCommands extends DrushCommands {


  /**
   * Command description here.
   *
   * @usage oab-updb
   *   Installation des nouveaux modules et passage des updates
   *
   * @command oab:updb
   */
  public function commandName() {
    $this->output()->writeln('Execution oab-updb...');
    $file_commands = drupal_get_path('module', 'oab_develop').'/drush_commands.inc';
    if (file_exists($file_commands)) {
      $num_lines = 0;
      $fp = fopen($file_commands, 'r');
      while ($row = fgets($fp)) {
        if (!empty($row) && substr($row, 0, 1) != '#') {
          $this->output()->writeln('- ' . $row);
          $this->processManager()->drush(Drush::aliasManager()->getSelf(), $row);
        }
      }
    }
    $this->output()->writeln('...Fin d\'execution oab-updb');
  }

}
