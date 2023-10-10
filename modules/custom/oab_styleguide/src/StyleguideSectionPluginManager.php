<?php

namespace Drupal\oab_styleguide;

use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Extension\ModuleHandlerInterface;
use Drupal\Core\Plugin\DefaultPluginManager;
use Drupal\Core\Plugin\Discovery\YamlDiscovery;
use Drupal\Core\Plugin\Factory\ContainerFactory;

/**
 * Defines a plugin manager to deal with styleguide_sections.
 *
 * Modules can define styleguide_sections in a MODULE_NAME.styleguide_sections.yml file contained
 * in the module's base directory. Each styleguide_section has the following structure:
 *
 * @code
 *   MACHINE_NAME:
 *     label: STRING
 *     description: STRING
 * @endcode
 *
 * @see \Drupal\oab_styleguide\StyleguideSectionDefault
 * @see \Drupal\oab_styleguide\StyleguideSectionInterface
 * @see plugin_api
 */
class StyleguideSectionPluginManager extends DefaultPluginManager {

  /**
   * {@inheritdoc}
   */
  protected $defaults = [
    // The styleguide_section id. Set by the plugin system based on the top-level YAML key.
    'id' => '',
    // The styleguide_section label.
    'label' => '',
    // The styleguide_section description.
    'description' => '',
    // Closed by default.
    'open' => FALSE,
    // The styleguide_section content.
    'elements' => [],
    // Default plugin class.
    'class' => 'Drupal\oab_styleguide\StyleguideSectionDefault',
  ];

  /**
   * Constructs StyleguideSectionPluginManager object.
   *
   * @param \Drupal\Core\Extension\ModuleHandlerInterface $module_handler
   *   The module handler to invoke the alter hook with.
   * @param \Drupal\Core\Cache\CacheBackendInterface $cache_backend
   *   Cache backend instance to use.
   */
  public function __construct(ModuleHandlerInterface $module_handler, CacheBackendInterface $cache_backend) {
    $this->factory = new ContainerFactory($this);
    $this->moduleHandler = $module_handler;
    $this->alterInfo('styleguide_section_info');
    $this->setCacheBackend($cache_backend, 'styleguide_section_plugins');
  }

  /**
   * {@inheritdoc}
   */
  protected function getDiscovery() {
    if (!isset($this->discovery)) {
      $this->discovery = new YamlDiscovery('styleguide_sections', $this->moduleHandler->getModuleDirectories());
      $this->discovery->addTranslatableProperty('label', 'label_context');
      $this->discovery->addTranslatableProperty('description', 'description_context');
    }
    return $this->discovery;
  }

}
