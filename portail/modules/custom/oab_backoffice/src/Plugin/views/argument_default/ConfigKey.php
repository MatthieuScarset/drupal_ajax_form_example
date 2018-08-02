<?php

namespace Drupal\oab_backoffice\Plugin\views\argument_default;

use Drupal\Core\Cache\Cache;
use Drupal\Core\Cache\CacheableDependencyInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\argument_default\ArgumentDefaultPluginBase;

/**
 * The fixed argument default handler.
 *
 * @ingroup views_argument_default_plugins
 *
 * @ViewsArgumentDefault(
 *   id = "config_key",
 *   title = @Translation("Config")
 * )
 */
class ConfigKey extends ArgumentDefaultPluginBase implements CacheableDependencyInterface {

  /**
   * {@inheritdoc}
   */
  protected function defineOptions() {
    $options = parent::defineOptions();
    $options['config_name'] = array('default' => '');
    $options['config_key'] = array('default' => '');

    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
    $form['config_name'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('config machine name'),
      '#default_value' => $this->options['config_name'],
    );
    $form['config_key'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('config key to target'),
      '#default_value' => $this->options['config_key'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getArgument() {
    $variable = \Drupal::config($this->options['config_name'])->get($this->options['config_key']);
    if (is_null($variable)) {
        $variable = 0;
    }
    return $variable;
  }

  /**
   * {@inheritdoc}
   */
  public function getCacheMaxAge() {
    return Cache::PERMANENT;
  }

  /**
   * {@inheritdoc}
   */
  public function getCacheContexts() {
    return [];
  }

}
