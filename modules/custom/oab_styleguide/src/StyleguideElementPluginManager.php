<?php

namespace Drupal\oab_styleguide;

use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Extension\ModuleHandlerInterface;
use Drupal\Core\Plugin\DefaultPluginManager;

/**
 * StyleguideElement plugin manager.
 */
class StyleguideElementPluginManager extends DefaultPluginManager {

  /**
   * Constructs StyleguideElementPluginManager object.
   *
   * @param \Traversable $namespaces
   *   An object that implements \Traversable which contains the root paths
   *   keyed by the corresponding namespace to look for plugin implementations.
   * @param \Drupal\Core\Cache\CacheBackendInterface $cache_backend
   *   Cache backend instance to use.
   * @param \Drupal\Core\Extension\ModuleHandlerInterface $module_handler
   *   The module handler to invoke the alter hook with.
   */
  public function __construct(\Traversable $namespaces, CacheBackendInterface $cache_backend, ModuleHandlerInterface $module_handler) {
    parent::__construct(
      'Plugin/StyleguideElement',
      $namespaces,
      $module_handler,
      'Drupal\oab_styleguide\StyleguideElementInterface',
      'Drupal\oab_styleguide\Annotation\StyleguideElement'
    );
    $this->alterInfo('styleguide_element_info');
    $this->setCacheBackend($cache_backend, 'styleguide_element_plugins');
  }

}
