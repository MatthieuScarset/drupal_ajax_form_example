<?php

namespace Drupal\oab_styleguide;

use Drupal\Core\Plugin\PluginBase;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Default class used for styleguide_sections plugins.
 */
class StyleguideSectionDefault extends PluginBase implements StyleguideSectionInterface {

  /**
   * The styleguide_element plugin manager.
   *
   * @var \Drupal\oab_styleguide\StyleguideElementPluginManager
   */
  protected $elementPluginManager;

  /**
   * The token service.
   *
   * @var \Drupal\Core\Utility\Token
   */
  protected $token;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    $instance = new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
    );

    $instance->elementPluginManager = $container->get('plugin.manager.styleguide_element');
    $instance->token = $container->get('token');

    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  public function label() {
    return (string) $this->pluginDefinition['label'];
  }

  /**
   * {@inheritdoc}
   */
  public function description() {
    $markup = (string) $this->pluginDefinition['description'];
    return $this->token->replace($markup);
  }

  /**
   * {@inheritdoc}
   */
  public function elements() {
    $this->sort();
    $elements = [];
    foreach ($this->pluginDefinition['elements'] as $plugin_id => $configuration) {
      try {
        $elements[$plugin_id] = $this->elementPluginManager->createInstance($plugin_id, $configuration);
      }
      catch (\Exception $e) {
        // Fail silently.
      }
    }
    return $elements;
  }

  /**
   * Sorts all plugin instances in this collection.
   *
   * @return $this
   */
  public function sort() {
    uasort($this->pluginDefinition['elements'], [$this, 'sortByWeight']);
    return $this;
  }

  /**
   * Provides uasort() callback to sort plugins.
   */
  public function sortByWeight($a, $b) {
    return strnatcasecmp($a['weight'] ?? 0, $b['weight'] ?? 0);
  }

  /**
   * {@inheritdoc}
   */
  public function isOpen() {
    return (bool) ($this->pluginDefinition['open'] ?? FALSE);
  }

}
