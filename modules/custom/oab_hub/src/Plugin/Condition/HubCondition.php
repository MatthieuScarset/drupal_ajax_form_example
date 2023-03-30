<?php

namespace Drupal\oab_hub\Plugin\Condition;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Condition\Annotation\Condition;
use Drupal\Core\Condition\ConditionPluginBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\path_alias\AliasManagerInterface;
use Drupal\Core\Path\CurrentPathStack;
use Drupal\Core\Path\PathMatcherInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\oab_hub\Controller\OabHubController;
use Drupal\taxonomy\Entity\Term;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\RequestStack;

/**
 * * Defines which hub it belongs to
 *
 * Class HubCondition
 * @package Drupal\oab_hub\Plugin\Condition
 *
 * @Condition(
 *   id = "hub_condition",
 *   label = @Translation("Hub"),
 * )
 *
 */
class HubCondition extends ConditionPluginBase implements ContainerFactoryPluginInterface {

  protected $pluginId;

  protected $pluginDefinition;

  /**
   * Constructs a RequestPath condition plugin.
   *
   * @param \Drupal\path_alias\AliasManagerInterface $alias_manager
   *   An alias manager to find the alias for the current system path.
   * @param \Drupal\Core\Path\PathMatcherInterface $path_matcher
   *   The path matcher service.
   * @param \Symfony\Component\HttpFoundation\RequestStack $request_stack
   *   The request stack.
   * @param \Drupal\Core\Path\CurrentPathStack $current_path
   *   The current path.
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param array $plugin_definition
   *   The plugin implementation definition.
   */
  public function __construct(array $configuration, $plugin_id, array $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);

     $this->pluginId = $plugin_id;
     $this->pluginDefinition = $plugin_definition;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition);
  }

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return ['hub_id' => []] + parent::defaultConfiguration();
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {

    $terms = OabHubController::getAllHubTerms();

    foreach ($terms as $term) {
      $options[$term->id()] = $term->label();
    }

    $form['hub_id'] = [
      '#type' => 'checkboxes',
      '#options' => $options,
      '#title' => $this->t('Hub'),
      '#default_value' => is_array($this->configuration['hub_id']) ? $this->configuration['hub_id'] : [$this->configuration['hub_id']],
      '#description' => $this->t("Define which hub it belongs to, on which hub it should appear." .
        "Use it only on Hub Block (ie. theme Oab Hub)", []),
    ];
    return parent::buildConfigurationForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array &$form, FormStateInterface $form_state) {
    $this->configuration['hub_id'] = array_filter($form_state->getValue('hub_id'));
    parent::submitConfigurationForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function summary() {
    return $this->t('Return true on selected hub pages');
  }

  /**
   * {@inheritdoc}
   */
  public function evaluate() {

    if ((is_array($this->configuration['hub_id']) && count($this->configuration['hub_id']) === 0)
      || $this->configuration === 0) {
      return true;
    }

    /** @var Term $term */
    $term = OabHubController::getActifHub();
    $ret = false;
    if ($term !== null) {
      if (is_array($this->configuration['hub_id'])) {
        foreach ($this->configuration['hub_id'] as $hub_id) {
          if ($term->id() === $hub_id) {
            $ret = true;
          }
        }
      } else {
        $ret = ($term->id() === $this->configuration['hub_id']);
      }
    }

    return $ret;
  }

  /**
   * {@inheritdoc}
   */
  public function getCacheContexts() {
    $contexts = parent::getCacheContexts();
    $contexts[] = 'url.path';
    return $contexts;
  }

}
