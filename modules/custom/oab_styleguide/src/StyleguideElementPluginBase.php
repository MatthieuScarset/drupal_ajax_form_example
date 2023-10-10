<?php

namespace Drupal\oab_styleguide;

use Drupal\Component\Plugin\PluginBase;
use Drupal\Component\Utility\Random;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Base class for styleguide_element plugins.
 */
abstract class StyleguideElementPluginBase extends PluginBase implements StyleguideElementInterface {

  use StringTranslationTrait;

  /**
   * The token service.
   *
   * @var \Drupal\Core\Utility\Token
   */
  protected $token;

  /**
   * The random utility.
   *
   * @var \Drupal\Component\Utility\Random
   */
  protected $random;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    $instance = new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
    );

    $instance->token = $container->get('token');
    $instance->random = new Random();

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
  public function render() {
    $markup = ['#markup' => $this->t('Empty element')];
    return $this->token->replace($markup);
  }
}
