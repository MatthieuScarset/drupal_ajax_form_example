<?php

namespace Drupal\oab_develop\Commands;

use Drush\Drush;
use Drush\Commands\DrushCommands;
use Consolidation\SiteAlias\SiteAliasManagerAwareInterface;
use Consolidation\SiteAlias\SiteAliasManagerAwareTrait;


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
class OabDevelopCommands extends DrushCommands implements SiteAliasManagerAwareInterface {

  use SiteAliasManagerAwareTrait;

 /* public function install(array $profile) {
      $selfRecord = $this->siteAliasManager()->getSelf();
      $args = ['system.site', ...];
      $options = ['yes' => true];
      $process = $this->processManager()->drush($selfRecord, 'config-set', $args, $options);
      $process->mustRun();
  }*/

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

      $fp = fopen($file_commands, 'r');

      while ($row = fgets($fp)) {
        $row = trim(preg_replace('/\s+/', ' ', $row));
        if (!empty($row) && substr($row, 0, 1) != '#'
            && strlen($row) > 1  /* Prevent empty lines to be executed */) {
          $this->output()->writeln('- ' . $row );

          $args = explode(' ', $row);
          $cmd = array_shift($args);

          $this->runCmd($cmd, $args);
          $this->output()->writeln('--------------------------');

        }
      }
    }
    $this->output()->writeln('...Fin d\'execution oab-updb');
  }

  /**
   * Installation des modules de dev après un config import
   *
   * @usage oab:config-import
   *   Installation des modules de dev après un config import
   *
   * @command oab:config-import
   * @aliases oab-cim
   */
  public function configImport() {
    $this->output()->writeln('drush config-import');
    $this->runCmd('cim', [], true);
    $this->output()->writeln('Installation des modules devs...');
    $file_commands = drupal_get_path('module', 'oab_develop').'/dev_modules.data';
    if (file_exists($file_commands)) {

      $fp = fopen($file_commands, 'r');
      $modules = [];
      while ($row = fgets($fp)) {
        $row = trim(preg_replace('/\s+/', ' ', $row));
        if (!empty($row) && substr($row, 0, 1) != '#' && strlen($row) > 1/* Prevent empty lines to be executed */) {
          $modules[] = $row;
        }
      }
      $this->output()->writeln('- pm:enable ' . implode(" ", $modules));
      $this->runCmd("pm:enable", $modules, true);
    }
  }


  private function runCmd($cmd, $args, $yes = true) {
    $options = [
//      'debug' => true,
    ];

    if ($yes) {
      $options['yes'] = true;
    }

    $process = $this->processManager()->drush($this->siteAliasManager()->getSelf(), $cmd, $args,  $options);
    $process->enableOutput(true);
    $process->mustRun();
    foreach ($process as $type => $data) {
      if ($process::OUT === $type) {
        echo $data."\n";
      } else {
        echo $data."\n";
      }
    }
  }
}
