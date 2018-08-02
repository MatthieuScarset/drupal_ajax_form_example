<?php

namespace Drupal\oab_backoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author CWPS0281
 * @Block(
 *   id = "ruby_version_block",
 *   admin_label = @Translation("Ruby Version Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class RubyVersionBlock extends BlockBase {

  public function build() {
    global $config;

    $c = $this->getConfiguration();
    $rubyversion = isset($c['ruby_version']) ? $c['ruby_version'] : '';

    $display = $config['header_env']['enabled'] ? 'block' : 'none';
    return [
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => '<i class="fa fa-times margin-right-5 close-env-info" aria-hidden="true"></i><span class="env-info" >'.
        $config['header_env']['label'].' - '.$rubyversion.
        '</span>',
      '#attributes' => [
        'class' => ['environnement-info'],
        'style' => ['background:'.$config['header_env']['color'] .'; display:'.$display]
      ]
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();

    // Add a form field to the existing block configuration form.
    $form['ruby_version'] = array(
      '#type' => 'textarea',
      '#title' => t('Version'),
      '#rows' => 1,
      '#description' => t('Type the version of the site'),
      '#default_value' => isset($config['ruby_version']) ? $config['ruby_version'] : '',
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    // Save our custom settings when the form is submitted.
    $this->setConfigurationValue('ruby_version', $form_state->getValue('ruby_version'));
  }
}
