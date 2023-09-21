<?php

namespace DrupalProject\composer;

use Composer\Script\Event;
use DrupalFinder\DrupalFinder;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Process\Process;

/**
 * Handles our custom composer scripts.
 */
class ScriptHandler {

  /**
   * Helper method to run any executable available in vendor/bin.
   *
   * Process output is logged under log/{$exec}.log.
   *
   * @param \Composer\Script\Event $event
   *   The event.
   * @param string $exec
   *   A given executable file name.
   */
  protected static function runExec(Event $event, string $exec) {
    $io = $event->getIO();
    $fs = new Filesystem();
    $drupalFinder = new DrupalFinder();
    $drupalFinder->locateRoot(getcwd());
    $binPath = $drupalFinder->getVendorDir() . "/bin/$exec";

    if (!$fs->exists($binPath)) {
      $io->write("Missing executable: $binPath");
      return;
    }

    // Execute the process with all arguments.
    $args = $event->getArguments();
    $process_args = array_merge([$binPath], $args);
    $process = new Process($process_args);
    $process->run();

    $logPath = $drupalFinder->getComposerRoot() . '/log';
    $logFilename = $logPath . '/' . $exec . '.log';
    $fs->touch($logFilename);
    file_put_contents($logFilename, $process->getOutput());

    $io->write('Code fix completed.');
    $io->write("See log: $logFilename");
  }

  /**
   * Handler our custom composer script to run PHPCBF.
   *
   * @param \Composer\Script\Event $event
   *   The event.
   */
  public static function codeFix(Event $event) {
    self::runExec($event, 'phpcbf');
  }

  /**
   * Handler our custom composer script to run PHPCS.
   *
   * @param \Composer\Script\Event $event
   *   The event.
   */
  public static function codeCheck(Event $event) {
    self::runExec($event, 'phpcs');
  }

}
